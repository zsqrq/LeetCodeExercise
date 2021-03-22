//
// Created by wz on 2021/3/22.
/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。
*/
#include <iostream>
#include <stdio.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int p = 0;
        int q = 0;
        int r = 1;
        for (int i = 0; i < n; ++i) {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    };
};

int main()
{
    Solution s;
    int n = 3;
    int res = s.climbStairs(n);
    cout << res << endl;
}
