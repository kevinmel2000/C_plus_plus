//
//  vector_stl_container.h
//  STL Containers
//
//  Created by Sudheendra Ayalasomayajula on 6/24/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef STL_Containers_vector_stl_container_h
#define STL_Containers_vector_stl_container_h



#endif

#include <iostream>
#include <vector>

using namespace std;

void show(const char *msg, vector<int> vect);

void call_funcs_vector_stl_container(){
    //Declare a vector that has an initial capacity of 10.
    vector<int> v(10);
    
    //Assign its elements some values.
    //Notice how this is done using the standard array-subscription syntax.
    //Notice that the number of elements in the vector is obtained by calling size().
    for (unsigned i=0; i < v.size(); ++i) {
        v[i] = i*i;
    }
    
    show("Contents of v:", v);
    
    //Compute the average of the values.
    //Again, notice the use of the subscripting operator.
    int sum = 0;
    for (unsigned i=0; i < v.size(); ++i) {
        sum += v[i];
    }
    
    double avg = sum/v.size();
    
    cout << "The average of the elements is " << avg << "\n\n";
    
    //Add elements to the end of v.
    v.push_back(100);
    v.push_back(121);
    
    show("v after pushing elements onto the end: ", v);
    cout << endl;
    
    //Now use pop_back() to remove one element.
    v.pop_back();
    show("v after back-popping one element: ", v);
    cout << endl;
    
    cout << "The first and last element in v as pointed to by begin() and end()-1:\n"
        << *v.begin() << ", " << *(v.end() - 1) << "\n\n";
    
    cout << "The first and last element in v as pointed to by rbegin() and rend()-1:\n"
        << *v.rbegin() << ", " << *(v.rend()-1) << "\n\n";
    
    //Declare an iterator to a vector<int>.
    vector<int>::iterator itr;
    
    //Now, declare reverse iterator to a vector<int>
    vector<int>::reverse_iterator ritr;
    
    //Cycle through v in the forward direction using an iterator.
    cout << "Cycle through the vector in the forward direction:\n";
    for (itr = v.begin(); itr != v.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << "\n\n";
    cout << "Now, use a reverse iterator to cycle through in the reverse direction:\n";
    
    //Cycle through v in the reverse direction using a reverse_iterator.
    for (ritr = v.rbegin(); ritr != v.rend(); ++ritr) {
        cout << *ritr << " ";
    }
    cout << "\n\n";
    
    //Create another vector that contains a subrange of v.
    vector<int> v2(v.begin()+2, v.end()-4);
    
    //Display the contents of v2 by using an iterator.
    show("v2 contains a subrange of v: ", v2);
    cout << endl;
    
    //Change the values of some of v2's elements.
    v2[1] = 100;
    v2[2] = 88;
    v2[4] = 99;
    show("After the assignments, v2 now contains: ", v2);
    cout << endl;
    
    //Create an empty vector and then assgin it a sequence that is the reverse of v.
    vector<int> v3;
    v3.assign(v.rbegin(), v.rend());
    show("v3 contains the reverse of v: ", v3);
    cout << endl;
    
    //Show the size and capacity of v.
    cout << "Size of v is " << v.size() << ". The capacity is " << v.capacity() << ".\n";
    
    //Now, resize v.
    v.resize(20);
    cout << "After calling resize(20), the size of v is " << v.size() << " and the capacity is " << v.capacity() << ".\n";
    
    //Now, reserve space for 50 elements.
    v.reserve(50);
    cout << "After calling reserve(50), the size of v is " << v.size() << " and the capacity is " << v.capacity() << ".\n";
}

//Display the contents of a vector<int>.
void show(const char *msg, vector<int> vect){
    cout << msg;
    for (unsigned i = 0; i < vect.size(); ++i) {
        cout << vect[i] << " ";
    }
    cout << "\n";
}