// Decorator Design Pattern
// Decorator pattern allows a user to add new functionality to an existing object without altering its structure.

//In this we are going to make a OTT Platform subscription Model
//In which there are going to be 3 types of subscriptions
// Basic, Gold and Platinum
// Gold will have some features Addon to Basic
// Platinum will have Some features Addon to Gold
//Every type of subscription will have some cost and features 
//Basic Subscription :- Cost = 250, features = "Mobile Screen, 720p Content, "
//Gold Subscription :- Cost = Cost of Basic + 250, features = features of basic + "Laptop Screen, 1080p Content, "
//Platinum Subscription :- Cost = cost of Gold + 500, features = feature of gold + "TV Screen, 4k Content, "

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Subscription Interface class
class Subscription{
	public:
		virtual int getCost() = 0;
		virtual string getFeatures() = 0;
};

//Basic Subscription class
//A concrete class for Subscription Interface
class BasicSubscription : public Subscription{
	string features;
		public:
			BasicSubscription(){
				cout << "Basic Subscription Constructor" << endl;
			}
			
			int getCost(){
				return 250;
			}
			
			string getFeatures(){
				features = "Mobile Screen, 720p Content, ";
				return features;
			}
};

//Gold Subscription class
//A concrete class for Subscription Interface
//Its a decorator class
//Its constructor takes an object of basicSubscription class
class GoldSubsDecorator : public Subscription{
	Subscription *basic; // pointer to object of basic Subscription
	string goldFeatures;
	public:
		GoldSubsDecorator(Subscription *SubsObj){
			cout << "Inside Gold Subscription Decorator Constructor" << endl;
			basic  = SubsObj;
		}
		
		int getCost(){
			return basic->getCost() + 250; // addition of cost to basic subscription
		}
		
		string getFeatures(){
			goldFeatures = "Laptop Screen, 1080p Content, "; // addition of features to basic Subscription
			
			string features;
			features.append(basic->getFeatures());
			features.append(goldFeatures);
			
			return features;
		}
};

////Platinum Subscription class
//A concrete class for Subscription Interface
//Its a decorator class
//Its constructor takes an object of GoldSubsDecorator class
class PlatinumSubsDecorator : public Subscription{
	Subscription *gold; // pointer to object of gold Subscription
	string platinumFeatures;
	
	public:
		PlatinumSubsDecorator(Subscription *SubsObj){
			cout << "Inside Platinum Subscription Decorator Constructor" << endl;
			gold  = SubsObj;
		}
		
		int getCost(){
			return gold->getCost() + 500; // addition of cost to gold subscription
		}
		
		string getFeatures(){
			platinumFeatures = "TV Screen, 4k Content, "; // addition of features to platinum Subscription
			
			string features;
			features.append(gold->getFeatures());
			features.append(platinumFeatures);
			
			return features;
		}
		
};

//Client Code
int main()
{
	BasicSubscription *basicSubs = new BasicSubscription();
	cout <<"Basic Subscription Price: " << basicSubs->getCost() << endl;
	cout <<"Basic Subscription Features: " << basicSubs->getFeatures() << endl;
	
	cout << "**********************************************************" << endl;
	
	GoldSubsDecorator *goldSubs = new GoldSubsDecorator(basicSubs);
	cout <<"Gold Subscription Price: " << goldSubs->getCost() << endl;
	cout <<"Gold Subscription Features: " << goldSubs->getFeatures() << endl;
	
	cout << "**********************************************************" << endl;
	
	PlatinumSubsDecorator *platinumSubs = new PlatinumSubsDecorator(goldSubs);
	cout <<"Platinum Subscription Price: " << platinumSubs->getCost() << endl;
	cout <<"Platinum Subscription Features: " << platinumSubs->getFeatures() << endl;
	
}
