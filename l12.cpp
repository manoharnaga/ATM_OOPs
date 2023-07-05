#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define cline cout<<"\n"

//
class Alpha{
private:
    int a,b;
public:
    Alpha(int x=0,int y=0){
        a=x;
        b=y;
        stat++;
    }
    static int stat;        // static member variable

    static int getStat(){   //static member function
        stat++;
        return stat;
    }
};

int Alpha:: stat = 0;// initialise


int main(){
    cout<<Alpha::getStat()<<"\n";
    cline;

    Alpha a1;
    Alpha a2;
    cout<<"Value using -- a1:\t"<<a1.stat<<"\n";
    cout<<"Value using -- a2:\t"<<a2.stat<<"\n";
    cout<<"Value using -- Alpha:\t"<<Alpha::stat<<"\n";
    

    cline;
    cout<<"Value using -- a1:\t"<<a1.getStat()<<"\n";
    cout<<"Value using -- a2:\t"<<a2.getStat()<<"\n";
    cout<<"Value using -- Alpha:\t"<<Alpha::getStat()<<"\n";
    

    return 0;
}