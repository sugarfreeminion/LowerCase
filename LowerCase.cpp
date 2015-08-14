#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

void ConvertToLower(string data)
{
	unsigned int index = 0;
	int asciiVal = 0;
	
	char dataChar[data.length()];
	
	strncpy(dataChar, data.c_str(), data.length());
	
	while(index < data.length())
	{
		asciiVal = int(dataChar[index]);
		
		if( (asciiVal >= 65) && (asciiVal <= 90) )
		{
			dataChar[index] = char(asciiVal + 32);
		}
		
		++index;
	}
	
	dataChar[index] = '\0';
	
	cout << dataChar << endl;
}

int main(int argc,char *argv[])
{
	ifstream inputFile(argv[1]);
	
	if(inputFile.is_open() == false)
	{
		cout << "Error opening " << argv[1] << " check the file name and make sure it is correct" << endl;
	}
	else
	{
		string data;
		
		while(inputFile.eof() == false)
		{
			getline(inputFile, data);
			
			//cout << "Original Line: " << data << endl;
			
			ConvertToLower(data);
		}
	}
	
	return 0;
}