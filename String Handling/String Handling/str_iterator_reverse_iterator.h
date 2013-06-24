//
//  str_iterator_reverse_iterator.h
//  String Handling
//
//  Created by Sudheendra Ayalasomayajula on 6/23/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef String_Handling_str_iterator_reverse_iterator_h
#define String_Handling_str_iterator_reverse_iterator_h



#endif

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

void call_funcs_str_iterator_reverse_iterator(){
    string strA("This is a test.");
    
    //Create an iterator to a string.
    string::iterator itr;
    
    //Use an iterator to cycle through the characters of a string.
    cout << "Display a string via an iterator.\n";
    
    for (itr = strA.begin(); itr != strA.end(); ++itr) {
        cout << *itr;
    }
    
    cout << "\n\n";
    
    //Use a reverse iterator to display the string in reverse.
    cout << "Display a string in reverse using a reverse iterator.\n";
    string::reverse_iterator ritr;
    
    for (ritr = strA.rbegin(); ritr != strA.rend(); ++ritr) {
        cout << *ritr;
    }
    
    cout << "\n\n";
    
    //Insert into a string via an iterator.
    
    //First, use the STL find() algorithm to obtain an iterator to the start of the first 'a'.
    itr = find(strA.begin(), strA.end(), 'a');
    
    //Next, increment the iterator so that it points to the character after 'a', which in this case is a space.
    ++itr;
    
    //Insert into str by using the iterator version of insert().
    cout << "Insert into a string via an iterator.\n";
    string strB(" bigger");
    strA.insert(itr, strB.begin(), strB.end());
    cout << strA << "\n\n";
    
    //Now, replace 'bigger' with 'larger'.
    cout << "Replace bigger with larger.\n";
    itr = find(strA.begin(), strA.end(), 'b');
    strA.replace(itr, itr+6, "larger");
    cout << strA << "\n\n";
    
    //Now, remove ' larger'.
    cout << "Remove ' larger'.\n";
    itr = find(strA.begin(), strA.end(), 'l');
    strA.erase(itr, itr+7);
    cout << strA << "\n\n";
    
    //Use an iterator with the STL transform() algorithm to convert a string to uppercase.
    cout << "use the STL transform() algorithm to convert a string into uppercase.\n";
    std::transform(strA.begin(), strA.end(), strA.begin(), ::toupper);
    cout << strA << "\n\n";
    
    //Create a string from a vector<char>.
    vector<char> vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back('A'+i);
    }
    
    string strC(vec.begin(), vec.end());
    cout << "Here is strC, which is constructed from a vector:\n";
    cout << strC << endl;
}