# include <map>
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <list>
#include "map.hpp"

#ifndef NAMESPACE
# define NAMESPACE ft
#endif
#define RED	1
#define BLACK 0
#define NC "\e[0m"
#define REDC "\e[0;31m"
#define GRN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define PINK "\e[0;35m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"
	
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

/* struct ft_more { */
/* 	bool	operator()(const int &first, const int &second) const { */
/* 		return (first > second); */
/* 	} */
/* }; */

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
*/

/*void	print(NAMESPACE::map<std::string, std::string>& lst) */
/*{ */
/*	/1* lst.printTree(); *1/ */
/*	for (typename NAMESPACE::map<std::string, std::string>::iterator it = lst.begin(); it != lst.end(); it++) */
/*		std::cout << it->first << " => " << it->second << '\n'; */
/*} */

/*template <class Key, class T> */
/*void	print(NAMESPACE::map<Key, T>& lst) */
/*{ */
/*	for (typename NAMESPACE::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++) */
/*		std::cout << it->first << " => " << it->second << '\n'; */
/*} */

/* void swap() */ 
/* { */ 
/* 	NAMESPACE::map<char,int> foo,bar; */ 

/*	foo['x']=100; */ 
/* 	foo['y']=200; */ 

/* 	bar['a']=11; */ 
/* 	bar['b']=22; */ 
/* 	bar['c']=33; */ 

/* 	NAMESPACE::map<char,int>::iterator it_foo = foo.begin(); */
/* 	NAMESPACE::map<char,int>::iterator it_bar = bar.begin(); */ 

/* 	foo.swap(bar); */ 


/* 	if (foo.begin() == it_bar) */ 
/* 		std::cout << "IT_BAR OK" << std::endl; */ 
/* 	if (bar.begin() == it_foo) */ 
/* 		std::cout << "IT_FOO OK" << std::endl; */ 

/* 	std::cout << "foo contains:\n"; */ 
/* 	for (NAMESPACE::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it) */ 
/* 		std::cout << it->first << " => " << it->second << '\n'; */ 

/* 	std::cout << "bar contains:\n"; */ 
/* 	for (NAMESPACE::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it) */ 
/* 		std::cout << it->first << " => " << it->second << '\n'; */
/*	/1* foo contains: *1/ */
/*/1* a => 11 *1/ */
/*/1* b => 22 *1/ */
/*/1* c => 33 *1/ */
/*/1* bar contains: *1/ */
/*/1* x => 100 *1/ */
/*/1* y => 200 *1/ */
/*	NAMESPACE::map<char, int>::const_iterator tmp = foo.begin(); //tmp iterates through foo */
/*	NAMESPACE::map<char, int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar */

/*	NAMESPACE::map<char, int>	other; */

/*  other['1'] = 73; */
/*  other['2'] = 173; */
/*  other['3'] = 763; */
/*  other['4'] = 73854; */
/*  other['5'] = 74683; */
/*  other['6'] = 753; */

/*  NAMESPACE::map<char, int>::const_iterator tmp3 = other.begin(); // tmp3 iterates through other */

/*  std::cout << "foo contains:\n"; */
/*  for (NAMESPACE::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it) */
/*    std::cout << it->first << " => " << it->second << '\n'; */

/*  std::cout << "bar contains:\n"; */
/*  for (NAMESPACE::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it) */
/*    std::cout << it->first << " => " << it->second << '\n'; */

/*	while(tmp != bar.end()) */
/*	{ */
/*		std::cout << tmp->first << " => " << tmp->second << '\n'; */
/*		tmp++; */
/*	} */
/*	tmp--; */

/*	while(tmp2 != foo.end()) */
/*	{ */
/*		std::cout << tmp2->first << " => " << tmp2->second << '\n'; */
/*		tmp2++; */
/*	} */
/*	tmp2--; */

/*	other.swap(foo); //tmp2 iterates through other */
/*					//tmp3 iterates throught foo */
/*	print(other); */
/*	print(foo); */
/*	print(bar); */
/*	while(tmp != bar.begin()) */
/*	{ */
/*		std::cout << tmp->first << " => " << tmp->second << '\n'; */
/*		tmp--; */
/*	} */
/*	std::cout << tmp->first << " => " << tmp->second << '\n'; */

/*	while(tmp2 != other.begin()) */
/*	{ */
/*		std::cout << tmp2->first << " => " << tmp2->second << '\n'; */
/*		tmp2--; */
/*	} */
/*	std::cout << tmp2->first << " => " << tmp2->second << '\n'; */

/*	while(tmp3 != foo.end()) */
/*	{ */
/*		std::cout << tmp3->first << " => " << tmp3->second << '\n'; */
/*		tmp3++; */
/*	} */
/*	tmp3--; */

/*	bar.swap(foo); //tmp3 iterates through bar */
/*				//tmp iterates through foo */

/*	print(other); */
/*	print(foo); */
/*	print(bar); */

/*	while(tmp != foo.end()) */
/*	{ */
/*		std::cout << tmp->first << " => " << tmp->second << '\n'; */
/*		tmp++; */
/*	} */

/*	while(tmp2 != other.end()) */
/*	{ */
/*		std::cout << tmp2->first << " => " << tmp2->second << '\n'; */
/*		tmp2++; */
/*	} */

/*	while(tmp3 != bar.begin()) */
/*	{ */
/*		std::cout << tmp3->first << " => " << tmp3->second << '\n'; */
/*		tmp3--; */
/*	} */
/*	std::cout << tmp3->first << " => " << tmp3->second << '\n'; */

/* } */ 
/*/1* */
 /* void clear() */ 
 /* { */ 
 /* 	NAMESPACE::map<std::string,int> mymap; */ 

 /* 	mymap["x"]=100; */ 
 /* 	mymap["y"]=200; */ 
	/* mymap["z"]=300; */ 

 /* 	std::cout << "mymap contains:\n"; */ 
	/* for (NAMESPACE::map<std::string,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it) */ 
		/* std::cout << it->first << " => " << it->second << '\n'; */ 

 /* 	mymap.clear(); */ 
 /* 	mymap["a"]=1101; */
	/* mymap["b"]=2202; */ 
 /* 	std::cout << "mymap contains:\n"; */ 
 /* 	for (NAMESPACE::map<std::string,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it) */ 
 /* 		std::cout << it->first << " => " << it->second << '\n'; */
	/* mymap contains: */
/* x => 100 */
/* y => 200 */
/* z => 300 */
/* mymap contains: */
/* a => 1101 */
/* b => 2202 */
 /* } */ 


 /* void key_comp() */ 
 /* { */ 
 /* 	NAMESPACE::map<char,int> mymap; */ 

 /* 	NAMESPACE::map<char,int>::key_compare mycomp = mymap.key_comp(); */ 

 /* 	mymap['a']=100; */ 
 /* 	mymap['b']=200; */ 
 /* 	mymap['c']=300; */ 

 /* 	std::cout << "mymap contains:\n"; */ 

 /* 	char highest = mymap.rbegin()->first;     // key value of last element */ 

 /* 	NAMESPACE::map<char,int>::iterator it = mymap.begin(); */ 
	/* do { */ 
 /* 		std::cout << it->first << " => " << it->second << '\n'; */ 
 /* 	} while ( mycomp((*it++).first, highest) ); */ 

 /* 	std::cout << '\n'; */
	/* mymap contains: */
/* a => 100 */
/* b => 200 */
/* c => 300 */
 /* } */ 

 /* void value_comp() */ 
 /* { */ 
 /* 	NAMESPACE::map<char,int> mymap; */ 

 /* 	mymap['x']=1001; */ 
 /* 	mymap['y']=2002; */ 
 /* 	mymap['z']=3003; */ 

 /* 	std::cout << "mymap contains:\n"; */ 

 /* 	NAMESPACE::pair<char,int> highest = *mymap.rbegin();          // last element */ 

 /* 	NAMESPACE::map<char,int>::iterator it = mymap.begin(); */ 
 /* 	do { */ 
 /* 		std::cout << it->first << " => " << it->second << '\n'; */ 
 /* 	} while ( mymap.value_comp()(*it++, highest) ); */
	/* mymap contains: */
/* x => 1001 */
/* y => 2002 */
/* z => 3003 */
 /* } */ 


 /* void find() */ 
 /* { */ 
 /* 	NAMESPACE::map<std::string,int> mymap; */ 
 /* 	NAMESPACE::map<std::string,int>::iterator it; */ 

 /* 	mymap["a"]=50; */ 
 /* 	mymap["b"]=100; */ 
 /* 	mymap["c"]=150; */ 
 /* 	mymap["d"]=200; */ 
/* //	mymap.erase("b"); */
 /* 	it = mymap.find("b"); */ 
 /* 	if (it != mymap.end()) */ 
 /* 		mymap.erase (it); */ 

 /* 	// print content: */ 
 /* 	std::cout << "elements in mymap:" << '\n'; */ 
 /* 	std::cout << "a => " << mymap.find("a")->second << '\n'; */ 
 /* 	std::cout << "c => " << mymap.find("c")->second << '\n'; */ 
 /* 	std::cout << "d => " << mymap.find("d")->second << '\n'; */
	/* elements in mymap: */
/* a => 50 */
/* c => 150 */
/* d => 200 */
 /* } */ 

 /* void count() */ 
 /* { */ 
 /* 	NAMESPACE::map<char,int> mymap; */ 
 /* 	char c; */ 

 /* 	mymap ['a']=101; */ 
 /* 	mymap ['c']=202; */ 
 /* 	mymap ['f']=303; */ 

 /* 	for (c='a'; c<'h'; c++) */ 
 /* 	{ */ 
 /* 		std::cout << c; */ 
 /* 		if (mymap.count(c)>0) */ 
 /* 			std::cout << " is an element of mymap.\n"; */ 
		/* else */ 
 /* 			std::cout << " is not an element of mymap.\n"; */ 
 /* 	} */ 
 /* } */ 

/* void lower_bound()*/ 
/*  {*/ 
/*  	NAMESPACE::map<std::string,int> mymap;*/ 
/*  	NAMESPACE::map<std::string,int>::iterator itlow,itup;*/ 

/*  	mymap["a"]=20;*/ 
/*  	mymap["b"]=40;*/ 
/*  	mymap["c"]=60;*/ 
/*  	mymap["d"]=80;*/ 
/*  	mymap["e"]=100;*/ 

/*  	itlow=mymap.lower_bound ("b");  // itlow points to b*/ 
/*  	itup=mymap.upper_bound ("d");   // itup points to e (not d!)*/ 

/*  //	mymap.erase("b");        // erases [itlow,itup)*/ 
/* //	mymap.printTree();*/
/*  //	mymap.erase("c");        // erases [itlow,itup)*/ 
/* //	mymap.printTree();*/
/*  //	mymap.erase("d");        // erases [itlow,itup)*/ 
/*  	mymap.erase(itlow,itup);        // erases [itlow,itup)*/ 

/*  	// print content:*/ 
/*  	for (NAMESPACE::map<std::string,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)*/ 
/*  		std::cout << it->first << " => " << it->second << '\n';*/ 
/*  }*/ 

/* void upper_bound()*/
/* {*/
/* 	NAMESPACE::map<char,int> mymap;*/
/* 	NAMESPACE::map<char,int>::iterator itlow,itup;*/

/* 	mymap['a']=20;*/
/* 	mymap['b']=40;*/
/* 	mymap['c']=60;*/
/* 	mymap['d']=80;*/
/* 	mymap['e']=100;*/

/* 	itlow=mymap.lower_bound ('b');  // itlow points to b*/
/* 	itup=mymap.upper_bound ('d');   // itup points to e (not d!)*/

/* 	mymap.erase(itlow,itup);        // erases [itlow,itup)*/

/* 	// print content:*/
/* 	for (NAMESPACE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)*/
/* 		std::cout << it->first << " => " << it->second << '\n';*/
/* 	//a => 20*/
/* 	//e => 100*/

/* }*/

/* void equal_range()*/
/* {*/
/* 	NAMESPACE::map<char,int> mymap;*/

/* 	mymap['a']=10;*/
/* 	mymap['b']=20;*/
/* 	mymap['c']=30;*/

/* 	NAMESPACE::pair<NAMESPACE::map<char,int>::iterator,NAMESPACE::map<char,int>::iterator> ret;*/
/* 	ret = mymap.equal_range('b');*/

/* 	std::cout << "lower bound points to: ";*/
/* 	std::cout << ret.first->first << " => " << ret.first->second << '\n';*/

/* 	std::cout << "upper bound points to: ";*/
/* 	std::cout << ret.second->first << " => " << ret.second->second << '\n';*/
/* 	//lower bound points to: 'b' => 20*/
/* 	//upper bound points to: 'c' => 30*/

/* }*/


/* void get_allocator()*/
/* {*/
/* 	int psize;*/
/* 	NAMESPACE::map<char,int> mymap;*/
/* 	NAMESPACE::pair<const char,int>* p;*/

/* 	// allocate an array of 5 elements using mymap's allocator:*/
/* 	p=mymap.get_allocator().allocate(5);*/

/* 	// assign some values to array*/
/* 	psize = sizeof(NAMESPACE::map<char,int>::value_type)*5;*/

/* 	std::cout << "The allocated array has a size of " << psize << " bytes.\n";*/

/* 	mymap.get_allocator().deallocate(p,5);*/
/* 	//The allocated array has a size of 40 bytes.*/

/* }*/

/* template <class MAP>*/
/* void	cmp(const MAP &lhs, const MAP &rhs)*/
/* {*/
/* 	static int i = 0;*/

/* 	std::cout << "############### [" << i++ << "] ###############"  << std::endl;*/
/* 	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;*/
/* 	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;*/
/* 	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;*/
/* }*/

/* void relationnal_ope()*/
/* {*/

/* std::map<char,int> foo,bar;*/
/*   foo['a']=100;*/
/*   foo['b']=200;*/
/*   bar['a']=10;*/
/*   bar['z']=1000;*/

/*   // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):*/
/*   if (foo==bar) std::cout << "foo and bar are equal\n";*/
/*   if (foo!=bar) std::cout << "foo and bar are not equal\n";*/
/*   if (foo< bar) std::cout << "foo is less than bar\n";*/
/*   if (foo> bar) std::cout << "foo is greater than bar\n";*/
/*   if (foo<=bar) std::cout << "foo is less than or equal to bar\n";*/
/*   if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";*/

/*   return ;*/
/*  // foo and bar are not equal*/
/* //foo is greater than bar*/
/* //foo is greater than or equal to bar*/
/* }*/

/* void swap_non_member() */
/* { */
/* 	NAMESPACE::map<char,int> foo,bar; */

/* 	foo['x']=100; */
/* 	foo['y']=200; */

/* 	bar['a']=11; */
/* 	bar['b']=22; */
/* 	bar['c']=33; */

/* 	swap(bar, foo); */

/* 	std::cout << "foo contains:\n"; */
/* 	for (NAMESPACE::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it) */
/* 		std::cout << it->first << " => " << it->second << '\n'; */

/* 	std::cout << "bar contains:\n"; */
/* 	for (NAMESPACE::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it) */
/* 		std::cout << it->first << " => " << it->second << '\n'; */
/* //foo contains: */
/* //a => 11 */
/* //b => 22 */
/* //c => 33 */
/* //bar contains: */
/* //x => 100 */
/* //y => 200 */
/* } */

/* void	testOfHell() { */
/* 	  std::cout << YELLOW << "# test_map" << NC << std::endl; */
/* std::cout << YELLOW <<  "/1* ********************************************************************** *1/" << std::endl; */
/* std::cout << "/1*                          "<< YELLOW << "BASIC TESTS" << YELLOW << "                                   *1/" << std::endl; */
/* std::cout << "/1* ********************************************************************** *1/" << NC << std::endl; */
/* std::cout << std::endl; */


/* NAMESPACE::map<std::string, int> mymap; */
/* 	print(mymap); */


/* std::cout << "mymap<" << PINK << "string" << NC << ", " << PINK << "int" << NC <<"> mymap;" << std::endl; */

/* std::cout << std::endl; */
/* std::cout << "mymap.max_size(): " << (mymap.max_size() > 10000) << std::endl; */
/* 	print(mymap); */
/* std::cout << std::endl; */


/* 	print(mymap); */
/* 	mymap.insert(NAMESPACE::pair<std::string, int>("ft", 42)); */

/* 	print(mymap); */
/* 	mymap.insert(NAMESPACE::pair<std::string, int>("one", 1)); */


/* std::cout << YELLOW << "# testing upper/lower_bound" << NC << std::endl; */
/* 	NAMESPACE::map<std::string, int>::iterator mit; */
/* 	NAMESPACE::map<std::string, int>::iterator it; */
/* 	print(mymap); */
/* 	it = mymap.lower_bound("aaa"); */
/* 	print(mymap); */
/* std::cout << std::setw(40) << "mymap.lower_bound(\"aaa\"): " << it->first << ":" << it->second << std::endl; */
/* std::cout << std::endl; */
/* 	print(mymap); */
/* 	it = mymap.lower_bound("one"); */
/* 	print(mymap); */
/* std::cout << std::setw(40) << "mymap.lower_bound(\"one\"): " << it->first << ":" << it->second << std::endl; */
/* std::cout << std::endl; */
/* 	print(mymap); */
/* 	it = mymap.lower_bound("oae"); */
/* 	print(mymap); */
/* std::cout << std::setw(40) << "mymap.lower_bound(\"oae\"): " << it->first << ":" << it->second << std::endl; */
/* std::cout << std::endl; */
/* 	print(mymap); */
/* 	it = mymap.lower_bound("ft"); */
/* 	print(mymap); */
/* std::cout << std::setw(40) << "mymap.lower_bound(\"ft\"): " << it->first << ":" << it->second << std::endl; */
/* std::cout << std::endl; */
/* 	print(mymap); */
/* 	it = mymap.lower_bound("zzz"); */
/* 	print(mymap); */
	
/* 	if (it == mymap.end()) */
/* 	std::cout << std::setw(40) << "mymap.lower_bound(\"zzz\"): mymap.end()" << std::endl; */
/* std::cout << std::endl; */
/* 	print(mymap); */
/* 	it = mymap.upper_bound("aaa"); */
	
/* 	print(mymap); */
/* std::cout << std::setw(40) << "mymap.upper_bound(\"aaa\"): " << it->first << ":" << it->second << std::endl;; */
/* std::cout << std::endl; */
/* 	print(mymap); */
/* 	it = mymap.upper_bound("oae"); */
/* 	print(mymap); */
/* std::cout << std::setw(40) << "mymap.upper_bound(\"oae\"): " << it->first << ":" << it->second << std::endl;; */
/* std::cout << std::endl; */
/* 	print(mymap); */
/* 	it = mymap.upper_bound("one"); */
	
/* 	if (it == mymap.end()) */
/* 	std::cout << std::setw(40) << "mymap.upper_bound(\"one\"): mymap.end()" << std::endl; */
/* 	print(mymap); */
/* std::cout << std::endl; */
/* 	it = mymap.upper_bound("ft"); */
/* 	print(mymap); */
/* std::cout << std::setw(40) << "mymap.upper_bound(\"ft\"): " << it->first << ":" << it->second << std::endl;; */
/* std::cout << std::endl; */
/* 	print(mymap); */
/* 	it = mymap.upper_bound("zzz"); */
	
/* 	if (it == mymap.end()) */
/* 	std::cout << std::setw(40) << "mymap.upper_bound(\"zzz\"): mymap.end()" << std::endl; */
/* 	print(mymap); */
/* std::cout << std::endl; */

/* 	print(mymap); */
/* 	mymap.erase("undefined"); */
/* 	print(mymap); */
/* 	mymap.erase("ft"); */
/* 	print(mymap); */
/* std::cout << YELLOW << "# double clear" << NC << std::endl; */
/* 	mymap.clear(); */
/* 	print(mymap); */
/* 	mymap.clear(); */
/* 	print(mymap); */
/* 	mymap["lol"]; */
/* 	print(mymap); */
	/* mymap.insert(NAMESPACE::pair<std::string, int>("xD", 123)); */
/* /1* 	print(mymap); *1/ */
	/* mymap.insert(mymap.end(), NAMESPACE::pair<std::string, int>("uch", 442)); */
/* /1* 	print(mymap); *1/ */
/* /1* 	mymap.insert(mymap.begin(), NAMESPACE::pair<std::string, int>("uch", 22)); *1/ */
/* /1* 	print(mymap); *1/ */
/* /1* 	mymap.insert(mymap.end(), NAMESPACE::pair<std::string, int>("uch", 23)); *1/ */
/* /1* 	print(mymap); *1/ */
/* /1* 	mymap.insert(NAMESPACE::pair<std::string, int>("uch", 23)); *1/ */
/* /1* 	print(mymap); *1/ */
	/* mymap["lol"] = 8; */


	/* print(mymap); */
	/* NAMESPACE::map<std::string, int> map2; */

/* std::cout << REDC << __LINE__ << NC << std::endl; */
	/* print(mymap); */
/* std::cout << REDC << __LINE__ << NC << std::endl; */
	/* print(map2); */
/* std::cout << "mymap<" << PINK << "string" << NC << ", " << PINK << "int" << NC <<"> mymap2;" << std::endl; */
	/* print(mymap); */
/* std::cout << "empty line\n"; */
	/* print(map2); */
/* std::cout << "empty line2\n"; */

	/* swap(mymap, map2); */
/* std::cout << "empty line3\n"; */
	/* print(mymap); */
/* std::cout << "empty line4\n"; */
	/* print(map2); */
/* std::cout << "empty line5\n"; */
/* std::cout << REDC << __LINE__ << NC << std::endl; */
	/* mymap = map2; */
/* std::cout << __LINE__ << std::endl; */
	/* print(mymap); */
/* std::cout << __LINE__ << std::endl; */
	/* print(map2); */
/* std::cout << __LINE__ << std::endl; */

/* std::cout << std::setw(40) << "map == map2: " << (mymap == map2) << std::endl; */
	/* print(mymap); */
	/* print(map2); */
/* std::cout << std::endl; */

	/* mymap.clear(); */
	/* print(mymap); */
	/* print(map2); */

/* std::cout << REDC << __LINE__ << NC << std::endl; */
	/* mymap["satan"] = 666; */
/* std::cout << REDC << __LINE__ << NC << std::endl; */
	/* print(mymap); */
	/* print(map2); */
/* std::cout << std::setw(40) << "mymap == map2: " << (mymap == map2) << std::endl; */
	/* print(mymap); */
	/* print(map2); */
/* std::cout << std::endl; */
/* std::cout << std::setw(40) << "mymap <= map2: " << (mymap <= map2) << std::endl; */
	/* print(mymap); */
	/* print(map2); */
/* std::cout << std::endl; */
/* std::cout << std::setw(40) << "mymap >= map2: " << (mymap >= map2) << std::endl; */
	/* print(mymap); */
	/* print(map2); */
/* std::cout << std::endl; */
/* std::cout << std::setw(40) << "mymap > map2: " << (mymap > map2) << std::endl; */
	/* print(mymap); */
	/* print(map2); */
/* std::cout << std::endl; */
/* std::cout << std::setw(40) << "mymap < map2: " << (mymap > map2) << std::endl; */
	/* print(mymap); */
	/* print(map2); */
/* std::cout << std::endl; */
/* } */

/* void toto() { */
	/* NAMESPACE::map<std::string, int> map1; */
	/* map1["a"] = 45; */
	/* map1["b"] = 46; */
	/* map1["c"] = 47; */
	/* map1["d"] = 48; */
	/* NAMESPACE::map<std::string, int> map2; */
	/* std::cout << "map 1" << std::endl; */
	/* print(map1); */
	/* std::cout << "map 2" << std::endl; */
	/* print(map2); */
	/* std::cout << "------" << std::endl; */
	/* map2 = map1; */
	/* std::cout << "map 1" << std::endl; */
	/* print(map1); */
	/* std::cout << "map 2" << std::endl; */
	/* print(map2); */
/* } */

/* static int iter = 0; */

/* /1* template <typename MAP> *1/ */
/* void	ft_erase(NAMESPACE::map<std::string, std::string> &mp, std::string param) */
/* { */
/* 	std::cout << "\t-- [" << iter++ << "] --"<<  " try to delete: " <<param << std::endl; */
/* 	/1* mp.printTree(); *1/ */
/* 	mp.erase(param); */
/* 	std::cout << __LINE__ << std::endl; */
/* 	/1* mp.printTree(); *1/ */
/* } */

/* #define T1 int */
/* #define T2 std::string */
/* typedef NAMESPACE::pair<const T1, T2> T3; */

/* static int iter = 0; */

/* template <typename MAP, typename U> */
/* void	ft_erase(MAP &mp, U param) */
/* { */
/* 	std::cout << "\t-- [" << iter++ << "] --" << std::endl; */
/* 	mp.erase(param); */
/* 	printSize(mp); */
/* } */

/* template <typename MAP, typename U, typename V> */
/* void	ft_erase(MAP &mp, U param, V param2) */
/* { */
/* 	std::cout << "\t-- [" << iter++ << "] --" << std::endl; */
/* 	mp.erase(param, param2); */
/* 	printSize(mp); */
/* } */

#define T1 std::string
#define T2 std::string

struct ft_more {
	bool	operator()(const T1 &lhs, const T1 &rhs) const {
	/* std::cout << "COMPARE " << lhs << " vs " << rhs << " result : " << (lhs < rhs) << std::endl; */
		return (lhs < rhs);
	}
};

typedef NAMESPACE::map<T1, T2, ft_more> ft_mp;
typedef NAMESPACE::map<T1, T2, ft_more>::iterator ft_mp_it;

int		main(void)
{
	ft_mp mp;

	mp["42"] = "fgzgxfn";
	mp["25"] = "funny";
	mp["80"] = "hey";
	mp["12"] = "no";
	mp["27"] = "bee";
	mp["90"] = "8";
	printSize(mp);
	/* mp.printTree(); */

	return (0);
}
/* int		main(void) */
/* { */
/* 	NAMESPACE::map<std::string, std::string> mp; */

/* 	mp["42"] = "lol"; */

/* 	mp["50"] = "mdr"; */
/* 	mp["25"] = "funny"; */

/* 	mp["46"] = "bunny"; */
/* 	mp["21"] = "fizz"; */
/* 	mp["30"] = "buzz"; */
/* 	mp["55"] = "fuzzy"; */

/* 	mp["18"] = "bee"; */
/* 	mp["23"] = "coconut"; */
/* 	mp["28"] = "diary"; */
/* 	mp["35"] = "fiesta"; */
/* 	mp["44"] = "hello"; */
/* 	mp["48"] = "world"; */
/* 	mp["53"] = "this is a test"; */
/* 	mp["80"] = "hey"; */

/* 	mp["12"] = "no"; */
/* 	mp["20"] = "idea"; */
/* 	mp["22"] = "123"; */
/* 	mp["24"] = "345"; */
/* 	mp["27"] = "27"; */
/* 	mp["29"] = "29"; */
/* 	mp["33"] = "33"; */
/* 	mp["38"] = "38"; */

/* 	mp["43"] = "1"; */
/* 	mp["45"] = "2"; */
/* 	mp["47"] = "3"; */
/* 	mp["49"] = "4"; */
/* 	mp["51"] = "5"; */
/* 	mp["54"] = "6"; */
/* 	mp["60"] = "7"; */
/* 	mp["90"] = "8"; */

/* 	std::cout << "LALALALA" << __LINE__ << std::endl; */
/* 	/1* A classic btree should give this: */
/* 	*                                      42 */
/* 	*                     /                                            \ */
/* 	*                    25                                            50 */
/* 	*           /                 \                         /                       \ */
/* 	*          21                 30                       46                       55 */
/* 	*      /       \           /      \                /       \             /           \ */
/* 	*     18       23        28        35            44         48         53             80 */
/* 	*   /   \    /    \    /    \     /   \        /   \       /   \     /    \         /     \ */
/* 	*  12   20  22    24  27    29  33    38     43    45    47    49   51    54       60      90 */
/* 	* */
/* 	* *1/ */

/* 	ft_erase(mp, "25"); // right != NULL; left != NULL */
/* 	ft_erase(mp, "55"); // right != NULL; left != NULL */

/* 	/1* After deleting 25 and 55, I would get: */
/* 	*                                      42 */
/* 	*                     /                                            \ */
/* 	*                    24                                            50 */
/* 	*           /                 \                         /                      \ */
/* 	*          21                 30                       46                      54 */
/* 	*      /       \           /      \                /       \             /           \ */
/* 	*     18       23        28        35            44         48         53             80 */
/* 	*   /   \    /         /    \     /   \        /   \       /   \     /              /     \ */
/* 	*  12   20  22        27    29  33    38     43    45    47    49   51             60      90 */
/* 	* */
/* 	* *1/ */

/* 	ft_erase(mp, "24"); // right != NULL; left != NULL */
/* 	ft_erase(mp, "54"); // right != NULL; left != NULL */

/* 	/1* After deleting 24 and 54, I would get: */
/* 	*                                      42 */
/* 	*                     /                                            \ */
/* 	*                    23                                            50 */
/* 	*           /                 \                         /                      \ */
/* 	*          21                 30                       46                      53 */
/* 	*      /       \           /      \                /       \             /           \ */
/* 	*     18       22        28        35            44         48         51             80 */
/* 	*   /   \              /    \     /   \        /   \       /   \                    /     \ */
/* 	*  12   20            27    29  33    38     43    45    47    49                  60      90 */
/* 	* */
/* 	* *1/ */

/* 	ft_erase(mp, "22"); // right == NULL; left == NULL */
/* 	ft_erase(mp, "51"); // right == NULL; left == NULL */

/* 	ft_erase(mp, "21"); // right == NULL; left != NULL */
/* 	ft_erase(mp, "53"); // right != NULL; left == NULL */

/* 	/1* After deleting 22, 51 and then 21, 53, I would get: */
/* 	*                                      42 */
/* 	*                     /                                            \ */
/* 	*                    23                                            50 */
/* 	*           /                 \                         /                      \ */
/* 	*          20                 30                       46                      80 */
/* 	*      /                   /      \                /       \                /        \ */
/* 	*     18                 28        35            44         48             60         90 */
/* 	*   /                  /    \     /   \        /   \       /   \ */
/* 	*  12                 27    29  33    38     43    45    47    49 */
/* 	* */
/* 	* *1/ */

/* 	ft_erase(mp, "20"); // right == NULL; left != NULL */

/* 	/1* After deleting 20, I would get: */
/* 	*                                      42 */
/* 	*                     /                                            \ */
/* 	*                    23                                            50 */
/* 	*           /                 \                         /                      \ */
/* 	*          18                 30                       46                      80 */
/* 	*      /                   /      \                /       \                /        \ */
/* 	*     12                 28        35            44         48             60         90 */
/* 	*                      /    \     /   \        /   \       /   \ */
/* 	*                     27    29  33    38     43    45    47    49 */
/* 	* */
/* 	* *1/ */

/* 	ft_erase(mp, "23"); // right != NULL; left != NULL */

/* 	/1* After deleting 23, I would get: */
/* 	*                                      42 */
/* 	*                     /                                            \ */
/* 	*                    18                                            50 */
/* 	*           /                 \                         /                      \ */
/* 	*          12                 30                       46                      80 */
/* 	*                          /      \                /       \                /        \ */
/* 	*                        28        35            44         48             60         90 */
/* 	*                      /    \     /   \        /   \       /   \ */
/* 	*                     27    29  33    38     43    45    47    49 */
/* 	* */
/* 	* *1/ */

/* 	ft_erase(mp, "42"); // right != NULL; left != NULL; parent == NULL */

/* 	/1* After deleting 42, I would get: */
/* 	*                                      38 */
/* 	*                     /                                            \ */
/* 	*                    18                                            50 */
/* 	*           /                 \                         /                      \ */
/* 	*          12                 30                       46                      80 */
/* 	*                          /      \                /       \                /        \ */
/* 	*                        28        35            44         48             60         90 */
/* 	*                      /    \     /            /   \       /   \ */
/* 	*                     27    29  33           43    45    47    49 */
/* 	* */
/* 	* *1/ */

/* 	ft_erase(mp, "38"); // right != NULL; left != NULL; parent == NULL */

/* 	/1* After deleting 38, I would get: */
/* 	*                                      35 */
/* 	*                     /                                            \ */
/* 	*                    18                                            50 */
/* 	*           /                 \                         /                      \ */
/* 	*          12                 30                       46                      80 */
/* 	*                          /      \                /       \                /        \ */
/* 	*                        28        33            44         48             60         90 */
/* 	*                      /    \                  /   \       /   \ */
/* 	*                     27    29               43    45    47    49 */
/* 	* */
/* 	* *1/ */

/* 	ft_erase(mp, "35"); // right != NULL; left != NULL; parent == NULL */

/* 	/1* After deleting 35, I would get: */
/* 	*                                      33 */
/* 	*                     /                                            \ */
/* 	*                    18                                            50 */
/* 	*           /                 \                         /                      \ */
/* 	*          12                 30                       46                      80 */
/* 	*                          /                       /       \                /        \ */
/* 	*                        28                      44         48             60         90 */
/* 	*                      /    \                  /   \       /   \ */
/* 	*                     27    29               43    45    47    49 */
/* 	* */
/* 	* *1/ */

/* 	ft_erase(mp, "33"); // right != NULL; left != NULL; parent == NULL */

/* 	/1* After deleting 33, I would get: */
/* 	*                                      30 */
/* 	*                     /                                            \ */
/* 	*                    18                                            50 */
/* 	*           /                 \                         /                      \ */
/* 	*          12                 28                       46                      80 */
/* 	*                          /      \                /       \                /        \ */
/* 	*                        27       29             44         48             60         90 */
/* 	*                                              /   \       /   \ */
/* 	*                                            43    45    47    49 */
/* 	* */
/* 	* *1/ */

/* 	return (0); */
/* } */

/* int main3() */
/* { */
/* 	toto(); */
/* 	testOfHell(); */
/* //	constructor(); */
/*    //     operator_equal(); // operator = */ 

/* //	 begin(); */ 
/* //	 end(); */ 
/* //	 rbegin(); */ 
/* //	 rend(); */ 
/* // */
/* //	 empty(); */ 
/* //	 size(); */ 
/* //	 max_size(); */ 

/* //	 operator_hook(); // operator [] */ 
/* // */
/* //	 insert(); */ 
/* //	swap(); */ 
/* //	 clear(); */ 

/* //	key_comp(); */ 
/* //	value_comp(); */
/* //	 erase(); */ 

/* //	find(); */ 
/* //	 count(); */ 
/* //	lower_bound(); */ 
/* //	upper_bound(); */
/* //	equal_range(); */

/* //	get_allocator(); */

/* //	relationnal_ope(); */
/* //	swap_non_member(); */

/* //	 iterator_validity(); */
/* 	return 0; */ 

/* } */
