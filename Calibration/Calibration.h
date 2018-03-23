#ifndef CALIBRATION_CALIBRATION_H_
#define CALIBRATION_CALIBRATION_H_
#include <iostream>
#include <opencv2/opencv.hpp>

#include "UI.h"

class Calibration 
{
	public:
		double calibrate;
		int  number;
		int height;
		int width;
		std::vector<cv::Mat> pictures;
		cv::Mat cameraMat;
		std::vector<float> distCoeffs;
		std::vector<cv::Mat> rvecs;
		std::vector<cv::Mat > tvecs;
		

		Calibration(int number, int width, int height, std::vector<cv::Mat> pictures);
		

	static void makeimagePoints(std::vector<cv::Mat> pictures, int number, int width, int height,
		                        std::vector<std::vector<cv::Point2f>>& imagePoints);
	static void realImage(std::vector<cv::Point3f>& objectPoints, int width, int height);
	double Calibrate();



};

#endif