//
// Terrance Hutchinson
// RedID: 822021623
// CS 480
// Professor Ben Shen
// Created by Terrance Hutchinson on 1/19/23.
//

#include "dictionary.h"

// dictNode constructor implementation
dictNode::dictNode() {
    isWord = false;
    for (int i = 0; i < NCHILD; i++) {
        next[i] = NULL;
    }
}

// dictTrie constructor implementation
dictTrie::dictTrie() {
    // initialize the levelMap
    for (int i = 0; i < 26; i++) {
        levelMap['a' + i] = i;
    }
    levelMap[ASCII_APOSTROPHE] = 26;
    levelMap[ASCII_HYPHEN] = 27;
    levelMap[ASCII_UNDERSCORE] = 28;
}

void dictTrie::vocabulary(dictNode *root, char *filepath) {
    // Open the input file
    ifstream in_file(filepath);
    string line;

    // Check if the file was successfully opened
    if (!in_file) {
        std::cerr << "Error opening file " << filepath << std::endl;
        return;
    }
    // Read each line of the file
    while (getline(in_file, line)) {
        char *line_c;
        line_c = &line[0];

        // Tokenize the line by the delimiters and add each word to the trie
        char *word = strtok(line_c, delimiters);
        while (word != nullptr) {
            add(root, word);

            word = strtok(NULL, delimiters);
        }
    }

    // Close the input file
    in_file.close();
}

bool dictTrie::add(dictNode*& root, char* wordBeingInserted) {
// create a new node if the root is null
    if (root == nullptr) {
        root = new dictNode;
    }
// if the end of the word is reached, mark the node as a word and return true
    if (wordBeingInserted[0] == '\0') {
        root->isWord = true;
        return true;
    }
// convert the current letter to lowercase
    char currentLetter = tolower(wordBeingInserted[0]);
    int level = levelMap[currentLetter];
// check if the current letter is not a valid character
    if (level == -1) {
// if the character is not a valid character, print an error message and return false
        cout << "Invalid Symbol: " << currentLetter;
        return false;
    }
// create a new node if it doesn't exist
    if (!root->next[level]) {
        root->next[level] = new dictNode;
    }
// recursively add the next letter of the word to the trie
    return add(root->next[level], wordBeingInserted + 1);
}

dictNode *dictTrie::findEndingNodeOfAStr(dictNode *root, char *strBeingSearched) {
    // Initialize the current node to the root of the trie
    dictNode *currentNode = root;
    // Initialize the current letter and level variables
    char currentLetter;
    int level;
    // Iterate through the trie while the current node is not null and the current letter is not the end of the word
    while (currentNode != nullptr && *strBeingSearched != '\0') {
        // Assign the current letter to the current character in the word being searched
        currentLetter = *strBeingSearched;
        // Convert the letter to lowercase if it is not already lowercase
        if (!islower(currentLetter)) currentLetter = tolower(currentLetter);
        // Look up the level of the current letter in the levelMap array
        level = levelMap[currentLetter];
        // If the level is negative, the character is not valid, so return null
        if (level < 0) {
            return nullptr;
        }
        // Set the current node to the next node in the trie at the current level
        currentNode = currentNode->next[level];
        // Move to the next character in the word being searched
        ++strBeingSearched;
    }
    return currentNode;
}
