//
// Created by Flo on 28.04.2024.
//

#ifndef INC_2_ALGOS_U2_TREE_H
#define INC_2_ALGOS_U2_TREE_H
#include "treeNode.h"
#include <iostream>
using namespace std;

class Tree {

    public:
        Tree();
        ~Tree();
        int maxkey;
        int minkey;
        int avg;
        bool avl;
        int sum;
        int count;
        treeNode* root;
        int printBalance(treeNode* root);
        treeNode* insert(treeNode* root, int key);
        treeNode* search(treeNode* root, int key, int mode);

        void printStats();
};


#endif //INC_2_ALGOS_U2_TREE_H
