#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

// helper function to initialize all arrays
void initialize(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % (2 * size);
	}
}

// helper function to display arrays
void display(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

/*************************************
Bubble Sort
/*************************************/

// bubble sort implementation
void bubbleSort(int arr[], int size) {
	
	int temp;
	//for loops to find the next larger element and swap those two indices
	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size - i - 1; j++) {

			// check if element is bigger than next
			if (arr[j] > arr[j + 1]) {

				// swap values
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

/*************************************
Insertion Sort
/*************************************/

// insertion sort implementation
void insertionSort(int arr[], int size) {
	// initialize variable
	int j, temp;

	// loop through array
	for (int i = 1; i < size; i++) {
		j = i;

		while ((j > 0) && (arr[j - 1] > arr[j])) {
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}
}

/*************************************
Merge Sort
/*************************************/

//function definition of merge()
void merge(int *myArr, int *left, int numL, int *right, int numR) {
	// i and j are used as indexes for left and right resp.
	// k is used as a tracker index for the main array
	int leftIndex = 0,
		rightIndex = 0,
		k = 0;

	//while loop to execute till all elements of either left or right array are compared
	while (leftIndex<numL && rightIndex<numR) {
		//compare the elements of left with right and 
		// assign the lower value to myArray
		if (left[leftIndex] < right[rightIndex]) {
			myArr[k] = left[leftIndex];
			leftIndex++;
		}
		else {
			myArr[k] = right[rightIndex];
			rightIndex++;
		}
		k++;
	}

	//After all values in left or right are compared,
	//we compare for the remaining values in the other array
	while (leftIndex<numL) {
		myArr[k] = left[leftIndex];
		leftIndex++;
		k++;
	}
	while (rightIndex<numR) {
		myArr[k] = right[rightIndex];
		rightIndex++;
		k++;
	}
}

//function definiton for mergeSort array
void mergeSort(int *myArr, int size) {

	//return the element if array size is 1
	if (size < 2) return;

	//determine midpoint of the array	
	int mid = size / 2;

	//declare arrays left and right to hold the two sections of the parent array
	int *left = new int[mid];
	int *right = new int[size - mid];

	//loop to insert values in left 
	for (int i = 0; i < mid; i++) {
		left[i] = myArr[i];
	}

	//loop to insert values in right
	for (int i = mid; i < size; i++) {
		right[i - mid] = myArr[i];
	}

	//call the mergeSort() function recursively to sort the sub arrays, left and right
	mergeSort(left, mid);
	mergeSort(right, size - mid);

	//once the main array has been broken 
	//down into the smallest possible sub-arrays,
	//call the merge function
	merge(myArr, left, mid, right, size - mid);

	//free up memory, after the arrays are merged
	delete(left);
	delete(right);
}

/*************************************
Quicksort Sort
/*************************************/
//divide() function which to sort the array with 
//smaller value items to the left of the pivot and 
//larger items to the right
int divide(int *myArr, int start, int end) {
	int divideIndex = start;

	//assign rightmost element as the pivot
	int focus = myArr[end];

	//loop to look for elements smaller than the 
	//pivot/focus and swap them to the divide index
	for (int i = start; i < end; i++) {
		if (myArr[i] <= focus) {
			swap(myArr[i], myArr[divideIndex]);
			divideIndex++;
		}
	}
	//swap the last index to the divide index
	swap(myArr[divideIndex], myArr[end]);
	return divideIndex;
}

//defintion of quickSort() 
void quickSort(int *myArr, int start, int end) {
	if (start < end) {

		int divideIndex = divide(myArr, start, end);
		//call quickSort() recursively till the divided parts of the array are sorted
		quickSort(myArr, start, divideIndex - 1);
		quickSort(myArr, divideIndex + 1, end);
	}
}

/*************************************
Counting Sort
/*************************************/
void countingSort(int arrA[], int size) {
	// calculate max key value
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (arrA[i] > max) {
			max = arrA[i];
		}
	}

	// creates new array to hold counts
	// initialized to zero
	int *arrC = new int[max]();


}

/*************************************/
/*************************************/

int main() {

	srand(time(NULL));

	// declare all arrays
	int arr10[10], arr100[100], arr500[500], arr5000[5000], arr25000[25000];
	
	// initialize all arrays
	initialize(arr10, 10);
	initialize(arr100, 100);
	initialize(arr500, 500);
	initialize(arr5000, 5000);
	initialize(arr25000, 25000);
	
	cout<<" Before Sort";
	display(arr10, 10);
	mergeSort(arr10, 10);
	//quickSort(arr10, 0, 9);
	cout<<"After Sort";
	display(arr10, 10);
	return 0;


}

