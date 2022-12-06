//
// Created by laure on 12/4/2022.
//

#pragma once
#include "MinMakeup.h"

class MinHeap
{
// pointer to array of elements in heap
public:
    //makeup object
    MinMakeup* makeupPtr;

    int capacity; // maximum possible size of min heap
    int heap_size;

    // Constructor
    MinHeap(int capacity);

    // to heapify a subtree with the root at given index
    void MinHeapify(int root);
    //dont change

    MinMakeup extractMin();

    // Returns the minimum key (key at root) from min heap
    MinMakeup getMin() { return makeupPtr[0]; }



    // Inserts a new key 'k'
    //void insertKey(int k);
    void insertKey(MinMakeup k);
    int parent(int i) { return (i - 1) / 2; }

    // to get index of left child of node at index i
    int left(int i) { return (2 * i + 1); }

    // to get index of right child of node at index i
    int right(int i) { return (2 * i + 2); }
};

// Inserts a new makeup object
void MinHeap::insertKey(MinMakeup k)
{

    if (heap_size == capacity) {
        cout << "does not work";
        return;
    }

    // First insert the new makeup obj at the end
    heap_size++;
    int i = heap_size - 1;
    makeupPtr[i] = k;
    while (i != 0 && makeupPtr[parent(i)].price > makeupPtr[i].price)
    {
        //check for minimum price, repeat until min is found

        //store as temp variable
        MinMakeup temp = (makeupPtr[i]);
        (makeupPtr[i]) = makeupPtr[parent(i)];
        makeupPtr[parent(i)] = temp;
        i = parent(i);
        //as long as the parent value is greater than the child value, it will continue to swap
    }
}

MinHeap::MinHeap(int cap)
{
    heap_size = 0;
    capacity = cap;

    makeupPtr = new MinMakeup[cap];
    //dynamic allocation
}


// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);

    int r = right(i);

    int minVal = i;

    if (l < heap_size && makeupPtr[l].price < makeupPtr[i].price) {
        minVal = l;
    }

    if (r < heap_size && makeupPtr[r].price < makeupPtr[minVal].price) {
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

MinMakeup MinHeap::extractMin()
{
    //if (heap_size <= 0)
    //	return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;

        return makeupPtr[0];
    }

    // Store the minimum value, and remove it from heap
    MinMakeup root = makeupPtr[0];
    //replacing the root with the last value
    makeupPtr[0] = makeupPtr[heap_size - 1];

    heap_size--;
    //heapifying to make the min the root again
    MinHeapify(0);

    return root;
}
