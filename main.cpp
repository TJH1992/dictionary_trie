//
// Terrance Hutchinson
// RedID: 822021623
// CS 480
// Professor Ben Shen
// Created by Terrance Hutchinson on 1/19/23.
//

#include "dictionary.h"

int main(int argc, char **argv) {

    dictTrie *dic = new dictTrie();
    dictNode *root = dictTrie::get_root();
    dic->vocabulary(root, argv[1]);
    dic->readTree(root, argv[2]);

    return 0;
}
