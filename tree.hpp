#ifndef TREE_HPP
#define TREE_HPP

#include <stdio.h>
/* #include "tree/tree.h" */

typedef struct s_tree_display {
	int		block_width;
	int		block_delta;
	int		label_width;
	int		label_delta;
	int		lwidth;
	int		lpos;
	int		rwidth;
	int		rpos;
	int		trunc;
	int		depth;
	int		pos;
}	t_tree_display;


#define P_PAD " "
#define PAD " "

#define P_TRUNC "…"
#define TRUNC "+"

#define P_PREFIX "\033[33m☾\033[34m"
#define PREFIX "["

#define P_SUFFIX "\033[33m☽\033[0m"
#define SUFFIX "]"

#define P_JUNCTION "━"
#define JUNCTION "-"

#define P_JUNCTION_LOW_L "\033[35m╭"
#define JUNCTION_LOW_L "/"

#define P_JUNCTION_HIG_L "╯\033[0m"
#define JUNCTION_HIG_L "'"

#define P_JUNCTION_LOW_R "╮\033[0m"
#define JUNCTION_LOW_R "\\"

#define P_JUNCTION_HIG_R "\033[35m╰"
#define JUNCTION_HIG_R "`"

typedef struct s_print_style{
	char	*word;
	int		len;
}				t_print_style;

typedef enum e_style_match {
	E_PAD,
	E_TRUNC,
	E_PREFIX,
	E_SUFFIX,
	E_JUNCTION,
	E_JUNCTION_LOW_L,
	E_JUNCTION_LOW_R,
	E_JUNCTION_HIG_L,
	E_JUNCTION_HIG_R,
}	t_style_match;

typedef struct s_buf {
	char	*str;
	char	*s;
	int		capacity;
	int		pretty;
}	t_buf;

static const t_print_style	g_pretty_style[] = {
	[E_PAD] = {P_PAD, sizeof(P_PAD) - 1},
	[E_TRUNC] = {P_TRUNC, sizeof(P_TRUNC) - 1},
	[E_PREFIX] = {P_PREFIX, sizeof(P_PREFIX) - 1},
	[E_SUFFIX] = {P_SUFFIX, sizeof(P_SUFFIX) - 1},
	[E_JUNCTION] = {P_JUNCTION, sizeof(P_JUNCTION) - 1},
	[E_JUNCTION_LOW_L] = {P_JUNCTION_LOW_L, sizeof(P_JUNCTION_LOW_L) - 1},
	[E_JUNCTION_LOW_R] = {P_JUNCTION_LOW_R, sizeof(P_JUNCTION_LOW_R) - 1},
	[E_JUNCTION_HIG_L] = {P_JUNCTION_HIG_L, sizeof(P_JUNCTION_HIG_L) - 1},
	[E_JUNCTION_HIG_R] = {P_JUNCTION_HIG_R, sizeof(P_JUNCTION_HIG_R) - 1},
};

static const t_print_style	g_basic_style[] = {
	[E_PAD] = {PAD, 1},
	[E_TRUNC] = {TRUNC, 1},
	[E_PREFIX] = {PREFIX, 1},
	[E_SUFFIX] = {SUFFIX, 1},
	[E_JUNCTION] = {JUNCTION, 1},
	[E_JUNCTION_LOW_L] = {JUNCTION_LOW_L, 1},
	[E_JUNCTION_LOW_R] = {JUNCTION_LOW_R, 1},
	[E_JUNCTION_HIG_L] = {JUNCTION_HIG_L, 1},
	[E_JUNCTION_HIG_R] = {JUNCTION_HIG_R, 1},
};

#include <string.h>
#include <stdlib.h>
int	buffer_append_raw(t_buf *b, const char *src, int len)
{
	const int	cur_len = b->s - b->str;

	if (cur_len + len >= b->capacity)
	{
		b->capacity += 5048;
		b->str = (char *)realloc(b->str, b->capacity);
		if (!b->str)
		{
			b->s = NULL;
			b->capacity = 0;
			return (1);
		}
		b->s = b->str + cur_len;
	}
	memcpy(b->s, src, len);
	b->s += len;
	return (0);
}

int	buffer_append(t_buf *b, t_style_match item)
{
	if (b->pretty)
		return (buffer_append_raw(b, g_pretty_style[item].word,
				g_pretty_style[item].len));
	return (buffer_append_raw(b, g_basic_style[item].word,
			g_basic_style[item].len));
}

int	buffer_trim_to_newline(t_buf *b)
{
	while (b->s > b->str && *(b->s - 1) == ' ')
		b->s--;
	return (buffer_append_raw(b, "\n", 1));
}

int	buffer_append_mul(t_buf *b, t_style_match item, int repeat)
{
	int		ret;

	if (repeat < 0)
		return (0);
	ret = 0;
	while (!ret && repeat--)
		ret = buffer_append(b, item);
	return (ret);
}

int	buffer_connect_leaf(t_buf *b, int is_l, int len, int *cumul)
{
	*cumul += len;
	if (is_l)
		return (buffer_append(b, E_JUNCTION_LOW_L)
			|| buffer_append_mul(b, E_JUNCTION, len - 2)
			|| buffer_append(b, E_JUNCTION_HIG_L)
		);
	return (buffer_append(b, E_JUNCTION_HIG_R)
		|| buffer_append_mul(b, E_JUNCTION, len - 2)
		|| buffer_append(b, E_JUNCTION_LOW_R));
}

namespace	ft {
	template<typename T>
		class	node {
			public:
				T value;
				node*	parent;
				node*	left;
				node*	right;
				t_tree_display	dsp;
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
					if (!P)
						return NULL;
					if (P->right == this)
						return P->left;
					else 
						return P->right;
				}

				node	*getUncle(node* N) {
					node* P = getParent(N);
					return getSibling(P);
				}

				void printTree() {
					_print_tree(this, 1, 1);
				}













#define MAX_WORD_WIDTH 20
#define WORD_ADDED_WIDTH 2

static int	print_connect(node *tree, t_buf *b, int *printed)
{
	int		print;
	int		ret;
	int		tmp;

	if (!tree->left)
		print = tree->dsp.pos - 1;
	else
		print = tree->left->dsp.pos + tree->left->dsp.block_delta - 1;
	ret = buffer_append_mul(b, E_PAD, print);
	if (ret || !tree->left)
		tmp = tree->dsp.lwidth;
	else
	{
		ret = buffer_connect_leaf(b, 1, tree->dsp.pos - print, &print);
		tmp = tree->left->dsp.block_width + tree->left->dsp.block_delta;
	}
	if (!ret && tree->right)
	{
		tmp = tree->right->dsp.pos + tree->right->dsp.block_delta + tmp
			- tree->dsp.pos + !tree->left;
		ret = buffer_connect_leaf(b, 0, tmp, &print);
	}
	*printed += print;
	tree->dsp.depth = 0;
	return (ret);
}

#include<string>

static int	print_label(node *tree, t_buf *b, int *printed)
{
	int			ret;

	ret = buffer_append_mul(b, E_PAD, tree->dsp.label_delta)
		|| buffer_append(b, E_PREFIX)
		|| buffer_append_raw(b, tree->color == 1 ? "\033[31m" : "\033[34m", sizeof("\033[31m") - 1)
		|| buffer_append_raw(b, (tree->value.first + ":" + std::to_string(tree->value.second))  .c_str(),//"TOTO",
			tree->dsp.label_width - WORD_ADDED_WIDTH - tree->dsp.trunc)
		;
	dprintf(2, " [%s] %d \n", (tree->value.first + ":" + std::to_string(tree->value.second))  .c_str(),
			tree->dsp.label_width - WORD_ADDED_WIDTH - tree->dsp.trunc);
	dprintf(2, "second: %d\n", tree->value.second);
	dprintf(2, "second str: %s\n", std::to_string(tree->value.second).c_str());
	if (!ret && tree->dsp.trunc)
		ret = buffer_append(b, E_TRUNC);
	if (!ret)
		ret = buffer_append(b, E_SUFFIX);
	*printed += tree->dsp.label_width + tree->dsp.label_delta;
	tree->dsp.depth = 2;
	return (ret);
}

static int	layer_print_specific(node *tree, t_buf *b, int (*layer_fn)(node *tree, t_buf *b, int *printed),
		int *ret)
{
	int		print;

	if (*ret)
		return (0);
	print = tree->dsp.block_delta;
	*ret = buffer_append_mul(b, E_PAD, tree->dsp.block_delta);
	if (!*ret && tree->dsp.depth == 0)
	{
		if (tree->left)
			print += layer_print_specific(tree->left, b, layer_fn, ret);
		else
		{
			print += tree->dsp.lwidth;
			*ret = buffer_append_mul(b, E_PAD, tree->dsp.lwidth);
		}
		if (!*ret && tree->right)
			print += layer_print_specific(tree->right, b, layer_fn, ret);
	}
	else if (!*ret)
		*ret = layer_fn(tree, b, &print);
	if (!*ret)
		*ret = buffer_append_mul(b, E_PAD,
				tree->dsp.block_width + tree->dsp.block_delta - print);
	return (tree->dsp.block_width + tree->dsp.block_delta);
}

static int	layer_print_tree(node *tree, int max_depth, int fd, int pretty)
{
	t_buf	b;
	int		ret;

	ret = 0;
	bzero(&b, sizeof(t_buf));
	b.pretty = pretty;
	while (!ret && max_depth >= 0)
	{
		layer_print_specific(tree, &b, print_label, &ret);
		if (!ret)
			ret = buffer_trim_to_newline(&b);
		if (max_depth--)
		{
			if (!ret)
				layer_print_specific(tree, &b, print_connect, &ret);
			if (!ret)
				ret = buffer_trim_to_newline(&b);
		}
	}
	if (!ret)
		ret = buffer_append_raw(&b, "\0", 1);
	if (!ret)
		dprintf(fd, "%s", b.str);
	free(b.str);
	return (ret);
}

int	_print_tree(node *tree, int pretty, int fd)
{
	t_tree_display	first;
	int				ret;

	if (!tree)
	{
		if (pretty)
			dprintf(fd, "\033[31mCannot print a NULL tree\033[0m\n");
		else
			dprintf(fd, "Cannot print a NULL tree\n");
		return (0);
	}
	bzero(&first, sizeof(t_tree_display));
	ret = layer_print_tree(tree, _calc_depth(tree, 0, &first), fd, pretty);
	if (ret)
	{
		if (pretty)
			dprintf(fd, "\033[31mMemory error while printing tree\033[0m\n");
		else
			dprintf(fd, "Memory error while printing tree");
	}
	return (ret);
}






static int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static void	label_adjust(t_tree_display *me)
{
	me->label_delta = me->pos - me->label_width / 2 - 1;
	if (me->label_delta < 0)
	{
		me->pos -= me->label_delta;
		me->label_delta = 0;
	}
}

static void	pos_calc(t_tree_display *me, t_tree_display *l, t_tree_display *r,
		int leaf[])
{
	const int	lpos = l->block_delta
		+ max(l->pos + 1, l->pos + (l->label_width - me->label_width) / 2);
	const int	rpos = l->block_width + l->block_delta + r->block_delta
		+ min(r->pos - 1, r->pos + (r->label_width - me->label_width) / 2);

	me->block_width = max(l->block_width + r->block_width + 1, me->label_width);
	if (leaf[0] && leaf[1])
		me->pos = (lpos + rpos) / 2;
	else if (leaf[0])
	{
		me->pos = lpos;
		if (me->lwidth > me->label_width)
			--me->block_width;
		me->rwidth = me->block_width - me->lwidth;
	}
	else if (leaf[1])
	{
		me->pos = rpos;
		if (me->rwidth > me->label_width)
			--me->block_width;
		me->lwidth = me->block_width - me->rwidth;
	}
	else
		me->pos = me->block_width / 2 + 1;
}

static void	delta_adjust(node *tree, t_tree_display *dsp[3], int leaf[2])
{
	const int	delta = dsp[0]->label_width
		- (dsp[1]->block_width + dsp[2]->block_width + 1);

	if (delta > 0)
	{
		if (leaf[0] && leaf[1])
		{
			dsp[2]->block_delta = (delta + 1) / 2;
			tree->right->dsp.block_delta = dsp[2]->block_delta;
			dsp[1]->block_delta = delta - dsp[2]->block_delta;
			tree->left->dsp.block_delta = dsp[1]->block_delta;
		}
	}
	else if (leaf[0] && leaf[1])
		tree->right->dsp.block_delta = 1;
}

static void	init_calc(node *tree, t_tree_display *me, t_tree_display *l,
		t_tree_display *r)
{
	bzero(l, sizeof(t_tree_display));
	bzero(r, sizeof(t_tree_display));
	me->depth = 1;
		me->label_width = tree->value.first.size() + //strlen(value.size()"TOTO");
	
	std::to_string(tree->value.second).size() + 1;
	if (me->label_width > MAX_WORD_WIDTH)
		me->trunc = 1;
	me->label_width = min(me->label_width, MAX_WORD_WIDTH) + WORD_ADDED_WIDTH;
}

int	_calc_depth(node *tree, int depth, t_tree_display *me)
{
	t_tree_display	l;
	t_tree_display	r;
	int				leaf[2];

	if (!tree)
		return (0);
	init_calc(tree, me, &l, &r);
	leaf[0] = _calc_depth(tree->left, depth + 1, &l);
	leaf[1] = _calc_depth(tree->right, depth + 1, &r);
	delta_adjust(tree, (t_tree_display *[]){me, &l, &r}, leaf);
	me->lwidth = l.block_width;
	me->rwidth = r.block_width;
	pos_calc(me, &l, &r, leaf);
	label_adjust(me);
	tree->dsp = *me;
	return (max(depth, max(leaf[0], leaf[1])));
}













		};
}

#endif
