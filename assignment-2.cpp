#include<iostream>
using namespace std;
class vehicle{
    public:
    int total_wheels;
    int milage;
    vehicle(int tw,int m){
        total_wheels=tw;
        milage=m;
    }
};
class car:public vehicle{
public:
int speed;
car(int tw,int m,int s):vehicle(tw,m){
    speed=s;
}
void cget(){
    cout<<"\ntotal_wheels : "<<total_wheels;
     cout<<"\nmilage : "<<milage;
cout<<"\nspeed : "<<speed;
}
};
class bike:public vehicle{
public:
int doors;
bike(int tw,int m,int s):vehicle(tw,m){
    doors=s;
}
void bget(){
cout<<"\ntotal_wheels : "<<total_wheels;
cout<<"\nmilage : "<<milage;
cout<<"\ndoor : "<<doors;
}
};
int main(){
    car c1(4,12,90);
    bike b1(2,15,0);
    c1.cget();
    b1.bget();
    system("pause"); 

}