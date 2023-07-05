#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007


// Operator Overloading


class A{
private:
    int weight;
public:
    A(int x=0){ // constructor overloading
        weight=x;
    }
    A addWeight(A &p2){ // traditional
        A temp;
        temp.weight = weight + p2.weight;
        return temp;
    }
    A operator+(A &p2){
        A temp;
        temp.weight = weight+ p2.weight;
        return temp;
    }

    void operator++(){ // pre-increment
        ++weight;
    }

    void operator++(int){ // post-increment
        weight++;
    }

    A operator%(A &p2){
        A temp;
        temp.weight = weight%p2.weight;
        return temp;
    }

    void getData();
};

void A::getData(){
    cout<<"Weight:\t"<<weight<<"\n";
}

int main(){
    int a,b,c;
    a=63;
    b=18;
    c = a + b;
    cout<<c<<"\n";

    A p1(a),p2(b);
    A total;    
    total = p1.addWeight(p2);
    total.getData();
    total = p2.addWeight(p1);
    total.getData();
    cout<<"\n";

    total = p1 + p2;
    total.getData();

    // pre/post-increment
    ++p1;
    p1.getData();
    p1++;
    p1.getData();

    total = p1%p2;
    total.getData();
    p1 = p1%p2;
    p1.getData();
    
    return 0;
}