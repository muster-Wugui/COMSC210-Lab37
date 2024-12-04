// COMSC-210 | Lab 378| Xiao Zhang

//
//  main.cpp
//  COMSC210-Lab38
//
//  Created by Xiao Zhang on 12/4/24.
//

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;

int gen_hash_index(string st);
void print_first_100(const map<int, list<string>>& hashtable);
void search_key(const map<int, list<string>>& hashtable);
void add_key(map<int, list<string>>& hashtable);
void remove_key(map<int, list<string>>& hashtable);
void modify_key(map<int, list<string>>& hashtable);

int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int)a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char)b << endl;

    map<int, list<string>> hashtable;

    ifstream infile("lab-37-data.txt");
    
    string text;
    while (getline(infile, text)) {
        int index = gen_hash_index(text);
        hashtable[index].push_back(text);
    }
    infile.close();

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Print the first 100 entries\n";
        cout << "2. Search for a key\n";
        cout << "3. Add a key\n";
        cout << "4. Remove a key\n";
        cout << "5. Modify a key\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                print_first_100(hashtable);
                break;
            case 2:
                search_key(hashtable);
                break;
            case 3:
                add_key(hashtable);
                break;
            case 4:
                remove_key(hashtable);
                break;
            case 5:
                modify_key(hashtable);
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}

int gen_hash_index(string st) {
    int sum = 0;
    for (int i = 0; i < st.length(); i++) {
        sum += (int)st[i];
    }
    return sum % 100;
}

void print_first_100(const map<int, list<string>>& hashtable) {
    cout << "The first 100 map entries in the hash table:" << endl;
    int num = 0;
    for (const auto& entry : hashtable) {
        if (num >= 100) {
            break;
        }
        cout << "Hash Index " << entry.first << ": ";
        for (const auto& code : entry.second) {
            cout << code << "\t";
        }
        cout << endl;
        num++;
    }
}

void search_key(const map<int, list<string>>& hashtable) {
    int key;
    cout << "Enter  index to search: ";
    cin >> key;

    auto it = hashtable.find(key);
    if (it != hashtable.end()) {
        cout << "Hash Index " << key << ": ";
        for (const auto& code : it->second) {
            cout << code << "\t";
        }
        cout << endl;
    } else {
        cout << "Can't find the key" << endl;
    }
}

void add_key(map<int, list<string>>& hashtable) {
    string new_string;
    cout << "Enter a string to add: ";
    cin >> new_string;

    int index = gen_hash_index(new_string);
    hashtable[index].push_back(new_string);

    cout << "Added string '" << new_string << "' to hash index " << index<< endl;
}

void remove_key(map<int, list<string>>& hashtable) {
    int key;
    cout << "Enter hash index to remove: ";
    cin >> key;

    if (hashtable.erase(key)) {
        cout << "Removed key " << key << " from the hash table." << endl;
    } else {
        cout << "Key can't be found" << endl;
    }
}

void modify_key(map<int, list<string>>& hashtable) {
    int key;
    cout << "Enter hash index to modify: ";
    cin >> key;

    auto it = hashtable.find(key);
    if (it != hashtable.end()) {
        cout << "Current entries at hash index " << key << ": ";
        for (const auto& code : it->second) {
            cout << code << "\t";
        }
        cout << endl;

        string new_string;
        cout << "Enter a new string: ";
        cin >> new_string;

        it->second.push_back(new_string);
        cout << "Added string '" << new_string << "' to hash index " << key << "." << endl;
    } else {
        cout << "Key can't be found." << endl;
    }
}
