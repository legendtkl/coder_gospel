#include "stdafx.h"
#include "Content.h"

Content::Content(int charNum, int lineNum)
{
	MaxCharNumPerLine = charNum;
	MaxLineNumShow = lineNum;

	contentShow = new std::vector<std::string>;
	(*contentShow).reserve(MaxLineNumShow);
}

Content::~Content()
{
	if(contentShow)
		delete contentShow;
}

bool Content::ContentGenerate()
{
	srand((int)time(NULL));
	int line = rand()%FileLineCount();

	_chdir("data/");
	std::ifstream out;
	out.open("data.txt");

	if(!out)
	{
		cout << "Error: unable to open the data.txt\n";
		exit(-1);
	}

	string showStr;
	while(line>0)
	{
		getline(out, showStr);
		line--;
	}
	out.close();
	if(showStr.size() > MaxCharNumPerLine*MaxLineNumShow*4/5)
		return false;

	int aveLength = showStr.size()/MaxLineNumShow;
	int pos=0;
	int	i=3*MaxCharNumPerLine/5;

	while(i<showStr.size())
	{
		if(isalnum(showStr[i]) || showStr[i]=='\'')
		{
			i++;
		}
		else
		{
			for(int j=i; j<showStr.size()&&isalnum(showStr[j]); j++)
			{
				if(ispunct(showStr[j]))
					i=j;
			}
			(*contentShow).push_back(showStr.substr(pos, i-pos+1));
			while(i<showStr.size() && !isalnum(showStr[i]))
			{
				i++;
			}
			pos=i;
			i += 3*MaxCharNumPerLine/5;
		}
	}
	(*contentShow).push_back(showStr.substr(pos, showStr.size()-pos+1));
	
	for(int i=0; i<(*contentShow).size(); i++)
		std::cout << (*contentShow)[i] << std::endl;
	return true;
}

int Content::FileLineCount()
{
	_chdir("data/");
	std::ifstream out;
	out.open("data.txt");

	string line;
	int count = 0;
	if(!out)
	{
		std::cout << "Error: unable to open the data.txt" << std::endl;
		exit(-1);
	}

	while(out)
	{
		getline(out, line);
		count ++;
	}
	out.close();

	return count;
}