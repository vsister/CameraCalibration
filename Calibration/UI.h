#ifndef CALIBRATION_UI_H_
#define CALIBRATION_UI_H_
#include <iostream>
#include <opencv2/opencv.hpp>

class UserInterface
{
public:
	static void vectorOfpictures(int i, cv::Mat& pictures, std::string ending = ".jpg");
};



#endif 

