#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include "easyfind.hpp"

template <typename T>
void test(T &container, int n)
{
	typename T::const_iterator it;

	try
	{
		it = easyfind(container, n);
		std::cout << "The number " << *it << " is in the container" <<
		std::endl;
	}
	catch (std::exception& err)
	{
		std::cout << "The number " << n << " is not in the container" << std::endl;
	}
}

template <typename T>
void printCont(T start, T end)
{
	for (; start != end; ++start)
		std::cout << *start << " ";
	std::cout << std::endl;
	std::cout << std::endl;
}

int main()
{
	std::cout << "===VECTOR===" << std::endl;
	std::vector<int> v;

	v.reserve(20);
	for (int i = 0; i < 20; i++)
		v.push_back(i);
	v.push_back(19);

	std::vector<int>::const_iterator it_vS  = v.begin();
	std::vector<int>::const_iterator it_vE = v.end();
	printCont(it_vS, it_vE);

	test(v, 5);
	test(v, 9);
	test(v, 20);
	test(v, 200);

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "===DEQUE===" << std::endl;
	std::deque<int> d;

	for (int i = 0; i < 20; i++)
		d.push_back(i);
	d.push_back(19);

	std::deque<int>::const_iterator it_dS  = d.begin();
	std::deque<int>::const_iterator it_dE = d.end();
	printCont(it_dS, it_dE);

	test(d, 5);
	test(d, 9);
	test(d, 20);
	test(d, 200);

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "===SET===" << std::endl;
	std::set<int> s;

	for (int i = 0; i < 20; i++)
		s.insert(i);
	s.insert(19);

	std::set<int>::const_iterator it_sS = s.begin();
	std::set<int>::const_iterator it_sE = s.end();
	printCont(it_sS, it_sE);

	test(s, 5);
	test(s, 9);
	test(s, 20);
	test(s, 200);

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "===LIST===" << std::endl;
	std::list<int> l;

	for (int i = 0; i < 20; i++)
		l.push_back(i);
	l.push_back(19);

	std::list<int>::const_iterator it_lS  = l.begin();
	std::list<int>::const_iterator it_lE = l.end();
	printCont(it_lS, it_lE);

	test(l, 5);
	test(l, 9);
	test(l, 20);
	test(l, 200);

	return 0;
}
