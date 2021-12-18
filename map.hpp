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
#define NC "\e[0m"
#define REDC "\e[0;31m"
#define GRN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define PINK "\e[0;35m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"

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
				void printTree() {
					if (_root != NULL) _root->printTree();
				}
				//default constructor
				explicit	map(const key_compare &comp = key_compare(), allocator_type const &alloc = allocator_type()) :
					_alloc_node(alloc), _root(NULL), _size(0), _comp(comp) {}
				//range constructor
				template<class InputIterator>
					map(InputIterator first, InputIterator last, key_compare const comp = key_compare(),
							allocator_type const &alloc = allocator_type()) :
						_alloc_node(alloc), _root(NULL), _size(0), _comp(comp) { insert(first, last); } //
				map(map const & src) : _alloc_node(src._alloc_node), _root(NULL), _size(0), _comp(src._comp) { *this = src; }
				~map(void) {  std::cout << "Destructeur" << std::endl; clearTree(_root); }  //

				//https://en.cppreference.com/w/cpp/container/map/insert
				pair<iterator, bool>	insert(value_type const &value) {
					std::cout << GRN "InsertPair Function" NC << std::endl;
					size_type oldSize = _size;
					return ft::make_pair<iterator, bool>(insert(0, value), _size != oldSize);
				}

				iterator	insert(iterator pos, value_type const &value) {
					std::cout << GRN "InsertIterator Function" NC << std::endl;
				//	size_type oldSize = _size;
					(void)pos;
					insertNode(value);
					std::cout << _root->value.first << std::endl;
					node	*tmp = searchKey(value.first, _root);
					return iterator(tmp);
				}

				template<class InputIterator>
					void	insert(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
							InputIterator last) {
						std::cout << GRN "Insert several Iterators Function" NC << std::endl;
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
					std::cout << YELLOW "Operator[] Function" NC << std::endl;
					node	*tmp = searchKey(key, _root);
					if (tmp){
						std::cout << PINK "Operator[] found" NC << std::endl;
						return tmp->value.second;
					}
					std::cout << PINK "Operator[" << key << "] not found" NC << std::endl;
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
						deleteNode(tmp->value.first);
				}

				void	erase(iterator first, iterator last) {
					while (first != last) {
						node	*tmp = searchNode(first._current);
						if (tmp)
							deleteNode(tmp->value.first);
						first++;
					}
				}

				size_type	erase(const key_type	&k) {
					std::cout << PINK "ERASE Function" NC << std::endl;
					size_type	initSize = this->size();
					deleteNode(k);
					return initSize - this->size();
				}

			protected:
				void	deleteNode(key_type	const &key) {
					node	*tmp = searchKey(key, _root);
					if (!tmp)
						return ;
					node	*up = tmp->parent;
					node	*downL = NULL;
					node	*downR = NULL;
					if (tmp->left)
						downL = tmp->left;
					if (tmp->right)
						downR = tmp->right;
					_alloc_node.destroy(tmp);
					_alloc_node.deallocate(tmp, 1);
					if (up->left == tmp) {
						up->left = downL;
						if (up->left)
							deleteFix(up->left);
					}
					else if (up->right == tmp) {
						up->right = downR;
						if (up->right)
							deleteFix(up->right);
					}
				}
				
				void	deleteFix(node* current) {
					node*	tmp;

					while (current && current->parent && current != searchRoot() && current->color == BLACK) {
						if (current == current->parent->left) { 
						// case 1 : if the right child of parent of x is RED
							tmp = current->parent->right;
							if (tmp && tmp->color == RED) {
								tmp->color = BLACK;
								current->parent->color = RED;
								leftRotate(current->parent);
								tmp = current->parent->right;
							}
							if (tmp && tmp->left->color == BLACK && tmp->right->color == BLACK) {
							// case 2 : if the color of both the right and the leftChild is BLACK
								tmp->color = RED;
								current = current->parent;
							} else {
								if (tmp->right->color == BLACK) {
								// case 3 : if the color of the rightChild of w is BLACK
									tmp->left->color = BLACK;
									tmp->color = RED;
									rightRotate(tmp);
									tmp = current->parent->right;
								}
								// case 4 :If any of the above cases do not occur
								tmp->color = current->parent->color;
								current->parent->color = BLACK;
								tmp->right->color = BLACK;
								leftRotate(current->parent);
								current = searchRoot();
							}
						} else {
							//the same as above with right changed to left and vice versa 
							tmp = current->parent->left;
							if (tmp && tmp->color == RED) {
								tmp->color = BLACK;
								current->parent->color = RED;
								rightRotate(current->parent);
								tmp = current->parent->left;
							}

							if (tmp && tmp->right->color == BLACK && tmp->left->color == BLACK) { //
								tmp->color = RED;
								current = current->parent;
							} else {
								if (tmp->left->color == BLACK) {
									tmp->right->color = BLACK;
									tmp->color = RED;
									leftRotate(tmp);
									tmp = current->parent->left;
								}
								tmp->color = current->parent->color;
								current->parent->color = BLACK;
								tmp->left->color = BLACK;
								rightRotate(current->parent);
								current = searchRoot();
							}
						}
					}
					current->color = BLACK;
				}

				void	clearTree(node	*current) {
					std::cout << GRN "ClearTree Function" NC << std::endl;
					node	*tmp = (current);
					if (tmp->left)
						clearTree(tmp->left);
					if (tmp->right)
						clearTree(tmp->right);
					if (tmp) {
						_alloc_node.destroy(tmp);
						_alloc_node.deallocate(tmp, 1);
					}
				}

				node	*searchRoot() {
					node	*tmp = _root;
					while (tmp->parent)
						tmp = tmp->parent;
					return tmp;
				}

				node	*searchKey(key_type	const &key, node	*current) {
					std::cout << GRN "SearchKey Function" NC << std::endl;
					//std::cout << current->value.first << std::endl;
					if (!current) {
						std::cout << "No tree on the line, no match" << std::endl;
						return NULL;
					}
					if (_comp(key, current->value.first) == true) { // if key < first -> go left
						std::cout << "search Left" << std::endl;
						return searchKey(key, current->left);
					}
					else if (_comp(current->value.first, key) == true) { // if first < key -> go right
						std::cout << "search Right" << std::endl;
						return searchKey(key, current->right);
					}
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
					std::cout << "Our new Node first value is :" << tmp->value.first << " end out second is:" << tmp->value.second << std::endl;
					return tmp;
				}

				void	insertFix(node* current) {
					node*	tmp;

					while (current->parent && current->parent->parent && current->parent->color == RED) {
						if (current->parent == current->parent->parent->right) {
							tmp = current->parent->parent->left;
							if (tmp && tmp->color == RED) {
							// Case 1 : if the color of the left child of grandPa is RED
								tmp->color = BLACK;
								current->parent->color = BLACK;
								current->parent->parent->color = RED;
								current = current->parent->parent;
							} else {
								if (current == current->parent->left) {
							// Case 2 : if the node is the left child of the parent
									current = current->parent;
									rightRotate(current);
								}
							// Case 3 : if none of the above
								current->parent->color = BLACK;
								current->parent->parent->color = RED;
								leftRotate(current->parent->parent);
							}
						} else { 
							// the same as above with left changed to right and vice versa 
							tmp = current->parent->parent->right;
							if (tmp && tmp->color == RED) {
								tmp->color = BLACK;
								current->parent->color = BLACK;
								current->parent->parent->color = RED;
								current = current->parent->parent;
							} else {
								if (current == current->parent->right) {
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
					node	*tmp  = current->right;
					printTree();
					current->right = tmp->left;
					if (tmp->left)
						tmp->left->parent = current;
					tmp->parent = current->parent;
					if (!current->parent)
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
					printTree();
					current->left = tmp->right; //
					if (tmp->right)
						tmp->right->parent = current;
					tmp->parent = current->parent;
					if (!current->parent)
						_root = tmp;
					else if (current == current->parent->right)
						current->parent->right = tmp;
					else
						current->parent->left = tmp;
					tmp->right = current;
					current->parent = tmp;
				}

				void	insertNode(value_type	const &value) {
					std::cout << GRN "InsertNode Function" NC << std::endl;
					if (!_root) {
						_root = newNode(value, NULL);
					}
					else {
						node *current = _root;
						while (current) {
							std::cout << "Lets find the right branch to our Tree" << std::endl;
							if (value > current->value) {
								if (!current->right) {
									current->right = newNode(value, current);
									insertFix(current->right);
									break;
								}
								current = current->right;
							}
							else {
								if (!current->left) {
									current->left = newNode(value,current);
									insertFix(current->left);
									break;
								}
								current = current->left;
							}
						}
					}
				}
		};
}

#endif
