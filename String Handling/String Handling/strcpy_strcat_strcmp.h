//
//  strcpy_strcat_strcmp.h
//  String Handling
//
//  Created by Sudheendra Ayalasomayajula on 6/23/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef String_Handling_strcpy_strcat_strcmp_h
#define String_Handling_strcpy_strcat_strcmp_h



#endif

#include <iostream>
#include <cstring>

using namespace std;

void strcpy_strcat_strcmp(){
    char strA[7] = "Up";
    char strB[5] = "Down";
    char strC[5] = "Left";
    char strD[6] = "Right";
    
    cout << "Here are the strings: " << endl;
    cout << "strA: " << strA << endl;
    cout << "strB: " << strB << endl;
    cout << "strC: " << strC << endl;
    cout << "strD: " << strD << "\n\n";
    
    //Display the length of strA
    cout << "Length of strA is " << strlen(strA) << endl;
    
    //Concatenate strB with strA
    strcat(strA, strB);
    cout << "strA after concatenation: " << strA << endl;
    cout << "Length of strA is now " << strlen(strA) << endl;
    
    //Copy strC into strB
    strcpy(strB, strC);
    cout << "strB now holds: " << strB << endl;
    
    //Compare strings
    if(!strcmp(strB, strC))
        cout << "strB is equal to strC\n";
    
    int result = strcmp(strC, strD);
    
    if (!result) {
        cout << "strC is equal to strD\n";
    }else if (result < 0){
        cout << "strC is less than strD\n";
    }else if (result > 0){
        cout << "strC is greater than strD\n";
    }
}