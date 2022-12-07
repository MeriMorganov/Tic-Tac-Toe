#pragma once
#ifndef ENTITY_h
#define ENTITY_h
#include "Vector2D.h"
namespace Commons
{
	class Entity
	{
	public:
		Entity();
		~Entity();
		virtual void Reset();
		virtual void Draw();
		virtual void SetPosition(const Commons::Vector2D<float>& position)=0;
	};
}
#endif
