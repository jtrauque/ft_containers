
#include <iostream>
#include <cstdlib>
#include <list>

#include <vector>
#include "vector.hpp"

#ifndef NAMESPACE
# define NAMESPACE ft
#endif

void swap_non_member() {
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

void relationnal_ope() {
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

void get_allocator() {
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

void clear() {
	std::cout << "CLEAR" << std::endl;
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

void swap() {
	std::cout << "SWAP" << std::endl;
	NAMESPACE::vector<int> foo (3,100);   // three ints with a value of 100
	NAMESPACE::vector<int> bar (5,200);   // five ints with a value of 200

	NAMESPACE::vector<int>::iterator it_foo = foo.begin();
	NAMESPACE::vector<int>::iterator it_bar = bar.begin();

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

void erase() {
	std::cout << "ERASE" << std::endl;
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

void insert() {
	std::cout << "INSERT" << std::endl;
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

void pop_back() {
	std::cout << "POP" << std::endl;
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

void push_back() {
	std::cout << "PUSH" << std::endl;
	NAMESPACE::vector<int> myvector;
	for (int i = 0; i < 50; i++)
		myvector.push_back((i) % 3);

	std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
}

void assign() {
	std::cout << "ASSIGN" << std::endl;
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

void back() {
	std::cout << "BACK" << std::endl;
	NAMESPACE::vector<int> myvector;

	myvector.push_back(10);

	while (myvector.back() != 0)
	{
		myvector.push_back ( myvector.back() -1 );
	}

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size() ; i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	//myvector contains: 10 9 8 7 6 5 4 3 2 1 0
}

void front() {
	std::cout << "FRONT" << std::endl;
	NAMESPACE::vector<int> myvector;

	myvector.push_back(78);
	myvector.push_back(16);

	// now front equals 78, and back 16

	myvector.front() -= myvector.back();

	std::cout << "myvector.front() is now " << myvector.front() << '\n';
	//myvector.front() is now 62
}

void at()
{
	std::cout << "AT" << std::endl;
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

void operator_hook()
{
	std::cout << "HOOK" << std::endl;
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

void reserve()
{
	std::cout << "RESERVE" << std::endl;
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

void empty()
{
	std::cout << "EMPTY" << std::endl;
	NAMESPACE::vector<int> myvector;
	int sum (0);

	for (int i=1;i<=10;i++) myvector.push_back(i);

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}

	std::cout << "total: " << sum << '\n';
	//total: 55
}

void capacity() {
	std::cout << "CAPACITY" << std::endl;
	NAMESPACE::vector<int> myvector;

	// set some content in the vector:
	std::cout << "max_size: " << (int) myvector.max_size() << '\n';
	for (int i=0; i<100; i++) myvector.push_back(i);

	std::cout << "size: " << (int) myvector.size() << '\n';
	std::cout << "capacity: " << (int) myvector.capacity() << '\n';
	std::cout << "max_size: " << (int) myvector.max_size() << '\n';
	/* size: 100 */
	/* capacity: 128 */
	/* max_size: 1073741823 */
}

void resize()
{
	std::cout << "RESIZE" << std::endl;
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
}

void max_size()
{
	std::cout << "MAX SIZE" << std::endl;
	NAMESPACE::vector<int> myvector;

	// set some content in the vector:
	for (int i=0; i<100; i++) myvector.push_back(i);

	std::cout << "size: " << myvector.size() << "\n";
	std::cout << "capacity: " << myvector.capacity() << "\n";
	std::cout << "max_size: " << myvector.max_size() << "\n";
}

void size()
{
	std::cout << "SIZE" << std::endl;
	NAMESPACE::vector<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<10; i++) myints.push_back(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.insert (myints.end(),10,100);
	std::cout << "2. size: " << myints.size() << '\n';

	myints.pop_back();
	std::cout << "3. size: " << myints.size() << '\n';
}

void rend()
{
	std::cout << "REND" << std::endl;
	NAMESPACE::vector<int> myvector (5);  // 5 default-constructed ints

	NAMESPACE::vector<int>::reverse_iterator rit = myvector.rbegin();

	int i=0;
	for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:";
	for (NAMESPACE::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void rbegin()
{
	std::cout << "RBEGIN" << std::endl;
	NAMESPACE::vector<int> myvector (5);  // 5 default-constructed ints

	int i=0;

	NAMESPACE::vector<int>::reverse_iterator rit = myvector.rbegin();
	for (; rit!= myvector.rend(); ++rit)
		*rit = ++i;

	std::cout << "myvector contains:";
	for (NAMESPACE::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}


void end()
{
	std::cout << "END" << std::endl;
	NAMESPACE::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	std::cout << "myvector contains:";
	for (NAMESPACE::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void begin()
{
	std::cout << "BEGIN" << std::endl;
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

}

void operator_equal()
{
	std::cout << "OPERATOR=" << std::endl;
	NAMESPACE::vector<int> foo (3,0);
	NAMESPACE::vector<int> bar (5,0);

	bar = foo;
	foo = NAMESPACE::vector<int>();

	std::cout << "Size of foo: " << int(foo.size()) << '\n';
	std::cout << "Size of bar: " << int(bar.size()) << '\n';
	return;
}


void constructor()
{
	// constructors used in the same order as described above:
	std::cout << "CONSTRUCTOR" << std::endl;
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

	return;
}

int main2()
{
	/* constructor(); */
	/* operator_equal(); // operator= */

	/* begin(); */
	/* end(); */
	/* rbegin(); */
	/* rend(); */

	/* size(); */
	/* max_size(); */
	/* resize(); */
	capacity();
	/* empty(); */
	/* reserve(); */

	/* operator_hook(); // operator[] */
	/* at(); */
	/* front(); */
	/* back(); */

	/* assign(); */
	/* push_back(); */
	/* pop_back(); */
	/* insert(); */
	/* erase(); */
	/* swap(); */
	/* clear(); */

	/* get_allocator(); */

	/* relationnal_ope(); */
	/* swap_non_member(); */


	return 0;
}

using namespace NAMESPACE;
using namespace std;

/* template <class T> */
/* void	print(NAMESPACE::vector<T> & lst) */
/* { */
/* 	for (typename NAMESPACE::vector<T> ::iterator it = lst.begin(); it != lst.end(); it++) */
/* 	{ */
/* 		for (typename NAMESPACE::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++) */
/* 			cout << *it2 << ' '; */
/* 		cout << '\n'; */
/* 	} */
/* } */

	template <class T>
void	print(NAMESPACE::vector<T>& lst)
{
	for (typename NAMESPACE::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
		cout << *it << ' ';
	cout << '\n';
}
class Awesome {

	public:

		Awesome( void ) : _n( 42 ) { std::cout << "Default constructor" << std::endl; } //should not happen too often or else there is a wrong use of allocator (which calls the copy constructor)
		Awesome( int n ) : _n( n ) { std::cout << "Int constructor" << std::endl; (void)n; }
		Awesome( Awesome const &rhs ) : _n( 42 ) { *this = rhs;}
		virtual ~Awesome(void) {}

		Awesome &operator=( Awesome const & rhs ) { this->_n = rhs._n; return (*this); }
		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) const { return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
		void operator+=(int rhs){ _n += rhs; }
		int get( void ) const { return this->_n; }

	private:

		int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

	template <class T>
void	print_vector(NAMESPACE::vector<T> &test)
{
	typename NAMESPACE::vector<T>::iterator		beg = test.begin();
	typename NAMESPACE::vector<T>::iterator		end = test.end();
	std::cout << "size : " << test.size() << ", capacity : " << test.capacity() << std::endl;
	for (typename NAMESPACE::vector<T>::iterator it = beg; it != end; it++)
	{
		std::cout << *it << " ";
		if (((it - beg) % 10 == 9) && it > beg)
			std::cout << std::endl;
	}
	std::cout << std::endl;
}

	template <class T>
void	push_pop_back_tests(void)
{
	std::cout << std::endl << "PUSH BACK & POP BACK TESTS" << std::endl;
	NAMESPACE::vector<T> test;

	std::cout << "Empty ? " << test.empty() << " / Capacity : " << test.capacity() << " / Size : " << test.size() << std::endl;
	for (size_t i = 0; i < 51; i++)
	{
		test.push_back(i);
		std::cout << test.size() << ": " << test.capacity() << " - ";
		if (!(i % 10) && i != 0)
			std::cout << std::endl;
	}
	print_vector<T>(test);
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	print_vector<T>(test);
}

	template <class T>
void	resize_tests(void)
{
	std::cout << std::endl << "RESIZE TESTS" << std::endl;
	NAMESPACE::vector<T> test(12, 12);

	test.resize(72);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.resize(100);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.resize(4170);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.resize(171, 12);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.resize(62);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
}

	template <class T>
void	insert_tests()
{
	std::cout << std::endl << "INSERT TESTS" << std::endl;
	NAMESPACE::vector<T> test(1, 1);
	NAMESPACE::vector<T> test2(5, 5);

	test.insert(test.begin(), 200, 12);
	print_vector<T>(test);
	/* std::cout << __LINE__ << std::endl; */
	test.insert(test.begin() + 12, 200, 30);
	/* std::cout << __LINE__ << std::endl; */
	print_vector<T>(test);
	test.insert(test.end(), 12, 50);
	/* std::cout << __LINE__ << std::endl; */
	print_vector<T>(test);
	test.insert(test.end() - 1, 0, 60);
	print_vector<T>(test);
	test.insert(test.end() - 1, 1, 70);
	print_vector<T>(test);
	test.insert(test.begin() + 412, test2.begin(), test2.end());
	print_vector<T>(test);
	test.insert(test.begin() + 6, test2.begin(), test2.end());
	print_vector<T>(test);
	test.insert(test.end(), test2.begin(), test2.end());
	print_vector<T>(test);
}

	template <class T>
void	reserve_tests(void)
{
	std::cout << std::endl << "RESERVE TESTS" << std::endl;
	NAMESPACE::vector<T> test(65, 7);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.reserve(12);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.reserve(66);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.reserve(128);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.reserve(1023);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.reserve(10252);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	try
	{
		test.reserve(test.max_size() + 1);
	}
	catch(std::length_error &le)
	{
		std::cout << "length error" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << "error : " << e.what() << std::endl;
	}
	print_vector<T>(test);
}

	template <class T>
void	copy_swap_tests(void)
{
	std::cout << std::endl << "COPY && SWAP TESTS" << std::endl;
	NAMESPACE::vector<T> test;
	std::cout << "test capacity :" << test.capacity() << std::endl;
	for (size_t i = 0; i < 50; i++) {
		test.push_back(i); 
		std::cout << "test capacity :" << test.capacity() << std::endl;
	}
	std::cout << __LINE__ << std::endl;
	print_vector<T>(test);
	NAMESPACE::vector<T> test_copy(test);
	for (size_t i = 0; i < test_copy.size(); i++) { test_copy[i] += 100; }
	print_vector<T>(test_copy);
	NAMESPACE::vector<T> test_range(test.begin() + 20, test.begin() + 30);
	print_vector<T>(test_range);
	test_copy.swap(test);
	std::cout << __LINE__ << std::endl;
	print_vector<T>(test);
	print_vector<T>(test_copy);
	test_copy.swap(test_range);
	print_vector<T>(test_range);
	print_vector<T>(test_copy);
	test.swap(test_copy);
	print_vector<T>(test);
	print_vector<T>(test_copy);
}

	template <class T>
void	reverse_it_tests(void)
{
	std::cout << std::endl << "REVERSE IT TESTS" << std::endl;
	NAMESPACE::vector<T> test;
	for (size_t i = 0; i < 12; i++) { test.push_back(i); }
	typename NAMESPACE::vector<T>::reverse_iterator		revbeg = test.rbegin();
	for (typename NAMESPACE::vector<T>::reverse_iterator it = revbeg; it != test.rend(); it++)
	{
		std::cout << *it << " ";
		if (!((revbeg - it) % 10) && it != revbeg)
			std::cout << std::endl;
	}
	std::cout << *(test.rbegin() + 2) << std::endl;
	std::cout << *(test.rend() - 8) << std::endl;
	std::cout << (test.rbegin() == revbeg) << std::endl;
	revbeg++;
	std::cout << *revbeg << std::endl;
	std::cout << (test.rbegin() == test.rend()) << std::endl;
	std::cout << (test.rbegin() <= test.rbegin()) << std::endl;
	std::cout << (test.rbegin() < test.rend()) << std::endl;
	std::cout << (test.rbegin() >= test.rend()) << std::endl;
	revbeg += 3;
	std::cout << *revbeg << std::endl;
	std::cout << std::endl;
}

	template <class T>
void	erase_clear_tests(void)
{
	std::cout << std::endl << "ERASE && CLEAR TESTS" << std::endl;
	NAMESPACE::vector<T> test(31, 12);
	test.erase(test.begin(), test.begin() + 5);
	print_vector<T>(test);
	test.erase(test.begin() + 12, test.begin() + 16);
	print_vector<T>(test);
	test.clear();
	print_vector<T>(test);
}

void	max_size_tests(void)
{
	std::cout << std::endl << "MAX SIZE TESTS" << std::endl;
	NAMESPACE::vector<int> test(31, 12);
	NAMESPACE::vector<std::string> test2;
	NAMESPACE::vector<long long int> test3;
	NAMESPACE::vector<Awesome> test4;
	NAMESPACE::vector<unsigned int> test5(12, 340);
	std::cout << test.max_size() << std::endl;
	std::cout << test2.max_size() << std::endl;
	std::cout << test3.max_size() << std::endl;
	std::cout << test4.max_size() << std::endl;
	std::cout << test5.max_size() << std::endl;
}

void	awesome_tests(void)
{
	std::cout << std::endl << "AWESOME TESTS" << std::endl;
	NAMESPACE::vector<Awesome> test(21, 12);
	print_vector<Awesome>(test);
	NAMESPACE::vector<Awesome> test2;
	print_vector<Awesome>(test2);
	test2.push_back(12);
	test2.push_back(8);
	test2.push_back(16);
	print_vector<Awesome>(test2);
	std::cout << "SAME ?" << (test.begin() + 1 == test2.begin() + 1) << std::endl;
	test.assign(test2.begin(), test2.end());
	print_vector<Awesome>(test);
	test = test2;
	print_vector<Awesome>(test);
	std::cout << "SAME ?" << (test.begin() + 1 == test2.begin() + 1) << std::endl;
	test.insert(test.end(), test2.begin(), test2.end());
	print_vector<Awesome>(test);
	test.insert(test.begin(), test2.begin(), test2.end());
	test2 = test;
	print_vector<Awesome>(test);
	std::cout << "end awesome test" << std::endl;
}

int main()
{
	NAMESPACE::vector<int>			test(3, 3);

	cout << "self assignation test\n";
	NAMESPACE::vector<int>	self_assign;
	NAMESPACE::vector<int>	*ptr = &self_assign;
	NAMESPACE::vector<int>	*ptr2 = &self_assign;

	self_assign.assign(4, test);
	*ptr = *ptr2;

	cout << std::boolalpha << (*ptr == *ptr2) << '\n';
//	self_assign = self_assign; //compiler doesn't like it!



	NAMESPACE::vector<int> JOHN;
	NAMESPACE::vector<int> BOB(5, test);
	cout << "BOB(5, test(test, 5)) : \n";
	for (size_t i = 0; i < BOB.size(); i++)
	{
		for (size_t j = 0; j < BOB[i].size(); j++)
			cout << BOB[i][j] << ' ';
		cout << '\n';
	}
	NAMESPACE::vector<int> MIKE(BOB);

	// CTORs
	cout << "\nCTORS\n";
	cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
	cout << "BOB is empty? " << BOB.empty() << '\n';

	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;

	// RESIZE
	size_t	bob_resize = 2;
	cout << "\nRESIZE\n";
	BOB.resize(bob_resize);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 63\n";

	size_t	mike_resize = 9;
	bob_resize = 0;
	
	BOB.resize(bob_resize);
	cout << "BOB is empty now ? " << BOB.empty() << '\n';
	MIKE.resize(mike_resize, test);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_resize)
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
		{
			cout << MIKE[i][j] << ' ';
		}
	cout << std::endl;
	}
	// RESERVE
	cout << "\nRESERVE\n";

	size_t	john_reserve = 0;
	size_t	bob_reserve = 3;
	size_t	mike_reserve = 4;

	JOHN.reserve(john_reserve);
	BOB.reserve(bob_reserve);
	MIKE.reserve(mike_reserve);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= john_reserve)
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_reserve)
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_reserve)
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			cout << MIKE[i][j] << ' ';
	cout << std::endl;
	}

	//AT
	cout << "\nAT\n";
	try
	{
		cout << MIKE.at(2).front() << '\n';
		cout << MIKE.at(87).back() << '\n';
	}
	catch (std::out_of_range& oor)
	{
		(void)oor;
		cout << "OOR error caught\n";
	}

	// FRONT / BACK
	cout << "\nFRONT / BACK\n";
	cout << "front() of MIKE : " << MIKE.front().front() << '\n';
	cout << "back() of MIKE : " << MIKE.back().back() << '\n';

	//ASSIGN
	cout << "\nASSIGN\n";
	test.assign(3, 17);
	BOB.assign(3, test);

	//ASSIGN RANGE
	cout << "\nASSIGN RANGE\n";
	NAMESPACE::vector<int>	assign_range;
	assign_range.assign(8, test);
	assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

	//EMPTY
	cout << "\nEMPTY\n";
	cout << "BOB is empty ? " << BO.empty() << '\n';
	cout << "BOB at(1) : " << BOB.at(1).front() << '\n';

	//PUSH/POP_BACK
	cout << "\nPUSH/POP_BACK\n";
	test.assign(2, 42);
	BOB.push_back(test);
	cout << "last elem of BOB : " << BOB.back().back() << '\n';
	BOB.pop_back();
	cout << "last elem of BOB : " << BOB.back().back() << '\n';

	//INSERT
	cout << "\nINSERT\n";
	NAMESPACE::vector<int>	insert_in_me;
	for (int i = 0; i < 15; i++)
	{
		NAMESPACE::vector<int>	j(2, i);
		insert_in_me.push_back(j);
	}
	for (size_t i = 0; i < insert_in_me.size(); i++)
	{
		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
			cout << insert_in_me.at(i).at(j) << ' ';
		cout << '\n';
	}

	NAMESPACE::vector<int>::iterator	tmp;
	test.assign(23, 19);
	tmp = insert_in_me.begin() + 4;
	insert_in_me.insert(tmp, 8, test);
	for (size_t i = 0; i < insert_in_me.size(); i++)
	{
		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
			cout << insert_in_me.at(i).at(j) << ' ';
		cout << '\n';
	}

	NAMESPACE::vector<int>::const_iterator const_it(insert_in_me.begin());
	cout << "Const it.front() : " << std::endl;
	cout << (*const_it).front() << '\n';


	//INSERT
	cout << "\nINSERT\n";
	NAMESPACE::vector<int>	std_insert_in_me;
	for (int i = 0; i < 15; i++)
		std_insert_in_me.push_back(test);
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		cout << std_insert_in_me.at(i).front() << ' ';
	cout << '\n';

	NAMESPACE::vector<int>::iterator	std_tmp;
	std_tmp = std_insert_in_me.begin() + 4;
	std_insert_in_me.insert(std_tmp, 8, test);
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		cout << std_insert_in_me.at(i).back() << ' ';
	cout << '\n';


	//INSERT RANGE
	cout << "\nINSERT RANGE\n";
	NAMESPACE::vector<int>	insert_bis;
	for (int i = 0; i < 7; i++)
	{
		NAMESPACE::vector<int>	j(2, i * 3);
		insert_bis.push_back(j);
	}
	for (size_t i = 0; i < insert_bis.size(); i++)
		cout << insert_bis[i].back() << ' ';
	cout << '\n';

	insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
	for (size_t i = 0; i < insert_bis.size(); i++)
		cout << insert_bis[i].back() << ' ';
	cout << '\n';


	//ERASE
	cout << "\nERASE\n";
	NAMESPACE::vector<int>	erase_in_me;
	for (int i = 0; i < 15; i++)
	{
		NAMESPACE::vector<int>	j(1, i);
		erase_in_me.push_back(j);
	}
	for (size_t i = 0; i < erase_in_me.size(); i++)
		cout << erase_in_me.at(i).front() << ' ';
	cout << '\n';

	erase_in_me.erase(erase_in_me.begin() + 7);
	for (size_t i = 0; i < erase_in_me.size(); i++)
		cout << erase_in_me.at(i).front() << ' ';
	cout << '\n';
	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
	for (size_t i = 0; i < erase_in_me.size(); i++)
		cout << erase_in_me.at(i).front() << ' ';
	cout << '\n';

	//SWAP
	cout << "\nSWAP\n";
	john_reserve = 4;
	JOHN.reserve(john_reserve);
	BOB.swap(MIKE);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			cout << MIKE[i][j] << ' ';
	cout << std::endl;
	}

	MIKE.swap(JOHN);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			cout << MIKE[i][j] << ' ';
	cout << std::endl;
	}

	//CLEAR
	cout << "\nCLEAR\n";
	JOHN.clear();
	MIKE.clear();
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			cout << MIKE[i][j] << ' ';
	cout << std::endl;
	}

	//NON MEMBER Functions
	cout << "\nNON MEMBER functions\n";
	NAMESPACE::swap(BOB, MIKE);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			cout << MIKE[i][j] << ' ';
	cout << std::endl;
	}
	
	//RELATIONAL OPERATORS
	cout << "\nRELATIONAL OPERATORS\n";
	NAMESPACE::vector<int> MIKE_2(MIKE);
	cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
	cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';

	cout << "\nReal Vector\n";
	NAMESPACE::vector<int> real;
	real.assign(5, test);
	for (NAMESPACE::vector<int>::iterator it = real.begin(); it != real.end(); it++)
		cout << (*it).front() << " ";
	cout << '\n';

	cout << std::endl;
	return (0);
}

/* int main() */
/* { */
/* 	push_pop_back_tests<int>(); */
/* 	resize_tests<int>(); */
/* 	insert_tests<int>(); */
/* 	reserve_tests<int>(); */
/* 	copy_swap_tests<int>(); */
/* 	reverse_it_tests<int>(); */
/* 	erase_clear_tests<int>(); */
/* 	max_size_tests(); */
/* 	awesome_tests(); */
/* 	push_pop_back_tests<Awesome>(); */
/* 	resize_tests<Awesome>(); */
/* 	insert_tests<Awesome>(); */
/* 	reserve_tests<Awesome>(); */
/* 	copy_swap_tests<Awesome>(); */
/* 	reverse_it_tests<Awesome>(); */
/* 	erase_clear_tests<Awesome>(); */
/* } */

