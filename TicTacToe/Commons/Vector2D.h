#pragma once
#ifndef VECTOR_2D_h
#define VECTOR_2D_h
namespace Commons
{
	template <class T>
	class Vector2D // Simple math vector class to make 2D vectors in any numeric typing
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

		//expand when needed. eg. add Dot or Cross functions
	};
}
#endif
