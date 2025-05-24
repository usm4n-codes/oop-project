#include<iostream>
using namespace std;

class Person {
public:
    void identity() {
        cout << "I am a person (shared via virtual inheritance)" << endl;
    }
};

class Father : virtual public Person {};
class Mother : virtual public Person {};
class Son : public Father, public Mother {};

int main() {
    Son s;
    s.identity(); // No ambiguity now
    system("pause");
}