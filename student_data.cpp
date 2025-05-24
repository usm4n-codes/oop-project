#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdio>
#include<string>
#include<iomanip>
using namespace std;
class person{
public:
string name;
string id;
void see_student_record();
void see_timetable();
void see_attendence();
};
class student:public person{
    string password;
    public: 
     string semester;
        float gpa;
        int score;
        student(){
            id="00";
            semester="unknown";
            gpa=0.0;
            score=0;
        }
        void set_student( int rn ,string Name, string sem,float GPA,int Score){
            name=Name;
            semester=sem;
            gpa=GPA;
            score=Score;
            id=rn;
         }
         void pass(string pass){
        password=pass;
         }
         string get_pass(){
            return password;
         }
       void add_std();
       void edit_std();
       void del_std();
       void std_login(string name,string pass);
       void acess_std();
       void solve_quiz();
};
class teacher:public person{
    public:
    void teacher_login(string name,string pass);
    void take_attendence();
    void acess_teacher();
    void create_quiz();

};
class admin{
    public:
    void add_std();
    void edit_std();
    void del_std();
    void edit_timetable();
};
int main(){
    person p;
    char opt;
   string pas;
    int role;
    do{
    cout<<"press 1 to login as a student "<<endl;
    cout<<"press 2 to login as a teacher "<<endl;
    cout<<"option :";
    cin>>role;
   
    if(role==1){
        student s;
        cin.ignore();
        cout<<"enter your name :";
        cin>>s.name;
        cout<<"enter your pass :";
        cin>>pas;
        s.pass(pas);
        s.std_login(s.name,s.get_pass());
    }
    if(role==2){
        teacher t;
        cin.ignore();
        cout<<"enter your name :";
        cin>>p.name;
        cout<<"enter your password :";
        cin>>pas;
        t.teacher_login(p.name,pas);
    }
    cout<<"press y to continue :";
    cin>>opt;
     }while(opt=='y'||opt=='Y');
    system("pause");
}
void student:: std_login(string name,string pass){
    ifstream fin;
    int i=0;
    string n,p,c;
    fin.open("std_login.txt");
    bool flag=0;
    while(fin>>n>>c>>p){
        if(name==n && pass==p){
        flag=1;
        break;
    }
    }
    fin.close();
    int choice;
    char opt;
    if (flag){
        acess_std();
    }
    else if(flag==0){
        cout<<"bad"<<endl;
    }
    else{
        cout<<" !!!!!!!!!";
    }
}
void student::acess_std(){
    int choice;
    char opt;
     do{
    cout<<"press 1 to add data "<<endl;
    cout<<"press 2 to delete data "<<endl;
    cout<<"press 3 to see record "<<endl;
    cout<<"press 4 to update record "<<endl;
    cout<<"press 5 to see time table "<<endl;
    cout<<"press 6 to see attendence record"<<endl;
    cout<<"press 7 to solve quiz"<<endl;
    cout<<"choice :";
    cin>>choice;
    if(choice==1){
       add_std();
    }
    else if(choice==2){
    del_std();
    }
    else if(choice==3){
        see_student_record();
    }
    else if(choice==4){
        edit_std();
    }
    else if(choice==5){
        see_timetable();
    }
    else if(choice==6){
        see_attendence();
    }
    else if(choice==7){
        solve_quiz();
    }
    else{
        cout<<"wrong input try again "<<endl;
    }
     cout<<"\npress y to continue :";
     cin>>opt;
     system("cls");
     }while(opt=='y'||opt=='Y');
}
void student ::add_std(){
    student s;
    ofstream fout;
    fout.open("practice.txt",ios::app);
    cout<<"enter roll number :";
    cin>>s.id;
    cout<<"enter your name :";
    cin>>s.name;
    cout<<"enter your section :";
    cin>>s.semester;
    cout<<"enter your score :";
    cin>>s.score;
    fout<<left<<setw(2)<<s.id<<"|"
        <<setw(7)<<s.name<<"|"
        <<setw(8)<<s.semester<<"|"
        <<setw(6)<<s.score<<"|"<<endl;
fout.close();
}
void student::del_std(){
    student s;
    cout<<"\nenter the id to del data :";
    cin>>s.id;
    ifstream fin;
    fin.open("practice.txt");
    string line;
    ofstream fout;
    fout.open("tem.txt");
    string roll;

    while(getline(fin,line)){
    
        istringstream iss(line);
        getline(iss,roll,'|');
        if(roll!=s.id){
            fout<<line<<endl;
        }
    }
    fout.close();
    fin.close();
    remove("practice.txt");
    rename("tem.txt","practice.txt");
}
void person ::see_student_record(){
    ifstream fin;
    string line;
    fin.open("practice.txt");
    while(getline(fin,line)){
        cout<<line<<endl;
    }
    fin.close();
} 
void student::edit_std(){
    student s;
    string line;
    string roll;
    cout<<"enter the roll number to edit data :";
    cin>>s.id;
    ifstream fin;
    fin.open("practice.txt");
    ofstream fout;
    fout.open("tem.txt");
    while(getline(fin,line)){
        istringstream iss(line);
        getline(iss,roll,'|');
   if(roll==s.id){
        cout<<"enter new roll number :";
        cin>>s.id;
        cout<<"enter new name :";
        cin>>s.name;
        cout<<"enter new section :";
        cin>>s.semester;
        cout<<"enter new score :";
        cin>>s.score;
        fout<<left<<setw(2)<<s.id<<"|"
            <<setw(7)<<s.name<<"|"
            <<setw(8)<<s.semester<<"|"
            <<setw(6)<<s.score<<"|"<<endl;
    }
    else{ 
        fout<<line<<endl;
    }
    }
    fin.close();
    fout.close();
    remove("practice.txt");
    rename("tem.txt","practice.txt");    
}
void person ::see_timetable(){
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
void person:: see_attendence(){
    string line;
    ifstream fin;
    fin.open("attendence-practice.txt");
    while(getline(fin,line)){
    cout<<line<<endl;
    }
}
void teacher::take_attendence(){
    int k;
	ifstream finp;
	finp.open("colindex.txt");
	finp>>k;
	finp.close();
	ofstream fiout;
	fiout.open("colindex.txt");
	fiout<<++k;
	fiout.close();
string a[10][k],line;
	ifstream fin;
	fin.open("attendence-practice.txt");
	stringstream sep;
	for(int i=0;i<10;i++)
	{
		getline(fin,line);
		sep.clear();
		sep.str(line);
		for(int j=0;j<k;j++)
		{
			getline(sep,a[i][j],'|');
		}
	}
	fin.close();
	ofstream fout;
	char aten;
	fout.open("attendence-practice.txt");
	for(int i=0;i<10 ;i++)
	{
		for(int j=0;j<k;j++)
		{
			if(j>k-2)
			{
				cout<<"enter attendence of roll no "<<a[i][1]<<" :";
				cin>>aten;
				if(aten=='a'||aten=='A'||aten=='p'||aten=='P')
				{
					a[i][j]=toupper(aten);
				}
				else
				{
					cout<<"wrong input try again "<<endl;
				}
			}
			fout<<a[i][j]<<"|";
		}
		fout<<endl;
	}
	fout.close();
	system("cls");
}
void teacher:: teacher_login(string name, string pass){
 ifstream fin;
    int i=0;
    string n,p,c;
    fin.open("teacher-login.txt");
    bool flag=0;
    while(fin>>n>>c>>p){
        if(name==n && pass==p){
        flag=1;
        break;
    }
    }
    fin.close();
    int choice;
    char opt;
    if (flag){
        teacher::acess_teacher();
    }
    else if(flag==0){
        cout<<"bad"<<endl;
    }
    else{
        cout<<" !!!!!!!!!";
    }   
}
void teacher ::acess_teacher(){
    char ch;
    int opt;
    teacher t;
    cin.ignore();
    do{
    cout<<"press 1 to view student record "<<endl;
    cout<<"press 2 to view time_table "<<endl;
    cout<<"press 3 to view attendence record  "<<endl;
    cout<<"press 4 to take attendence "<<endl;
    cout<<"press 5 to create quiz "<<endl;
    cout<<"choice :";
    cin>>opt;
    system("cls");
    if(opt==1){
        t.see_student_record();
    }
    else if(opt==2){
         t.see_timetable();
    }
    else if(opt==3){
        t.see_attendence();
    }
    else if(opt==4){
        t.take_attendence();
    }
    else if(opt==5){
        t.create_quiz();
    }
    else{
        cout<<"invalid input"<<endl;
    }
     cout<<"press y to continue :";
     cin>>ch;
    }while(ch=='y'||ch=='Y');
}
void teacher::create_quiz(){
            string  pen;
		int CorrectAns, i,correct ;
		char StoreAns[100], UserOption ,complete;
			ofstream cre, ans ;
			cre.open ("create.txt") ;
			i = 0 ;
			cout << "\n-------Create Quiz-------" << endl ;
			cin.ignore();
			do
			{
				cout << "Q" << i+1 << "." ;
				getline(cin,pen) ;
				cre << "Q" << i+1 << "." << pen << endl ;
				
				cout << "Option 1." ;
				getline (cin,pen) ;			
				cre << "1." << pen ;
				
				cout << "Option 2." ;
				getline (cin,pen) ;
				cre << "\t2." << pen ;
				
				cout << "Option 3." ;
				getline (cin,pen) ;
				cre << "\t3." << pen ;
				
				cout << "Option 4." ;
				getline (cin,pen) ;
				cre << "\t4." << pen << endl ;	
				
				cout << "Correct Option: " ;
				cin>>correct;
				StoreAns[i] = correct;
				cre << "Correct Option for Q" << i+1 << "." <<correct<< endl ;

				i++ ;
				cout << "Enter y to end quiz : " ;
				cin>>complete;
                cin.ignore();
				cout << endl ;
			}while(complete!='y');
			cre.close();
}
void student::solve_quiz(){
    string  pen, complete ;
		int CorrectAns, i,UserOption,answer[20] ;
        system ("cls") ;
			int linesprint = 1 ;
			CorrectAns = 0 ;
			ifstream ifs,ans;
			i = 0 ;
			ifs.open ("create.txt") ;
			ans.open("ans.txt");
			while(ans>>answer[i]){
            i++;
			}
			ans.close();
			i=0;
			cout<<"\n\n-------Quiz Started-------"<<endl;
			while (getline (ifs,pen))
			{
				if (linesprint%3!=0)
				{
					cout << pen ;
					cout << endl ;
				}
				else
				{
					cout << "\nEnter Correct Option : " ;
					cin >> UserOption ;
					cin.ignore();
					if (UserOption == answer[i])
					{
						cout<<"good";
						CorrectAns++ ;
					}
					cout << endl ;
					i++ ;
				}
				linesprint++ ;
			}
			ifs.close() ;
            float avg ;
			avg = (CorrectAns/(float)i) * 100 ;
			cout << "\n\n-------Result-------" << endl ;
			cout << "Your Total Score is " << CorrectAns <<" out  of " << i << endl ;
			cout << "Average of Your Score is : " << avg << "%" << endl ;
}