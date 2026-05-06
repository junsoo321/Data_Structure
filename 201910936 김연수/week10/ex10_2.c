#include <stdio.h>

#include "common.h"
#include "folderSize.h"

int ex10_2(void)
{
	folderTreeNode* F11 = makeFolderRootNode(120, NULL, NULL);
	folderTreeNode* F10 = makeFolderRootNode(55, NULL, NULL);
	folderTreeNode* F9 = makeFolderRootNode(100, NULL, NULL);
	folderTreeNode* F8 = makeFolderRootNode(200, NULL, NULL);
	folderTreeNode* F7 = makeFolderRootNode(68, F10, F11);
	folderTreeNode* F6 = makeFolderRootNode(40, NULL, NULL);
	folderTreeNode* F5 = makeFolderRootNode(15, NULL, NULL);
	folderTreeNode* F4 = makeFolderRootNode(2, F8, F9);
	folderTreeNode* F3 = makeFolderRootNode(10, F6, F7);
	folderTreeNode* F2 = makeFolderRootNode(0, F4, F5);
	folderTreeNode* F1 = makeFolderRootNode(0, F2, F3);

	FolderSize = 0;
	printf("C Size: %d M\n", postorder_FolderSize(F2));

	FolderSize = 0;
	printf("D Size: %d M\n", postorder_FolderSize(F3));

	FolderSize = 0;
	printf("Total Size: %d M\n", postorder_FolderSize(F1));

	printf("\n\npress any key ...");
	(void) getchar();
	return 0;
}