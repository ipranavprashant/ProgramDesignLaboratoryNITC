#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>

struct node
{
 struct node *right,*left,*prev;
 char data;
}*cur,*par,*root=NULL;

void preorder(struct node *);
void postorder(struct node *);
void inorder(struct node *);

int main()
{
  char a[10000];
  int len,i;
  struct node *new_node;
  char ch;
  do
  {
      scanf("%c",&ch);
      switch(ch)
      {
      case 'e':
  scanf("%s",a);
  len=strlen(a);
  for(i=len-1 ; i>=0 ; i--)
  {
   new_node=(struct node *)malloc(sizeof(struct node));
   new_node->data=a[i];
   new_node->left=new_node->right=new_node->prev=NULL;
   if(root==NULL)
   {
     root=new_node;
     cur=par=root;
   }
   else
   {
    if(a[i]=='+' ||a[i]=='-' ||a[i]=='*'||a[i]=='/')
    {
     if(par->right==NULL)
     {
      cur=new_node;
      par->right=cur;
      cur->prev=par;
      par=cur;
     }
     else if(par->left==NULL)
     {
      cur=new_node;
      par->left=cur;
      cur->prev=par;
      par=cur;
     }
    else
    {
     while(par->left!=NULL)
     {
      par=par->prev;
     }
     cur=new_node;
     par->left=cur;
     cur->prev=par;
     par=cur;
    }
   }
   else
   {
    if(par->right==NULL)
    {
     cur=new_node;
     par->right=cur;
     cur->prev=par;
    }
    else if(par->left==NULL)
    {
     cur=new_node;
     par->left=cur;
     cur->prev=par;
    }
    else
    {
     while(par->left!=NULL)
     {
      par=par->prev;
     }
     cur=new_node;
     par->left=cur;
     cur->prev=par;
    }
   }
  }
 }
 break;
 case 'i':
 inorder(root);
 break;
 case 'p':
 preorder(root);
 break;
 case 's':
 postorder(root);
  }
}while(ch!='t');
 return 0;
}

void inorder(struct node *root)
{
 if(root!=NULL)
 {
  inorder(root->left);
  printf("%c",root->data);
  inorder(root->right);
 }
}

void preorder(struct node *root)
{
 if(root!=NULL)
 {
  printf("%c",root->data);
  preorder(root->left);
  preorder(root->right);
 }
}

void postorder(struct node *root)
{
 if(root!=NULL)
 {
  postorder(root->left);
  postorder(root->right);
  printf("%c",root->data);
 }
}

