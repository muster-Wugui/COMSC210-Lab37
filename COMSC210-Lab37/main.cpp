// COMSC-210 | Lab 37 | Xiao Zhang

//
//  main.cpp
//  COMSC210-Lab37
//
//  Created by Xiao Zhang on 12/4/24.
//

#include <iostream>
#include <string>
using namespace std;

int sum_ascii(string st);

int main() {
    char a = 'A';
    cout << a << endl;
    cout << (int) a << endl;
    int b = 66;
    cout << b << endl;
    cout << (char) b << endl;
    
    string test;
    cout << "Enter a string: ";
    cin >> test;
    
    cout << "The sum of ASCII values: " << sum_ascii(test) << endl; //Print out the sum
    

    return 0;
}

int sum_ascii(string st){
    int sum = 0;
    
    for (int i = 0; i < st.length(); i++) {
           sum += (int)st[i]; // This is the step to cast each character to its ASCII value and add to sum
       }
    
    return sum;
}

/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/
