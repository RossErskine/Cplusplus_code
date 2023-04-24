#include <opencv2/opencv.hpp>
#include<iostream>
#include <fstream>
using namespace std;

void exercise3()
{
	cv::namedWindow("Exercise_3", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("PryDown", cv::WINDOW_AUTOSIZE);

	cv::VideoCapture capture(int(0));

	double fps = capture.get(cv::CAP_PROP_FPS);
	cv::Size size((int)capture.get(cv::CAP_PROP_FRAME_WIDTH),
		(int)capture.get(cv::CAP_PROP_FRAME_HEIGHT)
	);
	cv::VideoWriter writer;
	writer.open("PryDown.mp4", CV_FOURCC('M', 'P', '4', 'V'), fps, size);	// codec works for mp4

	cv::Mat pryDown_frame, bgr_frame;
	for (;;)
	{
		capture >> bgr_frame;
		if (bgr_frame.empty()) break;	 //end if done

		cv::imshow("Exercise_3", bgr_frame);
		cv::pyrDown(bgr_frame, pryDown_frame);

		cv::imshow("PryDown", pryDown_frame);
		writer << pryDown_frame;

		char c = cv::waitKey(10);
		if (c == 27) break;
	}
	capture.release();

}

// a complete program to read in a color video and write out the log-polar transformed video
//
void example2_11()
{
	cv::namedWindow("Example2_11", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Log_Polar", cv::WINDOW_AUTOSIZE);

	//( note: could capture from a camera by giving a camera id as an int.)
	//
	cv::VideoCapture capture("rooney.mp4");

	double fps = capture.get(cv::CAP_PROP_FPS);
	cv::Size size((int)capture.get(cv::CAP_PROP_FRAME_WIDTH),
		(int)capture.get(cv::CAP_PROP_FRAME_HEIGHT)
	);

	cv::VideoWriter writer;
	writer.open("rooney.mp4", CV_FOURCC('M', 'P', '4', 'V'), fps, size);	// codec works for mp4

	cv::Mat logpolar_frame, bgr_frame;
	for (;;) {

		capture >> bgr_frame;
		if (bgr_frame.empty()) break;	 //end if done

		cv::imshow("Example2_11", bgr_frame);

		cv::logPolar(
			bgr_frame,					// input color frame
			logpolar_frame,				//Output log-polar frame 
			cv::Point2f(				//Centerpoint for log-polar transformation
				bgr_frame.cols /2,		// x
				bgr_frame.rows /2		// y
			),
			50,							//Magnitude (scale parameter)
			cv::WARP_FILL_OUTLIERS		//Fill outliers with 'zero'
		);

		cv::imshow("Log_Polar", logpolar_frame);
		writer << logpolar_frame;

		char c = cv::waitKey(10);
		if (c == 27) break;
	}
	capture.release();


}

void example2_10()
{
	cv::VideoCapture cap;

	cap.open(0);	//default camera

	if (!cap.isOpened()) {
		cerr << "Could't open capture." << endl;
	}
	cv::Mat frame;
	for (;;) {
		cap.read(frame);
		if (frame.empty())break;
		imshow("Live", frame);
		if (cv::waitKey(33) >= 0)break;
	};
}

// combinig the pyrmid down operator(twice) and the canny subroutine in a simple image pipeline
//
//getting the setting pixels in example2_8
//
void example2_89()
{
	//example 8
	cv::Mat img_rgb, img_gry, img_cny, img_pyr, img_pyr2;

	cv::namedWindow("Example Gray", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example Canny", cv::WINDOW_AUTOSIZE);

	img_rgb = cv::imread("Paloo.jpg");

	cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
	cv::pyrDown(img_gry, img_pyr);
	cv::pyrDown(img_pyr, img_pyr2);
	cv::Canny(img_pyr2, img_cny, 10, 100, 3, true);
	cv::imshow("Example Canny", img_cny);

	//example 9
	int x = 16, y = 32;
	cv::Vec3b intensity = img_rgb.at < cv::Vec3b >(y, x);

	uchar blue = intensity[0];
	uchar green = intensity[1];
	uchar red = intensity[2];

	cout << "At (x, y) = (" << x << ", " << y <<
		"): (blue, green, red) = (" <<
		(unsigned int)blue <<
		", " << (unsigned int)green << ", " <<
		(unsigned int)red << ")" << endl;

	cout << "Gray pixel there is: " <<
		(unsigned int)img_gry.at<uchar>(y, x) << endl;

	x /= 4; y /= 4;
	cout << "Pyramid2 pixel there is: " <<
		(unsigned int)img_pyr2.at<uchar>(y, x) << endl;

	img_cny.at<uchar>(x, y) = 128; // set the canny pixel there to 128

	cv::waitKey(0);
}

// the canny edge detector writes its output to single-channel(grayscale)image
//
void example2_7()
{
	cv::Mat img_rgb, img_gry, img_cny;

	cv::namedWindow("Example Gray", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example Canny", cv::WINDOW_AUTOSIZE);

	img_rgb = cv::imread("morning.jpg");

	cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
	cv::imshow("Example Gray", img_gry);

	cv::Canny(img_gry, img_cny, 10, 100, 3, true);
	cv::imshow("Example Canny", img_cny);

	cv::waitKey(0);
}
//using cv::pyrDown to create a new image that is half the width and half the height of input image
//
void example2_6()
{
	cv::Mat img1, img2;

	cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example2", cv::WINDOW_AUTOSIZE);

	img1 = cv::imread("kingLuis.jpg");
	cv::imshow("Example1", img1);

	cv::pyrDown(img1, img2);
	cv::imshow("Example2", img2);

	cv::waitKey(0);

}
//loading and then smoothing an image before it is displayed on the screen
//
void example2_5(const cv::Mat& image)
{
	//create some windows to show the input
	// and output images in
	//
	cv::namedWindow("Example2_5-in", cv::WINDOW_NORMAL);
	cv::namedWindow("Example2_5-out", cv::WINDOW_NORMAL);

	//create a window to show our input image
	//
	cv::imshow("Example2_5-in", image);

	//create an image to hold the smoothed output
	//
	cv::Mat out;

	// do the smoothing
	//(note: could use GaussianBlur(), blur(), medinBlur() or bilateralFilter()
	cv::GaussianBlur(image, out, cv::Size(5, 5), 3, 3);
	cv::GaussianBlur(image, out, cv::Size(5, 5), 3, 3);

	//show the smoothed image in output window
	//
	cv::imshow("Example2_5", out);

	//wait for the user to hit a key, windows will self destruct
	//
	cv::waitKey(0);
}
void displayExample2_5()
{
	cv::Mat img = cv::imread("kingLuis.jpg");
	if (img.empty())return;

	example2_5(img);
	cv::waitKey(0);
}
// adding a trackbar slider to the basic viewer window for moving around within the video file
//
int g_slider_position = 0;
int g_run = 1, g_dontset = 0; //start out in single step mode
cv::VideoCapture g_cap;

void onTrackbarSlide(int pos, void *)
{
	g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);

	if (!g_dontset)
		g_run = 1;
	g_dontset = 0;
}

void trackbarSlide()
{
	cv::namedWindow("example2_4", cv::WINDOW_AUTOSIZE);
	g_cap.open("rooney.mp4");
	int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT);
	int tmpw = (int)g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
	int tmph = (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);

	cout << "Video has " << frames << " frames of dimensions("
		<< tmpw << ", " << tmph << ")." << endl;

	cv::createTrackbar("Position", "example2_4", &g_slider_position, frames, onTrackbarSlide);

	cv::Mat frame;
	for (;;)
	{
		if (g_run != 0)
		{
			g_cap >> frame; if (frame.empty())break;
			int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
			g_dontset = 1;

			cv::setTrackbarPos("Position", "example2_4", current_pos);
			cv::imshow("example2_4", frame);

			g_run -= 1;
		}

		char c = (char)cv::waitKey(10);
		if (c == 's')		// single step
		{
			g_run = 1;
			cout << "Single step, run = " << g_run << endl;
		}
		if (c == 'r')
		{
			g_run = -1;
			cout << "Run mode, run = " << g_run << endl;
		}
		if (c == 27)
			break;
	}

}
// displayes video
//
void displayVideo()
{
	cv::namedWindow("example #2", cv::WINDOW_NORMAL);
	cv::VideoCapture cap;
	cap.open("rooney.mp4");

	cv::Mat frame;
	for (;;) {
		cap >> frame;
		if (frame.empty())break;
		imshow("example #2", frame);
		if (cv::waitKey(33) >= 0)break;
	}
}
// displays image
//
void displayImage()
{
	cv::Mat img = cv::imread("Typical_house_ground_floor_plan.png");
	cv::namedWindow("example #1", cv::WINDOW_AUTOSIZE);
	if (img.empty())return;
	imshow("example #1", img);
	cv::waitKey(0);
}
void runChapter2()
{
	//displayImage();
	//displayVideo();
	//trackbarSlide();
	//displayExample2_5();
	//example2_6();
	example2_7();
	//example2_89();
	//example2_10();
	//example2_11();
	//exercise3();
}
