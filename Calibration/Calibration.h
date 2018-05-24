/**
* \brief Header file containing the description of the class Calibration.
*/
#ifndef CALIBRATION_CALIBRATION_H_
#define CALIBRATION_CALIBRATION_H_
#include <iostream>
#include <opencv2/opencv.hpp>

#include <vector>

class Calibration 
{
private:

	/**
	* \brief  Vector of pictures used for calibration.
	*/
	std::vector<cv::Mat> _pictures;

	/**
	* \brief Size of chessboard pattern (Number of items by width and height).
	*/
	cv::Size _size;

	/**
	* \brief Camera intistic parameters (Camera matrix).
	*/
	cv::Mat _cameraMat;

	/**
	* \brief Distortion coefficients = (k1 k2 p1 p2 k3).
	*/
	cv::Mat _distCoeffs;

public:

	/**
	* \brief Calibration constructor.
	* \param[in] size Size of chessboard pattern (Number of items by width and height).
	* \param[in] pictures Vector of images of chessboard pattern.
	*/
	Calibration(cv::Size size, std::vector<cv::Mat> pictures);
		
private:

	/**
	* \brief Finding corners on each image of the vector.
	* \param[out] imagePoints Coordinates of chessboard corners found on the image.
	*/
	void makeimagePoints(std::vector<std::vector<cv::Point2f>>& imagePoints);

	/**
	* \brief Creating a chessboard pattern.
	* \param[out] objectPoints Vector of created images of chessboard pattern.
	*/
	void realImage(std::vector<cv::Point3f>& objectPoints);

 public:

	 /**
	 * \brief Determinating camera parameters.
	 */
	double calibration();

	/**
	* \brief Getting camera matrix.
	*/
	cv::Mat getCameraMat();

	/**
	* \brief Getting distortion coefficients.
	*/
	cv::Mat getDistCoeffs();

	/**
	* \brief Saving camera parameters in the XML file.
	* \param[in] saveIn Name of the file.
	*/
	void saveParams(const std::string saveIn);

	/**
	* \brief Getting camera parametrs from the XML file.
	* \param[in] takeFrom Name of the file.
	*/
	void getParams(const std::string takeFrom);
};

#endif