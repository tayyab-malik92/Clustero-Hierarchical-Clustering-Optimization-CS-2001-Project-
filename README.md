# Clustero-Hierarchical-Clustering-Optimization-CS-2001-Project-
A comparative study and implementation of Agglomerative Hierarchical Clustering in C++. This project solves the problem of grouping $N$ spatial points into $M$ clusters using two distinct computational strategies to analyze performance trade-offs.

# Clustero: Hierarchical Clustering Optimization

A comparative study and implementation of **Agglomerative Hierarchical Clustering** in C++. This project solves the problem of grouping $N$ spatial points into $M$ clusters using two distinct computational strategies.

## Project Structure
*   **Q1: Basic Clustering (Brute Force):** Implemented using a standard distance matrix approach.
*   **Q2: Efficient Clustering (Heap-Optimized):** A high-performance version utilizing a **Custom Min-Heap** data structure to optimize distance management.

## Key Features
*   **Custom Heap Implementation:** Manual `MinHeap` class with `heapifyUp`, `heapifyDown`, and `indexMap`.
*   **Spatial Analytics:** Euclidean distance formulas for point proximity.
*   **Dynamic Grouping:** Optimized cluster merging using `std::list`.

## How to Run
1. Compile either `Q1.cpp` or `Q2.cpp` using a C++ compiler (e.g., g++).
2. Run the executable and follow the on-screen prompts for N (points) and M (target groups).
