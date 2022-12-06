////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////

struct Rango
{
	int min;
	int max;

	bool Dentro
	(	int   const n
	) const
	{
		return n >= this->min
		and    n <= this->max;
	}
};

////////////////////////////////////////////////////////////////