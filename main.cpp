

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "bubble.h"
#include "heap.h"
#include "merge.h"
#include "selection.h"
//#include "two.h"

#include "WeatherSummaries.h"

using namespace std;

int main() {
    //I'm going to make a vector of vectors for each sorting algorithm, that contains the ten vectors of varying sizes.
    //Because I shuffled with a fixed seed, these should all come out identically.
    std::vector<vector<WeatherSummary>> bubble;
    std::vector<vector<WeatherSummary>> heap;
    std::vector<vector<WeatherSummary>> merge;
    std::vector<vector<WeatherSummary>> selection;

    makeVectors(bubble);
















    return 0;
}