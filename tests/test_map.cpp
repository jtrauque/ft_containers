# include <map>
# include <iostream>
# include <cstdlib>
# include <list>
#include "map.hpp"

#ifndef NAMESPACE
# define NAMESPACE ft
#endif

////////////////////////////////////////////////////////////////////////////////
	template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

	template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	(void)print_content;
	std::cout << "size: " << mp.size() << std::endl;
	/* std::cout << "max_size: " << mp.max_size() << std::endl; */
	/* if (print_content) */
	/* { */
	/* 	typename T_MAP::const_iterator it = mp.begin(), ite = mp.end(); */
	/* 	std::cout << std::endl << "Content is:" << std::endl; */
	/* 	for (; it != ite; ++it) */
	/* 		std::cout << "- " << printPair(it, false) << std::endl; */
	/* } */
	/* std::cout << "###############################################" << std::endl; */
}

struct ft_more {
	bool	operator()(const int &first, const int &second) const {
		return (first > second);
	}
};
////////////////////////////////////////////////////////////////////////////////
#include <string>
/*
void constructor()
{
	// (1) Default constructor
	NAMESPACE::map<std::string, int> map1;
	//  map1["something"] = 69;
	//   map1["anything"] = 199;
	//  map1["that thing"] = 50;
	//   std::cout << "map1 = "; printSize(map1);
	//	std::cout << map1["something"] << std::endl;
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

	//	map1.printTree();
	//	map1.erase("g");
	//	map1.printTree();
	// with comp
	NAMESPACE::map<int, std::string> map_cmp; 
	map_cmp[42] = "fgzgxfn"; 
	map_cmp[25] = "funny"; 
	map_cmp[80] = "hey"; 
	map_cmp[12] = "no"; 
	map_cmp[27] = "bee"; 
	map_cmp[90] = "8"; 
	printSize(map_cmp); 


	std::cout << (map_cmp[42] < map_cmp[90]) << std::endl; 

	         // (2) Range constructor 
	NAMESPACE::map<std::string, int> iter(map1.find("a"), map1.end()); 
	std::cout << "\niter = "; printSize(iter);
	std::cout << "map1 = "; printSize(map1); 

	         // (3) Copy constructor 
	         NAMESPACE::map<std::string, int> copied(map1); 
	         std::cout << "\ncopied = "; printSize(copied); 
		std::cout << copied["z"] << std::endl;
	         std::cout << "map1 = "; printSize(map1);
		 
}

 void operator_equal() // operator = 
 {
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

 void begin() 
 { 
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

 void end() 
 { 
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

void rbegin()
 { 
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

 void rend() 
 { 
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


 void empty() 
 { 
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

 void size() 
 { 
 	NAMESPACE::map<char,int> mymap; 
 	mymap['a']=101; 
 	mymap['b']=202; 
 	mymap['c']=302; 

 	std::cout << "mymap.size() is " << mymap.size() << '\n';
	//mymap.size() is 3
 } 

 void max_size()
 {
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

 void operator_hook() // operator [] 
 { 
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


 void insert() 
 { 
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
  element 'z' already existed with a value of 200
mymap contains:
a => 100
b => 300
c => 400
z => 200
anothermap contains:
a => 100
b => 300
 } 

 void iterator_validity() 
 { 
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

 void erase() 
 { 
 	NAMESPACE::map<std::string,int> mymap; 
 	NAMESPACE::map<std::string,int>::iterator it; 

 	// insert some values: 
 	mymap["a"]=10; 
 	mymap["b"]=20; 
 	mymap["c"]=30; 
 	mymap["d"]=40; 
	mymap["e"]=50; 
 	mymap["f"]=60;
	std::cout << "---------------------------------------------------------------" << std::endl; 
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
template <class Key, class T>
void	print(NAMESPACE::map<Key, T>& lst)
{
	for (typename NAMESPACE::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}
 void swap() 
 { 
 	NAMESPACE::map<char,int> foo,bar; 

	foo['x']=100; 
 	foo['y']=200; 

 	bar['a']=11; 
 	bar['b']=22; 
 	bar['c']=33; 

 	NAMESPACE::map<char,int>::iterator it_foo = foo.begin();
 	NAMESPACE::map<char,int>::iterator it_bar = bar.begin(); 

 	foo.swap(bar); 


 	if (foo.begin() == it_bar) 
 		std::cout << "IT_BAR OK" << std::endl; 
 	if (bar.begin() == it_foo) 
 		std::cout << "IT_FOO OK" << std::endl; 

 	std::cout << "foo contains:\n"; 
 	for (NAMESPACE::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it) 
 		std::cout << it->first << " => " << it->second << '\n'; 

 	std::cout << "bar contains:\n"; 
 	for (NAMESPACE::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it) 
 		std::cout << it->first << " => " << it->second << '\n';
	foo contains:
a => 11
b => 22
c => 33
bar contains:
x => 100
y => 200
	NAMESPACE::map<char, int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
	NAMESPACE::map<char, int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar

	NAMESPACE::map<char, int>	other;

  other['1'] = 73;
  other['2'] = 173;
  other['3'] = 763;
  other['4'] = 73854;
  other['5'] = 74683;
  other['6'] = 753;

  NAMESPACE::map<char, int>::const_iterator tmp3 = other.begin(); // tmp3 iterates through other

  std::cout << "foo contains:\n";
  for (NAMESPACE::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (NAMESPACE::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

	while(tmp != bar.end())
	{
		std::cout << tmp->first << " => " << tmp->second << '\n';
		tmp++;
	}
	tmp--;

	while(tmp2 != foo.end())
	{
		std::cout << tmp2->first << " => " << tmp2->second << '\n';
		tmp2++;
	}
	tmp2--;

	other.swap(foo); //tmp2 iterates through other
					//tmp3 iterates throught foo
	print(other);
	print(foo);
	print(bar);
	while(tmp != bar.begin())
	{
		std::cout << tmp->first << " => " << tmp->second << '\n';
		tmp--;
	}
	std::cout << tmp->first << " => " << tmp->second << '\n';

	while(tmp2 != other.begin())
	{
		std::cout << tmp2->first << " => " << tmp2->second << '\n';
		tmp2--;
	}
	std::cout << tmp2->first << " => " << tmp2->second << '\n';

	while(tmp3 != foo.end())
	{
		std::cout << tmp3->first << " => " << tmp3->second << '\n';
		tmp3++;
	}
	tmp3--;

	bar.swap(foo); //tmp3 iterates through bar
				//tmp iterates through foo

	print(other);
	print(foo);
	print(bar);

	while(tmp != foo.end())
	{
		std::cout << tmp->first << " => " << tmp->second << '\n';
		tmp++;
	}

	while(tmp2 != other.end())
	{
		std::cout << tmp2->first << " => " << tmp2->second << '\n';
		tmp2++;
	}

	while(tmp3 != bar.begin())
	{
		std::cout << tmp3->first << " => " << tmp3->second << '\n';
		tmp3--;
	}
	std::cout << tmp3->first << " => " << tmp3->second << '\n';

 } 
*/
 void clear() 
 { 
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

/*
 void key_comp() 
 { 
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
	mymap contains:
a => 100
b => 200
c => 300
 } 

 void value_comp() 
 { 
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
	mymap contains:
x => 1001
y => 2002
z => 3003
 } 


 void find() 
 { 
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
	elements in mymap:
a => 50
c => 150
d => 200
 } 

 void count() 
 { 
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

void lower_bound() 
 { 
 	NAMESPACE::map<std::string,int> mymap; 
 	NAMESPACE::map<std::string,int>::iterator itlow,itup; 

 	mymap["a"]=20; 
 	mymap["b"]=40; 
 	mymap["c"]=60; 
 	mymap["d"]=80; 
 	mymap["e"]=100; 

 	itlow=mymap.lower_bound ("b");  // itlow points to b 
 	itup=mymap.upper_bound ("d");   // itup points to e (not d!) 

 //	mymap.erase("b");        // erases [itlow,itup) 
//	mymap.printTree();
 //	mymap.erase("c");        // erases [itlow,itup) 
//	mymap.printTree();
 //	mymap.erase("d");        // erases [itlow,itup) 
 	mymap.erase(itlow,itup);        // erases [itlow,itup) 

 	// print content: 
 	for (NAMESPACE::map<std::string,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it) 
 		std::cout << it->first << " => " << it->second << '\n'; 
 } 

void upper_bound()
{
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

void equal_range()
{
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


void get_allocator()
{
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

template <class MAP>
void	cmp(const MAP &lhs, const MAP &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

void relationnal_ope()
{

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

void swap_non_member()
{
	NAMESPACE::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	swap(bar, foo);

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

*/

int main3()
{
//	constructor();
   //     operator_equal(); // operator = 

//	 begin(); 
//	 end(); 
//	 rbegin(); 
//	 rend(); 
//
//	 empty(); 
//	 size(); 
//	 max_size(); 

//	 operator_hook(); // operator [] 
//
//	 insert(); 
//	swap(); 
	 clear(); 

//	key_comp(); 
//	value_comp();
//	 erase(); 

//	find(); 
//	 count(); 
//	lower_bound(); 
//	upper_bound();
//	equal_range();

//	get_allocator();

//	relationnal_ope();
//	swap_non_member();

//	 iterator_validity();
	return 0; 

}
