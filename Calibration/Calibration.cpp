#include <iostream>
#include <opencv2/opencv.hpp>

#include "UI.h"
#include "Calibration.h"


Calibration::Calibration(int number, int width, int height)
	: number(number),
	width(width), 
	height(height)
{
};

void Calibration::makeimagePoints(std::vector<cv::Mat> pictures,int number, int width, int height, std::vector<cv::Point2f>& imagePoints) {
	cv::Size ImageSize(width, height);
	for (int i = 0; i < number; ++i)
		bool find = cv::findChessboardCorners(pictures[i], ImageSize, imagePoints,0);
	
} 

void Calibration::realImage(std::vector<cv::Point3f>& objectPoints, int width, int height) {

	for (int j = 0; j < width; ++j) {
		for (int i = 0; i < height; ++i) {
			objectPoints.push_back(cv::Point3f(i, j, 0.));
		}
	}
}

 
double Calibration::Calibrate() {
	std::vector<std::vector<cv::Point3f>> objectPoints(1);
	std::vector<std::vector<cv::Point2f>> imagePoints(number);
	std::vector<cv::Mat> pictures(number);
	for (int i=0; i<number;++i)
	UserInterface::vectorOfpictures(i, pictures[i], ".jpg");
	cv::Size ImageSize(width, height);
	for (int i = 0; i<number; ++i)
		makeimagePoints(pictures, number, width, height, imagePoints[i]);
	realImage(objectPoints[0], width, height);
	objectPoints.resize(imagePoints.size(), objectPoints[0]);
	calibrate = cv::calibrateCamera(objectPoints, imagePoints, ImageSize, cameraMat, distCoeffs, rvecs, tvecs, 0);
	return calibrate;
}
