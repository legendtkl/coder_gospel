// coder gospel.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include "GenerateImage.h"
#include "Content.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int interval=0, showtime=0;
	
	while(interval==0)
	{
		std::cout << "Please specified the interval time (minute(s)): ";
		std::cin >> interval;
	}

	while(showtime==0)
	{
		std::cout << "Please specified the image showing time (minute(s)): ";
		std::cin >> showtime;
	}

	while(1){
		Sleep(interval*1000*60);
		ImageShow *show = new ImageShow(showtime);
		show->ImageGenerateAndShow();
	}

	return 0;
}

