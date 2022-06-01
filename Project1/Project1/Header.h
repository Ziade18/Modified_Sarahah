#pragma once
#pragma once
#pragma once
#pragma once
#include <iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;

class Message {
public:
	string text;
	//bool isfavourite = false;
	//bool isSent();
	//bool isRecived();
	Message();
	void addFavourite(string choice);
	void addFavourite_recieved(string choice);

	void ViewFavourite_sent();
	void ViewFavourite_recieved();
	void ViewRecieved();
	void sendMessg();
	void undolast();
	void viewsent();
	void removeFAV();
	deque <string> temporarymessages;
	stack<string>messages;

};
class User {
public:
	int ID;

	void login();
	void Regitster();
	void main_menu();
	void addContanct();
	bool checkid(int x);
	void viewContact();
	User();
	void searchCont();



private:
	string username, password;
	string* contacts;
	Message messages;

};
//class Contact {
//private:
//	char fname[20], lname[20], email[100];
//public:
//	Contact();
//	void addContact();
//	void viewContacts();
//	void searchContact();
//	~Contact();
//};
//
