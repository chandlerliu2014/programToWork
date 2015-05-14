//输入一个二叉树,输出它的镜像
//2015-05-14
//by chandler
#include <iostream>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode *m_pLeft;
	BinaryTreeNode *m_pRight;
};

void MirrorRecursively(BinaryTreeNode *pNode)
{
	if (pNode == NULL)
		return;

	BinaryTreeNode *temp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = temp;		
	MirrorRecursively(pNode->m_pLeft);
	MirrorRecursively(pNode->m_pRight);
}

BinaryTreeNode *createBinaryTreeNode(int value);
void connectBinaryTreeNode(BinaryTreeNode *root,BinaryTreeNode *left,BinaryTreeNode *right);
void printTree(BinaryTreeNode *root);
int main(void)
{
	
	/*BinaryTreeNode *p1 = createBinaryTreeNode(8);
	BinaryTreeNode *p2 = createBinaryTreeNode(6);
	BinaryTreeNode *p3 = createBinaryTreeNode(10);
	BinaryTreeNode *p4 = createBinaryTreeNode(5);
	BinaryTreeNode *p5 = createBinaryTreeNode(7);
	BinaryTreeNode *p6 = createBinaryTreeNode(9);
	BinaryTreeNode *p7 = createBinaryTreeNode(11);
	
	connectBinaryTreeNode(p1,p2,p3);
	connectBinaryTreeNode(p2,p4,p5);
	connectBinaryTreeNode(p3,p6,p7);*/

	BinaryTreeNode *p8 = createBinaryTreeNode(8);
	BinaryTreeNode *p7 = createBinaryTreeNode(7);
	BinaryTreeNode *p6 = createBinaryTreeNode(6);
	BinaryTreeNode *p5 = createBinaryTreeNode(5);
	BinaryTreeNode *p4 = createBinaryTreeNode(4);
	connectBinaryTreeNode(p8,NULL,p7);
	connectBinaryTreeNode(p7,NULL,p6);
	connectBinaryTreeNode(p6,NULL,p5);
	connectBinaryTreeNode(p5,NULL,p4);
	
	BinaryTreeNode *p = createBinaryTreeNode(1);
	//printTree(p1); 
	MirrorRecursively(p);
	printTree(p); 
	return 0;
}

void printTree(BinaryTreeNode *root)
{
	if (root == NULL)
		return;
	cout << root->m_nValue << endl;
	printTree(root->m_pLeft);
	printTree(root->m_pRight);
}
BinaryTreeNode *createBinaryTreeNode(int value)
{
	BinaryTreeNode *root = new BinaryTreeNode();
	root->m_nValue = value;
	root->m_pLeft = NULL;
	root->m_pRight = NULL;
	return root;
}
void connectBinaryTreeNode(BinaryTreeNode *root,BinaryTreeNode *left,BinaryTreeNode *right)
{
	root->m_pLeft = left;
	root->m_pRight = right;
}
