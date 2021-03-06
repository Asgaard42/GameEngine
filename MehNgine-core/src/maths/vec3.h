#pragma once
#include <iostream>

namespace mehngine{
	namespace maths{
		struct vec2
		{
			float x;
			float y;
			vec2();
			vec2(float x, float y);
			
			vec2& add(const vec2& other);
			vec2& subtract(const vec2& other);
			vec2& multiply(const vec2& other);
			vec2& divide(const vec2& other);

			friend vec2& operator+(vec2& left, const vec2& right);
			friend vec2& operator-(vec2& left, const vec2& right);
			
			friend std::ostream& operator <<(std::ostream& stream, const vec2& vector);
		};
	}
}