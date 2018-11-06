//
// Created by RDJ on 11/5/2018.
//

#ifndef CS124PROJECT_4_BUBBLE_H
#define CS124PROJECT_4_BUBBLE_H

#include <vector>
#include <ostream>
#include <memory>


template<typename Comparable>
void bubbleSort(std::vector<Comparable> &v, long* read, long* write) {
    // set this to true to enter the while loop
    bool haveSwapped = true;
    int sortedIndex = v.size();
    while (haveSwapped && sortedIndex != 0) {
        haveSwapped = false;
        for (int index = 0; index < sortedIndex - 1; ++index) {
            (*read) += 2;
            if (v[index] > v[index + 1]) {
                // swap
               // read++;
                Comparable temp = v[index];
                v[index] = v[index + 1];
                v[index + 1] = temp;
                haveSwapped = true;
                *write += 2;
                *read += 2;
            }
        }
        --sortedIndex;
    }
}

#endif //CS124PROJECT_4_BUBBLE_H
