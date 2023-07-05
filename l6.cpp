#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define cline cout<<"\n"

// Constructors & Inheritance




class base{
public:
    base()
    {
        cout<<"Def constructor of base class\n";
    }

    base(int x_a)
    {
        cout<<"Para constructor of base class:\t"<<x_a<<"\n";
    }
};


// 1.
class derived1:public base{
    // Empty
};


//2.    
class derived2:public base{
public:
    derived2()
    {
        cout<<"Def constructor of derived class\n";
    }

    derived2(int x)
    {
        cout<<"Para constructor of derived class:\t"<<x<<"\n";
    }
};


//3.
class derived3:public base{
public:
    derived3():base()
    {
        cout<<"Def constructor of derived class\n";
    }

    derived3(int x):base(x)
    {
        cout<<"Para constructor of derived class:\t"<<x<<"\n";
    }
};


int main(){
    cout<<"d1\n";
    derived1 d;
    cline;
    cline;

    cout<<"d2\n";
    derived2 d1;
    cline;
    derived2 d2(11); // no call to para constructor of base class
    cline;
    cline;

    cout<<"d3\n";
    derived3 d4;
    cline;
    derived3 d5(131);
    cline;
    return 0;
}
