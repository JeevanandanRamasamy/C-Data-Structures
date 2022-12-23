# C-Data-Structures

## sort.c
#### sort takes zero or more arguments, sorts them lexicographically, and then prints each argument on its own line.
#### If sorta receives no arguments, it exits without printing anything.
#### sort is based on ASCII comparison of characters (so ‘Z’ comes before ‘a’)
####

## sudoku.c
#### sudoku checks whether a proposed Sudoku solution is correct and checks whether a partially-solved Sudoku puzzle with up to two unknown square can be solved.
####
#### A completed Sudoku puzzle is a 9 ×9 matrix containing the digits 1–9, inclusive. The matrix is divided into nine 3 ×3 submatrixes, themselves arranged in a 3 ×3 square. A completed Sudoku puzzle is a correct solution if and only if it has the following properties:
#### • Each digit occurs exactly once in each row (that is, no row contains any digit more than once.
#### • Each digit occurs exactly once in each column.
#### • Each digit occurs exactly once in each submatrix.
#### An almost-completed Sudoku puzzle is similar, except that one or two elements are unspecified.
####
#### The input file should contain a completed Sudoku puzzle. The puzzle is given on nine lines, each of which contains nine digits without any separation. Note that the digit 0 will not occur. The input file file1.txt corresponding to the puzzle above would contain:
#### 534678912
#### 672195348
#### 198342567
#### 859761423
#### 426853791
#### 713924856
#### 961537284
#### 287419635
#### 345286179
#### When given such a file, sudoku must determine whether the completed puzzle is a correct solution (meaning it satisfies the three properties). If so, it prints correct. Otherwise, it prints incorrect. If the input file does not exist, is not readable, or does not follow the format specified here, sudoku  prints error.
