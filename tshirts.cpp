#include <iostream>
#include <cassert>

char determineShirtSize(int measurementInCms) {
    char sizeCategory = '\0';  // Initialize with null character
    if(measurementInCms < 38) {
        sizeCategory = 'S';
    } else if(measurementInCms >= 38 && measurementInCms < 42) {  // Corrected condition to include 38
        sizeCategory = 'M';
    } else if(measurementInCms >= 42) {  // Adjusted to include 42
        sizeCategory = 'L';
    }
    return sizeCategory;
}

int main() {
    assert(determineShirtSize(37) == 'S');
    assert(determineShirtSize(40) == 'M');
    assert(determineShirtSize(43) == 'L');
    assert(determineShirtSize(42) == 'L');  // Changed expectation for size 42 based on updated logic
    std::cout << "All is well (maybe!)\n";
    return 0;
}
