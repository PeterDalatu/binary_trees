#include "binary_trees.h"

/**
 * binary_tree_height - To measures the height of a binary tree
 *
 * @tree:A Pointer to the root node of the tree to measure the height
 *
 * Return: The Height of tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left;
	size_t height_right;

	if (tree == NULL)
		return (0);

	height_left = binary_tree_height(tree->left);
	height_left++;
	height_right = binary_tree_height(tree->right);
	height_right++;

	if (height_left > height_right)
		return (height_left);
	else
		return (height_right);
}

/**
 * levelorder - To Performs a level-order traversal using a binary tree
 *
 * @tree: A Pointer to the root node of the tree to traverse
 * @func: A Pointer to a function to call for each node
 * @level:The level of the tree
 */
void levelorder(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (tree == NULL || func == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else
	{
		levelorder(tree->left, func, level - 1);
		levelorder(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - It goes through a binary tree
 * using level-order traversal
 *
 * @tree:A Pointer to the root node of the tree to traverse
 * @func:A Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t count = 0;

	if (tree == NULL || func == NULL)
		return;

	while (binary_tree_height(tree) > count)
	{
		levelorder(tree, func, count);
		count++;
	}
}
