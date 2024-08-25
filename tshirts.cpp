#include <iostream>
#include <cassert>

char categorizeShirtSize(int measurementInCms) {
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

void testCategorizeShirtSize() {
    // Test cases for shirt size categorization
    assert(categorizeShirtSize(37) == 'S');
    assert(categorizeShirtSize(40) == 'M');
    assert(categorizeShirtSize(43) == 'L');
    assert(categorizeShirtSize(42) == 'L');  // Changed expectation for size 42 based on updated logic

    std::cout << "All tests passed successfully!\n";
}

int main() {
    testCategorizeShirtSize();  // Run the test cases

    std::cout << "All is well (maybe!)\n";
    return 0;
}
