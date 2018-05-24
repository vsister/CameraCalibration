/**
* /brief Header file containing the description of the class UserInterface.
*/
#ifndef CALIBRATION_UI_H_
#define CALIBRATION_UI_H_
#include <iostream>
#include <opencv2/opencv.hpp>

#include <string>
#include <vector>

class UserInterface
{
private:

	/**
	* \brief Number of images.
	*/
	int _number; 

	/**
	* \brief Image files' extension.
	*/
	std::string _ending;
public:

	/**
	* \brief UserInterface constructor.
	* \param[in] number Number of pictures.
	* \param[in] ending Image files' extension.
	*/
	UserInterface(int number, std::string ending);

	/**
	* \brief Making a vector of images.
	*/
	std::vector<cv::Mat> getPictures();
   
};



#endif 

