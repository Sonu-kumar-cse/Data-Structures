#include<bits/stdc++.h>
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

        int getHeightOfTree(Node* root)
        {
            if(root==NULL)
            {
                return 0;
            }
            return max(getHeightOfTree(root->left),getHeightOfTree(root->right))+1;
        }

        //level order traversal without using queue
        void _levelOrderTraversal(Node*node,int level)
        {
            if(node==NULL)
            {
                return;

            }
            if(level==1)
            {
                cout<<node->data<<" ";
            }
            if(level>1)
            {
                _levelOrderTraversal(node->left,level-1);
                _levelOrderTraversal(node->right,level-1);
            }
        }
        
        //level order traversal without using queue
        void levelOrderTraversal()
        {
            int level=getHeightOfTree(getroot());
            for(int i=1;i<=level;i++)
            {
                _levelOrderTraversal(getroot(),i);
            }
        }

        //level order traversal using queue
        void levelOrederTraversalQueue(Node* root)
        {
            queue<Node*> q;
            q.push(root);
            while(!q.empty())
            {
                Node* temp=q.front();
                q.pop();
                cout<<temp->data<<" ";
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
            }
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
    t.levelOrderTraversal();
    cout<<endl;
    t.levelOrederTraversalQueue(t.getroot());
    cout<<endl;
    
    return 0;
}