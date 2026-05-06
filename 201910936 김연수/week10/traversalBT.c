#include <stdio.h>
#include <stdlib.h>
#include "traversalBT.h"

treeNode* makeRootNode(element data, treeNode* leftNode, treeNode* rightNode)
{
	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
	newNode->data = data;
	newNode->left = leftNode;
	newNode->right = rightNode;
	return newNode;
}

void preOrder(treeNode* root)
{
	if (root != NULL)
	{
		printf("%c ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inorder(treeNode* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%c ", root->data);
		inorder(root->right);
	}
}

void postorder(treeNode* root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%c ", root->data);
	}
}