#ifndef LINEARSEARCH_H
#define LINEARSEARCH_H

#include <iostream>
#include "SearchingAlgorithm.h"
using namespace std;

class LinearSearch : public SearchingAlgorithm {
    public:
    int search(vector<int>& values, int target) override;
};

#endif