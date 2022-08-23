/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:19:53 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/23 23:02:20 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}