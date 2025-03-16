#include "dijkstras.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    Graph G;
    file_to_graph("./src/small.txt", G);

    vector<int> previous;

    vector<int> paths = dijkstra_shortest_path(G, 0, previous);

    for (vector<Edge> dist : G){
        for (Edge edg : dist){
            cout << edg << " ";
        }
        cout << endl;
    }

    for (int dist : paths) cout << dist << " ";


    return -1;
}
// g++ ./src/dijkstras_main.cpp ./src/dijkstras.cpp -o main -std=c++20

// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./main