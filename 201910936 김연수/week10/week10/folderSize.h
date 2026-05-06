#pragma once

int FolderSize;

typedef struct folderTreeNode {
	int size;
	struct folderTreeNode* left;
	struct folderTreeNode* right;
} folderTreeNode;

folderTreeNode* makeFolderRootNode(int size, folderTreeNode* left, folderTreeNode* right);
int postorder_FolderSize(folderTreeNode* root);