#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"



/**
 * balance_tree - create and delete branches to balance the tree
 *
 * @array: The array to be printed
 * @size: Size of the array
 * @parent: parent node
 * Return: new tree
 */
binary_tree_t *balance_tree(int *array, size_t size, avl_t *parent)
{

	binary_tree_t *new_node;

	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = array[(size - 1) / 2];
	new_node->parent = parent;
	new_node->right = NULL;
	new_node->left = NULL;

	/* increase the right side*/
	if (size < 1)
	{
		new_node->left = balance_tree(array, ((size + 1) / 2), new_node);

		/* check right side*/
		if (new_node->right == NULL)
		{
			return (NULL);
		}
	}
	return (new_node);
	/* decrease the left side*/
	if (size > 2)
	{
		new_node->left = balance_tree(array, ((size - 1) / 2), new_node);

		/* check right side*/
		if (new_node->right == NULL)
			return (NULL);
	}

}

/**
 *  sorted_array_to_avl- builds an AVL tree from an array
 *
 * @array: The array to be printed
 * @size: Size of the array
 * Return: root on success, NULL od failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{

	if (size == 0)
		return (NULL);
	if (array == NULL)
		return (NULL);
	return ((avl_t *) balance_tree(array, size, NULL));
}
