//
// Created by wz on 2021/3/25.
//
/*
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& input, int k) {
        vector<int> ret;
        if (k==0 || k>input.size()) return ret;
        sort(input.begin(), input.end());
        return vector<int>({input.begin(), input.begin()+k});
    }
};

int main()
{
    Solution s;
    vector<int> a = {4,5,1,6,2,7,3,8};
    vector<int> res = s.getLeastNumbers(a, 4);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
}