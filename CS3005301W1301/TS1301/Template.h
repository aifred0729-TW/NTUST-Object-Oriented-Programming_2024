#pragma once
#include <iostream>

template<class T>
void RBS(const T a[], int first, int last, T key, bool& found, int& location);

template<class T>
void ItrBinarySearch(const T a[], int first, int last, T key, bool& found, int& location) {
    int upper = last;
    int lower = first;
    found     = false;

    while (true) {
        int mid = (upper + lower) / 2;
        if (a[mid] == key) {
            found    = true;
            location = mid;
            break;
        }

        if (upper == lower)
            break;

        if (a[mid] > key) {
            upper = mid - 1;
        } else {
            lower = mid + 1;
        }
    }
}

template<class T>
void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location) {
    found = false;
    RBS(a, first, last, key, found, location);
    return;
}

template<class T>
void RBS(const T a[], int first, int last, T key, bool& found, int& location) {
    int mid = (first + last) / 2;
    if (a[mid] == key) {
        found    = true;
        location = mid;
        return;
    }

    if (first == last)
        return;

    if (a[mid] > key) {
        RecBinarySearch(a, first, mid - 1, key, found, location);
        return;
    }
    RecBinarySearch(a, mid + 1, last, key, found, location);
    return;
}