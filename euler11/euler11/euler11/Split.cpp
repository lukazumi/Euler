#include "stdafx.h"
#include "Split.h"
#include <string>
#include <sstream>
#include <vector>
#include <iterator>


Split::Split()
{
}


Split::~Split()
{
}

template<typename Out>
void Split::split(const std::string &s, char delim, Out result) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}
std::vector<std::string> Split::split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}
