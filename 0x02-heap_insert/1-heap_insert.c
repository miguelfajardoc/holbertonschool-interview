#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_insert - create a node of a binary tree
 * @root: the parent of te new node
 * @value: the value that hold the node
 * Return: a pointer of the new node or null on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	heap_t *parent = *root;
	heap_t *leaftest = NULL;
	int n_rt = 0;

	if (!parent)
	{
		parent = binary_tree_node(NULL, value);
		*root = parent;
		return (parent);
	}
	while (1)
	{
		if (parent->left == NULL || parent->right == NULL)
		{
			new_node = asign_new_node(parent, value);
			n_rt = check_for_swap_will_be_done(&parent, &new_node);
			if (n_rt)
				*root = parent;
			return (new_node);
		}
		leaftest = perfect_binary_tree(&parent);
		if (leaftest)
		{
			parent = leaftest;
			new_node = asign_new_node(parent, value);
			if (value > parent->n)
				n_rt = check_for_swap_will_be_done(&parent,
								   &new_node);
			if (n_rt)
				*root = parent;
			return (new_node);
		}
		else if (perfect_binary_tree(&(parent->left)))
			parent = parent->right;
		else
			parent = parent->left;
	}
	return (new_node);
}

/**
 * check_for_swap_will_be_done - do a swap between two nodes in binary tree
 * @parentt: the parent of the new node
 * @childd: the child
 * Return: 1 if the parent is actualized, 0 otherwise
 */
int check_for_swap_will_be_done(heap_t **parentt,  heap_t **childd)
{
	heap_t *aux = NULL, *prev_parent = NULL;
	heap_t *parent = *parentt, *child = *childd;

	while (parent != NULL && child->n > parent->n)
	{
		child->parent = parent->parent;
		if (parent->left == child)
		{	parent->left = child->left;
			child->left = parent, aux = child->right;
			child->right = parent->right;
			parent->parent = child, parent->right = aux;
			if (child->right)
				child->right->parent = child;
		}
		else
		{	parent->right = child->right, child->right = parent;
			aux = child->left, child->left = parent->left;
			parent->parent = child,	parent->left = aux;
			if (child->left)
				child->left->parent = child;
		}
		if (parent->left)
			parent->left->parent = parent;
		if (parent->right)
			parent->right->parent = parent;
		prev_parent = parent, parent = child->parent;
		if (parent)
		{
			if (parent->left == prev_parent)
				parent->left = child;
			else
				parent->right = child;
		}
	}
	if (parent == NULL)
	{
		parent = child, *parentt = parent;
		return (1);
	}
	return (0);
}


/**
 * asign_new_node - check where left or right a node have to be asign
 * to his father
 * @parent: the parent of the new node
 * @value: the value of the new node
 * Return: a pointer of the new node
 */
heap_t *asign_new_node(heap_t *parent, int value)
{
	heap_t *new_node = NULL;

	new_node = binary_tree_node(parent, value);
	if (parent->left == NULL)
	{
		parent->left = new_node;
	}
	else if (parent->right == NULL)
	{
		parent->right = new_node;
	}
	else
	{
		printf("something go like shit, parent have null son/n");
		return (NULL);
	}
	return (new_node);
}



/**
 * perfect_binary_tree - check if a binary tree is fill
 * @root: the root of the binary tree
 *
 * Return: a pointer of the lefth leaf or null if not fill
 */
heap_t *perfect_binary_tree(heap_t **root)
{
	heap_t *left_p = *root;
	heap_t *right_p = *root;

	while (left_p->left)
	{
		if (left_p->left != NULL && right_p->right != NULL)
		{
			left_p = left_p->left;
			right_p = right_p->right;
		}
		else
		{
			return (NULL);
		}
	}
	return (left_p);
}
