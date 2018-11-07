

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
#include "two.h"

#include "WeatherSummaries.h"

using namespace std;

int main() {
    //I'm going to make a vector for each algorithm to use, and resize with each loop through.
    //Because I shuffled with a fixed seed, these should all come out identically.
    vector<WeatherSummary> bubble,
                           heap,
                           merge,
                           selection,
                           two;
//    makeVector(bubble);
      makeVector(heap);
//    makeVector(merge);
//    makeVector(selection);
//    makeVector(two);

//    bubble.resize(1000);
      heap.resize(1000);
//    merge.resize(1000);
//    selection.resize(1000);
//    two.resize(1000);

//   shuffleVector(bubble);
      shuffleVector(heap);
//    shuffleVector(merge);
//    shuffleVector(selection);
//    shuffleVector(two);



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



//    long* read = new long;
//    long* write = new long;
//    *read = 0;
//    *write = 0;
//
//    // I need two CSV Files. One for reads, one for writes. Let's call them read.csv and write.csv
//    //setup: bubble, heap, merge, selection, two
//    ofstream readFile("read.csv");
//    readFile << "Bubble, Heap, Merge, Sel, Two \n";
//    ofstream writeFile("write.csv");
//    writeFile << "Bubble, Heap, Merge, Sel, Two \n";
//
//    //For each sort, shuffle the vector (fixed randomness with seed 867509)
//    // sort, write to read file, write to write file, reset reads & writes,  resize vector
//    for(int i = 9; i > 0; i--)
//    {
//        //Bubble sort
//        shuffleVector(bubble);
//        bubbleSort(bubble,read,write);
//        readFile << *read << ",";
//        writeFile << *write << ",";
//        *read = 0;
//        *write = 0;
//        bubble.resize((i*100));
//
//
//        //Heap sort
//        shuffleVector(heap);
//        heapSort(heap,read,write);
//        readFile << *read << ",";
//        writeFile << *write << ",";
//        *read = 0;
//        *write = 0;
//        heap.resize((i*100));
//
//
//        //Merge sort
//        shuffleVector(merge);
//        mergeSort(merge,read,write);
//        readFile << *read << ",";
//        writeFile << *write << ",";
//        *read = 0;
//        *write = 0;
//        merge.resize((i*100));
//
//
//        //Selection sort
//        shuffleVector(selection);
//        selectionSort(selection,read,write);
//        readFile << *read << ",";
//        writeFile << *write << ",";
//        *read = 0;
//        *write = 0;
//        selection.resize((i*100));
//
//
//        //Two-sort: Merge then selection by precipitation
//        shuffleVector(heap);
//        twoSort(two,read,write);
//        readFile << *read << "\n";
//        writeFile << *write << "\n";
//        *read = 0;
//        *write = 0;
//        two.resize((i*100));
//
//    }
//    readFile.close();
//    writeFile.close();
//
//    bubbleSort(bubble,read, write);
//    *read = 0;
//    *write = 0;
//
//
//
//    cout << "Bubble" << endl;
//    printVector(bubble,cout);
//    cout << endl;
//
//    cout << "Heap" << endl;
//    printVector(heap,cout);
//    cout << endl;
//
//    cout << "Merge" << endl;
//    printVector(merge,cout);
//    cout << endl;
//
//    cout << "Selection" << endl;
//    printVector(selection,cout);
//    cout << endl;
//
//    cout << "Two Sort (Merge, then Selection by precipitation" << endl;
//    printVector(two,cout);
//    cout << endl;

    //Prevent those memory leaks
//    delete read;
//    delete write;

      heapSort(heap);

      printVector(heap,cout);




    return 0;
}