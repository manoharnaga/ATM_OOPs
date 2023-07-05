#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define cline cout<<"------------------------------------------------------------\n"

// polymorphism

class base{
public:
    void func(){
        cout<<"Base class\n";
    }
    virtual void vfunc(){
        cout<<"v - Base class\n";
    }
    virtual int f() = 0;    // pure virtual function
    
    // virtual void give() = 0; error??
};


class derv1: public base{
public:
    void func(){
        cout<<"Derived Class 1\n";
    }
    void vfunc(){
        cout<<"v - Derived Class 1\n";
    }
    virtual int f(){ return 0;} 
};

class derv2: public derv1{
public:
    void func(){
        cout<<"Derived Class 2\n";
    }
    void vfunc(){
        cout<<"v - Derived Class 2\n";
    }
    int f(){ return 3;}
};


int main(){
    base* ptr;
    
    derv1 d1;
    derv2 d2;
    cout<<d1.f()<<"\n";   // executes as it is in the same parent class derv1
    cout<<d2.f()<<"\n";
    cline;
    ptr = &d1;  
    ptr->func();      // Base class
    ptr = &d2;  
    ptr->func();      // Base class


    // now change base class function to virtual
    ptr = &d1;
    ptr->vfunc();
    ptr = &d2;
    ptr->vfunc();
    
    return 0;
}