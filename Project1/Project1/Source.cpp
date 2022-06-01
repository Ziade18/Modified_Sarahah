#include<iostream>
#include"Header.h"
#include<string>
#include <filesystem> 
#include<fstream>
#include<stack>
#include<list>
#include<unordered_map>
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <conio.h>
#include <cstdlib>
#include <map>
#include <list>
#include <cstdlib>
#include <ctime>
#include<vector>
#include<cstdio>
#include <stdio.h>
#include<deque>
using namespace std;
stack<string> s1;
deque<string> n;
int logged_ID1;
string named;

User::User() {

}



void User::login() {

    // int count;
    bool islogin = false;
    string user, pass, u, p;

    cout << "please enter the following details" << endl;
    cout << "USERNAME :";
    cin >> user;
    cout << "PASSWORD :";
    cin >> pass;

    ifstream input("log.txt");
    while (input >> u >> p >> ID)
    {
        if (u == user && p == pass)

        {
            islogin = true;
            //ID+=1;
          //  logged_ID(ID);
            logged_ID1 = ID;
            named = user;
        }

    }

    input.close();
    if (islogin)
    {
        cout << "login succssuflly \n\n\n";
        cout << "       HEllO " << user << "   " << "Your ID is : " << logged_ID1 << endl;
        main_menu();

    }
    else
    {
        cout << "\nLOGIN ERROR\nPlease check your username and password\n";
        login();
    }
}
void User::Regitster() {

   /* string  ru, rp;*/

    /*unordered_map<string, string> map;*/

    cout << "Enter the username :";
    cin >> username;


    cout << "\nEnter the password :";
    cin >> password;

    cout << "\n Enter the id :";
    cin >> ID;
    checkid(ID);
    ofstream reg("log.txt", ios::app);
    reg << username << endl << password << endl << ID << endl;


    cout << "\nRegistration Sucessful\n";
    login();

}
bool User::checkid(int x)
{
    ifstream reg1("log.txt");
    int userID, wantedID, p;
    //   bool found = false;
    string u;
    //open file
    while (reg1 >> u >> p >> userID) {
        if (userID == x) {
            cout << "Unvalid ID .... Please Enter try again using diffrent ID   " << endl;
            Regitster();
            return false;
        }
    }
}



void User::main_menu()
{
    int choice;
    Message message;
    cout << "\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n[1] Add contact\n" << "[2] View contacts\n" << "[3] Search for contact\n"
        << "[4] Send a message to contact\n" << "[5] View sent messages\n"
        << "[6] View recieved messages\n" << "[7] View favourite messages that you sent\n"
        <<"[8] View favourite messages that you recieved\n"
        << "[9] Add message to favourites\n" << "[10] to Remove oldest message from favourites that i recieved\n"
        << "[11] to undo the last message\n";
    cin >> choice;
    switch (choice) {

    case 1:
        addContanct();
        break;
    case 2:
        //view Contacts
        viewContact();
        break;
    case 3:
        searchCont();
        break;
    case 4:
        //send a message
        message.sendMessg();
        break;
    case 5:
        //View sent messages
       // message.ViewSent();
        message.viewsent();
        break;
    case 6:
        //view recieved message
        message.ViewRecieved();
        break;
    case 7:
        //View favouite messages that you sent
        message.ViewFavourite_sent();
        break;
    case 8:
        //View favouite messages that you recieved
        message.ViewFavourite_recieved();
        break;
    case 9:
       // Add message to favourites that you recieved
        message.ViewRecieved();
        break;
    case 10:
   // to Remove oldest message from favourites that i recieved
        message.removeFAV();
        break;
    case 11:
        //Remove the last message
        message.undolast();
        break;

        break;
    default:
        cout << "You have to choose a number from 1 to 9";
        main_menu();
    }
    cin.get();
    cin.get();
    //main();

}

void User::viewContact()
{
    int i = 1;
    stack<string>n;
    string x, y, z;
    cout << "Your Contacts Are : \n" << endl;
    ifstream read("addContact.txt");
    while (read >> x >> y >> z)
        if (x == named)
        {
            n.push(z);
            while (!n.empty())
            {
                cout << i << "- " << n.top() << endl;
                n.pop();
                i++;
            }
        }
    main_menu();
}

void User::addContanct() {
    string name, y, reading, s, k;
    bool x = false;
    bool m = false;
    int userID, wantedID, p, t;
    cout << "Enter Contact Name: " << endl;;
    cin >> name;
    ifstream reg("addContact.txt");
    while (reg >> reading >> s >> k)
        if (reading == named && k == name)
        {
            //cout << "you already Added this user before try adding new user ...." << endl;
            //addContanct();
            m = true;
        }
    if (m)
    {
        cout << "you already Added this user before try adding new user by entering 1....or back to main menu by 0" << endl;
        int j;
        cin >> j;
        if (j == 1)
        {
            addContanct();
        }
        else
        {
            main_menu();
        }
    }

    else
    {

        ifstream read("log.txt");
        while (read >> y >> p >> userID)
        {
            if (name == y)
            {
                x = true;
                t = userID;
            }
        }
        if (x)
        {
            ofstream add("addContact.txt", ios::app);
            cout << "YOU Added the user that his Name IS : " << name << "   " << "And his ID is: " << t << endl;
            add << named << " added " << name << endl;
            cout << "\n\n";
            cout << "1- To Add Another User: " << endl;
            cout << "2- TO Back To Main Menu: " << endl;
            int l;
            cin >> l;
            if (l == 1)
            {
                addContanct();
            }
            if (l == 2)
            {
                main_menu();
            }

        }

        else
        {
            int w;

            cout << "the contact that you entered is not valid..... " << endl;
            cout << "1-Add Contact Again. " << endl << "2-Back To Main Menu. " << endl;
            cin >> w;
            if (w == 1)
            {
                addContanct();
            }
            if (w == 2)
            {
                main_menu();

            }
        }
    }
}

void User::searchCont()
{
    string x, y, z, a;
    bool p = false;
    ifstream read("addContact.txt");
    cout << "ENTER THE NAME OF THE CONTACT : ";
    cin >> a;
    while (read >> x >> y >> z)
    {
        if (x == named)
        {
            if (z == a)
            {
                p = true;
            }

        }
        
            
           
     }
    read.close();
        
        if (p)
        {
            cout << " The Contact Is found In Your Contacts : " << a << endl;
            cout << "1-to search at another contact... " << endl;
            cout << "2-To Back To Main Menu.... " << endl;
            int c;
            cin >> c;
            if (c == 1)
            {
                searchCont();
            }
            else
            {
                main_menu();
            }

        }
        else
        {
            cout << "\n" << "         NOT FOUND       " << endl;
            cout << "1-to search at another contact... " << endl;
            cout << "2-To Back To Main Menu.... " << endl;
            int c;
            cin >> c;
            if (c == 1)
            {
                searchCont();
            }
            else
            {
                main_menu();
            }
        }
    
}
Message::Message() {

}

void Message::addFavourite(string choice)
{
    while (!messages.empty()) {
        messages.pop();
    }


   // fstream userfile("FavouriteMessages_sent.txt", ios::app | ios::in | ios::out);


}

void Message::addFavourite_recieved(string choice)
{
    fstream userfile("FavouriteMessages_recieved.txt", ios::app | ios::in | ios::out);
    User user;
    vector<string>v;
    stack<string> isfav;
    //  list<string>mm;
    
    char l;
    bool x = false;
    int index = 1;
    //ifstream read("FavouriteMessages_recieved.txt");
    int i = 1;
    for (string line; getline(userfile, line); i++)
    {
        for (int i = 0; i <= line.size() - 1; i++)
        {
            isfav.push(line);
            break;
        }
    }
    if (choice != isfav.top())
    {
        isfav.pop();
    }
    else
    {
        x = true;
    }
    if (x)
    {
        userfile << choice << endl;
        user.main_menu();
    }
}
void Message::ViewFavourite_recieved()
{
    User user;
    vector<string>v;
    stack<string> messgOfspecificUser;
  //  list<string>mm;

    char l;
    int index = 1, choice;
    ifstream read("FavouriteMessages_recieved.txt");
    int i = 1;
    for (string line; getline(read, line); i++)
    {



        for (int i = 0; i <= line.size() - 1; i++)
        {

            if (to_string(logged_ID1) == string(1, line[line.size()-1]))
            {

                messgOfspecificUser.push(line);

                break;

            }

        }

    }
    while (!messgOfspecificUser.empty())
    {
        // mm.push_back(messgOfspecificUser.top());
        v.push_back(messgOfspecificUser.top());
        cout << index << "- " << messgOfspecificUser.top() << endl;
        messgOfspecificUser.pop();
        index++;

    }
    cout << "\n\n";
    cout << "            PRESS ANY NUMBER TO BACK TO MAIN MENU     " << endl;
    int k;
    cin >> k;
    user.main_menu();
}

void Message::ViewFavourite_sent()
{
    User user;
    vector<string>v;
    stack<string> favmessgOfspecificUser;
    

    ifstream read("FavouriteMessages_sent.txt");
    int i = 1, index = 1;
    for (string line; getline(read, line); i++)
    {



        for (int i = 0; i <= line.size() - 1; i++)
        {

            if (to_string(logged_ID1) == string(1, line[0]))
            {

                favmessgOfspecificUser.push(line);

                break;

            }

        }

    }
    while (!favmessgOfspecificUser.empty())
    {
        // mm.push_back(messgOfspecificUser.top());
        v.push_back(favmessgOfspecificUser.top());
        cout << index << "- " << favmessgOfspecificUser.top() << endl;
        favmessgOfspecificUser.pop();
        index++;

    }
    cout << "\n\n";
    cout << "            PRESS ANY NUMBER TO BACK TO MAIN MENU     " << endl;
    int k;
    cin >> k;
    user.main_menu();




}
void Message::ViewRecieved() {

    {
        User user;
        vector<string>v;
        stack<string>RecmessgOfspecificUser;
        list<string>mm;

        char l;
        int index = 1, choice;
        ifstream read("sendMessage.txt");
        int i = 1;
        for (string line; getline(read, line); i++)
        {
         //   cout <<  << endl;


            for (int i = 0; i <= line.size() - 1; i++)
            {

                if (to_string(logged_ID1) == string(1, line[line.size() - 1]))
                {

                    RecmessgOfspecificUser.push(line);

                    break;

                }

            }

        }
        while (!RecmessgOfspecificUser.empty())
        {
            // mm.push_back(messgOfspecificUser.top());
            v.push_back(RecmessgOfspecificUser.top());
            cout << index << "- " << RecmessgOfspecificUser.top() << endl;
            RecmessgOfspecificUser.pop();
            index++;

        }

        cout << "Do you like to add a message to your favourites y/n " << endl;
        cin >> l;
        if (l == 'y') {
            cout << "choose a message to add to your favourites" << endl;
            int choice;
            cin >> choice;
            --choice;
            /*	if (choice < counter) {
                    cout << "wrong number" << endl;
                }
                else*/
            addFavourite_recieved(v.at(choice));
            cout << v.at(choice) << endl;
            v.pop_back();
            cout << "\n\n";
            cout << "            PRESS ANY NUMBER TO BACK TO MAIN MENU     " << endl;
            int k;
            cin >> k;
            user.main_menu();
        }

        else
            user.main_menu();

    }
}

void Message::viewsent()
{
    User user;
    vector<string>v;
    stack<string> messgOfspecificUser;
    list<string>mm;

    char l;
    int index = 1, choice;
    ifstream read("sendMessage.txt");
    int i = 1;
    for (string line; getline(read, line); i++)
    {



        for (int i = 0; i <= line.size() - 1; i++)
        {

            if (to_string(logged_ID1) == string(1, line[0]))
            {

                messgOfspecificUser.push(line);

                break;

            }

        }

    }
    while (!messgOfspecificUser.empty())
    {
       // mm.push_back(messgOfspecificUser.top());
        v.push_back(messgOfspecificUser.top());
        cout << index << "- " << messgOfspecificUser.top() << endl;
        messgOfspecificUser.pop();
        index++;

    }

    cout << "Do you like to add a message to your favourites y/n " << endl;
    cin >> l;
    if (l == 'y') {
        cout << "choose a message to add to your favourites" << endl;
        int choice;
        cin >> choice;
        --choice;
        /*	if (choice < counter) {
                cout << "wrong number" << endl;
            }
            else*/
        addFavourite(v.at(choice));
        cout << v.at(choice) << endl;
        v.pop_back();
        user.main_menu();
    }
    
    else
        user.main_menu();

}
void Message::removeFAV()
{
 
    User user;
    vector<string>v;
    stack<string> messgOfspecificUser;
    list<string>mm;

    char l;
    int index = 1, choice,rr=1;
    ifstream read("FavouriteMessages_recieved.txt");
    int i = 1;
    for (string line; getline(read, line); i++)
    {



        for (int i = 0; i <= line.size() - 1; i++)
        {

            if (to_string(logged_ID1) == string(1, line[line.size() - 1]))
            {

                v.push_back(line);
               
                break;

            }

        }

    }
    //cout << v.size() << endl;
    while (v.size()!=rr)
    {
       
        
        
       
        cout << index << "- " << v.at(rr) << endl;
        rr++;
       index++;
       
             

    }
    
    cout << "\n\n";
    cout << "            PRESS ANY NUMBER TO BACK TO MAIN MENU     " << endl;
    int k;
    cin >> k;
    user.main_menu();
}
void Message::sendMessg()
{

    User user;
    string content, y, us_;
    int x, p, id, keep_reciever_id;
    bool isThere = false;

    //creating file to store recived messages
    fstream recieve("recieveMessage.txt", ios::app);

    cout << "Send a new message : ";
    getline(cin >> ws, content);

    cout << "to user: ";
    getline(cin >> ws, us_);


    ifstream read("log.txt");
    while (read >> y >> p >> id) {
        if (us_ == y) {
            isThere = true;
            keep_reciever_id = id;

        }
    }
    if (isThere) {

        //creating file to store send messages
        ofstream send("sendMessage.txt", ios::app);

        send << logged_ID1 << "   " << content << "   " << keep_reciever_id << endl;
    }
    else
    {
        cout << "User doesn't exist"<<endl;
        sendMessg();
    }

    cout << "1-To send another message " << endl;
    cout << "2-To back to the main menu " << endl;
    cin >> x;
    if (x == 1)
    {
        sendMessg();

    }
    else if (x == 2)
    {
        user.main_menu();

    }


}














void Message::undolast()
{
    
    User user;
    vector<string>v;
    stack<string> messgOfspecificUser;
    list<string>mm;

    char l;
    int index = 1, choice, rr=0;
    ifstream read("sendMessage.txt");
    int i = 1;
    for (string line; getline(read, line); i++)
    {



        for (int i = 0; i <= line.size() - 1; i++)
        {

            if (to_string(logged_ID1) == string(1, line[0]))
            {

                messgOfspecificUser.push(line);

                break;

            }

        }

    }

    messgOfspecificUser.pop();
    while (!messgOfspecificUser.empty())
    {
        cout << messgOfspecificUser.top() << endl;
        messgOfspecificUser.pop();
    }
    //while (!messgOfspecificUser.empty())
    //{
    //    // mm.push_back(messgOfspecificUser.top());
    //    v.push_back(messgOfspecificUser.top());
    //    cout << index << "- " << messgOfspecificUser.top() << endl;
    //    messgOfspecificUser.pop();
    //    index++;

    //}


        cout << "\n\n";
        cout << "            PRESS ANY NUMBER TO BACK TO MAIN MENU     " << endl;
        int k;
        cin >> k;
        user.main_menu();
    



}


