#ifndef	REVERSE_ITERATOR_HPP
#define	REVERSE_ITERATOR_HPP

#include <iostream>
#include <iterator>
#include "iterator_traits.hpp"
#include "vector_iterator.hpp"
#include "vector_iterator_const.hpp"
//https://www.cplusplus.com/reference/iterator/RandomAccessIterator/

namespace	ft {

	template<class Iterator>
		class	reverse_iterator	{ 
			public:
				typedef	Iterator	iterator_type;
				typedef	typename 	iterator_traits<Iterator>::difference_type	difference_type;
				typedef	typename	iterator_traits<Iterator>::value_type	value_type;
				typedef	typename	iterator_traits<Iterator>::pointer	pointer;
				typedef	typename	iterator_traits<Iterator>::reference	reference;
				typedef	typename	iterator_traits<Iterator>::iterator_category	iterator_category;

				reverse_iterator() : _it(NULL) {}
				
				reverse_iterator(iterator_type	it) : _it(it) {}
				
				template<typename Src>
				reverse_iterator(reverse_iterator<Src> const & src) : _it(src.base()) {}
				
				virtual ~reverse_iterator() {} // virtual ? 

				template<typename Src>
				reverse_iterator	&operator=(reverse_iterator<Src>	const & rhs) {
					_it = rhs.base(); 
					return *this;
				}

				iterator_type	base(void) const {
					return _it;
				}

				operator	reverse_iterator<vector_iterator<value_type	const> >(void) const { //
					return reverse_iterator<vector_iterator<value_type const> >(_it);
				}

				operator	reverse_iterator<vector_iterator<value_type> >(void) { //
					return reverse_iterator<vector_iterator<value_type> >(_it);
				}

			private:
				iterator_type	_it;

			public:
				reverse_iterator	operator+(difference_type n) const {
					return reverse_iterator(_it - n);
				}

				reverse_iterator	&operator+=(difference_type n) {
					_it -= n;
					return *this;
				}

				reverse_iterator	&operator++() {
					_it--;
					return *this;
				}

				reverse_iterator	operator++(int) {
					reverse_iterator it = *this;
					/* _it--; */
					++(*this);
					return it;
				}

				reverse_iterator	operator-(difference_type n) const {
					return reverse_iterator(_it + n);
				}

				reverse_iterator	&operator-=(difference_type n) {
					_it += n;
					return *this;
				}

				reverse_iterator	&operator--() {
					_it++;
					return *this;
				}

				reverse_iterator	operator--(int) {
					reverse_iterator it = *this;
					/* _it++; */
					--(*this);
					return it;
				}

				reference	operator[](int n) const {
					return *(_it - n - 1);
				}

				pointer	operator->() const {
					return &(operator*());
				}

				reference	operator*() const {
					iterator_type it = _it;
					it--;
					return *it;
				}
		};

	//NON Member overloard

	template <typename Iter1, typename Iter2>
		bool operator==(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs) {return lhs.base() == rhs.base();}
	template <typename Iter1, typename Iter2>
		bool operator!=(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs) {return lhs.base() != rhs.base();}
	template <typename Iter1, typename Iter2>
		bool operator<(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs) {return lhs.base() > rhs.base();}
	template <typename Iter1, typename Iter2>
		bool operator<=(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs) {return lhs.base() >= rhs.base();}
	template <typename Iter1, typename Iter2>
		bool operator>(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs) {return lhs.base() < rhs.base();}
	template <typename Iter1, typename Iter2>
		bool operator>=(const reverse_iterator<Iter1> &lhs, const reverse_iterator<Iter2> &rhs) {return lhs.base() <= rhs.base();}

	template <typename Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, //
			const reverse_iterator<Iterator> &rhs) {return reverse_iterator<Iterator>(rhs + n);}
	
	template <typename Iter1, typename Iter2>
	typename reverse_iterator<Iter1>::difference_type operator-(const reverse_iterator<Iter1> &lhs,// 
			const reverse_iterator<Iter2> &rhs) {return rhs.base() - lhs.base();}
}

#endif
