//
//  str_search_and_replace.h
//  String Handling
//
//  Created by Sudheendra Ayalasomayajula on 6/23/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef String_Handling_str_search_and_replace_h
#define String_Handling_str_search_and_replace_h



#endif

#include <iostream>
#include <string>

using namespace std;

bool search_and_replace(string &str, const string &oldsubstr, const string &newsubstr);

void call_funcs_str_search_and_replace(){
    string str = "This is a test. So is this.";
    
    cout << "Original string: " << str << "\n\n";
    
    cout << "Replacing 'is' with 'was':\n";
    
    //The following replaces is with was.
    //Notice that it passes string literals for the substrings.
    //These are automatically converted into string objects.
    while (search_and_replace(str, "is", "was")) {
        cout << str << endl;
    }
    
    cout << endl;
    
    //Of course, you can explicitly pass string objects, too.
    string oldstr("So");
    string newstr("So too");
    cout << "Replace 'So' with 'So too'" << endl;
    search_and_replace(str, oldstr, newstr);
    cout << str << endl;
}

//In the string referred to by str, replace oldsubstr with newsubstr.
//Thus, this function modifies the string referred to by str.
//It returns true if a replacement occurs and false otherwise.
bool search_and_replace(string &str, const string &oldsubstr, const string &newsubstr){
    string::size_type startidx;
    startidx = str.find(oldsubstr);
    
    if (startidx != string::npos) {
        str.replace(startidx, oldsubstr.size(), newsubstr);
        return true;
    }
    
    return false;
}