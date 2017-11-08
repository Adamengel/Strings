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

	int GetLength() const;
	void Assign(myString& otherString);
	void Assign(char* otherString);
	char CharAt(int index) const;
	myString Append(myString& otherString);
	myString Append(char* otherString);
	int Compare(myString& otherString) const;
	int Compare(char* otherString) const;
	bool IsEmpty() const;
	void Clear();

private:
	char* string;
	int length;
};