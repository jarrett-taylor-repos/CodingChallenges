#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

bool DiffByOneLetter(string a, string b) {
    if(a.length() != b.length()) return false;

    int diff = 0;
    for(int i = 0; i < a.length(); i++) {
        if(a[i] != b[i]) diff++;
        if(diff > 2) return false;
    }
    return diff == 1;
}

class Graph {
    public:
    map<string, vector<string> > adjacent;

    Graph(vector<string> wordList) {
        int size = wordList.size();
        for(int i = 0; i < size-1; i++) {
            for(int j = i; j < size; j++) {
                //addedge for both ways
                if(DiffByOneLetter(wordList[i], wordList[j])) {
                    AddEdge(wordList[i], wordList[j]);
                }
            }
        }
    }

    void AddEdge(string a, string b) {
        adjacent[a].push_back(b);
        adjacent[b].push_back(a);
    }

    void Print() {
        for(pair<string, vector<string>> pair : adjacent) {
            cout << pair.first << " -> ";
            for(string word : pair.second) {
                cout << word << " ";
            }
            cout << endl;
        }
    }

    
};

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    bool containsEndWord = false;
    for(int i = 0; i < wordList.size(); i++) {
        if(endWord == wordList[i]) {
            containsEndWord = true;
            break;
        }
    }
    if(!containsEndWord) return 0;

    //need to create links bewteen words that differe by one letter
    wordList.push_back(beginWord);
    Graph g(wordList);
    g.Print();

    //determine shortest path using dijkstra's algorithm, where each weight of an edge is 1 


}

int main() {
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit";
    string endWord = "cog";

    cout << ladderLength(beginWord, endWord, wordList);
    return 0;
}