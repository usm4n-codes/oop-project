#include<iostream>
#include<fstream>
#include<sstream>
#include <iomanip>
using namespace std;
class in{
public:
string name;
int roll;
float score;

};
void add(int size);
int main(){
    int size;
    cout<<"enter size :";
    cin>>size;
in a[size];
ofstream fout;
fout.open("inout.txt");
for(int i=0;i<size;i++){
   cout<<"name: ";
   cin>>a[i].name;
   cout<<"roll number :";
   cin>>a[i].roll;
   cout<<"enter score :";
   cin>>a[i].score;
   fout<<left;
   fout<<setw(10)
   <<a[i].name<<","<<setw(10)
   <<a[i].roll<<","<<setw(10)
   <<a[i].score<<endl;
}
fout.close();
//size=--size; 
int choice;
cout<<"press 1 to add new record "<<endl;
cout<<"press 2 to delete record "<<endl;
cout<<"choice : " ;
cin>>choice;
if(choice==1){
//     fout.open("inout.txt");
     size=++size;
//     cout<<"name :";
//     cin>>a[size].name;
//     cout<<"rollnmber :";
//     cin>>a[size].roll;
//     cout<<"score :";
//     cin>>a[size].score;
//     fout<<setw(10)
//    <<a[size].name<<","<<setw(10)
//    <<a[size].roll<<","<<setw(10)
//    <<a[size].score<<endl; 
// fout.close();
add(size);
}
else if(choice==2){
    int rn;
    cout<<"enter the roll number of student :";
    cin>>rn;


}

system("pause");
}
void add( int size){
    ifstream fin;
    string line;
    fin.open("inout.txt");
    int i=0,j=0;
    string a[i][j];
   for( i=0;i<size;i++){
    getline(cin,line)
    stringstream ss(line)
    

cout<<line<<endl;
    }

//     ofstream fout;
//     in a[size];
//     fout.open("inout.txt");
//     size=++size;
//     cout<<"name :";
//     cin>>a[size].name;
//     cout<<"rollnmber :";
//     cin>>a[size].roll;
//     cout<<"score :";
//     cin>>a[size].score;
//     fout<<setw(10)
//    <<a[size].name<<","<<setw(10)
//    <<a[size].roll<<","<<setw(10)
//    <<a[size].score<<endl; 
// fout.close();
}