#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
#include <list>
#include "dijkstras.h"

using namespace std;

/*
constexpr int INF = numeric_limits<int>::max();

struct Edge {
    int src=0;
    int dst=0;
    int weight=0;
    Edge(int s = 0, int d = 0, int w = 0) : src(s), dst(d), weight(w) {}
    friend istream& operator>>(istream& in, Edge& e)
    {
        return in >> e.src >> e.dst >> e.weight;
    }

    friend ostream& operator<<(ostream& out, const Edge& e)
    {
        return out << "(" << e.src << "," << e.dst << "," << e.weight << ")";
    }
};
*/

/*
struct Graph : public vector<vector<Edge>> {
    int numVertices=0;
};

inline istream& operator>>(istream& in, Graph& G) {
    if (!(in >> G.numVertices))
        throw runtime_error("Unable to find input file");
    G.resize(G.numVertices);
    for (Edge e; in >> e;)
        G[e.src].push_back(e);
    return in;
}

inline void file_to_graph(const string& filename, Graph& G) {
    ifstream in(filename);
    if (!in) {
        throw runtime_error("Can't open input file");
    }
    in >> G;
    in.close();
}
*/


class Compare { public: bool operator()(pair<int, int> a, pair<int, int> b) { return a.first > b.first; } };


vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int size = G.numVertices;
    vector<int> distances(size, INF);
    distances[source] = 0;
    previous.assign(size, -1);

    vector<bool> visited(size, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    pq.push({0, source});

    while (!pq.empty()){
        int currentDistance = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        if (visited[currentVertex]) continue;

        visited[currentVertex] = true;

        for (Edge neighbor : G[currentVertex]){
            int neighborWeight = neighbor.weight;
            int neighborVertex = neighbor.dst;

            if (!visited[neighborVertex] && (distances[currentVertex] + neighborWeight < distances[neighborVertex])){
                distances[neighborVertex] = distances[currentVertex] + neighborWeight;
                previous[neighborVertex] = currentVertex;
                pq.push({distances[neighborVertex], neighborVertex});
            }
        }
    } 
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination){
    vector<int> path;
    for (int curr = destination; curr != -1; previous[curr]) path.push_back(curr);
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total){
    for (int i : v) { cout << i << " "; }
    cout << endl << "Total cost is " << total << endl;
}