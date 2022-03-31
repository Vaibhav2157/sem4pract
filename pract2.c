#include<stdio.h>
#include<stdlib.h>


struct abc
{
  int data;
  struct abc *left, *right;
};

struct abc* create(int d)
{
struct abc *temp;
temp=(struct abc*)malloc(sizeof(struct abc));
temp->data=d;
temp->left=NULL;
temp->right=NULL;
return temp;
}

struct abc* search(struct abc* root,int d)
{
if(root->data == d)
{
printf("\nFound");
}
else if(root->data>d)
{
root->left = search(root->left,d);
}
else
{
root->right = search(root->right,d);
}

}
struct abc* insert(struct abc* root, int d)
{
if(root ==NULL)
{
return create(d);
}

else if(root->data>d)
{
root->left = insert(root->left,d);
}

else{root->right = insert(root->right,d);}
return root;
}



void inorder(struct abc*root)
{
if(root== NULL)
return;
inorder(root->left);
printf("%d ",root->data); 
inorder(root->right);  
}


void main()
{
struct abc *root =NULL; 
root=insert(root,15);
root=insert(root,10);
root=insert(root,20);
root=insert(root,5);
root=insert(root,8);
root=insert(root,35);
root=insert(root,7); 
root=insert(root,42);
root=insert(root,41);

inorder(root);
search(root,35);
//search(root,22);
}



