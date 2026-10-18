#include "JumpSearch.h"
#include <cmath>
#include <algorithm>

int JumpSearch::search(vector<int>& values, int target) {
    if (values.empty()) {
        return -1;
    }

    int n = values.size();
    int step = sqrt(n);
    int prev = 0;
    int next = step;

    while (prev < n) {
        numberComparaisons++;

        if (values[min(next, n) - 1] >= target) {
            break;
        }

        prev = next;
        next += step;
    }

    for (int i = prev; i < min(next, n); i++) {
        numberComparaisons++;

        if (values[i] == target) {
            return i;
        }
    }

    return -1;
}