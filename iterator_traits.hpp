#ifndef ITERATOR_TRAITS_HPP
#define	ITERATOR_TRAITS_HPP

#include <iterator>
#include <cstddef>
//https://www.cplusplus.com/reference/iterator/iterator_traits/
//std::iterator_traits is the type trait class that provides uniform interface to the properties of an iterator

//difference_type - a type that can be used to identify distance between iterators
//value_type - the type of the values that can be obtained by dereferencing the iterator. This type is void for output iterators.
//pointer - defines a pointer to the type iterated over (value_type)
//reference - defines a reference to the type iterated over (value_type)
//iterator_category - the category of the iterator. Must be one of iterator category tags.

namespace	ft {
	//https://en.cppreference.com/w/cpp/iterator/iterator_tags
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	//https://en.cppreference.com/w/cpp/iterator/iterator
	template	<class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T value_type;
		typedef	Distance difference_type;
		typedef	Pointer pointer;
		typedef	Reference reference;
		typedef	Category iterator_category;
	};
	
	template	<class Iterator>
	class	iterator_traits	{
		public:
			typedef	typename	Iterator::difference_type	difference_type;
			typedef	typename	Iterator::value_type	value_type;
			typedef	typename	Iterator::pointer	pointer;
			typedef	typename	Iterator::reference	reference;
			typedef	typename	Iterator::iterator_category	iterator_category;
	};

	template	<class	T>
	class	iterator_traits <T*> {
		public:
			typedef	std::ptrdiff_t	difference_type;
			typedef	T	value_type;
			typedef	T*	pointer;
			typedef	T&	reference;
			typedef	std::random_access_iterator_tag	iterator_category;
	};

	template	<class	T>
	class	iterator_traits <const T*> {
		public:
			typedef	std::ptrdiff_t	difference_type;
			typedef	T	value_type;
			typedef	T*	pointer;
			typedef	T&	reference;
			typedef	std::random_access_iterator_tag	iterator_category;
	};
	
	/* --------------------------------------------------------------------------- */
	//https://cplusplus.com/reference/algorithm/equal/
	template <class InputIterator1, class InputIterator2>
	bool	equal(InputIterator1 first1, InputIterator1 last, InputIterator2 first2) {
		while (first1 != last) {
			if (!(*first1 == *first2)) 
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	/* template <class InputIterator1, class InputIterator2, class BinaryPredicate> */
	/* bool	equal(InputIterator1 first1, InputIterator1 last, InputIterator2 first2, BinaryPredicate pred) { */
	/* 	while (first1 != last) { */
	/* 		if (pred(*first1, *first2) == false) */
	/* 			return false; */
	/* 		++first1; */
	/* 		++first2; */
	/* 	} */
	/* 	return true; */
	/* } */

	//https://cplusplus.com/reference/algorithm/lexicographical_compare/?kw=lexicographical_compare
	template <class InputIterator1, class InputIterator2>
	bool	lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
		while (first1 != last1) {
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

}

#endif
