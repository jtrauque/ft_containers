#ifndef ITERATOR_TRAITS_HPP
#define	ITERATOR_TRAITS_HPP

#include <iterator>
//https://www.cplusplus.com/reference/iterator/iterator_traits/
//std::iterator_traits is the type trait class that provides uniform interface to the properties of an iterator

//difference_type - a type that can be used to identify distance between iterators
//value_type - the type of the values that can be obtained by dereferencing the iterator. This type is void for output iterators.
//pointer - defines a pointer to the type iterated over (value_type)
//reference - defines a reference to the type iterated over (value_type)
//iterator_category - the category of the iterator. Must be one of iterator category tags.

namespace	ft {

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
			typedef	ptrdiff_t	difference_type;
			typedef	T	value_type;
			typedef	T*	pointer;
			typedef	T&	reference;
			typedef	std::random_access_iterator_tag	iterator_category;
	};

	template	<class	T>
	class	iterator_traits <const T*> {
		public:
			typedef	ptrdiff_t	difference_type;
			typedef	T	value_type;
			typedef	T*	pointer;
			typedef	T&	reference;
			typedef	std::random_access_iterator_tag	iterator_category;
	};

}

#endif
