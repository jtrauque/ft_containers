#include "stack.hpp"
#include "vector.hpp"
#include <stack>
#include <vector>
#include <iostream>
#include <string>

#ifndef NAMESPACE
# define NAMESPACE ft
#endif

#define NC "\e[0m"
#define REDC "\e[0;31m"
#define GRN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define PINK "\e[0;35m"

static void constructor() {
	std::cout << BLUE << __func__ << NC << std::endl;
	std::vector<int> myvector (2,200);        // vector with 2 elements

	NAMESPACE::stack<int> first;                    // empty stack
	NAMESPACE::stack<int,std::vector<int> > second (myvector);

	NAMESPACE::stack<int,std::vector<int> > third;  // empty stack using vector

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
}

static void	empty() {
	std::cout << BLUE << __func__ << NC << std::endl;
	NAMESPACE::stack<int> mystack;
	int sum (0);

	for (int i=1;i<=10;i++) mystack.push(i);

	while (!mystack.empty()) {
		sum += mystack.top();
		mystack.pop();
	}

	std::cout << "total: " << sum << '\n';
	//total: 55
}

static void	push_and_pop() {
	std::cout << BLUE << __func__ << NC << std::endl;
	NAMESPACE::stack<int> mystack;

	for (int i=0; i<5; ++i) mystack.push(i);

	std::cout << "Popping out elements...";
	while (!mystack.empty()) {
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';
	//Popping out elements... 4 3 2 1 0
}

static void	size() {
	std::cout << BLUE << __func__ << NC << std::endl;
	NAMESPACE::stack<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';
	//0. size: 0
	//1. size: 5
	//2. size: 4
}

static void	top() {
	std::cout << BLUE << __func__ << NC << std::endl;
	NAMESPACE::stack<int> mystack;

	mystack.push(10);
	mystack.push(20);

	mystack.top() -= 5;

	std::cout << "mystack.top() is now " << mystack.top() << '\n';
}

void		test_stack(void) {
	constructor();
	empty();
	push_and_pop();
	size();
	top();
}
