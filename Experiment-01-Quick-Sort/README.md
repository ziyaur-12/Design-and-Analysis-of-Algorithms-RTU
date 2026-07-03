# Experiment 01 - Quick Sort Algorithm

## Aim

Sort a given set of elements using the Quick Sort algorithm and determine the time required to sort the elements. Repeat the experiment for different values of **n** and plot a graph of the time taken versus **n**.

---

## Objective

To study and implement the Quick Sort algorithm and analyze its execution time for sorting a list of elements.

---

## Theory

Quick Sort is a Divide and Conquer algorithm.

It works by selecting a pivot element and partitioning the array into two parts:

- Elements smaller than pivot
- Elements greater than pivot

The same process is recursively applied to both subarrays.

Average Time Complexity:

- Best Case : **O(n log n)**
- Average Case : **O(n log n)**
- Worst Case : **O(n²)**

Space Complexity:

- **O(log n)**

---

## Algorithm

1. Select the last element as Pivot.
2. Partition the array.
3. Place pivot at correct position.
4. Apply Quick Sort recursively on left subarray.
5. Apply Quick Sort recursively on right subarray.
6. Print sorted array.

---

## Files Included

- **main.cpp** – Quick Sort implementation
- **input.txt** – Input dataset
- **README.md** – Project documentation

---

## Input

The input values are stored in **input.txt**.

Example:

```text
45
12
67
89
23
11
90
54
```

---

## Output

The program displays:

- Original data
- Sorted data
- Execution time in microseconds

---

## Requirements

- C++ Compiler
- VS Code / CodeBlocks / Dev C++
- g++

---

## How to Run

Compile

```bash
g++ main.cpp -o quicksort
```

Run

```bash
./quicksort
```

Windows

```bash
quicksort.exe
```

---

## Applications

- Database Sorting
- Search Algorithms
- Data Processing
- Competitive Programming
- System Software

---

## Advantages

- Very Fast
- Efficient for large datasets
- In-place sorting
- Widely used

---

## Limitations

- Worst-case complexity O(n²)
- Recursive implementation

---

## Result

The Quick Sort algorithm was successfully implemented using C++. The input data was sorted correctly, and the execution time was measured successfully.

---

## Keywords

Analysis of Algorithms, Quick Sort, Divide and Conquer, C++, RTU Lab, DAA Lab, Sorting Algorithm