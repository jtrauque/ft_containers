#ifndef MAP_HPP
#define MAP_HPP

#include "map_utils.hpp"
#include "map_iterator.hpp"

#define 1 RED
#define 0 BLACK

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
				typedef	map_iterator<value_type> iterator;
				typedef	map_iterator_const<value_type> const_iterator;
				typedef	typename	ft::reverse_iterator<iterator> reverse_iterator;
				typedef	typename	ft::reverse_iterator<const_iterator> const_reverse_iterator;
				typedef typename allocator_type::template rebind<node>::other node_allocator; 
				typedef	node<value_type> node;

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

			protected:
				node_allocator	_alloc_node;
				node*	_root;
				size_type _size;
				key_compare	_comp;

			public:
				//default constructor
				explicit	map(key_compare &comp = key_compare(), allocator_type const &alloc = allocator_type()) :
					_alloc_node(alloc), _root(NULL), _size(0), _comp(comp) {}
				//range constructor
				template<class InputIterator>
					map(InputIterator first, InputIterator last, key_compare const comp = key_compare(),
							allocator_type const &alloc = allocator_type()) :
						_alloc_node(alloc), _root(NULL), _sie(0), _comp(comp) { insert(first, last); } //
				map(map const & src) : _alloc_node(src._alloc_node), _root(NULL), _size(0), _comp(src._comp) { *this = src; }
				~map(void) { clearNode(_root); }  //

				//https://en.cppreference.com/w/cpp/container/map/insert
				pair<iterator, bool>	insert(value_type const &value) {

				}

				iterator	insert(iterator pos, value_type const &value) {
				}

				template<class InputIterator>
					void	insert(iterator pos, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
							InputIterator last) {
					}

			protected:

				node	*newNode(value_type	&value, node *parent) {
					node *newNode = _alloc_node.allocate(1);
					/* _alloc_node.construct(newNode, node(value, NULL, NULL, parent, false)); */
					_alloc_node.construct(newNode, value);
					newNode->parent = parent;
					newNode->left = NULL;
					newNode->right = NULL;
					_size++;
					newNode.color = RED;
					return newNode;
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


				clearNode(node *node);
		};
}

#endif
