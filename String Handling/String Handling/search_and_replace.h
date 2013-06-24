//
//  search_and_replace.h
//  String Handling
//
//  Created by Sudheendra Ayalasomayajula on 6/23/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef String_Handling_search_and_replace_h
#define String_Handling_search_and_replace_h



#endif

#include <iostream>
#include <cstring>

using namespace std;

bool search_and_replace(char *orgstr, int maxlen, const char *oldsubstr, const char *newsubstr);

void call_funcs_search_and_replace(){
    char str[80] = "alpha beta gamma alpha beta gamma";
    
    cout << "Original string: " << str << "\n\n";
    
    cout << "First, replace all instances of alpha with epsilon.\n";
    
    //Replace all occurrences of alpha with epsilon.
    while (search_and_replace(str, 79, "alpha", "epsilon")) {
        cout << "After a replacement: " << str << endl;
    }
    
    cout << "\nNext, replace all instances of gamma with zeta.\n";
    
    //Replace all occurrences of gamma with zeta.
    while (search_and_replace(str, 79, "gamma", "zeta")) {
        cout << "After a replacement: " << str << endl;
    }
    
    cout << "\nFinally, remove all occurrences of beta.\n";
    
    //Replace all occurrences of beta with a null string.
    //This has the effect of removing beta from the string.
    while (search_and_replace(str, 79, "beta", "")) {
        cout << "After a replacement: " << str << endl;
    }

}

//Replace the first occurrence of oldsubstr with newsubstr in the string pointed to by str.
//This means that the string pointed to by str is modified by this function.
//The maximum size of the resulting string is passed in maxlen.
//This value must be less than the size of the array that holds str in order to prevent an array overrun.
//It returns true if a replacement was made and false otherwise.
bool search_and_replace(char *str, int maxlen, const char *oldsubstr, const char *newsubstr){
    //Don't allow the null terminator to be substituted
    if (!*oldsubstr) {
        return false;
    }
    
    //Next, check that the resulting string has a length less than or equal to the maximum number of characters allowed as specified by maxlen.
    //If the maximum is exceeded, the function ends by returning false.
    int len = strlen(str) - strlen(oldsubstr) + strlen(newsubstr);
    
    if (len > maxlen) {
        return false;
    }
    
    //See if the specified substring is in the string.
    char *p = strstr(str, oldsubstr);
    
    //If the substring is found, replace it with the new one.
    if (p) {
        //First, use memmove() to move the remainder of the string so that the new substring can replace the old one.
        //In other words, this step either increases or decreases the size of the "hole" that the new substring will fill.
        memmove(p+strlen(newsubstr), p+strlen(oldsubstr), strlen(p)-strlen(oldsubstr)+1);
        
        //Now, copy substring into str.
        strncpy(p, newsubstr, strlen(newsubstr));
        
        return true;
    }
    
    //Return false if no replacement was made.
    return false;
}