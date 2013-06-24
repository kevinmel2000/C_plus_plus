//
//  word_count.h
//  String Handling
//
//  Created by Sudheendra Ayalasomayajula on 6/23/13.
//  Copyright (c) 2013 Sudheendra Ayalasomayajula. All rights reserved.
//

#ifndef String_Handling_word_count_h
#define String_Handling_word_count_h



#endif

#include <iostream>
#include <cctype>

using namespace std;

struct wc {
    int words;
    int spaces;
    int punct;
    int lines;
    
    wc(){
        words = punct = spaces = lines = 0;
    }
};

wc wordcount(const char *str);

void call_funcs_word_count(){
    const char *test = "By supplying a string class and also supporting null-terminated strings,\nC++ offers a rich programming environment for string-intensive tasks.\nIt's power programming.";
    
    cout << "Given: " << "\n\n";
    cout << test << endl;
    wc wcd = wordcount(test);
    
    cout << "\nWords: " << wcd.words << endl;
    cout << "Spaces: " << wcd.spaces << endl;
    cout << "Lines: " << wcd.lines << endl;
    cout << "Punctuation: " << wcd.punct << endl;
}

//A very simple "word count" function.
//It counts the words, lines, spaces, and punctuation in a string and returns the result in a wc structure.
wc wordcount(const char *str){
    wc data;
    
    //If the string is not null, then it contains at least one line.
    if (*str) {
        ++data.lines;
    }
    
    while (*str) {
        
        //Check for a word.
        if (isalpha(*str)) {
            //Start of word found. Now, look for the end of the word.
            //Allow apostrophes in words, as in "it's."
            while (isalpha(*str) || *str == '\'') {
                if (*str == '\'') {
                    ++data.punct;
                }
                ++str;
            }
            data.words++;
        }else {
            //Count punctuation, spaces (including newlines), and lines.
            if (ispunct(*str)) {
                ++data.punct;
            }else if(isspace(*str)){
                ++data.spaces;
                //If there is any character after the newline, increment the line counter.
                if (*str == '\n' && *(str+1)) {
                    ++data.lines;
                }
            }
            ++str;
        }
    }
    
    return data;
}