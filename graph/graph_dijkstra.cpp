#include <iostream>
#include <vector>
#include <limits>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

struct EdgeWeight
{
    int weight;
};

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, boost::no_property, EdgeWeight> Graph;

typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;
typedef boost::graph_traits<Graph>::edge_descriptor Edge;

typedef boost::property_map<Graph, int EdgeWeight::*>::type WeightMap;

int main()
{
    Graph graph;

    boost::add_edge(0, 1, EdgeWeight{10}, graph);
    boost::add_edge(0, 4, EdgeWeight{5}, graph);
    boost::add_edge(1, 2, EdgeWeight{1}, graph);
    boost::add_edge(1, 4, EdgeWeight{2}, graph);
    boost::add_edge(2, 3, EdgeWeight{4}, graph);
    boost::add_edge(3, 0, EdgeWeight{7}, graph);
    boost::add_edge(3, 2, EdgeWeight{6}, graph);
    boost::add_edge(4, 1, EdgeWeight{3}, graph);
    boost::add_edge(4, 2, EdgeWeight{9}, graph);
    boost::add_edge(4, 3, EdgeWeight{2}, graph);

    std::vector<int> distances(boost::num_vertices(graph), (std::numeric_limits<int>::max)());
    std::vector<Vertex> predecessors(boost::num_vertices(graph));

    WeightMap weight_map = get(&EdgeWeight::weight, graph);

    Vertex source = 0;
    boost::dijkstra_shortest_paths(
        graph, 
        source,
        boost::predecessor_map(
            boost::make_iterator_property_map(
                predecessors.begin(), 
                boost::get(boost::vertex_index, graph)
            )
        ).distance_map(
            boost::make_iterator_property_map(
                distances.begin(), 
                boost::get(boost::vertex_index, graph)
            )
        ).weight_map(weight_map)
    );

    std::cout << "Distances from source vertex " << source << ":\n";
    for (int i = 0; i < boost::num_vertices(graph); ++i)
    {
        std::cout << "Distance to vertex " << i << " is " << distances[i] << '\n';
    }

    std::cout << "\nPredecessors in the shortest path tree:\n";
    for (int i = 0; i < boost::num_vertices(graph); ++i)
    {
        std::cout << "Predecessor of vertex " << i << " is vertex " << predecessors[i] << '\n';
    }

    return 0;
}
