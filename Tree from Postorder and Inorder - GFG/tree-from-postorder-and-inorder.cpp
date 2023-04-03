//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
int find(int inorder[], int st, int en, int key){
    for(int i=st;i<=en;i++){
        if(inorder[i]==key) return i;
    }
    return -1;
}
Node* build(int in[], int post[], int st, int en, int& i, int n){
    if(st>en || i<0) return NULL;
    int ele=post[i--];
    int id=find(in,st,en,ele);
    Node* root=new Node(ele);
    root->right=build(in,post,id+1,en,i,n);
     root->left=build(in,post,st,id-1,i,n);
     return root;
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int i=n-1, en=n-1,st=0;
    return build(in,post,st,en,i,n);
}
