//In Strategy pattern, a class behavior or its algorithm can be changed at run time. 
//In Strategy pattern, we create objects which represent various strategies 
//and a context object whose behavior varies as per its strategy object. 
//The strategy object changes the executing algorithm of the context object.

//In this we are going to solve a problem of basic arithmetic opertions
//Add, subtract and multiply 2 numbers
// But behaviour to select operation will change at run time
#include <iostream>

using namespace std;

// Strategy class Interface
class Strategy{
	public:
		virtual int doOperation(int a, int b) = 0;
};

//Concrete class for Strategy interface
//AddOperation is done with this class
class AddOperation : public Strategy{
	public:
		int doOperation(int a, int b){
			return a + b;
		}
};

//Concrete class for Strategy interface
//SubtractOperation is done with this class
class SubtractOperation : public Strategy{
	public:
		int doOperation(int a, int b){
			return a - b;
		}
};

//Concrete class for Strategy interface
//MultiplyOperation is done with this class
class MultiplyOperation : public Strategy{
	public:
		int doOperation(int a, int b){
			return a * b;
		}
};

//Context Class
class Context{
	Strategy *strategy;
	public:
		Context(Strategy *s){
			strategy = s;
		}
		
		void setStrategy(Strategy *s){
			strategy = s;
		}
		
		int executeStrategy(int num1, int num2){
			strategy->doOperation(num1, num2);
		}
};
//Client code
int main()
{
	AddOperation add;
	SubtractOperation sub;
	MultiplyOperation mul;
	
	Context contextAdd(&add);
	Context contextSub(&sub);
	Context contextMul(&mul);
	
	cout << "Addition of 15 and 10: " << contextAdd.executeStrategy(15, 10) << endl;
	cout << "Subtraction of 15 and 10: " << contextSub.executeStrategy(15, 10) << endl;
	cout << "Multiplication of 15 and 10: " << contextAdd.executeStrategy(15, 10) << endl;
	
	contextAdd.setStrategy(&sub);
	cout << contextAdd.executeStrategy(15, 10) <<endl; //Add strategy is changed to subtraction o/p should be 5
}
