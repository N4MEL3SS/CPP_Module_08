#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template <typename T>
typename T::const_iterator easyfind(const T &container, const int toFind)
{
	typename T::const_iterator iter;

	iter = std::find(container.begin(), container.end(), toFind);

	if (iter == container.end())
		throw (std::exception());
	return (iter);
}

#endif //EASYFIND_HPP
