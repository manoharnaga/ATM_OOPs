#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007


// Constructor - initialise while allocating memory only
// compiler has it's default constructor if no constructor is used that allocates memory to mem var's without intiliasing



class Person{
private:
    string name;
    int age;
    float height;
public:
    
    // Person(){               // Non-Parametrized constructor
    //     name = "Null";
    //     age = 0;
    //     height = 0.0f;
    // }

    // Person(string name_a,int age_a,float height_a){ // Parametrized constructor
    //     name = name_a;
    //     age = age_a;
    //     height = height_a;
    // }

    // Constructor Overloading
    Person(string name_a = "Null",int age_a = 0,float height_a = 0.0f){ // Non-Parametrized & Parametrized
        name = name_a;
        age = age_a;
        height = height_a;
    }


    Person(Person &obj){                // Copy constructor
        name = obj.name;
        age = obj.age;
        height = obj.height;
    }

    void getData(){
        cout<<"Name:\t"<<name<<"\n";
        cout<<"Age:\t"<<age<<"\n";
        cout<<"Height:\t"<<height<<"\n";
        cout<<"\n";
    }

};

int main(){
    // constructors are called during declaration
    Person obj1, obj2("man",19,5.3f);
    Person obj3(obj2);

    obj1.getData();  // allocated memory for member variables & initialized
    obj2.getData();
    obj3.getData();

    return 0;
}