//Flyweight Design Pattern
//Flyweight pattern is primarily used to reduce the number of objects created and to decrease memory footprint and increase performance.
//Flyweight pattern tries to reuse already existing similar kind objects by storing them and creates new object when no matching object is found.
//We are going to use hashmap for storing the objects

//We are going to make this pattern by drawing 20 circles of different locations but we will create only 3 objects. 
//Only 3 colors are available so color property is used to check already existing Circle objects.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Shape class Interface
class Shape{
	public:
	virtual void setParam(int x, int y, int r) = 0;
	virtual void draw() = 0;
};

//Concrete class of Shape Interface
class Circle : public Shape{
	string color;
	int x, y, radius;
	public:
		Circle(string color){
			this->color = color;
		}
		
		void setX(int x){this->x = x;}
		void setY(int y){this->y = y;}
		void setR(int r){radius = r;}
		void setParam(int x, int y, int r){
			setX(x);
			setY(y);
			setR(r);
		}
		
		void draw(){
		    
			cout << "Circle at: x = " << x <<" y = " << y <<" of radius = " <<radius <<" and Color = " << color << endl;
		}
};

//FlyWeightFacory class
//This will store the created objects in the hashmaps according to colors as a keys
//If key already exisits then no need to create object it will return already created object only
class FlyWeightFactory : public Shape{
	static unordered_map<string, Shape* > map;
	public:
		static Shape* getCircle(string color){
		    Shape *c = NULL;
			if(map.find(color) != map.end()){
				c = map[color];
			}
			else{
				c = new Circle(color);
			}
			map[color] = c;
			return c;
		} 
};
unordered_map<string, Shape* > FlyWeightFactory::map;
// Client Code
int main()
{
	string colorList [] = {"RED", "GREEN", "BLUE"};
	
	for(int i=1;i<=20;){
		for(int j=0;j<3;j++){
			Shape *circle = FlyWeightFactory::getCircle(colorList[j]);
			circle->setParam(i+j, i-j, i*j);
			circle->draw();
		}
		i+=3;
	}
	
}
