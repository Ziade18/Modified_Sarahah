#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include"Header.h"
#include<unordered_map>
#include<vector>
#include<stack>
#include<list>

using namespace std;

//void login();
//void registr();
//
//
int main()
{
    int choice;
    User user;

    cout << "1.LOGIN" << endl;
    cout << "2.REGISTER" << endl;;
    cout << "3.Exit" << endl;
    cout << "\nEnter your choice :";
    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
        user.login();

        break;
    case 2:
        user.Regitster();
        break;
    case 3:

        cout << "Thanks for using this program\n\n";
        break;
    default:
        cout << "You've made a mistake , give it a try again\n" << endl;
        main();
    }

}
