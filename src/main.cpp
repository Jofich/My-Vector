/*
* Шапарь Матвей 2024 год
*/
#include <iostream>
#include "myVector"
int main()
{
	shp::vector num(5);
	num.push_back(8);
	num.push_back(8);
	num.push_back(8);
	num.push_back(8);
	num.push_back(8);
	num.push_back(8);
	for (int i = 0; i < num.size(); i++) {
		std::cout << num[i] << " ";
	}
}
