// MVC Design Patterns
//MVC Pattern stands for Model-View-Controller Pattern. This pattern is used to separate application's concerns.
//Model - Model represents an object or JAVA POJO carrying data. It can also have logic to update controller if its data changes.
//View - View represents the visualization of the data that model contains.
//Controller - Controller acts on both model and view. It controls the data flow into model object and updates the view whenever data changes. 
//             It keeps view and model separate.

//We are going to make aStudent object as a Model
// A student view to view all the details
//A student controller to controll the model to update the data in the Model obj and call view whenever needed

#include <iostream>
#include <cstring>
using namespace std;

//Student Class
//Model Class in MVC design Pattern
//This class is responsible for holding whole data
class StudentModel{
	char *name = new char[15];
	int rollno;
	int mobileno;
	
	// all getter and setters are defined
	public:
	void setName(char *name){
		strcpy(this->name, name);
	}
	
	char* getName(){
		return name;
	}
	
	void setRollNo(int rollno){
		this->rollno = rollno;
	}
	
	int getRollNo(){
		return rollno;
	}
	
	void setMob(int mobileno){
		this->mobileno = mobileno;
	}
	
	int getMob(){
		return mobileno;
	}
};

//StudentView is View class in MVC design pattern
//This is responsible for outputing the model data
class StudentView{
	public:
		void viewStudentDetails(char *name, int roll, int mob){
			cout << "Student Details:-" << endl;
			cout << "Name:- " << name << endl;
			cout << "Roll. No:- " << roll << endl;
			cout << "Mobile No:- " << mob << endl;
		}
};

// StudentController is controller class in MVC design pattern
// This is master mind class of this design pattern
// Its responsible for storing the data in model object or viewing the data from it or updating the o/p whenever necessery
class StudentController{
	StudentModel *model;
	StudentView *view;
	public:
		//Constructor taking model and view as i/p parameter
		StudentController(StudentModel *m, StudentView *v){
			model = m;
			view = v;
		}
		
		void setStudentName(char *name){
			model->setName(name);
		}
		
		char* getStudentName(char *name){
			return model->getName();
		}
		
		void setRollNo(int roll){
			model->setRollNo(roll);
		}
		
		int getRollNo(){
			return model->getRollNo();
		}
		
		void setMob(int mob){
			model->setMob(mob);
		}
		
		int getMob(){
			return model->getMob();
		}
		
		void updateView(){
			view->viewStudentDetails(model->getName(), model->getRollNo(), model->getMob());
		}
};

//This is a helper function to work as a database for demonstration
// its used as initialization tool
StudentModel* retrieveStudentFromDB(){
	StudentModel *student = new StudentModel();
	
	student->setName("ANUJ");
	student->setRollNo(8);
	student->setMob(7898558);
	
	return student;
}

//Client Code
int main()
{
	StudentModel *model = retrieveStudentFromDB();
	
	StudentView *view = new StudentView();
	
	StudentController *controller = new StudentController(model, view);
	
	controller->updateView();
	
	controller->setStudentName("GOYAL");
	
	controller->updateView();
}
