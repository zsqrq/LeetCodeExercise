//
// Created by wz on 2021/3/25.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Bbox
{
    Bbox(int x1,int y1,int x2,int y2){
        x_topleft = x1;
        y_topleft = y1;
        x_rightbottom = x2;
        y_rightbottom = y2;
    }
    int x_topleft;
    int y_topleft;
    int x_rightbottom;
    int y_rightbottom;
};

float Iou_cal(const Bbox &b1, const Bbox &b2){
    float w = min(b1.x_rightbottom, b1.x_rightbottom) - max(b1.x_topleft, b2.x_topleft);
    float h = min(b1.y_rightbottom, b2.y_rightbottom) - max(b1.y_topleft, b2.y_topleft);
    if (w <= 0 || h <= 0) return 0;

    float w1 = b1.x_rightbottom - b1.x_topleft;
    float h1 = b1.y_rightbottom - b1.y_topleft;
    float w2 = b2.x_rightbottom - b2.x_topleft;
    float h2 = b2.y_rightbottom - b1.y_topleft;

    float Iou = (w * h) / ((w1 * h1) + (w2 * h2) - (w * h));
    return Iou;
}

int main()
{
    Bbox b1(1,1,10,10), b2(2,2,18,18);
    float Iou = Iou_cal(b1, b2);
    cout << Iou << endl;
}