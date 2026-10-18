#include "LinearSearch.h"


int LinearSearch::search(vector<int>& values, int target) {
    for (int i = 0; i < values.size(); i++) {
        numberComparaisons++;

        if (values[i] == target) {
            return i;
        }
    }

    return -1;
}