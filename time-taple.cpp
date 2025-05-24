#include<iostream>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<cstdio>
using namespace std;

void see_timetable();
void edit_timetable();
int main(){
    int opt;
    char choice;
    do{
    cout<<"press 1 to see time_table "<<endl;
    cout<<"press 2 to edit_timetable "<<endl;
    cout<<"choice : ";
    cin>>opt;
    if(opt==1){
        see_timetable();
    }
    if(opt==2){
        edit_timetable();
    }
    cout<<"press 'y' to continue :";
    cin>>choice;
    system("cls");
    }while(choice=='y'||choice=='Y');
    system("pause");
}
void see_timetable(){
    cout<<"\t\t"<<endl;
    cout<<"\t\t"<<endl;
    cout<<"\t\t\tTIME  TABLE:"<<endl;
    cout<<"\t\t"<<endl;
    cout<<"\t\t"<<endl;
    ifstream fin;
    string line;
    fin.open("timetable2.txt");
    while(getline(fin,line)){
    cout<<"\t\t";
    cout<<line<<endl;
    }
    fin.close();
}
void edit_timetable(){
    string days,line,tem_line;
    cin.ignore();
    cout<<"enter the day to edit data :";
    getline(cin,days);
    ifstream fin;
    string lac1,lac2,lac3,lac4;
     fin.open("timetable2.txt");
     ofstream fout;
     fout.open("temp1.txt");
     //istringstream ss(line);
    while(getline(fin,line)){
     istringstream is(line);
     getline(is,tem_line,'|');
     if(days==tem_line){
        cout<<"enter lacture 1 :";
        cin>>lac1;
        cout<<"enter lacture 2 :";
        cin>>lac2;
        cout<<"enter lacture 3 :";
        cin>>lac3;
        cout<<"enter lacture 4 :";
        cin>>lac4;
        fout<<left<<setw(4)<<tem_line<<"|"<<setw(4)<<lac1<<"|"
        <<setw(4)<<lac2<<"|"<<setw(4)<<lac3<<"|"<<setw(4)<<lac4<<"|"<<endl;
     }
     else{
    fout<<line<<endl;
     }
    //cout<<line<<endl;
    }
    fout.close();
    fin.close();
    remove("timetable2.txt");
    rename("temp1.txt","timetable2.txt");

}