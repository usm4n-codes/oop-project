#include<iostream>
#include<fstream>
#include<iomanip>
#include<sstream>
using namespace std;
class student{
    int pass;
    public:
    string name;
    int rollnumber;
    string semester;
    float gpa;
    void setpass(int pass){
        this->pass=pass;
    }
    void getpass(){
        cout<<pass;
    }

};
int main(){
student s[3];
int pass;
ofstream fout;
fout.open("studentdata");
fout<<left;
fout<<setw(11)<<"name"<<","<<setw(7)<<"SR NO"<<","<<setw(9)<<"semester"<<","<<setw(5)<<"GPA"<<","<<setw(10)<<"password"<<endl;
for(int i=0;i<2;i++){
    cout<<"enter name of "<<i+1<<" student : ";
    cin>>s[i].name;
    
     cout<<"enter rollnumber of "<<i+1<<" student : ";
     cin>>s[i].rollnumber;
     
      cout<<"enter semester of "<<i+1<<" student : ";
      cin>>(s[i].semester);
      
       cout<<"enter gpa of "<<i+1<<" student : ";
       cin>>s[i].gpa;
       
       cout<<"enter pass of "<<i+1<<" student : ";
       cin>>pass;
       s[i].setpass(pass);

          fout<<setw(11)<<s[i].name<<","
           <<setw(7)<<s[i].rollnumber<<","
            <<setw(9)<<s[i].semester<<","
            <<setw(5)<<s[i].gpa<<","
            <<setw(10)<<pass<<endl;
       system("cls");
}
fout.close();
ifstream fin;
string line,l2;
fin.open("studentdata");

 while (getline(fin, line)) {  // safer than while (!fin.eof())
        stringstream ss(line);

        while (getline(ss, l2, ',')) {  // read tokens separated by comma
            cout << l2<<"|" ;
        }
       cout<<endl;
 }
fin.close();
system("pause");
}