#ifndef SET_ITERATOR_HPP
#define	SET_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "tree.hpp"
#include "reverse_iterator.hpp"

#define BLUE "\e[0;34m"
#define NC "\e[0m"
namespace	ft {

	template<class T>
		class	set_iterator_const;

	template<class T>
		class	set_iterator {
			public:
				typedef T value_type;
				typedef T* pointer;
				typedef T& reference;
				typedef	std::ptrdiff_t	difference_type;
				typedef ft::bidirectional_iterator_tag iterator_category;
				typedef node<T> node;

			protected :
				node *_current;

			public:
				set_iterator(void) : _current(NULL) {}
				set_iterator(node* node) : _current(node) {}
				set_iterator(set_iterator const & src) : _current(src._current) {}
				set_iterator	&operator=(set_iterator const & rhs) { 
					_current = rhs._current;
					return *this;
				}
				virtual ~set_iterator(void) {}

				set_iterator	&operator++(void) {
					//	std::cout << "current iterator : " << _current->parent->value.first << std::endl;
					if (!_current) 
						return *this;
					if (_current->right) {
						_current = _current->right;
						while (_current->left)
							_current = _current->left;	
					} 
					else if (_current->parent) {
						while (_current->parent && _current->parent->right == _current)
							_current = _current->parent;
						if (_current->parent && _current->parent->left == _current) {
							_current = _current->parent; // root became ++ si no right
						} 
						else {
							_current = NULL;
						}
					}
					else 
						_current = NULL;
					return *this;
				}

				set_iterator	operator++(int) { 
					set_iterator tmp = *this;
					++(*this);
					return tmp;
				}

				set_iterator	&operator--(void) {
					if (_current) {
						if (_current->left) {
							_current = _current->left;
							while (_current && _current->right)
								_current = _current->right;
						}
						else {
							node *tmp = _current; // on preserve la valeur de depart
							_current = _current->parent; //on remonte d un crant 
							while (_current && (_current->right != tmp)) { // tant qu il n y a pas de droite on monte
								tmp = _current;
								_current = _current->parent;
							}
						}
					}
					return *this;
				}

				set_iterator	operator--(int) { 
					set_iterator tmp = *this;
					--(*this);
					return tmp;
				}

				reference	operator*() const { return _current->value; }
				pointer	operator->() const { return &(operator*()); }
				node	*getNode(void) const { return _current; }
				bool	operator==(const set_iterator_const<T> &rhs) const { return _current == rhs.getNode(); }
				bool	operator!=(const set_iterator_const<T> &rhs) const { return _current != rhs.getNode(); }	
		};

	template<class T>
		class	set_iterator_const {
			public:
				typedef const T value_type;
				typedef const T* pointer;
				typedef const T& reference;
				typedef	std::ptrdiff_t	difference_type;
				typedef ft::bidirectional_iterator_tag iterator_category;
				typedef node<T> node;

			protected :
				node *_current;

			public:
				set_iterator_const(void) : _current(NULL) {}
				set_iterator_const(node* node) : _current(node) {}
				set_iterator_const(set_iterator_const const & src) : _current(src._current) {}
				set_iterator_const(set_iterator<T> const & src) : _current(src.getNode()) {}
				set_iterator_const	&operator=(set_iterator_const const & rhs) { 
					_current = rhs._current;
					return *this;
				}
				virtual ~set_iterator_const(void) {}

				set_iterator_const	&operator++(void) {
					if (_current) {
						if (_current->right) {
							_current = _current->right;
							while (_current->left)
								_current = _current->left;
						}
						else {
							node *tmp = _current; // on preserve la valeur de depart
							_current = _current->parent; //on remonte d un crant 
							while (_current && _current->left != tmp) { // tant qu il n y a pas de droite on monte
								tmp = _current;
								_current = _current->parent;
							}
						}
					}
					return *this;
				}

				set_iterator_const	operator++(int) { 
					set_iterator_const tmp = *this;
					++(*this);
					return tmp;
				}

				set_iterator_const	&operator--(void) {
					if (_current) {
						if (_current->left) {
							_current = _current->left;
							while (_current && _current->right)
								_current = _current->right;
						}
						else {
							node *tmp = _current; // on preserve la valeur de depart
							_current = _current->parent; //on remonte d un crant 
							while (_current && (_current->right != tmp)) { // tant qu il n y a pas de droite on monte
								tmp = _current;
								_current = _current->parent;
							}
						}
					}
					return *this;
				}

				set_iterator_const	operator--(int) { 
					set_iterator_const tmp = *this;
					--(*this);
					return tmp;
				}
				/* operator set_iterator<const T>() const { return set_iterator<const T>(_current);} */
				reference	operator*() const { return _current->value; }
				pointer	operator->() const { return &(operator*()); }
				node	*getNode(void) const { return _current; }
				bool	operator==(const set_iterator_const &rhs) const { return _current == rhs.getNode(); }
				bool	operator!=(const set_iterator_const &rhs) const { return _current != rhs.getNode(); }	
		};

}

#endif
