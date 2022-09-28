#include <iostream>
#include <list>
#include "MutantStack.hpp"

void stackPrint()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Stack Top and Size:" << std::endl;
	std::cout << mstack.top() << " ";
	std::cout << mstack.size() << std::endl;
	std::cout << std::endl;

	mstack.pop();
	std::cout << "Stack Top and Size:" << std::endl;
	std::cout << mstack.top() << " ";
	std::cout << mstack.size() << std::endl;
	std::cout << std::endl;

	std::cout << "Push in stack: 3" << std::endl;
	mstack.push(3);
	std::cout << "Push in stack: 5" << std::endl;
	mstack.push(5);
	std::cout << "Push in stack: 737" << std::endl;
	mstack.push(737);
	std::cout << "Push in stack: 0" << std::endl;
	mstack.push(0);
	std::cout << std::endl;

	std::cout << "Stack Size:" << std::endl;
	std::cout << mstack.size() << std::endl;
	std::cout << std::endl;

	std::cout << "Start stack iterator:" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
}

void listPrint()
{
	std::list<int> l;

	l.push_back(5);
	l.push_back(17);
	std::cout << "List Top and Size:" << std::endl;
	std::cout << l.back() << " ";
	std::cout << l.size() << std::endl;
	std::cout << std::endl;

	l.pop_back();
	std::cout << "List Top and Size:" << std::endl;
	std::cout << l.back() << " ";
	std::cout << l.size() << std::endl;
	std::cout << std::endl;

	std::cout << "Push in list: 3" << std::endl;
	l.push_back(3);
	std::cout << "Push in list: 5" << std::endl;
	l.push_back(5);
	std::cout << "Push in list: 737" << std::endl;
	l.push_back(737);
	std::cout << "Push in list: 0" << std::endl;
	l.push_back(0);
	std::cout << std::endl;

	std::cout << "List Size:" << std::endl;
	std::cout << l.size() << std::endl;
	std::cout << std::endl;

	std::cout << "Start list iterator:" << std::endl;
	std::list<int>::const_iterator it_lS  = l.end();
	std::list<int>::const_iterator it_lE = l.end();
	--it_lS;

	while (it_lS != it_lE)
	{
		std::cout << *it_lS << std::endl;
		--it_lS;
	}
}

int main()
{
	std::cout << "===Stack===" << std::endl;
	stackPrint();

	std::cout << std::endl << std::endl;

	std::cout << "===List===" << std::endl;
	listPrint();

	return 0;
}
