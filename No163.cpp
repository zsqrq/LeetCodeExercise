//
// Created by wz on 2021/3/31.
//
/*给定一个排序的整数数组 nums，其中元素的范围在闭区间[lower, upper]当中，返回不包含在数组中的缺失区间。

示例：

输入: nums = [0, 1, 3, 50, 75], lower = 0 和 upper = 99,
        输出: ["2", "4->49", "51->74", "76->99"]*/
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
class solution
{
public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        int L = lower;
        vector<string> res;
        for (int i = 0; i < n; i++) {
            if (L == nums[i]){
                L++;
            } else
            {
                if (L < nums[i] - 1)
                {
                    res.push_back(to_string(L) + "->" + to_string(nums[i] - 1));
                } else if (L == nums[i] - 1)
                {
                    res.push_back(to_string(L));
                }
                L = nums[i] + 1;
            }
        }
        if (L < upper){
            res.push_back(to_string(L) + "->" + to_string(upper));
        }
        if (L == upper){
            res.push_back(to_string(L));
        }
        return res;
    }
};

int main()
{
    solution s;
    vector<int> nums = {0,1,3,50,75};
    int lower = 0;
    int upper = 99;
    vector<string> res = s.findMissingRanges(nums,lower,upper);
    for (auto &iter : res) {
        cout << iter << endl;
    }
}