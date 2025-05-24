#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<iomanip>
using namespace std;
int main(){
    string line;
ifstream fin;
fin.open("tem.txt");
while(getline(fin,line)){
    cout<<line<<endl;
}
ofstream fout;
fout.open("tem.txt",ios:: app);


system("pause");
}