#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define cline cout<<"------------------------------------------------------------\n"
#define nline cout<<"\n"
#define PRESSKEY cout<<"\n\t\t<<PRESS ENTER TO CONTINUE>>\n"
// 

void clrScreen(){
    system("clear");
}

void nextPage(){
    PRESSKEY;
    cin.ignore();
    cin.get();
    clrScreen();
}

void exitATM(){
    clrScreen();
    cout<<"Thank you for using the ATM.\n";
    exit(1);
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
        cline;
        cout<<"WELCOME TO ManoAtm!!\n";
        cline;
        cout<<"1. Login\n";
        cout<<"2. Signup\n";
        cout<<"3. Quit\n";
        int inp;
        cin>>inp;
        if(inp==1){
            login();
        }
        else if(inp==2){
            signup();
            return 1;
        }
        else{
            exitATM();
        }
        return 0;
    }

    int check(ll acNo,string name,int pin,ll phNo,long double curbal){
        int f=1;
        for(char ch: name){
            if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z')) continue;
            f=0;
            break;
        }
        int cnt=0;
        while(pin){
            pin/=10;cnt++;
        }
        int pinflag=(cnt==4);
        cnt=0;
        while(phNo){
            phNo/=10;cnt++;
        }
        int phNoflag=(cnt==10);
        return  pinflag && phNoflag && (curbal>=0.0) && f;
    }

    void login(){
        clrScreen();
        cout<<"Account Number:\t";
        ll acNo;
        cin>>acNo;
        int ind=findUser(uarr,acNo,sz);
        if(ind==-1){
            clrScreen();
            cout<<"No account Found,Please try again\n";
            nextPage();
            ui1();
            return;
        }
        clrScreen();
        cout<<"Enter 4-digit pin:\t";
        int pin;
        cin>>pin;
        clrScreen();
        if(uarr[ind].getPIN()!=pin){
            cout<<"PIN INVALID!!\n";
            nextPage();
            ui1();
        }
        else{
            cout<<"Select an option from below:\n";
            cout<<"1.Check Balance\n";
            cout<<"2.Cash WithDrawal\n";
            cout<<"3.Show Account Details\n";
            cout<<"4.Update Mobile No.\n";
            cout<<"5.Quit\n";
            int inp;
            cin>>inp;
            clrScreen();
            if(inp==1){
                cout<<"Your Current Account Balance:\t"<<uarr[ind].getBalance()<<"/-\n rupees only\n";
                nextPage();
            }
            else if(inp==2){
                uarr[ind].cashwithDraw();
                nextPage();
            }
            else if(inp==3){
                uarr[ind].showUser();
                nextPage();
            }
            else if(inp==4){
                ll oldNo,newNo;
                cout<<"Enter Old Number:\t";
                cin>>oldNo;
                cout<<"Enter New Number:\t";
                cin>>newNo;
                if(!uarr[ind].updateMobileNo(oldNo,newNo)){
                    nextPage();
                    ui1();
                }
                else{
                    nextPage();
                }
            }
            else{
                exitATM();
            }
        }
    }

    void signup(){
        clrScreen();
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
        if(!check(acNo,name,pin,phNo,curbal)){
            cout<<"INVALID CREDENTIALS!";
            nextPage();
            ui1();
            return;
        }
        user u1(acNo,name,pin,phNo,curbal);
        sz++;
        uarr[sz-1]=u1;
        clrScreen();
        cout<<"\tCongratulations,your account is created!!\n";
        nextPage();
    }
    static int sz;
};

int ui::sz = 0;





int main(){
    while(1){
        ui* ptr = new ui();
        if(ptr->ui1()) ptr->ui1();

        delete ptr;
        // break;
    }
    return 0;
}