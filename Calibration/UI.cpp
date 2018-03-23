#include <iostream>
#include <opencv2/opencv.hpp>

#include "Calibration.h"
#include "UI.h"

UserInterface::UserInterface(int number, std::string ending) 
	:number(number),
	ending(ending)
{
};


 std::vector<cv::Mat> UserInterface::getPictures(){
	std::string picname = "";
	std::vector<cv::Mat> pictures(number);
	char c = 'A';
		for (int k = 0; k < number; ++k) {
		picname = c + ending;
		++c;
		pictures[k] = cv::imread(picname, cv::IMREAD_GRAYSCALE);
	}
		return pictures;
}