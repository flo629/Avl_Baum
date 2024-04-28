//
// Created by Flo on 28.04.2024.
//

#include "Tree.h"

Tree::Tree() {
    this->root = nullptr;
    sum = 0;
    count = 0;
}

Tree::~Tree() {
    delete root;
}

int Tree::printBalance(treeNode *root) {
    //cout << root << endl;
    if(root == nullptr) {
        return -1;
    }else{
        int rightHeight = printBalance(root->right);
        int leftHeight = printBalance(root->left);

        int balance = rightHeight - leftHeight;

        //cout << "( " << leftHeight << "," << rightHeight << ") Node: " << root->key << " - H " << root->height << endl;
        cout << "bal(" << root->key <<") = " << balance;

        if(balance > 1 || balance < -1) {
            avl = false;
            cout << " (AVL violation!)";
        }

        cout << endl;

        // Stats
        if(maxkey < root->key){
            maxkey = root->key;
        }
        if(minkey > root->key){
            minkey = root->key;
        }
        sum += root->key;
        count++;


        return max(rightHeight, leftHeight) + 1;
    }
}

treeNode *Tree::insert(treeNode *root, int key) {
    if (!root) {
        // Insert the first node, if root is NULL.
        maxkey = key;
        minkey = key;
        sum += key;
        count++;
        return new treeNode(key);
    }

    // Insert data.
    if (key > root->key) {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process right nodes.
        root->right = insert(root->right, key);
    }
    else if (key < root->key) {
        // Insert left node data, if the 'value'
        // to be inserted is smaller than 'root' node data.

        // Process left nodes.
        root->left = insert(root->left, key);
    }
    // Return 'root' node, after insertion.
    return root;
}

treeNode* Tree::search(treeNode *root, int key, int mode) {
    // Base Cases: root is null or key is present at root

    if (root == nullptr || root->key == key)
    {
        if(mode == 1)
        {
            cout << root->key;
        }

        return root;
    }

    // Key is greater than root's key
    if (root->key < key)
    {
        if(mode == 1)
        {
            cout << root->key << ", ";
        }
        return search(root->right, key, mode);
    }

    // Key is smaller than root's key
    if(mode == 1)
    {
        cout << root->key << ", ";
    }
    return search(root->left, key, mode);
}

void Tree::printStats() {

    cout << "AVL: " << (avl?"yes":"no")<<endl;
    cout << "min: " << minkey << ", max: " << maxkey << ", avg: " << (double(sum)/double(count)) << endl;

}
