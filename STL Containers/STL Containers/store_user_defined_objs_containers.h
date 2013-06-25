//
//  store_user_defined_objs_containers.h
//  STL Containers
//
//  Created by Sudheendra Ayalasomayajula on 6/24/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef STL_Containers_store_user_defined_objs_containers_h
#define STL_Containers_store_user_defined_objs_containers_h



#endif

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//This class store information on parts.
class part {
    string name;
    unsigned number;
    
public:
    //Default constructor.
    part() { name = ""; number = 0; }
    
    //Construct a complete part object.
    part(string n, unsigned num){
        name = n;
        number = num;
    }
    
    //Accessor functions for part data.
    string get_name() {
        return name;
    }

    unsigned get_number() {
        return number;
    }
};

void show(const char *msg, vector<part> vect);

//Compare objects using part number.
bool operator< (part a, part b) {
    return a.get_number() < b.get_number();
}

//Check for equality based on part number.
bool operator== (part a, part b){
    return a.get_number() == b.get_number();
}

void call_funcs_store_user_defined_objs_containers(){
    vector<part> partlist;
    
    //Initialize the parts list.
    partlist.push_back(part("flange", 9324));
    partlist.push_back(part("screw", 8452));
    partlist.push_back(part("bolt", 6912));
    partlist.push_back(part("nail", 1274));
    
    //Display contents of the vector.
    show("Parts list unsorted:\n", partlist);
    cout << endl;
    
    //Use the sort() algorithm to sort the parts list.
    //This requires that operator< () be defined for part.
    sort(partlist.begin(), partlist.end());
    
    show("Parts list sorted by part number:\n", partlist);
    
    //Use the find() algorithm to find a part given its number.
    //This requires that opearator== () be defined for part.
    cout << "Searching for part number 6912.\n";
    
    vector<part>::iterator itr;
    itr = find(partlist.begin(), partlist.end(), part("", 6912));
    cout << "Part found. Its name is " << itr->get_name() << ".\n";
}

//Display the contents of a vector<part>
void show(const char *msg, vector<part> vect){
    vector<part>::iterator itr;
    
    cout << msg;
    cout << " Part#\t Name\n";
    for (itr = vect.begin(); itr != vect.end(); ++itr){
        cout << " " << itr->get_number() << "\t " << itr->get_name() << endl;
        cout << "\n";
    }
}