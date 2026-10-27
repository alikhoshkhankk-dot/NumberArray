
#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

#include <iostream>

class NumberArray
{
private:
    static const int MAX_SIZE = 10;
    static constexpr double SAFE_DEFAULT = 0.0;

    int size;
    double* data;

public:
    // Creates an array and initializes all values to 0.0.
    // If the requested size is invalid, uses MAX_SIZE.
    NumberArray(int size = MAX_SIZE);

    // Releases the dynamically allocated array.
    ~NumberArray();

    // Stores a value if the index is valid.
    void setNumber(int index, double value);

    // Returns a value, or SAFE_DEFAULT for an invalid index.
    double getNumber(int index) const;

    // Calculates the smallest current value.
    double getMin() const;

    // Calculates the largest current value.
    double getMax() const;

    // Calculates the current average.
    double getAverage() const;

    // Prints all values in the array.
    void print() const;
};

#endif#pragma once
