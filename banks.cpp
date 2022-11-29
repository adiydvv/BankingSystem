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

class User{
    public:
    string Name;
    int Password;
    int Balance;

};




    User *user[50];
    
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
        switch (n)
        {
        case(1):
        cout << "How much money would you like to deposit: " << endl;
        cin >> DepsoitMoney;
        user->Balance = user->Balance + DepsoitMoney;
        cout << "Your new bank balance is: " << user->Balance << endl;
        break;
        case(2):
        cout << "How much money would you like to withdraw: " << endl;
        cin >> WithdrawMoney;
        user->Balance = user->Balance - WithdrawMoney;
        cout << "Your new bank balance is: " << user->Balance << endl;
        break;
        case(3):
         cout << "How much money would you like to transfer: " << endl;
        cin >> TransferMoney;
        cout << "Enter the user name of the account you want to transfer the money to" << endl;
        cin >> NAME;
        for(int i=0; i<10; i++) {
            if(user[i].Name == NAME){
                user[i].Balance += TransferMoney;
                user->Balance -= TransferMoney;
                cout << "Amount transferred successfully" << endl;
            }
            else{
                cout << "No user found\n";
                AccountDetails(user);
            } 
                    
            }
        break;
        case(4):
        start();
        default:
        cout << "Invalid choiice\n";
        break;
        }
    }
    void login(){
        cout << "Enter your Name: ";
        cin >> NAME;
        for(int i = 0; i < 50; i++){
            if(user[i]->Name == NAME){
                cout << "Enter your password: ";
                cin >> PASS;
                if(PASS == user[i]->Password)
                AccountDetails(user[i]);
                else
                cout << "Wrong password\n";}
            else{
                cout << "No user found\n";
                 }
        }
    }
    
   
    void NewUser(){
        cout << "Enter your Name: ";
        cin >> NAME;
        cout << "Enter your password: ";
        cin >> PASS;
        int k = 0;
        user[k]->Name = NAME;
        user[k]->Password = PASS;

        k += 1;

        start();
    }
    int main(){
    start();
    return 0;
}