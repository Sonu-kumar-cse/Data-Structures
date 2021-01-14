#include<iostream>
using namespace std;

class AVLTree
{
    private:
        struct Node
        {
            int data;
            Node *left;
            Node *right;
        };

        Node *root;

    public:
        AVLTree()
        {
            root=NULL;
        }
        
        Node* insertData(int data)
        {
            //kya karana hai mereko koi to battao
            

        }

};

int main()
{


    return 0;
}