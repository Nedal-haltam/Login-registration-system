#include<iostream>
#include<cstdlib>
#include "database.h"

using namespace std;

//try it for fun


void showlist()
{
	cout << "\t\t\thello , choose a choice :\n";
	cout << "\t\t\t1-Login\n\t\t\t2-Register\n";
	return;
}


int main()
{
	
	base data;
	while (1)
	{
		showlist();
		int choice; cin >> choice; string username, password;
		cout << "enter username: "; cin.ignore(); getline(cin, username);
		cout << "enter password: "; 		  getline(cin, password);

		if (choice == 1)
		{
			data.login(username, password);
		}
		else if (choice == 2)
		{
			data.Register(username, password);
		}
		else cout << "wrong choice dont give up" << endl;

	}
}
