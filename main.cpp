

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

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<int> shuffler;
    unsigned seed = 8675309; //I don't want true randomness, so I'm going to use a fixed seed.
    std::default_random_engine e(seed);
    shuffle(shuffler.begin(),shuffler.end(), e);











    return 0;
}