#include<stdio.h>
struct node
{
   struct node *left,*right;
   int data;
};
struct node* insert(int data)
struct node* GetNewNode(int data)
{
   struct node *new_node = NULL;
   new_node = (struct node *)malloc(sizeof(struct node));
   new_node->left = NULL;
   new_node->right = NULL;
   new_node->data = data;
   return new_node; 
}
void preorder(struct node *head)
{
  if(head == NULL)
      return;
  printf("%d ",head->data);
  inorder(head->left);
  inorder(head->right);
}
void postorder(struct node *head)
{
  if(head == NULL)
      return;
  inorder(head->left);
  inorder(head->right);
  printf("%d ",head->data);
}
void inorder(struct node *head)
{
  if(head == NULL)
      return;
  inorder(head->left);
  printf("%d ",head->data);
  inorder(head->right);
}
struct node *deleteNode(struct node *head,int delete)
{
  if(head == NULL || head->data == delete) return NULL;
  else if(head->data < delete )
     head->right = deleteNode(head->right,delete); 
  else if(head->data > delete )
     head->left = deleteNode(head->left,delete); 
}
int main()
{
  struct node *head;
  head = insert(7); 
  head->left = insert(3);
  head->left->left = insert(1);
  head->left->right = insert(5);
  head->right = insert(9);
  head->right->left = insert(8);
  head->right->right = insert(10);
  deleteNode(head,10);
  printf("*********** Pre order ***********\n");
  preorder(head);
  printf("\n");
  printf("*********** In order ***********\n");
  inorder(head);
  printf("\n");
  printf("*********** Post order ***********\n");
  postorder(head);
  printf("\n");
  return 0;
}
