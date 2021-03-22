//
// Created by wz on 2021/3/22.
//
/*
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。
*/
#include <vector>
#include <iostream>
#include <stdio.h>
using namespace  std;
class Solution {
public:
    Solution(){};
    ~Solution(){};
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0 ; i--) {
            if (digits[i] == 9) digits[i]=0;
            else
            {
                digits[i] += 1;
                return digits;
            }
        }
        if (digits.front() == 0) digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main()
{
    Solution a;
    vector<int> d1 = {1,2,3};
    a.plusOne(d1);
    cout << "test1 :" << endl;
    for (int i = 0; i < d1.size(); ++i) {
        cout << d1[i] << endl;
    }
    cout << "test2 :" << endl;
    vector<int> d2 = {4,3,2,1};
    a.plusOne(d2);
    for (int i = 0; i < d2.size(); ++i) {
        cout << d2[i] << endl;
    }
    cout << "test3 :" << endl;
    vector<int> d3 = {0};
    a.plusOne(d3);
    for (int i = 0; i < d3.size(); ++i) {
        cout << d3[i] << endl;
    }


}
