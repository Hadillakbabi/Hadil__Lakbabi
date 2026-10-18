#ifndef JUMPSEARCH_H
#define JUMPSEARCH_H

#include <iostream>
#include "SearchingAlgorithm.h"
using namespace std;

class JumpSearch : public SearchingAlgorithm {
    public:
    int search(vector<int>& values, int target) override;
};

#endif