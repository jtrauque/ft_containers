#ifndef MAP_HPP
#define MAP_HPP

#include "map_utils.hpp"
#include "map_iterator.hpp"
#include <iterator>
#include <iostream>
#include <memory>
#include "enable_if.hpp"
#include "tree.hpp"

#define RED	1
#define BLACK 0

//https://en.cppreference.com/w/cpp/container/map
namespace	ft {
	template<class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >

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
				typedef	map_iterator<value_type> iterator;
				typedef	map_iterator_const<value_type> const_iterator;
				typedef	typename	ft::reverse_iterator<iterator> reverse_iterator;
				typedef	typename	ft::reverse_iterator<const_iterator> const_reverse_iterator;
				typedef	node<value_type> node;
				typedef typename allocator_type::template rebind<node>::other node_allocator; 

				//https://en.cppreference.com/w/cpp/container/map/value_compare
				//std::map::value_compare is a function object that compares objects of type std::map::value_type (key-value pairs) by comparing of the first components of the pairs.
				class	value_compare	{
					public:
						typedef bool	result_type;
						typedef	value_type	first_argument_type;
						typedef	value_type	second_argument_type;

						value_compare(Compare c) : _comp(c) {}

						bool	operator()(value_type const &lhs, value_type const &rhs) const { return _comp(lhs.first, rhs.first); }
					protected:
						Compare	_comp;
				};

			protected:
				node_allocator	_alloc_node;
				allocator_type	_allocator;
				node*	_root;
				size_type _size;
				key_compare	_comp;

			public:
				//default constructor
				explicit	map(const key_compare &comp = key_compare(), allocator_type const &alloc = allocator_type()) :
					_alloc_node(alloc), _root(NULL), _size(0), _comp(comp) {}
				//range constructor
				template<class InputIterator>
					map(InputIterator first, InputIterator last, key_compare const comp = key_compare(),
							allocator_type const &alloc = allocator_type()) :
						_alloc_node(alloc), _root(NULL), _size(0), _comp(comp) { insert(first, last); } //
				map(map const & src) : _alloc_node(src._alloc_node), _root(NULL), _size(0), _comp(src._comp) { *this = src; }
				~map(void) { clearTree(_root); }  //

				//https://en.cppreference.com/w/cpp/container/map/insert
				pair<iterator, bool>	insert(value_type const &value) {
					size_type oldSize = _size;
					node *tmp = insertNode(value, _root);
					iterator it = iterator(tmp);
					return ft::make_pair<iterator, bool>(it, _size != oldSize);

				}

				iterator	insert(iterator pos, value_type const &value) {
					(void)pos;
					node	*tmp = insertNode(value, _root);
					return (iterator(tmp));
				}

				template<class InputIterator>
					void	insert(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
							InputIterator last) {
						while (first != last) {
							insert(*first);
							first++;
						}
					}	

				map	&operator=(map const &rhs) {
					clear();
					_comp = rhs._comp;
					for(const_iterator it = rhs.begin(); it != rhs.end(); it++) {
						insert(*it);
					}
					return *this;
				}

				allocator_type	get_allocator(void) const {
					return _alloc_node;
				}

				//https://en.cppreference.com/w/cpp/container/map/operator_at

				mapped_type	&operator[](key_type const &key) {
					node	*tmp = searchKey(key, _root);
					if (tmp)
						return tmp->value.second;
					insert(value_type(key, mapped_type()));
					return searchKey(key, _root)->value.second;
				}

				iterator	begin(void) {
					if (_size == 0)
						return iterator(_root);
					node *first = _root;
					while (first && first->left)
						first = first->left;
					return iterator(first);
				}

				const_iterator	begin(void) const {
					if (_size == 0)
						return const_iterator(_root);
					node *first = _root;
					while (first && first->left)
						first = first->left;
					return const_iterator(first);
				}

				iterator	end(void) {
					if (_size == 0)
						return iterator(_root);
					node *last = _root;
					while (last && last->right)
						last = last->right;
					return iterator(last);
				}

				const_iterator	end(void) const {
					if (_size == 0)
						return const_iterator(_root);
					node *last = _root;
					while (last && last->right)
						last = last->right;
					return const_iterator(last);
				}
				bool	empty(void) const {
					return _size == 0;
				}

				size_type	size(void) const {
					return _size;
				}

				size_type	max_size(void) const {
					return _alloc_node.max_size();
				}

				void	clear(void) {
					clearTree(_root);
					_root = _alloc_node.allocate(1);
					_alloc_node.construct(_root, node());
					_root->left = NULL;
					_root->right = NULL;
					_root->color = BLACK;
					_size = 0;	
				}
	
				void	erase(iterator position) {
					node	*tmp = position._current;
					if (tmp) 
						deleteNode(tmp->value.first, position);
				}

				void	erase(iterator first, iterator last) {
					while (first != last) {
						node	*tmp = searchNode(first._current);
						if (tmp)
							deleteNode(tmp->value.first, first);
						first++;
					}
				}

				size_type	erase(const key_type	&k) {
					node	*tmp = searchKey(k, _root);
					size_type	initSize = this->size();
					if (tmp)
						deleteNode(tmp->value.first, position);
					return initSize - this->size();
				}

			protected:
				
				void	deleteNode(key_type	const &key, iterator pos) {
					node	*tmp = searchKey(key, pos._current);
					node	*up = tmp->parent;
					if (tmp->left)
						node	*downL = tmp->left;
					if (tmp->right)
						node	*downR = tmp->right;
					_alloc_node.destroy(tmp);
					_alloc_node.deallocate(tmp, 1);
					if (downL)
						up->left = downL;
					if (downR)
						up->right = downR;
					insertFix(_root);	
				}

				void	clearTree(node	*current) {
					if (current->left)
						clearTree(current->left);
					if (current->right)
						clearTree(current->right);
					if (current) {
						_alloc_node.destroy(current);
						_alloc_node.deallocate(current, 1);
					}
				}

				node	*searchKey(key_type	const &key, node	*current) {
					if (!current)
						return NULL;
					if (_comp(key, current->value.first) == true)
						searchKey(key, current->left);
					else if (_comp(current->value.first, key) == true)
						searchKey(key, current->right);
					else 
						return current;
				}

				node	*newNode(value_type	const &value, node *parent) {
					node *tmp = _alloc_node.allocate(1);
					/* _alloc_node.construct(newNode, node(value, NULL, NULL, parent, false)); */
					_alloc_node.construct(tmp, node());
					_allocator.construct(&tmp->value, value);
					tmp->parent = parent;
					tmp->left = NULL;
					tmp->right = NULL;
					_size++;
					tmp->color = RED;
					return tmp;
				}

				void	insertFix(node* current) {
					node*	tmp;
					while (current->parent->color == RED) {
						if (current->parent == current->parent->parent->right) {
							tmp = current->parent->parent->left;
							if (tmp->color == RED) {
								tmp->color = BLACK;
								current->parent->color = BLACK;
								current->parent->parent->color = RED;
								current = current->parent->parent;
							} else {
								if (current == current->parent->left) {
									current = current->parent;
									rightRotate(current);
								}
								current->parent->color = BLACK;
								current->parent->parent->color = RED;
								leftRotate(current->parent->parent);
							}
						} else {
							tmp = current->parent->parent->right;
							if (tmp->color == RED) {
								tmp->color = BLACK;
								current->parent->color = BLACK;
								current->parent->parent->color = RED;
								current = current->parent->parent;
							} else {
								if (current == current->parent->left) {
									current = current->parent;
									leftRotate(current);
								}
								current->parent->color = BLACK;
								current->parent->parent->color = RED;
								rightRotate(current->parent->parent);
							}
						}
						if (current == _root)
							break ;
					}
					_root->color = BLACK;
				}

				void	leftRotate(node *current) {
					node*	tmp = current->right;
					current->right = tmp->left;
					if (tmp->left)
						tmp->left->parent = current;
					tmp->parent = current->parent;
					if (current->parent)
						_root = tmp;
					else if (current == current->parent->left)
						current->parent->left = tmp;
					else
						current->parent->right = tmp;
					tmp->left = current;
					current->parent = tmp;
				}

				void	rightRotate(node *current) {
					node*	tmp = current->left;
					current->right = tmp->right;
					if (tmp->right)
						tmp->right->parent = current;
					tmp->parent = current->parent;
					if (current->parent)
						_root = tmp;
					else if (current == current->parent->right)
						current->parent->right = tmp;
					else
						current->parent->left = tmp;
					tmp->right = current;
					current->parent = tmp;
				}

				node	*insertNode(value_type	const &value, node* current) {
					if (!current) {
						return newNode(value, current);
					}
					else {
						while (current) {
							if (value > current->value) {
								if (!current->right)
									break;
								current = current->right;
							}
							else {
								if (!current->left)
									break;
								current = current->left;
							}
						}
						if (value < current->value && !current->left)
							current->left = newNode(value, current);
						else 
							current->right = newNode(value, current);
						insertFix(current);

					}
				}


				/* clearNode(node *node) */
		};
}

#endif
