// 📝 Task 1: Basic Inheritance (Public)
// Create a class hierarchy where:

// Person is the base class with name and age.

// Student and Teacher classes publicly inherit from Person.

// Add rollNumber in Student, and subject in Teacher.

// ✅ Goal: Practice public inheritance and how members are accessed.

// #include<iostream>
// using namespace std;
// class person{
// public:
// string name;
// float age;
// };
// class student:public person{
//     public:
//     int rollnu;
//     void set_std(string name,int roll){
//         rollnu=roll;
//         person::name=name;
//     }
//     void get_std(){
//         cout<<" rollnumber : "<<rollnu<<"  name : "<<name;
//     }
// };
// class teacher :public person{
// public:
// string subject;
// void set_tea(string name,string sub){
//     person::name=name;
//     subject=sub;
// }
// void get_tea(){
//     cout<<"\nname : "<<name<<"   subject : "<<subject<<endl;
// }

// };
// int main(){
//     student s1;
//     s1.set_std("usman",1);
//     s1.get_std();
//     teacher t1;
//     t1.set_tea("maheen","oop");
//     t1.get_tea();
//     system("pause");
// }
// 📝 Task 2: Protected Inheritance Example
// Make a class Library with protected booksCount and a public method displayBooks().

// Create a Department class that inherits it protectedly.

// Inside Department, create a method that modifies and shows booksCount.

// ✅ Goal: Understand how protected inheritance affects visibility


// #include<iostream>
// using namespace std;
//  class library{
// protected:
// int bookcount;
// public:
// library(){
//     bookcount=0;
// }
// library(int bookcoun){
//     bookcount=bookcoun;
// }
// void display(){
//     cout<<"book count : "<<bookcount<<endl;
// }
//  };
//  class department:protected library{
// public:
// void modify(int n){
//     bookcount=n;
// }
// void get(){
//     display();
// }
//  };
// int main(){
//     library l1(50);
//     l1.display();
//     department d1;
//     d1.modify(30);
//     d1.get();
// system("pause");
// }

// 📝 Task 3: Private Inheritance Simulation
// Class LoginSystem has methods like authenticate(), logout().

// Class AdminPanel privately inherits LoginSystem.

// Inside AdminPanel, only allow access to authenticate() through a controlled method.

// ✅ Goal: See how private inheritance is useful to hide internal functionalities.

// 📝 Task 4: Virtual Functions and Polymorphism
// Base class User has a virtual function getDetails().

// Student, Teacher, and Admin override getDetails() to display their details.

// Store them in a User* array and call getDetails() polymorphically.

// ✅ Goal: Practice runtime polymorphism in inheritance.

// 📝 Task 5: Mini Project – University Directory
// Create a console-based menu where you can:

// Add students and teachers.

// Display their info using inheritance.

// Store their data in a file (use ofstream/ifstream).

// Use inheritance for Person → Student and Person → Teacher.

// ✅ Goal: Combine OOP + file handling + inheritance.

// Would you like the solution or template for any of these tasks to help you get started?
// #include<iostream>
// using namespace std;
// class sm{
// public:
// void verifypin(){
//     cout<<"pin is correct"<<endl;
// }
// void logacess(){
//     cout<<"acess logged "<<endl;
// }
// };
// class bm:private sm{
// public:
// void approveloan(){
//     verifypin();
//     logacess();
//     cout<<"loan approved";
// }
// };
// int main(){
//     bm a;
//     a.approveloan();
//     // a.verifypin();
// }