/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:01:26 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/05 12:34:53 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <utility>
#include <memory>
#include "ft_utils.hpp"
#include "ft_tree.hpp"
#include <stdexcept>
#include "tests/colours.h"
#include "ft_rbt_iterator.hpp"

namespace ft
{
	template <	class Key, class T, class Compare = std::less<Key>,
				class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<const Key, T>							value_type;
			typedef Compare											key_compare;
			typedef Allocator										allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename allocator_type::size_type				size_type;
			typedef typename allocator_type::difference_type		difference_type;
			typedef RBTreeIterator<value_type>						iterator;
		
		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class map;

			public: //should be protected
				key_compare comp;
				value_compare(key_compare c) : comp(c) {}
			public:
				bool operator()(const value_type &lhs, const value_type &rhs) const
					{return comp(lhs.first, rhs.first);}
		};
		
		// map(void);
		explicit map (const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : tree(comp, alloc)
		{};

		private:
			typedef ft::RBTree< value_type, value_compare, allocator_type>		tree_type;

		public: //should be private
			tree_type	tree;

		size_type erase(key_type key)
		{
			return(tree.erase_unique(key));
		}
		
		allocator_type get_allocator(void) const
		{
			return (tree.get_allocator());
		}

		///Element access
		mapped_type at(const Key &key)
		{
			mapped_type val = tree.find_by_only_key(key).first;
			if (val)
				return (val);
			throw std::out_of_range("key not found");
		}

		iterator test()
		{
			return(tree.test());
		}
	};
};
#endif //MAP_HPP