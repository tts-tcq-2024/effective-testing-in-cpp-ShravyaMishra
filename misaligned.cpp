#include <iostream>
#include <assert.h>
#include <string>

std::string colorMapOutput;
int i = 0, j = 0;

std::string getColorPair(int majorColorIndex, int minorColorIndex) {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    return std::to_string(majorColorIndex * 5 + minorColorIndex) + " | " + majorColor[majorColorIndex] + " | " + minorColor[majorColorIndex];
}

void printColorMap(){
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << getColorPair(i, j) << "\n";
            colorMapOutput = getColorPair(i, j);
        }
    }
}

void testColorMap() {
    std::string expectedOutput =
        "0 | White | Blue\n"
        "1 | White | Orange\n"
        "2 | White | Green\n"
        "3 | White | Brown\n"
        "4 | White | Slate\n"
        "5 | Red | Blue\n"
        "6 | Red | Orange\n"
        "7 | Red | Green\n"
        "8 | Red | Brown\n"
        "9 | Red | Slate\n"
        "10 | Black | Blue\n"
        "11 | Black | Orange\n"
        "12 | Black | Green\n"
        "13 | Black | Brown\n"
        "14 | Black | Slate\n"
        "15 | Yellow | Blue\n"
        "16 | Yellow | Orange\n"
        "17 | Yellow | Green\n"
        "18 | Yellow | Brown\n"
        "19 | Yellow | Slate\n"
        "20 | Violet | Blue\n"
        "21 | Violet | Orange\n"
        "22 | Violet | Green\n"
        "23 | Violet | Brown\n"
        "24 | Violet | Slate\n";

    std::string actualOutput;
    actualOutput += colorMapOutput;

    assert(actualOutput == expectedOutput);
}

int main() {
    testColorMap();
    std::cout << "All is well (maybe!)\n";
    return 0;
}
