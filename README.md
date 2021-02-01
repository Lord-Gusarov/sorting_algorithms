# Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

* At least four different sorting algorithms
* What is the Big O notation, and how to evaluate the time complexity of an algorithm
* How to select the best sorting algorithm for a given input
* What is a stable sorting algorithm

## Tasks

### 0. Bubble Sort
Write a function that sorts an array of integers in ascending order using the Bubble sort algorithm

* Prototype: void bubble_sort(int \*array, size_t size);
* You’re expected to print the array after each time you swap two elements

Write in the file 0-O, the big O notations of the time complexity of the Bubble sort algorithm, with 1 notation per line:
* in the best case
* in the average case
* in the worst case

### 1. Insertion sort
Write a function that sorts a doubly linked list of integers in ascending order using the Insertion sort algorithm
* Prototype: void insertion_sort_list(listint_t \*\*list);
* You are not allowed to modify the integer n of a node. You have to swap the nodes themselves.
* You’re expected to print the list after each time you swap two elements.

Write in the file 1-O, the big O notations of the time complexity of the Insertion sort algorithm, with 1 notation per line:
* in the best case
* in the average case
* in the worst case

### 2. Selection sort
Write a function that sorts an array of integers in ascending order using the Selection sort algorithm
* Prototype: void selection_sort(int \*array, size_t size);
* You’re expected to print the array after each time you swap two elements.

Write in the file 2-O, the big O notations of the time complexity of the Selection sort algorithm, with 1 notation per line:
* in the best case
* in the average case
* in the worst case

### 3. Quick sort
Write a function that sorts an array of integers in ascending order using the Quick sort algorithm
* Prototype: void quick_sort(int \*array, size_t size);
* You must implement the Lomuto partition scheme.
* The pivot should always be the last element of the partition being sorted.
* You’re expected to print the array after each time you swap two elements 

Write in the file 3-O, the big O notations of the time complexity of the Quick sort algorithm, with 1 notation per line:
* in the best case
* in the average case
* in the worst case

### 4. Shell sort (AKA #100)
Write a function that sorts an array of integers in ascending order using the Shell sort algorithm, using the Knuth sequence
* Prototype: void shell_sort(int \*array, size_t size);
* You must use the following sequence of intervals (a.k.a the Knuth sequence):
	* n+1 = n * 3 + 1
	* 1, 4, 13, 40, 121, ...

* You’re expected to print the array each time you decrease the interval

### 5. Cocktail shaker sort (AKA #101)
Write a function that sorts a doubly linked list of integers in ascending order using the Cocktail shaker sort algorithm
* Prototype: void cocktail_sort_list(listint_t \*\*list);
* You are not allowed to modify the integer n of a node. You have to swap the nodes themselves.
* You’re expected to print the list after each time you swap two elements (See example below)

Write in the file 101-O, the big O notations of the time complexity of the Cocktail shaker sort algorithm, with 1 notation per line:
* in the best case
* in the average case
* in the worst case
