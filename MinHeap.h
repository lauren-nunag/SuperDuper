#pragma once
#include "MinMakeup.h"
//AAYESHA
class MinHeap {
// pointer to array of elements in heap
public:
    MinMakeup* makeupPtr; //makeup object
    int maxSize; // maximum possible size of min heap
    int size;

    //functions:
    //creates minHeap
    MinHeap(int maxSize);
    //performs heapify at the root
    MinMakeup getMin() { return makeupPtr[0]; }
    //insert a new makeup object
    void MinHeapify(int root);
    //gets the minimum priced makeup
    void insert(MinMakeup k);
    //removes the current root
    MinMakeup extractMin();

    //gets index of nodes according to num
    int getLeft(int num);
    int getParent(int num);
    int getRight(int num);
};

// Inserts a new makeup object
void MinHeap::insert(MinMakeup k) {

    // First insert the new makeup obj at the end
    size++;
    int index = size - 1;
    makeupPtr[index] = k;
    while (index != 0 && makeupPtr[getParent(index)].price > makeupPtr[index].price) {
        //check for minimum price, repeat until min is found
        MinMakeup temp = (makeupPtr[index]);
        //store as temp variable
        (makeupPtr[index]) = makeupPtr[getParent(index)];
        makeupPtr[getParent(index)] = temp;
        index = getParent(index);
        //as long as the parent value is greater than the child value, it will continue to swap
    }
}

MinHeap::MinHeap(int maxSize) {
    maxSize = maxSize;
    size = 0;

    //dynamic allocation
    makeupPtr = new MinMakeup[maxSize];
}


// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = getLeft(i);
    int r = getRight(i);
    int minVal = i;

    if (l < size && makeupPtr[l].price < makeupPtr[i].price) {
        minVal = l;
    }

    if (r < size && makeupPtr[r].price < makeupPtr[minVal].price) {
        minVal = r;
    }

    if (minVal != i)
    {
        MinMakeup temp = (makeupPtr[i]);
        makeupPtr[i] = makeupPtr[minVal];
        makeupPtr[minVal] = temp;
        MinHeapify(minVal);
    }
}

MinMakeup MinHeap::extractMin() {

    if (size == 1) {
        size--;
        return makeupPtr[0];
    }

    MinMakeup root = makeupPtr[0];
    //replacing the root with the last value
    makeupPtr[0] = makeupPtr[size - 1];

    //decrement heap size by one
    size = size-1;

    //heapifying to make the min the root again
    MinHeapify(0);
    return root;
}

int MinHeap::getLeft(int num) {
    int result = 2 * num + 1;
    return result;
}

int MinHeap::getParent(int num) {
    int result = (num - 1) / 2;
    return result;
}

int MinHeap::getRight(int num) {
    int result = 2 * num + 2;
    return result;
}
