#include <iostream>
#include "PicNode.h"

void PicNode::printToScreen()
{
	cout.width(20);
	cout << left << name.substr(0, 19);
	cout.width(15);
	cout << left << year;
	cout.width(15);
	cout << left << nomination;
	cout.width(15);
	cout << left << rating;
	cout.width(15);
	cout << left << duration;
	cout.width(15);
	cout << left << genre1.substr(0, 14);
	cout.width(15);
	cout << left << genre2.substr(0, 14);
	cout.width(15);
	cout << left << release.substr(0, 14);
	if (metacritic == 0)
	{
		cout.width(15);
		cout << left << "n/a";
	}
	else
	{
		cout.width(15);
		cout << left << metacritic;
	}
	cout.width(15);
	cout << left << synopsis.substr(0, 49) << endl;
}