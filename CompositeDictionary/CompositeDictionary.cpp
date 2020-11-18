// CompositeDictionary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MultiKeyDictionary.cpp"

int main()
{
    MultiKeyDictionary<int, string, int , string> mkDictionary;
    mkDictionary.add(1, "Unity", 0, "Whole");
    mkDictionary.add(2, "Beta", 3, "Gamma");
    mkDictionary.add(3, "Gamma", 4, "Delta");
    mkDictionary.add(4, "Unity", 0, "Whole");
    mkDictionary.remove("Beta", 3, "Gamma");
    mkDictionary.remove("Beta", 5, "Gamma");
    int val1 = mkDictionary.get("Gamma", 4, "Delta");
    int val2 = mkDictionary.get("Unity", 0, "Whole");
    int val3 = mkDictionary.get("Unity", 13, "Whole");
    mkDictionary.print();
    mkDictionary.clear();
    mkDictionary.print();
    return getchar();
}
