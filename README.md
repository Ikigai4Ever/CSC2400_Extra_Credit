# CSC2400_Extra_Credit

## Overview

This C++ program demonstrates a classic **decrease-and-conquer** algorithm by using recursion to find the maximum value in a user-defined array.

The goal is to teach students how recursive algorithms reduce the size of a problem step-by-step and then build the solution back up while unwinding the recursive calls.

---

## How It Works

1. **User Input**  
   The user enters a row of comma-separated integers (e.g., `3,5,2,9,1,8,0,2`).  
   The program parses this input and stores it in a dynamically allocated array.

2. **Recursive Maximum Search**  
   The program then calls `recusiveMaxFind`, a recursive function that finds the maximum value in the array.

3. **Trace Table Output**  
   While running, the program prints a table showing:
   - The current size of the array being evaluated
   - The current maximum value found
   - A comparison between values
   - Whether the comparison result was `TRUE` or `FALSE`

4. **Complication of Program**  
   For quick complication of the program, users can use the online complier [Programiz](https://www.programiz.com/cpp-programming/online-compiler/). The link is available when highlighting the work on this README.
   
   Simply copy the program code (main.cpp) that is available on this repository into the main.cpp section on [Programiz](https://www.programiz.com/cpp-programming/online-compiler/) and click the `Run` button on the screen to compile and use the program. 


---

## Decrease and Conquer Strategy

### 🡇 Decrease Phase
- Each recursive call reduces the problem size by 1 (`elements - 1`).
- The recursion continues until only one element remains.

### ⛔ Base Case
- When only one element is left, it's returned as the initial maximum.
- This is the stopping point of recursion.

### 🡅 Conquer Phase
- As each recursive call returns, it compares the current element to the previously found maximum.
- The maximum is updated if necessary, and the comparison is printed for clarity.

---

## Educational Purpose

This project visually and functionally demonstrates how recursion can be used to:
- Break down a problem (decrease)
- Solve smaller subproblems
- Build the solution back up as recursive calls return (conquer)

It is especially useful for students new to recursion or algorithmic thinking.

---

## Sample Output Table
     __________________________________________________
    | SIZE | MAX VALUE | COMPARISON | VALID COMPARISON | 
       1        3         3 > N/A           N/A 
       2        3         3 > 5             FALSE 
       3        5         5 > 2             TRUE 
       4        5         5 > 9             FALSE 
       5        9         9 > 1             TRUE 
       6        9         9 > 8             TRUE 
       7        9         9 > 0             TRUE 
       8        9         9 > 2             TRUE 
    |              FINISHED RECURSION                  | 
    |__________________________________________________|

## Authors
- Ty Ahrens  
- Blake Hudson

## Citations: 

“I want to take in a set of numbers like this: 3, 5, 2, 9, 1, 8, 0, 2 and make sure to read only the numbers from the string.” prompt. ChatGPT, 13 Feb. version 4.0, OpenAI, 29 Apr. 2025, chat.openai.com/chat.

“How does my recursiveMaxFind algorithm look?” prompt. ChatGPT, 13 Feb. version 4.0, OpenAI, 29 Apr. 2025, chat.openai.com/chat.

“Create a README.md file that I can use to describe the how this program operates.” prompt. ChatGPT, 13 Feb. version 4.0, OpenAI, 29 Apr. 2025, chat.openai.com/chat.