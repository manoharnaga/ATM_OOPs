#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define cline cout<<"\n"

// overriding functions

class base{
public:
    void Msg(){
        cout<<"This is base class\n";
    }
};

class derived:public base{
public:
    void Msg(){
        cout<<"This is derived class\n";
    }

    void Msg2(){
        cout<<"This is derived class_2\n";
        base::Msg();
    }
};



int main(){
    base b1;

    b1.Msg();
    cline;

    
    derived d1;
    
    d1.Msg();
    cline;
    d1.Msg2();
    cline;

    return 0;
}