#include <opencv2/opencv.hpp>

// alphablend <imageA> <imageB>
//
void chapter5_1()
{
	cv::Mat src1 = cv::imread("Paloo.jpg");
	cv::Mat src2 = cv::imread("kingLuis.jpg");

	if (!src1.empty() && !src2.empty())
	{
		int x = 200;
		int y = 250;
		int w = 100;
		int h = 50;
		double alpha = 150;
		double beta = 20;

		cv::Mat roi1(src1, cv::Rect(x, y, w, h));
		cv::Mat roi2(src1, cv::Rect(0, 0, w, h));

		cv::addWeighted(roi1, alpha, roi2, beta, 0.0, roi1);

		cv::namedWindow("Alpha blend", 1);
		cv::imshow("Alpha blend", src2);
		cv::waitKey(0);
		

	}
}

void runChapter5()
{
	chapter5_1();
}
