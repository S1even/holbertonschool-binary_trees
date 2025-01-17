#include "binary_trees.h"

/**
 * binary_trees_ancestor - function finds the lowest common ancestor of 2 nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to lowest common ancestor node of the two given nodes
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	if (is_descendant(first, second))
		return ((binary_tree_t *)first);

	if (is_descendant(second, first))
		return ((binary_tree_t *)second);

	while (first != second)
	{
		if (first->parent)
			first = first->parent;

		if (second->parent)
			second = second->parent;
	}
	return ((binary_tree_t *)first);
}

/**
 * is_descendant - function check second node is a descendant of first
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: 1 if the second node is a descendant of the first node else 0
 */

int is_descendant(const binary_tree_t *first, const binary_tree_t *second)
{
	int descendant_left, descendant_right;

	if (!first || !second)
		return (0);

	if (first == second)
		return (1);
	descendant_left = is_descendant(first->left, second);
	descendant_right = is_descendant(first->right, second);
	return (descendant_left || descendant_right);
}
