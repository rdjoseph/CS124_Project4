

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
#include "quick.h"
#include "selection.h"
#include "two.h"

#include "WeatherSummaries.h"

using namespace std;

int main() {
    //I'm going to make a vector for each algorithm to use, and resize with each loop through.

    vector<WeatherSummary> bubble,
                           heap,
                           merge,
                           quick,
                           selection,
                           two;
      makeVector(bubble);
      makeVector(heap);

      makeVector(merge);
      makeVector(quick);
      makeVector(selection);
      makeVector(two);






    //Because my vector gets made in order of my sorting attribute, I have to shuffle it. See WeatherSummaries.cpp for my function.
    //If you need proof that they all end up in the same order, here's a section that does that
    //The shuffle uses a fixed seed so it should never produce a different result for the same input

    /*

    shuffleVector(bubble);
    shuffleVector(heap);
    shuffleVector(insert);
    shuffleVector(merge);
    shuffleVector(quick);
    shuffleVector(selection);
    shuffleVector(two);

    cout << "Bubble vector" << endl;
    printVector(bubble,cout);
    cout << endl;

    cout << "Heap vector" << endl;
    printVector(heap,cout);
    cout << endl;

    cout << "Merge vector" << endl;
    printVector(merge,cout);
    cout << endl;

     cout << "Quick vector" << endl;
    printVector(quick,cout);
    cout << endl;

    cout << "Selection vector" << endl;
    printVector(selection,cout);
    cout << endl;
    */



    long* read = new long;
    long* write = new long;
    *read = 0;
    *write = 0;

    // I need two CSV Files. One for reads, one for writes. Let's call them read.csv and write.csv
    //setup: bubble, heap, merge, selection, two
    ofstream readFile("read.csv");
    readFile << "Bubble, Heap, Merge, Quick, Sel, Two \n";
    ofstream writeFile("write.csv");
    writeFile << "Bubble, Heap, Merge, Quick, Sel, Two \n";

    //For each sort, shuffle the vector (fixed randomness with seed 867509)
    // sort, write to read file, write to write file, reset reads & writes,  resize vector
    for(int i = 10; i > 0; i--)
    {
        //Bubble sort
        bubble.resize((i*100));
        shuffleVector(bubble);
        bubbleSort(bubble,read,write);
        readFile << *read << ",";
        writeFile << *write << ",";
        *read = 0;
        *write = 0;

        //Heap sort
        heap.resize((i*100));
        shuffleVector(heap);
        heapSort(heap,read,write);
        readFile << *read << ",";
        writeFile << *write << ",";
        *read = 0;
        *write = 0;

        //Merge sort
        merge.resize((i*100));
        shuffleVector(merge);
        mergeSort(merge,read,write);
        readFile << *read << ",";
        writeFile << *write << ",";
        *read = 0;
        *write = 0;

        //Quick sort
        quick.resize((i*100));
        shuffleVector(quick);
        quickSort(quick,read,write);
        readFile << *read << ",";
        writeFile << *write << ",";
        *read = 0;
        *write = 0;

        //Selection sort
        selection.resize((i*100));
        shuffleVector(selection);
        selectionSort(selection,read,write);
        readFile << *read << ",";
        writeFile << *write << ",";
        *read = 0;
        *write = 0;

        //Two-sort: Merge then selection by precipitation
        two.resize((i*100));
        shuffleVector(heap);
        twoSort(two,read,write);
        readFile << *read << "\n";
        writeFile << *write << "\n";
        *read = 0;
        *write = 0;


    }
    readFile.close();
    writeFile.close();
    //Only issue is that the data writes in reverse of order I want it too. I can reverse the rows manually in Excel.

    bubbleSort(bubble,read, write);
    *read = 0;
    *write = 0;

    cout << "Bubble" << endl;
    printVector(bubble,cout);
    cout << endl;

    cout << "Heap" << endl;
    printVector(heap,cout);
    cout << endl;

    cout << "Merge" << endl;
    printVector(merge,cout);
    cout << endl;

    cout << "Selection" << endl;
    printVector(selection,cout);
    cout << endl;

    cout << "Two Sort (Merge, then Selection by precipitation" << endl;
    printVector(two,cout);
    cout << endl;

    //Prevent those memory leaks
    delete read;
    delete write;

    return 0;
}