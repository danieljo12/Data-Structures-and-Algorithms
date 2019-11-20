#include <iostream>

using namespace std;

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, minNum;

	for (i = 0; i < n - 1; i++)
	{
		// assigns the inner loop `i` value to minNum
		minNum = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[minNum])
				minNum = j;



			// Swaps the minmiun value found to array element of `i` 
			if (minNum != i) {
				swap(&arr[minNum], &arr[i]);
				//cout << "swapredd ";
			}
			cout << arr[i] << ", " << i << "ddd ";
		}
		cout << " out ";
	}
	cout << "end\n";
}

// Driver program to test above functions  
int main()
{
	//             0   1   2   3   4
	int arr[] = { 11, 44, 33, 55, 22 };
	int n = sizeof(arr) / sizeof(arr[0]);
	selectionSort(arr, n);
	cout << "Sorted array: \n";

	for (int i : arr) {
		cout << i << ", ";
	}

	return 0;
}

/*
SELECTION SORT

O(n^2) as there are two nested loops.

*/
