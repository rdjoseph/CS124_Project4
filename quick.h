//
// Created by RDJ on 11/7/2018.
//

#ifndef CS124PROJECT_4_QUICK_H
#define CS124PROJECT_4_QUICK_H

#include <vector>

//right-read, left-write
template<typename Comparable>
void quickSort(std::vector<Comparable> &v, long* read, long* write ) {
    if (!v.empty()) {
        std::vector<Comparable> less, equal, greater;
        int partitionIndex = 0;
        (*read)++;
        Comparable partitionValue = v[partitionIndex];
        for (int i = partitionIndex + 1; i < v.size(); ++i) {
            (*read)++;
            if (v[i] < partitionValue) {
                (*read)++;
                less.push_back(v[i]);
            } else if (v[i] > partitionValue) { //it'll only do this read if the if doesn't happen, so I can record it inside it
                (*read)+=2;
                greater.push_back(v[i]);
            } else {
                (*read)++;
                equal.push_back(v[i]);
            }
        }
        // Recursive calls for the less and greater vectors to sort themselves
        quickSort(less,read,write);
        quickSort(greater,read,write);
        // Copy everything back into v
        int index = 0;
        for (Comparable &item : less) {
            (*write)++;
            v[index] = item;
            ++index;
        }

        (*read)++;
        v[index] = partitionValue;
        ++index;
        for (Comparable &item : equal) {
            (*write)++;
            v[index] = item;
            ++index;
        }
        for (Comparable &item : greater) {
            (*write)++;
            v[index] = item;
            ++index;
        }
    }
}





#endif //CS124PROJECT_4_QUICK_H
