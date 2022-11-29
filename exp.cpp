#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* right;
    Node* left;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp ==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL); 
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp -> left){
                q.push(temp -> left);
            }
    
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}
Node* insertToBST(Node* root, int d){
    if(root==NULL){             //base case    t.c.=O(log n)
        root=new Node(d);
        return root;
    }
    if(d> root->data){
        root->right = insertToBST(root->right, d);
    }
    else{
        root->left = insertToBST(root->left, d);
    }
    return root;
}
Node* minVal(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
Node* maxVal(Node* root){
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}
void takeinput(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertToBST(root, data);
        cin>>data;
    }
}
Node* deleteFromBST(Node* root, int val){
    if(root==NULL){         //t.c. = O(n)
        return root;
    }
    if(root->data==val){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child
        if (root->left!=NULL && root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if (root->left==NULL && root->right!=NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini = minVal(root->right)->data;
            root->data=mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if(root->data > val){
        root->left =deleteFromBST(root->left, val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}
int main(){
    Node* root=NULL;
    cout<<"enter the data to create BST"<<endl;
    takeinput(root);
    cout<<"printing the BST"<<endl;
    levelOrderTraversal(root);   
    cout<<"min value is"<<minVal(root)->data<<endl;     //50 20 70 10 30 90 110 -1
    cout<<"max value is"<<maxVal(root)->data<<endl;
    root = deleteFromBST(root,30);
    cout<<endl;
    cout<<"printing the BST after deletion"<<endl;
    levelOrderTraversal(root);   
    cout<<"min value is"<<minVal(root)->data<<endl;     //50 20 70 10 30 90 110 -1
    cout<<"max value is"<<maxVal(root)->data<<endl;
    return 0;
}