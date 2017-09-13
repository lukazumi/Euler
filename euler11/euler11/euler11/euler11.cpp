// euler11.cpp : https://projecteuler.net/problem=11
//Luke Jackson 2017
//

#include "stdafx.h"
#include <iostream>
#include "NumberGrid.h"

int main()
{
	NumberGrid ng = NumberGrid();
	ng.readInput("input.txt");
	int big = 0;
	int prod = 0;
	for (int i = 0; i < ng.get_grid_length(); i++) {
		for (int j = 0; j < ng.get_grid_width(); j++) {
			prod = ng.find_biggest_product(i, j);
			if (prod > big)
				big = prod;
		}
	}
	std::cout << big;
	std::cout << "\n\n";
}

