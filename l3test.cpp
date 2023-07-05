#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007


// program

class Phone{
private:
    string name,processor;
    int RAM;
    float battery;
public:
    Phone(string name_a="Null",int RAM_a=0,string processor_a="Null",int battery_a=0.0f){
        name = name_a;
        RAM = RAM_a;
        processor = processor_a;
        battery =  battery_a;
    }

    Phone(Phone &p){
        name = p.name;
        RAM = p.RAM;
        processor = p.processor;
        battery =  p.battery;
    }

    void getData();
};

void Phone::getData(){      
    cout<<"Name:\t"<<name<<"\n";
    cout<<"RAM:\t"<<RAM<<" GB\n";
    cout<<"Processor:\t"<<processor<<"\n";
    cout<<"Battery:\t"<<battery<<"mAh\n";
    cout<<"\n";
}

int main(){
    Phone p1,p2("RedmiY1Lite",4,"Snapdragon662",3760.0f),p3(p2);

    p1.getData();
    p2.getData();
    p3.getData();
    return 0;
}