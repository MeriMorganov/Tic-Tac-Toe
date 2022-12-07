#pragma once
#ifndef VECTOR_2D_h
#define VECTOR_2D_h
namespace Commons
{
	template <class T>
	class Vector2D
	{
	public:
		Vector2D() {};
		Vector2D(T x, T y)
			{
			this->x = x;
			this->y = y;
		};
		~Vector2D() {};
		T x;
		T y;

		//expand when needed
	};
}
#endif
