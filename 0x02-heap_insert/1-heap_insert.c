#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - create a node of a binary tree
 * @parent: the parent of te new node
 * @value: the value that hold the node
 * Return: a pointer of the new node or null on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	heap_t *checker = *root;

	while(checker->right)
	{
		new_node = perfect_binary_tree(&checker);
		if (new_node != NULL)
		{
			return binary_tree_node(new_node, value);
		}
		else
		{
			if (perfect_binary_tree(&(checker->left)) != null)
			{
				checker = checker->right;
			}
			else
			{
				checker = checker->left;
			}
		}
	}
	return binary_tree_node(checker->right, value);
}




/**
 * perfect_binary_tree - check if a binary tree is fill
 * @root: the root of the binary tree
 *
 * Return: a pointer of the lefth leaf or null if not fill
 */
heap_t *perfect_binary_tree(heapt_t **root)
{
	heapt_t *left_p = *root;
	heapt_t *right_p = *root;

	while (left_p->left)
	{
		if(left_p->left != NULL && right_p->right != NULL)
		{
			left_p = left_p->left;
			right_p = right->right;
		}
		else
		{
			return false
		}
	}
	return left_p;
}
