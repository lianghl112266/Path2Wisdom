# 最大素因子问题

## 题目描述

对于给定的字符序列，从左至右将所有的数字字符取出拼接成一个无符号整数（字符序列长度小于100，拼接出的整数小于 \(2^{31}\) ），计算并输出该整数的最大素因子（如果是素数，则其最大因子为自身）。

## 输入输出格式

### 输入描述

有多组数据，输入数据的第一行为一个正整数，表示字符序列的数目。每组数据为一行字符序列。

### 输出描述

对每个字符序列，取出所得整数的最大素因子，若字符序列中没有数字或者找出的整数为0，则输出0。每个整数占一行输出。

## 输入输出样例

### 输入样例

```
3
sdf0ejg3.f?9f
?4afd0s&2d79*(g
abcde
```

### 输出样例

```
13
857
0
```