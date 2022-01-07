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

#define DEBUG // std::cout << REDC << __FILE__ << " " << CYN << __FUNCTION__  << " " << __LINE__ << NC << std::endl;

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
				node*	_end;
				size_type _size;
				key_compare	_comp;

			public:
				/* void printTree() { */
				/* 	if (_root != NULL) _root->printTree(); */
				/* } */
				//default constructor
				explicit	map(const key_compare &comp = key_compare(), allocator_type const &alloc = allocator_type()) :
					_alloc_node(alloc), _root(NULL), _end(NULL), _size(0), _comp(comp) {
						/* std::cout << "map constructeur standard" << std::endl; */
						_end = newNode(value_type(Key(), mapped_type()), NULL);
						_root = _end;
					}
				//range constructor
				template<class InputIterator>
					map(InputIterator first, InputIterator last, key_compare const comp = key_compare(),
							allocator_type const &alloc = allocator_type()) :
						_alloc_node(alloc), _root(NULL), _end(NULL), _size(0), _comp(comp) {
							/* std::cout << "map constructeur itererator" << std::endl; */
							_end = newNode(value_type(Key(), mapped_type()), NULL);
							_root = _end;
							insert(first, last); 
						} //
				map(map const & src) : _alloc_node(src._alloc_node), _root(NULL), _end(NULL), _size(0), _comp(src._comp) {
					/* std::cout << REDC "map copy constructeur" NC << std::endl; */
					*this = src; 
				}
				~map(void) {  
					/* std::cout << "Destructeur" << std::endl; */
					if (_root) {
						clear();
						_alloc_node.destroy(_end);
						_alloc_node.deallocate(_end, 1);

					} 
				}  //

				//https://en.cppreference.com/w/cpp/container/map/insert
				pair<iterator, bool>	insert(value_type const &value) {
					/* std::cout << GRN "InsertPair Function" NC << std::endl; */
					size_type oldSize = _size;
					return ft::make_pair<iterator, bool>(insert(0, value), _size != oldSize);
				}

				iterator	insert(iterator pos, value_type const &value) {
					/* std::cout << GRN "InsertIterator Function" NC << std::endl; */
					(void)pos;
					insertNode(value);
					node	*tmp = searchKey(value.first, _root);
					return iterator(tmp);
				}

				template<class InputIterator>
					void	insert(InputIterator first, InputIterator last) {
						/* std::cout << GRN "Insert several Iterators Function" NC << std::endl; */
						while (first != last) {
							insert(*first);
							first++;
						}
					}	

				map	&operator=(map const &rhs) {
					clear();
					_comp = rhs._comp;
					const_iterator it = rhs.begin();
					while (it != rhs.end()) {
						insert(*it);
						it++;
					}
					return *this;
				}

				allocator_type	get_allocator(void) const {
					return _alloc_node;
				}

				//https://en.cppreference.com/w/cpp/container/map/operator_at

				mapped_type	&operator[](key_type const &key) {
					node	*tmp = searchKey(key, _root);
					if (tmp){
						return tmp->value.second;
					}
					insert(value_type(key, mapped_type()));
					return searchKey(key, _root)->value.second;
				}

				iterator	begin(void) {
					if (_size == 1)
						return iterator(_root);
					node *first = _root;
					while (first && first->left)
						first = first->left;
					return iterator(first);
				}

				const_iterator	begin(void) const {
					if (_size == 1)
						return const_iterator(_root);
					node *first = _root;
					while (first && first->left)
						first = first->left;
					return const_iterator(first);
				}

				reverse_iterator	rbegin(void) {
					if (_size == 1)
						return reverse_iterator(_root);
					return reverse_iterator(--end());
				}

				const_reverse_iterator	rbegin(void) const {
					if (_size == 1)
						return iterator(_root);
					return const_reverse_iterator(--end());
				}

				reverse_iterator	rend(void) {
					return reverse_iterator(--begin());
				}

				const_reverse_iterator	rend(void) const {
					return const_reverse_iterator(--begin());
				}

				iterator	end(void) {
					/* std::cout << YELLOW "End Function" NC << std::endl; */
					if (_size == 1)
						return iterator(_root);
					node *last = _root;
					while (last && last->right)
						last = last->right;
					return iterator(last);
				}

				const_iterator	end(void) const {
					/* std::cout << YELLOW "End const Function" NC << std::endl; */
					if (_size == 1)
						return const_iterator(_root);
					node *last = _root;
					while (last && last->right)
						last = last->right;
					return const_iterator(last);
				}

				bool	empty(void) const {
					return (_size == 1 ? true : false);
				}

				size_type	size(void) const {
					return _size - 1;
				}

				size_type	max_size(void) const {
					return _alloc_node.max_size();
				}

				void	clear(void) {
					clearTree(_root);
					DEBUG;
					_end->parent = NULL;
					_end->left = NULL;
					_root = _end;
					_size = 1;	
				}

				void	erase(iterator position) {
					/* std::cout << PINK "ERASE IT Function" NC << std::endl; */
					deleteNode(position.getNode());
				}

				void	erase(iterator first, iterator last) {
					/* std::cout << PINK "ERASE 2 IT Function" NC << std::endl; */
					iterator tmp;
					while (first != last) {
						tmp = first;
						tmp++;
						erase(first);
						first = tmp;
					}
				}

				size_type	erase(const key_type	&k) {
					/* std::cout << PINK "ERASE Function" NC << std::endl; */
					size_type	initSize = this->size();
					deleteNode(searchKey(k, _root));
					return initSize - this->size();
				}

				void	swap(map &x) {

					node_allocator	tmp_node_alloc = x._alloc_node;
					allocator_type	tmp_alloc = x._allocator;
					node*	tmp_node = x._root;
					node*	tmp_end_node = x._end;
					size_type tmp_size = x._size;
					key_compare	tmp_comp = x._comp;

					x._alloc_node = _alloc_node;
					x._allocator = _allocator;
					x._root = _root;
					x._size = _size;
					x._comp = _comp;
					x._end = _end;

					_alloc_node = tmp_node_alloc;
					_allocator = tmp_alloc;
					_root = tmp_node;
					_size = tmp_size;
					_comp = tmp_comp;
					_end = tmp_end_node;
				}

				key_compare	key_comp(void) const {
					return this->_comp;
				}

				value_compare	value_comp(void) const {
					return value_compare(this->_comp);
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
					/* std::cout << PINK "upper bound Function" NC << std::endl; */
					iterator it = begin();
					while (it != end()) {
						if (it->first != k && !_comp(it->first, k))
							return it;
						it++;
					}
					return end();

				}

				const_iterator	upper_bound(const key_type &k) const {
					const_iterator it = begin();
					while (it != end()) {
						if (it->first != k && !_comp(it->first, k))
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

				void	deleteRoot(node *tmp) {
					if (!tmp->right && !tmp->left)
						_root = NULL; 
					else if (!tmp->right && tmp->left) {
						_root = tmp->left;
						tmp->left->parent = tmp->parent;
						deleteFix(tmp, tmp->left, tmp->left, tmp);
					}
					else if (tmp->right && !tmp->left) {
						_root = tmp->right;
						tmp->right->parent = tmp->parent;
						deleteFix(tmp, tmp->right, tmp->right, tmp);
					}
					else {
						node	*next = findNextNode(tmp);
						_root = next;
						node	*parentN;
						if (next->parent != tmp)
							parentN = next->parent;
						else 
							parentN = NULL;
						node	*childR = next->right;
						next->left = tmp->left;
						if (next->left) {
							//if tmp->left != NULL tmp->left take tmp
							next->left->parent = next; //
						}
						if (next->right && next->parent != tmp) {
							next->right->parent = next->parent;
							next->parent->left = next->right;
						}
						else
							next->parent->left = NULL;
						if (tmp->right != next) {
							next->right = tmp->right;
							tmp->right->parent = next;
						}
						next->parent = tmp->parent;
						deleteFix(tmp, next, childR, parentN);
					}
					_alloc_node.destroy(tmp);
					_alloc_node.deallocate(tmp, 1);
					_size--;
				}

				void 	deleteNode(node *tmp) {
					/* std::cout << REDC "Delete Function :" << NC << std::endl; */
					if (!tmp)
						return;
					if (tmp == _root) {
						deleteRoot(tmp);
						return ;
					}
					node	**childOf = tmp->parent->right == tmp ? &tmp->parent->right : &tmp->parent->left;
					// if right childof = tmp right else childt
					// if tmp has no children -> tmp became null
					if (!tmp->right && !tmp->left) {
						*childOf = NULL;
						deleteFix(tmp, NULL, NULL, tmp);
					}
					else if (tmp->right && !tmp->left) {
						//if tmp has only a right child, the child take tmp's place
						*childOf = tmp->right;
						tmp->right->parent = tmp->parent;
						deleteFix(tmp, tmp->right, tmp->right, tmp);
					}
					else if (!tmp->right && tmp->left) {
						//if tmp has only a left child, the child take tmp's place
						*childOf = tmp->left;
						tmp->left->parent = tmp->parent;
						deleteFix(tmp, tmp->left, tmp->left, tmp);
					}
					else {
						//if tmp has both children the 
						node	*next = findNextNode(tmp);
						*childOf = next;
						node	*childR = next->right;
						node	*parent = next->parent;
						//next cannot have left children as it has to be the most lefty to be the closest to tmp
						next->left = tmp->left;
						if (next->left) {
							//if tmp->left != NULL tmp->left take tmp
							next->left->parent = next; //
						}
						if (next->right && next->parent != tmp) {
							next->right->parent = next->parent;
							next->parent->left = next->right;
						}
						if (tmp->right != next) {
							next->right = tmp->right;
							tmp->right->parent = next;
						}
						next->parent = tmp->parent;
						deleteFix(tmp, next, childR, parent);
					}
					_alloc_node.destroy(tmp);
					_alloc_node.deallocate(tmp, 1);
					_size--;
				}

				void	fixCases(node *x, node *w) {
					/* std::cout << REDC "Delete FIX CASES Function :" << NC << std::endl; */
					if (x && x->color == RED) { // case 0
						x->color = BLACK;
						return ;
					}
					if ((!x || x->color == BLACK) && w && w->color == RED) { // case 1
						w->color = BLACK;
						w->parent->color = RED;
						if (w == w->parent->right) {
							leftRotate(w->parent);
							w = w->parent->right;
						}
						else {
							rightRotate(w->parent);
							w = w->parent->left;
						}
					}
					if ((!x || x->color == BLACK) && (w && w->color == BLACK
								&& (!w->left || w->left->color == BLACK)
								&& (!w->right || w->right->color == BLACK))) { // case 2
						if (w)
							w->color = RED;
						if (x)
							x = x->parent;
						if (x && x->color == RED)
							x->color = BLACK;
						else if ((x && x->color == BLACK) || !x) {
							fixCases(x, w);
						}
						else if ((!x || x->color == BLACK) && !x->parent)
							return ;
					}
					if ((!x || x->color == BLACK) && (!w || w->color == BLACK)) {
						if ((!x || (x && x == x->parent->left)) && w && w == w->parent->right 
								&& w->left && w->left->color == RED
								&& (!w->right || w->right->color == BLACK)) { // case 3
							w->left->color = BLACK;
							w->color = RED;
							rightRotate(w);
							w = w->parent->right;
						}
						else if ((!x || x == x->parent->right) && w && w == w->parent->left
								&& w->right && w->right->color == RED
								&& (!w->left || w->left->color == BLACK)) {
							w->right->color = BLACK;
							w->color = RED;
							leftRotate(w);
							w = w->parent->left;
						}

						if ((!x || x == x->parent->left) && w && w->right && w->right->color == RED) { // case 4
							w->color = w->parent->color;
							w->parent->color = BLACK;
							w->right->color = BLACK;
							leftRotate(w->parent);
						}
						else if ((!x || x == x->parent->right) && w && w->left && w->left->color == RED) { 
							w->color = w->parent->color;
							w->parent->color = BLACK;
							w->left->color = BLACK;
							rightRotate(w->parent);
						}
					}
				}

				void	deleteFix(node* delNode, node* nextNode, node* x, node* xP) {
					/* std::cout << REDC "Delete FIX Function :" << x << std::endl; */
					if (delNode->color == RED && (!nextNode || nextNode->color == RED)) {
						/* printTree(); */
						return ;
					}
					else if (delNode->color == RED && nextNode->color == BLACK) { 
						nextNode->color = RED;
					}
					else if (delNode->color == BLACK && nextNode && nextNode->color == RED) {
						nextNode->color = BLACK;
						/* printTree(); */
						return ;
					}
					else if (delNode->color == BLACK && (!nextNode || nextNode->color == BLACK)
							&& x && x->parent)
						;
					else if (delNode->color == BLACK && (!nextNode || nextNode->color == BLACK)
							&& searchRoot() == x) {
						/* printTree(); */
						return ;
					}
					node	*w;
					if (xP == NULL)
						w = NULL;
					else	
						w = x->getSibling(xP);
					fixCases(x, w);
					/* printTree(); */

				}

				void	clearTree(node	*current) {
					/* std::cout << GRN "ClearTree Function" NC << std::endl; */
					DEBUG;
					node	*tmp = current;
					if (!tmp)
						return ;
					if (tmp->left)
						clearTree(tmp->left);
					if (tmp->right)
						clearTree(tmp->right);
					if (tmp != _end) {
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

				node	*searchKey(key_type	const &key, node	*current) const {
					/* std::cout << GRN "SearchKey Function" NC << std::endl; */
					if (!current) {
						return NULL;
					}
					if (current == _end && !current->left) {
						return NULL;
					}
					if (current == _end || _comp(key, current->value.first) == true) { // if key < first -> go left
						return searchKey(key, current->left);
					}
					else if (_comp(current->value.first, key) == true) { // if first < key -> go right
						return searchKey(key, current->right);
					}
					return current;
				}

				node	*newNode(value_type	const &value, node *parent) {
					/* std::cout << GRN "Newnode Function" NC << std::endl; */
					node *tmp = _alloc_node.allocate(1);
					_alloc_node.construct(tmp, node());
					_allocator.construct(&tmp->value, value);
					tmp->parent = parent;
					tmp->left = NULL;
					tmp->right = NULL;
					_size++;
					tmp->color = RED;
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
					/* std::cout << GRN "InsertNode Function" NC << " " << value.first << std::endl; */
					if (!_root) {
						_root = newNode(value, NULL);
					}
					else {
						node *current = _root;
						while (current) {
							DEBUG;
							if (current == _end)
								DEBUG;
							if (current != _end && value.first == current->value.first) {
								DEBUG;
								break ;
							}
							if (value > current->value && current != _end) {
								if (!current->right && value.first != current->value.first) {
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
					DEBUG;
				}
		};

	/*NON MEMBER FUNCTIONS */
	template <class Key, class T, class Compare, class Alloc>
		bool operator==(ft::map<Key,T,Compare,Alloc> const &lhs, ft::map<Key,T,Compare,Alloc> const &rhs) {
			if (lhs.size() != rhs.size())
				return false;
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		}
	template <class Key, class T, class Compare, class Alloc>
		bool operator!=(ft::map<Key,T,Compare,Alloc> const &lhs, ft::map<Key,T,Compare,Alloc> const &rhs) {return !(lhs == rhs);}
	template <class Key, class T, class Compare, class Alloc>
		bool operator<(ft::map<Key,T,Compare,Alloc> const &lhs, ft::map<Key,T,Compare,Alloc> const &rhs) { 
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}
	template <class Key, class T, class Compare, class Alloc>
		bool operator<=(ft::map<Key,T,Compare,Alloc> const &lhs, ft::map<Key,T,Compare,Alloc> const &rhs) {return lhs < rhs || lhs == rhs;}
	template <class Key, class T, class Compare, class Alloc>
		bool operator>(ft::map<Key,T,Compare,Alloc> const &lhs, ft::map<Key,T,Compare,Alloc> const &rhs) {return rhs < lhs;}
	template <class Key, class T, class Compare, class Alloc>
		bool operator>=(ft::map<Key,T,Compare,Alloc> const &lhs, ft::map<Key,T,Compare,Alloc> const &rhs) {return lhs > rhs || lhs == rhs;}

	template <class Key, class T, class Compare, class Alloc>
		void	swap(ft::map<Key,T,Compare,Alloc> &lhs, ft::map<Key,T,Compare,Alloc> &rhs) {
			lhs.swap(rhs);
			return ;
		}
}

#endif
