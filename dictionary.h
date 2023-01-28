//
// Terrance Hutchinson
// RedID: 822021623
// CS 480
// Professor Ben Shen
// Created by Terrance Hutchinson on 1/19/23.
//

#ifndef DICTIONARY_H
#define DICTIONARY_H

// Marcos for ASCII Values
#define ASCII_APOSTROPHE 39
#define ASCII_HYPHEN 45
#define ASCII_UNDERSCORE 95

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

const char delimiters[] = "\n\r !\"#$%&()*+,./0123456789:;<=>?@[\\]^`{|}~"; // delimiters used to separate words in the input files

class dictNode {
public:
    static const int NCHILD = 29; // number of children for each node in the trie
    dictNode(); // constructor
    bool isWord; // flag indicating if the current node is the end of a word
    dictNode *next[NCHILD]; // pointer to the next node in the trie
};

class dictTrie {
public:
    int levelMap[128] = {-1}; // levelMap initialization
    dictTrie(); //constructor
    static dictNode* get_root(){return new dictNode();}
    void vocabulary(dictNode *root, char *filepath); // reads a vocabulary file and adds each word to the trie
    void readTree(dictNode *root, char *filepath); // reads a text file and prints the number of words in the trie with the given prefix
    bool add(dictNode*& root, char* wordBeingInserted); // adds a word to the trie
    dictNode *findEndingNodeOfAStr(dictNode *root, char *strBeingSearched); // returns the node in the trie where the given string ends
    int countPrefix(dictNode *prefix); // returns the number of words in the trie with the given prefix
};

#endif

