//
//  strcmp_ign_case.h
//  String Handling
//
//  Created by Sudheendra Ayalasomayajula on 6/23/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef String_Handling_strcmp_ign_case_h
#define String_Handling_strcmp_ign_case_h



#endif

#include <iostream>
#include <cctype>

using namespace std;

int strcmp_ign_case(const char *str1, const char *str2);
void showresult(const char *str1, const char *str2, int result);

void call_funcs_strcmp_ign(){
    char strA[] = "tesT";
    char strB[] = "Test";
    char strC[] = "testing";
    char strD[] = "Tea";
    
    int result;
    
    cout << "Here are the strings: " << endl;
    cout << "strA: " << strA << endl;
    cout << "strB: " << strB << endl;
    cout << "strC: " << strC << endl;
    cout << "strD: " << strD << "\n\n";
    
    //Compare strings ignoring case
    result = strcmp_ign_case(strA, strB);
    showresult(strA, strB, result);
    
    result = strcmp_ign_case(strA, strC);
    showresult(strA, strC, result);
    
    result = strcmp_ign_case(strA, strD);
    showresult(strA, strD, result);
    
    result = strcmp_ign_case(strD, strA);
    showresult(strD, strA, result);
}

//A simple string comparison function that ignores case differences.
int strcmp_ign_case(const char *str1, const char *str2){
    while (*str1 && *str2) {
        if (tolower(*str1) != tolower(*str2)) {
            break;
        }
        
        ++str1;
        ++str2;
    }
    
    return tolower(*str1) - tolower(*str2);
}

void showresult(const char *str1, const char *str2, int result){
    cout << str1 << " is ";
    
    if (!result) {
        cout << "equal to ";
    }else if(result < 0){
        cout << "less than ";
    }else{
        cout << "greater than ";
    }
    
    cout << str2 << endl;
}