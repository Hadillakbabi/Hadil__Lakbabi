#ifndef SEARCHINGALGORITHM_H
#define SEARCHINGALGORITHM_H

#include <iostream>
#include <vector>
using namespace std;

class SearchingAlgorithm {
    
protected:
    long int numberComparaisons;
    static long int totalComparisons;
    static long int totalSearch;
    static double averageComparisons;

public:
    SearchingAlgorithm();
    virtual ~SearchingAlgorithm() = default;
    virtual int search(vector<int>& values, int target) = 0;
    void displaySearchResults(ostream& os, int result, int target);
};

#endif