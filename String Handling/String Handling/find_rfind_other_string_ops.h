//
//  find_rfind_other_string_ops.h
//  String Handling
//
//  Created by Sudheendra Ayalasomayajula on 6/23/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef String_Handling_find_rfind_other_string_ops_h
#define String_Handling_find_rfind_other_string_ops_h



#endif

#include <iostream>
#include <string>

using namespace std;

void showresult(string s, string::size_type i);

void call_funcs_find_rfind_other_string_ops(){
    string::size_type indx;
    
    //Create a string.
    string str("one two three, one two three");
    string str2;
    
    cout << "String to be searched: " << str << "\n\n";
    
    cout << "Searching for the first occurrence of 'two'\n";
    indx = str.find("two");
    showresult(str, indx);
    
    cout << "Searching for the last occurrence of 'two'\n";
    indx = str.rfind("two");
    showresult(str, indx);
    
    cout << "Searching for the first occurrence of t or h\n";
    indx = str.find_first_of("th");
    showresult(str, indx);
    
    cout << "Searching for the last occurrence of t or h\n";
    indx = str.find_last_of("th");
    showresult(str, indx);
    
    cout << "Searching for the first occurrence of any character other than o, n, e, or space\n";
    indx = str.find_first_not_of("one ");
    showresult(str, indx);
    
    cout << "Searching for the last occurrence of any character other than o, n, e, or space\n";
    indx = str.find_last_not_of("one ");
    showresult(str, indx);
}

//Display the results of the search.
void showresult(string s, string::size_type i){
    if (i == string::npos) {
        cout << "No match found.\n";
    }
    
    cout << "Match found at index " << i << endl;
    
    cout << "Remaining string from point of match: " << s.substr(i) << "\n\n";
}