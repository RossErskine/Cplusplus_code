#include <opencv2/opencv.hpp>
#include <iostream>


/* Toy program for using a mouse to draw boxes on the screen
*
*	define our callback which we will install for
*	 mouse events
*/
void my_mouse_callback(int event, int x, int y, int flags, void* param);

cv::Rect box;
bool drawing_box = false;

// a little sub-routine to draw a box onto an image
//
void draw_box(cv::Mat& img, cv::Rect box)
{
	cv::rectangle(img,
		box.tl(),
		box.br(),
		cv::Scalar(0x00,0x00,0xff) //red//
		);
}

void help()
{
	std::cout << "Call: ./ch4_ex4_1\n" <<
		" shows how to use mouse to draw regions in an image. " << std::endl;
}

void chapter9_2()
{
	help();
	box = cv::Rect(-1, -1, -0, 0);
	cv::Mat image(200, 200, CV_8UC3), temp;
	image.copyTo(temp);

	box = cv::Rect(-1, -1, 0, 0);
	image = cv::Scalar::all(0);

	cv::namedWindow("Box Example");

	//Here is the crucial moment where we actually install
	//the callback. note that we set the value of 'params' to
	//be the image we are working with so that the callback
	//will ahve the image to edit
	//
	cv::setMouseCallback("Box Example", my_mouse_callback, (void*)&image);

	// the main program loop here we copy the working image 
	// to the temp image, and if the user is drawing, then 
	// put the currently contemplated box onto that temp image,
	//display the temp image, and wait 15ms for a keystroke,
	// then repeat.
	//
	for (;;) {

		image.copyTo(temp);
		if (drawing_box)draw_box(temp, box);
		cv::imshow("Box Example", temp);

		if (cv::waitKey(15) == 27)break;
	}
	return;
}

void my_mouse_callback(int event, int x, int y, int flags, void* param)
{
	cv::Mat& image = *(cv::Mat*) param;

	switch (event)
	{
	case cv::EVENT_MOUSEMOVE:
		if (drawing_box)
		{
			box.width = x - box.x;

			box.height = y - box.y;
		}
		break;
	case cv::EVENT_LBUTTONDOWN:
		drawing_box = true;
		box = cv::Rect(x, y, 0, 0);
		break;
	case cv::EVENT_LBUTTONUP:
		drawing_box = false;
		if (box.width < 0)
		{
			box.x += box.width;
			box.width *= -1;
		}
		if (box.height < 0)
		{
			box.y += box.height;
			box.height *= -1;
		}
		draw_box(image, box);
		break;
	}
	
}
void chapter9_1()
{
	// create a named window with the name of the file 
	//
	cv::namedWindow("Chapter9_1");

	// load the image from the given filename
	//
	cv::Mat img = cv::imread("kingLuis.jpg");

	// show the image in the named window
	// 
	cv::imshow("Chapter9_1", img);

	// idle until user hits the Esc key
	//
	while (true)
	{
		if (cv::waitKey(100/* milliseconds*/) == 27)break;
	}

	// clean up 
	//
	cv::destroyWindow("Chapter9_1");

	exit(0);

}

void runchapter9()
{
	//chapter9_1();
	chapter9_2();
}
