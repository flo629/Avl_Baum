#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "treenode.h"
#include <string>
#include <fstream>
#include <algorithm>
#include "Tree.h"
using namespace std;


treeNode* readfile(Tree* tree, const string& name){

    ifstream myfile("..//input_files//"+name+".txt");
    string myLine;
    int key;
    treeNode* root = nullptr;

    if(myfile.is_open()){
        while(myfile){
            getline(myfile, myLine);
            if(!myLine.empty()) {

                key = stoi(myLine);
                if(tree->search(root,key, 0) == nullptr){
                    root = tree->insert(root, key);
                }

            }
        }
    }
    return root;
}

int subtreeSearch(Tree* tree, treeNode* searchTreeNode, treeNode* root) {

    //cout << "search" << root->key << endl;
    treeNode* result = tree->search(searchTreeNode, root->key, 0);
    if(result == nullptr) {
        //cout<< root->key << " not found!";
        return 0;
    }else{
        //cout << "found " << root->key << endl;
        int leftfound = 1;
        int rightfound = 1;

        if(root->left != nullptr) {
            leftfound =  subtreeSearch(tree, result, root->left);
        }

        if(root->right != nullptr) {
            rightfound = subtreeSearch(tree, result, root->right);
        }

        if(leftfound && rightfound) {
            return 1;
        } else {
            return 0;
        }

    }



}

int main(int argc, char** argv)
{
    Tree* tree = new Tree();

    cout << argc << endl;
    for(int i = 0; i < argc; i++) {
        cout << argv[i] << endl;
    }

    tree->root = readfile(tree, argv[1]);

    if(argc <= 2) {
        tree->printBalance(tree->root);
        tree->printStats();
    } else {

        tree->printBalance(tree->root);
        tree->printStats();

        ifstream myfile(string("..//input_files//") + argv[2] + ".txt");
        int lines = count(std::istreambuf_iterator<char>(myfile),
                   std::istreambuf_iterator<char>(), '\n') +1;

        cout << "Lines" << lines << endl;

        string myLine;
        int key = 0;

        if(lines == 1) {
            if(myfile.is_open()){
                myfile.seekg(0);
                getline(myfile, myLine);
                if(!myLine.empty()) {
                    key = stoi(myLine);
                }
            }

            treeNode* result = tree->search(tree->root, key, 0);

            if(result != nullptr){
                cout<<result->key<<" found: ";
                tree->search(tree->root,key,1);
            } else {
                cout << key << " not found!" << endl;
            }
        } else  {
            Tree* subTree = new Tree();

            subTree->root = readfile(subTree, argv[2]);

            int result = subtreeSearch(tree, tree->root, subTree->root);

            if(result) {
                cout << "subtree found" << endl;
            }
        }

    }



    delete tree;
    return 0;
}