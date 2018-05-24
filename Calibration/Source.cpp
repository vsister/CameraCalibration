#include<iostream>
#include <vector>
#include "UI.h"
#include "Calibration.h"

int main() {
	cv::Size size(9, 6);
	UserInterface UI(20, ".jpg");
	std::vector<std::vector<cv::Point2f>> imagePoints(20);
	std::vector<cv::Mat> pictures =UI.getPictures();
	Calibration Camera(size, pictures);
	double d = Camera.calibration();
	std::cout << "Distortion" << '\n';
	std::cout << Camera.getDistCoeffs();
	std::cout << '\n' << '\n';
	std::cout << "CameraMat" << '\n';
	std::cout << Camera.getCameraMat();
	Camera.saveParams("parametrs.xml");
	return 0;
}