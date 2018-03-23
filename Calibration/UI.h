#ifndef CALIBRATION_UI_H_
#define CALIBRATION_UI_H_
#include <iostream>
#include <opencv2/opencv.hpp>

class UserInterface
{
public:
	int number; 
	std::string ending;
	UserInterface(int number, std::string ending);
	std::vector<cv::Mat> getPictures();
   
};



#endif 

