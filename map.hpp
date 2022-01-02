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
					_alloc_node(alloc), _root(NULL), _size(0), _comp(comp) {
						std::cout << "map constructeur standard" << std::endl;
					}
				//range constructor
				template<class InputIterator>
					map(InputIterator first, InputIterator last, key_compare const comp = key_compare(),
							allocator_type const &alloc = allocator_type()) :
						_alloc_node(alloc), _root(NULL), _size(0), _comp(comp) {
							std::cout << "map constructeur itererator" << std::endl;
							insert(first, last); 
						} //
				map(map const & src) : _alloc_node(src._alloc_node), _root(NULL), _size(0), _comp(src._comp) {
					std::cout << REDC "map copy constructeur" NC << std::endl;
					*this = src; 
				}
				~map(void) {  std::cout << "Destructeur" << std::endl;
					std::cout << "root = " << _root << std::endl;
					if (_root) {clearTree(_root);} 
				}  //

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
					void	insert(InputIterator first, InputIterator last) {
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
					std::cout << YELLOW "Operator[] Function :" << key <<  NC << std::endl;
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
					//	std::cout << "begin function : " << first->value.first << std::endl;
					while (first && first->left)
						first = first->left;
					//	std::cout << YELLOW "begin function : " << first->value.first << NC << std::endl;
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

				reverse_iterator	rbegin(void) {
					if (_size == 0)
						return iterator(_root);
					node *last = _root;
					while (last && last->right)
						last = last->right;
					return reverse_iterator(last);
				}

				const_reverse_iterator	rbegin(void) const {
					if (_size == 0)
						return iterator(_root);
					node *last = _root;
					while (last && last->right)
						last = last->right;

					return const_reverse_iterator(last);
				}

				reverse_iterator	rend(void) {
					return reverse_iterator(begin());
				}

				const_reverse_iterator	rend(void) const {
					return const_reverse_iterator(begin());
				}

				iterator	end(void) {
					std::cout << YELLOW "End Function" NC << std::endl;
					if (_size == 0)
						return iterator(_root);
					node *last = _root;
					while (last)
						last = last->right;
					return iterator(last);
				}

				const_iterator	end(void) const {
					std::cout << YELLOW "End const Function" NC << std::endl;
					if (_size == 0)
						return const_iterator(_root);
					node *last = _root;
					while (last)
						last = last->right;
					return const_iterator(last);
				}
				bool	empty(void) const {
					return (_size == 0 ? true : false);
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
					std::cout << PINK "ERASE IT Function" NC << std::endl;
					deleteNode(position.getNode());
				}

				void	erase(iterator first, iterator last) {
					std::cout << PINK "ERASE 2 IT Function" NC << std::endl;
					iterator tmp;
					while (first != last) {
						tmp = first;
						tmp++;
						erase(first);
						first = tmp;
					}
				}

				size_type	erase(const key_type	&k) {
					std::cout << PINK "ERASE Function" NC << std::endl;
					size_type	initSize = this->size();
					deleteNode(searchKey(k, _root));
					return initSize - this->size();
				}

				void	swap(map &x) {

					node_allocator	tmp_node_alloc = x._alloc_node;
					allocator_type	tmp_alloc = x._allocator;
					node*	tmp_node = x._root;
					size_type tmp_size = x._size;
					key_compare	tmp_comp = x._comp;

					x._alloc_node = _alloc_node;
					x._allocator = _allocator;
					x._root = _root;
					x._size = _size;
					x._comp = _comp;

					_alloc_node = tmp_node_alloc;
					_allocator = tmp_alloc;
					_root = tmp_node;
					_size = tmp_size;
					_comp = tmp_comp;
				}

				key_compare	key_comp(void) const {
					return this->comp;
				}

				value_compare	value_comp(void) const {
					return value_compare(this->comp);
				}

				iterator	find(const key_type &k) {
					node	*tmp = searchKey(k, _root);
					if (tmp)
						return iterator(tmp);
					return end();
				}

				const_iterator	find(const key_type &k) const {
					node	*tmp = searchKey(k, _root);
					if (tmp)
						return const_iterator(tmp);
					return end();
				}

				size_type	count(const key_type &k) const {
					node	*tmp = searchKey(k, _root);
					if (tmp)
						return 1;
					return 0;
				}

				iterator	lower_bound(const key_type &k) {
					iterator it = begin();
					while (it != end()) {
						if (it->first == k || !_comp(it->first, k))
							return it;
						it++;
					}
					return end();
				}

				const_iterator	lower_bound(const key_type &k) const {
					const_iterator it = begin();
					while (it != end()) {
						if (it->first == k || !_comp(it->first, k))
							return const_iterator(it);
						it++;
					}
					return const_iterator(end());

				}

				iterator	upper_bound(const key_type &k) {
					iterator it = begin();
					while (it != end()) {
						if (it->first != k || !_comp(it->first, k))
							return it;
						it++;
					}
					return end();

				}

				const_iterator	upper_bound(const key_type &k) const {
					const_iterator it = begin();
					while (it != end()) {
						if (it->first != k || !_comp(it->first, k))
							return const_iterator(it);
						it++;
					}
					return const_iterator(end());

				}

				pair<const_iterator, const_iterator>	equal_range(const key_type &k) const {
					return ft::make_pair(lower_bound(k), upper_bound(k));
				}

				pair<iterator, iterator>	equal_range(const key_type &k) {
					return ft::make_pair(lower_bound(k), upper_bound(k));
				}

			protected:
				node	*findNextNode(node *tmp) {
					node 	*ref = tmp;
					if (tmp && tmp->right)
						tmp = tmp->right;
					while(tmp && tmp->left)
						tmp = tmp->left;
					if (tmp == ref) {
						if (tmp->left)
							tmp = tmp->left;
						while(tmp && tmp->left)
							tmp = tmp->left;
					}
					return tmp;		
				}

				void 	deleteNode(node *tmp) {
					std::cout << REDC "Delete Function :"  << NC << std::endl;
					if (!tmp)
						return;
					std::cout << REDC "Delete Function :"  << tmp->value.first << NC << std::endl;
					if (tmp == _root) {
						if (!tmp->right && !tmp->left)
							_root = NULL; 
						//do that
						return ;
					}
					node	**childOf = tmp->parent->right == tmp ? &tmp->parent->right : &tmp->parent->left;
					// if right childof = tmp right else childt
					// if tmp has no children -> tmp became null
					if (!tmp->right && !tmp->left) {
						*childOf = NULL;
					}
					else if (tmp->right && !tmp->left) {
						//if tmp has only a right child, the child take tmp's place
						*childOf = tmp->right;
						tmp->right->parent = tmp->parent;
						deleteFix(tmp, tmp->right);
					}
					else if (!tmp->right && tmp->left) {
						//if tmp has only a left child, the child take tmp's place
						/* deleteFix(*childOf); */
						*childOf = tmp->left;
						tmp->left->parent = tmp->parent;
						deleteFix(tmp, tmp->left);
					}
					else {
						//if tmp has both children the 
						std::cout << "ON PASSE LA" << std::endl;
						node	*next = findNextNode(tmp);
						*childOf = next;
						/* deleteFix(*childOf); */
						//next cannot have left children as it has to be the most lefty to be the closest to tmp
						next->left = tmp->left;
						if (next->left) {
							//if tmp->left != NULL tmp->left take tmp
							next->left->parent = next; //
							/* deleteFix(next->left->parent); */
						}
						/* if (tmp->parent->right == tmp) { */
						/* 	if (next->right && next->parent != tmp) { */
						/* 		next->right->parent = next->parent; */
						/* 		next->parent = next->right; */
						/* 	} */
						/* 	tmp->parent->right = next; */
						/* 	next->parent = tmp->parent; */
						/* 	next->left = tmp->left; */
						/* } */
						if (next->right && next->parent != tmp) {
							next->right->parent = next->parent;
							next->parent->left = next->right;
						}
						next->parent = tmp->parent;
						deleteFix(tmp, next);
						/* else { */
						/* 	if (next->right && next->parent != tmp) { */
						/* 		next->right->parent = next->parent; */
						/* 		next->parent = next->right; */
						/* 	} */
						/* 	tmp->parent->left = next; */
						/* 	next->parent = tmp->parent; */
						/* 	next->left = tmp->left; */
						/* 	//next->right = tmp->right; */
						/* } */
					}
					/* if (_root) */
					/* 	deleteFix(_root); */
					_alloc_node.destroy(tmp);
					_alloc_node.deallocate(tmp, 1);
					_size--;
				}


				/*	void	deleteNode(node *tmp) {
					std::cout << REDC "Delete Function :"  << NC << std::endl;
					if (!tmp)
					return ;
					node	*up = tmp->parent;
					node *downL = tmp->left;
					node *downR = tmp->right;

					if (up && up->left == tmp) {
					up->left = downL;
					if (downL)
					downL->parent = up;
					printTree();
					if (up->left)
					deleteFix(up->left);
					}
					else if (up && up->right == tmp) {
					up->right = downR;
					if (downR)
					downR->parent = up;
					if (up->right)
					deleteFix(up->right);
					}
					else {	
					if (downL) {
					node	*newValue = downL;
					while (newValue && newValue->right)
					newValue = newValue->right;
					_root = newValue;
					if (downR) {
					_root->right = downR;
					downR->parent = _root;
					}
					_root->parent = NULL;
					}
					else if (downR) {
					node	*newValue = tmp->right;
					while (newValue && newValue->left)
					newValue = newValue->left;
					_root->parent = NULL;
					_root = newValue;
					}
					else
					_root = NULL;

					if (_root) {
					printTree();
					deleteFix(_root);
					}
					}
					_alloc_node.destroy(tmp);
					_alloc_node.deallocate(tmp, 1);
					_size--;
					}*/
				void	deleteFix(node* delNode, node* nextNode) {
					std::cout << REDC "Delete FIX Function :" << NC << std::endl;
					if (delNode->color == RED && (!nextNode || nextNode->color == RED))
						return ;
					else if (delNode->color == BLACK && nextNode->color == RED) {
						nextNode->color = BLACK;
						return ;
					}
					else if (delNode->color == BLACK && (!nextNode || nextNode->color == BLACK) && !delNode->parent) {
						std::cout << BLUE << __LINE__ << NC << std::endl;
						return ;
					}
					else if (delNode->color == RED && nextNode->color == BLACK) { //case 0
						nextNode->color = RED;
						if (nextNode->right) {
							nextNode->right->color = BLACK;
						}
						std::cout << BLUE << __LINE__ << NC << std::endl;
					}
					if (delNode->color == RED)
						delNode->color = BLACK;
					if (delNode->color == BLACK && nextNode->color == BLACK && delNode->parent) {
						node	*brother = delNode->getSibling(delNode);
						std::cout << BLUE << __LINE__ << NC << std::endl;
						if (!brother) {
						std::cout << BLUE << __LINE__ << NC << std::endl;

							return ;
						}
						if (brother->color == RED) {
						std::cout << BLUE << __LINE__ << NC << std::endl;
							brother->color = BLACK;
							delNode->parent->color = RED;
							if (delNode == delNode->parent->left) {
								leftRotate(delNode->parent);
								brother = delNode->parent->right;
							}
							else {
								rightRotate(delNode->parent);
								brother = delNode->parent->left;
							}

						}
						if (brother->right && brother->left && brother->left->color == BLACK
								&& brother->right->color == BLACK) {
						std::cout << BLUE << __LINE__ << NC << std::endl;
							brother->color = RED;
							delNode = delNode->parent;
							if (delNode->color == RED)
								delNode->color = BLACK;
							else if (delNode->color == BLACK)
								deleteFix(delNode, nextNode);
						}
						if (delNode == delNode->parent->left) {
							if (brother->left && brother->left->color == RED
									&& ((brother->right && brother->right->color == BLACK) || !brother->right)) {
						std::cout << BLUE << __LINE__ << NC << std::endl;
								brother->left->color = BLACK;
								brother->color = RED;
								rightRotate(brother);
								brother = delNode->parent->right;
							}
							if (brother->right && brother->right->color == RED) {
						std::cout << BLUE << __LINE__ << NC << std::endl;
								brother->color = delNode->parent->color;
								delNode->parent->color = BLACK;
								brother->right->color = BLACK;
								leftRotate(delNode->parent);
							}
						}
						else if (delNode == delNode->parent->right) {
							if (brother->right && brother->right->color == RED
									&& ((brother->left && brother->left->color == BLACK) || !brother->left)) {
						std::cout << BLUE << __LINE__ << NC << std::endl;
								brother->right->color = BLACK;
								brother->color = RED;
								leftRotate(brother);
								brother = delNode->parent->left;
							}
							if (brother->left && brother->left->color == RED) {
						std::cout << BLUE << __LINE__ << NC << std::endl;
								brother->color = delNode->parent->color;
								delNode->parent->color = BLACK;
								brother->left->color = BLACK;
								rightRotate(delNode->parent);
							}

						}
					}
				}
				/* void	deleteFix(node* current) { */
				/* 	std::cout << REDC "Delete FIX Function :" << NC << std::endl; */
				/* 	printTree(); */
				/* 	node*	tmp; */

				/* 	while (current && current->parent && current->color == BLACK) { */
				/* 		if (current == current->parent->left) { */ 
				/* 			tmp = current->parent->right; */
				/* 			if (tmp && tmp->color == RED) { */
				/* 				// case 1 : if the right child is RED */
				/* 				tmp->color = BLACK; */
				/* 				current->parent->color = RED; */
				/* 				leftRotate(current->parent); */
				/* 				tmp = current->parent->right; */
				/* 			} */
				/* 			if (tmp && tmp->left->color == BLACK && tmp->right->color == BLACK) { */
				/* 				// case 2 : if the color of both the right and the leftChild is BLACK */
				/* 				tmp->color = RED; */
				/* 				current = current->parent; */
				/* 			} else { */
				/* 				if (tmp->right->color == BLACK) { */
				/* 					// case 3 : if the color of the rightChild is BLACK */
				/* 					tmp->left->color = BLACK; */
				/* 					tmp->color = RED; */
				/* 					rightRotate(tmp); */
				/* 					tmp = current->parent->right; */
				/* 				} */
				/* 				// case 4 :If any of the above cases do not occur */
				/* 				tmp->color = current->parent->color; */
				/* 				current->parent->color = BLACK; */
				/* 				tmp->right->color = BLACK; */
				/* 				leftRotate(current->parent); */
				/* 				current = searchRoot(); */
				/* 			} */
				/* 		} else { */
				/* 			//the same as above with right changed to left and vice versa */ 
				/* 			tmp = current->parent->left; */
				/* 			if (tmp && tmp->color == RED) { */
				/* 				tmp->color = BLACK; */
				/* 				current->parent->color = RED; */
				/* 				rightRotate(current->parent); */
				/* 				tmp = current->parent->left; */
				/* 			} */

				/* 			if (tmp && tmp->right->color == BLACK && tmp->left->color == BLACK) { // */
				/* 				tmp->color = RED; */
				/* 				current = current->parent; */
				/* 			} else { */
				/* 				if (tmp->left->color == BLACK) { */
				/* 					tmp->right->color = BLACK; */
				/* 					tmp->color = RED; */
				/* 					leftRotate(tmp); */
				/* 					tmp = current->parent->left; */
				/* 				} */
				/* 				tmp->color = current->parent->color; */
				/* 				current->parent->color = BLACK; */
				/* 				tmp->left->color = BLACK; */
				/* 				rightRotate(current->parent); */
				/* 				current = searchRoot(); */
				/* 			} */
				/* 		} */
				/* 	} */
				/* 	//	if (!current->parent && (!current->left || !current->right)) */
				/* 	//		deleteFixRoot(current); */
				/* 	current->color = BLACK; */
				/* } */
				/*
				   int	nbNodeLeft(node* current) {
				   int nb = 0;
				   if (!current || !current->left)
				   return 0;
				   while (current && current->left) {
				   current = current->left;
				   nb++;
				   }
				   return nb;
				   }

				   int	nbNodeRight(node* current) {
				   int nb = 0;
				   if (!current || !current->right)
				   return 0;
				   while (current && current->right) {
				   current = current->right;
				   nb++;
				   }
				   return nb;
				   }*/

				void	deleteFixRoot(node   *current) {
					if (!current->left)
						leftRotate(current);
					else if (!current->right)
						rightRotate(current);
				}

				void	clearTree(node	*current) {
					std::cout << GRN "ClearTree Function" NC << std::endl;
					node	*tmp = current;
					if (!tmp)
						return ;
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
					while (tmp && tmp->parent)
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
				//if node and parent are red end the uncle is red as well then we push the blachness down form the grandparent
				//children of red child are black
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
					//printTree();
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
					//printTree();
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
									std::cout << "here tmp = " << current->right->value.first << current->right << std::endl;
									break;
								}
								current = current->right;
							}
							else {
								if (!current->left) {
									current->left = newNode(value,current);
									insertFix(current->left);
									std::cout << "here tmp = " << current->left->value.first << current->left << std::endl;
									break;
								}
								current = current->left;
							}
						}
					}
				}
		};

	/*NON MEMBER FUNCTIONS */
	template <class Key, class T, class Compare, class Alloc>
		bool operator==(map<Key,T,Compare,Alloc> const &lhs, map<Key,T,Compare,Alloc> const &rhs) {
			if (lhs.size() != rhs.size())
				return false;
			return equal(lhs.begin(), lhs.end(), rhs.begin());
		}
	template <class Key, class T, class Compare, class Alloc>
		bool operator!=(map<Key,T,Compare,Alloc> const &lhs, map<Key,T,Compare,Alloc> const &rhs) {return !(lhs == rhs);}
	template <class Key, class T, class Compare, class Alloc>
		bool operator<(map<Key,T,Compare,Alloc> const &lhs, map<Key,T,Compare,Alloc> const &rhs) { 
			return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}
	template <class Key, class T, class Compare, class Alloc>
		bool operator<=(map<Key,T,Compare,Alloc> const &lhs, map<Key,T,Compare,Alloc> const &rhs) {return lhs < rhs || lhs == rhs;}
	template <class Key, class T, class Compare, class Alloc>
		bool operator>(map<Key,T,Compare,Alloc> const &lhs, map<Key,T,Compare,Alloc> const &rhs) {return rhs < lhs;}
	template <class Key, class T, class Compare, class Alloc>
		bool operator>=(map<Key,T,Compare,Alloc> const &lhs, map<Key,T,Compare,Alloc> const &rhs) {return lhs > rhs || lhs == rhs;}

	template <class Key, class T, class Compare, class Alloc>
		void	swap(map<Key,T,Compare,Alloc> const &lhs, map<Key,T,Compare,Alloc>const &rhs) {lhs.swap(rhs);}
}

#endif
