#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main() {

   /* Mat szita = imread("szita2.png", IMREAD_GRAYSCALE);
    Mat melyseg = imread("melyseg.png", IMREAD_GRAYSCALE);
    Mat median, gauss, blured;
    Size newsize(3, 3);*/
   /* blur(img, blured, newsize);
    GaussianBlur(img, gauss, Size(3, 3), img.cols/2);
    medianBlur(img, median, 3);
    imshow("eredeti", img);
    imshow("blured", blured);
    imshow("gauss", gauss);
    imshow("median", median);*/

    /*Mat img = imread("dog.jpg", IMREAD_GRAYSCALE);
    Mat dest;
    threshold(img, dest, 100, 255, THRESH_BINARY);//kuszoboles
    Mat medianszurt;
    medianBlur(dest, medianszurt, 3);
    imshow("alap", img);
    imshow("kuszobolt", dest);
    imshow("kuszobolt mediannal", medianszurt);*/

    
    //madar
    /*Mat img = imread("Madar.jpg", IMREAD_COLOR);
    vector<Mat>c;
    Mat kuszobolt;
    Mat dest;
    split(img, c);
    //imshow("B", c[0]);
    //imshow("G", c[1]);
    //imshow("R", c[2]);
    kuszobolt = c[1];
    threshold(kuszobolt, dest, 125, 255, THRESH_BINARY);
    imshow("kuszobolt", dest);  
    imshow("eredeti", img);
    Mat hsv;
    cvtColor(img, hsv, COLOR_BGR2HSV);
    Mat mask;
    Mat fekete = Mat::zeros(img.size(), img.type());
    Scalar also_hatar(50, 50, 50);  // Adjust the values as needed
    Scalar felso_hatar(120, 255, 255);
    inRange(hsv, also_hatar, felso_hatar, mask);
    //imshow("mask",mask);
    hsv.copyTo(fekete, mask);
    Mat dest2;
    cvtColor(fekete, dest2, COLOR_HSV2BGR);
    imshow("Fekete", dest2);*/

    Mat img = imread("gray_buttons.jpg", IMREAD_GRAYSCALE);
    imshow("eredeti", img);
    Mat mask;
    inRange(img, 165, 213, mask);
    medianBlur(mask, mask, 3);
    bitwise_not(mask, mask);
    img.setTo(0, mask);
    imshow("mask", img);
    cvtColor(img,dest,COLOR_BGR2GRAY)

    waitKey(0);

    return 0;
}