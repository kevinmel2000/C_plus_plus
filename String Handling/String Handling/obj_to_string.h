//
//  obj_to_string.h
//  String Handling
//
//  Created by Sudheendra Ayalasomayajula on 6/23/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef String_Handling_obj_to_string_h
#define String_Handling_obj_to_string_h



#endif

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void call_funcs_obj_to_string(){
    string str("This is a test.");
    char cstr[80];
    
    cout << "Here is the original string:\n";
    cout << str << "\n\n";
    
    //Obtain a pointer to the string.
    const char *p = str.c_str();
    
    cout << "Here is the null-terminated version of the string:\n";
    cout << p << "\n\n";
    
    //Copy the string into a statistically allocated array.
    
    //First, confirm that the array is long enough to hold the string.
    if (sizeof(cstr) < str.size() + 1) {
        cout << "Array is too small to hold the string.\n";
        return;
    }
    
    strcpy(cstr, p);
    cout << "Here is the string copied into cstr:\n" << cstr << "\n\n";
    
    //Next, copy the string into a dynamically allocated array.
    try {
        //Dynamically allocate the array.
        char *p2 = new char[str.size()+1];
        
        //Copy the string into the array.
        strcpy(p2, str.c_str());
        
        cout << "String after being copied into dynamically-allocated array:\n";
        cout << p2 << endl;
        
        delete[] p2;
    } catch (bad_alloc ba) {
        cout << "Allocation Failure\n";
        return;
    }
    
    return;
}

