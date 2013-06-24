//
//  use_gettoken.h
//  String Handling
//
//  Created by Sudheendra Ayalasomayajula on 6/23/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef String_Handling_use_gettoken_h
#define String_Handling_use_gettoken_h



#endif

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

const char *gettoken(const char *str);

void call_funcs_gettoken(){
    char sampleA[] = "max=12+3/89; count27 = 19*(min+floor);";
    char sampleB[] = "while(i < max) i = counter * 2;";
    const char *tok;
    
    //Tokenize the first string.
    tok = gettoken(sampleA);
    cout << "Here are the tokens in: " << sampleA << endl;
    
    while (tok) {
        cout << tok << endl;
        tok = gettoken(NULL);
    }
    
    cout << "\n\n";
    
    //Restart gettoken() by passing the second string.
    tok = gettoken(sampleB);
    cout << "Here are the tokens in: " << sampleB << endl;
    while (tok) {
        cout << tok << endl;
        
        tok = gettoken(NULL);
    }
}

//A very simple custom gettoken() function.
//The tokens are comprised of alphanumeric strings, numbers, and single-character punctuation.
//Although this function is quite limited, it demonstrates the basic framework that can be expanded and enhanced to obtain other types of tokens.

//On the first call, pass a pointer to the string to be tokenized.
//On subsequent calls, pass a null pointer.
//It returns a pointer to the current token, or a null pointer if there are no more tokens.
#define MAX_TOK_SIZE 128

const char *gettoken(const char *str) {
    static char token[MAX_TOK_SIZE+1];
    static const char *ptr;
    int count; //holds the current character count
    char *tokptr;
    
    if (str) {
        ptr = str;
    }
    
    tokptr = token;
    count = 0;
    
    while (isspace(*ptr)) {
        ptr++;
    }
    
    if (isalpha(*ptr)) {
        while (isalpha(*ptr) || isdigit(*ptr)) {
            *tokptr++ = *ptr++;
            ++count;
            if (count == MAX_TOK_SIZE) {
                break;
            }
        }
    }else if(isdigit(*ptr)) {
        while (isdigit(*ptr)) {
            *tokptr++ = *ptr++;
            ++count;
            if (count == MAX_TOK_SIZE) {
                break;
            }
        }
    }else if(ispunct(*ptr)){
        *tokptr++ = *ptr++;
    }else {
        return NULL;
    }
    
    //Null-terminate the token.
    *tokptr = '\0';
    
    return token;
}