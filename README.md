QUESTION 11 - BINARY SEARCH TREE

Problem Statement

A government database stores the following identification numbers:

A102, A25, A7, B100, B12, A120, B3, A45

The identification numbers are organised using a Binary Search Tree. BST Search and Linear Search are compared based on the number of comparisons. The effect of key length and insertion order on BST height and search performance is also analysed.


INPUT DATA

Identification Numbers:

A102
A25
A7
B100
B12
A120
B3
A45

Search Keys:

A45
B3
A50


DATA STRUCTURE USED

Binary Search Tree (BST)

Each node contains:

1. Identification number
2. Pointer to the left child
3. Pointer to the right child

The identification numbers are compared as strings using strcmp().

If the new ID is smaller than the current node, it is inserted into the left subtree.

If the new ID is greater than the current node, it is inserted into the right subtree.


BST CONSTRUCTION

The IDs are inserted in the given order:

A102
A25
A7
B100
B12
A120
B3
A45

Resulting BST:

                    A102
                   /    \
                A25      B100
               /   \        \
            A120    A7      B12
               \              \
               A45             B3

The tree is not completely balanced.

The longest path contains 4 nodes:

A102 -> B100 -> B12 -> B3

Therefore, the height of the tree is 3 edges or 4 levels.


INORDER TRAVERSAL

The inorder traversal follows:

Left Subtree -> Root -> Right Subtree

Output:

A102 A120 A25 A45 A7 B100 B12 B3

Since the IDs are strings, the ordering is based on lexicographical string comparison.


TRACE TABLE - BST INSERTION

Step 1

Inserted: A102

Tree:

A102


Step 2

Inserted: A25

Comparison:
A25 > A102

Inserted to the right of A102.


Step 3

Inserted: A7

Comparisons:
A7 < A102
A7 < A25

Inserted to the left of A25.


Step 4

Inserted: B100

Comparisons:
B100 > A102
B100 > A25

Inserted to the right of A25.


Step 5

Inserted: B12

Comparisons:
B12 > A102
B12 > A25
B12 < B100

Inserted to the left of B100.


Step 6

Inserted: A120

Comparisons:
A120 > A102
A120 < A25

Inserted to the left of A25.


Step 7

Inserted: B3

Comparisons:
B3 > A102
B3 > A25
B3 < B100
B3 > B12

Inserted to the right of B12.


Step 8

Inserted: A45

Comparisons:
A45 < A102
A45 > A25
A45 > A120

Inserted to the right of A120.


SEARCH TRACE

Search Key: A45

BST Search Path:

A102 -> A25 -> A45

Number of comparisons = 3

Result = Found


Linear Search Path:

A102 -> A25 -> A7 -> B100 -> B12 -> A120 -> B3 -> A45

Number of comparisons = 8

Result = Found


Search Key: B3

BST Search Path:

A102 -> B100 -> B12 -> B3

Number of comparisons = 4

Result = Found


Linear Search Path:

A102 -> A25 -> A7 -> B100 -> B12 -> A120 -> B3

Number of comparisons = 7

Result = Found


Search Key: A50

BST Search Path:

A102 -> A25 -> A45 -> A7

Number of comparisons = 4

Result = Not Found


Linear Search Path:

A102 -> A25 -> A7 -> B100 -> B12 -> A120 -> B3 -> A45

Number of comparisons = 8

Result = Not Found


SEARCH COMPARISON TABLE

Search Key    BST Result    BST Comparisons    Linear Result    Linear Comparisons

A45           Found         3                  Found            8
B3            Found         4                  Found            7
A50           Not Found     4                  Not Found        8


COMPLEXITY ANALYSIS

BST Search:

Best Case: O(1)

Average Case: O(log n) for a balanced BST

Worst Case: O(n) for a highly unbalanced BST

Linear Search:

Best Case: O(1)

Average Case: O(n)

Worst Case: O(n)


SPACE COMPLEXITY

BST:

Space required for n nodes = O(n)

Linear Search:

Additional search space = O(1)

The array containing the IDs requires O(n) storage.


EFFECT OF INSERTION ORDER

Insertion order has a major effect on the height of a normal BST.

If the IDs are inserted in a balanced order, the tree can have a smaller height and searching becomes faster.

If the IDs are inserted in an unfavourable order, the tree can become highly unbalanced.

Example of a highly unbalanced tree:

A
 \
  B
   \
    C
     \
      D

In this case, the height becomes approximately n - 1.

Therefore, BST search can degrade from O(log n) to O(n).


EFFECT OF KEY LENGTH

The identification numbers have different lengths, such as:

A7
A25
A45
A102
A120
B3
B12
B100

The program compares the IDs as strings using strcmp().

Longer keys may require more character comparisons before a difference is found.

Therefore, the length of the identification number can affect the actual cost of string comparison.

However, the standard BST complexity is normally expressed in terms of the number of nodes visited:

Balanced BST: O(log n)

Worst-case BST: O(n)


COMPARISON OF BST SEARCH AND LINEAR SEARCH

Parameter              BST Search                 Linear Search

Data Structure         Binary Search Tree         Array
Best Case              O(1)                       O(1)
Average Case            O(log n)                  O(n)
Worst Case             O(n)                       O(n)
Search Method           Tree traversal             Sequential checking
Effect of insertion     High                        None
Additional space        O(1)                       O(1)
Storage                 O(n)                       O(n)


OBSERVED RESULTS

For A45:

BST Search required 3 comparisons.

Linear Search required 8 comparisons.

For B3:

BST Search required 4 comparisons.

Linear Search required 7 comparisons.

For A50:

BST Search required 4 comparisons.

Linear Search required 8 comparisons.

The observed results show that BST Search required fewer comparisons for all three selected searches.


TREE HEIGHT ANALYSIS

The longest path in the constructed BST is:

A102 -> B100 -> B12 -> B3

Number of edges = 3

Number of levels = 4

The tree is not perfectly balanced.

An unbalanced BST may require more comparisons during searching.


THEORETICAL VS OBSERVED PERFORMANCE

For a balanced BST, search performance is approximately O(log n).

For the given BST, the tree is not perfectly balanced, so the observed comparisons depend on the location of each key.

In the worst case, a normal BST can become skewed and its search complexity becomes O(n).

Linear Search always checks elements sequentially and has O(n) average and worst-case complexity.


CONCLUSION

A Binary Search Tree was implemented using the given government identification numbers.

The inorder traversal was successfully obtained.

BST Search required fewer comparisons than Linear Search for the selected test cases.

The performance of a BST depends strongly on its height and insertion order. A balanced BST provides better search performance, while a highly unbalanced BST can have O(n) search time.

The length of the identification keys can also affect the actual cost of string comparisons.

For a growing database, a self-balancing BST such as an AVL Tree or Red-Black Tree can be used to maintain efficient search performance.

For very large database systems, indexed structures such as B-Trees or B+ Trees can also be considered.