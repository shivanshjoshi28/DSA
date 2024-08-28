#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Vertex {
    int index;
    int degree;
};

// Comparator to sort vertices based on degree
bool compareDegree(const Vertex& v1, const Vertex& v2) {
    return v1.degree > v2.degree;
}

void calculateDegree(const std::vector<std::vector<int>>& graph, std::vector<int>& degrees) {
    int n = graph.size();
    for (int i = 0; i < n; i++) {
        degrees[i] = graph[i].size();
    }
}

// Function to perform BFS and find chromatic number
int bfsColoring(const std::vector<std::vector<int>>& graph, const std::vector<Vertex>& vertices) {
    int n = graph.size();
    std::vector<int> result(n, -1);  // Color of each vertex
    std::vector<bool> availableColors(n, false);  // Available colors tracker

    for (const auto& v : vertices) {
        int u = v.index;

        // Mark colors of adjacent vertices as unavailable
        for (int adj : graph[u]) {
            if (result[adj] != -1) {
                availableColors[result[adj]] = true;
            }
        }

        // Find the first available color
        int color;
        for (color = 0; color < n; color++) {
            if (!availableColors[color]) {
                break;
            }
        }

        // Assign the found color to the current vertex
        result[u] = color;

        // Reset the availableColors array for the next vertex
        for (int adj : graph[u]) {
            if (result[adj] != -1) {
                availableColors[result[adj]] = false;
            }
        }
    }

    // The chromatic number is the maximum color assigned plus one
    int chromaticNumber = *std::max_element(result.begin(), result.end()) + 1;

    return chromaticNumber;
}

int main() {
    // Example graph represented as an adjacency list
    std::vector<std::vector<int>> graph = {
        {1, 2, 3},  // Vertex 0 is connected to vertices 1, 2, 3
        {0, 2},     // Vertex 1 is connected to vertices 0, 2
        {0, 1, 3},  // Vertex 2 is connected to vertices 0, 1, 3
        {0, 2}      // Vertex 3 is connected to vertices 0, 2
    };

    int n = graph.size();
    std::vector<int> degrees(n, 0);
    calculateDegree(graph, degrees);

    // Create a list of vertices with their degrees
    std::vector<Vertex> vertices(n);
    for (int i = 0; i < n; i++) {
        vertices[i] = {i, degrees[i]};
    }

    // Sort vertices by their degree in descending order
    std::sort(vertices.begin(), vertices.end(), compareDegree);

    // Find the chromatic number using BFS coloring
    int chromaticNumber = bfsColoring(graph, vertices);

    std::cout << "The chromatic number of the graph is: " << chromaticNumber << std::endl;

    return 0;
}

/*
Ref : Chatgpt
TC: O(v log v) + O(v+e)


Other method : BruteForce, try filling every color M^V
Other method : Greedy -> using set : https://www.geeksforgeeks.org/chromatic-number-of-a-graph-graph-colouring/

*/

