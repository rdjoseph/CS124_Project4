//
// Created by RDJ on 11/5/2018.
//

#ifndef CS124PROJECT_4_BUBBLE_H
#define CS124PROJECT_4_BUBBLE_H

template<typename Comparable>
void bubbleSort(vector<Comparable> &v) {
    // set this to true to enter the while loop
    bool haveSwapped = true;
    int sortedIndex = v.size();
    while (haveSwapped && sortedIndex != 0) {
        haveSwapped = false;
        for (int index = 0; index < sortedIndex - 1; ++index) {
            if (v[index] > v[index + 1]) {
                // swap
                Comparable temp = v[index];
                v[index] = v[index + 1];
                v[index + 1] = temp;
                haveSwapped = true;
            }
        }
        --sortedIndex;
    }
}

#endif //CS124PROJECT_4_BUBBLE_H
