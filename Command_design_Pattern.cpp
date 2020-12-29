//Command pattern is a data driven design pattern and falls under behavioral pattern category. 
//A request is wrapped under an object as command and passed to invoker object. 
//Invoker object looks for the appropriate object which can handle this command 
//and passes the command to the corresponding object which executes the command.

//We are going to solve  a Stock buy sell problem in which broker class work as invoker 
// There is going to be a stock class which has stock buy and sell function
// an Order Interface which is acting as command
// 2 concrete classes of Order class i.e BuyStock and SellStock

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Stock class
//We are restricting the name and quantity as default for simplicity
class Stock{
	string name = "Google";
	int quantity = 10;
	
	public:
		
		void buy(){
			cout << "Stock: " << name <<" bought quantity: " << quantity << endl;
		}
		void sell(){
			cout << "Stock: " << name <<" sold quantity: " << quantity << endl;
		}
		
};

//Order interface
//Actiong as a command
class Order{
	public:
		virtual void execute() = 0;
};

//BuyStock class
class BuyStock : public Order{
	Stock st;
	public:
		BuyStock(Stock s){
			st = s;
		}
		void execute(){
			st.buy();
		}
};

//SellStock class
class SellStock : public Order{
	Stock st;
	public:
		SellStock(Stock s){
			st = s;
		}
		void execute(){
			st.sell();
		}
};

//Broker class
//Acts as an invoker class to call respective classes
class Broker{
	
	public:
		void ExecuteOrder(Order *order){
			order->execute();
		}
};

//Client code
int main()
{
	Stock st;
	
	BuyStock *buy = new BuyStock(st);
	SellStock *sell = new SellStock(st);
	
	Broker b;
	
	b.ExecuteOrder(buy);
	b.ExecuteOrder(sell);
	
}
