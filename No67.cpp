//
// Created by wz on 2021/3/22.
/*
给你两个二进制字符串，返回它们的和（用二进制表示）。
输入为非空字符串且只包含数字1和0。
示例
输入: a = "11", b = "1"
输出: "100"
示例2:
输入: a = "1010", b = "1011"
输出: "10101"
提示：
每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;
/*
二进制求和，满二进一
首先让两个字符串等长，若不等长，在短的字符串前补零，否则之后的操作会超出索引。
然后从后到前遍历所有的位数，同位相加，这里有一个点，用的是字符相，利用 ASCII 码，
字符在内部都用数字表示，我们不需要知道具体数值，但可知 ‘0’-‘0’ = 0， ‘0’+1=‘1’，以此类推 。
字符的加减，大小比较，实际上都是内部数字的加减，大小比较判断相加后的字符，若大于等于字符 ‘2’‘2’，下一位需要进一
第 00 位数的相加在这里是单独处理的，因为它可能涉及到字符的插入（即是否需要在最前面加一位数 ‘1’‘1’
 */


class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = max(a.size(), b.size());
        int carry = 0;
        for (int i = 0; i < n; ++i) {
            carry += i < a.size() ? a[i] == '1' : 0;
            carry += i < b.size() ? b[i] == '1' : 0;
            res.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }
        if (carry){
            res.push_back('1');
        }
        reverse(res.begin(), res.end());
        return res;
    };
};

int main()
{
    Solution s;
    string a = "11";
    string b = "1";
    string res1 = s.addBinary(a,b);
    cout << res1 << endl;
    string a2 = "1010";
    string b2 = "1011";
    string res2 = s.addBinary(a2,b2);
    cout << res2 << endl;
}