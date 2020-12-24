#ifndef BINARY_TREE
#define BINARY_TREE

#include <stddef.h>
#include <stdio.h>
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
typedef struct binary_tree_s heap_t;
typedef heap_t binary_tree_t;

heap_t *perfect_binary_tree(heap_t **root);
void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
heap_t *heap_insert(heap_t **root, int value);
int check_for_swap_will_be_done(heap_t **parent,  heap_t **child);
heap_t *asign_new_node(heap_t *parent, int value);

#endif /* BINARY_TREE */
