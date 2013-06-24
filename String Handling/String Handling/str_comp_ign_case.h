//
//  str_comp_ign_case.h
//  String Handling
//
//  Created by Sudheendra Ayalasomayajula on 6/23/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef String_Handling_str_comp_ign_case_h
#define String_Handling_str_comp_ign_case_h



#endif

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

bool comp_ign_case(char x, char y);
string::iterator search_ign_case(string &str, const string &substr);
bool search_and_replace_ign_case(string &str, const string &oldsubstr, const string &newsubstr);

void call_funcs_str_comp_ign_case(){
    string strA("This is a test of case-insensitive searching.");
    string strB("test");
    string strC("TEST");
    string strD("testing");
    
    cout << "First, demonstrate search_ign_case().\n";
    cout << "String to be searched:\n" << strA << "\n\n";
    
    cout << "Searching for " << strB << ". ";
    if (search_ign_case(strA, strB) != strA.end()) {
        cout << "Found!\n";
    }
    
    cout << "Searching for " << strC << ". ";
    if(search_ign_case(strA, strC) != strA.end()) {
        cout << "Found!\n";
    }
    
    cout << "Searching for " << strD << ". ";
    if (search_ign_case(strA, strD) != strA.end()) {
        cout << "Found!\n";
    }else {
        cout << "Not Found.\n";
    }
    
    //Use the iterator returned by search_ign_case() to display the reminder of the string.
    cout << "\nRemainder of string after finding 'of':\n";
    string::iterator itr = search_ign_case(strA, "of");
    
    while (itr != strA.end()) {
        cout << *itr++;
    }
    
    cout << "\n\n";
    
    //Now, demonstrate search and replace.
    strA = "Alpha Beta Gamma alpha beta gamma";
    cout << "Now demonstrate search_and_replace_ign_case().\n";
    cout << "String that will receive replacements:\n" << strA << "\n\n";
    cout << "Replacing all occurrences of alpha with zeta:\n";

    while (search_and_replace_ign_case(strA, "alpha", "zeta")) {
        cout << strA << endl;
    }
}

//Ignore case when searching for a substring.
//The string to search is passed in str.
//The substring to search for is passed in substr.
//It returns an iterator to the start of the match or str.end() if no match is found.

//Notice that it uses the search() algorithm and specifies the binary predicate comp_ign_case().
string::iterator search_ign_case(string &str, const string &substr){
    return search(str.begin(), str.end(), substr.begin(), substr.end(), comp_ign_case);
}

//Ignore case when comparing two character for equality.
//Return true if the characters are equal, independently of case differences.
bool comp_ign_case(char x, char y){
    return tolower(x) == tolower(y);
}

//This function replaces the first occurrence of oldsubstr with newsubstr in the string passed in str.
//It returns true if a replacement occurs and false otherwise.

//Note that this function modifies the string referred to by str.
//Also note that it uses search_ign_case() to find the substring to replace.
bool search_and_replace_ign_case(string &str, const string &oldsubstr, const string &newsubstr){
    string::iterator startitr;
    
    startitr = search_ign_case(str, oldsubstr);
    
    if (startitr != str.end()) {
        str.replace(startitr, startitr+oldsubstr.size(), newsubstr);
        return true;
    }
    
    return false;
}