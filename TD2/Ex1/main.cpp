#include <iostream>
#include <vector>
#include "LinearSearch.h"
#include "BinarySearch.h"
#include "JumpSearch.h"

using namespace std;

int main() {
    vector<int> values = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};

    int target = 23;

    LinearSearch linear;
    BinarySearch binary;
    JumpSearch jump;

    cout << " LINEAR SEARCH " << endl;
    int result1 = linear.search(values, target);
    linear.displaySearchResults(cout, result1, target);

    cout << "\n BINARY SEARCH " << endl;
    int result2 = binary.search(values, target);
    binary.displaySearchResults(cout, result2, target);

    cout << "\n JUMP SEARCH " << endl;
    int result3 = jump.search(values, target);
    jump.displaySearchResults(cout, result3, target);

    return 0;
}