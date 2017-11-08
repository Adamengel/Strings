/*
Author: Adam Engelhart
file: myString.cpp

constructor and method implementations 
*/

#include <iostream>
#include "myString.h"

using namespace std;

myString::myString()
{
	string = NULL;
	length = 0;
}

myString::myString(char* thisString)
{
	int index = 0;
	while (*(thisString + index) != '\0')
	{
		index++;
	}
	length = index;
	string = new char[ length + 1];
	for (int index = 0; index < length; index++)
	{
		string[ index ] = thisString[ index ];
	}
	string[ length ] = '\0';
}
myString::myString(myString& thisString)
{
	length = thisString.length;
	string = new char[ length + 1 ];
	for (int index = 0; index < length; index++)
	{
		string[ index ] = thisString.string[ index ];
	}
	string[ length ] = '\0';
}

myString::~myString()
{
	if (string != NULL)
		delete [] string;
	length = 0;
}

//return length of string
int myString::GetLength()
{
	return length;
}

// assign value of parameter string to current string
void myString::Assign(myString& otherString)
{
	(myString*)this = new myString(otherString);
}
void myString::Assign(char* otherString)
{
	if (otherString != NULL)
	{
		length = strlen(otherString) - 1;
		string = new char[ length + 1 ];
		for (int index = 0; index < length; index++)
		{
			string[ index ] = otherString[ index ];
		}
		string[ length ] = '\0';
	}
	else
	{
		string = NULL;
		length = 0;
	}
}

//return the character at the given index of the string
char myString::CharAt(int index)
{
	char retVal = '\0';
	if (index >= 0 && index < length)
	{
		retVal = string[ index ];
	}
	return retVal;
}

//concatenate two strings together
myString myString::Append(myString& otherString)
{
	int newLength = length + otherString.length;
	char* newString = new char[ newLength + 1];
	for (int index = 0; index < length; index++)
	{
		newString[ index ] = string[ index ];
	}
	for (int index = 0; index < otherString.length; index++)
	{
		newString[ length + index ] = otherString.string[ index ];
	}

	newString[ newLength ] = '\0';

	string = newString;
	length = newLength;

	return string;
}

myString myString::Append(char* otherString)
{
	if (otherString != NULL)
	{
		unsigned lenOtherString = strlen(otherString);
		int newLength = length + lenOtherString;
		char* newString = new char[ newLength + 1 ];
		for (int index = 0; index < length; index++)
		{
			newString[ index ] = string[ index ];
		}
		for (int index = 0; index < lenOtherString; index++)
		{
			newString[ length + index ] = otherString[ index ];
		}

		newString[ newLength ] = '\0';

		string = newString;
		length = newLength;
	}
	return string;
}

//compare two strings. 
//return -1 if parameter string comes after class string, 0 is they are the same, and 1 if parameter string comes before class string
int myString::Compare(myString& otherString)
{
	int compare = 0;
	unsigned index = 0;
	if (0 == length && 0 != otherString.length)
	{
		compare = 1;
	}
	else if (0 != length && 0 == otherString.length)
	{
		compare = -1;
	}
	while (index < length && index < otherString.length && !index)
	{
		if (string[ index ] < otherString.string[ index ])
		{
			compare = -1;
			break;
		}
		if (string[ index ] > otherString.string[ index ])
		{
			compare = 1;
			break;
		}
	}
	return compare;
}

int myString::Compare(char* otherString)
{
	int retVal = 0;
	if (otherString != NULL) {
		retVal = strcmp(string, otherString);
	}
	return retVal;
}

//return true if empty, false if not
bool myString::IsEmpty()
{
	return length == 0 ? true : false;
}

//clear string value and length
void myString::Clear()
{
	string = NULL;
	length = 0;
}