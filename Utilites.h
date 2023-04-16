#pragma once
#include <iostream>
#include <vector>
#include "User.h"
#include "hashtableclosed.h"

using namespace std;

vector<User> users;
static vector<User> allUsers;
static HashTableClosed ht;			// hash table how save login and password

User Handler1() {
	bool isExit = true;
	char myChoice;
	while (isExit) {
		cout << "\nMenu1:"
			 << "\n1-Registrations Users"
			 << "\n2-Create message by login"
			 << "\n4-ShowAllUsers"
			 << "\n5-Show HashTable array"
			 << "\n6-exit\n";
		cin >> myChoice;
		if (myChoice == '6') {			// quick exit
			isExit = false;
			break;
		}
		if (myChoice == '1') {
			// registration user
			// and save login and password in hash table
			cout << "Create you login: \n";
			string myLogin;
			cin >> myLogin;
			cout << "Create you password: \n";
			string myPassword;
			cin >> myPassword;
			cout << "Enter your name: \n";
			string myName;
			cin >> myName;

			ht.add(myLogin, myPassword);			// added password to hash table
		
			User user(myLogin, myPassword, myName);
			users.push_back(user);
			allUsers.push_back(user);
			user.show();
		}
		if (myChoice == '2') {
			cout << "Input index user(0): \n";
			int index = 0;
			cin >> index;
			//cout << "You choose user by login: " << users[index] << endl;
			static User currentUser = users[index];
			cout << "new current user selected " << currentUser;
			cout << "\nAuthorization user \n";
			cout << "Input your login: \n";
			string login;
			cin >> login;
			cout << "Input your password: \n";
			string password;
			cin >> password;
			if (login == currentUser.getUserLogin() && password == currentUser.getUserPassword()) {
				cout << "well done" << endl;
			}
			return currentUser;
		}
		if (myChoice == '4') {
			for (auto item : users) {
				cout << "login: " << item.getUserLogin() 
					 << " password: " << item.getUserPassword() 
					 << " name: " << item.getUserName() << endl;
			}
		}
		if (myChoice == '5') {
			cout << "Hash Table: \n";
			ht.printHashTableClosed();
		}
	}
	return User();
}