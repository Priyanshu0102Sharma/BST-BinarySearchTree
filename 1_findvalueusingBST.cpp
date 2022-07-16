#include<bits/stdc++.h>
#include "binarytreeuse.h"
using namespace std;

binarytreenode<int> * takeinput()
{
    int rootdata;
   cout<<"Enter root data: ";
   cin>>rootdata;
   if(rootdata==-1)
   return NULL;
   binarytreenode<int> * root= new binarytreenode<int>(rootdata);
   queue<binarytreenode<int>*> pendingNode;
   pendingNode.push(root);
   while(pendingNode.size()!=0)
   {

        binarytreenode<int>* front=pendingNode.front();
        pendingNode.pop();
        int left_child_data;
        cout<<"Enter left Child of "<<front->data<<endl;
        cin>>left_child_data;
        if(left_child_data!=-1)
        {
            binarytreenode<int> *child=new binarytreenode<int>(left_child_data);
            pendingNode.push(child);
            front->left=child;
        }
        int right_child_data;
        cout<<"Enter right CHild of "<<front->data<<endl;
        cin>>right_child_data;
        if(right_child_data!=-1)
        {
            binarytreenode<int>* child=new binarytreenode<int>(right_child_data);
            pendingNode.push(child);
            front->right=child;
        }
   }
   return root;
}

void printtree(binarytreenode<int> * root)
{
    if(root==NULL)
    return ;
    queue<binarytreenode<int>*> pendingNode;
    pendingNode.push(root);
    while(pendingNode.size()!=0)
    {

        binarytreenode<int>* front=pendingNode.front();
        pendingNode.pop();
        cout<<front->data<<": ";
        if(front->left!=NULL)
        {
            pendingNode.push(front->left);
            cout<<"L-"<<front->left->data<<" ";
        }
        if(front->right!=NULL)
        {
            pendingNode.push(front->right);
            cout<<"R-"<<front->right->data<<" ";
        }
        cout<<endl;

    }
}

void findNode(binarytreenode<int>* root, int key){

    if(root==NULL)
    {cout<<"key not found";
    return ;
    }
    cout<<root->data<<" ";
    if(root->data==key){
    cout<<"key find "<<key<<endl;
    return;
    }
    (key>(root->data))? findNode(root->right,key) : findNode(root->left,key);

}

int main()
{

binarytreenode<int>* root=takeinput();
printtree(root);
findNode(root,4);
    return 0;
}