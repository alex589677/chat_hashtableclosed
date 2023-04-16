#pragma once
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include "TrieAutocomplete.h"

void callHandleFunction() {
	//----autocomplete----
	string s[] = { "adas", "adf", "am", "aok", "dk", "dae", "dad" };
	int length_string = sizeof(s) / sizeof(s[0]);
	Trie* trie = new Trie();
	// input trie tree
	for (int i = 0; i < length_string; i++) {
		trie->insert(s[i]);
	}
	//----autocomplete----
	User currentUser = Handler1();		// call handler file Utilites.h
	map<string, string> containers;
	map<string, string> allContainers;
	cout << " main " << currentUser << endl;
	int counter = 0;
	bool isFlag = true;
	while (isFlag) {
		cout << "Menu2: \n"
			<< "1-write text to user\n"
			<< "2-go previous menu\n"
			<< "3-show local chat\n"
			<< "4-show all chat\n"
			<< "5-exit\n";
		cin >> counter;
		if (counter == 5) {
			isFlag = false;
			break;
		}
		if (counter == 1) {
			// write message
			cout << "Input login from write message: \n";
			string loginSource = "";
			cin >> loginSource;
			cout << "Input login to write message: \n";
			string loginTarget = "";
			cin >> loginTarget;
			string flag = "";
			cout << "Input word for 'local' or 'all' create message: \n";
			cin >> flag;
			trie->printTrie();
			cout << "Write your message, and click Enter: \n";
			string str1;
			// input message and using autocomplete
			/*getline(cin, str1, '@');		// после ввода префикса не печатаются данные дерева*/
			cin >> str1;
			// print prefix words in trie
			trie->printTrieWithPrefix(str1);

			Message message1(loginSource, loginTarget, str1);
			if (flag == "local") {
				cout << "[" << loginTarget << "]: " << message1.getText() << endl;
				containers.insert(make_pair(loginTarget, message1.getText()));
			}
			else if (flag == "all") {
				for (auto& item : users) {
					allContainers.insert(make_pair(item.getUserLogin(), message1.getText()));
				}
				containers.insert(make_pair(loginTarget, message1.getText()));
			}
		}
		if (counter == 2) {
			// go to previous menu
			Handler1();
		}
		if (counter == 3) {
			// show local chat
			cout << "--------LocalChat------------" << endl;
			for (auto& item : containers) {
				cout << "login: " << item.first
					<< "\nmessage: " << item.second << endl;
			}
			cout << "--------------" << endl;
		}
		if (counter == 4) {
			// show for all chat
			cout << "--------AllChat------------" << endl;
			for (auto& item : allContainers) {
				cout << "login: " << item.first
					<< "\nmessage: " << item.second << endl;
			}
			cout << "--------------" << endl;
		}
	}
}