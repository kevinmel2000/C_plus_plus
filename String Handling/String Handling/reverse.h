//
//  reverse.h
//  String Handling
//
//  Created by Sudheendra Ayalasomayajula on 6/23/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef String_Handling_reverse_h
#define String_Handling_reverse_h



#endif


//Reverse a string in place.

#include <iostream>
#include <cstring>

using namespace std;

void revstr(char *str);

void call_revstr(){
    char str[] = "abcdefghijklmnopqrstuvwxyz";
    
    cout << "Original string: " << str << endl;
    
    revstr(str);
    
    cout << "Reversed string: " << str << endl;
}

void revstr(char *str){
    int i, j;
    char t;
    
    for (i = 0, j = strlen(str)-1; i < j; ++i, --j) {
        //Exchange corresponding characters, front to back.
        t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
}

