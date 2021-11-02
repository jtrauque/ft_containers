#ifndef	REVERSE_ITERATOR_HPP
#define	REVERSE_ITERATOR_HPP

#include <iostream>
#include "iterator_traits.hpp"
//https://www.cplusplus.com/reference/iterator/RandomAccessIterator/

namespace	ft {

	template<class Iterator> // pas T ? 
		class	reverse_iterator	{ // voir le lien avec iterator traits
			public:
				typedef	Iterator	iterator_type;
				typedef	typename 	iterator_traits<Iterator>::difference_type	difference_type;
				typedef	typename	iterator_traits<Iterator>::value_type	value_type;
				typedef	typename	iterator_traits<Iterator>::pointer	pointer;
				typedef	typename	iterator_traits<Iterator>::reference	reference;
				typedef	typename	iterator_traits<Iterator>::iterator_category	iterator_category;

				reverse_iterator() : _it(NULL) {}
				reverse_iterator(iterator_type	it) : _it(it) {}
				template<typename src>
				reverse_iterator(reverse_iterator<src> const & src) : _it(src._it) {}
				~reverse_iterator() {}

				reverse_iterator	&operator=(reverse_iterator	const & rhs) {
					_it = rhs._it; 
					return *this;
				}
				iterator_type	base(void) const {
					return _it;
				}

				/* operator	reverse_iterator<value_type	const>(void) const { // */
				/* 	return reverse_iterator<value_type const>(_it); */
				/* } */

			private:
				iterator_type	_it;

			public:
				reverse_iterator	operator+(difference_type n) const {
					return reverse_iterator(_it + n);
				}

				reverse_iterator	&operator+=(difference_type n) {
					_it += n;
					return *this;
				}

				reverse_iterator	&operator++(difference_type n) {
					_it++;
					return *this;
				}

				reverse_iterator	&operator++(int) {
					reverse_iterator it = *this;
					++(*this);
					return it
				}

				reverse_iterator	operator-(difference_type n) const {
					return reverse_iterator(_it - n);
				}

				reverse_iterator	&operator-=(difference_type n) {
					_it -= n;
					return *this;
				}

				reverse_iterator	&operator--(difference_type n) {
					_it--;
					return *this;
				}

				reverse_iterator	&operator--(int) {
					reverse_iterator it = *this;
					--(*this);
					return it
				}

				reference	operator[](difference_type n) const {
					return *(_it + n);
				}

				pointer	operator->() const {
					return _it;
				}

				reference	operator*() const {
					return *_it;
				}

				bool operator==(const reverse_iterator &rhs) {return _pointer == rhs._pointer;}
				bool operator!=(const reverse_iterator &rhs) {return _pointer != rhs._pointer;}
				bool operator<(const reverse_iterator &rhs) {return _pointer < rhs._pointer;}
				bool operator<=(const reverse_iterator &rhs) {return _pointer <= rhs._pointer;}
				bool operator>(const reverse_iterator &rhs) {return _pointer > rhs._pointer;}
				bool operator>=(const reverse_iterator &rhs) {return _pointer >= rhs._pointer;}

				friend reverse_iterator operator+(difference_type n, //
						const reverse_iterator &rhs) {return reverse_iterator(rhs._it + n);}

				friend difference_type operator-(const reverse_iterator &lhs,// 
						const reverse_iterator &rhs) {return lhs._it - rhs._it;}
		};

}

#endif
