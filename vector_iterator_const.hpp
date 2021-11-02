#ifndef	VECTOR_ITERATOR_CONST_HPP
#define	VECTOR_ITERATOR_CONST_HPP

#include <iostream>
#include "iterator_traits.hpp"

//https://www.cplusplus.com/reference/iterator/RandomAccessIterator/

namespace	ft {

	template<class T>
		class	vector_iterator_const	{
			public:
				typedef	T	value_type;
				typedef	ptrdiff_t	difference_type;
				typedef	value_type	&referece;
				typedef	value_type	*pointer;
				typedef	std::random_access_iterator_tag	iterator_category;

				vector_iterator_const() : _ptr(NULL) {}
				vector_iterator_const(value_type	*ptr) : _ptr(ptr) {}
				vector_iterator_const(vector_iterator_const const & src) : _ptr(src._ptr) {}
				~vector_iterator_const() {}
				vector_iterator_const	&operator=(vector_iterator_const	const & rhs) {
					_ptr = rhs._ptr; 
					return *this;
				}
				value_type	*getPtr(void) const {
					return _ptr;
				}
				operator	vector_iterator_const<value_type	const>(void) const {
					return vector_iterator_const<value_type const>(_ptr);
				}

			private:
				value_type	*_ptr;

			public:
				vector_iterator_const	operator+(difference_type n) const {
					return vector_iterator_const(_ptr + n);
				}

				vector_iterator_const	&operator+=(difference_type n) {
					_ptr += n;
					return *this;
				}

				vector_iterator_const	&operator++(difference_type n) {
					_ptr++;
					return *this;
				}

				vector_iterator_const	&operator++(int) {
					vector_iterator_const it = *this;
					++(*this);
					return it
				}

				vector_iterator_const	operator-(difference_type n) const {
					return vector_iterator_const(_ptr - n);
				}

				vector_iterator_const	&operator-=(difference_type n) {
					_ptr -= n;
					return *this;
				}

				vector_iterator_const	&operator--(difference_type n) {
					_ptr--;
					return *this;
				}

				vector_iterator_const	&operator--(int) {
					vector_iterator_const it = *this;
					--(*this);
					return it
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

				bool operator==(const vector_iterator_const &rhs) {return _pointer == rhs._pointer;}
				bool operator!=(const vector_iterator_const &rhs) {return _pointer != rhs._pointer;}
				bool operator<(const vector_iterator_const &rhs) {return _pointer < rhs._pointer;}
				bool operator<=(const vector_iterator_const &rhs) {return _pointer <= rhs._pointer;}
				bool operator>(const vector_iterator_const &rhs) {return _pointer > rhs._pointer;}
				bool operator>=(const vector_iterator_const &rhs) {return _pointer >= rhs._pointer;}

				friend vector_iterator_const operator+(difference_type n,
						const vector_iterator_const &rhs) {return vector_iterator_const(rhs._ptr + n);}

				friend difference_type operator-(const vector_iterator_const &lhs,
						const vector_iterator_const &rhs) {return lhs._ptr - rhs._ptr;}
		};

}

#endif
