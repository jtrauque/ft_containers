#ifndef MAP_UTILS_HPP
#define MAP_UTILS_HPP

namespace	ft {
	//https://en.cppreference.com/w/cpp/utility/functional/less
	template<class T>
		struct	less {
			typedef bool result_type;
			typedef	T	first_argument_type;
			typedef	T	second_argument_type;

			bool	operator() (const T& lhs, const T& rhs) const { return lhs < rhs; }
		};

	//https://en.cppreference.com/w/cpp/utility/pair
	template<class T1, class T2>
		struct	pair {
			//Member types
			typedef	T1 first_type;
			typedef	T2 second_type;

			//Member objects
			first_type first;
			second_type second;
			
			//https://en.cppreference.com/w/cpp/utility/pair/pair
			pair(void) : first(), second() {}
			template<class U1, class U2>
				pair(pair<U1, U2> const &p) : first(p.first), second(p.second) {}
			pair(first_type const &x, second_type const &y) : first(x), second(y) {}
			~pair(void) {}

			pair	&operator=(pair	const &other) {
				first = other.first;
				second = other.second;
				return *this;
			}
		};

	//https://en.cppreference.com/w/cpp/utility/pair/operator_cmp
	template<class T1, class T2>
		bool	operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); }
	template<class T1, class T2>
		bool	operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (!(lhs == rhs)); }
	template<class T1, class T2>
		bool	operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (lhs.first < rhs.first ||
				(!(rhs.first < lhs.first) && lhs.second < rhs.second)); }
	template<class T1, class T2>
		bool	operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (!(rhs < lhs)); }
	template<class T1, class T2>
		bool	operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (rhs < lhs); }
	template<class T1, class T2>
		bool	operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) { return (!(lhs < rhs)); }
	
	template<class T1, class T2>
		pair<T1, T2>	make_pair(T1 x, T2 y) { return (pair<T1, T2>(x, y)); }
}

#endif
