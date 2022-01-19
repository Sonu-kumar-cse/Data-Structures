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

        void iterativeInorderTraversal(Node *node)
        {
            stack<Node*> s;
            Node *curr=node;
            while (1)
            {
                while(curr!=NULL)
                {
                    s.push(curr);
                    curr=curr->left;
                }
                if(s.empty() && curr==NULL)break;
                cout<<s.top()->data<<" ";
                curr=s.top()->right;
                s.pop();
            }
            
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
        void iterativePreorderTraversal(Node *node)
        {
            stack<Node*> s;
            Node *curr=node;
            s.push(node);
            while(1)
            {
                while(curr!=NULL)
                {
                    cout<<s.top()->data<<" ";
                    curr=curr->left;
                    if(curr!=NULL)
                        s.push(curr);
                }
                if(s.empty() && curr==NULL) break;
                curr=s.top()->right;
                s.pop();
                if(curr!=NULL)
                    s.push(curr);
            }
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
        void iterativePostorderTraversalTwoStack(Node *node)
        {
            stack<Node*> s1;
            stack<Node*> s2;
            s1.push(node);
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
                if(s2.top()->left!=NULL)
                s1.push(s2.top()->left);
                if(s2.top()->right!=NULL)
                s1.push(s2.top()->right);
            }
            while(!s2.empty())
            {
                cout<<s2.top()->data<<" ";
                s2.pop();
            } 
            
        }
        void iterativePostorderTraversalOneStack(Node *node)
        {
            stack<Node*> s;
            Node *curr=node;
            Node *prev=NULL;
            while(!s.empty() || curr!=NULL )
            {
                if(curr!=NULL)
                {
                    s.push(curr);
                    curr=curr->left;
                }
                else
                {
                    curr=s.top();
                    if(curr->right==NULL || curr->right==prev)
                    {
                        cout<<curr->data<<" ";
                        s.pop();
                        prev=curr;
                        curr=NULL;
                    }
                    else
                    {
                        curr=curr->right;
                    }
                }
            }
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
    // t.inorderTraversal(t.getroot());
    // cout<<endl;
    // t.postorderTraversal(t.getroot());
    // cout<<endl;
    // t.preorderTraversal(t.getroot());
    // cout<<endl;
    // t.levelOrderTraversal();
    // cout<<endl;
    // t.levelOrederTraversalQueue(t.getroot());
    // cout<<endl;
    t.iterativePreorderTraversal(t.getroot());
    cout<<endl;
    t.iterativeInorderTraversal(t.getroot());
    cout<<endl;
    t.iterativePostorderTraversalOneStack(t.getroot());
    cout<<endl;
    t.iterativePostorderTraversalTwoStack(t.getroot());
    
    return 0;
}