//-------------------------------------------------------------------------------------------
//* CopyRight: taokelu@gmail.com
//* 2013-11-18
//
//
//--------------------------------------------------------------------------------------------


#ifndef __GENERATE_IMAGE_H__
#define __GENERATE_IMAGE_H__

#include "stdafx.h"
#include <string>
#include "cv.h"
#include "highgui.h"
#include "cxcore.h"
#include "opencv.hpp"
#include "Content.h"
#include <windows.h>
#include <vector>

using namespace std;

class ImageShow
{
public:
	ImageShow(int _showTime);
	~ImageShow();
	void ImageGenerateAndShow();
	void ImageShowing(cv::Mat img);
	void initShowWindow();
	void destroyShowWindow();
private:
	int showTime;
};

#endif