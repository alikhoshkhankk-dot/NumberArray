
#include <iostream>
#include <iomanip>
#include <random>
#include "NumberArray.h"

using namespace std;

int main()
{
    cout << fixed << setprecision(2);

    // Test 1: Default constructor
    cout << "\nTest 1: Default constructor" << endl;

    NumberArray firstArray;

    firstArray.print();
    cout << "Expected: 10 values, all 0.00" << endl;

    // Test 2: Store and read values
    cout << "\nTest 2: Store and read values" << endl;

    NumberArray scores(5);

    scores.setNumber(0, 10.0);
    scores.setNumber(1, 20.0);
    scores.setNumber(2, 30.0);
    scores.setNumber(3, 40.0);
    scores.setNumber(4, 50.0);

    scores.print();

    cout << "First value: " << scores.getNumber(0) << endl;
    cout << "Middle value: " << scores.getNumber(2) << endl;
    cout << "Last value: " << scores.getNumber(4) << endl;

    // Test 3: Statistics
    cout << "\nTest 3: Minimum, maximum, and average" << endl;

    cout << "Minimum: " << scores.getMin() << endl;
    cout << "Maximum: " << scores.getMax() << endl;
    cout << "Average: " << scores.getAverage() << endl;

    cout << "Expected: Min = 10.00, Max = 50.00, Average = 30.00"
        << endl;

    // Test 4: Invalid indexes
    cout << "\nTest 4: Invalid indexes" << endl;

    scores.setNumber(-1, 99.0);
    scores.setNumber(5, 99.0);

    cout << "Value for index -1: " << scores.getNumber(-1) << endl;
    cout << "Value for index 5: " << scores.getNumber(5) << endl;

    // Test 5: Negative, decimal, and zero values
    cout << "\nTest 5: Negative and decimal values" << endl;

    NumberArray mixed(4);

    mixed.setNumber(0, -5.5);
    mixed.setNumber(1, 0.0);
    mixed.setNumber(2, 2.5);
    mixed.setNumber(3, 7.0);

    mixed.print();

    cout << "Minimum: " << mixed.getMin() << endl;
    cout << "Maximum: " << mixed.getMax() << endl;
    cout << "Average: " << mixed.getAverage() << endl;

    cout << "Expected: Min = -5.50, Max = 7.00, Average = 1.00"
        << endl;

    // Test 6: Array with size one
    cout << "\nTest 6: Array size of one" << endl;

    NumberArray oneValue(1);
    oneValue.setNumber(0, 8.5);

    oneValue.print();

    cout << "Minimum: " << oneValue.getMin() << endl;
    cout << "Maximum: " << oneValue.getMax() << endl;
    cout << "Average: " << oneValue.getAverage() << endl;

    // Test 7: Invalid size
    cout << "\nTest 7: Invalid array size" << endl;

    NumberArray invalidSize(0);
    invalidSize.print();

    cout << "Expected: Default size of 10, all values 0.00"
        << endl;

    // Test 8: Random values
    cout << "\nTest 8: Random values" << endl;

    NumberArray randomArray(5);

    random_device rd;
    mt19937 generator(rd());
    uniform_real_distribution<double> distribution(-10.0, 10.0);

    for (int i = 0; i < 5; i++)
    {
        randomArray.setNumber(i, distribution(generator));
    }

    randomArray.print();

    double minimum = randomArray.getMin();
    double maximum = randomArray.getMax();
    double average = randomArray.getAverage();

    cout << "Minimum: " << minimum << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Average: " << average << endl;

    if (minimum <= average && average <= maximum)
    {
        cout << "Random statistics check: PASS" << endl;
    }
    else
    {
        cout << "Random statistics check: FAIL" << endl;
    }

    // Test 9: Destructor for a block-scoped object
    cout << "\nTest 9: Destructor test" << endl;

    {
        NumberArray temporary(3);
        temporary.setNumber(0, 1.0);
        temporary.setNumber(1, 2.0);
        temporary.setNumber(2, 3.0);

        temporary.print();

        cout << "Leaving the block now." << endl;
    }

    cout << "The temporary object has been destroyed." << endl;

    cout << "\nAll tests finished." << endl;

    return 0;
}