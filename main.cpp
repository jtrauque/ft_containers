#include <iostream>
#include "test_vector.hpp"
#include "test_map.hpp"
#include "test_stack.hpp"

#define NC "\e[0m"
#define YELLOW "\e[0;33m"

int	main() {
	std::cout << YELLOW << "-------------------------------VECTOR---------------------------------" << NC << std::endl;
	test_vector();	
	std::cout << YELLOW << "-------------------------------STACK---------------------------------" << NC << std::endl;
	test_stack();	
	std::cout << YELLOW << "-------------------------------MAP---------------------------------" << NC << std::endl;
	test_map();	
}
