// A145 Kaustubh Jagtap
// Assignment No. 1 
// Construct and expression tree from postfix/prefix expression and perform recursive and 
// non-recursive In-order, pre-order and post-order traversals. 
 
#include <stdio.h> 
#include <stdlib.h> 
struct node 
{ 
 int data; 
 struct node *left, *right, *next; 
}; 
struct node *top = NULL; 
void Push(struct node *); struct node *Pop(); 
struct node *NetempNode(char); 
void Inorder_Traversal(struct node *); 
void Preorder_Traversal(struct node *); 
void Postorder_Traversal(struct node *); 
struct node *NetempNode(char a) 
{ 
 struct node *temp = (struct node *)malloc(sizeof(struct node)); 
 temp->data = a; 
 temp->left = NULL; 
 temp->right = NULL; 
 temp->next = NULL; 
 return (temp); 
} 
void Inorder_Traversal(struct node *root) 
{ 
 if (root == NULL) 
 return; 
 else 
 { 
 Inorder_Traversal(root->left); 
 printf("%c\t", root->data); 
 Inorder_Traversal(root->right); 
 } 
} 
void Preorder_Traversal(struct node *root) 
{ 
 if (root == NULL) 
 return; 
 else 
 { 
 printf("%c\t", root->data); 
 Preorder_Traversal(root->left); 
 Preorder_Traversal(root->right); 
 } 
} 
void Postorder_Traversal(struct node *root) 
{ 
 if (root == NULL) 
 return; 
 else 
 { 
 Postorder_Traversal(root->left); 
 Postorder_Traversal(root->right); 
 printf("%c\t", root->data); 
 } 
} 
int main() 
{ 
 struct node *root, *p, *q; 
 char a[] = {'a', 'b', '+', 'c', '*'}; 
 int l = sizeof(a) / sizeof(a[0]); 
 for (int i = 0; i < l; i++) 
 { if (a[i] == '+' || a[i] == '*') 
 { 
 root = NetempNode(a[i]); 
 p = Pop(); 
 q = Pop(); 
 root->right = p; 
 root->left = q; 
 Push(root); 
 } 
 
 else 
 { 
 root = NetempNode(a[i]); 
 Push(root); 
 } 
 } 
 printf("Inorder_Traversal traversal:\n"); 
 Inorder_Traversal(root); 
 
 printf("\nPreorder_Traversal traversal:\n"); 
 Preorder_Traversal(root); 
 
 printf("\nPostorder_Traversal traversal:\n"); 
 Postorder_Traversal(root); 
 return 0; 
}