//
//  use_strtok.h
//  String Handling
//
//  Created by Sudheendra Ayalasomayajula on 6/23/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef String_Handling_use_strtok_h
#define String_Handling_use_strtok_h



#endif

//Demonstrate strtok()
#include <iostream>
#include <cstring>

using namespace std;

void call_funcs_strtok(){
    //First, use strtok() to tokenize a sentence.
    
    //Create a string of delimiters for simple sentences.
    char delims[] = "., ?;!";

    char str[] = "I like apples, pears, and grapes. Do you?";
    
    char *tok;
    
    cout << "Obtain the words in a sentence.\n";
    
    //Pass the string to be tokenized and get the first token.
    tok = strtok(str, delims);
    
    //Get all remaining tokens.
    while (tok) {
        cout << tok << endl;
        
        //Each subsequent call to strtok() is passed NULL for the first argument.
        tok = strtok(NULL, delims);
    }
    
    //Now, use strtok() to extract keys and values stored in key/value pairs within a string.
    char kvpairs[] = "count = 10, name=\"Tom Jones, jr.\", max = 100, min=0.01";
    
    //Create a list of delimiters for key/value pairs.
    char kvdelims[] = " =, ";

    cout << "\nTokenize key/value pairs.\n";
    
    //Get the first key.
    tok = strtok(kvpairs, kvdelims);
    
    //Get all remaining tokens.
    while (tok) {
        cout << "Key: " << tok << " ";
        
        //Get a value.
        
        //First, if the key is name, the value will be a quoted string.
        if (!strcmp("name", tok)) {
            //Notice that this call uses only quotes as a delimiter.
            //This lets it read a quoted string that contains any character.
            tok = strtok(NULL, "\"");
        }else {
            //Otherwise, read a simple value.
            tok = strtok(NULL, kvdelims);
        }
        
        cout << "Value: " << tok << endl;
        
        //Get the next key.
        tok = strtok(NULL, kvdelims);
    }
}