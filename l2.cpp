#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007


// Acess specifiers

class house{
private:
    int length,breadth;
protected:             // accessed only in inheriting class
    int height; 
public:
    void setData(int x,int y){
        length=x;breadth=y;
    }
    void area(){
        cout<<"Area:\t"<<(length*breadth)<<"\n";
    }
};

// inheriting class
class cost: public house{
public:
    void setHeight(int x=0){
        height = x;
    }
    void getHouseCost(int permetersq){
        cout<<"Cost of height: "<<height*permetersq<<"\n";
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

    cost c;
    c.setData(5,6);
    c.area();
    c.setHeight(13);
    c.getHouseCost(5);
    return 0;
}