//Observer design Pattern
//It defines a one to many dependency b/w objects so that one object changes
//its state, all of its dependents are notified and updated automatically

// We are solving a problem in which prices of hops are to be updated automaticly when prices changes
//there are going to be many shop objects.
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Observer Interface
class IObserver{
	public:
		virtual void newUpdateShow(float price) = 0;
};

// Concrete class of Observer Interface
// All shop object prices are to be updated when price changes
class Shop : public IObserver{
	string name;
	float price;
	
	public:
		Shop(string name){
			this->name = name;
		}
		
		void newUpdateShow(float price){
			this->price = price;
			cout << "Price at " << this->name << " is now " << price << endl;
		}
		
};

// This is the Subject class
//Subject is an object having methods to attach and detach observers to a client object
class SubjectShopOperation{
	vector<Shop*> mList;
	
	public:
		//It attaches the shop with client code
		void subscribeShop(Shop *shop){
			mList.push_back(shop);
		}
		// It detaches th shop from client code
		void unsubscribeShop(Shop *shop){
			mList.erase(remove(mList.begin(), mList.end(), shop), mList.end());
		}
		//Update the prices of all the objects
		void notifyInfo(float price){
			for(auto i : mList){
				i->newUpdateShow(price);
			}
		}
};

// This class , will use Subject and concrete class object to show observer pattern in action.
class UpdateProductInfo : public SubjectShopOperation{
	public:
		void updatePrice(float price){
			notifyInfo(price);
		}
};

int main()
{
	UpdateProductInfo updateProduct;
	
	Shop s1("Shop 1");
	Shop s2("Shop 2");
	
	updateProduct.subscribeShop(&s1);
	updateProduct.subscribeShop(&s2);
	updateProduct.updatePrice(50);
	
	updateProduct.unsubscribeShop(&s1);
	cout << "Shop 1 is unsubscribed" << endl;
	
	//Now lets try to update the prices
	
	updateProduct.updatePrice(100);
	
	return 0;
}
