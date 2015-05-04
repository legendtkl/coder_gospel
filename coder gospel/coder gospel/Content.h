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
	//��Ļÿ�п������ɵ�����ַ�����
	int MaxCharNumPerLine;
	//��Ļ��������ʾ������
	int MaxLineNumShow;
};

#endif