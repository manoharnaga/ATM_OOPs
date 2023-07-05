#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define cline cout<<"------------------------------------------------------------\n"

// Friend Class

class Alpha{
private:
    int a1;
public:
    Alpha(int x=0){
        a1=x;
    }
    friend class Beta;
};

class Beta{
private:
    int b1;
public:
    Beta(int x=0){
        b1=x;
    }
    int sum(){
        Alpha a_obj(3);
        return (a_obj.a1+b1);
    }
};

int main(){
    Beta b_obj(8);
    cout<<"Sum:\t"<<b_obj.sum()<<"\n";
    return 0;
}