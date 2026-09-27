# Binary Search Tree – Government Identification Database

## 1. Aim

To implement a Binary Search Tree (BST) to organize government identification numbers and compare the performance of BST Search and Linear Search based on the number of comparisons.

## 2. Problem Statement

A government database stores the following identification numbers:

A102, A25, A7, B100, B12, A120, B3, A45

The objectives are:

1. Implement a BST to store the identification numbers and display its inorder traversal.
2. Search for selected identification numbers using BST Search and Linear Search.
3. Record and compare the number of comparisons required by both searching methods.

## 3. Identification Numbers

The given identification numbers are:

A102
A25
A7
B100
B12
A120
B3
A45

## 4. Binary Search Tree

A Binary Search Tree is a tree data structure in which:

- Smaller values are stored in the left subtree.
- Greater values are stored in the right subtree.
- Each node can have at most two children.

Since the identification numbers contain letters and numbers, string comparison is used to determine their order.

## 5. BST Structure

The BST formed using the given insertion order is:

                    A102
                   /    \
                A25      B100
               /   \      /
            A120   A7    B12
                    /      \
                  A45       B3

## 6. Inorder Traversal

Inorder traversal follows:

Left → Root → Right

The inorder traversal of the BST is:

A102 A120 A25 A45 A7 B100 B12 B3

## 7. BST Search

BST Search starts from the root and compares the search key with the current node.

- If the key is equal to the current node, the element is found.
- If the key is smaller, the search continues in the left subtree.
- If the key is greater, the search continues in the right subtree.

Example: Searching for A45

A102 → A25 → A7 → A45

Number of comparisons = 4

## 8. Linear Search

Linear Search checks each element one by one from the beginning of the list until the required element is found.

Example: Searching for A45

A102 → A25 → A7 → B100 → B12 → A120 → B3 → A45

Number of comparisons = 8

## 9. Comparison of BST Search and Linear Search

| Feature | BST Search | Linear Search |
|---------|------------|---------------|
| Data Structure | Binary Search Tree | Array/List |
| Searching Method | Follows a tree path | Checks elements one by one |
| Best Case | O(1) | O(1) |
| Average Case | O(log n) | O(n) |
| Worst Case | O(n) | O(n) |
| Performance | Faster when balanced | Slower for large data |
| Main Factor | Tree height | Position of element |

## 10. Sample Result

For searching A45:

BST Search:
Found
Number of comparisons = 4

Linear Search:
Found
Number of comparisons = 8

## 11. Time Complexity

### BST Search

Best Case: O(1)

Average Case: O(log n)

Worst Case: O(n)

### Linear Search

Best Case: O(1)

Average Case: O(n)

Worst Case: O(n)

## 12. Advantages of BST

- Provides efficient searching when the tree is balanced.
- Maintains data in an ordered structure.
- Inorder traversal produces the elements in sorted order.
- Insertion does not require shifting existing elements.

## 13. Limitations of BST

- An ordinary BST can become unbalanced.
- A skewed BST can have O(n) search time.
- Performance depends on the insertion order.
- Additional memory is required for pointers.

## 14. Conclusion

The government identification numbers were organized using a Binary Search Tree. The inorder traversal was obtained successfully. BST Search and Linear Search were compared by counting the number of comparisons.

The experiment shows that BST Search can require fewer comparisons than Linear Search when the tree is suitably structured. For large databases, self-balancing trees such as AVL Trees or Red-Black Trees can be used to maintain efficient searching.
