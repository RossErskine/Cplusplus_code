#include <opencv2/opencv.hpp>
#include <iostream>

cv::RNG rng = cv::theRNG();

void exercise7_3()
{
	cv::Mat matInt100 = cv::Mat(100, 1, CV_32FC3, cv::Scalar(0));
	// the first and second dimension have a Guassian distribution, centered 
	// 64 & 192 with variance of 10
	//
	vector<cv::Mat> planes;
	split(matInt100, planes);
	rng.fill(planes[0], cv::RNG::NORMAL, 64, 10);
	rng.fill(planes[1], cv::RNG::NORMAL, 192, 10);

	// the third dimension has a gaussion distribution cenered 128 
	// with variance of 2
	//
	rng.fill(planes[2], cv::RNG::NORMAL, 128, 2);

	// cusing PCA object, compute projection maxComponent=2;
	//
	cv::PCA pca(planes[0], cv::Mat(), CV_PCA_DATA_AS_ROW, 2);
	planes[0] = pca.project(planes[0]);
	pca(planes[1], cv::Mat(), CV_PCA_DATA_AS_ROW, 2);
	planes[1] = pca.project(planes[1]);
	pca(planes[2], cv::Mat(), CV_PCA_DATA_AS_ROW, 2);
	planes[2] = pca.project(planes[2]);

	// compute mean in both dimensions 
	//
	float f1 = 0;
	float f2 = 0;
	float f3 = 0;
	for (int i = 0; i < 100; i++)
	{
		f1 += planes[0].at<float>(i, 0);
		f2 += planes[1].at<float>(i, 0);
		f3 += planes[2].at<float>(i, 0);
	}
	f1 = f1 / 100;
	f2 = f2 / 100;
	f3 = f3 / 100;
}

void exercise7_2()
{
	// using fill of RNG create array of 20 floating-point numbers 0.0  1.0
	//
	cv::Mat matFloat20 = cv::Mat(20, 1, CV_32FC1, cv::Scalar(0));
	rng.fill(matFloat20, cv::RNG::UNIFORM, 0.f, 1.f);

	//using fill of RNG create array of 20 floating - point numbers using Gaussian distribution 0.0  1.0
	//
	rng.fill(matFloat20, cv::RNG::NORMAL, 0.f, 1.f);

	// 20 unsigned bytes uniform distribution 0 & 255
	//
	cv::Mat matUbyte20 = cv::Mat(20, 1, CV_8UC1, cv::Scalar(0));
	rng.fill(matUbyte20, cv::RNG::UNIFORM, 0, 255);

	// 20 color triplets each of 3 bytes 0 & 255
	cv::Mat matColor20 = cv::Mat(20, 1, CV_8UC3, cv::Scalar(0));
	rng.fill(matColor20, cv::RNG::UNIFORM, 0, 255);
}

void exercise7_1()
{
	
	// generate 3 floating point random numbers between 0.0 & 1.0
	//
	float f1 = rng.uniform(0.f, 1.f);
	float f2 = rng.uniform(0.f, 1.f);
	float f3 = rng.uniform(0.f, 1.f);

	std::cout << "F1: " << f1 << ", F2: " << f2
		<< ", F3: " << f3 << std::endl;

	//  generate 3 double precision numbers using Gaussian distribution 
	// between 0.0 & 1.0
	//
	cv::Vec3d vec3d;
	rng.fill(vec3d, cv::RNG::NORMAL, 0., 1.);

	std::cout << "D1: " << vec3d[0] << ", D2: " << vec3d[1]
		<< ", D3: " << vec3d[2] << std::endl;

	// generate 3 unsigned bytes between 0 & 255
	//
	unsigned byte1 = rng.uniform(0, 255);
	unsigned byte2 = rng.uniform(0, 255);
	unsigned byte3 = rng.uniform(0, 255);

	std::cout << "Byte1: " << byte1 << ", Byte2: " << byte2
		<< ", Byte3: " << byte3 << std::endl;
}

void runChapter7()
{
	exercise7_1();
	exercise7_2();
	exercise7_3();
}
