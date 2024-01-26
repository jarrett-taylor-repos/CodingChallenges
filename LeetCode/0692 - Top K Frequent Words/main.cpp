#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct Compare {
    bool operator()(pair<string, int> a, pair<string, int> b){
        if(a.second == b.second) {
            bool test = (a.first > b.first);
            return test;
        }
        bool temp = (a.second-b.second);
        return temp;
    }
};

void Print(map<string, int> hash) {
    map<string, int>::iterator it;
    for(it = hash.begin(); it != hash.end(); it++) {
        cout << it->first << " - " << it->second << endl; 
    }
}

void Print(vector<string> vect) {
    for(int i = 0; i < vect.size(); i++) {
        cout << vect[i] << endl;
    }
}

vector<string> topKFrequent(vector<string>& words, int k) {
    //get frequencies of all words O(n)
    //order with priroity queue, order by frquency and then by lexical value (ie a before b and b before c)
    map<string, int> hash; 
    for(string word : words) {
        map<string, int>::iterator it = hash.find(word);
        if(it != hash.end()) {
            it->second++;
        } else {
            hash.insert(pair<string, int>(word, 1));
        }
    }

    //Print(hash);

    priority_queue<pair<string, int>, vector<pair<string, int> >, Compare> pq;

    for(pair<string, int> pair : hash) {
        pq.push(pair);
        if(pq.size() > k) pq.pop();
    }

    vector<string> topk;
    while(!pq.empty()) {
        string elem = pq.top().first;
        topk.push_back(elem);
        pq.pop();
    }
    return topk;
}

int main(){
    vector<string> words = {"i","love","leetcode","i","love","coding"};
    int k = 2;

    vector<string> topk = topKFrequent(words, k);
    Print(topk);

    return -1;
}