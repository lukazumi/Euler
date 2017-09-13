#pragma once
#include <vector>
#include <string>
class Split
{
public:
	Split();
	~Split();
	template<typename Out>
	void split(const std::string &s, char delim, Out result);
	std::vector<std::string> split(const std::string &s, char delim);
};

