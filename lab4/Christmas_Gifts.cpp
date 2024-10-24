#include <iostream>
using namespace std;

struct node{
    node* left;
    node* right;
    int value;

    node(int x){
        right = left = nullptr;
        value = x;
    }
};

struct BST
{
    node* insert(node* root, int value) {
        if (root == nullptr) {
            return new node(value);  
        }
        if (value < root->value) {
            root->left = insert(root->left, value);  
        } else {
            root->right = insert(root->right, value);  
        }
        return root;  
    }
    node* findNode(node* root,int value){
        if(root == nullptr || root->value == value ){
            return root;
        }
        if(root->value > value){
            return findNode(root->left,value);
        }else{
            return findNode(root->right,value);
        }
    }
    void print(node* root){
        if(root == nullptr) return;
        cout<<root->value<<" ";
        print(root->left);
        print(root->right);
}
};



int main(){
    BST tree;
    node* root = nullptr;

    int n; cin >> n;
    for(int i=0;i<n;i++){
        int k; cin >> k;
        root = tree.insert(root,k);
    }

    int s; cin >> s;
    node* targetNode = tree.findNode(root, s);

    if (targetNode) {
        tree.print(targetNode);
        cout << endl;
    } 
}