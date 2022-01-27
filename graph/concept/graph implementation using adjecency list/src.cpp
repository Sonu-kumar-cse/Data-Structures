#include<bits/stdc++.h>
using namespace std;

class Graph
{
    private:
        struct Node
        {
            int data;
            Node* next;
            Node(int d)
            {
                data=d;
                next=NULL;
            }
        };
        vector<Node*> graph;
        int vertex,edge;
        
        void addEdge(int source,int destination)
        {
            if(graph[source]==NULL)
            {
                graph[source]=new Node(destination);
            }
            else
            {
                Node *temp=graph[source];
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=new Node(destination);
            }

            if(graph[destination]==NULL)
            {
                graph[destination]=new Node(source);
            }
            else
            {
                Node *temp=graph[destination];
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=new Node(source);
            }
        }        
    public:

        Graph(int v,int e)
        {
            vertex=v;
            edge=e;
            
            for(int i=0;i<vertex;i++)
            {
                graph.push_back(NULL);
            }

        }

        void createGraph()
        {
            int source,destination;
            for(int i=0;i<edge;i++)
            {
                cout<<"source :";
                cin>>source;
                cout<<"destination :";
                cin>>destination;
                addEdge(source,destination);
            }
        }

        void BFSTraveral()
        {
            int vistited[vertex];
            for(int i=0;i<vertex;i++)
            {
                vistited[i]=0;
            }
            queue<int> q;
            q.push(0);
            vistited[0]=1;
            while(!q.empty())
            {
                cout<<q.front()<<" ";
                Node* temp=graph[q.front()];
                while(temp!=NULL)
                {
                    if(vistited[temp->data]==0)
                    {
                        q.push(temp->data);
                        vistited[temp->data]=1;
                    }
                    temp=temp->next;
                }
                q.pop();
            }
            cout<<endl;
        }
        bool _dfsRecursive(int source,int destination,bool *visited)
        {
            if(source==destination) return true;
            Node *temp=graph[source];
            visited[source]=true;
            while(temp!=NULL)
            {
                if(temp->data==destination) return true;
                if(!visited[temp->data])
                {
                    bool found=_dfsRecursive(temp->data,destination,visited);
                    if(found) return true;
                }
                    
                temp=temp->next;
            }
            return false;

        }
        bool dfsRecursive(int source, int destination)
        {
            bool v[vertex];
            return _dfsRecursive(source,destination,v);
        }
        bool dfs(int source,int destination)
        {
            bool visited[vertex];
            visited[source]=true;
            stack<int> s;
            s.push(source);
            while(!s.empty())
            {
                int curr=s.top();
                s.pop();
                if(curr== destination) return true;
                Node* temp= graph[curr];
                while(true)
                {
                    if(temp==NULL) break;
                    if(!visited[temp->data])
                    {
                        s.push(temp->data);
                        visited[temp->data]=true;
                        break;
                    }
                    temp=temp->next;

                }
            }
            return false;
        }


};


int main()
{
    Graph g(5,6);
    g.createGraph();
    int source,destination;
    cout<<"enter source and destinatiion for checking if there any path or not ";
    cin>>source>>destination;
    if(g.dfsRecursive(source,destination))
    {
        cout<<"possible";

    } 
    else 
    cout<<"not possible";
    return 0;
}