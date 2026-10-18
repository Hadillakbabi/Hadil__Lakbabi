#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <iostream>
#include "SearchingAlgorithm.h"
using namespace std;

class BinarySearch : public SearchingAlgorithm {
    public:
    int search(vector<int>& values, int target) override;
};

#endif