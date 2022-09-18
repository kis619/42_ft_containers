/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:19:53 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/17 23:46:31 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP
#include <stdint.h>

namespace ft
{
	
	template< bool B, class T = void >
	struct enable_if {};

	template<class T> //partial template specialisation
	struct enable_if<true, T> { typedef T type; };

	template< class T, T v >
	struct integral_constant
	{
		static const T value = v;
		typedef T value_type;
		typedef integral_constant<T, v> type;
		operator T() { return v; }
	};
	
	
	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;
	
	template< class T >
	struct is_integral : false_type{};

	template <> struct is_integral<int> : true_type {};
	template <> struct is_integral<char> : true_type {};
	template <> struct is_integral<char16_t> : true_type {};
	template <> struct is_integral<char32_t> : true_type {};
	template <> struct is_integral<wchar_t> : true_type {};
	template <> struct is_integral<signed char> : true_type {};
	template <> struct is_integral<short int> : true_type {};
	template <> struct is_integral<bool> : true_type{};
	template <> struct is_integral<long int> : true_type {};
	template <> struct is_integral<long long int> : true_type {};
	template <> struct is_integral<unsigned char> : true_type {};
	template <> struct is_integral<unsigned short int> : true_type {};
	template <> struct is_integral<unsigned int> : true_type {};
	template <> struct is_integral<unsigned long int> : true_type {};
	template <> struct is_integral<unsigned long long int> : true_type {};

	template<class InputIt1, class InputIt2>
	bool equal( InputIt1 first1, InputIt1 last1, 
				InputIt2 first2)
	{
		for (; first1 != last1; ++first1, ++first2) 
		{
			if (!(*first1 == *first2))
			{
				return false;
			}
		}
		return true;
	}

	//Checks if the first range [first1, last1) is lexicographically less than the second range [first2, last2).
	template< class InputIt1, class InputIt2 >
	bool lexicographical_compare(	InputIt1 first1, InputIt1 last1,
									InputIt2 first2, InputIt2 last2 )
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	};

	template< typename T1, typename T2 >
	struct pair
	{
		T1	first;
		T2	second;
		
		pair(void) : first(), second() {};
		//copy constructor
		template<class U, class V>
		pair (const pair<U,V> &pr) : first(pr.first), second(pr.second) {}
		//initialising constructor
		pair(const T1 &x, const T2 &y) : first(x), second(y) {};
		//assignment operator
		pair &operator=( const pair &other )
		{
			first = other.first;
			second = other.second;
			
			// new (this) pair(other.first, other.second); //placement new operator
			return (*this);
		}
		
	};
	
	template< class T1, class T2 >
	bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		if (lhs.first == rhs.first && lhs.second == rhs.second)
			return (true);
		return (false);
	}

	template< class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
		{return(!(lhs==rhs));}
	
	template< class T1, class T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		if (lhs.first<rhs.first)
			return (true);
		if (rhs.first<lhs.first)
			return (false);
		if (lhs.second<rhs.second)
			return (true);
		return (false);
	}
	
	template< class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
		{return(!(rhs < lhs));}
	
	template< class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
		{return(rhs < lhs);}
	
	template< class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
		{return (!(lhs < rhs));}

	template< class T1, class T2 >
	pair<T1,T2> make_pair( T1 x, T2 y )
	{
		return pair<T1,T2>(x ,y);
	}
	
}
#endif