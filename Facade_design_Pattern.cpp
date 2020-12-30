//Facade Design Pattern
//Facade pattern hides the complexities of the system and provides an interface 
//to the client using which the client can access the system.

// In this we are going to solve a problem of Mobiloe Shop keeper
//There are 3 types of phones Iphone, Samsung and Oneplus
//There is a mobile shop which has price and name of model
//there is a shopkeeper which is an interface for client //and this is a facade class to ease the complexity

#include <iostream>
using namespace std;

//MobileShop Interface
class MobileShop{
	public:
		virtual void model() = 0;
		virtual void price() = 0;
};

//Concrete class for MobileShop Interface
//Iphone Class
class Iphone : public MobileShop{
	public:
		void model(){
			cout << "Model name is: Iphone 12 pro max " << endl;
		}
		
		void price(){
			cout << "Iphone price is : 125000" <<endl;
		}
};

//Concrete class for MobileShop Interface
//Samsung Class
class Samsung : public MobileShop{
	public:
		void model(){
			cout << "Model name is: S20 ultra " << endl;
		}
		
		void price(){
			cout << "Samsung price is : 85000" <<endl;
		}
};

//Concrete class for MobileShop Interface
//Oneplus Class
class Oneplus : public MobileShop{
	public:
		void model(){
			cout << "Model name is: Oneplus 8 " << endl;
		}
		
		void price(){
			cout << "Oneplus price is : 55000" <<endl;
		}
};

//Now its a Facade class that will reduce the complexity for client
// and privide a clear interface to the client
//Shopkeeper class

class Shopkeeper{
	Iphone *iphone;
	Samsung *samsung;
	Oneplus *oneplus;
	
	public:
		Shopkeeper(){
			iphone = new Iphone();
			samsung = new Samsung();
			oneplus = new Oneplus();
		}
		
		void SamsungModel(){
			samsung->model();
			samsung->price();
		}
		
		void IphoneModel(){
			iphone->model();
			iphone->price();
		}
		
		void OneplusModel(){
			oneplus->model();
			oneplus->price();
		}
};

//Client code
int main()
{
	Shopkeeper s;
	s.SamsungModel();
	s.IphoneModel();
	s.OneplusModel();
	return 0;
}
