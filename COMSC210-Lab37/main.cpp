// COMSC-210 | Lab 37 | Xiao Zhang

//
//  main.cpp
//  COMSC210-Lab37
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

int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;
    
    map<int, list<string>> hashtable;
    
    ifstream infile("lab-37-data.txt");
    
    string text;
        
    while (getline(infile, text)){
        int index = gen_hash_index(text);
        hashtable[index].push_back(text);
    }
    
    infile.close();
    
    cout << "The first 100 map entries in the hash table:" << endl;
    int num = 0;
    for (const auto& entry : hashtable) {
        if (num >= 100){
            return 1;
        }
        cout << "Hash Index " << entry.first << ": ";
        for (const auto& code : entry.second) {
            cout << code << "\t";
        }
        cout << endl;
        num++;
        }
    
    return 0;
}

int gen_hash_index(string st){
    int sum = 0;
    
    for (int i = 0; i < st.length(); i++) {
           sum += (int)st[i]; // This is the step to cast each character to its ASCII value and add to sum
       }
     
    int hash = sum % 100;
    
    return hash;
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
