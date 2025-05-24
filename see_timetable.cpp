#include<iostream>
#include<fstream>
using namespace std;
int main(){
    string line;
    ifstream fin;
    fin.open("attendence-practice.txt");
    while(getline(fin,line)){
        cout<<line<<endl;
    }
    system("pause");
}