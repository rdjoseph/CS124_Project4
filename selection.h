//
// Created by RDJ on 11/5/2018.
//

#ifndef CS124PROJECT_4_SELECTION_H
#define CS124PROJECT_4_SELECTION_H

#include <vector>


//right-read,left-write

template<typename Comparable>
void selectionSort(std::vector<Comparable> &v, long* read, long* write) {
    if (!v.empty()) {
        Comparable min = v[0], temp;
        (*read)++;
        int minIndex = 0, swapIndex = 0;
        for (; swapIndex < v.size() - 1; ++swapIndex) {
            min = v[swapIndex];
            (*read)++;
            minIndex = swapIndex;
            for (int i = swapIndex + 1; i < v.size(); ++i) {
                (*read)++;
                if (min > v[i]) {
                    // we found a new minimum value
                    min = v[i];
                    minIndex = i;
                    (*read)++;
                }
            }
            if (minIndex != swapIndex) {
                // need to swap min into place
                temp = v[minIndex];
                v[minIndex] = v[swapIndex];
                v[swapIndex] = temp;
                (*write) += 2;
                (*read) += 2;
            }

        }
    }
}

#endif //CS124PROJECT_4_SELECTION_H
