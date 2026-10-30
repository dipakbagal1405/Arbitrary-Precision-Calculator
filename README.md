# Arbitrary Precision Calculator (Big Number Calculator)

A console-based software calculator implemented in C that performs arithmetic operations on **arbitrarily large integers** (numbers whose sizes exceed the limits of standard primitive data types like `long long int`). This project uses a **Doubly Linked List (DLL)** structure where each node stores a single digit, enabling infinite-precision mathematical computation.

## 🚀 Features
* **Infinite Precision Addition:** Handles numbers with hundreds or thousands of digits using carry-forward logic.
* **Precision Subtraction:** Implements safe mathematical borrow logic with string-based magnitude comparison.
* **Large Multiplication:** Executes digit-by-digit shifting and cumulative list additions.
* **Large Division:** Performs repeated modular wiza-subtraction with active leading-zero cleanups to optimize memory.

## 🛠️ Tech Stack & Key Concepts
* **Language:** C Programming
* **Data Structures:** Doubly Linked Lists (DLL)
* **Key Concepts:** Dynamic Memory Allocation (`malloc`/`free`), Pointers, Bitwise/Arithmetic Simulation, Command Line Arguments (CLA).

## 💻 How to Run
Compile all the implementation files using GCC and provide the mathematical expression through Command Line Arguments:

1. **Compilation:**
   ```bash
   gcc main.c apc.c dll.c validation.c -o apc
   ```

2. **Execution Examples:**
   * **Addition:** `./apc 12345678901234567890 + 98765432109876543210`
   * **Subtraction:** `./apc 100000000000000000000 - 99999999999999999999`
   * **Multiplication:** `./apc 999999999999 '*' 999999999999`
   * **Division:** `./apc 444444444444444444 / 222222222222`
