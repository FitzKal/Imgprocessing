#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void pirosmasolo(Mat img, Mat& dest) {
    Vec3b c;
    for (int i = 0; i < img.rows; ++i)
    {
        for (int j = 0; j < img.cols; ++j)
        {
            c = img.at<Vec3b>(i, j);
            if (c[2] > c[1] && c[2] > c[0]) {
                dest.at<Vec3b>(i, j) = c;
            }
        }
    }
}

void deklaracio(Mat img, Mat& dest) {
    Vec3b c;
    for (int i = 0; i < img.rows; ++i)
    {
        for (int j = 0; j < img.cols; ++j)
        {
            c = img.at<Vec3b>(i, j);
            if (i < dest.rows && j < dest.cols) {
                dest.at<Vec3b>(i + 50, j+300) = c;
                dest.at<Vec3b>(i + 400, j+300) = c;
            }
        }
    }
}
void masolo(const Mat& stitch, Mat& polo) {
    Vec3b chs;
    for (int i = 0; i < stitch.rows; i++) {
        for (int j = 0; j < stitch.cols; j++) {
            chs = stitch.at<Vec3b>(i, j);
            if (chs[0] < 100 and chs[1] < 100 and chs[2] < 100) {
                polo.at<Vec3b>(i, j) = chs;
            }
        }
    }

}



int main() {
 
    /*Mat img = imread("piros_alma_sziv.jpg", IMREAD_COLOR);
    Mat dest = img.clone();
    dest.setTo(Scalar(0, 0, 0));
    pirosmasolo(img, dest);
    imshow("eredmeny", dest);*/

    /*Mat bg = imread("hatter_halloween.jpeg", IMREAD_COLOR);
    Mat fg = imread("dekoracio.jpg", IMREAD_COLOR); 
    deklaracio(fg, bg);
    imshow("xd", bg);*/

    /*Mat img = imread("m&m.jpg", IMREAD_COLOR);
    Mat hsv;
    Mat dest = img.clone();
    dest.setTo(Scalar(0, 0, 0));
    cvtColor(img, hsv, COLOR_BGR2HSV);
    Vec3b c; 
    for (int i = 0; i < img.rows; ++i)
    {
        for (int j = 0; j < img.cols; ++j) {
            c = img.at<Vec3b>(i, j);
            int hue = hsv.at<Vec3b>(i, j)[0];
            if (hue > 100 && hue < 120) {
                dest.at<Vec3b>(i, j) = c;
            }
        }
    }
    medianBlur(dest, dest, 5);
    imshow("igen", dest);*/

    /*Mat img = imread("img2.jpg", IMREAD_COLOR);
    vector<Mat> chs;
    Mat dest;
    split(img, chs);
    chs[2] = 255 - chs[2];
    merge(chs, dest);
    imshow("", dest);*/

    /*Mat hatter = imread("img8_1.jpg", IMREAD_COLOR);
    Mat eloter = imread("img8_2.jpg", IMREAD_COLOR);
    resize(eloter, eloter, Size(500, 500));
    Mat hsv, korvonal;
    Mat dest(eloter.size(), eloter.type(), Scalar(255, 255, 255));


    cvtColor(eloter, hsv, COLOR_BGR2HSV);
    inRange(hsv, Scalar(0, 0, 0), Scalar(255, 255, 100), korvonal);
    eloter.copyTo(dest, korvonal);
    imshow(" w", korvonal);
    imshow(" ", dest);
    imshow("xd ", eloter);

    masolo(dest, hatter);

    imshow("kep.jpg", hatter);*/

    /*Mat img = imread("coins2.jpg", IMREAD_GRAYSCALE);
    Mat mask;
    threshold(img, mask, 250, 255, THRESH_BINARY_INV);
    imshow("kuszobolt", mask);
    Mat se = getStructuringElement(MORPH_ELLIPSE, Size(2, 2));
    Mat dest;
    //morphologyEx(mask, dest, MORPH_CLOSE, se);
   // imshow("dest", dest);
    dilate(mask, mask, se);
    Mat S2 = getStructuringElement(MORPH_ELLIPSE, Size(80, 80));
    erode(mask, dest, S2);
    imshow("erode", dest);*/


    /*Mat img = imread("piros_alma_sziv.jpg", IMREAD_COLOR);
    Mat maszk, szurke;
    cvtColor(img, szurke, COLOR_BGR2GRAY);
    threshold(szurke, maszk, 210, 255, THRESH_BINARY_INV);
    imshow("maszk", maszk);
    Mat dest;
    img.copyTo(dest, maszk);
    imshow(" ", dest);*/

    Mat img = imread("madar.jpg", IMREAD_COLOR);
    vector <Mat> chs;
    Mat mask, dest;
    split(img, chs);
    imshow("alma", chs[0]);
    //imshow("ajlma", chs[1]);
   // imshow("aljma", chs[2]);
    threshold(chs[0], mask, 150, 255, THRESH_BINARY);
    imshow("maszk", mask);
    img.copyTo(dest, mask);
    imshow("xd", dest);


    waitKey();
    return 0;
}