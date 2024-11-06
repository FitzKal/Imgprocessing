#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main() {

    //eroded
    /*Mat img = imread("abc.jpg", IMREAD_GRAYSCALE);
    Mat mask;
    threshold(img, mask, 30, 255, THRESH_BINARY_INV);
    imshow("og", img);
    Mat S = getStructuringElement(MORPH_ELLIPSE, Size(17, 17));
    Mat eroded;
    erode(mask, eroded, S);
    imshow("erded", eroded);*/

    //dilated
    /*Mat img = imread("abc.jpg", IMREAD_GRAYSCALE);
    Mat mask;
    threshold(img, mask, 200, 255, THRESH_BINARY_INV);
    imshow("og", img);
    Mat S = getStructuringElement(MORPH_ELLIPSE, Size(17, 17));
    Mat dilated;
    dilate(mask, dilated, S);
    imshow("eroded", dilated);*/

    /*Mat img = imread("abc.jpg", IMREAD_GRAYSCALE);
    Mat eroded, dilated, mask1, mask2, dest;
    threshold(img, mask1, 30, 255, THRESH_BINARY_INV);
    Mat S = getStructuringElement(MORPH_ELLIPSE, Size(13, 13));
    Mat E = getStructuringElement(MORPH_ELLIPSE, Size(10, 10));
    erode(mask1, eroded, E);
    imshow("eroded", eroded);
    threshold(img, mask2, 200, 255, THRESH_BINARY_INV);
    dilate(mask2, dilated, S);
    imshow("dilated", dilated);
    dest = dilated - eroded;
    imshow("dest", dest);*/

   //morphgrad
    /*Mat img = imread("otos.png", IMREAD_GRAYSCALE);
    Mat mask, grad;
    threshold(img, mask, 200, 255, THRESH_BINARY_INV);
    Mat S = getStructuringElement(MORPH_ELLIPSE, Size(15, 15));
    morphologyEx(mask, grad, MORPH_GRADIENT, S);
    imshow("grad", grad);*/

    //rbetu
    /*Mat img = imread("r.png", IMREAD_GRAYSCALE);
    Mat mask, dest, dilated, eroded;
    threshold(img, mask, 200, 255, THRESH_BINARY_INV);
    imshow("mask", mask);
    Mat S = getStructuringElement(MORPH_ELLIPSE, Size(15, 15));
    morphologyEx(mask, dest, MORPH_CLOSE, S);
    dilate(mask, dilated, S);
    erode(mask, eroded, S);
    imshow("dest", dest);
    imshow("eroded", eroded);
    imshow("dilated", dilated);*/

    //ujjlenyomat
    /*Mat img = imread("ujjlenyomat.png", IMREAD_GRAYSCALE);
    Mat mask, dest, blurred;
    resize(img, img, Size(img.cols * 2, img.rows * 2));
    imshow("original", img);
    threshold(img, mask, 220, 255, THRESH_BINARY);
    medianBlur(mask, blurred, 5);
    imshow("blurred", blurred);
    imshow("mask", mask);
    Mat S = getStructuringElement(MORPH_ELLIPSE, Size(9, 9));
    morphologyEx(mask, dest, MORPH_CLOSE, S);
    imshow("kuszobolt", dest);*/

    //ermek
    /*Mat img = imread("coins2.jpg", IMREAD_GRAYSCALE);
    Mat dest, mask, eroded;
    threshold(img, mask, 250, 255, THRESH_BINARY_INV);
    Mat s = getStructuringElement(MORPH_ELLIPSE, Size(2, 2));
    morphologyEx(mask, dest, MORPH_CLOSE, s);
    Mat s2 = getStructuringElement(MORPH_ELLIPSE, Size(80, 80));
    erode(dest, eroded,s2);
    imshow("mask", mask);
    imshow("dest", dest);
    imshow("dest2", eroded);*/

    //sajt
    Mat img = imread("sajt.png", IMREAD_GRAYSCALE);
    Mat dest, mask, dest2;
    threshold(img, mask, 250, 255, THRESH_BINARY_INV);
    Mat s = getStructuringElement(MORPH_ELLIPSE, Size(8, 8));
    morphologyEx(mask, dest, MORPH_GRADIENT, s);
    imshow("mask", mask);
    imshow("og", img);
    imshow("dest", dest);
    Mat se = getStructuringElement(MORPH_ELLIPSE, Size(29, 29));
    Mat dilated;
    dilate(mask, dilated, se);
    Mat szurt;
    morphologyEx(mask, dest2, MORPH_CLOSE, se, cv::Point(-1, -1), 1, BORDER_CONSTANT, 0);
    imshow("dest2", dest2);
    imshow("dilated", dilated);
    medianBlur(dilated, dilated, 11);
    imshow("dilated2", dilated);


    waitKey();
    return 0;
}