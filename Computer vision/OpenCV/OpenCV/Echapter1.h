#include <opencv2/opencv.hpp>
#include <iostream>

void Echapter1_1()
{
	int flip_code = -1;
	cv::Mat out_image; // Output image
	
	cv::Mat in_image = cv::imread("Paloo.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	if (in_image.empty()) { // Check if read
		throw "Error! Input image cannot be read...\n";
		
	}
	
	flip(in_image, out_image, flip_code);
	imwrite("Paloof.jpg", out_image); // Write image to file
	cv::namedWindow("Flipped…"); // Creates a window
	imshow("Flipped…",out_image); // Shows output image on window
	std::cout << "Press any key to exit...\n";
	cv::waitKey(); // Wait infinitely for key press
	

}

void runEchapter1()
{
	
	Echapter1_1();
}
