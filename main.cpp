

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

    std::vector<WeatherSummary> weatherData;
    makeVector(weatherData,1200);
    printVector(weatherData,cout);
    cout << endl;




    //If you need proof that they're the same, here's a section that does that
    /*
    cout << "Bubble vector of 100" << endl;
    printVector((bubble.at(0)),cout);
    cout << endl;

    cout << "Heap vector of 100" << endl;
    printVector((heap.at(0)),cout);
    cout << endl;

    cout << "Merge vector of 100" << endl;
    printVector((merge.at(0)),cout);
    cout << endl;

    cout << "Selection vector of 100" << endl;
    printVector((selection.at(0)),cout);
    cout << endl;
    */



    long* read = new long;
    long* write = new long;
    *read = 0;
    *write = 0;

    bubbleSort(weatherData, read, write);

    /* Do with a thousand, then resize, */



    //printVector(bubble.at(9),cout);




    delete read;
   delete write;




    return 0;
}