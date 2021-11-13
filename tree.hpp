#ifndef TREE_HPP
#define TREE_HPP

namespace	ft {
	template<typename T>
		class	node {
			public:
				V content;
				node*	parent;
				node*	left;
				node*	right;
				int color;

				node(void) : parent(NULL), left(NULL), right(NULL) {}
				node(node const &src) : parent(src.parent), left(src.left), right(src.right) {}
				~node(void) {}

				node	&operator=(node const &rhs) {
					parent = rhs.parent;
					left = rhs.left;
					right = rhs.right;
					return *this;
				}

				node	*getParent(node* N) {
					return (N == NULL ? NULL : N->parent);
				}

				node	*getGrandParent(node* N) {
					return getParent(getParent(N));
				}

				node	*getSibling(node* N) {
					node* P = getParent(N);
					if (P->right == this)
						return P->left;
					else 
						return P->right;
				}

				node	*getUncle(node* N) {
					node* P = getParent(N);
					return getSibling(P);
				}
		};
}

#endif
