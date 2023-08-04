#include <iostream>
using namespace std;

// Define a structure to hold array data and the search value
struct ArrayData
{
    int searchValue;   // The value to search for
    int size;          // Size of the array
    int *array;        // Pointer to the array
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

    // Read the search value from the file
    int searchValue;
    fscanf(inputFile, "%d", &searchValue);
    fgetc(inputFile); // Consume the newline character left in the stream

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

    // Print the read search value and array data
    cout << "Successfully read the Search value: " << searchValue << endl;
    cout << "Successfully read array of size: " << size << endl;
    cout << "Array values: ";
    for (int i = 0; i < size; i++)
    {
        cout << myArray[i] << " ";
    }
    cout << endl;

    // Create and return the ArrayData structure containing the search value, the array, and its size
    ArrayData data;
    data.searchValue = searchValue;
    data.size = size;
    data.array = myArray;
    return data;
}
    
// Function to perform binary search on a sorted array
int binarySearch(int searchValue, int size, int array[])
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (array[mid] == searchValue)
        {
            return mid; // Return the index where the value is found
        }
        else if (array[mid] > searchValue)
        {
            right = mid - 1; // Search the left half of the array
        }
        else
        {
            left = mid + 1; // Search the right half of the array
        }
    }

    return -1; // Return -1 if the value is not found in the array
}

int main()
{
    // File containing search value and array data
    string filename = "TestCase3.2.txt";
    
    // Read data from the file and create an array
    ArrayData data = readFileAndCreateArray(filename);
    
    // Perform binary search on the array to find the search value
    int foundIndex = binarySearch(data.searchValue, data.size, data.array);

    // Check if the search value is found and print the result
    if (foundIndex != -1)
        cout << "Value " << data.searchValue << " successfully found at index: " << foundIndex << endl;
    else
        cout << "Value " << data.searchValue << " not found in the array." << endl;

    return 0;
}
