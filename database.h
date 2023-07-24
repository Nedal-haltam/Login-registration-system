#pragma once
#include<iostream>
#include<cstdlib>
#include<unordered_map>
#include<string.h>
#include "user_profile.h"
using namespace std;


class base
{
private:

	unordered_map<string, string*> userpass;
	
	unordered_map<string, user_profile*> userdata;

	bool is_valid_username(string, char);

	

public:

	base();


	void login(string , string);
	void Register(string , string);


};
base::base(){}

void base::login(string user , string pass)
{
	if (!is_valid_username(user , 'l')) {
		cout << "user name entred is not valid" << endl;
		return;
	}

	if (*userpass[user] == pass) {
		cout << "access granted welcome, " << user << endl;
		userdata[user]->showoptions();

	}
	else
	{
		cout << "wrong invalid password dont give up\n";
	}


}

bool base::is_valid_username(string user, char c)
{
	if (c == 'r')
	{
		if (userpass.find(user) != userpass.end()) { cout << "username is already used dont give up" << endl; return false; }
		else return true;
	}

	else if (c == 'l')
	{
		if (userpass.find(user) == userpass.end()) { cout << "username is wrong please try again" << endl; return false; }
		else return true;
	}

}
void base::Register(string user , string pass)
{
	if (!is_valid_username(user, 'r')) return;

	else
	{
		userdata[user] = new user_profile(user, pass);

		userpass[user] = &userdata[user]->password;
		cout << "registered successfully" << endl;

	}

}

