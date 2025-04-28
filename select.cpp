#include <iostream>
using namespace std;

// Function to perform selection sort
void selectionSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int minIndex = i;
    // Find the minimum element in the unsorted part of the array
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[minIndex])
      {
        minIndex = j;
      }
    }
    // Swap the found minimum element with the first element
    swap(arr[i], arr[minIndex]);
  }
}

// Function to print the array
void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  int n;
  cout << "Enter number of elements: ";
  cin >> n;
  int arr[n];

  cout << "Enter the elements: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  // Sort the array
  selectionSort(arr, n);

  // Print the sorted array
  cout << "Sorted array: ";
  printArray(arr, n);

  return 0;
}
