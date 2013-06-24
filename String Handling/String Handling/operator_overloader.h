//
//  operator_overloader.h
//  String Handling
//
//  Created by Sudheendra Ayalasomayajula on 6/23/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef String_Handling_operator_overloader_h
#define String_Handling_operator_overloader_h



#endif

#include <iostream>
#include <string>

using namespace std;

string operator- (const string &left, const string &right);
string operator-= (string &left, const string &right);

void call_funcs_operator_overloader(){
    string str("This is a test.");
    string res_str;
    
    cout << "Contents of str: " << str << "\n\n";
    
    //Subtract "is" from str and put the result in res_str.
    res_str = str - "is";
    cout << "Result of str - \"is\": " << res_str << "\n\n";
    cout << "Here is str again " << str << "\nNotice that str is unchanged by the preceding operations." << "\n\n";
    
    cout << "Here are some more examples:\n\n";
    
    //Attempt to subtract "xyz". This causes no change.
    res_str = str - "xyz";
    cout << "Result of str - \"xyz\": " << res_str << "\n\n";
    
    //Remove the last three characters from str.
    res_str = str - "st.";
    cout << "Result of str - \"st.\": " << res_str << "\n\n";
    
    //Remove a null string, which results in no change.
    res_str = str - "";
    cout << "Result of str - \"\": " << res_str << "\n\n";
}

//Overload - (subtraction) for string objects so that it removes the first occurrence of the substring on the right from the string on the left and returns the result.
//Neither operand is modified.
//If the substring was not found, the result contains the same string as the left operand.
string operator- (const string &left, const string &right){
    string::size_type i;
    string result(left);
    
    i = result.find(right);
    if (i != string::npos){
        result.erase(i, right.size());
    }
    
    return result;
}

//Overload -= for string objects.
//It removes the first occurrence of the substring on the right from the string on the left.
//Thus, the string referred to by left is modified.
//The resulting string is also returned.
string operator-= (string &left, const string &right){
    string::size_type i;
    
    i = left.find(right);
    if (i != string::npos){
        left.erase(i, right.size());
    }
    
    return left;
}