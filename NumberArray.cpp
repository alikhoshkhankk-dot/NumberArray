
#include "NumberArray.h"
#include <iostream>
using namespace std;

// Constructor
NumberArray::NumberArray(int requestedSize)
{
    if (requestedSize <= 0)
    {
        size = MAX_SIZE;
    }
    else
    {
        size = requestedSize;
    }

    data = new double[size];

    for (int i = 0; i < size; i++)
    {
        data[i] = 0.0;
    }
}

// Destructor
NumberArray::~NumberArray()
{
    delete[] data;
    cout << "NumberArray memory released." << endl;
}

// Store a number at a valid index
void NumberArray::setNumber(int index, double value)
{
    if (index >= 0 && index < size)
    {
        data[index] = value;
    }
    else
    {
        cout << "Invalid index. Value was not stored." << endl;
    }
}

// Return a number at a valid index
double NumberArray::getNumber(int index) const
{
    if (index >= 0 && index < size)
    {
        return data[index];
    }

    cout << "Invalid index. Returning 0.0." << endl;
    return SAFE_DEFAULT;
}

// Find the smallest number
double NumberArray::getMin() const
{
    double smallest = data[0];

    for (int i = 1; i < size; i++)
    {
        if (data[i] < smallest)
        {
            smallest = data[i];
        }
    }

    return smallest;
}

// Find the largest number
double NumberArray::getMax() const
{
    double largest = data[0];

    for (int i = 1; i < size; i++)
    {
        if (data[i] > largest)
        {
            largest = data[i];
        }
    }

    return largest;
}

// Calculate the average
double NumberArray::getAverage() const
{
    double total = 0.0;

    for (int i = 0; i < size; i++)
    {
        total += data[i];
    }

    return total / size;
}

// Print all numbers
void NumberArray::print() const
{
    cout << "Array values: ";

    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }

    cout << endl;
}