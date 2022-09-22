/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:01:26 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/22 14:44:33 by kmilchev         ###   ########.fr       */
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
#include "ft_reverse_iterator.hpp"
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
	
	explicit map (const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : tree(comp, alloc) {};
	map (const map& x) : tree(x.value_comp(), x.get_allocator())
	{
		*this = x;
	}
	template <class InputIterator>
	map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : tree(comp, alloc)
	{
		
		while(first != last)
		{
			tree.insert(*(first.getPtr()->value));
			first++;
		}
	}
	
	map &operator=(const map& other)
	{
		// std::cout << "here\n";
		clear();
		const_iterator it_begin = other.begin();
		const_iterator it_end = other.end();
		while(it_begin != it_end)
		{
			// std::cout << COLOUR_GREEN << "Value: " << (*(it_begin.getPtr()->value)).first << COLOUR_DEFAULT<< std::endl;
			tree.insert(*(it_begin.getPtr()->value));
			it_begin++;
		}
		return(*this);
	}
	
	~map(void)
	{
		clear();
		tree.deallocateNil();
	}
	private:
		typedef ft::RBTree< value_type, value_compare, allocator_type>		tree_type;

	public:
		typedef RBTreeIterator<typename tree_type::node>					iterator;
		typedef const_RBTreeIterator<typename tree_type::node>				const_iterator;
		typedef ft::reverse_iterator<iterator>								reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
		
	public: //should be private
		tree_type	tree;


	///Alocator
	allocator_type get_allocator(void) const
	{
		return (tree.get_allocator());
	}

	///Element access
	mapped_type at(const Key &key)
	{
		typename tree_type::node_ptr n = tree.find_by_only_key(key);
		if (n != tree.getNil())
			return(n->value->second);
		throw std::out_of_range("key not found");
	}

	mapped_type &operator[](const Key &key)
	{
		typename tree_type::node_ptr n = tree.find_by_only_key(key);
		if (n == tree.getNil())
			insert(ft::make_pair(key, T()));
			// return insert(ft::make_pair(key, T())).first->second;
		n = tree.find_by_only_key(key);
		return (n->value->second);
	}
	
	///Iterators
	iterator begin(void)
	{
		if (tree.size())
			return(tree.begin());
		else
			return(tree.end());
	}

	iterator end(void)
	{
		return(tree.end());
	}

	const_iterator begin(void) const
	{
		return const_iterator(tree.begin());
	}

	const_iterator end(void) const
	{
		return const_iterator(tree.end());
	}

	///Reverse iterators
	reverse_iterator rbegin(void)
	{
		return reverse_iterator(tree.end());
	}

	const_reverse_iterator rbegin(void) const
	{
		return const_reverse_iterator(tree.end());
	}

	reverse_iterator rend(void)
	{
		return reverse_iterator(tree.begin());
	}

	const_reverse_iterator rend(void) const
	{
		return const_reverse_iterator(tree.begin());
	}

	
	///Capacity
	bool empty(void) const
	{
		//return (begin() == end());
		return(tree.empty());
	}

	size_type size(void) const
	{
		return(tree.size());
	}

	size_type max_size(void) const
	{
		return(tree.max_size());
	}

	///Modifiers
	void clear(void)
	{
		erase(tree.begin(), tree.end());
		// iterator it_begin = this->begin();
		// iterator it_end = this->end();
		// while(it_begin != it_end)
		// {
		// 	tree.erase(*(it_begin.getPtr()->value));
		// 	it_begin = begin();
		// }
	}

	void swap (map& x)
	{
		tree_type temp_tree = x.tree;
		x.tree = tree;
		tree = temp_tree;
	}
	
	///Insert
	pair<iterator, bool> insert( const value_type& value )
	{
		typename tree_type::node_ptr n = tree.find(value);
		if (n == tree.getNil())
			return(ft::make_pair(tree.insert(value), true));
		return(ft::make_pair(tree.insert(value), false));
	}
	
	iterator insert (iterator position, const value_type& value)
	{
		return (tree.insert(value)); //maybe do this one
	}

	template< class InputIt >
	void insert( InputIt first, InputIt last, typename enable_if<!is_integral<InputIt>::value>::type* = nullptr )
	{
		for (; first != last; first++)
			tree.insert(*(first.getPtr()->value));
	}

	///Erase
	size_type erase(key_type key)
	{
		return(tree.erase_unique(key));
	}

	void erase( iterator pos )
	{
		tree.erase(*(pos.getPtr()->value));
	}

	void erase( iterator first, iterator last )
	{
		iterator temp = first;
		while(first != last)
		{
			first++;
			tree.erase(*(temp.getPtr()->value));
			temp = first;
		}
	}

	///Observers
	value_compare value_comp() const
	{
		return value_compare(tree.getComp());
	}
	
	key_compare key_comp() const
	{
		return (tree.getComp().comp);
	}

	///Lookup
	size_type count( const Key& key ) const
	{
		if (tree.find_by_only_key(key) == tree.getNil())
			return (0);
		return (1);
	}

	iterator find (const key_type& key)
	{
		return (tree.find_iterator(key));
	}

	const_iterator find (const key_type& key) const
	{
		return (tree.find_iterator(key));
	}

	iterator lower_bound (const key_type& key)
	{
		iterator it = tree.begin();
		iterator end = tree.end();
		while(it != end && key_comp()(it->first, key))
			it++;
		return (it);
	}

	const_iterator lower_bound (const key_type& key) const
	{
		const_iterator it = tree.begin();
		const_iterator end = tree.end();
		while(it != end && key_comp()(it->first, key))
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
};

	template <class Key, class T, class Compare, class Allocator>
	bool operator ==(	const map<Key, T, Compare, Allocator>& x,
						const map<Key, T, Compare, Allocator>& y)
	{
		return(x.size() == y.size() && equal(x.begin(), x.end(), y.begin()));
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator !=(	const map<Key, T, Compare, Allocator>& x,
						const map<Key, T, Compare, Allocator>& y)
	{
		return!(x == y);
	}
	
	template <class Key, class T, class Compare, class Allocator>
	bool operator <(	const map<Key, T, Compare, Allocator>& x,
						const map<Key, T, Compare, Allocator>& y)
	{
		return(ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
	}
	
	template <class Key, class T, class Compare, class Allocator>
	bool operator >(	const map<Key, T, Compare, Allocator>& x,
						const map<Key, T, Compare, Allocator>& y)
	{
		return(y < x);
	}
	
	template <class Key, class T, class Compare, class Allocator>
	bool operator >=(	const map<Key, T, Compare, Allocator>& x,
						const map<Key, T, Compare, Allocator>& y)
	{
		return !(x < y);
	}
	
	template <class Key, class T, class Compare, class Allocator>
	bool operator <=(	const map<Key, T, Compare, Allocator>& x,
						const map<Key, T, Compare, Allocator>& y)
	{
		return !(y < x);
	}
	
};	
#endif //MAP_HPP



// 'ft::RBTree<ft::pair<const int, int>, ft::map<int, int, std::__1::less<int>, std::__1::allocator<ft::pair<const int, int> > >::value_compare, std::__1::allocator<ft::pair<const int, int> > >::node_ptr'
// 'ft::map<int, int, std::__1::less<int>, std::__1::allocator<ft::pair<const int, int> > >::iterator' 


// ft::RBTree<ft::pair<const int, int>, ft::map<int, int, std::__1::less<int>, std::__1::allocator<ft::pair<const int, int> > >::value_compare, std::__1::allocator<ft::pair<const int, int> > >::Node

// RBTreeIterator<ft::RBTree<ft::pair<const int, int>, ft::map<int, int,
// std::__1::less<int>, std::__1::allocator<ft::pair<const int, int> > >::value_compare, std::__1::allocator<ft::pair<const int, int> > >::Node>
