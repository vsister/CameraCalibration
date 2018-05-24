#include <iostream>
#include <opencv2/opencv.hpp>

#include "Calibration.h"


Calibration::Calibration(cv::Size size, std::vector<cv::Mat> pictures)
	:_size(size),
	_pictures(pictures)
	
{

};

void Calibration::makeimagePoints(std::vector<std::vector<cv::Point2f>>& imagePoints) {
	for (int i = 0; i < _pictures.size(); ++i) 
		bool find = cv::findChessboardCorners(_pictures[i], _size, imagePoints[i], 0);
	
	
} 

void Calibration::realImage(std::vector<cv::Point3f>& objectPoints) {
	for (int j = 0; j < _size.width; ++j) {
		for (int i = 0; i < _size.height; ++i) {
			objectPoints.push_back(cv::Point3f(i, j, 0.));
		}
	}
}

double Calibration::calibration() {
	double calibrate = 0;
	std::vector<cv::Mat> rvecs;
	std::vector<cv::Mat> tvecs;
	std::vector<std::vector<cv::Point3f>> objectPoints(1);
	std::vector<std::vector<cv::Point2f>> imagePoints(_pictures.size());
    makeimagePoints(imagePoints);
	realImage(objectPoints[0]);
	objectPoints.resize(imagePoints.size(), objectPoints[0]);
	calibrate = cv::calibrateCamera(objectPoints, imagePoints, _size, _cameraMat, _distCoeffs, rvecs, tvecs, 0);
	return calibrate;
}

cv::Mat Calibration::getCameraMat() {
	return _cameraMat.clone();
}
cv::Mat Calibration::getDistCoeffs() {
	return _distCoeffs.clone();
}

void Calibration::saveParams(const std::string saveIn)
{
	cv::FileStorage calibFile(saveIn, cv::FileStorage::WRITE);
	calibFile << "Camera_matrix" << _cameraMat;
	calibFile << "Distortion_coefficients" << _distCoeffs;
	calibFile.release();
}

void Calibration::getParams(const std::string takeFrom)
{
	cv::FileStorage calibFile(takeFrom, cv::FileStorage::READ);
	calibFile["Camera_matrix"] >> _cameraMat;
	calibFile["Distortion_coefficients"] >> _distCoeffs;
	calibFile.release();

}