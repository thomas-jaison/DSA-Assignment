# 🌳 QUESTION 11 — BINARY SEARCH TREE

## 📌 Data Structures and Algorithms

**Assignment:** Assignment 2  
**Question:** 11  
**Topic:** Binary Search Tree (BST) and Searching Algorithms

---

## 📝 Problem Statement

A government database stores the following identification numbers:

```text
A102, A25, A7, B100, B12, A120, B3, A45
```

The identification numbers are organised using a **Binary Search Tree (BST)**. BST Search and Linear Search are compared based on the number of comparisons.

The effect of **key length** and **insertion order** on BST height and search performance is also analysed.

---

## 📥 Input Data

### Identification Numbers

```text
A102
A25
A7
B100
B12
A120
B3
A45
```

### Search Keys

```text
A45
B3
A50
```

---

## 🌲 Data Structure Used

### Binary Search Tree (BST)

Each node contains:

1. Identification number
2. Pointer to the left child
3. Pointer to the right child

The identification numbers are compared as strings using `strcmp()`.

- If the new ID is smaller than the current node, it is inserted into the **left subtree**.
- If the new ID is greater than the current node, it is inserted into the **right subtree**.

---

# 🌳 BST Construction

The IDs are inserted in the given order:

```text
A102
A25
A7
B100
B12
A120
B3
A45
```

### Resulting BST

```text
                    A102
                   /    \
                A25      B100
               /   \        \
            A120    A7      B12
               \              \
               A45             B3
```

The tree is not completely balanced.

The longest path contains 4 nodes:

```text
A102 → B100 → B12 → B3
```

Therefore:

```text
Height = 3 edges
Levels = 4
```

---

# 🔄 Inorder Traversal

Inorder traversal follows:

```text
Left Subtree → Root → Right Subtree
```

### Output

```text
A102 A120 A25 A45 A7 B100 B12 B3
```

Since the IDs are strings, the ordering is based on **lexicographical string comparison**.

---

# 📊 Trace Table — BST Insertion

| Step | Inserted ID | Comparisons | Position |
|---:|---|---|---|
| 1 | `A102` | Root node | Root |
| 2 | `A25` | A25 > A102 | Right of A102 |
| 3 | `A7` | A7 < A102, A7 < A25 | Left of A25 |
| 4 | `B100` | B100 > A102, B100 > A25 | Right of A25 |
| 5 | `B12` | B12 > A102, B12 > A25, B12 < B100 | Left of B100 |
| 6 | `A120` | A120 > A102, A120 < A25 | Left of A25 |
| 7 | `B3` | B3 > A102, B3 > A25, B3 < B100, B3 > B12 | Right of B12 |
| 8 | `A45` | A45 < A102, A45 > A25, A45 > A120 | Right of A120 |

---

# 🔎 Search Trace

## Search Key: `A45`

### BST Search Path

```text
A102 → A25 → A45
```

**Number of comparisons:** `3`

**Result:** `Found`

### Linear Search Path

```text
A102 → A25 → A7 → B100 → B12 → A120 → B3 → A45
```

**Number of comparisons:** `8`

**Result:** `Found`

---

## Search Key: `B3`

### BST Search Path

```text
A102 → B100 → B12 → B3
```

**Number of comparisons:** `4`

**Result:** `Found`

### Linear Search Path

```text
A102 → A25 → A7 → B100 → B12 → A120 → B3
```

**Number of comparisons:** `7`

**Result:** `Found`

---

## Search Key: `A50`

### BST Search Path

```text
A102 → A25 → A45 → A7
```

**Number of comparisons:** `4`

**Result:** `Not Found`

### Linear Search Path

```text
A102 → A25 → A7 → B100 → B12 → A120 → B3 → A45
```

**Number of comparisons:** `8`

**Result:** `Not Found`

---

# 📈 Search Comparison Table

| Search Key | BST Result | BST Comparisons | Linear Result | Linear Comparisons |
|---|---|---:|---|---:|
| `A45` | Found | 3 | Found | 8 |
| `B3` | Found | 4 | Found | 7 |
| `A50` | Not Found | 4 | Not Found | 8 |

### Observation

The observed results show that **BST Search required fewer comparisons** than Linear Search for all three selected test cases.

---

# ⏱️ Complexity Analysis

## BST Search

| Case | Time Complexity |
|---|---|
| Best Case | `O(1)` |
| Average Case | `O(log n)` for a balanced BST |
| Worst Case | `O(n)` for a highly unbalanced BST |

---

## Linear Search

| Case | Time Complexity |
|---|---|
| Best Case | `O(1)` |
| Average Case | `O(n)` |
| Worst Case | `O(n)` |

---

# 💾 Space Complexity

### BST

Space required for `n` nodes:

```text
O(n)
```

### Linear Search

Additional search space:

```text
O(1)
```

The array containing the IDs requires:

```text
O(n)
```

storage.

---

# 🔀 Effect of Insertion Order

Insertion order has a major effect on the height of a normal BST.

If the IDs are inserted in a balanced order, the tree can have a smaller height and searching becomes faster.

If the IDs are inserted in an unfavourable order, the tree can become highly unbalanced.

### Example of a Highly Unbalanced Tree

```text
A
 \
  B
   \
    C
     \
      D
```

In this case, the height becomes approximately:

```text
n - 1
```

Therefore, BST search can degrade from:

```text
O(log n) → O(n)
```

---

# 🔤 Effect of Key Length

The identification numbers have different lengths, such as:

```text
A7
A25
A45
A102
A120
B3
B12
B100
```

The program compares the IDs as strings using:

```c
strcmp()
```

Longer keys may require more character comparisons before a difference is found.

Therefore, the length of the identification number can affect the actual cost of string comparison.

However, the standard BST complexity is normally expressed in terms of the number of nodes visited:

```text
Balanced BST → O(log n)

Worst-case BST → O(n)
```

---

# ⚖️ BST Search vs Linear Search

| Parameter | BST Search | Linear Search |
|---|---|---|
| Data Structure | Binary Search Tree | Array |
| Best Case | `O(1)` | `O(1)` |
| Average Case | `O(log n)` | `O(n)` |
| Worst Case | `O(n)` | `O(n)` |
| Search Method | Tree traversal | Sequential checking |
| Effect of Insertion | High | None |
| Additional Space | `O(1)` | `O(1)` |
| Storage | `O(n)` | `O(n)` |

---

# 📌 Observed Results

### `A45`

```text
BST Search     → 3 comparisons
Linear Search  → 8 comparisons
```

### `B3`

```text
BST Search     → 4 comparisons
Linear Search  → 7 comparisons
```

### `A50`

```text
BST Search     → 4 comparisons
Linear Search  → 8 comparisons
```

The observed results show that BST Search required fewer comparisons for all three selected searches.

---

# 📏 Tree Height Analysis

The longest path in the constructed BST is:

```text
A102 → B100 → B12 → B3
```

Therefore:

```text
Number of edges  = 3
Number of levels = 4
```

The tree is not perfectly balanced.

An unbalanced BST may require more comparisons during searching.

---

# 🧮 Theoretical vs Observed Performance

### Theoretical Performance

For a balanced BST:

```text
Search ≈ O(log n)
```

For a highly unbalanced BST:

```text
Search = O(n)
```

For Linear Search:

```text
Average Case = O(n)
Worst Case   = O(n)
```

### Observed Performance

For the selected test cases, BST Search required fewer comparisons than Linear Search.

The actual number of comparisons depends on the location of the searched key and the structure of the BST.

---

# 🏢 Suitable Approach for a Growing Database

As the database grows, maintaining a normal BST can become inefficient if the tree becomes highly unbalanced.

A **self-balancing BST** can be used to maintain efficient searches.

Examples include:

```text
AVL Tree
Red-Black Tree
```

These structures maintain a controlled tree height and provide approximately:

```text
O(log n)
```

search performance.

For very large database systems, indexed structures such as:

```text
B-Tree
B+ Tree
```

can also be considered.

---

# ✅ Conclusion

A Binary Search Tree was implemented using the given government identification numbers.

The inorder traversal was successfully obtained.

BST Search required fewer comparisons than Linear Search for the selected test cases.

The performance of a BST depends strongly on its height and insertion order. A balanced BST provides better search performance, while a highly unbalanced BST can have `O(n)` search time.

The length of the identification keys can also affect the actual cost of string comparisons.

For a growing database, a self-balancing BST such as an **AVL Tree** or **Red-Black Tree** can be used to maintain efficient search performance.

For very large database systems, indexed structures such as **B-Trees** or **B+ Trees** can also be considered.

---

# 📁 Project Files

```text
Question_11/
│
├── question_11_bst.c
├── question_11_output.txt
└── README.md
```

---

## 🧠 Concepts Covered

```text
✓ Binary Search Tree
✓ BST Insertion
✓ Inorder Traversal
✓ BST Search
✓ Linear Search
✓ String Comparison
✓ Trace Table
✓ Search Comparison
✓ Tree Height
✓ Time Complexity
✓ Space Complexity
✓ Insertion Order Analysis
✓ Key Length Analysis
```

---

## 🚀 Status

**Assignment Completed ✓**
