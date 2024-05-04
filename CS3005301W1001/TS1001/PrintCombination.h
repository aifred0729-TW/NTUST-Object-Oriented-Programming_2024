#pragma once
#include <iostream>
#include <vector>

void recursiveSort(int* arrayPtr, std::vector<int>& numbers, int eCount, int numSize, int index, int nIndex);

void PrintCombination(int* arrayPtr, int eCount, int numSize) {
	using namespace std;

    vector<int> numbers;

    for (unsigned int i = 0; i < numSize; i++) {
        numbers.push_back(arrayPtr[i]);
    }
    recursiveSort(arrayPtr, numbers, eCount, numSize, numSize-1, numSize);
}

void recursiveSort(int* arrayPtr, std::vector<int>& numbers, int eCount, int numSize, int index, int nIndex) {
    using namespace std;

    for (unsigned int i = 0; i < numSize - 1; i++) {
        cout << numbers[i] << ' ';
    }
    cout << numbers[numSize - 1] << endl;

    if (numbers[0] == arrayPtr[eCount - numSize]) return;
    numbers[index] = arrayPtr[nIndex];

    if (numbers[index] < arrayPtr[eCount - (numSize - index)]) {
        recursiveSort(arrayPtr, numbers, eCount, numSize, index, nIndex + 1);
        return;
    }
    else if (index != 0){
        recursiveSort(arrayPtr, numbers, eCount, numSize, index - 1, numbers[index-1]);
        return;
    }
    recursiveSort(arrayPtr, numbers, eCount, numSize, 0, 0);
    return;
}