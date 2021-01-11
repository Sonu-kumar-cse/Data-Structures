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

        //actual implementation of insertion
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
        
        //actual implementation of searching
        Node* _searchData(int data,Node *node)
        {
            if(node==NULL)
            {
                return node;
            }
            if(node->data==data)
            {
                return node;
            }
            Node* temp=NULL;
            if(node->data<data)
            {
                temp=_searchData(data,node->right);
                
            }
            else
            {
                temp=_searchData(data,node->left);
                
            }
            return temp;
            
        }
        
        //axtual implementation of getting height of root node
        int _getHeight(Node *node)
        {
            if(node==NULL)
            {
                return 0;
            }


            int leftHeight=_getHeight(node->left);
            int rightHeight=_getHeight(node->right);
            
            if(leftHeight>rightHeight)
            {
                return leftHeight+1;
            }
            else
            {
                return rightHeight+1;
            }

            return 0;
        }

    public:
        //overriding default constructor
        BinarySearchTree()
        {
            root=NULL;
        }

        // function for inserting a node  
        void insertData(int data)
        {
            _insertData(data,root);
        }

        //function for getting the root node
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
        
        //function for searching a data
        void searchData(int data)
        {
            Node *temp=_searchData(data,root);
            if(temp==NULL)
            {
                cout<<data<<" not found"<<endl;
            }
            else
            {
                cout<<temp->data<<" found"<<endl;
            }
            
        }

        //funcion for getting the height of root node
        int getRootHeight()
        {
            return _getHeight(root)-1;
        }
        
};

int main()
{

    //variable for a bst   
    BinarySearchTree b;
   
    //inserting data in the bst
    b.insertData(10);
    b.insertData(2);
    b.insertData(12);
    b.insertData(1);
    b.insertData(7);
    b.insertData(4);
    b.insertData(8);

    //printing inorder traversal of bst
    b.inorderTraversal(b.getRoot());

    //printing height of the root node
    cout<<endl<<"height of the root node="<<b.getRootHeight()<<endl;
    
    //searching some data
    b.searchData(12);
    b.searchData(34);
    

    return 0;

}