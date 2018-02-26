#include <iostream>
#include <opencv2/opencv.hpp>

#include "Calibration.h"
#include "UI.h"

void UserInterface::vectorOfpictures(int i, cv::Mat& pictures, std::string ending) {

	std::string picname = "";
		char c = char(i) + 65;
		picname = c + ending;
		pictures = cv::imread(picname, cv::IMREAD_GRAYSCALE);

	
}