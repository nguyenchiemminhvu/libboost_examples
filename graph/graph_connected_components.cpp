#include <iostream>
#include <vector>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/connected_components.hpp>
#include <boost/graph/graph_utility.hpp>

int main()
{
    boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS> graph;

    boost::add_edge(boost::vertex(0, graph), boost::vertex(1, graph), graph);
    boost::add_edge(boost::vertex(1, graph), boost::vertex(2, graph), graph);
    boost::add_edge(boost::vertex(1, graph), boost::vertex(4, graph), graph);
    boost::add_edge(boost::vertex(2, graph), boost::vertex(3, graph), graph);
    boost::add_edge(boost::vertex(3, graph), boost::vertex(5, graph), graph);
    boost::add_edge(boost::vertex(3, graph), boost::vertex(6, graph), graph);
    boost::add_edge(boost::vertex(4, graph), boost::vertex(2, graph), graph);

    int n = boost::num_vertices(graph);
    std::cout << n << " vertices" << std::endl;
    boost::print_graph(graph);

    std::vector<int> components(n);
    int num_component = boost::connected_components(graph, &components[0]);

    std::cout << num_component << " components" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Vertex " << i << " is in component " << components[i] << std::endl;
    }

    boost::remove_edge(boost::vertex(3, graph), boost::vertex(5, graph), graph);
    boost::remove_edge(boost::vertex(3, graph), boost::vertex(6, graph), graph);
    
    num_component = boost::connected_components(graph, &components[0]);

    std::cout << num_component << " components" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Vertex " << i << " is in component " << components[i] << std::endl;
    }

    return 0;
}