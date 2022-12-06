#pragma once
#include "Makeup.h"
using namespace std;

// each node should be a makeup object
// this object should hold type, rating, price, and brand (id #?)
// read each item from file and continually add to the heap
// each node should be a different makeup object, organized by price
class PairingHeap {
private:
public:
    Makeup* root = nullptr;
    int size = 0;
    void Insert(Makeup* newMakeup);
    void Print();
    Makeup* GetMin();
};

//make the tree that has the larger root the leftmost subtree of the other tree.
void PairingHeap::Insert(Makeup* newMakeup) {
    size++;
    //cout << newMakeup->price << endl;
    if (root == nullptr) {
        root = newMakeup;
        //cout << "nullptr" << endl;
    }

    else if (root->price < newMakeup->price) { //if root's price is smaller than newMakeup's...
        //make newMakeup a left child of the root node
        //cout << "root: " << root->price << " newMakeup: " << newMakeup->price << endl;
        if (root->leftChild == nullptr) { //if a left child doesn't exist yet, make it the left child
            root->leftChild = newMakeup;
        }
        else { //if a left child already exists...
            Makeup* temp = root->leftChild;
            root->leftChild = newMakeup; //root's left child will now be newMakeup
            Makeup* tempSibling = root->sibling;
            root->sibling = temp; //set newMakeup's sibling to be the root's current left child

            if (root->sibling != nullptr) {
                root->sibling->sibling = tempSibling;
            }

//            Makeup* currMakeup = root->leftChild;
//            while (currMakeup != nullptr) {
//                currMakeup = currMakeup->sibling;
//            }
//            currMakeup->sibling = newMakeup;
        }
    }
    else { //make it the new root, it has the lowest price so far
        Makeup* oldRoot = root;
        root = newMakeup;
        root->leftChild = oldRoot;
    }

}

void PairingHeap::Print() {
    Makeup* currProduct = root;
    //cout << root->price;
    while (currProduct->leftChild != nullptr) {
        currProduct = currProduct->leftChild;
        cout << currProduct->price << endl;
        while (currProduct->sibling != nullptr) {
            Makeup* row = currProduct->sibling;
            cout << currProduct->price << endl;
        }
    }
}

Makeup* PairingHeap::GetMin() {
    if (root == nullptr) {
        cout << "ur dumb" << endl;
    }
    /*cout << root->id << endl;
    cout << root->brand << endl;*/

    return root;
}