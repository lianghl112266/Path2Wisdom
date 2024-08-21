# Nodes from the Root

## 题目描述

Time Limit: 1000 ms
Memory Limit: 256 mb
There is a binary tree with N nodes indexing from 0 to N-1, where 0 is the root. Each edge of the tree has an integer weight W. At first all the nodes could be reached from the root, through a sequence of edges.
An integer threshold X (X >= 0) is used to close the edge, which means that all the edges whose weights are less than X will be closed.
Given the tree and an integer Y, please find the minimum threshold X so that the number of nodes reachable from the root (including the root itself) is no more than Y.


## 输入输出格式

### 输入描述

The first line is an interger T, indicating the number of test cases.
Then in each case:
The first line contains one integer N (N ≤ 2e4), representing the number of nodes in the tree.
The second line contains one integer Y (0 ≤ Y ≤ N), representing the maximum number of nodes allowed to be reachable from the root. 
Each of the following N-1 lines contains three integers U, V (0 ≤ U, V < N), W(0 ≤ W ≤ 1e7), representing that the edge between node U and node V has a weight W. The integers are separated by a space.
The total sum of N in all cases is less than 1e5.

### 输出描述

T lines and each line contains an integer, representing the minimum threshold X (X≥0).
Sample Input

## 输入输出样例

### 输入样例

```plaintext
2
3 2
0 1 2
0 2 3
6 3
0 1 8
0 2 3
1 3 2
1 4 5
2 5 6
```

### 输出样例

```plaintext
3
4
```