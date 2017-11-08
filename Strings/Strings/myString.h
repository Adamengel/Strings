/*
	Author: Adam Engelhart
	file: myString.h

	method definitions
	property definitions
*/
#pragma once


class myString
{
public:
	myString();
	myString(char* thisString);
	myString(myString& thisString);
	~myString();

	int GetLength();
	void Assign(myString& otherString);
	void Assign(char* otherString);
	char CharAt(int index);
	myString Append(myString& otherString);
	myString Append(char* otherString);
	int Compare(myString& otherString);
	int Compare(char* otherString);
	bool IsEmpty();
	void Clear();

private:
	char* string;
	int length;
};