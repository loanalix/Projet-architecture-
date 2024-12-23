#include "pch.h"
#include "Math.h"
#include <cmath>

namespace maths
{
	void VectorNoramlise(Vector2* vector) {
		float lenght = std::sqrt(vector->x* vector->x + vector->y*vector->y );

		if (lenght > 0) {
			vector->x = vector->x / lenght;
			vector->y = vector->y / lenght;
		}
		else 
		{
			vector->x = 0;
			vector->y = 0;
		}
		 
	}

}
