// C++ Program to show the working of
// static member functions
#include <iostream> 
#include<cstring>
using namespace std;
class account{
public:
	char holder[50];
	float balance=0;
	float interest_rate=0.00;
	float fixed_deposit_rate =0.00;

	int type;
	
	void deposit(float deposit){
	balance=balance+deposit;
	}
        void withdraw(float amount){
	balance = balance-amount;
	}
}; 
class saving_account:public account{

     public:
     	saving_account(const char *name)
     	{
     		strcpy(holder,(char*)name);
     		type=0;
     	}
	
	
};

class current_account: public account {
private:
	public:
		current_account(const char *name)
     	{
     		strcpy(holder,(char*)name);
     		type=1;
     	}
	
	};
void print_saving_account(account *ac) 
{
cout <<"holder : "<< ac->holder<< endl;
cout <<"balance : "<< ac->balance << endl;
cout <<"interest rate : "<< ac->interest_rate<< endl;
cout <<"FD rates : "<< ac->fixed_deposit_rate << endl;
}
void print_current_account(account *ac) {

cout <<"holder : "<< ac->holder<< endl;
cout <<"balance : "<< ac->balance << endl;
cout <<"interest rate : "<< ac->interest_rate<< endl;
cout <<"FD rates : "<< ac->fixed_deposit_rate << endl;
}
double fixed_deposit_rate(account *ac) 
{
return (ac->type==0) ? 6.5 : 4.0;
}

void delete_account(account *ac) {delete ac;}

int main() {

saving_account *s_ac =new saving_account("john");
s_ac->deposit(1000);
s_ac->withdraw(100.30);
print_saving_account(s_ac);

cout<<fixed_deposit_rate(s_ac);
cout<<endl;

current_account *c_ac =new current_account("deepak");
c_ac->deposit(1000);
c_ac->withdraw(100.30);
print_current_account(c_ac);
cout<<fixed_deposit_rate(c_ac);

delete_account(s_ac);
delete_account(c_ac);
cout << endl;
print_current_account(c_ac);
return 0;

}

