#include <iostream>
#include "myString.h"
using namespace std;

int main()
{
	char* tempString = "abcd";
	myString mystring1;
	myString mystring2(tempString);
	myString mystring3(mystring2);

	mystring1.Assign(mystring2);
	mystring2.Append(mystring3);


	system("pause");
	return 0;
}