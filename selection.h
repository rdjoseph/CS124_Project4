//
// Created by RDJ on 11/5/2018.
//

#ifndef CS124PROJECT_4_SELECTION_H
#define CS124PROJECT_4_SELECTION_H

template<typename Comparable>
void selectionSort(vector<Comparable> &v) {
    if (!v.empty()) {
        Comparable min = v[0], temp;
        int minIndex = 0, swapIndex = 0;
        for (; swapIndex < v.size() - 1; ++swapIndex) {
            min = v[swapIndex];
            minIndex = swapIndex;
            for (int i = swapIndex + 1; i < v.size(); ++i) {
                if (min > v[i]) {
                    // we found a new minimum value
                    min = v[i];
                    minIndex = i;
                }
            }
            if (minIndex != swapIndex) {
                // need to swap min into place
                temp = v[minIndex];
                v[minIndex] = v[swapIndex];
                v[swapIndex] = temp;
            }
            printVector(v);
        }
    }
}

#endif //CS124PROJECT_4_SELECTION_H
