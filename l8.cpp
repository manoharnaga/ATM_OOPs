#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define cline cout<<"------------------------------------------------------------\n"

// polymorphism

class base{
public:
    void basefunc1(){
        cout<<"Base Func1\n";
    }
    void basefunc2(){
        cout<<"Base Func2\n";
    }
};


class derived: public base{
public:
    void extra1(){
        cout<<"Derived Extra func1\n";
    }
    void extra2(){
        cout<<"Derived Extra func2\n";
    }
    void extra3();
};

void derived::extra3(){
    cout<<"Derived Extra func3\n";
}


class derv1: public base{
public:
    derv1(){
        cout<<"Derived Class 1\n";
    }
};

class derv2: public derv1{
public:
    derv2(){
        cout<<"Derived Class 2\n";
    }
};


int main(){
    base* ptr;
    derived d;

    ptr = &d;   //<===> ptr = new derived();
    ptr->basefunc1();
    // ptr->extra1(); not accessible
    d.extra1();
    d.extra3();
    cline;

    derv1 d1;
    derv2 d2;
    cout<<"\n";
    ptr = new derv1();
    ptr = new derv2();

    
    return 0;
}