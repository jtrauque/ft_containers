#ifndef MAP_HPP
#define MAP_HPP

#include "map_utils.hpp"

//https://en.cppreference.com/w/cpp/container/map
namespace	ft {
	template<class Key, class T, class Compare = ft::less<key>, class Allocator = std::allocator<ft::pair<const Key, T> >
	
	class	map {
		public:
			typedef	Key	key_type;
			typedef	T	mapped_type;
			typedef	ft::pair<const Key, T>	value_type;
			typedef	std::size_t	size_type;
			typedef	std::ptrdiff_t	difference_type;
			typedef Compare	key_compare;
			typedef	Alloc	allocator_type;
			typedef	typename	allocator_type::reference	reference;
			typedef	typename	allocator_type::const_reference	const_reference;
			typedef	typename	allocator_type::pointer	pointer;
			typedef	typename	allocator_type::const_pointer	const_pointer;
			typedef	iterator_map<value_type> iterator;
			typedef	iterator_map_const<value_type> const_iterator;
			typedef	typename	ft::reverse_iterator<iterator> reverse_iterator;
			typedef	typename	ft::reverse_iterator<const_iterator> const_reverse_iterator;

			//https://en.cppreference.com/w/cpp/container/map/value_compare
			//std::map::value_compare is a function object that compares objects of type std::map::value_type (key-value pairs) by comparing of the first components of the pairs.
			class	value_compare	{
				public:
					typedef bool	result_type;
					typedef	value_type	first_argument_type;
					typedef	value_type	second_argument_type;
					
					value_compare(Compare c) : _comp(c) {}

					bool	operator()(value_type const &lhs, value_type const &rhs) const { return _comp(lhs.first, rhs.first); }
			};


	};
}

#endif
