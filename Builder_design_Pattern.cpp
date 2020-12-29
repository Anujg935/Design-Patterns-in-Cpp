//This is a Notification manager Design Problem solved using Builder design Pattern

// In this for a accademy ther are 3 types of Customers namely:-"Individial", "Coaching" & "Group"
// And when these type of customers books the slot then notification is send to different peoples woth different modes

// In case of "Individual"
//     - Notification is send to Security and Members

// In case of "Coaching"
//     - Notification is send to Security , Members and Coach

// In case of "Group"
//     - Notification is send to Security, Members, Coach and Manager;


#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//PersonalNotification Interface
class PersonalNotification{
	public:
		virtual void sendNotification(string booking) = 0;
};

// concrete class of personalNotification
class securityNotification : public PersonalNotification{
	public:
		void sendNotification(string booking){
			cout <<"Security Notification: SMS" << endl;
		}
};

// concrete class of personalNotification
class memberNotification : public PersonalNotification{
	public:
		void sendNotification(string booking){
			cout <<"Member Notification: SMS and Email" << endl;
		}
};

// concrete class of personalNotification
class coachNotification : public PersonalNotification{
	public:
		void sendNotification(string booking){
			cout <<"Coach Notification: SMS and Email" << endl;
		}
};

// concrete class of personalNotification
class managerNotification : public PersonalNotification{
	public:
		void sendNotification(string booking){
			cout <<"Manager Notification: Email" << endl;
		}
};

// A composite class
class Notification{
	public:
		vector<PersonalNotification*> mList;
		string booking;
		
		Notification(string b){
			booking = b;
		}
		
		void Notify(){
		    cout << "Notifications for " << booking <<" type are :-" << endl;
			for(auto m: mList){
				m->sendNotification(booking);
			}
		}
};

// Builder class to handle everything
// with this client code will remain same even on modification of internal codes
class NotificationBuilder{
	public:
		static Notification* buildNotification(string booking){
			if(booking == "Individual"){
				return buildIndividualBooking(booking);
			}
			else if(booking == "Coaching"){
				return buildCoachBooking(booking);
			}
			else if(booking == "Group"){
				return buildGroupBooking(booking);
			}
		}
		
		static Notification* buildIndividualBooking(string booking){
			Notification *n = new Notification(booking);
			n->mList.push_back(new securityNotification());
			n->mList.push_back(new memberNotification());
			
			return n;
		}
		
		static Notification* buildCoachBooking(string booking){
			Notification *n = new Notification(booking);
			n->mList.push_back(new securityNotification());
			n->mList.push_back(new memberNotification());
			n->mList.push_back(new coachNotification());
			
			return n;
		}
		
		static Notification* buildGroupBooking(string booking){
			Notification *n = new Notification(booking);
			n->mList.push_back(new securityNotification());
			n->mList.push_back(new memberNotification());
			n->mList.push_back(new coachNotification());
			n->mList.push_back(new managerNotification());
			
			return n;
		}
};

// Client Code
int main()
{
	Notification *n = NotificationBuilder::buildNotification("Individual");
	n->Notify();
	
	n = NotificationBuilder::buildNotification("Coaching");
	n->Notify();
	
	n = NotificationBuilder::buildNotification("Group");
	n->Notify();
}
