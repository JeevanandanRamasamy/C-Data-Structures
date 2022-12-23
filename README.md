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







## bst.c | Binary Search Tree Implementation

















