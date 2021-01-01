# Design-Patterns-in-Cpp
Basic Design patterns in C++. All codes snippets are well documented easily understandable.
![Design Pattern](https://miro.medium.com/max/630/1*y1i8Qz-s3VFijV6bUiRQFg.png)
## Following are the Design Patterns in this Repositoty:-

- ### Factory Design Pattern
This design patter in used to get the object without client knowing the process of creation of it.
In Factory pattern, we create object without exposing the creation logic to the client and refer to newly created object using a common interface.

In this We created an interface Vehicle Class and 3 concrete classes named cycle, car and bus.
One Factory class is created which will return the object of the class based on input parameters.

File demonstrating Factory Design Pattern :-[Link](https://github.com/Anujg935/Design-Patterns-in-Cpp/blob/master/Factory_design%20_Pattern.cpp)

- ### Singleton Design Pattern
Its a design patter in which only 1 object is possible of that particular class.

In this Singleton class Private constriuctor, copy constuctor, and assign operator because don't wan't to give access to outside world to create an object.
Static method to get the instance of this class and check if already created then return that only.

File demonstrating Singleton Design Pattern :-[Link](https://github.com/Anujg935/Design-Patterns-in-Cpp/blob/master/Singleton_design_Pattern%20.cpp)

- ### Combination of Factory and Singleton Design Pattern
In this combination of Factory and Singleton Design Pattern is demonstrated.

In this firstly created a DBInterface abstract class and created 2 concrete classes of that Interface named db1 and db2.
Both concrete classes are Singleton classes. Now another Factory class in created which wil return the object of appropriate class db1 or db2 based on the client input.

File demonstrating Factory and Singleton Design Pattern :-[Link](https://github.com/Anujg935/Design-Patterns-in-Cpp/blob/master/Factory_and_Singleton_design_pattern.cpp)

- ### Adapter Design Pattern
Adapter pattern works as a bridge between two incompatible interfaces. This type of design pattern comes under structural pattern as this pattern combines the capability of two independent interfaces.

In this created, MediaPlayer interface and a concrete class AudioPlayer implementing the MediaPlayer interface. AudioPlayer can play mp3 format audio files by default. We are having another interface AdvancedMediaPlayer and concrete classes implementing the AdvancedMediaPlayer interface. These classes can play vlc and mp4 format files. We want to make AudioPlayer to play other formats as well. To attain this, we have created an adapter class MediaAdapter which implements the MediaPlayer interface and uses AdvancedMediaPlayer objects to play the required format. AudioPlayer uses the adapter class MediaAdapter passing it the desired audio type without knowing the actual class which can play the desired format. Client code, will use AudioPlayer class to play various formats.

File demonstrating Adapter Design Pattern :-[Link](https://github.com/Anujg935/Design-Patterns-in-Cpp/blob/master/Adapter_design_Pattern.cpp)

- ### Builder Design Pattern
Builder pattern builds a complex object using simple objects and using a step by step approach. A Builder class builds the final object step by step. This builder is independent of other objects.<br/>
In this created a Notification manager Design Problem solved using Builder design Pattern<br/>
In this for an accademy there are 3 types of Customers namely:-"Individial", "Coaching" & "Group"<br/>
And when these type of customers books the slot then notification is send to different peoples woth different modes<br/>
In case of "Individual"<br/>
     -> Notification is send to Security and Members<br/>
In case of "Coaching"<br/>
     -> Notification is send to Security , Members and Coach<br/>
In case of "Group"<br/>
     -> Notification is send to Security, Members, Coach and Manager<br/>
     
File demonstrating Builder Design Pattern :-[Link](https://github.com/Anujg935/Design-Patterns-in-Cpp/blob/master/Builder_design_Pattern.cpp)

- ### Observer Design Pattern
It defines a one to many dependency b/w objects so that one object changes. its state, all of its dependents are notified and updated automatically.<br/>
Observer pattern uses three actor classes. Subject, Observer and Client. Subject is an object having methods to attach and detach observers to a client object. We have created an abstract class Observer and a concrete class Subject that is extending class Observer.<br/>

We are solving a problem in which prices of Shops are to be updated automaticaly when prices changes there are going to be many shop objects.

File demonstrating Observer Design Pattern :-[Link](https://github.com/Anujg935/Design-Patterns-in-Cpp/blob/master/Observer_design_Pattern.cpp)

- ### Command Design Pattern
Command pattern is a data driven design pattern and falls under behavioral pattern category.<br/>
A request is wrapped under an object as command and passed to invoker object. <br/>
Invoker object looks for the appropriate object which can handle this command and passes the command to the corresponding object which executes the command.<br/>

We are going to solve  a Stock buy sell problem in which broker class work as invoker<br/> 
There is going to be a stock class which has stock buy and sell function<br/> 
Order Interface which is acting as command, 2 concrete classes of Order class i.e BuyStock and SellStock<br/>

File demonstrating Command Design Pattern :-[Link](https://github.com/Anujg935/Design-Patterns-in-Cpp/blob/master/Command_design_Pattern.cpp)

- ### Strategy Design Pattern
In Strategy pattern, a class behavior or its algorithm can be changed at run time.<br/> 
In Strategy pattern, we create objects which represent various strategies and a context object whose behavior varies as per its strategy object.<br/> 
The strategy object changes the executing algorithm of the context object.<br/>

In this we are going to solve a problem of basic arithmetic opertions :- Add, subtract and multiply 2 numbers But behaviour to select operation will change at run time.<br/>

File demonstrating Strategy Design Pattern :-[Link](https://github.com/Anujg935/Design-Patterns-in-Cpp/blob/master/Strategy_design_Pattern.cpp)

- ### Facade Design Pattern
Facade pattern hides the complexities of the system and provides an interface to the client using which the client can access the system.<br/>

In this we are going to solve a problem of Mobiloe Shop keeper<br/>
There are 3 types of phones Iphone, Samsung and Oneplus<br/>
There is a mobile shop which has price and name of model<br/>
There is a shopkeeper which is an interface for client(and this is a facade class to ease the complexity)<br/>

File demonstrating Facade Design Pattern :-[Link](https://github.com/Anujg935/Design-Patterns-in-Cpp/blob/master/Facade_design_Pattern.cpp)

- ### Bridge Design Pattern
Bridge is used when we need to decouple an abstraction from its implementation so that the two can vary independently.<br/>
This pattern involves an interface which acts as a bridge which makes the functionality of concrete classes independent from interface implementer classes.<br/>
Both types of classes can be altered structurally without affecting each other.<br/>

In this we are going to solve a problem to draw and color the shape. <br/>
we have two shapes circle and rectangle and two colors red and black. <br/>
We are going to make a interface of shape and Color and make a bridge class which takes the object of color class and do the opertion. <br/>

File demonstrating Bridge Design Pattern :-[Link](https://github.com/Anujg935/Design-Patterns-in-Cpp/blob/master/Bridge_design_Pattern.cpp)

- ### Decorator Design Pattern
Decorator pattern allows a user to add new functionality to an existing object without altering its structure.<br/>
This pattern creates a decorator class which wraps the original class and provides additional functionality keeping class methods signature intact.<br/>

In this we are going to make a OTT Platform subscription Model. <br/>
In which there are going to be 3 types of subscriptions<br/>
Basic, Gold and Platinum<br/>
Every type of subscription will have some cost and features<br/> 
Basic Subscription :- Cost = 250, features = "Mobile Screen, 720p Content, "<br/>
Gold Subscription :- Cost = Cost of Basic + 250, features = features of basic + "Laptop Screen, 1080p Content, "<br/>
Platinum Subscription :- Cost = cost of Gold + 500, features = feature of gold + "TV Screen, 4k Content, "<br/>

File demonstrating Decorator Design Pattern :-[Link](https://github.com/Anujg935/Design-Patterns-in-Cpp/blob/master/Decorator_design_Pattern.cpp)

- ### Flyweight Design Pattern
Flyweight pattern is primarily used to reduce the number of objects created and to decrease memory footprint and increase performance.<br/>
Flyweight pattern tries to reuse already existing similar kind objects by storing them and creates new object when no matching object is found. <br/>
We are going to use hashmap for storing the objects.<br/>

We are going to make this pattern by drawing 20 circles of different locations but we will create only 3 objects. <br/>
Only 3 colors are available so color property is used to check already existing Circle objects.<br/>

File demonstrating Flyweight Design Pattern :-[Link](https://github.com/Anujg935/Design-Patterns-in-Cpp/blob/master/Flyweight_design_Pattern.cpp)

- ### MVC Design Pattern
MVC Pattern stands for Model-View-Controller Pattern. This pattern is used to separate application's concerns.<br/>
Model - Model represents an object or JAVA POJO carrying data. It can also have logic to update controller if its data changes.<br/>
View - View represents the visualization of the data that model contains.<br/>
Controller - Controller acts on both model and view. It controls the data flow into model object and updates the view whenever data changes. It keeps view and model separate.<br/>

We are going to make aStudent object as a Model<br/>
A student view to view all the details. A student controller to controll the model to update the data in the Model obj and call view whenever needed.<br/>

File demonstrating MVC Design Pattern :-[Link](https://github.com/Anujg935/Design-Patterns-in-Cpp/blob/master/MVC_design_Pattern.cpp)