# Distinct Subsequences

## 题目描述

**Time Limit:** 1000 ms  
**Memory Limit:** 256 mb

Given a string `S` and a string `T`, count the number of distinct subsequences of `S` which is equal to `T`.  
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "nus" is a subsequence of "njucs" while "nsu" is not).

## 输入输出格式

### 输入描述

- The first line is an integer `Q` ( `Q = 50` ), indicating the number of test cases.
- Then in each case:
  - The first line is the string `S`, and the second line is the string `T`. ( `0 < |S|, |T| ≤ 1e4` )
  
The data guarantee every character of `T` is randomly generated.

### 输出描述

Q lines and each line contains an interger P, representing the number of different subsequences of S which is equal to T.
Since P maybe very large, you should output it after module 1000000007(1e9+7).

## 输入输出样例

### 输入样例

```plaintext
2
aaabbb
ab
njnunju
nju
```

### 输出样例

```plaintext
9
5
```