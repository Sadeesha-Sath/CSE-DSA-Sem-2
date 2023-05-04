#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int top = root;
   int left = 2 * root + 1;
   int right = 2 * root + 2;

   // If left node is greater than the root
   if (left < n && arr[left] > arr[top])
      top = left;

   // If right node is greater than the root
   if (right < n && arr[right] > arr[top])
      top = right;

   if (top != root)
   {
      int temp = arr[root];
      arr[root] = arr[top];
      arr[top] = temp;
      // Recursively use heapify
      heapify(arr, n, top);
   }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--)
   {
      heapify(arr, n, i);
   }

   // extracting elements from heap one by one
   for (int i = n - 1; i >= 0; i--)
   {
      int temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
      heapify(arr, i, 0);
   }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
   const int MAX = 100;
   int n;
   cout << "Size of heap: ";
   cin >> n;

   int heap_arr[MAX];

   for (int i = 0; i < n; i++)
   {
      cin >> heap_arr[i];
   }

   cout << "Input array" << endl;
   displayArray(heap_arr, n);

   heapSort(heap_arr, n);

   cout << "Sorted array" << endl;
   displayArray(heap_arr, n);
}