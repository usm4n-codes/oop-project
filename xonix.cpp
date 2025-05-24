#include <iostream>
#include <vector>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <random>

using namespace std;

// Constants for game settings
const int WIDTH = 80;
const int HEIGHT = 25;
const char PLAYER = '@';
const char BORDER = '#';
const char TRAIL = '.';
const char CLAIMED = '*';
const char ENEMY = 'O';
const char EMPTY = ' ';
const int NUM_ENEMIES = 3;
const int GAME_SPEED = 100; // milliseconds

// Direction enum for movement
enum class Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    NONE
};

// Point class to represent coordinates
class Point {
public:
    int x, y;
    
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
};

// GameObject base class
class GameObject {
protected:
    Point position;
    char symbol;
    
public:
    GameObject(int x, int y, char sym) : position(x, y), symbol(sym) {}
    virtual ~GameObject() = default;
    
    Point getPosition() const {
        return position;
    }
    
    char getSymbol() const {
        return symbol;
    }
    
    virtual void update() = 0;
};

// Player class
class Player : public GameObject {
private:
    Direction direction;
    bool onBorder;
    
public:
    Player(int x, int y) : GameObject(x, y, PLAYER), direction(Direction::NONE), onBorder(true) {}
    
    void move(Direction newDirection) {
        direction = newDirection;
    }
    
    void update() override {
        Point newPos = position;
        
        switch (direction) {
            case Direction::UP:
                newPos.y--;
                break;
            case Direction::DOWN:
                newPos.y++;
                break;
            case Direction::LEFT:
                newPos.x--;
                break;
            case Direction::RIGHT:
                newPos.x++;
                break;
            case Direction::NONE:
                return;
        }
        
        // Update position if within bounds
        if (newPos.x > 0 && newPos.x < WIDTH - 1 && newPos.y > 0 && newPos.y < HEIGHT - 1) {
            position = newPos;
        }
    }
    
    void setOnBorder(bool border) {
        onBorder = border;
    }
    
    bool isOnBorder() const {
        return onBorder;
    }
};

// Enemy class
class Enemy : public GameObject {
private:
    Point velocity;
    
public:
    Enemy(int x, int y) : GameObject(x, y, ENEMY) {
        // Random direction
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(-1, 1);
        
        velocity.x = dis(gen);
        velocity.y = dis(gen);
        
        // Ensure enemy is moving
        if (velocity.x == 0 && velocity.y == 0) {
            velocity.x = 1;
        }
    }
    
    void update() override {
        position = position + velocity;
        
        // Bounce off walls
        if (position.x <= 1 || position.x >= WIDTH - 2) {
            velocity.x = -velocity.x;
        }
        if (position.y <= 1 || position.y >= HEIGHT - 2) {
            velocity.y = -velocity.y;
        }
    }
};

// Game class to manage the game
class XonixGame {
private:
    vector<vector<char>> grid;
    vector<vector<bool>> claimed;
    vector<Point> trail;
    Player player;
    vector<Enemy> enemies;
    int score;
    bool gameOver;
    int percentClaimed;
    
    // Initialize grid with borders
    void initGrid() {
        grid = vector<vector<char>>(HEIGHT, vector<char>(WIDTH, EMPTY));
        claimed = vector<vector<bool>>(HEIGHT, vector<bool>(WIDTH, false));
        
        // Create borders
        for (int x = 0; x < WIDTH; x++) {
            grid[0][x] = BORDER;
            grid[HEIGHT - 1][x] = BORDER;
            claimed[0][x] = true;
            claimed[HEIGHT - 1][x] = true;
        }
        
        for (int y = 0; y < HEIGHT; y++) {
            grid[y][0] = BORDER;
            grid[y][WIDTH - 1] = BORDER;
            claimed[y][0] = true;
            claimed[y][WIDTH - 1] = true;
        }
    }
    
    // Create enemies at random positions
    void createEnemies() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> disX(2, WIDTH - 3);
        uniform_int_distribution<> disY(2, HEIGHT - 3);
        
        for (int i = 0; i < NUM_ENEMIES; i++) {
            int x = disX(gen);
            int y = disY(gen);
            enemies.emplace_back(x, y);
        }
    }
    
    // Fill an enclosed area with claimed territory
    void fillEnclosedArea() {
        vector<vector<bool>> visited(HEIGHT, vector<bool>(WIDTH, false));
        
        // Mark all border cells as visited
        for (int x = 0; x < WIDTH; x++) {
            floodFill(x, 0, visited);
            floodFill(x, HEIGHT - 1, visited);
        }
        
        for (int y = 0; y < HEIGHT; y++) {
            floodFill(0, y, visited);
            floodFill(WIDTH - 1, y, visited);
        }
        
        // Any unvisited cells are enclosed and should be claimed
        for (int y = 1; y < HEIGHT - 1; y++) {
            for (int x = 1; x < WIDTH - 1; x++) {
                if (!visited[y][x] && !claimed[y][x]) {
                    grid[y][x] = CLAIMED;
                    claimed[y][x] = true;
                }
            }
        }
    }
    
    // Flood fill algorithm to mark reachable cells
    void floodFill(int x, int y, vector<vector<bool>>& visited) {
        if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT || visited[y][x] || claimed[y][x]) {
            return;
        }
        
        visited[y][x] = true;
        
        floodFill(x + 1, y, visited);
        floodFill(x - 1, y, visited);
        floodFill(x, y + 1, visited);
        floodFill(x, y - 1, visited);
    }
    
    // Check if player is on border
    bool checkOnBorder(int x, int y) {
        return claimed[y][x];
    }
    
    // Calculate percentage of area claimed
    void calculatePercentClaimed() {
        int totalCells = (WIDTH - 2) * (HEIGHT - 2);
        int claimedCells = 0;
        
        for (int y = 1; y < HEIGHT - 1; y++) {
            for (int x = 1; x < WIDTH - 1; x++) {
                if (claimed[y][x]) {
                    claimedCells++;
                }
            }
        }
        
        percentClaimed = (claimedCells * 100) / totalCells;
    }
    
    // Check for collisions between player and enemies or trail
    bool checkCollisions() {
        // Check enemy collisions
        Point playerPos = player.getPosition();
        
        // Check if player hits trail
        for (const auto& point : trail) {
            if (point == playerPos) {
                return true;
            }
        }
        
        // Check if player hits enemy
        for (const auto& enemy : enemies) {
            if (enemy.getPosition() == playerPos) {
                return true;
            }
        }
        
        // Check if enemy hits trail
        for (const auto& enemy : enemies) {
            Point enemyPos = enemy.getPosition();
            for (const auto& point : trail) {
                if (point == enemyPos) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    // Draw the game grid
    void drawGrid() {
        system("cls");
        
        // Add player and enemies to grid
        Point playerPos = player.getPosition();
        grid[playerPos.y][playerPos.x] = player.getSymbol();
        
        for (const auto& enemy : enemies) {
            Point pos = enemy.getPosition();
            grid[pos.y][pos.x] = enemy.getSymbol();
        }
        
        // Draw the grid
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                cout << grid[y][x];
            }
            cout << endl;
        }
        
        // Show score and percentage
        cout << "Score: " << score << " | Claimed: " << percentClaimed << "%" << endl;
        cout << "Controls: Arrow keys to move, ESC to quit" << endl;
        
        // Reset player and enemies from grid
        grid[playerPos.y][playerPos.x] = claimed[playerPos.y][playerPos.x] ? CLAIMED : EMPTY;
        
        for (const auto& enemy : enemies) {
            Point pos = enemy.getPosition();
            grid[pos.y][pos.x] = claimed[pos.y][pos.x] ? CLAIMED : EMPTY;
        }
    }
    
public:
    XonixGame() : player(1, 1), score(0), gameOver(false), percentClaimed(0) {
        srand(static_cast<unsigned>(time(nullptr)));
        initGrid();
        createEnemies();
    }
    
    void run() {
        const int TARGET_PERCENT = 75; // Win when 75% is claimed
        
        while (!gameOver) {
            // Process input
            if (_kbhit()) {
                int key = _getch();
                
                switch (key) {
                    case 27: // ESC key
                        gameOver = true;
                        break;
                    case 224: // Arrow keys prefix
                        key = _getch();
                        switch (key) {
                            case 72: // Up arrow
                                player.move(Direction::UP);
                                break;
                            case 80: // Down arrow
                                player.move(Direction::DOWN);
                                break;
                            case 75: // Left arrow
                                player.move(Direction::LEFT);
                                break;
                            case 77: // Right arrow
                                player.move(Direction::RIGHT);
                                break;
                        }
                        break;
                }
            }
            
            // Update game state
            Point oldPos = player.getPosition();
            player.update();
            Point newPos = player.getPosition();
            
            // Check if position changed
            if (oldPos.x != newPos.x || oldPos.y != newPos.y) {
                bool onBorder = checkOnBorder(newPos.x, newPos.y);
                
                // If player was not on border and now is
                if (!player.isOnBorder() && onBorder) {
                    // Convert trail to claimed territory
                    for (const auto& point : trail) {
                        grid[point.y][point.x] = CLAIMED;
                        claimed[point.y][point.x] = true;
                    }
                    
                    // Fill enclosed areas
                    fillEnclosedArea();
                    
                    // Clear trail
                    trail.clear();
                    
                    // Calculate score and percentage
                    calculatePercentClaimed();
                    score += trail.size() * 10;
                    
                    // Check win condition
                    if (percentClaimed >= TARGET_PERCENT) {
                        drawGrid();
                        cout << "\nCongratulations! You've claimed " << percentClaimed << "% of the area!" << endl;
                        cout << "Final Score: " << score << endl;
                        gameOver = true;
                        break;
                    }
                }
                // If player was on border and now is not
                else if (player.isOnBorder() && !onBorder) {
                    // Start new trail
                    trail.clear();
                }
                // If player is not on border
                else if (!onBorder) {
                    // Add to trail
                    grid[newPos.y][newPos.x] = TRAIL;
                    trail.push_back(newPos);
                }
                
                player.setOnBorder(onBorder);
            }
            
            // Update enemies
            for (auto& enemy : enemies) {
                enemy.update();
            }
            
            // Check for collisions
            if (checkCollisions()) {
                drawGrid();
                cout << "\nGame Over! An enemy hit your trail." << endl;
                cout << "Final Score: " << score << endl;
                gameOver = true;
                break;
            }
            
            // Draw the game
            drawGrid();
            
            // Control game speed
            Sleep(GAME_SPEED);
        }
    }
};

int main() {
    // Hide cursor for cleaner display
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
    
    // Title and instructions
    cout << "======= XONIX GAME =======" << endl;
    cout << "Claim territory by creating closed paths!" << endl;
    cout << "Avoid enemies and don't cross your own trail." << endl;
    cout << "Press any key to start..." << endl;
    _getch();
    
    // Create and run the game
    XonixGame game;
    game.run();
    
    cout << "Thanks for playing! Press any key to exit..." << endl;
    _getch();
    
    return 0;
}