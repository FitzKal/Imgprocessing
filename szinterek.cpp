#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<vector>
using namespace std;
using namespace cv;
void piros_invertalas(Mat img, Mat& dest) {
	vector <Mat> c;
	split(img, c);
	c[2] = 255-c[2];
	merge(c,dest);
}

void pirosmasolo(Mat fg, Mat& bg) {
	Vec3b c; 
	for (int i = 0; i < fg.rows; ++i)
	{
		for (int j = 0; j < fg.cols; ++j) {
			c = fg.at<Vec3b>(i, j);
			if (c[2] > c[1] && c[2] > c[0]) {
				bg.at<Vec3b>(i, j) = c;
			}
		}
	}
}

void zoldmasolo(Mat fg, Mat& bg) {
	Vec3b c;
	for (int i = 0; i < fg.rows; ++i)
	{
		for (int j = 0; j < fg.cols; ++j) {
			c = fg.at<Vec3b>(i, j);
			if (c[1] > c[0] && c[1] > c[2]) {
				bg.at<Vec3b>(i, j) = c;
			}
		}
	}
}void sparxd(Mat fg, Mat& bg) {
	Vec3b c;
	for (int i = 0; i < fg.rows; ++i)
	{
		for (int j = 0; j < fg.cols; ++j) {
			c = fg.at<Vec3b>(i, j);
			if (c[1] > c[0] && c[1] > c[2]) {
				bg.at<Vec3b>(i, j) = c;
				bg.at<Vec3b>(i, j) = bg.at<Vec3b>(i, j)[0];
			}
		}
	}
	for (int i = 0; i < fg.rows; ++i)
	{
		for (int j = 0; j < fg.cols; ++j) {
			c = fg.at<Vec3b>(i, j);
			if (c[2] > c[1] && c[2] > c[0]) {
				bg.at<Vec3b>(i, j) = c;
			}
		}
	}
}

void lilalufi(Mat img, Mat& dest) {
	Vec3b c;
	Mat hsv;
	cvtColor(img, hsv, COLOR_BGR2HSV);
	for (int i = 0; i < img.rows; ++i)
	{
		for (int j = 0; j < img.cols; ++j)
		{
			c = img.at<Vec3b>(i, j);
			int hue = hsv.at<Vec3b>(i, j)[0];
			if ((hue >= 0 && hue < 125) || (hue > 160)) {
				dest.at<Vec3b>(i, j) = c;
			}
		}
	}
}

void pride(Mat img, Mat& dest) {
	Vec3b c;
	Mat hsv;
	cvtColor(img, hsv, COLOR_BGR2HSV);
	for (int i = 0; i < img.rows; ++i)
	{
		for (int j = 0; j < img.cols; ++j) {
			c = img.at<Vec3b>(i, j);
			int hue = hsv.at<Vec3b>(i, j)[0];
			if (hue > 165 && hue < 180) {
				dest.at<Vec3b>(i, j) = c;
				dest.at<Vec3b>(i, j) = dest.at<Vec3b>(i, j)[0];
			}
			else {
				dest.at<Vec3b>(i, j) = c;
			}
		}
	}
}

void korvonalmasolo(Mat img, Mat& dest) {
	Vec3b c;
	Mat hsv;
	cvtColor(img, hsv, COLOR_BGR2HSV);
	for (int i = 0; i < img.rows; ++i)
	{
		for (int j = 0; j < img.cols; ++j) {
			c = img.at<Vec3b>(i, j);
			int hue = hsv.at<Vec3b>(i, j)[0];
			if (hue == 0) {
				dest.at<Vec3b>(i, j) = c;
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
	/*Mat img = imread("C:\\Users\\bleac\\Desktop\\uni\\harmadik felev\\kepfeldolgozas\\kepek\\zold_alma.jpg", IMREAD_COLOR);
	Size newsize(img.cols / 5, img.rows / 5);
	Mat resized(img.size(), img.type());
	resize(img, resized, newsize);
	Vec3b c;
	Mat dest(resized.size(),resized.type(),Scalar(0, 0, 0));
	//imshow("almaxd", img);
	imshow("almkicsi", resized);
	for (int i = 0; i < resized.rows; ++i) {
		for (int j = 0; j < resized.cols; ++j)
		{
			c = resized.at<cv::Vec3b>(i, j);
			if (c[1] > c[0] && c[1] > c[2]) {
				dest.at<cv::Vec3b>(i, j) = c;
			}
		}
	}
	imshow("zoldalam", dest);*/
	/*Mat img = imread("C:\\Users\\bleac\\Desktop\\uni\\harmadik felev\\kepfeldolgozas\\kepek\\piros_alma_sziv.jpg", IMREAD_COLOR);
	Mat dest(img.size(), img.type(), Scalar(0, 0, 0));
	Vec3b c;
	for (int i = 0; i < img.rows; ++i)
	{
		for (int j = 0; j < img.cols; ++j)
		{
			c = img.at<Vec3b>(i, j);
			if (c[2] > c[0] && c[2] > c[1]) {
				dest.at<Vec3b>(i, j) = c;
			}
		}
	}

	imshow("peros", dest);*/
	/*Mat bg = imread("C:\\Users\\bleac\\Desktop\\uni\\harmadik felev\\kepfeldolgozas\\kepek\\hatter_halloween.jpeg", IMREAD_COLOR);
	//imshow("bg", bg);
	Mat dek = imread("C:\\Users\\bleac\\Desktop\\uni\\harmadik felev\\kepfeldolgozas\\kepek\\dekoracio.jpg", IMREAD_COLOR);
	//imshow(" ", dek);
	Vec3b c;
	for (int i = 0; i < dek.rows; ++i) {
		for (int j = 0; j < dek.cols; ++j)
		{
			c = dek.at<Vec3b>(i, j);
			if (bg.rows != i && bg.cols != j) {
				bg.at<Vec3b>(i + 25,j + 300) = c;
				bg.at<Vec3b>(i +  400, j + 300) = c;
			}
		}
	}
	
	imshow("valtoztatott", bg);*/

	/*Mat img = imread("C:\\Users\\bleac\\Desktop\\uni\\harmadik felev\\kepfeldolgozas\\kepek\\m&m.jpg", IMREAD_COLOR);
	Mat dest(img.size(), img.type(), Scalar(0, 0, 0));
	Vec3b c; 
	for (int i = 0; i < img.rows; ++i)
	{
		for (int j = 0; j < img.cols; ++j) {
			c = img.at<Vec3b>(i, j);
			if (c[2] > c[0] && c[2] > c[1]) {
				dest.at<Vec3b>(i, j) = c;
			}
		}
	}
	imshow(" ", dest);*/
	
	//hsv1
	/*Mat img = imread("C:\\Users\\bleac\\Desktop\\uni\\harmadik felev\\kepfeldolgozas\\kepek\\m&m.jpg", IMREAD_COLOR);
	Mat dest(img.size(), img.type(), Scalar(0, 0, 0));
	Mat hsv(img.size(),	CV_8UC3);
	Vec3b c;
	cvtColor(img, hsv, COLOR_BGR2HSV);
	for (int i = 0; i < hsv.rows; ++i)
	{
		for (int j = 0; j < hsv.cols; ++j)
		{
			int hue = hsv.at<Vec3b>(i, j)[0];
			int saturation = hsv.at<Vec3b>(i, j)[1];
			c = img.at<Vec3b>(i, j);
			if (hue > 100 && hue < 120) {
				dest.at<Vec3b>(i,j) = c;
			}
		}
	}
	imwrite("kekem.jpg", dest);*/

	/*Mat img = imread("C:\\Users\\bleac\\Desktop\\uni\\harmadik felev\\kepfeldolgozas\\kepek\\m&m.jpg", IMREAD_COLOR);
	Mat dest(img.size(), img.type(), Scalar(0, 0, 0));
	Mat hsv(img.size(), CV_8UC3);
	Vec3b c;
	cvtColor(img, hsv, COLOR_BGR2HSV);
	for (int i = 0; i < hsv.rows; ++i)
	{
		for (int j = 0; j < hsv.cols; ++j)
		{
			int hue = hsv.at<Vec3b>(i, j)[0];
			int saturation = hsv.at<Vec3b>(i, j)[1];
			c = img.at<Vec3b>(i, j);
			if (hue > 100 && hue < 120) {
				dest.at<Vec3b>(i, j)[1] = 120;
			}
		}
	}
	imshow("kekem.jpg", dest);*/
	
	/*Mat img = imread("C:\\Users\\bleac\\Desktop\\uni\\harmadik felev\\kepfeldolgozas\\kepek\\dekoracio.jpg", IMREAD_COLOR);
	Mat dest(img.size(), img.type(), Scalar(0, 0, 0));
	Mat hsv;
	Vec3b c;
	cvtColor(img, hsv, COLOR_BGR2HSV);
	for (int i = 0; i < img.rows; ++i)
	{
		for (int j = 0; j < img.cols; ++j) {
			c = img.at<Vec3b>(i, j);
			int hue = img.at<Vec3b>(i, j)[0];
			int saturation = img.at<Vec3b>(i, j)[1];
			if (hue > 0 && hue <60) {
				dest.at<Vec3b>(i, j)= c;
			}

		}
	}
	Size newsize(dest.rows / 2, dest.cols);
	int Height = img.rows;
	int Width = img.cols;
	Rect r(0, 160, Width, 160);
	Mat resized = dest(r);
	imshow(" ", resized);*/
	
	/*Mat szolo = imread("C:\\Users\\bleac\\Desktop\\uni\\harmadik felev\\kepfeldolgozas\\kepek\\szolo.jpg", IMREAD_COLOR);
	Size newsize(szolo.rows / 5, szolo.cols / 5);
	Mat resized(szolo.size(), szolo.type());
	resize(szolo, resized, newsize);
	Mat dest(resized.size(), resized.type(), Scalar(0, 0, 0));
	Vec3b c;
	Mat hsv;
	for (int i = 0; i < resized.rows; ++i)
	{
		for (int j = 0; j < resized.cols; ++j)
		{
			int hue = resized.at<Vec3b>(i, j)[0];
			int saturation = resized.at<Vec3b>(i, j)[1];
			c = resized.at<Vec3b>(i, j);
			if ((hue > 20 && hue < 70) && saturation > 70) {
				dest.at<Vec3b>(i, j) = c;
				dest.at<Vec3b>(i, j) = dest.at<Vec3b>(i, j)[2];
			}
		}
	}
	imshow(" ",dest);*/

//An 1
	/*
Mat img = imread("img1.jpg", IMREAD_GRAYSCALE);
imshow(" ", img);*/
//An2
/*Mat img = imread("img2.jpg", IMREAD_COLOR);
Mat dest(img.size(), img.type());
piros_invertalas(img, dest);
imshow("alap", img);
imshow(" ", dest);*/
//An3
	/*Mat img = imread("img3.jpg", IMREAD_COLOR);
	Size newsize(img.rows / 2, img.cols / 2);
	Mat ujgeci(img.size(), img.type());
	resize(img, ujgeci, newsize);
	Mat dest(ujgeci.size(), ujgeci.type(), Scalar(0, 0, 0));
	pirosmasolo(ujgeci, dest);
	imshow("kys", dest);*/

	//An4 
/*Mat img = imread("img4.jpg", IMREAD_COLOR);
Mat dest(img.size(), img.type(), Scalar(255, 255, 255));
zoldmasolo(img, dest);
imshow(" ", dest);*/


//An 5 
/*Mat img = imread("img5.jpg", IMREAD_COLOR);
Mat dest(img.size(), img.type(), Scalar(255, 255, 255));
sparxd(img, dest);

imshow(" ", dest);*/

//An 6
/*Mat img = imread("img6.jpg", IMREAD_COLOR);
Mat dest(img.size(), img.type(), Scalar(255, 255, 255));
lilalufi(img, dest);

imshow(" ", dest);*/

//An 7 
/*Mat img = imread("img7.jpg", IMREAD_COLOR);
Mat dest(img.size(), img.type(), Scalar(255, 255, 255));
pride(img, dest);

imshow(" ", dest);*/

//An 8
/*Mat stitch = imread("img8_2.jpg", IMREAD_COLOR);
Mat bg = imread("img8_1.jpg", IMREAD_COLOR);
Size newsize(500, 500);
Mat newstitch;
resize(stitch, newstitch, newsize);
korvonalmasolo(newstitch, bg);
imshow(" ", bg);
	waitKey();*/

Mat hatter = imread("img8_1.jpg", IMREAD_COLOR);
Mat eloter = imread("img8_2.jpg", IMREAD_COLOR);
resize(eloter, eloter, Size(500, 500));
Mat hsv, korvonal;
Mat dest(eloter.size(), eloter.type(), Scalar(255, 255, 255));


cvtColor(eloter, hsv, COLOR_BGR2HSV);
inRange(hsv, Scalar(0, 0, 0), Scalar(255, 255, 100), korvonal);
eloter.copyTo(dest, korvonal);
imshow(" ", dest);
imshow("2", korvonal);
imshow(" xd", eloter);

masolo(dest, hatter);

imshow("kep.jpg", hatter);
waitKey(0);

	return 0;
}