//
// Created by wz on 2021/3/24.
//
#include <iostream>
#include <stdio.h>
using namespace std;


int digui(int i) {
    int j = 0;
    if (i == 0)
        return 1;
    j = digui(i - 1);
    return j;
}

int main()
{
    int res = digui(5);
    cout << res << endl;
}

