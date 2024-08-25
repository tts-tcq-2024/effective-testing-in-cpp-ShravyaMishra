#include <iostream>
#include <assert.h>

// Function to determine t-shirt size based on cms measurement
char determineSize(int cmsMeasurement) {
    char sizeChar = '\0';
    if (cmsMeasurement < 38) {
        sizeChar = 'S'; // Small
    } else if (cmsMeasurement >= 38 && cmsMeasurement < 42) {
        sizeChar = 'M'; // Medium
    } else if (cmsMeasurement >= 42) {
        sizeChar = 'L'; // Large
    }
    return sizeChar;
}

// Function to test t-shirt size determination
void testTshirtSizes() {
    assert(determineSize(37) == 'S');
    assert(determineSize(40) == 'M');
    assert(determineSize(43) == 'L');
    assert(determineSize(38) == 'M');
    assert(determineSize(41) == 'M');
    assert(determineSize(42) == 'L');
    assert(determineSize(44) == 'L');
}

int main() {
    testTshirtSizes();
    std::cout << "All tests passed (hopefully!)\n";
    return 0;
}
