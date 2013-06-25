//
//  using_map_stl.h
//  STL Containers
//
//  Created by Sudheendra Ayalasomayajula on 6/24/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef STL_Containers_using_map_stl_h
#define STL_Containers_using_map_stl_h



#endif

//Demostrate the use of map.

#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;

void show(const char *msg, map<string, string> mp);

void call_funcs_using_map_stl(){
    map<string, string> phonemap;
    
    //Insert elements by using operator[].
    phonemap["Tom"] = "555-1234";
    phonemap["Jane"] = "314 555-6576";
    phonemap["Ken"] = "660 55-9843";
    
    show("Here is the original map: ", phonemap);
    cout << endl;
    
    //Now, change the phone number for Ken.
    phonemap["Ken"] = "415 997-8893";
    cout << "New number for Ken: " << phonemap["Ken"] << "\n\n";
    
    //Use find() to find a number.
    map<string, string>::iterator itr;
    itr = phonemap.find("Jane");
    if (itr != phonemap.end()) {
        cout << "Number for Jane is " << itr->second << "\n\n";
    }
    
    //Cycle through the map in the reverse direction.
    map<string, string>::reverse_iterator ritr;
    cout << "Display phonemap in reverse order:\n";
    for (ritr = phonemap.rbegin(); ritr != phonemap.rend(); ++ritr) {
        cout << " " << ritr->first << ": " << ritr->second << endl;
    }
    cout << endl;
    
    //Create a pair object that will contain the result of a call to insert().
    pair<map<string, string>::iterator, bool> result;
    
    //Use insert() to add an entry.
    result = phonemap.insert(pair<string, string>("Jay", "555-9999"));
    if (result.second) {
        cout << "Jay added.\n";
    }
    
    show("phonemap after adding Jay: ", phonemap);
    
    //Duplicate keys are not allowed, as the following proves.
    result = phonemap.insert(pair<string, string>("Jay", "555-1010"));
    if (result.second) {
        cout << "Duplicate Jay added! Error!";
    }else {
        cout << "Duplicate Jay not allowed.\n";
    }
    
    show("phonemap after attempt to add duplicate Jay key: ", phonemap);
}

//Display the contents of a map<string, string> by using an iterator.
void show(const char *msg, map<string, string> mp){
    map<string, string>::iterator itr;
    
    cout << msg << endl;
    
    for (itr=mp.begin(); itr != mp.end(); ++itr) {
        cout << " " << itr->first << ": " << itr->second << endl;
    }
    cout << endl;
}