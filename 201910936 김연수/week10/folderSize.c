#include <stdlib.h>
#include "folderSize.h"

folderTreeNode* makeFolderRootNode(int size, folderTreeNode* left, folderTreeNode* right)
{
	folderTreeNode* node = (folderTreeNode*)malloc(sizeof(folderTreeNode));
	node->size = size;
	node->left = left;
	node->right = right;
	return node;
}

int postorder_FolderSize(folderTreeNode* root)
{
	if (root)
	{
		postorder_FolderSize(root->left);
		postorder_FolderSize(root->right);
		FolderSize += root->size;
	}

	return FolderSize;
}