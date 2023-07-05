#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define cline cout<<"------------------------------------------------------------\n"
#define nline cout<<"\n"

// 

void clrScreen(){
    system("clear");
}

class user{
private:
    int atmPIN;
    ll accountNo;
    string name;
    long double curbalance;
    ll phoneNo;

public:
    user(ll acNo=-1LL,string name_a="user#",int pin=-1,ll phNo=1234567890LL,long double curbal=0.0f){
        accountNo = acNo;
        name = name_a;
        phoneNo = phNo;
        atmPIN = pin;
        curbalance = curbal;
    }

    ll getaccounNo(){
        return accountNo;
    }

    string getName(){
        return name;
    }

    ll getphNo(){
        return phoneNo;
    }

    ll getPIN(){
        return atmPIN;
    }

    long double getBalance(){
        return curbalance;
    }

    void cashwithDraw(){
        clrScreen();
        long double cash;
        cout<<"Enter the amount in rupees:\t";
        cin>>cash;
        if((curbalance-cash)>=0){
            cout<<"Please collect your amount::\t"<<cash<<"/-\n rupees only\n";
            curbalance -= cash;
            // cout<<curbalance<<"\n";
        }
        else{
            cout<<"Insufficient Funds!!\n";
        }
    }

    void showUser(){
        clrScreen();
        cout<<"Name:\t"<<name<<"\n";
        cout<<"Account.No:\t"<<accountNo<<"\n";
        cout<<"Phone.No:\t"<<phoneNo<<"\n";
    }

    int updateMobileNo(ll oldNo,ll newNo){
        if(phoneNo == oldNo){
            phoneNo = newNo;
            cout<<"Phone Number updated successfully!!\n";
            return 1;
        }
        else{
            cout<<"Old Phone Number -- INVALID\n";
            return 0;
        }
    }
};

user uarr[100];

int findUser(user* uarr,ll acNo,int sz){
    for(int i=0;i<sz;i++){
        if(uarr[i].getaccounNo() == acNo){
            return i;
        }
    }
    return -1;
}

class ui{
public:
    ~ui(){
        // cout<<"Destructor called\n";
    }
    int ui1(){
        clrScreen();
        cout<<"1. Login\n";
        cout<<"2. Signup\n";
        cout<<"3. Quit\n";
        int inp;
        cin>>inp;
        if(inp==1){
            login();
            return 0;
        }
        else if(inp==2){
            signup();
            return 1;
        }
        else{
            exit(1);
        }
    }

    void login(){
        loginline:
        clrScreen();
        cout<<"Account Number:\t";
        ll acNo;
        cin>>acNo;
        int ind=findUser(uarr,acNo,sz);
        if(ind==-1){
            cout<<"No account Found,Please try again\n";
            // getchar();
            // ui1();
            return;
        }
        
        cout<<"Enter 4-digit pin:\t";
        int pin;
        cin>>pin;
        
        if(uarr[ind].getPIN()!=pin){
            cout<<"PIN INVALID!!\n";
            goto loginline;
        }
        else{
            clrScreen();
            cout<<"Select an option from below:\n";
            cout<<"1.Check Balance\n";
            cout<<"2.Cash WithDrawal\n";
            cout<<"3.Show Account Details\n";
            cout<<"4.Update Mobile No.\n";
            cout<<"5.Quit\n";
            int inp;
            cin>>inp;
            if(inp==1){
                cout<<"Your Current Account Balance:\t"<<uarr[ind].getBalance()<<"/-\n rupees only\n";
            }
            else if(inp==2){
                uarr[ind].cashwithDraw();
            }
            else if(inp==3){
                uarr[ind].showUser();
            }
            else if(inp==4){
                phline:
                ll oldNo,newNo;
                cout<<"Enter Old Number:\t";
                cin>>oldNo;
                cout<<"Enter New Number:\t";
                cin>>newNo;
                if(!uarr[ind].updateMobileNo(oldNo,newNo)) goto phline;
            }
            else{
                cout<<"Kuch Nahi\n";
                exit(1);
            }
        }
    }

    void signup(){
        string name;
        ll acNo,phNo;
        int pin;
        long double curbal;
        cout<<"Name:\t";
        cin>>name;
        cout<<"Account.No:\t";
        cin>>acNo;
        cout<<"Enter 4-digit pin:\t";
        cin>>pin;
        cout<<"Account Balance:\t";
        cin>>curbal;
        cout<<"Phone.No:\t";
        cin>>phNo;
        user u1(acNo,name,pin,phNo,curbal);
        sz++;
        uarr[sz-1]=u1;
        cout<<"Congratulations,your account is created!!\n";
    }
    static int sz;
};

int ui::sz = 0;





int main(){


    cline;
    cout<<"WELCOME TO ManoAtm!!\n";
    cline;
    while(1){
        ui* ptr = new ui();
        if(ptr->ui1()) ptr->ui1();

        delete ptr;
        // break;
    }
    return 0;
}