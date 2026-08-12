#include "Searcher.h"

//
// Part B-1
//

int Searcher::LinearSearch(const std::vector<Light>& lights, int greenColor) const
{
	for (int i = 0; i < lights.size(); i++)
	{
		if (greenColor == lights[i].green)
		{
			return i;
		}
	}
	return NOT_FOUND;
}
