# Push Swap

This project requires you to sort data on a stack using a limited set of instructions, with the goal of minimizing the number of actions. To succeed, you will need to manipulate various types of algorithms and choose the most appropriate solution from among many options for optimized data sorting.

## Overview

Push_swap is an algorithm project at School 42. I’ve successfully completed it with a full score of 100/100, and I’ll explain how I achieved it.

## Introduction

You start with two empty stacks: `a` and `b`. A random list of integers is provided via command line arguments. The goal is to sort the integers in ascending order in stack `a`, using a limited set of operations, while leaving stack `b` empty.

## Operations

You can only use the following operations:

| Code  | Instruction                         | Action                                                     |
|-------|-------------------------------------|------------------------------------------------------------|
| `sa`  | swap a                              | Swap the first 2 elements at the top of stack `a`.          |
| `sb`  | swap b                              | Swap the first 2 elements at the top of stack `b`.          |
| `ss`  | swap a + swap b                     | Perform `sa` and `sb` simultaneously.                      |
| `pa`  | push a                              | Move the top element of stack `b` to the top of stack `a`.  |
| `pb`  | push b                              | Move the top element of stack `a` to the top of stack `b`.  |
| `ra`  | rotate a                            | Shift all elements of stack `a` up by 1.                    |
| `rb`  | rotate b                            | Shift all elements of stack `b` up by 1.                    |
| `rr`  | rotate a + rotate b                 | Perform `ra` and `rb` simultaneously.                      |
| `rra` | reverse rotate a                    | Shift all elements of stack `a` down by 1.                  |
| `rrb` | reverse rotate b                    | Shift all elements of stack `b` down by 1.                  |
| `rrr` | reverse rotate a + reverse rotate b | Perform `rra` and `rrb` simultaneously.                    |

## The Turk Algorithm

The Turk Algorithm is the approach I used to solve the problem. It is named after the Mechanical Turk, reflecting its hard-coded and unelegant nature. Here's a step-by-step explanation of the algorithm:

### Getting Started

1. **Push elements from a to b if their value is below the average**: This approach simplifies the final sorting step since elements below the average are moved first, allowing for more efficient sorting of the remaining elements in a.

2. **Stack behavior**: Treat stacks as circular linked lists. The last element is just before the first element.

3. **Positioning numbers**:
   - If the number being pushed to `b` is the new minimum or maximum, place it above the current maximum in `b`.
   - If it's neither, find the correct position manually.

4. **Magic number 3**: If the stack size is three, it requires minimal operations to sort, usually one or two.

5. **Optimize rotations**: Instead of rotating `a` and `b` separately, find the least common number of rotations to minimize operations.

### Detailed Steps

1. **Initial Push**:
   - Push two numbers from `a` to `b` to establish an initial state for comparisons.

2. **Find the cheapest number**:
   - For each number in `a`, calculate the number of operations required to place it in the correct position in `b`.
   - Push the number requiring the fewest operations.

3. **Final Steps for Three Elements**:
   - When only three elements are left in `a`, sort them directly.

4. **Push back to `a`**:
   - Push elements from `b` to `a`, ensuring they are placed in the correct position in `a`.

5. **Final Arrangement**:
   - Rotate `a` to bring the smallest number to the top, completing the sort.

## Example Execution

An example of sorting a stack of 10 elements is provided in the algorithm description above.

## Performance

My implementation achieves the following:

- 3 numbers with a maximum of 3 instructions
- 4 numbers with a maximum of 7 instructions
- 5 numbers with a maximum of 11 instructions
- 100 numbers with a maximum of 600 instructions
- 500 numbers with a maximum of 5100 instructions

The algorithm is efficient enough to pass the project with a full score.

## Conclusion

Understanding and implementing this algorithm will help you achieve a perfect score on the Push_swap project at School 42. Feel free to explore the code and the detailed explanation provided above.
