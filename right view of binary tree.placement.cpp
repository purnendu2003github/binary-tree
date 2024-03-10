#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left,*right;
};
struct node* newNode(int item)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=item;
    temp->left=temp->right=NULL;
    return temp;
}
void rightview(struct node* root,int level,vector<int>&res)
{
    if(root==NULL)return;
    if(res.size()==level) res.push_back(root->data);
    rightview(root->right,level+1,res);
    rightview(root->left,level+1,res);
}
vector<int>rightviewbt(struct node* root)
{
    vector<int>res;
    rightview(root,0,res);
    return res;
}
int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->right = newNode(8);
 
    vector<int> result = rightviewbt(root);
    for(int i=0;i<result.size();++i)
    {
        cout<<result[i]<<" ";
    }
 
    return 0;
}