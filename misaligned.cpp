#include <iostream>
#include <assert.h>
#include <string>

std::string colorMapOutputBuffer;
int majorColorIndex = 0, minorColorIndex = 0;

std::string getColorPair(int majorColorIdx, int minorColorIdx) {
    const char* majorColors[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColors[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    return std::to_string(majorColorIdx * 5 + minorColorIdx) + " | " + majorColors[majorColorIdx] + " | " + minorColors[minorColorIdx];
}

void printColorMap() {
    for (majorColorIndex = 0; majorColorIndex < 5; majorColorIndex++) {
        for (minorColorIndex = 0; minorColorIndex < 5; minorColorIndex++) {
            std::cout << getColorPair(majorColorIndex, minorColorIndex) << "\n";
            colorMapOutputBuffer += getColorPair(majorColorIndex, minorColorIndex) + "\n";
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
        "22 | Violet | Green\n
