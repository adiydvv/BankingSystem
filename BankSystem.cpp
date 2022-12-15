#include<iostream>
using namespace std;
int TransferMoney;
string NAME;
int PASS;
int DepsoitMoney;
int WithdrawMoney;
int Tranfer;

void start();
void login();
void NewUser();
void transfer();

class User{
    public:
    string Name;
    int Password;
    int Balance;

};
User *user[50];
int k = -1;    
void start();

    
void start(){

    cout << "1. Login" << endl << "2. New User" << endl << "3. Exit" << endl;
    int n; cin >> n;
    switch(n){
    case 1:
        login();
        break;
    case 2:
        NewUser();
        break;
    case 3:
        return;
    default:
        cout << "Invalid Input" << endl;
        break;
    }
}
void AccountDetails(User *user){
    cout << "Hello " << user->Name << endl;
    
    cout << "Your bank balance is: " << user->Balance << endl;
    cout << "What do you want to do: " << endl;
    cout << "1.Deposit" << "\n2.Withdraw" << "\n3.Transfer to another user" << "\n4.Exit"  << endl;
    int n; cin >> n;
    switch (n){
        case(1):
        cout << "How much money would you like to deposit: " << endl;
        cin >> DepsoitMoney;
        user->Balance = user->Balance + DepsoitMoney;
        cout << "Your new bank balance is: " << user->Balance << endl;
        AccountDetails(user);
        break;
        case(2):
        cout << "How much money would you like to withdraw: " << endl;
        cin >> WithdrawMoney;
        if(user->Balance >= WithdrawMoney){
            user->Balance = user->Balance - WithdrawMoney;
            cout << "Your new bank balance is: " << user->Balance << endl;
            AccountDetails(user);}
        else{
            cout << "You don't have sufficient balance in your account" << endl;
            AccountDetails(user);
        }
        break;
        case(3):
        cout << "How much money would you like to transfer: " << endl;
        cin >> TransferMoney;
        if(user->Balance >= TransferMoney){
        cout << "Enter the user name of the account you want to transfer the money to" << endl;
        cin >> NAME;
        user->Balance -= TransferMoney;
        transfer();
        AccountDetails(user);
        }
        else{
            cout << "You don't have sufficient balance in your account" << endl;
            AccountDetails(user);
        }
        break;
        case(4):
        start();
        default:
        cout << "Invalid choiice\n";
        AccountDetails(user);
        break;
        }
    }
void transfer(){
    int p = 0;
    for(int i=0; i<10; i++) {
        if(user[i]->Name == NAME){
            p = 1;
            cout << "Amount transferred successfully" << endl;
            user[i]->Balance = user[i]->Balance + TransferMoney;
        }
        else
            continue;
        }
        if(p =0){           
            cout << "User not found\n";
        }
}
void login(){
    int q = 0;
    cout << "Enter your Name: ";
    cin >> NAME;
    for(int i = 0; i < 50; i++){
        if(user[i]->Name == NAME){
            q = 1;
            cout << "Enter your password: ";
            cin >> PASS;
            if(PASS == user[i]->Password)
            AccountDetails(user[i]);
            else
                cout << "Wrong password\n";
                start();}
        else{
                continue;
                }
        }
    if(q =1){
        cout << "User not found\n";
        start();
    }
        
    }
    
   
void NewUser(){
    k++;
    cout << "Enter your Name: ";
    cin >> NAME;
    cout << "Enter your password: ";
    cin >> PASS;
    user[k] = new User();
    user[k]->Name = NAME;
    user[k]->Password = PASS;
    start();
}
int main(){
    start();
    return 0;
}