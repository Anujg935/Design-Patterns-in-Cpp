#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class vehicle{
	public:
		virtual void getVehicle() = 0;
};

class cycle : public vehicle{
	public:
		void getVehicle(){
			cout << "I am a Cycle" << endl;
		}
};

class car : public vehicle{
	public:
		void getVehicle(){
			cout << "I am a Car" << endl;
		}
};

class bus : public vehicle{
	public:
		void getVehicle(){
			cout << "I am a Bus" << endl;
		}
};

// This design patter in used to get the object without client knowing the process of creation of it
class Factory{
	
	public:
		Factory(){
			cout << "I am a factory" << endl;
		}
		
		// Its static function because with this don't need
		// to create an object of Factory class can directly call this function
		static vehicle* create(string name){
			if(name=="cycle")
				return new cycle();
			else if(name=="car")
				return new car();
			else if(name == "bus")
				return new bus();
			else
				return NULL;
		}
};

int main()
{
	vehicle *v = Factory::create("cycle");
	v->getVehicle();
	
	v = Factory::create("car");
	v->getVehicle();
	
	v = Factory::create("bus");
	v->getVehicle(); 
}
