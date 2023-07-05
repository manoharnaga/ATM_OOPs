#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

class house{
private:
    int length,breadth;
public:
    void setData(int x,int y){
        length=x;breadth=y;
    }
    void area(){
        cout<<"Area:\t"<<(length*breadth)<<"\n";
    }
};

int main(){
    house h1; //memory allocated
    h1.setData(300,450);
    h1.area();

    // h1.length = 350; //inaccessible - private

    house h2,h3;    // here h1,h2,h3 share member functions - setData(),area()
    h2.setData(150,200);
    h2.area();

    h3.setData(100,150);
    h3.area();

    return 0;
}