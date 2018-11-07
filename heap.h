//
// Created by RDJ on 11/5/2018.
//

#ifndef CS124PROJECT_4_HEAP_H
#define CS124PROJECT_4_HEAP_H

#include <vector>


//right-read,left-write







template <typename Comparable>
void heapSort(std::vector<Comparable> &v) {
    // build the heap (with max value at root)
    for(int i = v.size( ) / 2 - 1; i >= 0; --i) {
        percolateDown(v, i, v.size());
    }
    printVector(v);
    // keep deleting the max
    for(int j = v.size( ) - 1; j > 0; --j) {
        // swap a[0] and a[j]
        Comparable temp = v[0];
        v[0] = v[j];
        v[j] = temp;

        percolateDown(v, 0, j);

        printVector(v);
    }
}

inline int leftChild(int i) {
    return 2 * i + 1;
}

// i is the index of the value being percolated down
// n is the number of items in the heap
template <typename Comparable>
void percolateDown(std::vector<Comparable> &v, int i, int n) {
    int child;
    Comparable tmp;

    for(tmp = v[i]; leftChild(i) < n; i = child) {
        child = leftChild(i);
        // choose the child with the larger value
        if (child != n - 1 && v[child] < v[child + 1]) {
            ++child;
        }
        // if the parent is less than the child, swap them
        if (tmp < v[child]) {
            v[i] = v[child];
        } else {
            // parent is >= both children. nothing more to do.
            break;
        }
    }
    v[i] = tmp;
}
#endif //CS124PROJECT_4_HEAP_H
