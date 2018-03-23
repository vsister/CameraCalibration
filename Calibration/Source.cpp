
#include "UI.h"
#include "Calibration.h"

int main() {
	UserInterface UI(20, ".jpg");
	std::vector<cv::Mat> pictures =UI.getPictures();

	Calibration Camera(UI.number,9,6, pictures);
	double d = Camera.Calibrate();

	return 0;
}