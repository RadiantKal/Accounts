#include <iostream> 
#include <string> 
using namespace std;

class AbstractBankAccount{
	virtual void deposit(int Total)=0;
	virtual void withdrawl(int Total)=0;
	virtual void send(AbstractBank& recipient, int amount)=0;
};


class BankAccount:AbstractBankAccount{

private:
	string Name;
	int Age;
	int AccountNumber;
	int Total;  

public:
	string getName(){
		return Name;
	}
	int getAge(){
		return Age;
	}
	int getAccountNumber(){
		return AccountNumber;
	}
	int getTotal(){
		return Total; 
	}
	void deposit(int total){
		Total += total;
	} 
	void withdrawl(int total){
		Total -= total; 
	}
	 
	BankAccount(string name, int age){
		if (age < 18)
			throw std::invalid_argument("Required Age 18");
		Name = name;  
		Age = age; 
		Total = 0;  
	}
	
	void send(BankAccount& recipient, int amount){
		Total -= amount;
		recipient.Total += amount;
	}
};

class CorporationAccount{
private:
	string CorporationId; 
	string Address; 
	string State;
	int AccountNumber; 
	int Funds; 

public:
	CorporationAccount(string companyName, string address, string state){
		CorporationId = companyName;
		Address = address; 
		State = state;
	}
};

int main(){
	BankAccount b1 = BankAccount("Kalsang Chedak", 21); 
	BankAccount b2 = BankAccount("John Smith", 25); 
}
