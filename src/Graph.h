#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using namespace std;

class Graph{
    private:
        int n;
        vector<vector<int> > list;
    public:
        Graph(int N);

        Graph();

        void addEdge(int u, int v);

        int size();

        const vector<vector<int> >& getAdjacentList();
};

#endif // !GRAPH_H