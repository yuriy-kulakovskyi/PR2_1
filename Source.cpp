#include "./classes/IntRange.h"
#include <iostream>

using namespace std;

#pragma pack(push, 1)
struct PackedIntRange {
    int first;
    int second;
};
#pragma pack(pop)

int main() {
    IntRange r1;
    cin >> r1;

    cout << "r1: " << r1 << endl;

    int num;
    cout << "Input number to check: ";
    cin >> num;
    if (r1.rangeCheck(num)) {
        cout << num << " belongs to the range." << endl;
    }
    else {
        cout << num << " is out of range." << endl;
    }

    cout << "++r1: " << ++r1 << endl;
    cout << "r1++: " << r1++ << " (now: " << r1 << ")" << endl;
    cout << "--r1: " << --r1 << endl;
    cout << "r1--: " << r1-- << " (now: " << r1 << ")" << endl;

    cout << "Size IntRange (with #pragma pack): " << sizeof(IntRange) << endl;
    cout << "Size PackedIntRange: " << sizeof(PackedIntRange) << endl;

    return 0;
}
