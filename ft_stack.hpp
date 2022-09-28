/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 07:20:26 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/28 10:09:37 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK
# define FT_STACK
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
			stack(const stack & other) : c(other.c) {}
		
		///Element Access
		reference top(void) {return c.back();}
		const_reference top(void) const {return c.back();}

		///Capacity
		bool empty(void) {return c.empty();}
		size_type size(void) {return c.size();}

		///Modifiers
		void push(const value_type &val) {c.push_back(val);}
		void pop(void) {c.pop_back();}
	};
}


#endif //FT_STACK
