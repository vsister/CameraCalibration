#include <iostream>
#include <opencv2/opencv.hpp>
#include "UI.h"

UserInterface::UserInterface(int number, std::string ending) 
	:_number(number),
	_ending(ending)
{
};

 std::vector<cv::Mat> UserInterface::getPictures(){
	std::string picname = "";
	std::vector<cv::Mat> pictures(_number);
	char c = 'A';
		for (int k = 0; k < _number; ++k) {
		picname = c + _ending;
		++c;
		pictures[k] = cv::imread(picname, cv::IMREAD_GRAYSCALE);
	}
		return pictures;
}