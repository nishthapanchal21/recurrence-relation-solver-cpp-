# Universal Recurrence Relation Solver

A C++ console-based application that solves two major types of recurrence relations commonly studied in Design and Analysis of Algorithms (DAA) and Discrete Mathematics. The program supports both algorithm recurrence analysis using the Master Theorem and sequence recurrence solving using the Characteristic Equation method.

---

## Features

### Algorithm Recurrence Solver

- Solves divide-and-conquer recurrences of the form:

```
T(n) = aT(n/b) + f(n)
```

- Displays recursion tree trace
- Simulates total work performed
- Determines Master Theorem case
- Calculates asymptotic time complexity

Supported work functions:

- Constant: `f(n) = 1`
- Linear: `f(n) = n`
- Quadratic: `f(n) = n²`

---

### Sequence Recurrence Solver

Solves recurrence relations of the form:

```
aₙ = A·aₙ₋₁ + B·aₙ₋₂
```

with base cases:

```
a₀ = 0
a₁ = 1
```

Features:

- Characteristic Equation Method
- Calculates nth term
- Supports Fibonacci-like sequences
- Detects Fibonacci recurrence

---

# Technologies Used

- C++
- Standard Template Library (STL)
- Mathematical Functions (`cmath`)
- Console-Based User Interface

---

# Concepts Implemented

## Divide and Conquer

Analyzes recursive algorithms using:

- Number of subproblems
- Division factor
- Additional work function

---

## Master Theorem

Automatically determines:

- Case 1
- Case 2
- Case 3

Outputs the corresponding asymptotic complexity.

---

## Characteristic Equation

Solves second-order linear recurrence relations by:

- Finding characteristic roots
- Computing constants
- Evaluating the nth term

---

## Recursion

Used for:

- Building recursion tree
- Simulating recursive algorithm execution

---

## Mathematical Analysis

Uses:

- Logarithms
- Square roots
- Powers
- Discriminant calculation

---

# Program Structure

```
Universal-Recurrence-Solver/
│
├── main.cpp
└── README.md
```

---

# Menu Options

```
1. Algorithm Recurrence (Master Theorem)

2. Sequence Recurrence
   (Fibonacci and similar)

3. Exit
```

---

# Algorithm Recurrence Solver

Input:

- Problem size (n)
- Number of subproblems (a)
- Division factor (b)
- Work function

Example:

```
T(n) = 2T(n/2) + n
```

Output:

- Recursion Tree
- Total Simulated Work
- n^(log_b a)
- Master Theorem Case
- Time Complexity

Example Result:

```
Case 2

T(n) = Θ(n log n)
```

---

# Sequence Recurrence Solver

Input:

```
A
B
n
```

Example:

```
aₙ = aₙ₋₁ + aₙ₋₂
```

Output:

```
a(10) = 55
```

Automatically identifies the Fibonacci sequence when:

```
A = 1
B = 1
```

---

# Sample Execution

```
=============================================
UNIVERSAL RECURRENCE RELATION SOLVER
=============================================

1. Algorithm Recurrence
2. Sequence Recurrence
3. Exit

Enter your choice:
```

---

# Learning Outcomes

This project demonstrates:

- Recursion
- Divide and Conquer
- Master Theorem Analysis
- Characteristic Equation Method
- Time Complexity Analysis
- Mathematical Programming
- Console-Based Application Development
- Algorithm Analysis

---

# Applications

- Design and Analysis of Algorithms
- Discrete Mathematics
- Competitive Programming
- Algorithm Complexity Analysis
- Educational Demonstrations
- Recurrence Relation Solving

---

# Future Improvements

- Support custom work functions
- Graphical visualization of recursion trees
- Handle higher-order recurrence relations
- Export recursion tree to file
- Interactive complexity comparison
- Support dynamic programming recurrence analysis
- Performance visualization using graphs

---

# How to Compile

Using g++:

```bash
g++ main.cpp -o recurrence_solver
```

---

# How to Run

Windows:

```bash
recurrence_solver.exe
```

Linux/macOS:

```bash
./recurrence_solver
```
