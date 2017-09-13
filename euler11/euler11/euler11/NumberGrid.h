#pragma once
#include <string>
#include <vector>
class NumberGrid
{
public:
	std::vector<std::vector<int>> grid; //2s list representing the grid
	NumberGrid();
	~NumberGrid();
	void NumberGrid::readInput(std::string dir);
	int NumberGrid::get_grid_length();
	int NumberGrid::get_grid_width();
	int NumberGrid::find_biggest_product(int originx, int originy);
private:
	int NumberGrid::find_product(int direction, int originx, int originy);
};

