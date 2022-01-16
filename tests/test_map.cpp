# include <map>
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <list>
#include <string>
#include "map.hpp"

#ifndef NAMESPACE
# define NAMESPACE ft
#endif

#define NC "\e[0m"
#define REDC "\e[0;31m"
#define GRN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define PINK "\e[0;35m"

	template <typename T>
static std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

	template <typename T_MAP>
static void	printSize(T_MAP const &mp, bool print_content = 1)
{
	(void)print_content;
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << std::endl;
}

struct ft_cmp {
	bool	operator()(const int &first, const int &second) const {
		return (first > second);
	}
};

static void constructor() {
	std::cout << PINK << __func__ << NC << std::endl;
	// (1) Default constructor
	NAMESPACE::map<std::string, int> map1;
	map1["c"] = 3;
	map1["a"] = 1;
	map1["b"] = 2;
	map1["g"] = 7;
	map1["d"] = 4;
	map1["e"] = 5;
	map1["f"] = 6;
	map1["z"] = 8;
	std::cout << "map1 = "; printSize(map1); 
	std::cout << "map1 = "; printSize(map1); 

	// (2) Range constructor 
	NAMESPACE::map<std::string, int> iter(map1.find("a"), map1.end()); 
	std::cout << "\niter = "; printSize(iter);
	std::cout << "map1 = "; printSize(map1); 

	// (3) Copy constructor 
	NAMESPACE::map<std::string, int> copied(map1); 
	std::cout << "\ncopied = "; printSize(copied); 
	std::cout << copied["z"] << std::endl;
	std::cout << "map1 = "; printSize(map1);

	NAMESPACE::map<std::string, int, ft_cmp> compare;
	std::cout << "map1 = "; printSize(map1);
}

static void operator_equal() { // operator = 
	std::cout << PINK << __func__ << NC << std::endl;
	NAMESPACE::map<char,int> first; 
	NAMESPACE::map<char,int> second; 

	first['x']=8; 
	first['y']=16; 
	first['z']=32; 

	second=first;                // second now contains 3 ints 
	first=NAMESPACE::map<char,int>();  // and first is now empty 

	std::cout << "Size of first: " << first.size() << '\n'; 
	std::cout << "Size of second: " << second.size() << '\n';
	//Size of first: 0
	//Size of second: 3
}

static void begin() { 
	std::cout << PINK << __func__ << NC << std::endl;
	NAMESPACE::map<char,int> mymap; 

	mymap['b'] = 100; 
	mymap['a'] = 200; 
	mymap['c'] = 300; 

	// show content: 
	for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it) 
		std::cout << it->first << " => " << it->second << '\n';
	//a => 200
	//b => 100
	//c => 300
	std::cout << "Hello there\n";
	for (NAMESPACE::map<char,int>::const_iterator it=mymap.begin(); it!=mymap.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "General Kenobi\n";

	NAMESPACE::map<char, int>::const_iterator it = mymap.begin();
	NAMESPACE::map<char, int>::const_iterator ti = mymap.end();
	std::cout << "Wupwup\n";

	it++;
	++it;
	it--;
	--it;
	std::cout << "marker1\n";

	ti--;
	--ti;
	++ti;
	ti++;

	ti = it;

	std::cout << "Trump is a kiddo\n";
	NAMESPACE::map<char, int>::iterator end = mymap.end();
	while(it != end)
	{
		std::cout << it->first << " => " << it->second << '\n';
		it++;
	}
} 

static void end() { 
	std::cout << PINK << __func__ << NC << std::endl;
	NAMESPACE::map<char,int> mymap; 

	mymap['b'] = 100; 
	mymap['a'] = 200; 
	mymap['c'] = 300; 

	// show content: 
	for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it) 
		std::cout << it->first << " => " << it->second << '\n';
	//a => 200
	//b => 100
	//c => 300


	NAMESPACE::map<char,int>::iterator it = mymap.end();
	it--;
	std::cout << "end - 1 " << it->first << '\n';
	for (it = --mymap.end(); it!=mymap.begin(); --it)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << it->first << " => " << it->second << '\n';
} 

static void rbegin() { 
	std::cout << PINK << __func__ << NC << std::endl;
	NAMESPACE::map<char,int> mymap; 

	mymap['x'] = 100; 
	mymap['y'] = 200; 
	mymap['z'] = 300; 

	// show content: 
	NAMESPACE::map<char,int>::reverse_iterator rit;
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit) 
		std::cout << rit->first << " => " << rit->second << '\n';
	//z => 300
	//y => 200
	//x => 100

} 

static void rend() { 
	std::cout << PINK << __func__ << NC << std::endl;
	NAMESPACE::map<char,int> mymap; 

	mymap['x'] = 100; 
	mymap['y'] = 200; 
	mymap['z'] = 300; 

	// show content: 
	NAMESPACE::map<char,int>::reverse_iterator rit; 
	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit) 
		std::cout << rit->first << " => " << rit->second << '\n';
	//z => 300
	//y => 200
	//x => 100
} 


static void empty() { 
	std::cout << PINK << __func__ << NC << std::endl;
	NAMESPACE::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	while (!mymap.empty())
	{
		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
	}
	//a => 10
	//b => 20
	//c => 30

} 

static void size() { 
	std::cout << PINK << __func__ << NC << std::endl;
	NAMESPACE::map<char,int> mymap; 
	mymap['a']=101; 
	mymap['b']=202; 
	mymap['c']=302; 

	std::cout << "mymap.size() is " << mymap.size() << '\n';
	//mymap.size() is 3
} 

static void max_size() {
	std::cout << PINK << __func__ << NC << std::endl;
	int i;
	NAMESPACE::map<int,int> mymap; 

	if (mymap.max_size()>1000) 
	{
		for (i=0; i<1000; i++)  {
			mymap[i]=0; 
		}
		std::cout << "The map contains 1000 elements.\n"; 
	} 
	else std::cout << "The map could not hold 1000 elements.\n"; 
} 

static void operator_hook() {// operator []  
	std::cout << PINK << __func__ << NC << std::endl;
	NAMESPACE::map<char,std::string> mymap; 

	mymap['a']="an element"; 
	mymap['b']="another element"; 
	mymap['c']=mymap['b']; 

	std::cout << "mymap['a'] is " << mymap['a'] << '\n'; 
	std::cout << "mymap['b'] is " << mymap['b'] << '\n'; 
	std::cout << "mymap['c'] is " << mymap['c'] << '\n'; 
	std::cout << "mymap['d'] is " << mymap['d'] << '\n'; 

	std::cout << "mymap now contains " << mymap.size() << " elements.\n"; 
} 


static void insert() { 
	std::cout << PINK << __func__ << NC << std::endl;
	NAMESPACE::map<char,int> mymap; 

	// first insert function version (single parameter):
	mymap.insert ( NAMESPACE::pair<char,int>('a',100) );
	mymap.insert ( NAMESPACE::pair<char,int>('z',200) );

	NAMESPACE::pair<NAMESPACE::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( NAMESPACE::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	NAMESPACE::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, NAMESPACE::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, NAMESPACE::pair<char,int>('c',400));  // no max efficiency inserting

	// third insert function version (range insertion):
	NAMESPACE::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	/* element 'z' already existed with a value of 200 */
	/* 	mymap contains: */
	/* 	a => 100 */
	/* 	b => 300 */
	/* 	c => 400 */
	/* 	z => 200 */
	/* 	anothermap contains: */
	/* 	a => 100 */
	/* 	b => 300 */
} 

static void iterator_validity() { 
	std::cout << PINK << __func__ << NC << std::endl;
	NAMESPACE::map<char,int> mymap; 
	mymap.insert ( NAMESPACE::pair<char,int>('b',100) ); 
	mymap.insert ( NAMESPACE::pair<char,int>('c', 50) ); 
	mymap.insert ( NAMESPACE::pair<char,int>('d', 510) ); 

	NAMESPACE::map<char,int>::iterator it1 = ++(mymap.begin()); 
	NAMESPACE::map<char,int>::iterator it2 = ++(++(mymap.begin())); 

	mymap.insert (NAMESPACE::pair<char,int>('z',300)); 

	NAMESPACE::map<char,int>::iterator it11 = ++(mymap.begin()); 
	NAMESPACE::map<char,int>::iterator it22 = ++(++(mymap.begin())); 

	if (it1 == it11 && it2 == it22) 
		std::cout << "it insert validity OK" << std::endl;

	mymap.erase ('z'); 

	it11 = ++(mymap.begin()); 
	it22 = ++(++(mymap.begin())); 

	if (it1 == it11 && it2 == it22) 
		std::cout << "it erase validity OK" << std::endl; 
}

static void erase() { 
	std::cout << PINK << __func__ << NC << std::endl;
	NAMESPACE::map<std::string,int> mymap; 
	NAMESPACE::map<std::string,int>::iterator it; 

	// insert some values: 
	mymap["a"]=10; 
	mymap["b"]=20; 
	mymap["c"]=30; 
	mymap["d"]=40; 
	mymap["e"]=50; 
	mymap["f"]=60;
	it=mymap.find("b"); 
	mymap.erase (it);                   // erasing by iterator 
	mymap.erase ("f");                  // erasing by key 

	it=mymap.find ("e"); 
	mymap.erase ( it, mymap.end() );    // erasing by range 
	mymap.erase ("e");                  // erasing by key 
	// mymap.erase ("b");                  // erasing by key 
	//	mymap.printTree();

	// show content: 
	for (it=mymap.begin(); it!=mymap.end(); ++it) 
		std::cout << it->first << " => " << it->second << '\n'; 
} 

static void swap() {  
	std::cout << PINK << __func__ << NC << std::endl;
	NAMESPACE::map<char,int> foo,bar;  

	foo['x']=100;  
	foo['y']=200;  

	bar['a']=11;  
	bar['b']=22;  
	bar['c']=33;  

	foo.swap(bar);  

	std::cout << "foo contains:\n";  
	for (NAMESPACE::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)  
		std::cout << it->first << " => " << it->second << '\n';  

	std::cout << "bar contains:\n";  
	for (NAMESPACE::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)  
		std::cout << it->first << " => " << it->second << '\n'; 
	/* foo contains: */ 
		/* a => 11 */ 
		/* b => 22 */ 
		/* c => 33 */ 
		/* bar contains: */ 
		/* x => 100 */ 
		/* y => 200 */ 
}  

static void clear() {  
	std::cout << PINK << __func__ << NC << std::endl;
	NAMESPACE::map<std::string,int> mymap;  

	mymap["x"]=100;  
	mymap["y"]=200;  
	mymap["z"]=300;  

	std::cout << "mymap contains:\n";  
	for (NAMESPACE::map<std::string,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)  
		std::cout << it->first << " => " << it->second << '\n';  

	mymap.clear();  
	mymap["a"]=1101; 
	mymap["b"]=2202;  
	std::cout << "mymap contains:\n";  
	for (NAMESPACE::map<std::string,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)  
		std::cout << it->first << " => " << it->second << '\n'; 
	/* mymap contains: */ 
	/* x => 100 */ 
	/* y => 200 */ 
	/* z => 300 */ 
	/* mymap contains: */ 
	/* a => 1101 */ 
	/* b => 2202 */ 
}  


static void key_comp() {  
	std::cout << PINK << __func__ << NC << std::endl;
	NAMESPACE::map<char,int> mymap;  

	NAMESPACE::map<char,int>::key_compare mycomp = mymap.key_comp();  

	mymap['a']=100;  
	mymap['b']=200;  
	mymap['c']=300;  

	std::cout << "mymap contains:\n";  

	char highest = mymap.rbegin()->first;     // key value of last element  

	NAMESPACE::map<char,int>::iterator it = mymap.begin();  
	do {  
		std::cout << it->first << " => " << it->second << '\n';  
	} while ( mycomp((*it++).first, highest) );  

	std::cout << '\n'; 
	/* mymap contains: */ 
	/* a => 100 */ 
	/* b => 200 */ 
	/* c => 300 */ 
}  

static void value_comp() {  
	std::cout << PINK << __func__ << NC << std::endl;
	NAMESPACE::map<char,int> mymap;  

	mymap['x']=1001;  
	mymap['y']=2002;  
	mymap['z']=3003;  

	std::cout << "mymap contains:\n";  

	NAMESPACE::pair<char,int> highest = *mymap.rbegin();          // last element  

	NAMESPACE::map<char,int>::iterator it = mymap.begin();  
	do {  
		std::cout << it->first << " => " << it->second << '\n';  
	} while ( mymap.value_comp()(*it++, highest) ); 
	/* mymap contains: */ 
	/* x => 1001 */ 
	/* y => 2002 */ 
	/* z => 3003 */ 
}  


static void find() {  
	std::cout << PINK << __func__ << NC << std::endl;
	NAMESPACE::map<std::string,int> mymap;  
	NAMESPACE::map<std::string,int>::iterator it;  

	mymap["a"]=50;  
	mymap["b"]=100;  
	mymap["c"]=150;  
	mymap["d"]=200;  
	//	mymap.erase("b"); 
	it = mymap.find("b");  
	if (it != mymap.end())  
		mymap.erase (it);  

	// print content:  
	std::cout << "elements in mymap:" << '\n';  
	std::cout << "a => " << mymap.find("a")->second << '\n';  
	std::cout << "c => " << mymap.find("c")->second << '\n';  
	std::cout << "d => " << mymap.find("d")->second << '\n'; 
	/* elements in mymap: */ 
	/* a => 50 */ 
	/* c => 150 */ 
	/* d => 200 */ 
}  

static void count() {  
	std::cout << PINK << __func__ << NC << std::endl;
	NAMESPACE::map<char,int> mymap;  
	char c;  

	mymap ['a']=101;  
	mymap ['c']=202;  
	mymap ['f']=303;  

	for (c='a'; c<'h'; c++)  
	{  
		std::cout << c;  
		if (mymap.count(c)>0)  
			std::cout << " is an element of mymap.\n";  
		else  
			std::cout << " is not an element of mymap.\n";  
	}  
}  

static void lower_bound() { 
	std::cout << PINK << __func__ << NC << std::endl;
	NAMESPACE::map<char,int> mymap; 
	NAMESPACE::map<char,int>::iterator itlow,itup; 

	mymap['a']=20; 
	mymap['b']=40; 
	mymap['c']=60; 
	mymap['d']=80; 
	mymap['e']=100; 

	itlow=mymap.lower_bound ('b');  // itlow points to b 
	itup=mymap.upper_bound ('d');   // itup points to e (not d!) 

	/* mymap.erase('b');        // erases [itlow,itup) */ 
	/* mymap.erase('d');        // erases [itlow,itup) */ 
	mymap.erase(itlow,itup);        // erases [itlow,itup) 

	// print content: 
	for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it) 
		std::cout << it->first << " => " << it->second << '\n'; 
} 

static void upper_bound() {
	std::cout << PINK << __func__ << NC << std::endl;
	NAMESPACE::map<char,int> mymap;
	NAMESPACE::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	//a => 20
	//e => 100

}

static void equal_range() {
	std::cout << PINK << __func__ << NC << std::endl;
	NAMESPACE::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	NAMESPACE::pair<NAMESPACE::map<char,int>::iterator,NAMESPACE::map<char,int>::iterator> ret;
	ret = mymap.equal_range('b');

	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';

	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
	//lower bound points to: 'b' => 20
	//upper bound points to: 'c' => 30

}


static void get_allocator() {
	std::cout << PINK << __func__ << NC << std::endl;
	int psize;
	NAMESPACE::map<char,int> mymap;
	NAMESPACE::pair<const char,int>* p;

	// allocate an array of 5 elements using mymap's allocator:
	p=mymap.get_allocator().allocate(5);

	// assign some values to array
	psize = sizeof(NAMESPACE::map<char,int>::value_type)*5;

	std::cout << "The allocated array has a size of " << psize << " bytes.\n";

	mymap.get_allocator().deallocate(p,5);
	//The allocated array has a size of 40 bytes.

}

static void relationnal_ope() {
	std::cout << PINK << __func__ << NC << std::endl;
	std::map<char,int> foo,bar;
	foo['a']=100;
	foo['b']=200;
	bar['a']=10;
	bar['z']=1000;

	// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	return ;
	// foo and bar are not equal
	//foo is greater than bar
	//foo is greater than or equal to bar
}

static void swap_non_member() { 
	std::cout << PINK << __func__ << NC << std::endl;
	NAMESPACE::map<char,int> foo,bar; 

	foo['x']=100; 
	foo['y']=200; 

	bar['a']=11; 
	bar['b']=22; 
	bar['c']=33; 

	NAMESPACE::swap(bar, foo); 

	std::cout << "foo contains:\n"; 
	for (NAMESPACE::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it) 
		std::cout << it->first << " => " << it->second << '\n'; 

	std::cout << "bar contains:\n"; 
	for (NAMESPACE::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it) 
		std::cout << it->first << " => " << it->second << '\n'; 
	//foo contains: 
	//a => 11 
	//b => 22 
	//c => 33 
	//bar contains: 
	//x => 100 
	//y => 200 
} 

void test_map() {
	constructor();
	operator_equal(); // operator = 

	begin(); 
	end(); 
	rbegin(); 
	rend(); 

	empty(); 
	size(); 
	max_size(); 

	operator_hook(); // operator [] 

	insert(); 
	swap(); 
	clear(); 

	key_comp(); 
	value_comp();
	erase(); 

	find(); 
	count(); 
	lower_bound(); 
	upper_bound();
	equal_range();

	get_allocator();

	relationnal_ope();
	swap_non_member();

	iterator_validity();
}
