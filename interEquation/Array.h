#pragma once
#include <valarray>

template<class T> class valarray_2d
	: public std::valarray<std::valarray<T> >
{
public:

	valarray_2d() {}
	valarray_2d(size_t raw, size_t col) 
		: std::valarray<std::valarray<T>>(raw)
	{
		for (size_t i = 0; i < raw; ++i)
		{
			(*this)[i].resize(col);
		}
	}
	~valarray_2d() {}

	size_t raw() { return this->size(); }
	size_t col() { return (*this)[0].size(); }
};

typedef std::valarray<double> array_1d;

typedef valarray_2d<double> array_2d;