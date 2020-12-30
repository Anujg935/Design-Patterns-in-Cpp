//Bridge Design Pattern
//Bridge is used when we need to decouple an abstraction from its implementation so that the two can vary independently.
//This pattern involves an interface which acts as a bridge which makes the functionality of concrete classes 
//independent from interface implementer classes. 
//Both types of classes can be altered structurally without affecting each other.

// In this we are going to solve a problem to draw and color the shape
//we have two shapes circle and rectangle and two colors red and black
//We are going to make a interface of shape and Color and make a bridge class
// which takes the object of color class and do the opertion

#include <iostream>
using namespace std;

//Shapedraw Interface
class ShapeDraw{
	public:
		virtual void DrawIt() = 0;
		virtual void ColorIt() = 0;
};

//Color Interface
class Color{
	public:
		virtual void ColorIt() = 0;
};

//Concrete class for Color Interface
class Red : public Color{
	public:
		void ColorIt(){
			cout << "Red Color is filled" << endl;
		} 
};

//Concrete class for Color Interface
class Black : public Color{
	public:
		void ColorIt(){
			cout << "Black Color is filled" << endl;
		} 
};

// A bridg class to make a bridge b/ww shape Interface and color Interface
class Bridge : public ShapeDraw{
	protected:
	Color *colorObj;
	public:
		Bridge(Color *color){
			colorObj = color;
			cout << "Bridge Class Color" << endl;
		}
};

//Concrete class for ShapeDraw Interface
// deriving from Bridge class which is already a child class of ShapeDraw
class Circle : public Bridge{
	public:
		Circle(Color *color):Bridge(color){
		}
		
		void ColorIt(){
			colorObj->ColorIt();
		}
		
		void DrawIt(){
			cout << "Drawing circle" << endl;
		}
};

//Concrete class for ShapeDraw Interface
// deriving from Bridge class which is already a child class of ShapeDraw
class Rectangle : public Bridge{
	public:
		Rectangle(Color *color):Bridge(color){
		}
		
		void ColorIt(){
			colorObj->ColorIt();
		}
		
		void DrawIt(){
			cout << "Drawing Rectangle" << endl;
		}
};

//Client Code
int main()
{
	ShapeDraw *shape1;
	
	Color *red = new Red;
	Color *black = new Black;
	
	shape1 = new Circle(red);
	shape1->ColorIt();
	shape1->DrawIt();
	
	shape1 = new Circle(black);
	shape1->ColorIt();
	shape1->DrawIt();
	
	cout << "--------------------------------" <<endl;
    
    ShapeDraw *shape2;
	
	shape2 = new Rectangle(red);
	shape2->ColorIt();
	shape2->DrawIt();
	
	shape2 = new Rectangle(black);
	shape2->ColorIt();
	shape2->DrawIt();
	
}
