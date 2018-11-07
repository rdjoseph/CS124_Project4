

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
    //I'm going to make a vector for each algorithm to use, and resize with each loop through.
    //Because I shuffled with a fixed seed, these should all come out identically.
    vector<WeatherSummary> bubble,
                           heap,
                           merge,
                           selection;
                         //  two;
    makeVector(bubble);
    makeVector(heap);
    makeVector(merge);
    makeVector(selection);
   // makeVector(two);

    bubble.resize(1000);
    heap.resize(1000);
    merge.resize(1000);
    selection.resize(1000);
   // two.resize(1000);



    //If you need proof that they're all in the same order, here's a section that does that
    /*
    cout << "Bubble vector" << endl;
    printVector(bubble),cout);
    cout << endl;

    cout << "Heap vector" << endl;
    printVector((heap),cout);
    cout << endl;

    cout << "Merge vector" << endl;
    printVector((merge),cout);
    cout << endl;

    cout << "Selection vector" << endl;
    printVector((selection),cout);
    cout << endl;
    */



    long* read = new long;
    long* write = new long;
    *read = 0;
    *write = 0;
    /* Do with a thousand, then resize, */






    //printVector(bubble.at(9),cout);




    delete read;
   delete write;




    return 0;
}