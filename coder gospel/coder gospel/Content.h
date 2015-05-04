#ifndef __CONTENT_H__
#define __CONTENT_H__

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>
#include <direct.h>
#include <time.h>
#include <vector>

using std::vector;
using std::cout;
using std::string;


class Content{
public:
	Content(int charNum, int lineNum);
	~Content();
	bool ContentGenerate();
	int FileLineCount();
	vector<string> *contentShow;
private:
	//屏幕每行可以容纳的最多字符个数
	int MaxCharNumPerLine;
	//屏幕最多可以显示多少行
	int MaxLineNumShow;
};

#endif