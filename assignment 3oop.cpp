#include<iostream>
using namespace std;
class countB;
class countA{
    int valueA;
public:
static int count;
countA(int a){
    count++;
    valueA=a;
}
void get(){
    cout<<"value a ="<<valueA<<endl;
}
friend void sum(countA &,countB &);
};
class countB{
    int valueB;
    public:
   static int count;
countB(int b){
    count++;
    valueB=b;
}
void get(){
    cout<<"value b ="<<valueB<<endl;
}
friend void sum(countA &,countB &);
};
int countA::count=0;
int countB::count=0;
void sum(countA &a,countB &b){
   
    cout<<"sum of A and B IS = "<<a.valueA+b.valueB<<endl;
   
}
int main(){
    countA a1(20),a2(30);
    countB b1(40),b2(50);
    cout<<"count A = "<<countA::count<<endl;
    cout<<"count B = "<<countB::count<<endl;
    sum(a1,b2);
    sum(a2,b2);
    system("pause");
} 