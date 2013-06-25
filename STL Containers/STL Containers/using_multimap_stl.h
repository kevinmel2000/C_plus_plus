//
//  using_multimap_stl.h
//  STL Containers
//
//  Created by Sudheendra Ayalasomayajula on 6/24/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef STL_Containers_using_multimap_stl_h
#define STL_Containers_using_multimap_stl_h



#endif

#include <iostream>
#include <map>
#include <string>

using namespace std;

void shownumbers(const char *n, multimap<string, string> mp);

void call_funcs_using_multimap_stl(){
    multimap<string, string> phonemap;
    
    //Insert elements by using operator[].
    phonemap.insert(pair<string, string>("Tom", "Home: 555-1111"));
    phonemap.insert(pair<string, string>("Tom", "Work: 555-1234"));
    phonemap.insert(pair<string, string>("Tom", "Cell: 555-2224"));
    
    phonemap.insert(pair<string, string>("Jane", "Home: 314 555-6576"));
    phonemap.insert(pair<string, string>("Jane", "Cell: 314 555-8822"));
    
    phonemap.insert(pair<string, string>("Ken", "Home: 660 555-9843"));
    phonemap.insert(pair<string, string>("Ken", "Work: 660 555-1010"));
    phonemap.insert(pair<string, string>("Ken", "Cell: 217 555-9995"));
    
    //Show all phone numbers for Tom, Jane, and Ken
    shownumbers("Tom", phonemap);
    cout << endl;
    shownumbers("Jane", phonemap);
    cout << endl;
    shownumbers("Ken", phonemap);
    cout << endl;
    
    //Now remove all phone numbers for Ken:
    cout << "Removing all numbers for Ken.\n";
    int count  = phonemap.erase("Ken");
    cout << count << " elements have been removed.\n\n";
    
    cout << "After removing Ken, attempt to find phone number fails:\n";
    shownumbers("Ken", phonemap);
}

//Show all numbers for a given name.
void shownumbers(const char *n, multimap<string, string> mmp){
    multimap<string, string>::iterator itr;
    
    //Find the first matching key.
    itr = mmp.find(n);
    
    //If the key was found, then display all phone numbers that have that key.
    if (itr != mmp.end()) {
        cout << "Here are the numbers for " << n << ": " << endl;
        do {
            cout << " " << itr->second << endl;
            ++itr;
        }while (itr != mmp.upper_bound(n));
    }else {
        cout << "No entry for " << n << " found.\n";
    }
}