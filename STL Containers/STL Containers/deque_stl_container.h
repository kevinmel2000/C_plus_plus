//
//  deque_stl_container.h
//  STL Containers
//
//  Created by Sudheendra Ayalasomayajula on 6/24/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef STL_Containers_deque_stl_container_h
#define STL_Containers_deque_stl_container_h



#endif

#include <iostream>
#include <deque>

using namespace std;

void show(const char *msg, deque<int> q);

void call_funcs_deque_stl_container(){
    //Declare a deque that has an initial capacity of 10.
    deque<int> dq(10);
    
    //Assign its elements some values.
    //Notice how this is done using the standard array-subscripting syntax.
    //Notice that the number of elements in the deque is obtained by calling size().
    for (unsigned i = 0; i < dq.size(); ++i) {
        dq[i] = i*i;
    }
    
    show("Contents of dq: ", dq);
    
    //Compute the average of the values.
    //Again, notice the use of the subscripting operator.
    int sum = 0;
    for (unsigned i=0; i < dq.size(); ++i) {
        sum += dq[i];
    }
    
    double avg = sum/dq.size();
    
    cout << "The average of the elements is " << avg << "\n\n";
    
    //Add elements to the end of dq.
    dq.push_back(100);
    dq.push_back(121);
    
    show("dq after pushing elements onto the end: ", dq);
    cout << endl;
    
    //Now use pop_back() to remove one element.
    dq.pop_back();
    show("dq after back-popping one element: ", dq);
    cout << endl;
    
    cout << "The first and last element in dq as pointed to by begin() and end()-1:\n" << *dq.begin() << ", " << *(dq.end()-1) << "\n\n";
    
    cout << "The first and last element in dq as pointed to by rbegin() and rend()-1:\n" << *dq.rbegin() << ", " << *(dq.rend() -1) << "\n\n";
    
    //Declare an iterator to a deque<int>.
    deque<int>::iterator itr;
    
    //Now, declare reverse iterator to a deque<int>
    deque<int>::reverse_iterator ritr;
    
    //Cycle through dq in the forward direction using an iterator.
    cout << "Cycle through the deque in the forward direction:\n";
    for (itr = dq.begin(); itr != dq.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << "\n\n";
    cout << "Now, use a reverse iterator to cycle through in the reverse direction:\n";
    
    //Cycle through dq in the reverse direction using a reverse_iterator.
    for (ritr = dq.rbegin(); ritr != dq.rend(); ++ritr) {
        cout << *ritr << " ";
    }
    cout << "\n\n";
    
    //Create another deque that contains a subrange of dq.
    deque<int> dq2(dq.begin()+2, dq.end()-4);
    
    //Display the contents of dq2 by using an iterator.
    show("dq2 cointains a subrange of dq: ", dq2);
    cout << endl;
    
    //Change the values of some dq2's elements.
    dq2[1] = 100;
    dq2[2] = 88;
    dq2[4] = 99;
    show("After the assignments, dq2 now contains: ", dq2);
    cout << endl;
    
    //Create an empty deque and then assign it a sequence that is the reverse of dq.
    deque<int> dq3;
    dq3.assign(dq.rbegin(), dq.rend());
    show("dq3 contains the reverse of dq: ", dq3);
    cout << endl;
    
    //Push an element onto the front of dq.
    dq.push_front(-31416);
    show("dq after call to push_front(): ", dq);
    cout << endl;
    
    //Now, clear dq by popping elements one at a time.
    cout << "Front popping elements from dq.\n";
    while (dq.size() > 0) {
        cout << "Popping: " << dq.front() << endl;
        dq.pop_front();
    }
    
    if (dq.empty()) {
        cout << "dq is now empty.\n";
    }
}

//Display the contents of a deque<int>.
void show(const char *msg, deque<int> q){
    cout << msg;
    for (unsigned i = 0; i < q.size(); ++i) {
        cout << q[i] << " ";
    }
    cout << "\n";
}