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
    // Open the file for reading
    FILE *inputFile = fopen(filename.c_str(), "r");

    // Check if the file was successfully opened
    if (!inputFile)
    {
        cerr << "Failed to open the input file." << endl;
        exit(1);
    }

    // Read the size of the array from the file
    int size;
    fscanf(inputFile, "%d", &size);
    fgetc(inputFile); // Consume the newline character left in the stream

    // Create a dynamic array to store the data from the file
    int *myArray = new int[size];

    // Read array elements from the file and store them in the array
    for (int i = 0; i < size; i++)
    {
        fscanf(inputFile, "%d", &myArray[i]);
        if (i < size - 1)
            fgetc(inputFile); // Consume the comma between elements
    }

    // Close the file as we no longer need it
    fclose(inputFile);

    // Print the read array data
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

// Function to perform insertion sort on an array
void performInsertionsSort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i];
        int j = i - 1;
        // Move elements greater than the key to one position ahead of their current position
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key; // Place the key at the correct position in the sorted array
    }
}

// Function to find the median value in a sorted array
int findMedian(int array[], int size)
{
    // Sort the array using insertion sort
    performInsertionsSort(array, size);
    // Return the middle element of the sorted array, which represents the median
    return array[size / 2];
}

int main()
{
    // File containing array data
    string filename = "TestCase4.3.txt";

    // Read data from the file and create an array
    ArrayData data = readFileAndCreateArray(filename);

    // Find the median of the array
    int median = findMedian(data.array, data.size);

    // Print the result
    cout << "Median of the array: " << median << endl;

    // Deallocate the memory allocated for the dynamic array
    delete[] data.array;
    return 0;
}
