#include <numeric>
#include "Span.hpp"

Span::Span()
{
	this->_size = 0;
}

Span::Span(unsigned int n)
{
	this->_size = n;
}

Span::Span(const Span &toCopy)
{
	this->_size = toCopy._size;
	this->_v = toCopy._v;
}

Span::~Span() {}

Span &Span::operator = (const Span &toCopy)
{
	this->_size = toCopy._size;
	this->_v = toCopy._v;

	return *this;
}

void Span::addNumber(int num)
{
	if (_v.size() == _size)
		throw Span::SpanIsFullException();

	_v.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator it_S,
		std::vector<int>::iterator it_E)
{
	if (it_S > it_E)
		return ;

	if (this->_size == 0)
		throw Span::SpanIsNullException();

	std::vector<int>::iterator copy_it = it_S;
	std::vector<int>::iterator copy_ite = it_E;

	for (; copy_it != copy_ite; copy_it++)
	{
		if (this->_v.size() == this->_size)
			throw Span::SpanIsFullException();
		this->_v.push_back(*copy_it);
	}
}

int Span::shortestSpan() const {
	if (this->_size == 0 || this->_v.empty())
		throw Span::SpanIsNullException();

	if (this->_v.size() == 1)
		throw Span::SpanIsOneException();

	std::vector<int> temp = this->_v;
	std::sort(temp.begin(), temp.end());
	std::adjacent_difference(temp.begin(), temp.end(), temp.begin());
	return *std::min_element(temp.begin() + 1, temp.end());
}

int Span::longestSpan() const
{
	if (this->_size == 0 || this->_v.empty())
		throw Span::SpanIsNullException();

	if (this->_v.size() == 1)
		throw Span::SpanIsOneException();

	int max = *std::max_element(this->_v.begin(), this->_v.end());
	int min = *std::min_element(this->_v.begin(), this->_v.end());

	return max - min;
}

std::vector<int> &Span::getVector()
{
	return this->_v;
}

char const* Span::SpanIsFullException::what() const throw() {
	return "Span is full";
}

char const* Span::SpanIsNullException::what() const throw() {
	return "There's no number";
}

char const* Span::SpanIsOneException::what() const throw() {
	return "There's only one number";
}
