#include "dijkstras.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    Graph G;
    file_to_graph("./src/small.txt", G);

    for (vector<Edge> dist : G){
        for (Edge edg : dist){
            cout << edg << " ";
        }
        cout << endl;
    }
    

    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);

    for (int i : previous){
        cout << "Previous " << i << endl;
    }

    for (int i : distances){
        cout << "Distances " << i << endl;
    }

    for (int i = 0; i < distances.size(); ++i){
        print_path(extract_shortest_path(distances, previous, i), distances[i]);

    }
}
