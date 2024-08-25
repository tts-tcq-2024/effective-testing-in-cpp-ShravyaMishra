#include <iostream>
#include <cassert>

int failureCount = 0;

char categorizeSize(int measurementInCms) {
    char sizeCategory = '\0';
    if(measurementInCms < 38) {
        sizeCategory = 'S';
    } else if(measurementInCms >= 38 && measurementInCms < 42) {
        sizeCategory = 'M';
    } else if(measurementInCms >= 42) {
        sizeCategory = 'L';
    }
    return sizeCategory;
}

void testCategorizeSize() {
    failureCount = 0;

    // Test cases
    char result;

    result = categorizeSize(37);
    if (result != 'S') failureCount++;
    
    result = categorizeSize(38);
    if (result != 'M') failureCount++;
    
    result = categorizeSize(41);
    if (result != 'M') failureCount++;
    
    result = categorizeSize(42);
    if (result != 'L') failureCount++;
    
    result = categorizeSize(43);
    if (result != 'L') failureCount++;
    
    std::cout << "FailureCount = " << failureCount << std::endl;
    assert(failureCount == 0);  // Expect no failures
    
    std::cout << "All tests passed successfully!\n";
}

int main() {
    testCategorizeSize();  // Run the test cases

    std::cout << "All is well (maybe!)\n";
    return 0;
}

