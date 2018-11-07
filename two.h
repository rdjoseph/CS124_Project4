//
// Created by RDJ on 11/7/2018.
//

#ifndef CS124PROJECT_4_TWO_H
#define CS124PROJECT_4_TWO_H

#include "WeatherSummaries.h"
#include "merge.h"

/* Requires: A vector of weather summary objects
 * Modifies: Sorts using a standard mergesort (see: merge.h), then again by precipitation using selection sort
 * Effects: Modifies the long pointers read and write.
 */


//right-read,left-write
void twoSort(std::vector<WeatherSummary> &v, long* read, long* write) {
    //First do the merge sort
    mergeSort(v,read,write);

    //Now sort by precipitation.
    if (!v.empty()) {
        WeatherSummary min = v[0], temp;
        (*read)++;
        int minIndex = 0, swapIndex = 0;
        for (; swapIndex < v.size() - 1; ++swapIndex) {
            min = v[swapIndex];
            (*read)++;
            minIndex = swapIndex;
            for (int i = swapIndex + 1; i < v.size(); ++i) {
                (*read)++;
                if (min.getPrecipitation() > v[i].getPrecipitation()) {
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





#endif //CS124PROJECT_4_TWO_H
