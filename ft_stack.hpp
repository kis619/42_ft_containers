/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 07:20:26 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/28 10:33:13 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_stack
# define FT_stack
# include "ft_vector.hpp"
namespace ft
{
	template< class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container 						container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;
		
		protected:
			Container	c;
		
		public:
			explicit stack(const Container & cont = Container()) : c(cont) {}
			stack(const stack & copy) : c(copy.c) {}
			~stack() {}
			stack &operator=(const stack &other) {c = other.c; return(*this);}
		///Element Access
		reference top(void) {return c.back();}
		const_reference top(void) const {return c.back();}

		///Capacity
		bool empty(void) {return c.empty();}
		size_type size(void) {return c.size();}

		///Modifiers
		void push(const value_type &val) {c.push_back(val);}
		void pop(void) {c.pop_back();}

		///Logical operators
		friend bool operator==(const stack &lhs, const stack &rhs) 				{ return lhs.c == rhs.c; };
		friend bool operator!=(const stack &lhs, const stack &rhs) 				{ return lhs.c != rhs.c; };
		friend bool operator<=(const stack &lhs, const stack &rhs) 				{ return lhs.c <= rhs.c; };
		friend bool operator>=(const stack &lhs, const stack &rhs) 				{ return lhs.c >= rhs.c; };
		friend bool operator<(const stack &lhs, const stack &rhs) 				{ return lhs.c < rhs.c; };
		friend bool operator>(const stack &lhs, const stack &rhs) 				{ return lhs.c > rhs.c; };
	};
}


#endif //FT_stack
