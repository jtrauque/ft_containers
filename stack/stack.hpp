#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

//https://en.cppreference.com/w/cpp/container/stack

namespace	ft {
	template	<class T, class Container = vector<T> >
		class stack {
			public:
				typedef	T	value_type;
				typedef	Container	container_type;
				typedef	typename container_type::size_type	size_type;

			protected:
				container_type	_container;

			public:
				explicit	stack(container_type const &container = container_type()) : _container(container) {}
				virtual ~stack(void) {}

				value_type	&top(void) { return _container.back(); }
				value_type	const &top(void) const { return _container.back(); }
				bool	empty() const { return _container.empty(); }
				size_type	size(void) const { return _container.size(); }
				void	push(const value_type	&val) { _container.push_back(val); }
				void	pop(void) { _container.pop_back(); }

				//operator non membre
				friend bool operator==(stack<T,Container> const &lhs, stack<T,Container> const &rhs) { return lhs._container == rhs._container; }
				friend bool operator!=(stack<T,Container> const &lhs, stack<T,Container>const &rhs) { return lhs._container != rhs._container; }
				friend bool operator<(stack<T,Container> const &lhs, stack<T,Container>const &rhs) { return lhs._container < rhs._container; }
				friend bool operator<=(stack<T,Container> const &lhs, stack<T,Container> const &rhs) { return lhs._container <= rhs._container; }
				friend bool operator>(stack<T,Container> const &lhs, stack<T,Container> const &rhs) { return lhs._container > rhs._container; }
				friend bool operator>=(stack<T,Container> const &lhs, stack<T,Container>const &rhs) { return lhs._container >= rhs._container; }
				//Compares the contents of the underlying containers of two container adaptors. The comparison is done by applying the corresponding operator to the underlying containers.
				//https://en.cppreference.com/w/cpp/container/stack/operator_cmp
		};
				template	<class U, class Cont>
				bool operator==(stack<U,Cont> const &lhs, stack<U,Cont> const &rhs) { return lhs._container == rhs._container; }
				template	<class U, class Cont>
				bool operator!=(stack<U,Cont> const &lhs, stack<U,Cont> const &rhs) { return lhs._container != rhs._container; }
				template	<class U, class Cont>
				bool operator<(stack<U,Cont> const &lhs, stack<U,Cont> const &rhs) { return lhs._container < rhs._container; }
				template	<class U, class Cont>
				bool operator<=(stack<U,Cont> const &lhs, stack<U,Cont> const &rhs) { return lhs._container <= rhs._container; }
				template	<class U, class Cont>
				bool operator>(stack<U,Cont> const &lhs, stack<U,Cont> const &rhs) { return lhs._container > rhs._container; }
				template	<class U, class Cont>
				bool operator>=(stack<U,Cont> const &lhs, stack<U,Cont> const &rhs) { return lhs._container >= rhs._container; }
}

#endif
