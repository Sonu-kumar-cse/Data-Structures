#include<iostream>
using namespace std;

class BinaryTree
{
    private:
        struct Node{
            int data;
            Node *left;
            Node *right;
            Node(int x)
            {
                data =x;
                left=right=NULL;
            }
        };
        Node *root;
    
    public:
        BinaryTree()
        {
            root=NULL;
        }

        Node* _create()
        {
            cout<<"enter data(-1 for no data) ";
            int x;
            cin>>x;
            if(x == -1)
            {
                return NULL;
            }

            Node *newnode=new Node(x);
            cout<<"left of "<<x<<" ";
            newnode->left=_create();
            cout<<"right of "<<x<<" ";
            newnode->right=_create();

            return newnode;
        }
        void create()
        {
            root=_create();
        }


        void inorderTraversal(Node *root)
        {
            if(root==NULL)
            {
                return;
            }
            inorderTraversal(root->left);
            cout<<root->data<<" ";
            inorderTraversal(root->right);
        }
        
        void postorderTraversal(Node *root)
        {
            if(root==NULL)
            {
                return;
            }
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            cout<<root->data<<" ";
        }
        
        void preorderTraversal(Node *root)
        {
            if(root==NULL)
            {
                return;
            }
            cout<<root->data<<" ";
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }

        Node *getRoot()
        {
            return root;
        }


};

int main()
{
    BinaryTree b;
    b.create();

    cout<<"inorder traversal"<<endl;
    b.inorderTraversal(b.getRoot());

    cout<<endl<<"postorder traversal"<<endl;
    b.postorderTraversal(b.getRoot());
    
    cout<<endl<<"preorder traversal"<<endl;
    b.preorderTraversal(b.getRoot());
 
    return 0;
}