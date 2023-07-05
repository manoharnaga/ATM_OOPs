#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define cline cout<<"\n"


// Inheritance

class rect{
public:
    int length,breadth;
    rect(int length_a=0,int breadth_a=0){
        length = length_a;
        breadth = breadth_a;
    }
    void getData(){
        cout<<"Length: \t"<<length<<"\n";
        cout<<"Breadth:\t"<<breadth<<"\n";
    }
    void area(){
        cout<<"Area:   \t"<<length*breadth<<"\n";
    }
};

class cuboid:public rect{
private:
    int height;
public:
    void setHeight(int x=0){
        height = x;
    }
    void getData(){
        cout<<"Length: \t"<<length<<"\n";
        cout<<"Breadth:\t"<<breadth<<"\n";
        cout<<"Height: \t"<<height<<"\n";
    }
    void volume(){
        cout<<"Volume: \t"<<length*breadth*height<<"\n";
    }
};

int main(){
    rect r1(12,13);
    r1.getData();
    cline;
    r1.area();

    cuboid c1;
    c1.length = 12;
    c1.breadth = 13;
    c1.setHeight(15);
    cline;

    c1.getData(); 
    cline;

    c1.area();
    cline;

    c1.volume();
    cline;

    return 0;
}