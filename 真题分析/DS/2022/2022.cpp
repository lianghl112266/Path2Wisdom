/*
先判断节点是否子节点是合法的， 如果不合法返回false, 如果合法再递归判断左右孩子是否合法
时间复杂度 O(n)
空间复杂度 O(n)

输入格式： 第一行2个数字代表顶点数，和边数，剩余行代表边
输出格式： 1（true), 0(false)

测试用例1
10
40 25 60 -1 30 -1 80 -1 -1 27
expected output: 1

测试用例2
11
40 50 60 -1 30 -1 -1 -1 -1 -1 35
expected output: 0
*/

#include<bits/stdc++.h>
 
using namespace std;

const int MAX_SIZE = 20;

struct SqBiTree {
    int SqBiTNode[MAX_SIZE];
    int ElemNum;
};

bool solve(SqBiTree node) {

    function<bool(int)> dfs = [&](int i) -> bool
    {
        //拿到左右孩子下标
        int x = 2 * (i + 1) - 1, y = 2 * (i + 1) + 1 - 1;
        bool left = true, right = true;
        //判断左孩子是否存在
        if (x < node.ElemNum && node.SqBiTNode[x] != -1)
        {
            //判断自己和左孩子关系是否合法
            if (node.SqBiTNode[x] > node.SqBiTNode[i])
            {
                return false;
            }
            //判断左子树是否合法
            left = dfs(x);
        }
        //同理操作右孩子
        if (y < node.ElemNum && node.SqBiTNode[y] != -1)
        {
            if (node.SqBiTNode[y] < node.SqBiTNode[i])
            {
                return false;
            }
            right = dfs(y);
        }
        return left && right;
    };

    //递归入口
    return dfs(0);
}


//用于输入
int main() {
    SqBiTree node;
    cin >> node.ElemNum;
    for (int i = 0; i < node.ElemNum; i++){
        cin >> node.SqBiTNode[i];
    }
    cout << solve(node);
}