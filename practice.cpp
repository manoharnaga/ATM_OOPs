#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define cline cout<<"\n"

//
class Person{
protected:
    string name;
    int age;
    int height;
public:
    void setData(string name_a,int age_a){
        name = name_a;
        age = age_a;
    }
    
    Person operator +(Person& p1){
        Person total;
        total.name= name+p1.name;
        total.age = age+p1.age;
        return total;
    }

    int operator >(Person p1){
        return (age>p1.age);
    }
    int operator <(Person p1){
        return (age<p1.age);
    }
    void getData();
};

void Person::getData(){
    cout<<"Name:\t"<<name;cline;
    cout<<"Age:\t"<<age;cline;
    cout<<"Height:\t"<<height;cline;
}


class setH: public Person{
public:

    setH(){
        name="Null";
        age=0;
        height=13;
    }

    setH(string name_a,int age_a,int height_a){
        name=name_a;
        age=age_a;
        height=height_a;
    }

    // setH(string name_a="Null",int age_a=0,int height_a=13){
    //     name=name_a;
    //     age=age_a;
    //     height=height_a;
    // }
    
    void operator ++(){
        ++height;
    }

    setH(setH& s1){
        name=s1.name;
        age=s1.age;
        height=0;
    }

    void fullData(){
        cout<<"Name:\t"<<name;cline;
        cout<<"Age:\t"<<age;cline;
        cout<<"Height:\t"<<height;cline;
    }
};




class c1{
protected:
    int a,b;
public:
    c1(int x=-1,int y=-1){
        a=x;
        b=y;
    }

    void getData(){
        cout<<a;cline;
        cout<<b;cline;
    }
};


class c2: protected c1{
protected:
    int c,d;
public:
    c2(int x=-1,int y=-1,int z=-1,int k=-1){
        a=x;
        b=y;
        c=z;
        d=k;
    }
    void getData(){
        cout<<a;cline;
        cout<<b;cline;
        cout<<c;cline;
        cout<<d;cline;
    }
};


class c3: protected c2{
public:
    c3(int x=-1,int y=-1,int z=-1,int k=-1){
        a=x;
        b=y;
        c=z;
        d=k;
    }
    void getData(){
        cout<<a;cline;
        cout<<b;cline;
        cout<<c;cline;
        cout<<d;cline;
    }
};

int main(){
    Person p1;
    p1.getData();
    p1.setData("Herwe",31);
    p1.getData();
    cline;
    setH s1("Morpheous",134,5671);
    // s1.setData("Mdfer",13);
    s1.fullData();
    cline;
    setH s2(s1);
    s2.fullData();
    cline;
    cline;
    Person p2;
    p2.setData("Gerwe",27);
    Person total;
    total = p1 + p2;
    total.getData();cline;
    total = p2 + p1;
    total.getData();cline;

    ++s1;
    s1.fullData();

    c1 cx(7,11);
    cx.getData();cline;

    c2 cxy(1,2,3,4);
    cxy.getData();cline;

    c3 cxyz(4,3,2,1);
    cxyz.getData();cline;

    if(p1 > p2) cout<<"Yes\n";
    if(p2 < p1) cout<<"No\n";
    return 0;
}