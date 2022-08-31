/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:01:26 by kmilchev          #+#    #+#             */
/*   Updated: 2022/08/31 23:07:11 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include <utility>
#include <memory>

namespace ft
{
	template <	class Key, class T, class Compare = std::less<Key>,
				class Allocator = std::allocator<std::pair<const Key, T> > >
	class map
	{
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef std::pair<const key_type, mapped_type>			value_type; //need to implement pair myself //so no std..
			typedef Compare											key_compare;
			typedef Allocator										allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename allocator_type::size_type				size_type;
			typedef typename allocator_type::difference_type		difference_type;

		
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map;

			protected:
				key_compare comp;
				value_compare(key_compare c) : comp(c) {}
			public:
				bool operator()(const value_type &lhs, const value_type &rhs) const
					{return comp(lhs.first, rhs.second);}
		};
		
		explicit map (	const key_compare &comp = key_compare(),
						const allocator_type &alloc = allocator_type()); 
	};
};