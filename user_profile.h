#pragma once
#include<iostream>
#include<cstdlib>
#include<set>
#include<string.h>
#include<string>
#include "database.h"
using namespace std;

class user_profile
{
private:
	string username, password, notes;
	set<string> friends;

	void changepass();


public:
	user_profile(string , string );
	void showoptions();
	void editnotes();
	void addfriend();


	
	friend class base;
};
user_profile::user_profile(string user, string pass)
{
	this->username = user;
	this->password = pass;
}

void user_profile::showoptions()
{
	while (1)
	{
		cout << "\t\t\t1-edit your notes\n\t\t\t2-add friend name to list\n\t\t\t3-change password\n\t\t\t4-exit\n";
		int choice; cin >> choice;

		switch (choice)
		{
		case 1:
			editnotes();
			break;
		case 2:
			addfriend();
			break;
		case 3:
			changepass();
			break;
		case 4:
			return;
		default:
			showoptions();
			break;
		}
	}
	

}


void user_profile::editnotes()
{
	cout << "hello here you can edit the following note" << endl;
	cout << notes << endl;

	cin.ignore(); getline(cin, notes);
}

void user_profile::addfriend()
{
	cout << "this is your friends list do you want to add more! (yes or no)\n";

	for (auto& i : friends) cout << i << endl;
	string choice; cin.ignore(); getline(cin, choice);

	if (choice == "no") return;

	else if (choice == "yes")
	{
		cin.ignore(); getline(cin, choice);
		friends.insert(choice);
		addfriend();
	}

	else addfriend();
	return;
}

void user_profile::changepass()
{
	while (1)
	{
		cout << "enter no to go back\n";
		cout << "enter old password : ";
		string pass; cin.ignore(); getline(cin, pass);
		if (pass == "no") return;

		if (password == pass)
		{
			cout << "enter new password : "; cin.ignore(); getline(cin, pass);
			password = pass;
			return;
		}


		else if (password != pass) {
			cout << "wrong entered password try again\n";
			continue;
		}

		
	}
}
