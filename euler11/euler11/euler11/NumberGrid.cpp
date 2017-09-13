#include "stdafx.h"
#include "NumberGrid.h"
#include <vector>
#include <string>
#include "Split.h"
#include <fstream>
#include <iostream>

NumberGrid::NumberGrid()
{
}


NumberGrid::~NumberGrid()
{
}

void NumberGrid::readInput(std::string dir) {
	std::string line;
	std::ifstream myfile(dir);
	Split splitter = Split();
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			//a line is space seperated numbers
			std::vector<std::string> x = splitter.split(line, ' ');
			//convert each element to int
			std::vector<int> line;
			for (int i = 0; i < x.size(); ++i)
				line.push_back(std::stoi(x[i]));
			//add as row
			grid.push_back(line);
		}
		myfile.close();
	}
	else
		std::cout << "Unable to open file";
	return;
}

int NumberGrid::find_biggest_product(int originx, int originy) {
	int prod = 0;
	int big = 0;
	prod = NumberGrid::find_product(0, originx, originy);
	if (prod > big)
		big = prod;
	prod = NumberGrid::find_product(1, originx, originy);
	if (prod > big)
		big = prod;
	prod = NumberGrid::find_product(2, originx, originy);
	if (prod > big)
		big = prod;
	prod = NumberGrid::find_product(3, originx, originy);
	if (prod > big)
		big = prod;
	return big;
}

int NumberGrid::find_product(int direction, int originx, int originy ) {
	///  00 01 02 03 04
	///  05 06 07 08 09
	///  10 11 12 13 14
	///  15 16 17 18 19

	// rx=0 ry=0
	// [rx][ry] , [rx][ry+1:3]
	// [0][0]   , [0]{[1][2][3]}
	int product = 1;
	switch (direction)
	{
	case 0 : // down
		for (int i = 0; i < 4; i++) {
			try {
				product = product*grid.at(originx).at(originy + i);
			}
			catch (const std::out_of_range& oor)
			{
				return -1;
			}
		}
		return product;
	case 1 : // left
		for (int i = 0; i < 4; i++) {
			try {
				product = product*grid.at(originx+i).at(originy);
			}
			catch (const std::out_of_range& oor)
			{
				return -1;
			}
		}
		return product;
	case 2 : // diag down left
		for (int i = 0; i < 4; i++) {
			try {
				product = product*grid.at(originx+i).at(originy + i);
			}
			catch (const std::out_of_range& oor)
			{
				return -1;
			}
		}
		return product;
	case 3: // diag down right
		//if (originx < 4 || originy < 4) {
		//	return -1;
		//}
		for (int i = 0; i < 4; i++) {
			try {
				product = product*grid.at(originx+i).at(originy - i);
			}
			catch (const std::out_of_range& oor)
			{
				return -1;
			}
		}
		return product;
	// up, right are covered by a previous search.
	default:
		break;
	}
}

int NumberGrid::get_grid_length()
{
	int gs = grid.size();
	return gs;
}

int NumberGrid::get_grid_width()
{
	return grid[0].size();
}