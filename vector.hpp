
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
				vector(vector const &src) :
					_array(NULL), _capacity(src._capacity), _size(src._size), _allocator(src._allocator) {
						_array = _allocator.allocate(_capacity); //allocate uninitialized storage
						for (size_type i = 0; i < _capacity, i++) {
							_allocator.construct(_array + i, src._array[i]); //construct an object in allocated object
						}
					}

				~vector(void) {
					this->clear();
					_allocator.deallocate(_array, _capacity);
				}

				vector	&operator=(vector const &rhs) {
					this->clear();
					_allocator.deallocate(_array, _capacity);
					_capacity = rhs._capacity;
					_size = rhs._size;
					_array = _allocator.allocate(_capacity); //allocate uninitialized storage
					for (size_type i = 0; i < _capacity, i++) {
						_allocator.construct(_array + i, rhs._array[i]); //construct an object in allocated object
					}
				}

				template<class InputIterator>
				void	assign(InputIterator first, InputIterator last, 
							typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true) {
				}

				void	assign(size_type count, const value_type &val) {
				}

				allocator_type	get_allocator(void) const {
				}

				/* FUNCTIONS - ITERATOR */
				//https://en.cppreference.com/w/cpp/named_req/Container
				iterator	begin(void) {
					return iterator(_array);
				}

				iterator	end(void) {
					return iterator(_array + size);
				}

				const_iterator	begin(void) {
					return const_iterator(_array);
				}

				const_iterator	end(void) {
					return const_iterator(_array + size);
				}

				reverse_iterator	rbegin(void) {
					return reverse_iterator(end());
				}

				reverse_iterator	rend(void) {
					return reverse_iterator(begin());
				}
				
				const_reverse_iterator	rbegin(void) {
					return const_reverse_iterator(end());
				}

				const_reverse_iterator	rend(void) {
					return const_reverse_iterator(begin());
				}

				/* FUNCTIONS - ELEMENT ACCESS */
				//https://en.cppreference.com/w/cpp/container/vector
				//
				reference	at(size_type	pos) {
					if (pos >= _size || pos < 0)
						throw std::out_of_range("out of range");
					return _array[pos];
				}
				
				const_reference	at(size_type	pos) const {
					if (pos >= _size || pos < 0)
						throw std::out_of_range("out of range");
					return _array[pos];
				}

				reference_operator[](size_type pos) {
					return _array[pos];
				}

				const_reference_operator[](size_type pos) const {
					return _array[pos];
				}

				reference	front(void) {
					return _array[0];
				}
				
				const_reference	front(void) const {
					return _array[0];
				}
				
				reference	back(void) {
					return _array[_size - 1];
				}
				
				const_reference	back(void) const {
					return _array[_size - 1];
				}

				/* FUNCTIONS - CAPACITY */
				bool	empty(void) const {
					return (_size == 0 ? true : false);
				}

				size_type	size(void) const {
					return _size;
				}

				size_type	max_size(void) const {
					return _allocator.max_size();
				}

				void	reserve(size_type new_cap) {
					if (new_cap > max_size()) {
						throw std::length_error("n greater than max_size()");
					}
					if (new_cap > _capacity) {
						pointer	ptr = _allocator.allocate(new_cap);
						for (size_type i = 0; i < _size; i++) {
							_allocator.construct(ptr + i, _array[i]); // we save the data from the old array before destroying it
							_allocator.destroy(_array + i);
						}
						_allocator.deallocate(_array, _capacity);
						_capacity = new_cap;
						_array = ptr;
					}
				}

				size_type	capacity(void) const {
					return _capacity;
				}

				/* FUNCTIONS - MODIFIERS */
				void	clear(void) {
					if (!this->empty()) {
						for (size_type i = 0; i < _size; i++) {
							_allocator.destroy(_array + i);
						}
						_size = 0;
					}
				}
				
				iterator	insert(iterator	pos, const value_type &val) {
					difference_type tmp = pos._ptr - _array;
					insert(position, 1, val);
					return interator(begin() + tmp);
				}

				void	insert(iterator	pos, size_type n, const value_type &val) {
					difference_type tmp = pos._ptr - _array;
					if (n <= 0) 
						return ;

				}

				template<class InputIterator>
					void	insert(iterator pos, InputIterator first, InputIterator last, 
							typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true) {
					}

				iterator	erase(iterator pos) {
				}

				void	push_back(const value_type	&val) {
				}

				void	pop_back(void) {
				}

				void	resize(size_type count, value_type val = value_type()) {
				}

				iterator	erase(iterator position) {
				}

				iterator	erase(iterator first, iterator last) {
				}


				void	swap(vector	&src) {
					pointer	tmp_arr = _array;
					size_type tmp_cap = _capacity;
					size_type tmp_size = _size;
					allocator_type tmp_alloc = _allocator;

					_array = src._array;
					_capacity = src._capacity;
					_size = src._size;
					_allocator = src._allocator;

					src._array = tmp_arr;
					src._capacity = tmp_cap;
					src._size = tmp_size;
					src._allocator = tmp_alloc;
				}
		};
		
	/*NON MEMBER FUNCTIONS */
	template <class T, class Alloc>
		bool operator==(const vector<T, Alloc> const &lhs, const vector<T, Alloc> const &rhs) {return lhs.base() == rhs.base();}
	template <class T, class Alloc>
		bool operator!=(const vector<T, Alloc> const &lhs, const vector<T, Alloc> const &rhs) {return lhs.base() != rhs.base();}
	template <class T, class Alloc>
		bool operator<(const vector<T, Alloc> const &lhs, const vector<T, Alloc> const &rhs) {return lhs.base() < rhs.base();}
	template <class T, class Alloc>
		bool operator<=(const vector<T, Alloc> const &lhs, const vector<T, Alloc> const &rhs) {return lhs.base() <= rhs.base();}
	template <class T, class Alloc>
		bool operator>(const vector<T, Alloc> const &lhs, const vector<T, Alloc> const &rhs) {return lhs.base() > rhs.base();}
	template <class T, class Alloc>
		bool operator>=(const vector<T, Alloc> const &lhs, const vector<T, Alloc> const &rhs) {return lhs.base() >= rhs.base();}
}


