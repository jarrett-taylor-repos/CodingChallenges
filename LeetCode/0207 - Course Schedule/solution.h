#include <iostream>
#include <vector>
#include <map>
using namespace std;


namespace Solution {
    class Graph {
        public:
        map<int, bool> visited;
        map<int, vector<int> > adjacent;

        Graph(vector<vector<int>> prereqs) {
            for(int i = 0; i < prereqs.size(); i++) {
                vector<int> courses =  prereqs[i];
                addEdge(courses);
            }
        }

        void addEdge(vector<int> courses) {
            int vertex = courses[1];
            int dest = courses[0];
            adjacent[vertex].push_back(dest);
        }

        //v is the start node
        void DFS(int v, bool& hasCycle) {
            visited[v] = true;
            
            vector<int>::iterator i;
            for(i = adjacent[v].begin(); i != adjacent[v].end(); i++) {
                if(visited[*i]) {
                    hasCycle = false; 
                    return;
                } else {
                    DFS(*i, hasCycle);
                }
            }
            return;
        }

        void PrintGraph() {
            map<int, vector<int>>::iterator i;
            for(i = adjacent.begin(); i != adjacent.end(); i++) {
                cout << i->first;
                cout << " "; 
                Print(i->second);
                cout << endl;
            }
        }

        void Print(vector<int> v) {
            for(int i = 0; i < v.size(); i++) {
                cout << v[i] << " ";
            }
        }
    };


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //need a graph with no cycles for condiiton to be true 

        //set of visited and visiting nodes
        //if we are visiting a node that exists in visted, return false
        //this can be done with dfs after creating a graph 

        Graph g(prerequisites);
        //g.PrintGraph();
        bool can = true;
        g.DFS(prerequisites[0][0], can);
        return can;
    }
}