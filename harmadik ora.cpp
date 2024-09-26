#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

void narancsmasolo(const cv::Mat fg, cv::Mat& bg) {//atmasolja a narancssarga reszeket egy masik kepre
	bg = Mat::zeros(fg.size(), fg.type());
	//Vec3b c;
	//Vec3b narancs(255, 165, 0);
	for (int i = 0; i < fg.rows; ++i) {
		for (int j = 0; j < fg.cols; ++j) {
			Vec3b c = fg.at<Vec3b>(i, j);
			if (c[0] < c[2] && c[1] < c[2]) {
				bg.at<Vec3b>(i, j) = c;
			}
		}
	}
}

void narancsmasoloHSV(const cv::Mat fg, cv::Mat& bg) {//kb ugyanaz mint az elozo, de hsv skalan van ertelmezve
	bg = Mat::zeros(fg.size(), fg.type());
	Mat hsv;
	cvtColor(fg, hsv, COLOR_BGR2HSV);//szin konverzio
	for (int i = 0; i < fg.rows; ++i) {
		for (int j = 0; j < fg.cols; ++j) {
			Vec3b c = hsv.at<Vec3b>(i, j);
			if (c[0] < 30) {
				bg.at<Vec3b>(i, j) = fg.at<Vec3b>(i,j);
			}
		}
	}
}

void narancsmasoloMask(const cv::Mat fg, cv::Mat& bg) {//maskkal
	bg = Mat::zeros(fg.size(), fg.type());
	Mat hsv;
	cvtColor(fg, hsv, COLOR_BGR2HSV); 
	Mat mask;
	inRange(hsv, Scalar(0, 0, 0),
		Scalar(30, 255, 255), mask);
	fg.copyTo(bg, mask);//allitolag igy konnyebb mint for ciklussal
	/*for (int i = 0; i < fg.rows; ++i) {
		for (int j = 0; j < fg.cols; ++j) {
			Vec3b c = hsv.at<Vec3b>(i, j);
			if (c[0] < 30) {
				bg.at<Vec3b>(i, j) = fg.at<Vec3b>(i, j);
			}
		}
	}*/
}

void tehenfesto(cv::Mat fg) {//atszinez egy adott reszt
	Mat hsv;
	cvtColor(fg, hsv, COLOR_BGR2HSV);
	for (int i = 0; i < fg.rows; ++i) {
		for (int j = 0; j < fg.cols; ++j) {
			Vec3b c = hsv.at<Vec3b>(i, j);
			if (c[0] > 130) {
				hsv.at<Vec3b>(i, j)[0] = 20;
			}
		}
	}
	cvtColor(hsv, fg, COLOR_HSV2BGR);
}

//egy kep eseten egyszeru bejaras
void tehenfesto2(cv::Mat fg) {
	Mat hsv;
	cvtColor(fg, hsv, COLOR_BGR2HSV);
	Mat_<Vec3b> hs = hsv;
	for (auto& p : hs) {
		if (130 < p[0])
			p[0] = 20;
	}
	cvtColor(hsv, fg, COLOR_HSV2BGR);
	
}

void Mormota(cv::Mat fg, cv::Mat bg) {
	Mat hsv, mask;
	cvtColor(fg, hsv, COLOR_BGR2HSV);
	inRange(hsv, Scalar(100, 0, 0),
		Scalar(130, 255, 255), mask);
	mask = 255 - mask;
	//imshow("img", mask);
	Rect r(50, 50, fg.cols, fg.rows);
	imshow(" ", bg(r));
	fg.copyTo(bg(r), mask);
	imshow("img", mask);
	waitKey();
}

void conver(const  Mat img, Mat& lab) {
	Mat imgf;
	img.convertTo(imgf, CV_32FC3, 1 / 255.0);
	cvtColor(imgf, lab, COLOR_BGR2Lab);
}
int main() {

	//Mat kep = imread("C:\\Users\\bleac\\Desktop\\uni\\harmadik felev\\kepfeldolgozas\\orange1.jpg", IMREAD_COLOR);
	//Mat bg;
	//Mat milka = imread("C:\\Users\\bleac\\Desktop\\uni\\harmadik felev\\kepfeldolgozas\\milka.jpg");
	//Mat mormota = imread("C:\\Users\\bleac\\Desktop\\uni\\harmadik felev\\kepfeldolgozas\\mormota_kekhatter.jpg");
	Mat deik = imread("C:\\Users\\bleac\\Desktop\\uni\\harmadik felev\\kepfeldolgozas\\Deik.jpg");
	/*narancsmasolo(kep, bg);
	imshow("narancs", bg);
	narancsmasoloMask(narancs, hsv2);
	imshow("hsv", hsv2);*/
	//tehenfesto2(milka);
	//imshow("tehen", milka);
	Mat lab;
	conver(deik, lab);
	Vec3f p = lab.at<Vec3f>(0.0);
	Vec3f p2 = lab.at<Vec3f>(0, 1);
	cout << cv::norm(p - p2) << endl;

	

	waitKey();

	
}