//
// Terrance Hutchinson
// RedID: 822021623
// CS 480
// Professor Ben Shen
// Created by Terrance Hutchinson on 1/19/23.
//

#include "dictionary.h"

void dictTrie::readTree(dictNode *root, char *filepath) {
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

        // Tokenize the line by the delimiters
        char *word = strtok(line_c, delimiters);
        while (word != nullptr) {
            // Find the last node of the given string
            dictNode *prefix = findEndingNodeOfAStr(root, word);
            cout << word << " ";
            // Print the number of words with the given prefix
            cout << countPrefix(prefix) << "\n";
            // Read next word
            word = strtok(nullptr, delimiters);
        }
    }

    // Close the input file
    in_file.close();
}

int dictTrie::countPrefix(dictNode *prefix) {
    // Base case: if the prefix is null, return 0
    if (!prefix) {
        return 0;
    }
    // Initialize a count variable and set it to 1 if the current node is a word
    int count = prefix->isWord ? 1 : 0;
    // Iterate through all the children of the current node
    for (int i = 0; i < prefix->NCHILD; ++i) {
    // Recursively call countWords on each child and add the result to the count
        count += countPrefix(prefix->next[i]);
    }
    // Return the final count
    return count;
}