#include <bits/stdc++.h>

using namespace std;


struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int _x) : val(_x), next(nullptr) {}
    Node(int _x, Node *_next) : val(_x), next(_next) {}
};


Node *solve(Node *head, int n) {
    
}