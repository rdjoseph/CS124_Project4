//
// Created by RDJ on 11/5/2018.
//

#ifndef CS124PROJECT_4_MERGE_H
#define CS124PROJECT_4_MERGE_H

#include <vector>
#include <memory>

template <typename Comparable>
void mergeSort(std::vector<Comparable> &v, int* read, int* write) {
    split(v, 0, v.size() - 1, read, write);
}

template <typename Comparable>
void split(std::vector<Comparable> &v, int start, int end, int* read, int* write) {
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
    split(v, start, center, read, write);
    // Recursive call for right side
    split(v, center + 1, end, read, write);

    // Assume the recursive calls make each half sorted
    // Now we need to merge the two halves together
    merge(v, start, center, end, read, write);
}

template <typename Comparable>
void merge(std::vector<Comparable> &v, int start, int center, int end,int* read, int* write) {
    std::vector<Comparable> temp;
    int c = center, s = start;
    // Keep choosing the smallest item between the halves
    // Until one half empties
    while (start <= c && center + 1 <= end) {
        (*read) += 2;
        if (v[start] < v[center + 1]) {
            temp.push_back(v[start]);
            ++start;
        } else {
            temp.push_back(v[center + 1]);
            ++center;
        }
        (*write)++;
    }

    while (start <= c || center + 1 <= end) {
        if (start <= c) {
            temp.push_back(v[start]);
            ++start;
        } else {
            temp.push_back(v[center + 1]);
            ++center;
        }
        (*write)++;
    }

    // Now copy everything back from temp into v
    for (int i = 0; i < temp.size(); ++i) {
        v[s + i] = temp[i];
        (*write)++;
    }

}

#endif //CS124PROJECT_4_MERGE_H
