#include <iostream>
using namespace std;

// Data structure to hold array size and pointer to the array
struct ArrayData
{
    int size;
    int *array;
};

// Function to read data from a file and create an array
ArrayData readFileAndCreateArray(const string &filename)
{
    // Open the file
    FILE *inputFile = fopen(filename.c_str(), "r");

    // Check if the file was opened successfully
    if (!inputFile)
    {
        cerr << "Failed to open the input file." << endl;
        exit(1); // Exit the program with an error code 1
    }

    // Read the size of the array from the file
    int size;
    fscanf(inputFile, "%d", &size);

    // Consume the newline character left in the stream after reading size
    fgetc(inputFile);

    // Create a dynamic array of the given size
    int *myArray = new int[size];

    // Read the elements of the array from the file
    for (int i = 0; i < size; i++)
    {
        fscanf(inputFile, "%d", &myArray[i]);
        if (i < size - 1)
            fgetc(inputFile); // Consume the comma between elements
    }

    // Close the file as we have finished reading from it
    fclose(inputFile);

    // Display the information about the array
    cout << "Successfully read array of size: " << size << endl;
    cout << "Array values: ";
    for (int i = 0; i < size; i++) {
        cout << myArray[i] << " "; // Print each element of the array
    }
    cout << endl;

    // Create a data structure to hold the array and its size
    ArrayData data;
    data.size = size;
    data.array = myArray;
    return data;
}

// Function to perform Insertion Sort and count the total bribes
int getBribesByInsertionSort(int arr[], int size)
{
    int totalBribes = 0;
    for (int i = 1; i < size; i++)
    {
        int currentValue = arr[i];
        int j = i - 1;
        // Move elements greater than currentValue one position ahead
        while (j >= 0 && arr[j] > currentValue)
        {
            arr[j + 1] = arr[j];
            j--;
            totalBribes++; // Increment the total bribes count
        }
        // Insert the currentValue at the correct position in the sorted part of the array
        arr[j + 1] = currentValue;
    }
    return totalBribes; // Return the total number of bribes
}

int main()
{
    // Specify the file name containing the array data
    string filename = "TestCase1.1.txt";

    // Read the array data from the file and create the array
    ArrayData data = readFileAndCreateArray(filename);

    // Sort the array using Insertion Sort and get the total number of bribes
    int totalBribes = getBribesByInsertionSort(data.array, data.size);

    // Display the total number of bribes required to sort the array
    cout << "Total Bribes : " << totalBribes << endl;

    // Deallocate the memory allocated for the dynamic array
    delete[] data.array;

    return 0; // Return 0 to indicate successful program execution
}
