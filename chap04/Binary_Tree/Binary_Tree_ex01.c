// https://www.cprogramming.com/snippets/source-code/binary-tree-creation-traversal-and-search
// binary tree creation, traversal and search source code

#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int data;
    struct tnode *left;
    struct tnode *right;
};
 
typedef struct tnode TreeNode;
 
TreeNode *newItem(int data) {
    TreeNode *pn = (TreeNode *) malloc(sizeof(TreeNode));
    pn->data = data;
    pn->left = 0;
    pn->right = 0;
     
    return pn;
}

void destroyTree( TreeNode pn) {
	//...
}

TreeNode *searchTree(TreeNode *pn, int data) {
  //...
}

TreeNode* insertTree(TreeNode *pn, int data) {
    if (!pn)
        return newItem(data);
    else {
        if (data <= pn->data)
            pn->left = insertTree(pn->left, data);
        else 
            pn->right = insertTree(pn->right, data);
    }
 
    return  pn;
}
 
TreeNode *createTree() {
    TreeNode * pr = insertTree(0, 4);
    insertTree(pr, 1);
    insertTree(pr, 2);
    insertTree(pr, 3);
    insertTree(pr, 5);
    insertTree(pr, 6);
 
    return pr;
}
 
void printPreorder(TreeNode *pn) {
    if (pn) {
        printf("preorder = %d\n", pn->data);
        printPreorder(pn->left);
        printPreorder(pn->right);
    }
}
 
void printPostorder(TreeNode *pn) {
    if (pn) {
        printPostorder(pn->left);
        printPostorder(pn->right);
        printf("postorder = %d\n", pn->data);
    }
}
 
void printInorder(TreeNode *pn) {
    if (pn) {
        printInorder(pn->left);
        printf("inorder = %d\n", pn->data);
        printInorder(pn->right);
    }
}
 
int size(TreeNode *pn) {
    if (pn) 
        return 1 + size(pn->left) + size(pn->right);
    else
        return 0;
}
 
int depth(TreeNode *pn) {
    if (pn) {
        int ld = depth(pn->left);
        int rd = depth(pn->right);
 
        if (ld > rd)
            return ld + 1;
        else
            return rd + 1;
    } else
        return 0;
}
 
int minVal(TreeNode *pn) {
    if (pn) {
        while(pn->left)
            pn = pn->left;
 
        return pn->data;
    } else
        return 0;
}
 
int maxVal(TreeNode *pn) {
    if(pn) {
        while(pn->right)
            pn = pn->right;
 
        return pn->data;
    } else
        return 0;
}

int main() {
	TreeNode *node;
	
	node = createTree();
	
	printInorder(node);
	
	printf("\n");
	printf("minVal = %d\n", minVal(node));
	printf("maxVal = %d\n", maxVal(node));
}
