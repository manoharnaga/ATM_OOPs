#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define cline cout<<"------------------------------------------------------------\n"


// comparison operator overloading

// p1,p2 -- person
class p1{
private:
    int weight;
public:
    p1(int weight_a=0){
        weight=weight_a;
    }
    int operator >(p1 person){
        return weight > person.weight;
    }
    int operator <(p1 person){
        return weight < person.weight;
    }
};

class p2{
private:
    int weight;
public:
    p2(int w=0){
        weight=w;
    }
    friend bool operator > (p2 p21,p2 p22); //member function cannot take to p2 objects as parameters
    friend bool operator < (p2 p21,p2 p22); // so we use friend functions
};

bool operator > (p2 p21,p2 p22){
    return p21.weight > p22.weight;
}

bool operator < (p2 p21,p2 p22){
    return p21.weight < p22.weight;
}

int main(){
    int x,y;
    cin>>x>>y;
    p1 john(x);
    p1 rick(y);
    if(john > rick) cout<<"John is heavier!\n";

    if(john < rick) cout<<"Rick is heavier!\n";

    cline;
    
    cin>>x>>y;
    p2 alice(x);
    p2 bob(y);
    if(alice > bob) cout<<"Alice is heavier!\n";

    if(alice < bob) cout<<"Bob is heavier!\n";
    return 0;
}