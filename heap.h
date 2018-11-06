//
// Created by RDJ on 11/5/2018.
//

#ifndef CS124PROJECT_4_HEAP_H
#define CS124PROJECT_4_HEAP_H

#include <vector>


//right-read,left-write

template <typename Comparable>
void heapSort(std::vector<Comparable> &v, long* read, long* write) {
    // build the heap (with max value at root)
    for(int i = v.size( ) / 2 - 1; i >= 0; --i) {
        percolateDown(v, i, v.size(), read, write);
    }
    // keep deleting the max
    for(int j = v.size( ) - 1; j > 0; --j) {
        // swap a[0] and a[j]
        Comparable temp = v[0];
        v[0] = v[j];
        v[j] = temp;
        //One read, two writes
        (*read)++;
        (*write) += 2;

        percolateDown(v, 0, j, read, write);
    }
}

inline int leftChild(int i) {
    return 2 * i + 1;
}

// i is the index of the value being percolated down
// n is the number of items in the heap
template <typename Comparable>
void percolateDown(std::vector<Comparable> &v, int i, int n,  long* read, long* write) {
    int child;
    Comparable tmp;

    (*read)++; // Count for loop as one access or many?
    for(tmp = v[i]; leftChild(i) < n; i = child) {
        child = leftChild(i);
        // choose the child with the larger value
        (*read)++; //two accesses in if statement
        if (child != n - 1 && v[child] < v[child + 1]) {
            ++child;
        }
        // if the parent is less than the child, swap them
        (*read)++; //one access in if statement;
        if (tmp < v[child]) {
            v[i] = v[child];
            (*write)++;
        } else {
            // parent is >= both children. nothing more to do.
            break;
        }
    }
    v[i] = tmp;
    (*write)++;
}

#endif //CS124PROJECT_4_HEAP_H
