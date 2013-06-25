//
//  using_set_and_multiset.h
//  STL Containers
//
//  Created by Sudheendra Ayalasomayajula on 6/24/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef STL_Containers_using_set_and_multiset_h
#define STL_Containers_using_set_and_multiset_h



#endif

//Demonstrate set.

#include <iostream>
#include <set>
#include <string>

using namespace std;

//This class stores employee information.
class employee {
    string name;
    string ID;
    string phone;
    string department;
    
public:
    //Default constructor.
    employee(){
        ID = name = phone = department = "";
    }
    
    //Construct temporary object using only the ID, which is the key.
    employee(string id1) {
        ID = id1;
    }
    
    //Construct a complete employee object.
    employee(string n, string id1, string dept, string p){
        name = n;
        ID = id1;
        phone = p;
        department = dept;
    }
    
    //Accessor functions for employee data.
    string get_name() { return name; }
    string get_id() {return ID; }
    string get_dept() { return department; }
    string get_phone() { return phone; }
};

//Compare objects using ID.
bool operator< (employee a, employee b){
    return a.get_id() < b.get_id();
}

//Check for equality based on ID.
bool operator== (employee a, employee b){
    return a.get_id() == b.get_id();
}

//Create an inserter for employee.
ostream &operator<< (ostream &s, employee &o){
    s << o.get_name() << endl;
    s << "Emp#: " << o.get_id() << endl;
    s << "Dept: " << o.get_dept() << endl;
    s << "Phone: " << o.get_phone() << endl;
    
    return s;
}

void call_funcs_using_set_and_multiset(){
    set<employee> emplist;
    
    //Initialize the employee list.
    emplist.insert(employee("Tom Harvy", "9423", "Client Relations", "555-1010"));
    emplist.insert(employee("Susan Thomasy", "8723", "Sales", "555-8899"));
    emplist.insert(employee("Alex Johnson", "5719", "Repair", "555-0174"));
    
    //Create an iterator to the set.
    set<employee>::iterator itr = emplist.begin();
    
    //Display contents of the set.
    cout << "Current set: \n\n";
    
    do{
        cout << &*itr << endl;
        ++itr;
    }while (itr != emplist.end());
    cout << endl;
    
    //Find a specific employee.
    cout << "Searching for employee 8723.\n";
    itr = emplist.find(employee("8723"));
    if (itr != emplist.end()){
        cout << "Found. Information follows:\n";
        cout << &*itr << endl;
    }
}