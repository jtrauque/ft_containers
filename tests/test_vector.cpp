
#include <iostream>
#include <cstdlib>
#include <list>

#include <vector>
#include "vector.hpp"

#ifndef NAMESPACE
# define NAMESPACE ft
#endif

#define NC "\e[0m"
#define REDC "\e[0;31m"
#define GRN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define PINK "\e[0;35m"

static void swap_non_member() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> foo (3,100);   // three ints with a value of 100
	NAMESPACE::vector<int> bar (5,200);   // five ints with a value of 200

	NAMESPACE::swap(bar, foo);

	std::cout << "foo contains:";
	for (NAMESPACE::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "bar contains:";
	for (NAMESPACE::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	//foo contains: 200 200 200 200 200 
	//bar contains: 100 100 100 
}

static void relationnal_ope() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> foo (3,100);   // three ints with a value of 100
	NAMESPACE::vector<int> bar (2,200);   // two ints with a value of 200

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

static void get_allocator() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> myvector;
	int * p;
	unsigned int i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	// destroy and deallocate:
	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);
	//The allocated array contains: 0 1 2 3 4
}

static void clear() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';

	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	//myvector contains: 100 200 300
	//myvector contains: 1101 2202
}

static void swap() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> foo (3,100);   // three ints with a value of 100
	NAMESPACE::vector<int> bar (5,200);   // five ints with a value of 200

	/* NAMESPACE::vector<int>::iterator it_foo = foo.begin(); */
	/* NAMESPACE::vector<int>::iterator it_bar = bar.begin(); */

	foo.swap(bar);

	std::cout << "foo contains:";
	for (unsigned i=0; i<foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << '\n';
	//foo contains: 200 200 200 200 200 
	//bar contains: 100 100 100 
}

static void erase() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector.push_back(i);

	// erase the 6th element
	myvector.erase (myvector.begin()+5);

	// erase the first 3 elements:
	myvector.erase (myvector.begin(),myvector.begin()+3);

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	//myvector contains: 4 5 7 8 9 10
}

static void insert() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> myvector (3,100);
	NAMESPACE::vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert ( it , 200 );

	myvector.insert (it,2,300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	NAMESPACE::vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	//myvector contains: 501 502 503 300 300 400 400 200 100 100 100
}

static void pop_back() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	while (!myvector.empty())
	{
		sum+=myvector.back();
		myvector.pop_back();
	}

	std::cout << "The elements of myvector add up to " << sum << '\n';
	//The elements of myvector add up to 600
}

static void push_back() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> myvector;
	for (int i = 0; i < 50; i++)
		myvector.push_back((i) % 3);

	std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
}

static void assign() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> first;
	NAMESPACE::vector<int> second;
	NAMESPACE::vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100

	NAMESPACE::vector<int>::iterator it;
	it=first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';
	//Size of first: 7
	//Size of second: 5
	//Size of third: 3
}

static void back() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> myvector;

	myvector.push_back(10);

	while (myvector.back() != 0) {
		myvector.push_back ( myvector.back() -1 );
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size() ; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	//myvector contains: 10 9 8 7 6 5 4 3 2 1 0
}

static void front() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> myvector;

	myvector.push_back(78);
	myvector.push_back(16);

	// now front equals 78, and back 16

	myvector.front() -= myvector.back();

	std::cout << "myvector.front() is now " << myvector.front() << '\n';
	//myvector.front() is now 62
}

static void at() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> myvector (10);   // 10 zero-initialized ints

	// assign some values:
	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
	std::cout << '\n';
	//myvector contains: 0 1 2 3 4 5 6 7 8 9
}

static void operator_hook() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> myvector (10);   // 10 zero-initialized elements

	NAMESPACE::vector<int>::size_type sz = myvector.size();

	// assign some values:
	for (unsigned i=0; i<sz; i++) myvector[i]=i;

	// reverse vector using operator[]:
	for (unsigned i=0; i<sz/2; i++)
	{
		int temp;
		temp = myvector[sz-1-i];
		myvector[sz-1-i]=myvector[i];
		myvector[i]=temp;
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	//myvector contains: 9 8 7 6 5 4 3 2 1 0

}

static void reserve() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int>::size_type sz;

	NAMESPACE::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		if (sz!=foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	NAMESPACE::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);   // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		if (sz!=bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
	/* making foo grow: */
	/* capacity changed: 1 */
	/* capacity changed: 2 */
	/* capacity changed: 4 */
	/* capacity changed: 8 */
	/* capacity changed: 16 */
	/* capacity changed: 32 */
	/* capacity changed: 64 */
	/* capacity changed: 128 */
	/* making bar grow: */
	/* capacity changed: 100 */
}

static void empty() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> myvector;
	int sum (0);

	for (int i=1;i<=10;i++) myvector.push_back(i);

	while (!myvector.empty()) {
		sum += myvector.back();
		myvector.pop_back();
	}

	std::cout << "total: " << sum << '\n';
	//total: 55
}

static void capacity() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> myvector;

	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);

	std::cout << "size: " << (int) myvector.size() << '\n';
	std::cout << "capacity: " << (int) myvector.capacity() << '\n';
	std::cout << "max_size: " << (int) myvector.max_size() << '\n';
	/* size: 100 */
	/* capacity: 128 */
	/* max_size: 1073741823 */
}

static void resize() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> myvector;

	// set some initial content:
	for (int i=1;i<10;i++) myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);

	std::cout << "myvector contains:";
	for (size_t i=0;i<myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	//myvector contains: 1 2 3 4 5 100 100 100 0 0 0 0
}

static void max_size() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> myvector;

	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);

	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";
	//size: 100
	//capacity: 128
	//max_size: 1073741823
}

static void size() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert (myints.end(),10,100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';
	//0. size: 0
	//1. size: 10
	//2. size: 20
	//3. size: 19
}

static void rend() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> myvector (5);  // 5 default-constructed ints

	NAMESPACE::vector<int>::reverse_iterator rit = myvector.rbegin();

	int i=0;
	for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:";
	for (NAMESPACE::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	//5 4 3 2 1 
}

static void rbegin() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> myvector (5);  // 5 default-constructed ints

	int i=0;

	NAMESPACE::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:";
	for (NAMESPACE::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	//myvector contains: 5 4 3 2 1
}


static void end() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	std::cout << "myvector contains:";
	for (NAMESPACE::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	//myvector contains: 1 2 3 4 5
}

static void begin() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	std::cout << "myvector contains:";
	for (NAMESPACE::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	NAMESPACE::vector<int>::iterator 	it = myvector.begin();
	NAMESPACE::vector<int>::const_iterator 	const_it = myvector.begin();
	if (it == const_it)
		std::cout << "comparaison with comp OK" << std::endl;
	//myvector contains: 1 2 3 4 5
}

static void operator_equal() {
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> foo (3,0);
	NAMESPACE::vector<int> bar (5,0);

	bar = foo;
	foo = NAMESPACE::vector<int>();

	std::cout << "Size of foo: " << int(foo.size()) << '\n';
	std::cout << "Size of bar: " << int(bar.size()) << '\n';
	//Size of foo: 0
	//Size of bar: 3
}


static void constructor() {
	// constructors used in the same order as described above:
	std::cout << GRN << __func__ << NC << std::endl;
	NAMESPACE::vector<int> first;                                // empty vector of ints
	NAMESPACE::vector<int> second (4,100);                       // four ints with value 100
	NAMESPACE::vector<int> third (second.begin(),second.end());  // iterating through second
	NAMESPACE::vector<int> fourth (third);                       // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	NAMESPACE::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are:";
	for (NAMESPACE::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	//The contents of fifth are: 16 2 77 29 
}

void test_vector() {
	constructor();
	operator_equal(); // operator=

	begin();
	end();
	rbegin();
	rend();

	size();
	max_size();
	resize();
	capacity();
	empty();
	reserve();

	operator_hook(); // operator[]
	at();
	front();
	back();

	assign();
	push_back();
	pop_back();
	insert();
	erase();
	swap();
	clear();

	get_allocator();

	relationnal_ope();
	swap_non_member();

}
