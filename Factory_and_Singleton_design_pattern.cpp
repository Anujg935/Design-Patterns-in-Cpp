#include <iostream>

using namespace std;

//Base Interface class 
class DatabaseIntf{
	public:
		virtual void DbConnect() = 0;
};

// db1 singleton class derived from DatabaseIntf
class db1 : public DatabaseIntf{
	private:
		static bool objCheckdb1;
		static db1* single;
		int i=0;
		
		// constructors are private so that no access to outside world to create obj
		db1(){
			cout << "Private db1 constructor" << endl;
		}
		
		db1(const db1&){
			cout << "db1 private copy constructor" << endl;
		}
		
		db1& operator=(db1&){
			cout << "db1 private copy assign. opperator" << endl;
		}
	
	public:
		// static function to get return object of the class if called more than 1 time
		// then return the same object instance
		static db1* getInstance(){
			if(!objCheckdb1){
				cout << "Singleton: Creating object of db1" << endl;
				single = new db1();
				objCheckdb1 = true;
				
				return single;
			}
			else{
				return single;
			}
		}
		
		// this is the virtual fucntion to be defined
		// mainly used to check if calling thorugh different ptrs obj is single or not
        void DbConnect(){
    		i = i+1;
    		cout << "method: DbConnect to db1 database: " << i << endl;
		}		
		
		~db1(){
			objCheckdb1 = false;
		}
};
bool db1::objCheckdb1 = false;
db1* db1::single = NULL;


class db2 : public DatabaseIntf{
	private:
		static bool objCheckdb2;
		static db2* single;
		int i=0;
		
		db2(){
			cout << "Private db2 constructor" << endl;
		}
		
		db2(const db2&){
			cout << "db2 private copy constructor" << endl;
		}
		
		db2& operator=(db2&){
			cout << "db2 private copy assign. opperator" << endl;
		}
	
	public:
		static db2* getInstance(){
			if(!objCheckdb2){
				cout << "Singleton: Creating object of db2" << endl;
				single = new db2();
				objCheckdb2 = true;
				
				return single;
			}
			else{
				return single;
			}
		}
		
		void DbConnect(){
			i = i+1;
			cout << "method: DbConnect to db2 database: " << i << endl;
		}
		~db2(){
			objCheckdb2 = false;
		}
};
bool db2::objCheckdb2 = false;
db2* db2::single = NULL;

//// db2 singleton class derived from DatabaseIntf
// everything is same as db1 class
class Factory{
	public:
		Factory(){
			cout << "Factory class constructor" << endl;
		}
		
		static DatabaseIntf* create(string db_name){
			if(db_name == "db1"){
				cout << "Factory: Creating/ returning Object of db1 " << endl;
				return db1::getInstance();
			}
			else if(db_name == "db2"){
				cout << "Factory: Creating/ returning Object of db2 " << endl;
				return db2::getInstance();
			}
			else{
				return NULL;
			}
		}
};

int main()
{
	// creating 2 ptrs and calling DbConnect() through both of them
	// to verify if only one object is creatd or not
	DatabaseIntf* db1SinglePtr = NULL;
	DatabaseIntf* db1SinglePtr1 = NULL;
	
	db1SinglePtr = Factory::create("db1");
	db1SinglePtr->DbConnect();
	
	db1SinglePtr1 = Factory::create("db1");
	db1SinglePtr1->DbConnect();
	
	cout << "-------------------------------------------------" << endl;
	
	// creating 2 ptrs and calling DbConnect() through both of them.
	// to verify if only one object is creatd or not.
	DatabaseIntf* db2SinglePtr = NULL;
	DatabaseIntf* db2SinglePtr1 = NULL;
	
	db2SinglePtr = Factory::create("db2");
	db2SinglePtr->DbConnect();
	
	db2SinglePtr1 = Factory::create("db2");
	db2SinglePtr1->DbConnect();
	return 0;
}
