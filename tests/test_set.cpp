# include <set>
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <list>
#include <string>
#include "set.hpp"

#ifndef NAMESPACE
# define NAMESPACE ft
#endif

#define NC "\e[0m"
#define REDC "\e[0;31m"
#define GRN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define PINK "\e[0;35m"
#define CYN "\e[0;36m"

	template <typename T>
static void	printSize(T const &mp, bool print_content = 1)
{
	(void)print_content;
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << std::endl;
}

static bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
	bool operator() (const int& lhs, const int& rhs) const
	{return lhs<rhs;}
};

static void	constructor() {
	std::cout << CYN << __func__ << NC << std::endl;
	NAMESPACE::set<int> first;                           // empty set of ints

	int myints[]= {10,20,30,40,50};
	NAMESPACE::set<int> second (myints,myints+5);        // range
	printSize(second);
	NAMESPACE::set<int> third (second);                  // a copy of second
	printSize(third);

	NAMESPACE::set<int> fourth (second.begin(), second.end());  // iterator ctor.
	printSize(fourth);

	NAMESPACE::set<int,classcomp> fifth;                 // class as Compare
	printSize(fifth);

	bool(*fn_pt)(int,int) = fncomp;
	NAMESPACE::set<int,bool(*)(int,int)> sixth (fn_pt);  // function pointer as Compare
	printSize(sixth);
}

static void	begin() {
	std::cout << CYN << __func__ << NC << std::endl;
	int myints[] = {75,23,65,42,13};
	NAMESPACE::set<int> myset (myints,myints+5);

	std::cout << "myset contains:";
	for (NAMESPACE::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

static void	clear() {
	std::cout << CYN << __func__ << NC << std::endl;
	NAMESPACE::set<int> myset;

	myset.insert (100);
	myset.insert (200);
	myset.insert (300);

	std::cout << "myset contains:";
	for (NAMESPACE::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	myset.clear();
	myset.insert (1101);
	myset.insert (2202);

	std::cout << "myset contains:";
	for (NAMESPACE::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

static void	count() {
	std::cout << CYN << __func__ << NC << std::endl;
	NAMESPACE::set<int> myset;

	// set some initial values:
	for (int i=1; i<5; ++i) myset.insert(i*3);    // set: 3 6 9 12

	for (int i=0; i<10; ++i)
	{
		std::cout << i;
		if (myset.count(i)!=0)
			std::cout << " is an element of myset.\n";
		else
			std::cout << " is not an element of myset.\n";
	}
}

static void	empty() {
	std::cout << CYN << __func__ << NC << std::endl;
	NAMESPACE::set<int> myset;

	myset.insert(20);
	myset.insert(30);
	myset.insert(10);

	std::cout << "myset contains:";
	while (!myset.empty())
	{
		std::cout << ' ' << *myset.begin();
		myset.erase(myset.begin());
	}
	std::cout << '\n';
}

static void	end() {
	std::cout << CYN << __func__ << NC << std::endl;
	int myints[] = {75,23,65,42,13};
	NAMESPACE::set<int> myset (myints,myints+5);

	std::cout << "myset contains:";
	for (NAMESPACE::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';
}

static void	equal_range() {
	std::cout << CYN << __func__ << NC << std::endl;
	NAMESPACE::set<int> myset;

	for (int i=1; i<=5; i++) myset.insert(i*10);   // myset: 10 20 30 40 50

	NAMESPACE::pair<NAMESPACE::set<int>::const_iterator,NAMESPACE::set<int>::const_iterator> ret;
	ret = myset.equal_range(30);

	std::cout << "the lower bound points to: " << *ret.first << '\n';
	std::cout << "the upper bound points to: " << *ret.second << '\n';
}

static void	erase() {
	std::cout << CYN << __func__ << NC << std::endl;
	NAMESPACE::set<int> myset;
	NAMESPACE::set<int>::iterator it;

	// insert some values:
	for (int i=1; i<10; i++) myset.insert(i*10);  // 10 20 30 40 50 60 70 80 90

	it = myset.begin();
	++it;                                         // "it" points now to 20

	myset.erase (it);

	myset.erase (40);

	it = myset.find (60);
	myset.erase (it, myset.end());

	std::cout << "myset contains:";
	for (it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	//myset contains: 10 30 50
}

static void	find() {
	std::cout << CYN << __func__ << NC << std::endl;
	NAMESPACE::set<int> myset;
	NAMESPACE::set<int>::iterator it;

	// set some initial values:
	for (int i=1; i<=5; i++) myset.insert(i*10);    // set: 10 20 30 40 50

	it=myset.find(20);
	myset.erase (it);
	myset.erase (myset.find(40));

	std::cout << "myset contains:";
	for (it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';	
	//myset contains: 10 30 50
}

static void	get_allocator() {
	std::cout << CYN << __func__ << NC << std::endl;
	NAMESPACE::set<int> myset;
	int * p;
	unsigned int i;

	// allocate an array of 5 elements using myset's allocator:
	p=myset.get_allocator().allocate(5);

	// assign some values to array
	for (i=0; i<5; i++) p[i]=(i+1)*10;

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	myset.get_allocator().deallocate(p,5);
	//The allocated array contains: 10 20 30 40 50
}

static void	insert() {
	std::cout << CYN << __func__ << NC << std::endl;
	NAMESPACE::set<int> myset;
	NAMESPACE::set<int>::iterator it;
	NAMESPACE::pair<NAMESPACE::set<int>::iterator,bool> ret;

	// set some initial values:
	for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50

	ret = myset.insert(20);               // no new element inserted

	if (ret.second==false) it=ret.first;  // "it" now points to element 20

	myset.insert (it,25);                 // max efficiency inserting
	myset.insert (it,24);                 // max efficiency inserting
	myset.insert (it,26);                 // no max efficiency inserting

	int myints[]= {5,10,15};              // 10 already in set, not inserted
	myset.insert (myints,myints+3);

	std::cout << "myset contains:";
	for (it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	//myset contains: 5 10 15 20 24 25 26 30 40 50
}

static void	key_comp() {
	std::cout << CYN << __func__ << NC << std::endl;
	NAMESPACE::set<int> myset;
	int highest;

	NAMESPACE::set<int>::key_compare mycomp = myset.key_comp();

	for (int i=0; i<=5; i++) myset.insert(i);

	std::cout << "myset contains:";

	highest=*myset.rbegin();
	NAMESPACE::set<int>::iterator it=myset.begin();
	do {
		std::cout << ' ' << *it;
	} while ( mycomp(*(++it),highest) );

	std::cout << '\n';
	//myset contains: 0 1 2 3 4
}

static void	lower_bound() {
	std::cout << CYN << __func__ << NC << std::endl;
	NAMESPACE::set<int> myset;
	NAMESPACE::set<int>::iterator itlow,itup;

	for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

	itlow=myset.lower_bound (30);                //       ^
	itup=myset.upper_bound (60);                 //                   ^

	myset.erase(itlow,itup);                     // 10 20 70 80 90

	std::cout << "myset contains:";
	for (NAMESPACE::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	//myset contains: 10 20 70 80 90
}

static void	max_size() {
	std::cout << CYN << __func__ << NC << std::endl;
	int i;
	NAMESPACE::set<int> myset;

	if (myset.max_size()>1000)
	{
		for (i=0; i<1000; i++) myset.insert(i);
		std::cout << "The set contains 1000 elements.\n";
	}
	else std::cout << "The set could not hold 1000 elements.\n";
}

static void	operator_equal() {
	std::cout << CYN << __func__ << NC << std::endl;
	int myints[]={ 12,82,37,64,15 };
	NAMESPACE::set<int> first (myints,myints+5);   // set with 5 ints
	NAMESPACE::set<int> second;                    // empty set

	second = first;                          // now second contains the 5 ints
	first = NAMESPACE::set<int>();                 // and first is empty

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	//Size of first: 0
	//Size of second: 5
}

static void	rbegin() {
	std::cout << CYN << __func__ << NC << std::endl;
	int myints[] = {21,64,17,78,49};
	NAMESPACE::set<int> myset (myints,myints+5);

	NAMESPACE::set<int>::reverse_iterator rit;

	std::cout << "myset contains:";
	for (rit=myset.rbegin(); rit != myset.rend(); ++rit)
		std::cout << ' ' << *rit;

	std::cout << '\n';
	//myset contains: 78 64 49 21 17
}

static void	rend() {
	std::cout << CYN << __func__ << NC << std::endl;
	int myints[] = {21,64,17,78,49};
	NAMESPACE::set<int> myset (myints,myints+5);

	NAMESPACE::set<int>::reverse_iterator rit;

	std::cout << "myset contains:";
	for (rit=myset.rbegin(); rit != myset.rend(); ++rit)
		std::cout << ' ' << *rit;

	std::cout << '\n';
	//myset contains: 78 64 49 21 17
}

static void	size() {
	std::cout << CYN << __func__ << NC << std::endl;
	NAMESPACE::set<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<10; ++i) myints.insert(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert (100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.erase(5);
	std::cout << "3. size: " << myints.size() << '\n';
	//0. size: 0
	//1. size: 10
	//2. size: 11
	//3. size: 10
}

static void	swap() {
	std::cout << CYN << __func__ << NC << std::endl;
	int myints[]={12,75,10,32,20,25};
	NAMESPACE::set<int> first (myints,myints+3);     // 10,12,75
	NAMESPACE::set<int> second (myints+3,myints+6);  // 20,25,32

	first.swap(second);

	std::cout << "first contains:";
	for (NAMESPACE::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "second contains:";
	for (NAMESPACE::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	//first contains: 20 25 32
	//second contains: 10 12 75
}

static void	upper_bound() {
	std::cout << CYN << __func__ << NC << std::endl;
	NAMESPACE::set<int> myset;
	NAMESPACE::set<int>::iterator itlow,itup;

	for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

	itlow=myset.lower_bound (30);                //       ^
	itup=myset.upper_bound (60);                 //                   ^

	myset.erase(itlow,itup);                     // 10 20 70 80 90

	std::cout << "myset contains:";
	for (NAMESPACE::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';	
	//myset contains: 10 20 70 80 90
}

static void	value_comp() {
	std::cout << CYN << __func__ << NC << std::endl;
	NAMESPACE::set<int> myset;
	NAMESPACE::set<int>::value_compare mycomp = myset.value_comp();

	for (int i=0; i<=5; i++) myset.insert(i);

	std::cout << "myset contains:";

	int highest=*myset.rbegin();
	NAMESPACE::set<int>::iterator it=myset.begin();
	do {
		std::cout << ' ' << *it;
	} while ( mycomp(*(++it),highest) );

	std::cout << '\n';
	//myset contains: 0 1 2 3 4
}

static void	relational_operators() {
	std::cout << CYN << __func__ << NC << std::endl;
	NAMESPACE::set<int> foo,bar;
	foo.insert(10);
	bar.insert(20);
	bar.insert(30);
	foo.insert(40);

	printSize(foo);
	printSize(bar);
	// foo ({10,40}) vs bar ({20,30}):
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	//foo and bar are not equal
	//foo is less than bar
	//foo is less than or equal to bar
}

static void	non_member_swap() {
	std::cout << CYN << __func__ << NC << std::endl;
	int myints[]={12,75,10,32,20,25};
	NAMESPACE::set<int> first (myints,myints+3);     // 10,12,75
	NAMESPACE::set<int> second (myints+3,myints+6);  // 20,25,32
	std::cout << "first contains:";
	for (NAMESPACE::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "second contains:";
	for (NAMESPACE::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "SWAP" << std::endl;
	NAMESPACE::swap(first,second);

	std::cout << "first contains:";
	for (NAMESPACE::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "second contains:";
	for (NAMESPACE::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void	test_set() {
	constructor();
	begin();
	clear();
	count();
	empty();
	end();
	equal_range();
	erase();
	find();
	get_allocator();
	insert();
	key_comp();
	lower_bound();
	max_size();
	operator_equal();
	rbegin();
	rend();
	size();
	swap();
	upper_bound();
	value_comp();
	relational_operators();
	non_member_swap();
}
