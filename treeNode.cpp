//
// Created by Florian Korcian on 26.04.24.
//

#include "treeNode.h"

treeNode::treeNode(int key) {
    this->key = key;
    left = nullptr;
    right = nullptr;
    balance = 0;
    height = 0;
}

treeNode::~treeNode() {

    delete left;
    delete right;

}
