// #207 Course Schedule
//
// There are a total of n courses you have to take, labeled from 0 to n - 1.
//
// Some courses may have prerequisites, for example to take course 0 you have
// to first take course 1, which is expressed as a pair: [0,1]
//
// Given the total number of courses and a list of prerequisite pairs, is it
// possible for you to finish all courses?
//
// For example:
//
// 2, [[1,0]]
//
// There are a total of 2 courses to take. To take course 1 you should have
// finished course 0. So it is possible.
//
// 2, [[1,0],[0,1]]
//
// There are a total of 2 courses to take. To take course 1 you should have
// finished course 0, and to take course 0 you should also have finished course
// 1. So it is impossible.
//
// Note:
//
// The input prerequisites is a graph represented by a list of edges, not
// adjacency matrices. Read more about how a graph is represented.
//
// Hints:
//
// This problem is equivalent to finding if a cycle exists in a directed graph.
// If a cycle exists, no topological ordering exists and therefore it will be
// impossible to take all courses.
//
// Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera
// explaining the basic concepts of Topological Sort.
//
// Topological sort could also be done via BFS.


class Solution {

    bool toposortImp(const vector< list<int> >& nodes,
                     int                        node,
                     vector<int>&               visited)
    {
        if (1 == visited[node]) return false;
        else if (2 == visited[node]) return true;
        else {
            visited[node] = 1;
            for (list<int>::const_iterator it  = nodes[node].begin();
                                           it != nodes[node].end();
                                         ++it)
            {
                if (!toposortImp(nodes, *it, visited)) return false;
            }
            visited[node] = 2;
        }
        return true;
    }

    bool toposort(const vector< list<int> >& nodes)
    {
        // 0 - not visited
        // 1 - visiting
        // 2 - visited
        vector<int> visited(nodes.size(), 0);

        for (int i = 0; i < nodes.size(); ++i) {
            if (0 == visited[i]) {
                if (!toposortImp(nodes, i, visited)) return false;
            }
        }
        return true;
    }

  public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        vector< list<int> > nodes;
        nodes.resize(numCourses);
        for (vector< pair<int, int> >::const_iterator
                it  = prerequisites.begin();
                it != prerequisites.end();
              ++it)
        {
            nodes[it->first].push_back(it->second);
        }

        return toposort(nodes);
    }
};
