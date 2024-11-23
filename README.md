# C-Data-Structures

## rot13.c | String Operations

Rot-13 (rotate-13) is a simple substitution cipher that shifts each letter 13 positions forward or backward in the alphabet. For example, A becomes N, M becomes Z, N becomes A, and Z becomes M. Since 13 is half the number of letters in the alphabet, applying rot-13 twice restores the original text.

#### Usage

```bash
$ ./rot13 Hello
Uryyb

$ ./rot13 Uryyb
Hello

$ ./rot13 ebg13
rot13

$ ./rot13 ""
$ ./rot13 "Awesome Power!"
Njrfbzr Cbjre!

$ ./rot13 erzrzore\ gung\ gur\ furyy\ cebprffrf\ lbhe\ fgevat\ svefg
remember that the shell processes your string first
```

## sort.c | String Operations

sort takes one or more arguments, sorts them lexicographically, and prints each argument on a new line. If no arguments are provided, it exits without printing anything. Sorting is done using ASCII comparison (e.g., ‘Z’ comes before ‘a’).

#### Usage

```bash
$ ./sorta foo bar baz quuz
bar
baz
foo
quux

$ ./sorta aaa aAa AaA AAA
AAA
AaA
aAa
aaa

$ ./sorta 3 20 100
100
20
3

$ ./sorta " z" a
z
a
```

## sudoku.c | Checking sudoku solutions

sudoku checks if a proposed Sudoku solution is correct and verifies whether a partially-solved Sudoku puzzle with up to two unknown squares can be solved. A Sudoku puzzle consists of a 9x9 matrix of digits 1–9, arranged in nine 3x3 subgrids. A correct solution satisfies the following conditions:
	•	Each digit occurs exactly once in each row, column, and subgrid.

The program also checks if an almost-completed puzzle (with unknown entries) can be solved.

#### Correctness Checking

For a completed Sudoku puzzle, the program verifies if the solution is correct.

```
534678912
672195348
198342567
859761423
426853791
713924856
961537284
287419635
345286179
```

When given such a file, sudoku must determine whether the completed puzzle is a correct solution (meaning it satisfies the three properties). If so, it prints correct. Otherwise, it prints incorrect. If the input file does not exist, is not readable, or does not follow the format specified here, sudoku prints error.

#### Usage

```bash
$ ./sudoku file1.txt
correct
```

#### Solvability Checking

For an almost-completed Sudoku puzzle, the program determines if the puzzle is solvable.

```
435269781
682571493
1978345 2
826195347
374682915
951743628
519 26874
248957136
763418259
```

If the input file contains an almost-completed puzzle, sudoku must determine whether the puzzle can be solved. If the puzzle has unspecified entries, can they be replaced by a digits such that the completed puzzle is a correct solution? If so, sudoku prints solvable. Otherwise, it prints unsolvable. If the puzzle contains no unspecified entries (that is, it is a completed puzzle), sudoku will print correct or incorrect as before.

If the input file does not exist, is not readable, does not follow the format specified above, or contains more than two unspecified elements, sudoku prints error.

#### Usage

```bash
$ ./sudoku file2.txt
solvable
```

## list.c | Linked List Implementation

list manages a sorted linked list and performs operations based on commands read from standard input. The list maintains elements in increasing numeric order after each operation.

#### Operations

- **insert** n: Adds an integer n to the list, if not already present.
- **delete** n: Removes an integer n from the list if present.

#### Usage 

```bash
$ ./list
i 5
1 : 5

d 3
1 : 5

i 3
2 : 3 5

i 500
3 : 3 5 500

d 5
2 : 3 500

^D  # To terminate input
```

Alternatively, you may use input redirection to send the contents of a file to list. For example, assume list_commands.txt contains this text:

```
i 10
i 11
i 9
d 11
```

Then we may send this file to list as its input like so:

```bash
$ ./list < list_commands.txt
1 : 10
2 : 10 11
3 : 9 10 11
2 : 9 10
```

## mexp.c | Matrix Exponentiation

mexp multiplies a square matrix by itself n times. The program reads a matrix from a file and computes the result of matrix exponentiation. It handles non-static matrix sizes and uses dynamic memory allocation.

#### Usage

```bash
$ ./mexp file1.txt
30 36 42
66 81 96
102 126 150
```

## bst.c | Binary Search Tree Implementation

bst manipulates binary search trees (BST) and handles various commands for insertion, deletion, search, and printing of the tree structure.

#### Commands

- **insert** n: Adds a value n to the tree if not already present.

- **search** n: Searches for a value n in the tree.

- **print**: Prints the current tree structure.

- **delete** n: Removes a value n from the tree.

#### Usage

```bash
$ ./bst
i 1
inserted

i 2
inserted

i 1
not inserted

s 3
absent

p
(1(2))

^D
```

#### Printing nodes

An empty tree (that is, NULL) is printed as an empty string. A node is printed as a (, followed by the left sub-tree, the item for that node, the right subtree, and ), without spaces.

#### Deleting nodes

- **No children**: Simply removes the node.

- **One child**: Replaces the node with its child.

- **Two children**: Replaces the node with the maximum value from its left subtree, then deletes the original node.

Note that the root node could also be deleted.
