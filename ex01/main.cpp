#include <iostream>
#include <cstdlib>
#include "Span.hpp"

int main()
{
	Span span(6);
	span.addNumber(1);
	span.addNumber(22);
	span.addNumber(43);
	std::cout << span.longestSpan() << std::endl;
	std::cout << span.shortestSpan() << std::endl;

	std::cout << std::endl;

	srand(time(NULL));
	std::vector<int> randNum;

	randNum.reserve(100000);
	for (int i = 0; i < 100000; i++)
		randNum.push_back(rand());

	Span spanBig(100000);
	spanBig.addNumber(randNum.begin(), randNum.end());
	std::cout << "Random Generate (100000):" << std::endl;
	std::cout << "Shortest span: " << spanBig.shortestSpan() << std::endl;
	std::cout << "Longestest span: " << spanBig.longestSpan() << std::endl;
	std::cout << std::endl;

	Span sp = Span(15000);
	for (int i = 0; i < 15000; i++)
		sp.addNumber(i);

	std::cout << "Iterate:" << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longestest span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;

	Span sp2 = Span(15000);
	std::vector<int>::iterator a = sp.getVector().begin();
	std::vector<int>::iterator b = sp.getVector().end();
	sp2.addNumber(a, b);

	std::cout << "Operator = : " << std::endl;
	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	std::cout << std::endl;

	Span sp3 = Span(3);

	std::cout << "Except 1: " << std::endl;
	try
	{
		sp3.addNumber(6);
		sp3.addNumber(3);
		sp3.addNumber(17);
		sp3.addNumber(9);
		sp3.addNumber(11);
	}
	catch (std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}

	Span sp4;

	std::cout << "Except 2: " << std::endl;
	try
	{
		sp4.addNumber(123);
	}
	catch (std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}

	Span sp5(1);
	sp5.addNumber(123);

	std::cout << "Except 3: " << std::endl;
	try
	{
		std::cout << "Longest span: " << sp5.longestSpan() << std::endl;
	}
	catch (std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}

	return 0;
}
