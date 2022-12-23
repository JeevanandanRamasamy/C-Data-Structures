# C-Data-Structures

## rot13.c | String Operations

Rot-13 (rotate-13) is a simple substitution cipher, in which each letter is encoded by the letter appearing 13 places later (or earlier) in the alphabet. Thus, A becomes N, M becomes Z, N becomes A, and Z becomes M. Because 13 is half the number of letters in the alphabet, we use the same substitution for ciphering and deciphering. That is, applying rot-13 twice to a text yields the original text.

#### Usage

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

## sort.c | String Operations

sort takes zero or more arguments, sorts them lexicographically, and then prints each argument on its own line.

If sorta receives no arguments, it exits without printing anything.

sort is based on ASCII comparison of characters (so ‘Z’ comes before ‘a’)

#### Usage

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

## sudoku.c | Checking sudoku solutions

sudoku checks whether a proposed Sudoku solution is correct and checks whether a partially-solved Sudoku puzzle with up to two unknown square can be solved.

A completed Sudoku puzzle is a 9 ×9 matrix containing the digits 1–9, inclusive. The matrix is divided into nine 3 ×3 submatrixes, themselves arranged in a 3 ×3 square. A completed Sudoku puzzle is a correct solution if and only if it has the following properties:

- Each digit occurs exactly once in each row (that is, no row contains any digit more than once.

- Each digit occurs exactly once in each column.

- Each digit occurs exactly once in each submatrix.

An almost-completed Sudoku puzzle is similar, except that one or two elements are unspecified.

#### Correctness Checking

The input file should contain a completed Sudoku puzzle. The puzzle is given on nine lines, each of which contains nine digits without any separation. Note that the digit 0 will not occur. The input file file1.txt corresponding to the puzzle above would contain:

534678912

672195348

198342567

859761423

426853791

713924856

961537284

287419635

345286179

When given such a file, sudoku must determine whether the completed puzzle is a correct solution (meaning it satisfies the three properties). If so, it prints correct. Otherwise, it prints incorrect. If the input file does not exist, is not readable, or does not follow the format specified here, sudoku  prints error.

#### Usage

$ ./sudoku file1.txt

correct

#### Solvability Checking

The input file contains an almost-completed Sudoku puzzle. The format is the same as above—nine lines with nine characters each—except that up to two of the characters may be spaces instead of digits. The spaces indicate that the digit for that element is unspecified. The input file file2.txt contains an almost-completed puzzle with two unknown entries:

435269781

682571493

1978345 2

826195347

374682915

951743628

519 26874

248957136

763418259

If the input file contains an almost-completed puzzle, sudoku must determine whether the puzzle can be solved. If the puzzle has unspecified entries, can they be replaced by a digits such that the completed puzzle is a correct solution? If so, sudoku prints solvable. Otherwise, it prints unsolvable. If the puzzle contains no unspecified entries (that is, it is a completed puzzle), sudoku will print correct or incorrect as before.

If the input file does not exist, is not readable, does not follow the format specified above, or contains more than two unspecified elements, sudoku prints error.

#### Usage

$ ./sudoku file2.txt

solvable

## list.c | Linked List Implementation

list maintains and manipulates a sorted linked list according to instructions received from standard input. The linked list is maintained in order, meaning that the items in the list are stored in increasing numeric order after every operation.

list will allocate space for new nodes as they are created, using malloc; any allocated space is deallocated using free as soon as it is no longer needed.

Note that the list will not contain duplicate values.

list supports two operations:

**insert** n Adds an integer n to the list. If n is already present in the list, it does nothing. The instruction format is an i followed by a space and an integer n.

**delete** n Removes an integer n from the list. If n is not present in the list, it does nothing. The instruction format is a d followed by a space and an integer n.

After each command, list will print the length of the list followed by the contents of the list, in order from first (least) to last (greatest).

list halts once it reaches the end of standard input.

**Input format** Each line of the input contains an instruction. Each line begins with a letter (either “i” or “d”), followed by a space, and then an integer. A line beginning with “i” indicates that the integer should be inserted into the list. A line beginning with “d” indicates that the integer should be deleted from the list.

**Output format** After performing each instruction, list will print a single line of text containing the length of the list, a colon, and the elements of the list in order, all separated by spaces.

Because list reads from standard input, you may test it by entering inputs line by line
from the terminal.

#### Usage 

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

^D

To terminate your session, type Control-D at the beginning of the line. (This is indicated here by the sequence ^D.) This closes the input stream to list, as though it had reached the end of a file.

Alternatively, you may use input redirection to send the contents of a file to list. For example, assume list_commands.txt contains this text:

i 10

i 11

i 9

d 11

Then we may send this file to list as its input like so:

$ ./list < list_commands.txt

1 : 10

2 : 10 11

3 : 9 10 11

2 : 9 10

## mexp.c | Matrix Exponentiation

mexp multiplies a square matrix by itself a specified number of times. mexp takes a single argument, which is the path to a file containing a square (k ×k) matrix M and a non-negative exponent n. It computes M nand prints the result.

Since the size of the matrix is not known statically, mexp uses malloc to allocate space for the matrix once its size is obtained from the input file.

To compute M^n, it is sufficient to multiply M by itself n − 1 times. That is, M^3 = M × M × M.

Naturally, a different strategy is needed for M^0.

**Input format** The first line of the input file contains an integer k. This indicates the size of the matrix M, which has k rows and k columns.

The next k lines in the input file contain k integers. These indicate the content of M. Each line corresponds to a row, beginning with the first (top) row.

The final line contains an integer n. This indicates the number of times M will be multiplied by itself. n must be non-negative.

For example, an input file file.txt containing

3

1 2 3

4 5 6

7 8 9

2

indicates that mexp must compute the square of the matrix

1 2 3

4 5 6

7 8 9

**Output format** The output of mexp is the computed matrix M^n. Each row of M^n is printed on a separate line, beginning with the first (top) row. The items within a row are separated by spaces.

#### Usage

$ ./mexp file1.txt

30 36 42

66 81 96

102 126 150

## bst.c | Binary Search Tree Implementation

bst manipulates binary search trees. It will receive commands from standard input, and print resposes to those commands to standard output.

A binary search tree is a binary tree that stores integer values in its interior nodes. The value for a particular node is greater than every value stored its left sub-tree and less than every value stored in its right sub-tree. The tree will not contain any value more than once. bst allocates space for new nodes as they are created using malloc; any allocated space is deallocated using free before bst terminates.

#### Commands

**insert** n Adds a value to the tree, if not already present. The new node will always be added as the child of an existing node, or as the root. No existing node will change or move as as result of inserting an item. If n was not present, and hence has been inserted, bst will print inserted.
Otherwise, it will print not inserted. The instruction format is an i followed by an integer n.

**search** n Searches the tree for a value n. If n is present, bst will print present. Otherwise, it will print absent. The instruction format is an s followed by an integer n.

**print** Prints the current tree structure. The instruction format is a p.

**delete** n Removes a value from the tree. See section 1.6.2 for further discussion of deleting nodes. If n is not present, print absent. Otherwise, print deleted. The instruction format is a d followed by an integer n.

**Input format** The input will be a series of lines, each beginning with a command character (i, s, p, or d), possibly followed by an integer. When the input ends, the program terminates.

**Output format** The output will be a series of lines, each in response to an input command. Most commands will respond with a word, aside from p.

#### Usage

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

^D here indicates typing Control-D at the start of a line in order to signal the end of file.

#### Printing nodes

An empty tree (that is, NULL) is printed as an empty string. A node is printed as a (, followed by the left sub-tree, the item for that node, the right subtree, and ), without spaces.

#### Deleting nodes

There are several strategies for deleting nodes in a binary tree: 

- If a node has no children, it can simply be removed. That is, the pointer to it can be changed to a NULL pointer.

- If a node has one child, it can be replaced by that child. 

- If a node has two children, its value will be changed to the maximum element in its left subtree.

The node which previously contained that value will then be deleted.

Note that the root node could also be deleted.
