// RBT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "binarySearchTree.h"
#include "Comsci.h"
int val1[9] = { 30, 35, 13, 22, 42, 28, 23, 16, 25 };
int val2[9] = { 13, 16, 22, 23, 25, 28, 30, 35, 42 };
int main()
{
	int cts = 0;
	splash("Binary Search Tree + Red Black Tree", "class asignment", false);
	bSearchTreeType <int> tree1, tree2;
	while (cts < 9)
	{
		tree1.insert(val1[cts]);
		cts++;
	}
	cts = 0;
	while (cts < 9)
	{
		tree2.insert(val2[cts]);
		cts++;
	}
	cout << "30, 35, 13, 22, 42, 28, 23, 16, 25" << std::endl;
	cout << "13, 16, 22, 23, 25, 28, 30, 35, 42" << std::endl;
	cout << "Data inserted into trees\n";
	cout << "Tree1 PreOrder Traversal :>";
	tree1.preorderTraversal();
	cout << std::endl;
	cout << "Tree2 PostOrder Traversal:>";
	tree2.postorderTraversal();
	std::cout << std::endl << "Removing Node 30 from Tree 1" << std::endl;
	tree1.deleteNode(30);
	tree1.postorderTraversal();
	std::cout << std::endl;
	tree1.preorderTraversal();
	pause();
    return 0;
}

