#include<iostream>
using namespace std;

class BinarySearchTree
{
    private:
        struct Node
        {
            int data;
            Node* left;
            Node *right;
            Node(int x)
            {
                data=x;
                left=right=NULL;
            }
        };
        Node *root;
    
    public:
        BinarySearchTree()
        {
            root=NULL;
        }
        
        
        void _insertData(int data, Node *node)
        {
            if(root==NULL)
            {
                root=new Node(data);
                return;
            }
            if(node->data>data)
            {
                if(node->left==NULL)
                {
                    node->left=new Node(data);
                    return;
                }
                else
                {
                    _insertData(data,node->left);
                }
            }else
            {
                if(node->right==NULL)
                {
                    node->right=new Node(data);
                    return;
                }
                else{
                    _insertData(data,node->right);
                }
            }
        }

        void insertData(int data)
        {
            _insertData(data,root);
        }

        Node* getRoot()
        {
            return root;
        }

        //inorder traversal of a binary search tree is always sorted
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

        
};

int main()
{
    
    BinarySearchTree b;
    b.insertData(12);
    b.insertData(122);
    b.insertData(1);
    b.insertData(11);
        
    b.inorderTraversal(b.getRoot());
    return 0;

}