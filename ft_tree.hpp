/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmilchev <kmilchev@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 09:27:27 by kmilchev          #+#    #+#             */
/*   Updated: 2022/09/04 17:31:44 by kmilchev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# define RED true
# define BLACK false
# include "ft_utils.hpp"

namespace ft
{
template <class T,  class Compare, class Allocator>
class RBTree
{
	public:
		struct Node;
	public:
		typedef T												value_type;
		typedef Allocator										allocator_type;
		typedef Compare											value_compare;
		typedef size_t											size_type;			
	
	struct Node
	{
		bool		colour;
		value_type	value;
		Node		*parent;
		Node		*left;
		Node		*right;
	};

	typedef Node*									node_ptr;

	private:
		node_ptr				root;
		node_ptr				nil_node;
		std::allocator<Node>	node_alloc;
		allocator_type			alloc;
		value_compare			compare;
		size_type				_size;
	
	public:
	RBTree(const value_compare &compare_, const allocator_type &alloc_) : compare(compare_), alloc(alloc_), _size(0)
	{
		nil_node = node_alloc.allocate(sizeof(struct Node));
		nil_node->colour = BLACK;
		nil_node->parent = NULL;
		nil_node->left = nil_node;
		nil_node->right = nil_node;
		// nil_node->value = NULL;
		root = nil_node;
	}

	~RBTree(void)
	{
		// node_alloc.deallocate(nil_node, sizeof(struct Node));
	}
	
	void initialise_RED_node(node_ptr new_node, const value_type &val)
	{
		new_node->parent	= NULL;
		new_node->left		= nil_node;
		new_node->right		= nil_node;
		new_node->colour	= RED;
		new_node->value		= val;
	}
	
	node_ptr insert(const value_type &val)
	{
		//Binary Search Insertion
		node_ptr new_node	= node_alloc.allocate(sizeof(struct Node));
		node_ptr parent		= NULL;
		node_ptr current	= root;

		initialise_RED_node(new_node, val);
		while(current != nil_node)
		{
			parent = current;
			if (compare(new_node->value, current->value))
				current = current->left;
			else if (compare(current->value, new_node->value))
				current = current->right;
			else
				return (current);
		}
		_size++;
		// Set the parent and insert the new node
		new_node->parent = parent;
		if (parent == NULL)
			root = new_node;
		else if (compare(new_node->value, parent->value))
			parent->left = new_node;
		else
			parent->right = new_node;
		
		// if new_node is the root node, recolour it to black and end
		if (new_node->parent == NULL)
		{
			new_node->colour = BLACK;
			return (new_node);
		}
		
		// if parent is root (grandparent is null) then end
		if (new_node->parent->parent == NULL)
			return (new_node);
				
		fix_insert(new_node);
		return(new_node);
	}

	// rotate left at node x
	void rotate_left(node_ptr x)
	{
		node_ptr y = x->right;
		x->right = y->left;
		
		if (y->left != nil_node)
			y->left->parent = x;
		
		y->parent = x->parent;
		if (x->parent == NULL)
			root = y;
		else if (x == x->parent->left)
			x->parent->left = y;
		else
			x->parent->right = y;
		y->left = x;
		x->parent = y;
	}

	// rotate right at node x
	void rotate_right(node_ptr x)
	{
		node_ptr y = x->left;
		x->left = y->right;
		if (y->right != nil_node)
			y->right->parent = x;
		
		y->parent = x->parent;
		if (x->parent == NULL)
			root = y;
		else if (x == x->parent->right)
			x->parent->right = y;
		else
			x->parent->left = y;
		y->right = x;
		x->parent = y;
	}
	
	void fix_insert(node_ptr child)
	{
		node_ptr uncle;
		
		while(child->parent->colour == RED)
		{
			if (child->parent == child->parent->parent->right)
			{
				uncle = child->parent->parent->left;
				if (uncle->colour == RED)
				{
					uncle->colour = BLACK;
					child->parent->colour = BLACK;
					child->parent->parent->colour = RED;
					child = child->parent->parent;
				}
				else if (uncle->colour == BLACK)
				{
					if (child == child->parent->left)
					{
						child = child->parent;
						rotate_right(child);
					}
					child->parent->colour = BLACK;
					child->parent->parent->colour = RED;
					rotate_left(child->parent->parent);
				}
				
			}
			else
			{
				uncle = child->parent->parent->right;
				
				if (uncle->colour == RED)
				{
					uncle->colour = BLACK;
					child->parent->colour = BLACK;
					child->parent->parent->colour = RED;
					child = child->parent->parent;
				}
				else if (uncle->colour == BLACK)
				{
					if (child == child->parent->right)
					{
						child = child->parent;
						rotate_left(child);
					}
					child->parent->colour = BLACK;
					child->parent->parent->colour = RED;
					rotate_right(child->parent->parent);
				}
			}
			
			if (child == root)
				break ;
		}
		root->colour = BLACK;
	}
	
	void print_tree(void) const
	{
		_printHelper("", root, false);
	}

	void _printHelper(const std::string& prefix, const node_ptr n, bool isLeft) const
	{
		if (n != nil_node && n != nullptr)
		{
			std::cout << prefix;

			std::cout << (isLeft ? "├──" : "└──" );

			// print the value of the node
			std::cout << n->value.first << std::endl;

			// enter the next tree level - left and right branch
			_printHelper(prefix + (isLeft ? "│   " : "    "), n->left, true);
			_printHelper(prefix + (isLeft ? "│   " : "    "), n->right, false);
		}
	}

	// template<class Key>
	// void erase(const Key &key)
	// {
	// 	node_ptr node = root;

	// 	while(node != nil_node)
	// 	{
	// 		if (node->value.first == key)
	// 			break ;
	// 		if (key < node->value.first)
	// 			node = node->left;
	// 		else if (key > node->value.first)
	// 			node = node->right;
	// 	}
		
	// 	erase(node->value);
	// }
	void erase(const value_type &val)
	{
		node_ptr found_node = find(val);
		node_ptr x;
		node_ptr y;

		if (found_node == nil_node) //will adapt this later
		{
			std::cout << "No node\n";
			return ;
		}

		//BST delete
		_size--;
		y = found_node;
		bool y_og_colour = y->colour;

		//if there is only one node
		if (found_node == root && (found_node->left == nil_node && found_node->right == nil_node)) //could use size == 0 here maybe
		{
			//free found_note or simply root
			#include <stdlib.h>
			root = nil_node;
			return ;
		}
		
		if (found_node->left == nil_node)
		{
			x = found_node->right;
			rb_transplant(found_node, found_node->right);
		}
		else if (found_node->right == nil_node)
		{
			x = found_node->left;
			rb_transplant(found_node, found_node->left);
		}
		else
		{
			y = min(found_node->right);
			y_og_colour = y->colour;
			x = y->right;
			if (y->parent == found_node)
				x->parent = y;
			else
			{
				rb_transplant(y, y->right);
				y->right = found_node->right;
				y->right->parent = y;
			}
			rb_transplant(found_node, y);
			y->left = found_node->left;
			y->left->parent = y;
			y->colour = found_node->colour;
		}
		//free found_node;
		if (y_og_colour == BLACK)
		{
			fix_erase(x);
		}
		
		///saw it in Kacper's code // need to check with him what for
		Node *temp1 = this->root;
		while (temp1->right != this->nil_node)
			temp1 = temp1->right;
		this->nil_node->parent = temp1;
		
		
	}

	void fix_erase(node_ptr x)
	{
		node_ptr s;
		while(x != root && x->colour == BLACK)
		{
			if (x == x->parent->left)
			{
				s = x->parent->right;
				if (s->colour == RED)
				{
					s->colour = BLACK;
					x->parent->colour = RED;
					rotate_left(x->parent);
					s = x->parent->right;
				}
				
				if (s->left->colour == BLACK && s->right->colour == BLACK)
				{
					s->colour = RED;
					x = x->parent;
				}
				else
				{
					if (s->right->colour == BLACK)
					{
						s->left->colour = BLACK;
						s->colour = RED;
						rotate_right(s);
						s = x->parent->right;
					}
					s->colour = x->parent->colour;
					x->parent->colour = BLACK;
					s->right->colour = BLACK;
					rotate_left(x->parent);
					x = root;
				}
			}
			else
			{
				s = x->parent->left;
				if (s->colour == RED)
				{
					s->colour = BLACK;
					x->parent->colour = RED;
					rotate_right(x->parent);
					s = x->parent->left;
				}

				if (s->right->colour == BLACK && s->right->colour == BLACK)
				{
					s->colour = RED;
					x = x->parent;
				} 
				else
				{
					if (s->left->colour == BLACK)
					{
						s->right->colour = BLACK;
						s->colour = RED;
						rotate_left(s);
						s = x->parent->left;
					} 
					s->colour = x->parent->colour;
					x->parent->colour = BLACK;
					s->left->colour = BLACK;
					rotate_right(x->parent);
					x = root;
				}
			}
		}
		x->colour = BLACK;
	}
	//util for delete
	void rb_transplant(node_ptr u, node_ptr v)
	{
		if (u->parent == NULL)
			root = v;
		else if (u == u->parent->left)
			u->parent->left = v;
		else
			u->parent->right = v;
		v->parent = u->parent;
	}
	
	//util for delete
	node_ptr min(node_ptr node)
	{
		while(node->left != nil_node)
			node = node->left;
		return (node);
	}

	node_ptr find(const value_type &val)
	{
		node_ptr node = root;

		while(node != nil_node)
		{
			if (node->value == val)
				return (node);
			if (compare(val, node->value))
				node = node->left;
			else if (compare(node->value, val))
				node = node->right;
		}
		return (node);
	}

	size_t size(void)
	{
		return (_size);
	}

	bool empty(void)
	{
		return (_size == 0);
	}

	allocator_type get_allocator(void)
	{
		return (alloc);
	}

	// key_compare get_comp()
	// {
	// 	return (compare);
	// }
};
}
#endif