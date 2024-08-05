#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root of the tree
 * Return: height of tree, or 0 if tree is NULL
 */


size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}


/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: the balance factor, or 0 if tree is NULL.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left_height = tree->left ? (int)binary_tree_height(tree->left) : 0;
	int right_height = tree->right ? (int)binary_tree_height(tree->right) : 0;

	return (left_height - right_height);
}
