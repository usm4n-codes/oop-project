// 📝 Task 5: Mini Project – University Directory
// Create a console-based menu where you can:

// Add students and teachers.

// Display their info using inheritance.

// Store their data in a file (use ofstream/ifstream).

// Use inheritance for Person → Student and Person → Teacher.

// ✅ Goal: Combine OOP + file handling + inheritance.
#include<iostream>
using namespace std;
class person{
    public:
    string name;
    int id;
    int age;
    
};
class student:public person{
public:
float salary;
void setstd(string name,int id,int age,float salary){
this->name=name;
this->id=id;
this->age=age;
this->salary=salary;
}

void getstd(){
    cout<<"\nname : "<<name;
    cout<<"\nid : "<<id;
    cout<<"\nage : "<<age;
    cout<<"\nsalary  : "<<salary;
}
};
class teacher:public person{
public:
string subject;
void settea(string name,int id,int age ,string subject){
this->name=name;
this->id=id;
this->age=age;
this->subject=subject;
}
void gettea(){
    cout<<"\nname : "<<name;
    cout<<"\nid : "<<id;
    cout<<"\nage : "<<age;
    cout<<"\nsubject : "<<subject;
}
};
int main(){
    //teacher t1;
    student s1[3];
    string name;
    int id,age;
    float salary;
    for(int i=0;i<3;i++){
        cout<<"\nenter name of "<<i+1<<" student :";
        getline(cin,name);
        cout<<"\nenter id of "<<i+1<<" student :";
        cin>>id;
        cout<<"\nenter age of "<<i+1<<" student :";
        cin>>age;
        cout<<"\nenter salary of "<<i+1<<" student :";
        cin>>salary;
        cin.ignore();
    s1[i].setstd(name,id,age,salary);  
    }
    for(int i=0;i<3;i++){
    s1[i].getstd();
    }
    // t1.settea("zahir",1,40,"oop");
    // t1.gettea();
    system("pause"); 
}