#include <iostream>
using namespace std;

// Define a structure to hold array data
struct ArrayData
{
    int size;   // Size of the array
    int *array; // Pointer to the array
};

// Function to read data from a file and create an array
ArrayData readFileAndCreateArray(const string &filename)
{
    FILE *inputFile = fopen(filename.c_str(), "r");

    if (!inputFile)
    {
        cerr << "Failed to open the input file." << endl;
        exit(1);
    }

    int size;
    fscanf(inputFile, "%d", &size);
    fgetc(inputFile); // Consume the newline character left in the stream

    int *myArray = new int[size];

    // Read data from the file and store it in the array
    for (int i = 0; i < size; i++)
    {
        fscanf(inputFile, "%d", &myArray[i]);
        if (i < size - 1)
            fgetc(inputFile); // Consume the comma
    }

    fclose(inputFile);

    // Print the array data
    cout << "Successfully read array of size: " << size << endl;
    cout << "Array values: ";
    for (int i = 0; i < size; i++)
    {
        cout << myArray[i] << " ";
    }
    cout << endl;

    // Create and return the ArrayData structure containing the array and its size
    ArrayData data;
    data.size = size;
    data.array = myArray;
    return data;
}

// Function to find the maximum number of consecutive overtime days
int findMaxConsecutiveOvertimeDays(const int *arr, int size, int dailyWorkingHours)
{
    int maxConsecutiveOverTimeDays = 0;
    int currentConsecutiveOverTimeDays = 0;

    // Traverse the array to find the maximum consecutive overtime days
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > dailyWorkingHours)
        {
            currentConsecutiveOverTimeDays++;
        }
        else
        {
            // Reset the count if working hours are less than or equal to the daily working hours
            maxConsecutiveOverTimeDays = max(maxConsecutiveOverTimeDays, currentConsecutiveOverTimeDays);
            currentConsecutiveOverTimeDays = 0;
        }
    }

    // Check for consecutive working hours at the end of the array
    maxConsecutiveOverTimeDays = max(maxConsecutiveOverTimeDays, currentConsecutiveOverTimeDays);
    return maxConsecutiveOverTimeDays;
}

int main()
{
    // File containing employee working hours data
    string filename = "TestCase2.5.txt";

    // Read data from the file and create an array
    ArrayData data = readFileAndCreateArray(filename);

    // Set the daily working hours for the employee
    int dailyWorkingHours = 6;

    // Find the maximum consecutive overtime days for the employee
    int maxConsecutiveOvertimeDays = findMaxConsecutiveOvertimeDays(data.array, data.size, dailyWorkingHours);

    // Print the result
    cout << "Maximum Consecutive Overtime Days of this employee : " << maxConsecutiveOvertimeDays << endl;

    // Deallocate the memory allocated for the dynamic array
    delete[] data.array;
    
    return 1;
}
