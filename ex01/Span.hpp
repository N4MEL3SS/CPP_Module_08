#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <exception>
# include <limits>
# include <vector>

class Span {
public:
	Span();
	Span(unsigned int n);
	Span(Span const &toCopy);

	virtual ~Span();

	Span& operator = (Span const& toCopy);

	void addNumber(int num);
	void addNumber(std::vector<int>::iterator begin,
			std::vector<int>::iterator end);
	void addNumber(std::vector<int>::const_iterator begin,
			std::vector<int>::const_iterator end);
	int shortestSpan() const;
	int longestSpan() const;

	std::vector<int> &getVector();

	class SpanIsFullException : public std::exception {
	public:
		char const* what() const throw();
	};

	class SpanIsNullException : public std::exception {
	public:
		char const* what() const throw();
	};

	class SpanIsOneException : public std::exception {
	public:
		char const* what() const throw();
	};

private:
	unsigned int _size;
	std::vector<int> _v;
};

#endif //SPAN_HPP
