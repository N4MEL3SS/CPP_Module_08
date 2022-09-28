#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>{
public:
	MutantStack<T>() {}

	MutantStack<T>(MutantStack<T> const &toCopy)
	{
		static_cast<void>(toCopy);
	}

	~MutantStack<T>() {}

	MutantStack<T> const &operator = (MutantStack<T> const &toCopy)
	{
		std::stack<T>::operator = (toCopy);

		return *this;
	}

	class iterator
	{
	public:
		iterator(T *ptr)
		{
			this->_ptr = ptr;
		}

		iterator &operator++()
		{
			this->_ptr--;

			return *this;
		}

		iterator operator++(int)
		{
			iterator it = *this;
			--(*this);

			return it;
		}

		iterator &operator--()
		{
			_ptr++;

			return *this;
		}

		iterator operator--(int)
		{
			iterator it = *this;
			++(*this);

			return it;
		}

		T &operator[](int idx)
		{
			return *(this->_ptr + idx);
		}

		T *operator->()
		{
			return this->_ptr;
		}

		T &operator*()
		{
			return *this->_ptr;
		}

		bool operator == (const iterator &other) const
		{
			return this->_ptr == other._ptr;
		}

		bool operator != (const iterator &other) const
		{
			return this->_ptr != other._ptr;
		}

	private:
		T *_ptr;
	};

	iterator begin()
	{
		return &this->top();
	}
	iterator end()
	{
		return &this->top() - this->size();
	}
};

#endif //MUTANTSTACK_HPP
