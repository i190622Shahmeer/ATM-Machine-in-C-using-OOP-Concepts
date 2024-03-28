//============================================================================
// Name        : 19i-0622-PROJECT.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

// Muhammad Shahmeer 19i-0622
#include <fstream>
#include <iostream>
using namespace std;


class Transactions 		//Class of "Transactions" that withdraws cash and deposit cash
{				//This is the parent class the main purpose of ATM is to do transactions.
 protected :
 	int withdrawalCash;
 	int depositCash;
	public:
	void EnterWithdrawalAmount(int a)	//method to choose withdraw amount and take it
  	{
  		if(a==1)
  		{
  		withdrawalCash = 20;
  		cout<<"Cash Withdrawed Successfully."<<endl;
  		cout<<"!!! Take Your Money !!!"<<endl<<endl;
  		}
  		if(a==2)
  		{
  		withdrawalCash = 40;
  		cout<<"Cash Withdrawed Successfully."<<endl;
  		cout<<"!!! Take Your Money !!!"<<endl<<endl;
  		}
  		if(a==3)
  		{
  		withdrawalCash = 60;
  		cout<<"Cash Withdrawed Successfully."<<endl;
  		cout<<"!!! Take Your Money !!!"<<endl<<endl;
  		}
  		if(a==4)
  		{
  		withdrawalCash = 100;
  		cout<<"Cash Withdrawed Successfully."<<endl;
  		cout<<"!!! Take Your Money !!!"<<endl<<endl;
  		}
  		if(a==5)
  		{
  		withdrawalCash = 200;
  		cout<<"Cash Withdrawed Successfully."<<endl;
  		cout<<"!!! Take Your Money !!!"<<endl<<endl;
  		}
  		if(a==6)
  		{
  		withdrawalCash = 0;
  		cout<<"Transaction Canceled "<<endl<<endl;
  		}

 	}

 	void EnterDepositCash(int d)	//method to deposit cash in account
 	{
 	if (d==0)
 	{
 	cout<<"Transaction Cancelled."<<endl<<endl;
 	depositCash = 0;
 	}
 	else
 	{
 	depositCash = d / 100;
 	cout<<"!!!Cash Deposited Successfully!!!"<<endl<<endl;
 	}
 	}

};


class Balance : public Transactions	//Balance class is inherited from transactions
{					//This class deals with the balance of account selected
 protected :
 	int balance;
 public:

	void updateBalance(int b) { balance = b;}
	int getBalance() {return balance;}

 	void SubtractWithdrawal()	// method to subtract withdrawal amount from account balance
 		{
 		balance = balance - withdrawalCash;
 		}
 	void AddDepositCash()	 	//method to add deposited cash in account balance balance
 		{
 		balance = balance + depositCash;
 		}

};


class AccountInfo : public Balance  //Class derived from balance class
{				     //To select the user entered account
  private:
  	int AccNo;
  	int Pin;
  public:

 	void setAccNo(int a) {AccNo=a;}	//method to enter Account Number
 	void setPin(int p) {Pin = p;}		//method to enter Pin
 	int getAccNo() {return AccNo;}	//method to get Account No
 	int getPin() {return Pin;}		//method to get Pin

} ;

class AtmScreen 	//The basic class of atm screen which welcomes user
{

 public :
 	virtual void display()		//Repeated Display method
 	{
 	cout<<"WELCOME!"<<endl;
 	}

};

class MainMenu : AtmScreen	//Class dervied from ATM Screen that displays main menu on screen after
{				//account is entered and verified
 public :
 	virtual void display()		//Repeated Display method
 	{
 	cout<<"Main Menu : "<<endl;
 	cout<<"   1 - View my balance"<<endl;
 	cout<<"   2 - Withdraw cash "<<endl;
 	cout<<"   3 - Deposit funds"<<endl;
 	cout<<"   4 - Exit"<<endl;
 	cout<<"Enter a choice : ";
 	}
};

class WithdrawalMenu : MainMenu //Class derived from main menu if user wants to withdraw cash
{				 //Displays withdrawal amount menu on screen
 public :
 	virtual void display()		//Repeated Display method
 	{
 	cout<<"Withdrawal options : "<<endl;
 	cout<<"  1 - $20      4 - $100"<<endl;
 	cout<<"  2 - $40      5 - $200"<<endl;
 	cout<<"  3 - $60      6 - Cancel transaction."<<endl;
 	cout<<"Choose a withdrawal option(1-6) : "<<endl;
 	}

};

class Exit		//Class to exit an account
{
 public :
 	void exit()
 	{
 	cout<<"Account Closed. "<<endl<<endl;
	}
};


int main ()
{


	WithdrawalMenu wMenu;
	Exit e;
	AccountInfo a1,a2,a3;
	ofstream outputFile;
	int AccNo;
	int Pin;
	int Bal;
	outputFile.open("Account.txt", ios::out|ios::app);	//To store accounts info in a file
	cout<<"Storing  Accounts Info in file : "<<endl<<endl;
	for(int i=0;i<3;i++)
	{
	cout<<"Please Enter Account No : ";
	cin>>AccNo;
	cout<<"Please Enter Pin : ";
	cin>>Pin;
	cout<<"Enter Balance : ";
	cin>>Bal;
	cout<<endl;
	if(i==0) {a1.setAccNo(AccNo); a1.setPin(Pin); a1.updateBalance(Bal);}
	if(i==1) {a2.setAccNo(AccNo); a2.setPin(Pin); a2.updateBalance(Bal);}
	if(i==2) {a3.setAccNo(AccNo); a3.setPin(Pin); a3.updateBalance(Bal);}

	outputFile<<"Account No : "<< AccNo;
	outputFile<< "\nPin : " <<Pin;
	outputFile<<"\nBalance : "<<Bal<<endl;
	}
	outputFile.close();

	AtmScreen screen;

	for(int i=0;;i++)
	{


	screen.display();

	AccountInfo Acc;
	cout<<"Please Enter your account number : ";
	cin>>AccNo;
	cout<<"Please Enter your PIN : ";
	cin>>Pin;
	Acc.setAccNo(AccNo);  Acc.setPin(Pin);

	cout<<endl;

	if((Acc.getAccNo()==a1.getAccNo()) && (Acc.getPin()==a1.getPin()))
	{

	int select;
	MainMenu menu;
	for(int i=0;;i++)
	{
	menu.display();
	cin>>select;
	cout<<endl;
		if(select==1)
		{
		cout<<"Balance : "<<a1.getBalance()<<endl<<endl;
		}
		else if(select==2)
		{
		int choice;
		wMenu.display();
		cin>>choice;
		//condition that checks if account balance is less than withdrawal amount.
		if(choice == 1 && a1.getBalance()>=20)
		{
		a1.EnterWithdrawalAmount(choice);
		a1.SubtractWithdrawal();
		}

		else if(choice == 2 && a1.getBalance()>=40)
		{
		a1.EnterWithdrawalAmount(choice);
		a1.SubtractWithdrawal();
		}

		else if(choice == 3 && a1.getBalance()>=60)
		{
		a1.EnterWithdrawalAmount(choice);
		a1.SubtractWithdrawal();
		}

		else if(choice == 4 && a1.getBalance()>=100)
		{
		a1.EnterWithdrawalAmount(choice);
		a1.SubtractWithdrawal();
		}

		else if(choice == 5 && a1.getBalance()>=200)
		{
		a1.EnterWithdrawalAmount(choice);
		a1.SubtractWithdrawal();
		}

		else if(choice == 6)
		{
		a1.EnterWithdrawalAmount(choice);
		a1.SubtractWithdrawal();
		}

		else { cout<<"!!!ERROR!!!"<<endl<<endl; }


		}
		else if(select==3)
		{
		int cash;
		cout<<"Enter Cash to deposit (in cents)."<<endl;
		cin>>cash;
		a1.EnterDepositCash(cash);
		a1.AddDepositCash();
		}
		else if(select==4) //Updates account info in file when user exits account
		{


	outputFile.open("Account.txt", ios::out|ios::app);
	cout<<"Updating  Accounts Info in file : "<<endl<<endl;
	outputFile<<"Updated Data : "<<endl;

	outputFile<<"Account No : "<< a1.getAccNo();
	outputFile<< "\nPin : " <<a1.getPin();
	outputFile<<"\nBalance : "<<a1.getBalance()<<endl;


	outputFile.close();


		e.exit();
		break;
		}
		else {cout<<"Invalid Choice."<<endl<<endl; continue;}
	}
	}

	else if((Acc.getAccNo()==a2.getAccNo()) && (Acc.getPin()==a2.getPin()))
	{
	int select;
	MainMenu menu;
	for(int i=0;;i++)	//To repreat menu main options
	{
	menu.display();
	cin>>select;
	cout<<endl;
	if(select==1)
		{
		cout<<"Balance : "<<a2.getBalance()<<endl<<endl;
		}
		else if(select==2)
		{
		int choice;
		wMenu.display();
		cin>>choice;
		//condition that checks if account balance is less than withdrawal amount.
		if(choice == 1 && a2.getBalance()>=20)
		{
		a2.EnterWithdrawalAmount(choice);
		a2.SubtractWithdrawal();
		}

		else if(choice == 2 && a2.getBalance()>=40)
		{
		a2.EnterWithdrawalAmount(choice);
		a2.SubtractWithdrawal();
		}

		else if(choice == 3 && a2.getBalance()>=60)
		{
		a2.EnterWithdrawalAmount(choice);
		a2.SubtractWithdrawal();
		}

		else if(choice == 4 && a2.getBalance()>=100)
		{
		a2.EnterWithdrawalAmount(choice);
		a2.SubtractWithdrawal();
		}

		else if(choice == 5 && a2.getBalance()>=200)
		{
		a2.EnterWithdrawalAmount(choice);
		a2.SubtractWithdrawal();
		}

		else if(choice == 6)
		{
		a2.EnterWithdrawalAmount(choice);
		a2.SubtractWithdrawal();
		}

		else { cout<<"!!!ERROR!!!"<<endl<<endl; }



		}
		else if(select==3)
		{
		int cash;
		cout<<"Enter Cash to deposit (in cents)."<<endl;
		cin>>cash;
		a2.EnterDepositCash(cash);
		a2.AddDepositCash();
		}
		else if(select==4) //Updates account info in file when user exits account
		{


	outputFile.open("Account.txt", ios::out|ios::app);
	cout<<"Updating  Accounts Info in file : "<<endl<<endl;
	outputFile<<"Updated Data : "<<endl;


	outputFile<<"Account No : "<< a2.getAccNo();
	outputFile<< "\nPin : " <<a2.getPin();
	outputFile<<"\nBalance : "<<a2.getBalance()<<endl;


	outputFile.close();

		e.exit();
		break;
		}
		else {cout<<"Invalid Choice."<<endl<<endl; continue;}
	}
	}

	else if((Acc.getAccNo()==a3.getAccNo()) && (Acc.getPin()==a3.getPin()))
	{
	int select;
	MainMenu menu;
	for(int i=0;;i++)
	{
	menu.display();
	cin>>select;
	cout<<endl;
	if(select==1)
		{
		cout<<"Balance : "<<a3.getBalance()<<endl<<endl;
		}
		else if(select==2)
		{
		int choice;
		wMenu.display();
		cin>>choice;
		//condition that checks if account balance is less than withdrawal amount.
		if(choice == 1 && a3.getBalance()>=20)
		{
		a3.EnterWithdrawalAmount(choice);
		a3.SubtractWithdrawal();
		}

		else if(choice == 2 && a3.getBalance()>=40)
		{
		a3.EnterWithdrawalAmount(choice);
		a3.SubtractWithdrawal();
		}

		else if(choice == 3 && a3.getBalance()>=60)
		{
		a3.EnterWithdrawalAmount(choice);
		a3.SubtractWithdrawal();
		}

		else if(choice == 4 && a3.getBalance()>=100)
		{
		a3.EnterWithdrawalAmount(choice);
		a3.SubtractWithdrawal();
		}

		else if(choice == 5 && a3.getBalance()>=200)
		{
		a3.EnterWithdrawalAmount(choice);
		a3.SubtractWithdrawal();
		}

		else if(choice == 6)
		{
		a3.EnterWithdrawalAmount(choice);
		a3.SubtractWithdrawal();
		}

		else { cout<<"!!!ERROR!!!"<<endl<<endl; }


		}
		else if(select==3)
		{
		int cash;
		cout<<"Enter Cash to deposit (in cents)."<<endl;
		cout<<"Press 0 to cancel transaction. "<<endl;
		cin>>cash;
		a3.EnterDepositCash(cash);
		a3.AddDepositCash();
		}
		else if(select==4) //Updates account info in file when user exits account
		{


	outputFile.open("Account.txt", ios::out|ios::app);
	cout<<"Updating  Accounts Info in file : "<<endl<<endl;
	outputFile<<"Updated Data : "<<endl;

	outputFile<<"Account No : "<< a3.getAccNo();
	outputFile<< "\nPin : " <<a3.getPin();
	outputFile<<"\nBalance : "<<a3.getBalance()<<endl;

	outputFile.close();

		e.exit();
		break;
		}
		else {cout<<"Invalid Choice."<<endl<<endl; continue;}
	}
	}

	else 	//condition if account no or Pin not correct
	{
	cout<<"Account not verified "<<endl<<endl;
	}

	}



	return 0;
}
