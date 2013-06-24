//
//  isalpha_isdigit_isspace_ispunct.h
//  String Handling
//
//  Created by Sudheendra Ayalasomayajula on 6/23/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef String_Handling_isalpha_isdigit_isspace_ispunct_h
#define String_Handling_isalpha_isdigit_isspace_ispunct_h



#endif

#include <iostream>
#include <cctype>

using namespace std;

void call_funcs_isalpha_isdigit_isspace_ispunct(){
    const char *str = "I have 30 apples and 12 pears. Do you have any?";
    int letters  = 0, spaces = 0, punct = 0, digits = 0;
    
    cout << str << endl;
    
    while (*str) {
        if (isalpha(*str)) {
            ++letters;
        }else if(isspace(*str)){
            ++spaces;
        }else if(ispunct(*str)){
            ++punct;
        }else if(isdigit(*str)){
            ++digits;
        }
        
        ++str;
    }
    
    cout << "Letters: " << letters << endl;
    cout << "Digits: " << digits << endl;
    cout << "Spaces: " << spaces << endl;
    cout << "Punctuation: " << punct << endl;
}