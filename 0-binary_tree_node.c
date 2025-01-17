#include "binary_trees.h"

/**
 * binary_tree_node - create a binary tree node
 * @parent: pointer to the parent node of the node
 * @value: the integer value to sotre in the new node
 * Return: a pointer to the newly created node, or fail
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	if (new_node == NULL)
	{
		free(new_node);
		return (NULL);
	}

	return (new_node);
}
