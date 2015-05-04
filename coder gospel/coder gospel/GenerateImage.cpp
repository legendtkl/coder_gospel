#include "stdafx.h"
#include "GenerateImage.h"


ImageShow::ImageShow(int _showTime)
{
	showTime = _showTime*1000*60;
}

ImageShow::~ImageShow()
{
}

void ImageShow::ImageGenerateAndShow()
{
	//调节字体等属性
	int fontFace = cv::FONT_HERSHEY_SIMPLEX;
	std::string text("HelloWorld"); 

	double fontScale = 3;
	int thickness = 2 ;

	int baseline=0;
	cv::Size textSize = cv::getTextSize(text, fontFace, fontScale, thickness, &baseline);
	
	int fontHeight = textSize.height;

	//获得屏幕分辨率
	int nFullWidth = GetSystemMetrics(SM_CXSCREEN);//横向
	int nFullHeight = GetSystemMetrics(SM_CYSCREEN);//纵向

	Content *tent = new Content((nFullHeight*10/textSize.width), (nFullWidth*4/5)/(3*textSize.height/2));
	while(!tent->ContentGenerate());
	//获得需要显示的内容，存在ptext里
	std::cout << "contentShow size: " << (*tent->contentShow).size() << std::endl;
	std::vector<std::string> ptext = *tent->contentShow;
	std::cout << "ptext size: " << ptext.size() << std::endl;
	for(int i=0; i<ptext.size(); i++)
		std::cout << ptext[i] << std::endl;

	cv::Mat img(nFullWidth, nFullHeight, CV_8U, cv::Scalar::all(0));
	cv::Mat imgdst(nFullHeight, nFullWidth, CV_8U, cv::Scalar::all(0));

	//一行字的左下角坐标
	cv::Point textOrg;

	int i, pos=3*fontHeight;
	for(i=0; i<ptext.size()&&i*fontHeight+nFullHeight/5 + i*fontHeight/3 < img.rows*4/5; i=i+2)
	{
		textSize = cv::getTextSize(ptext[i], fontFace, fontScale, thickness, &baseline);
		textOrg.x = (img.cols-textSize.width)/2;
		textOrg.y = pos;
		cv::putText(img, ptext[i], textOrg, fontFace, fontScale, cv::Scalar::all(255), thickness, 8);
		pos += 3*fontHeight;
	}
	cv::flip(img, img, 0);
	cv::flip(img, img, 1);

	if(ptext.size()%2)
	{
		i=i-3;
		pos = nFullWidth - textOrg.y + 5*fontHeight/2;
	}
	else{
		--i;
		pos = nFullWidth - textOrg.y - fontHeight/2;
	}
	std::cout << "i= " << i << std::endl;
	for(; i>0; i=i-2)
	{
		std::cout << ptext[i] << std::endl;
		textSize = cv::getTextSize(ptext[i], fontFace, fontScale, thickness, &baseline);
		textOrg.x = (img.cols-textSize.width)/2;
		textOrg.y = pos;
		cv::putText(img, ptext[i], textOrg, fontFace, fontScale, cv::Scalar::all(255), thickness, 8);
		pos += 3*fontHeight;
	}
	
	//transpose the image 90 degree anticlockwise
	cv::flip(img, img, 0);
	cv::flip(img, img, 1);
	cv::transpose(img, imgdst);
	cv::flip(imgdst, imgdst, 0);

	cv::imwrite("test5.jpg", imgdst);
	initShowWindow();
	ImageShowing(imgdst);
	destroyShowWindow();
}

void ImageShow::initShowWindow()
{
	cvNamedWindow("Projector Window", CV_WINDOW_NORMAL);
	cvSetWindowProperty("Projector Window", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);
}

void ImageShow::ImageShowing(cv::Mat img)
{
	//cv::Mat img = cv::imread("E:\\lena.jpg",0);
	IplImage ipl_img = img;
	cvShowImage("Projector Window", &ipl_img);
	cvWaitKey(showTime);
}

void ImageShow::destroyShowWindow()
{
	cvDestroyWindow("Projector Window");
}