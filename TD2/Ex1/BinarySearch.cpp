#include "BinarySearch.h"

int BinarySearch::search(vector<int>& values, int target) {
    if (values.empty()) {
        return -1;
    }

    int left = 0;
    int right = values.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        numberComparaisons++;

        if (values[mid] == target) {
            return mid;
        }

        numberComparaisons++;

        if (values[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1;
}