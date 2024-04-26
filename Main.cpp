#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "treenode.h"
#include <string>
#include <fstream>
using namespace std;

int getHeight(treeNode* root)
{

    cout << root << endl;
    if(root == nullptr) {
        return -1;
    }

    int height_left = -1;
    int height_right = -1;
    if(root->left != nullptr) {
        height_left = getHeight(root->left);
    }
    if(root->right != nullptr) {
        height_right = getHeight(root->right);
    }

    //Balance
    cout << height_right - height_left;

    //return höhe
    return 1;

}


int updateHeight(treeNode* root)
{
    cout << root << endl;
    if(root == NU){
        cout << "null" << endl;
        return 0;
    }else{
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        root->height = max(rightHeight, leftHeight);

        cout << "( " << leftHeight << "," << rightHeight << ") Node: " << root->key << " - H " << root->height << endl;

        return max(rightHeight, leftHeight) + 1;
    }


}

treeNode* insert(treeNode* root, int key){

    if (!root) {
        // Insert the first node, if root is NULL.
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

void Inorder(treeNode* root)
{
    if (!root) {
        return;
    }
    Inorder(root->left);
    cout << root->key << " - " << root->height << endl;
    Inorder(root->right);
}


treeNode* search(treeNode* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == nullptr || root->key == key)
    {
        return root;
    }

    // Key is greater than root's key
    if (root->key < key)
    {
        return search(root->right, key);
    }

    // Key is smaller than root's key
    return search(root->left, key);
}


treeNode* readfile(const string& name){

    ifstream myfile("..//input_files//"+name+".txt");
    string myLine;
    int key;
    treeNode* root = nullptr;

    if(myfile.is_open()){
        while(myfile){
            getline(myfile, myLine);
            if(!myLine.empty()) {

                key = stoi(myLine);
                if(search(root,key) == nullptr){
                    root = insert(root, key);
                    cout << "NEW " << root->right << endl;
                    updateHeight(root);
                }

            }
        }
    }
    return root;
}





int main()
{
    treeNode* root = readfile("testTree");

    Inorder(root);



    return 0;
}