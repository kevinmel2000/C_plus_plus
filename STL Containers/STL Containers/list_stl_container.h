//
//  list_stl_container.h
//  STL Containers
//
//  Created by Sudheendra Ayalasomayajula on 6/24/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef STL_Containers_list_stl_container_h
#define STL_Containers_list_stl_container_h



#endif

#include <iostream>
#include <list>

using namespace std;

void show(const char *msg, list<char> lst);

void call_funcs_list_stl_container(){
    //Declare two lists.
    list<char> lstA;
    list<char> lstB;
    
    //Use push_back() to give the lists some elements.
    lstA.push_back('A');
    lstA.push_back('F');
    lstA.push_back('B');
    lstA.push_back('R');
    
    lstB.push_back('X');
    lstB.push_back('A');
    lstB.push_back('F');
    
    show("Original contents of lstA: ", lstA);
    show("Original contents of lstB: ", lstB);
    cout << "Size of lstA is " << lstA.size() << endl;
    cout << "Size of lstB is " << lstB.size() << endl;
    cout << endl;
    
    //Sort lstA and lstB
    lstA.sort();
    lstB.sort();
    
    show("Sorted contents of lstA: ", lstA);
    show("Sorted contents of lstB: ", lstB);
    cout << endl;
    
    //Merge lstB into lstA
    lstA.merge(lstB);
    show("lstA after merge: ", lstA);
    if (lstB.empty()) {
        cout << "lstB is now empty().\n";
    }
    cout << endl;
    
    //Remove duplicates from lstA
    lstA.unique();
    show("lstA after call to unique(): ", lstA);
    cout << endl;
    
    //Give lstB some new elements.
    lstB.push_back('G');
    lstB.push_back('H');
    lstB.push_back('P');
    
    show("New contents of lstB: ", lstB);
    cout << endl;
    
    //Now, splice lstB into lstA
    list<char>::iterator itr = lstA.begin();
    ++itr;
    lstA.splice(itr, lstB);
    show("lstA after splice: ", lstA);
    cout << endl;
    
    //Remove A and H.
    lstA.remove('A');
    lstA.remove('H');
    show("lstA after removing A and H: ", lstA);
    cout << endl;
}

//Display the contents of a list<char>
void show(const char *msg, list<char> lst){
    list<char>::iterator itr;

    cout << msg;
    
    for (itr = lst.begin(); itr != lst.end(); ++itr) {
        cout << *itr << " ";
    }
    
    cout << "\n";
}