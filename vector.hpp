
#ifndef	VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "vector_iterator.hpp"
#include "vector_iterator_const.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"

namespace	ft {  //ft:: est comme le std:: - c est la reference de librairie - un identificateur
	template<class T, class Alloc = std::allocator<T> > //generic template vector

	class vector {
		public:
			//Member types
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef typename allocator_type::reference	reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer	pointer;
			typedef typename allocator_type::const_pointer	const_pointer;
			
			typedef	vector_iterator<T> iterator; // class iterator_vector
			typedef vector_iterator_const<T> const_iterator; // class iterator vector const
			
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
			
			typedef std::ptrdiff_t	difference_type;
			typedef std::size_t	size_type;

		private:
			pointer	_array;
			size_type _capacity;
			size_type _size;
			allocator_type _allocator;

		public:
			//explicit : cannot be used for impliciti conversion or copy initialization
			//creation of an empty container
			//the alloc allows me to pass a specific instance of an allocator - it is the instance of the class Alloc ligne 8
	
			//https://en.cppreference.com/w/cpp/memory/allocator
			//default constructor
			explicit	vector(const allocator_type	&alloc = allocator_type()):
				_array(NULL), _capacity(0), _size(0), _allocator(alloc) {
				return ;
			}

			//fill in constructor
			explicit	vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()):
				_array(NULL), _capacity(n), _size(n), _allocator(alloc) {
				_array = _allocator.allocate(n); //allocate uninitialized storage
				for (size_type i = 0; i < n, i++) {
					_allocator.construct(_array + i, val); //construct an object in allocated object
				}
				return ;
			}

			//constructor with range
			template <class InputOperator>
			vector(InputOperator first, InpuOperator last, const allocator_type &alloc = allocator_type(), 
				typename ft::enable_if<!ft::is_integral<InputOperator>::value, bool>::type = true) :
				_array(NULL), _capacity(n), _size(n), _allocator(alloc) {
				size_type n = 0;
				for (INputOperator it = first; it != last; it++) {
					n++;
				}
				_array = _allocator.allocate(n); //allocate uninitialized storage
				for (size_type i = 0; i < n, i++) {
					_allocator.construct(_array + i, val); //construct an object in allocated object
				}
				_capacity = n;
				_size = n;
				return ;
			}

			//copy constructor
			vector(vector const &src) : _array(NULL), _capacity(src._capacity), _size(src._size), _allocator(src._allocator) {
				_array = _allocator.allocate(_capacity); //allocate uninitialized storage
				for (size_type i = 0; i < _capacity, i++) {
					_allocator.construct(_array + i, src._array[i]); //construct an object in allocated object
				}
			}

			~vector(void) {
				this->clear();
				_allocator.deallocate(_array, _capacity);
			}
			
			vector	&operator=(vector const &src) {
			}
	};
}

#endif
