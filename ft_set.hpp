/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:23:38 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/30 16:47:07 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include <memory>
# include "ft_rbt_iterator.hpp"
# include "ft_tree.hpp"

namespace ft
{
	template< class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> >
	class set
	{
		public:
			typedef Key												key_type;
			typedef Key												value_type;
			typedef std::size_t										size_type;
			typedef std::ptrdiff_t									difference_type;
			typedef Compare											key_compare;
			typedef Compare											value_compare;
			typedef Allocator										allocator_type;
			typedef value_type &									reference;
			typedef const value_type &								const_reference;
			typedef typename Allocator::pointer						pointer;
			typedef typename Allocator::const_pointer				const_pointer;
			// typedef RBTreeIterator<value_type>					iterator;
		private:
			typedef ft::RBTree< value_type, value_compare, allocator_type>		tree_type;
		
		public:
			typedef RBTreeIterator<typename tree_type::node>		iterator;
			typedef const_RBTreeIterator<typename tree_type::node>	const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

		private:
			tree_type tree;
		
		public:
		///CONSTRUCITON///
		///Default
		set(void) : tree(value_compare(), allocator_type()) {};
		
		///Compare
		explicit set(const Compare& comp, const Allocator& alloc = Allocator()) : tree(comp, alloc) {};
		
		///Copy
		set(const set &other) : tree(other.tree) {};
		
		///Range TBD
		// template< class InputIt >
		// set(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
		// {
		// 	// insert(first, last);
		// };

		///Assignment operator TBD
		
		///Deconstruct TBD

		///ITERATORS///
		iterator begin(void)
		{
			if (tree.size())
				return(tree.begin());
			else
				return(tree.end());
		}
		
		iterator end(void)
		{
			return (tree.end());
		}

		reverse_iterator rbegin(void)
		{
			return (tree.end());
		}

		reverse_iterator rend(void)
		{
			return (tree.begin());
		}
		
		///CAPACITY///
		bool empty() const {return tree.empty();};
		size_type size() const {return tree.size();};
		size_type max_size() const {return tree.max_size();};
		
		///LOOKUP///
		size_type count( const Key& key ) const
		{
			if (tree.find(key) == tree.getNil())
				return (0);
			return (1);
		};
		
		iterator find(const Key& key) {return tree.find(key);};
		const_iterator find(const Key& key) const {return tree.find(key);};
		iterator lower_bound (const Key& key)
		{
			iterator it = begin();
			iterator end = end();
			while(it != end && key_comp()(*it, key))
				it++;
			return (it);
		}
		const_iterator lower_bound(const Key& key) const
		{
			const_iterator it = begin();
			const_iterator end = end();
			while(it != end && key_comp()(*it, key))
				it++;
			return (it);
		}

		iterator upper_bound (const key_type& key)
		{
			iterator it = tree.begin();
			iterator end = tree.end();
			while(it != end && !key_comp()(key, it->first))
				it++;
			return (it);
		}

		const_iterator upper_bound (const key_type& key) const
		{
			const_iterator it = tree.begin();
			const_iterator end = tree.end();
			while(it != end && !key_comp()(key, it->first))
				it++;
			return (it);
		}

		pair<iterator,iterator> equal_range (const key_type& key)
		{
			return (ft::make_pair(lower_bound(key), upper_bound(key)));
		}

		pair<const_iterator,const_iterator> equal_range (const key_type& key) const
		{
			return (ft::make_pair(lower_bound(key), upper_bound(key)));
		}
		///MODIFIERS///

		ft::pair<iterator,bool> insert( const value_type& value )
		{
			if (tree.find(value) == tree.getNil())
				return ft::make_pair(iterator(insert(0, value)), true);
			return ft::make_pair(iterator(insert(0, value)), false);
		};

		iterator insert(iterator hint, const value_type& value)
		{
			return tree.insert(value);
		};

		// template< class InputIt >
		// void insert( InputIt first, InputIt last, typename ft::enable_if<!is_integral<InputIt>::value>::type* = nullptr  )
		// {
		// 	while(first != last)
		// 	{
		// 		tree.insert(*first);
		// 		first++;
		// 	}
		// }

		// iterator erase( iterator pos );
		// iterator erase( iterator first, iterator last );
		// size_type erase( const Key& key )
		// {
		// 	return(t)
		// }
		
		void swap (set& x)
		{
			tree_type temp_tree = x.tree;
			x.tree = tree;
			tree = temp_tree;
		}

		///OBSERVERS///
		key_compare key_comp(void) const {tree.getComp();};
		value_compare value_comp(void) const {tree.getComp();};

	};
}
#endif //SET_HPP