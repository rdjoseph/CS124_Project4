//
// Created by RDJ on 11/5/2018.
//

#ifndef CS124PROJECT_4_MERGE_H
#define CS124PROJECT_4_MERGE_H

template <typename Comparable>
void mergeSort(vector<Comparable> &v) {
    split(v, 0, v.size() - 1);
}

template <typename Comparable>
void split(vector<Comparable> &v, int start, int end) {
    int length = end - start;
    // TODO: fixed this base case
    // Base case to stop recursion: start = end
    if (length < 1) {
        return;
    }
    // Need to split again
    // TODO: fixed this to add start
    int center = start + (length / 2);
    // Recursive call for left side
    split(v, start, center);
    // Recursive call for right side
    split(v, center + 1, end);

    // Assume the recursive calls make each half sorted
    // Now we need to merge the two halves together
    merge(v, start, center, end);
}

template <typename Comparable>
void merge(vector<Comparable> &v, int start, int center, int end) {
    vector<Comparable> temp;
    int c = center, s = start;
    // Keep choosing the smallest item between the halves
    // Until one half empties
    while (start <= c && center + 1 <= end) {
        if (v[start] < v[center + 1]) {
            temp.push_back(v[start]);
            ++start;
        } else {
            temp.push_back(v[center + 1]);
            ++center;
        }
    }

    while (start <= c || center + 1 <= end) {
        if (start <= c) {
            temp.push_back(v[start]);
            ++start;
        } else {
            temp.push_back(v[center + 1]);
            ++center;
        }
    }

    // Now copy everything back from temp into v
    for (int i = 0; i < temp.size(); ++i) {
        v[s + i] = temp[i];
    }
    printVector(v);
}

#endif //CS124PROJECT_4_MERGE_H
