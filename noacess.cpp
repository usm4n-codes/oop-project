#include<iostream>
#include<fstream>
using namespace std;    
int main(){
    ifstream fin;
    string name,pass;
    fin.open("std_login.txt");
    while(fin>>name>>pass){
        //fin>>name>>pass;

        cout<<name<<pass<<endl;
    }
    fin.close();
    system("pause");
}