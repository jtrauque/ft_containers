
#ifndef	VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <iterator>
#include "vector_iterator.hpp"
#include "vector_iterator_const.hpp"
#include "reverse_iterator.hpp"
#include "iterator_traits.hpp"
#include "enable_if.hpp"

#define DEBUG // std::cout << REDC << __FILE__ << " " << CYN << __FUNCTION__  << " " << __LINE__ << NC << std::endl;

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

				typedef typename	allocator_type::difference_type	difference_type;
				typedef	std::size_t	size_type;

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
						for (size_type i = 0; i < n; i++) {
							_allocator.construct(_array + i, val); //construct an object in allocated object
						}
						return ;
					}

				//constructor with range
				template <class InputIterator>
					vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, 
							const allocator_type &alloc = allocator_type()) :
						_array(NULL), _capacity(0), _size(0), _allocator(alloc) {
							size_type n = std::distance(first, last);
							_array = _allocator.allocate(n); //allocate uninitialized storage
							for (size_type i = 0; i < n; i++) {
								_allocator.construct(_array + i, *first); //construct an object in allocated object
								first++;
							}
							_capacity = n;
							_size = n;
							return ;
						}

				//copy constructor
				vector(vector const &src) :
					_array(NULL), _capacity(src._capacity), _size(src._size), _allocator(src._allocator) {
						_array = _allocator.allocate(_capacity); //allocate uninitialized storage
						for (size_type i = 0; i < _size; i++) {
							_allocator.construct(_array + i, src._array[i]); //construct an object in allocated object
						}
					}

				virtual ~vector(void) {
					this->clear();
					_allocator.deallocate(_array, _capacity);
				}

				vector	&operator=(vector const &rhs) {
					this->clear();
					_allocator.deallocate(_array, _capacity);
					_capacity = rhs._capacity;
					_size = rhs._size;
					_array = _allocator.allocate(_capacity); //allocate uninitialized storage
					for (size_type i = 0; i < _capacity; i++) {
						_allocator.construct(_array + i, rhs._array[i]); //construct an object in allocated object
					}
					return *this;
				}

				template<class InputIterator>
					void	assign(InputIterator first, InputIterator last, 
							typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type =true) {
						size_type n = std::distance(first, last);
						resize(n);
						_capacity = n;
						_size = n;
						for (size_type i = 0; i < n && first != last; i++, first++) {
							_allocator.construct(_array + i, *first);
						}
						return ;
					}

				void	assign(size_type count, const value_type &val) {
					_allocator.deallocate(_array, _capacity);
					_array = _allocator.allocate(count);
					_capacity = count;
					_size = count;
					for (size_type i = 0; i < count; i++) {
						_allocator.construct(_array + i, val);
					}
					return ;
				}

				allocator_type	get_allocator(void) const {
					return _allocator;
				}

				/* FUNCTIONS - ITERATOR */
				//https://en.cppreference.com/w/cpp/named_req/Container
				iterator	begin(void) {
					return iterator(_array);
				}

				iterator	end(void) {
					return iterator(_array + _size);
				}

				const_iterator	begin(void) const {
					return const_iterator(_array);
				}

				const_iterator	end(void) const {
					return const_iterator(_array + _size);
				}

				reverse_iterator	rbegin(void) {
					return reverse_iterator(end());
				}

				reverse_iterator	rend(void) {
					return reverse_iterator(begin());
				}

				const_reverse_iterator	rbegin(void) const {
					return const_reverse_iterator(end());
				}

				const_reverse_iterator	rend(void) const {
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

				reference	operator[](size_type pos) {
					return _array[pos];
				}

				const_reference	operator[](size_type pos) const {
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
					difference_type tmp = pos.getPtr() - _array;
					insert(pos, 1, val);
					return iterator(begin() + tmp);
				}

				void	insert(iterator	pos, size_type count, const value_type &val) {
					difference_type tmp = pos.getPtr() - _array;
					if (count <= 0) 
						return ;
					if (_size + count > _capacity) {
						if ( _size + count < _capacity * 2)
							reserve(_capacity * 2);
						else
							reserve(_size + count);
					}
					pointer it = _array + _size + count - 1;
					pointer ite = _array + tmp + count - 1;
					while (it != ite) {
						_allocator.construct(it, *(it - count));
						_allocator.destroy(it - count); 
						// we save and destroy pos to end value to shift
						it--;
					}
					_size += count;
					for (size_type i = 0; i < count; i++) {	
						_allocator.construct(_array + tmp + i, val);
					}
					return ;
				}

				template<class InputIterator>
					void	insert(iterator pos, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
							InputIterator last) {
						difference_type tmp = pos.getPtr() - _array;
						size_type n = std::distance(first, last);
						if (n == 0)
							return ;
						if (_size + n > _capacity) {
							if ( _size + n < _capacity * 2)
								reserve(_capacity * 2);
							else
								reserve(_size + n);
						}
						pointer it = _array + _size + n - 1;
						pointer ite = _array + tmp + n - 1;
						while (it != ite) {
							_allocator.construct(it, *(it - n));
							_allocator.destroy(it - n); 
							// we save and destroy pos to end value to shift
							it--;
						}
						_size += n;
						for (size_type i = 0; i < n; i++) {	
							_allocator.construct(_array + tmp + i, *first);
							first++;
							ite++;
						}
						return ;
					}


				void	push_back(const value_type	&val) {
					if (_capacity == 0)
						reserve(1);
					else if (_size == _capacity)
						reserve(_capacity * 2);
					_allocator.construct(_array + _size, val); // on construct a la fin de l array
					_size++;
				}

				void	pop_back(void) {
					_size--;
					_allocator.destroy(_array + _size); // on construct a la fin de l array
				}

				void	resize(size_type count, value_type val = value_type()) {
					if (count > _capacity && count < _capacity * 2)
						reserve(_capacity * 2);
					else 
						reserve(count);
					if (count > _size) {
						while (_size < count) {
							_allocator.construct(_array + _size, val);
							_size++;
						}
					}
					else {
						for (size_type n = count; n < _size; n++) {
							_allocator.destroy(_array + n);

						}
						_size = count;
					}
				}

				iterator	erase(iterator pos) {
					if (empty() || pos == end())
						return end();
					_allocator.destroy(pos.getPtr());
					pointer it = pos.getPtr();
					pointer ite = end().getPtr() - 1;
					while (it != ite) {
						_allocator.construct(it, *(it + 1)); // on decale ce au il y a apres pos pour combler le trou
						_allocator.destroy(it + 1); 
						it++;
					}
					_size--;
					return pos;
				}

				iterator	erase(iterator first, iterator last) {
					if (empty())
						return end();
					size_type n = std::distance(first, last);
					for (pointer it = first.getPtr(); it != last.getPtr(); it++) {
						_allocator.destroy(it); 
					}
					pointer it = first.getPtr();
					pointer ite = end().getPtr() - n;
					while (it != ite) {
						_allocator.construct(it, *(it + n)); // on decale ce au il y a apres pos pour combler le trou
						_allocator.destroy(it + n); 
						it++;
					}
					_size -= n;
					return first;
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
		bool operator==(vector<T, Alloc> const &lhs, vector<T, Alloc> const &rhs) {
			if (lhs.size() != rhs.size())
				return false;
			return equal(lhs.begin(), lhs.end(), rhs.begin());
		}
	template <class T, class Alloc>
		bool operator!=(vector<T, Alloc> const &lhs, vector<T, Alloc> const &rhs) {return !(lhs == rhs);}
	template <class T, class Alloc>
		bool operator<(vector<T, Alloc> const &lhs, vector<T, Alloc> const &rhs) { 
			return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}
	template <class T, class Alloc>
		bool operator<=(vector<T, Alloc> const &lhs, vector<T, Alloc> const &rhs) {return lhs < rhs || lhs == rhs;}
	template <class T, class Alloc>
		bool operator>(vector<T, Alloc> const &lhs, vector<T, Alloc> const &rhs) {return rhs < lhs;}
	template <class T, class Alloc>
		bool operator>=(vector<T, Alloc> const &lhs, vector<T, Alloc> const &rhs) {return lhs > rhs || lhs == rhs;}

	template <class T, class Alloc>
		void	swap(vector<T, Alloc> const &lhs, vector<T, Alloc>const &rhs) {lhs.swap(rhs);}
}

#endif
