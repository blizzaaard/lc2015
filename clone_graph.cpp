// #133 Clone Graph
//
// Clone an undirected graph. Each node in the graph contains a label and a
// list of its neighbors.
//
// OJ's undirected graph serialization:
//
// Nodes are labeled uniquely.
//
// We use # as a separator for each node, and , as a separator for node label
// and each neighbor of the node.
//
// As an example, consider the serialized graph {0,1,2#1,2#2,2}.
//
// The graph has a total of three nodes, and therefore contains three parts as
// separated by #.
//
// First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
//
// Second node is labeled as 1. Connect node 1 to node 2.
//
// Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming
// a self-cycle.
//
// Visually, the graph looks like the following:
//
//        1
//       / \
//      /   \
//     0 --- 2
//          / \
//          \_/


#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

struct UndirectedGraphNode {
    int label;
    std::vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {

  public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        typedef UndirectedGraphNode Node;
        if (!node) {
            return 0;
        }
        Node *copy = new Node(node->label);

        std::queue<Node *>                 queue;
        std::unordered_map<Node *, Node *> map;

        queue.push(node);
        map[node] = copy;
        while (!queue.empty()) {
            Node *node = queue.front();
            queue.pop();
            for (int i = 0; i < node->neighbors.size(); ++i) {
                Node *neighbor = node->neighbors[i];
                if (map.end() == map.find(neighbor)) {
                    Node *neighborCopy = new Node(neighbor->label);
                    map[neighbor] = neighborCopy;
                    queue.push(neighbor);
                    map[node]->neighbors.push_back(neighborCopy);
                } else {
                    map[node]->neighbors.push_back(map[neighbor]);
                }
            }
        }
        return copy;
    }
};

int main()
{
    Solution s;
    UndirectedGraphNode node1(1);
    s.cloneGraph(&node1);
    return 0;
}
