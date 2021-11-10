#ifndef	VECTOR_ITERATOR_HPP
#define	VECTOR_ITERATOR_HPP

#include <iostream>
#include <cstddef>
#include <iostream>
#include "iterator_traits.hpp"
#include "vector_iterator_const.hpp"
//https://www.cplusplus.com/reference/iterator/RandomAccessIterator/

namespace	ft {
	template<class T>
		class	vector_iterator_const;

	template<class T>
		class	vector_iterator	{
			public:
				typedef	T	value_type;
				typedef	std::ptrdiff_t	difference_type;
				typedef	value_type	&reference;
				typedef	value_type	*pointer;
				typedef	std::random_access_iterator_tag	iterator_category;

				vector_iterator() : _ptr(NULL) {}
				vector_iterator(value_type	*ptr) : _ptr(ptr) {}
				vector_iterator(vector_iterator const & src) { *this = src; }
				virtual ~vector_iterator() {}
				vector_iterator	&operator=(vector_iterator	const & rhs) {
					_ptr = rhs._ptr; 
					return *this;
				}
				value_type	*getPtr(void) const {
					return _ptr;
				}

			private:
				value_type	*_ptr;

			public:
				vector_iterator	operator+(difference_type n) const {
					return vector_iterator(_ptr + n);
				}

				vector_iterator	&operator+=(difference_type n) {
					_ptr += n;
					return *this;
				}

				vector_iterator	&operator++() {
					_ptr++;
					return *this;
				}

				vector_iterator	operator++(int) {
					vector_iterator it = *this;
					++(*this);
					return it;
				}

				vector_iterator	operator-(difference_type n) const {
					return vector_iterator(_ptr - n);
				}

				vector_iterator	&operator-=(difference_type n) {
					_ptr -= n;
					return *this;
				}

				vector_iterator	&operator--() {
					_ptr--;
					return *this;
				}

				vector_iterator	operator--(int) {
					vector_iterator it = *this;
					--(*this);
					return it;
				}

				reference	operator[](difference_type n) const {
					return *(_ptr + n);
				}

				pointer	operator->() const {
					return _ptr;
				}

				reference	operator*() const {
					return *_ptr;
				}

				bool operator==(const ft::vector_iterator_const<T> &rhs) const {return _ptr == rhs.getPtr();}
				bool operator!=(const ft::vector_iterator_const<T> &rhs) const {return _ptr != rhs.getPtr();}
				bool operator<(const ft::vector_iterator_const<T> &rhs) const {return _ptr < rhs.getPtr();}
				bool operator<=(const ft::vector_iterator_const<T> &rhs) const {return _ptr <= rhs.getPtr();}
				bool operator>(const ft::vector_iterator_const<T> &rhs) const {return _ptr > rhs.getPtr();}
				bool operator>=(const ft::vector_iterator_const<T> &rhs) const {return _ptr >= rhs.getPtr();}

				friend vector_iterator operator+(difference_type n, //
						const vector_iterator &rhs) {return vector_iterator(rhs.getPtr() + n);}

				friend difference_type operator-(const vector_iterator &lhs, //
						const vector_iterator &rhs) {return lhs.getPtr() - rhs.getPtr();}
		};
}

#endif
