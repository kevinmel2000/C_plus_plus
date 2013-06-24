//
//  str_ops.h
//  String Handling
//
//  Created by Sudheendra Ayalasomayajula on 6/23/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef String_Handling_str_ops_h
#define String_Handling_str_ops_h



#endif

#include <iostream>
#include <string>

using namespace std;

void call_funcs_str_ops(){
    //Create some string objects.
    //Three are initialized using the string literal passed as an argument.
    string str1("Alpha");
    string str2("Beta");
    string str3("Gamma");
    string str4;
    
    //Output a string via cout.
    cout << "Here are the original strings:\n";
    cout << " str1: " << str1 << endl;
    cout << " str2: " << str2 << endl;
    cout << " str3: " << str3 << endl;
    
    //Display the maximum string length.
    cout << "The maximum string length is: " << str1.max_size() << "\n\n";
    
    //Display the size of str1.
    cout << "str1 contains " << str1.size() << " characters.\n";
    
    //Display the capacity of str1.
    cout << "Capacity of str1: " << str1.capacity() << "\n\n";
    
    //Display the characters in a string one at a time by using the indexing operator.
    for (unsigned i = 0; i < str1.size(); ++i) {
        cout << "str1[i]: " << str1[i] << endl;
    }
    
    cout << endl;
    
    //Assign one string to another.
    str4 = str1;
    cout << "str4 after being assigned str1: " << str4 << "\n\n";
    
    //Concatenate two strings.
    str4 = str1 + str3;
    cout << "str4 after begin assigned str1+str3: " << str4 << "\n\n";
    
    //Insert one string into another.
    str4.insert(5, str2);
    cout << "str4 after inserting str2: " << str4 << "\n\n";
    
    //Obtain a substring.
    str4 = str4.substr(5, 4);
    cout << "str4 after being assigned str4.substr(5, 4): " << str4 << "\n\n";
    
    //Compare two strings.
    cout << "Compare strings.\n";
    if (str3 > str1) {
        cout << "str3 > str1\n";
    }
    
    if (str3 == str1+str2) {
        cout << "str3 == str1+str2\n";
    }
    
    if (str1 <= str2) {
        cout << "str1 <=str2\n\n";
    }
    
    //Create a string object using another string object.
    cout << "Initialize str5 with the contents of str1.\n";
    string str5(str1);
    cout << "str5: " << str5 << "\n\n";
    
    //Erase str4.
    cout << "Erasing str4.\n";
    str4.erase();
    if (str4.empty()) {
        cout << "str4 is now empty.\n";
    }
    
    cout << "Size and capacity of str4 is " << str4.size() << " " << str4.capacity() << "\n\n";
    
    //Use push_back() to add characters to str4.
    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        str4.push_back(ch);
    }
    
    cout << "str4 after calls to push_back(): " << str4 << endl;
    cout << "Size and capacity of str4 is now " << str4.size() << " " << str4.capacity() << "\n\n";
    
    //Set the capacity of str4 to 128.
    cout << "Setting the capacity of str4 to 128\n";
    str4.reserve(128);
    cout << "Capacity of str4 is now: " << str4.capacity() << "\n\n";
    
    //Input a string via cin.
    cout << "Enter a string: ";
    cin >> str1;
    cout << "You entered: " << str1 << "\n\n";
}