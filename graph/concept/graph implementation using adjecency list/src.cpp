#include<iostream>
#include<vector>
using namespace std;

class Graph
{
    private:
        int totalNodes;
        int totalEdges;
        vector<vector<int>> graph;
    public:
        Graph(int nodes, int edges)
        {
            totalNodes=nodes;
            totalEdges=edges;
            
            for(int i=0;i<nodes;i++)
            {
                vector<int> v;
                graph.push_back(v);
            }
            cout<<"enter edges"<<endl;
            for(int i=0;i<edges;i++)
            {
                int source,destination;
                cin>>source>>destination;
                graph[source].push_back(destination);
                graph[destination].push_back(source);
            }
            cout<<"graph created"<<endl;
        }
        void printGraph()
        {
            for(int i=0;i<graph.size();i++)
            {
                cout<<i<<" -> ";
                for(int j=0;j<graph[i].size();j++)
                {
                    cout<<graph[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        
};


int main()
{
    Graph g(5,6);
    g.printGraph();
}