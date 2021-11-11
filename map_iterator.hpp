#ifndef MAP_ITERATOR_HPP
#define	MAP_ITERATOR_HPP

#include "iterator_traits"
#include "tree.hpp"

namespace	ft {
	template<typename T>
		class	map_iterator {
			public:
				typedef T value_type;
				typedef T* pointer;
				typedef T& reference;
				typedef	std::ptrdiff_t	difference_type;
				typedef ft::budirectionnal_iterator_tag iterator_category;
				typedef node<T> node;

			protected :
				node *_current;

			public:
				map_iterator(void) : _current(NULL) {}
				map_iterator(node* node) : _current(node) {}
				map_iterator(map_iterator const & src) : _current(src._current) {}
				map_iterator	&operator=(map_iterator const & rhs) { 
					_current = rhs._current;
					return *this;
				}
				~map_iterator(void) {}

				map_iterator	&operator++(void) {
					if (_current->right) {
						_current = current->right;
						while (_current->left)
							_current = current->left;
					}
					else {
						node *tmp = _current; // on preserve la valeur de depart
						_curent = _current->parent; //on remonte d un crant 
						while (_current && _current->left != tmp) { // tant qu il n y a pas de droite on monte
							tmp = _current;
							_current = _current->parent;
						}
					}
				}
				
				map_iterator	operator++(int) { 
					map_iterator tmp = *this;
					++(*this);
					return tmp;
				}

				map_iterator	&operator--(void) {
					if (_current->left) {
						_current = current->left;
						while (_current && _current->right)
							_current = current->right;
					}
					else {
						node *tmp = _current; // on preserve la valeur de depart
						_curent = _current->parent; //on remonte d un crant 
						while (_current && (_current->right != tmp)) { // tant qu il n y a pas de droite on monte
							tmp = _current;
							_current = _current->parent;
						}
					}
				}

				map_iterator	operator--(int) { 
					map_iterator tmp = *this;
					--(*this);
					return tmp;
				}

				reference	operator*() const { return _current->value; }
				reference	operator->() const { return &(operator*()); }
				node	*getNode(void) { return _current; }
				bool	operator==(const map_iterator_const<T> &rhs) const { return _current == rhs.getNode(); }
				bool	operator!=(const map_iterator_const<T> &rhs) const { return _current != rhs.getNode(); }	
		};
}

#endif
