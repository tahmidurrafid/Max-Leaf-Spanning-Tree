#include "AbstractAlgorithm.h"
#include "algorithms/DegreeProbAlgorithm.cpp"
#include "algorithms/GreedyVertexAlgorithm.cpp"
#include "algorithms/LocalSearchAlgorithm.cpp"
#include "algorithms/TwoApprox.cpp"
#include "algorithms/BfsAlgorithm.cpp"
#include "SpanningTree.h"
#include <vector>

using namespace std;

int main(){
    freopen("input.txt","r",stdin);

    int n, m;
    cin >> n >> m;

    Graph g(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    AbstractAlgorithm* algorithm = new BfsAlgorithm(g);

    SpanningTree * bfsTree = (SpanningTree *)algorithm->execute();

    cout << "Is tree?" << bfsTree->verify(g) << "\n";
    cout << "Leaves Count" << bfsTree->getLeavesCount() << "\n";

    AbstractAlgorithm* localSearch = new LocalSearchAlgorithm(g);
    localSearch->initiate(*bfsTree);

    SpanningTree * output = (SpanningTree *)localSearch->execute();

    cout << "Is tree?" << output->verify(g) << "\n";
    cout << "Leaves Count" << output->getLeavesCount() << "\n";

    return 0;
}
