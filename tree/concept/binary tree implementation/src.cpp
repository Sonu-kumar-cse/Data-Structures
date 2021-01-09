#include<iostream>
using namespace std;

class BinaryTree
{
    private:
        struct Node
        {
            int data;
            Node *left;
            Node *right;
            Node(int x)
            {
                data=x;
                left=right=NULL;
            }
        };
        Node *root;
    public:
        BinaryTree()
        {
            root=NULL;
        }
        
        Node* create()
        {
            Node *newnode=NULL;
            int x;
            cout<<"enter data (-1 for no data):";
            cin>>x;
            if(x==-1)
            {
                return newnode;
            }
            newnode=new Node(x);
            cout<<"left of "<<x<<" ";
            newnode->left=create();
            cout<<"right of "<<x<<" ";
            newnode->right=create();

            return newnode;

        }

        void inorderTraversal(Node *node)
        {
            if(node==NULL)
            {
                return;
            }
            inorderTraversal(node->left);
            cout<<node->data<<" ";
            inorderTraversal(node->right);

        }
        void preorderTraversal(Node *node)
        {
            if(node==NULL)
            {
                return;
            }
            cout<<node->data<<" ";
            preorderTraversal(node->left);
            preorderTraversal(node->right);

        }
        void postorderTraversal(Node *node)
        {
            if(node==NULL)
            {
                return;
            }
            postorderTraversal(node->left);
            postorderTraversal(node->right);
            cout<<node->data<<" ";
        }
        Node* getroot()
        {
            return root;
        }
        void setroot(Node *node)
        {
            root=node;
        }
};

int main()
{
    BinaryTree t;
    t.setroot(t.create());
    t.inorderTraversal(t.getroot());
    cout<<endl;
    t.postorderTraversal(t.getroot());
    cout<<endl;
    t.preorderTraversal(t.getroot());
    cout<<endl;
    
    return 0;
}