//
//  strchr_strpbrk_strstr.h
//  String Handling
//
//  Created by Sudheendra Ayalasomayajula on 6/23/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef String_Handling_strchr_strpbrk_strstr_h
#define String_Handling_strchr_strpbrk_strstr_h



#endif

#include <iostream>
#include <cstring>

using namespace std;

void strchr_strpbrk_strstr(){
    const char *url = "HerbSchildt.com";
    const char *url2 = "Apache.org";
    
    const char *emailaddr = "Herb@HerbSchildt.com";
    
    const char *tld[] = { ".com", ".net", ".org" };
    
    const char *p;
    
    //First, determine if url and url2 contain .com, .net, or .org.
    for (int i = 0; i < 3; i++) {
        p = strstr(url, tld[i]);
        if (p) {
            cout << url << " has top-level domain " << tld[i] << endl;
        }
        
        p = strstr(url2, tld[i]);
        if (p) {
            cout << url2 << " has top-level domain " << tld[i] << endl;
        }
    }
    
    //Search for a specific character.
    p = strchr(emailaddr, '@');
    if (p) {
        cout << "Site name of e-mail address is: " << p+1 << endl;
    }
    
    //Search for any of a set of characters. In this case, find the first @ or period.
    p = strpbrk(emailaddr, "@.");
    
    if (p) {
        cout << "Found " << *p << endl;
    }
}