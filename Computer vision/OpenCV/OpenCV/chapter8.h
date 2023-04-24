#include <opencv2/opencv.hpp>
#include <iostream>
#include <fstream>
#include <time.h>

//Using cv::Filestorage to read a .yml file
// 
void chapter8_3()
{
	cv::FileStorage fs2("test.yml", cv::FileStorage::READ);

	// first method: use (type) operator on FileNode.
	//
	int frameCount = (int)fs2["frameCount"];

	// second method: use cv::FileNode::operator >>
	//
	std::string date;
	fs2["calibrationDate"] >> date;

	cv::Mat cameraMatrix2, distCoeffs2;
	fs2["cameraMatrix"] >> cameraMatrix2;
	fs2["distCoeffs"] >> distCoeffs2;

	cout << "frameCount: " << frameCount << endl
		<< "calibration date: " << date << endl
		<< "camera matrix: " << cameraMatrix2 << endl
		<< "distortion coeffs: " << distCoeffs2 << endl;

	cv::FileNode features = fs2["features"];
	cv::FileNodeIterator it = features.begin(), it_end = features.end();
	int idx = 0;
	std::vector<uchar> lbpval;

	// iterate through a sequence using FileNodeIterator
	for (; it != it_end; ++it, idx++) {

		cout << "feature #" << idx << ": ";
		cout << "x=" << (int)(*it)["x"]
			<< ", y=" << (int)(*it)["y"]
			<< ", lbp: (";

		// ( Note: easily read numerical arrays using FileNode >> std::vector. )
		//
		(*it)["lbp"] >> lbpval;
		for (int i = 0; i < (int)lbpval.size(); i++)
			cout << " " << (int)lbpval[i];
		cout << ")" << endl;

	}

	fs2.release();
}

// Using cv::Filestorage to create a .yml data file
//
void chapter8_2()
{
	cv::FileStorage fs("test.yml", cv::FileStorage::WRITE);

	fs << "frameCount" << 5;

	/*time_t rawtime; time(&rawtime);
	char *s2 = asctime(localtime(&rawtime));
	fs << "calibrationDate" << s2 ;*/

	cv::Mat cameraMatrix = (cv::Mat_<double>(3, 3)
		<< 1000, 0, 320, 0, 1000, 240, 0, 0, 1);
	cv::Mat distCoeffs = (cv::Mat_<double>(5, 1)
		<< 0.1, 0.01, -0.0001, 0, 0);
	fs << "cameraMatrix" << cameraMatrix << " distCoeffs" << distCoeffs;

	fs << "features" << "[";
	for (int i = 0; i < 3; i++)
	{
		int x = rand() % 640;
		int y = rand() % 480;
		uchar lbp = rand() & 256;

		fs << "{:" << "x" << x << "y" << y << "lbp" << "[:";
		for(int j = 0; j< 8; j++)
		{
			fs << ((lbp >> j) & 1);
		}
		fs << "]" << "}";
	}
	fs << "]";
	fs.release();
}


// Unpacking a four-character code to indentify a video codec
//
void chapter8_1()
{
	cv::VideoCapture cap("rooney.mp4");

	unsigned f = (unsigned)cap.get(cv::CAP_PROP_FOURCC);
	char fourcc[] = {
		(char)f,			// first character is lowest bits
		(char)(f >> 8),		//Next character is bits 8 - 15
		(char)(f >> 16),	//Next character is bits 16 - 23
		(char)(f >> 24),	//Last character is bits 24 - 31
		'\0'				// and don't forget to terminate
	};
}

void runChapter8()
{
	//chapter8_1();
	chapter8_2();
}