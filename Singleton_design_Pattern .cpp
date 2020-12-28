#include <iostream>
using namespace std;

//Its a design patter in which only 1 object is possible of that particular class
class Singleton{
	private:
		static bool objIdx;
		static Singleton *single;
		
		int i = 0;
		
		//Private constriuctor, copy constuctor, and assign operator because don't wan't to give access to
		//outside world to create an object
		Singleton(){
			cout << "Singleton class Private constructor" << endl;
		}
		Singleton(const Singleton&){
			cout << "Singleton copy constructor" << endl;
		}
		Singleton& operator=(Singleton&){
			cout << "Singleton copy assignment operator" << endl;
		}
		
	public:
		// Static method to get the instance of this class and check if already created then
		// return that only
		static Singleton* getInstance(){
			if(!objIdx){
				single = new Singleton();
				objIdx = true;
				return single;
			}
			else{
				return single;
			}
		}
		
		// this function is created to show that only 1 object is created
		// and this will increment i every time this is claaed even if throw different pointers
		void method(){
			cout << "Method of class : " << i <<endl;
			i++;
		}
		
		~Singleton(){
			objIdx = false;
			single = NULL;
		}
		
};

bool Singleton::objIdx = false;
Singleton* Singleton::single = NULL;
int main()
{
	Singleton *firstPtr, *secondPtr;
	
	firstPtr = Singleton::getInstance();
	
	firstPtr->method();
	
	secondPtr =  Singleton::getInstance();
	secondPtr->method();
	
	return 0;
}
