//
// Created by Florian Korcian on 26.04.24.
//

#ifndef AVL_BAUM_TREENODE_H
#define AVL_BAUM_TREENODE_H


class treeNode {

public:
    treeNode(int key);

    ~treeNode();
    int key;
    treeNode* left;
    treeNode* right;

};


#endif //AVL_BAUM_TREENODE_H
