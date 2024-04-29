//
// Created by Florian Korcian on 26.04.24.
//

#include "treeNode.h"

treeNode::treeNode(int key) {
    this->key = key;
    left = nullptr;
    right = nullptr;
}

treeNode::~treeNode() {

    delete left;
    delete right;

}
