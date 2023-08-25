//#include "PrintColorMapTest.h"
//#include "PrintColorMapTest.h"
//#include "ColorMap.h"
#include <iostream>
#include <vector>
#include <assert.h>
#include<string>
#include <iomanip>
struct ColorPair
    {
        int number;
        std::string majorColor;
        std::string minorColor;
    };

std::vector<ColorPair> PrintColorMap() {
    const char* majorColor[] = { "White", "Red", "Black", "Yellow", "Violet" };
    const char* minorColor[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
    int i = 0, j = 0;
    std::vector<ColorPair> colorMap;
        for (i = 0; i < 5; i++)
    {
        for (j = 0; j <5; j++)
        {
            ColorPair cp;
            cp.number = i * 5 + j+1;
            cp.majorColor = majorColor[i];
            cp.minorColor = minorColor[j];
            colorMap.push_back(cp);
            std::cout << std::setw(2)<<cp.number << std::setw(2)<< "|" << std::setw(6)<<cp.majorColor << std::setw(2)<< "|" << std::setw(6) << cp.minorColor << "\n";
        }
    }
    return colorMap;
}

void test_PrintColorMap()
{
     std::vector<ColorPair> colorMap = PrintColorMap();
    int result = colorMap.size();
    std::string expectedstr = "25|Violet|Slate";
    std::string actualstr = std::to_string(colorMap[24].number) + "|" + colorMap[24].majorColor + "|" + colorMap[24].minorColor;
    
    assert(result == 25);

    assert(colorMap[0].number == 1);
    assert(colorMap[0].majorColor == "White");
    assert(colorMap[0].minorColor == "Blue");

    assert(colorMap[12].number == 13);
    assert(colorMap[12].majorColor == "Black");
    assert(colorMap[12].minorColor == "Green");

    assert(colorMap[24].number == 25);
    assert(colorMap[24].majorColor == "Violet");
    assert(colorMap[24].minorColor == "Slate");

    assert(expectedstr == actualstr);
}

int main() {
    
    test_PrintColorMap();
    std::cout << "All is well (maybe!)\n";
    return 0;
}