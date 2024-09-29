#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/astar_search.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/iteration_macros.hpp>
#include <boost/graph/properties.hpp>
#include <boost/graph/exception.hpp>
#include <iostream>
#include <vector>
#include <cmath>

struct goal_found : public std::exception {};

template <typename Graph, typename CostType>
class manhattan_heuristic : public boost::astar_heuristic<Graph, CostType>
{
public:
    using Vertex = typename boost::graph_traits<Graph>::vertex_descriptor;

    manhattan_heuristic(const std::vector<std::pair<int, int>>& coordinates, Vertex goal)
        : coords(coordinates), goal(goal) {}

    CostType operator()(Vertex u) {
        return static_cast<CostType>(std::abs(coords[goal].first - coords[u].first) +
                                     std::abs(coords[goal].second - coords[u].second));
    }

private:
    const std::vector<std::pair<int, int>>& coords;
    Vertex goal;
};

template <typename Vertex>
class astar_goal_visitor : public boost::default_astar_visitor
{
public:
    astar_goal_visitor(Vertex goal) : goal(goal) {}

    template <typename Graph>
    void examine_vertex(Vertex u, const Graph&)
    {
        if (u == goal)
        {
            throw goal_found();
        }
    }

private:
    Vertex goal;
};

int main()
{
    using Graph = boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS,
                                        boost::no_property, boost::property<boost::edge_weight_t, int>>;
    using Vertex = boost::graph_traits<Graph>::vertex_descriptor;

    const int num_vertices = 5;
    Graph graph(num_vertices);

    std::vector<std::pair<int, int>> vertex_coords = {{0, 0}, {1, 0}, {1, 1}, {0, 1}, {2, 2}};

    boost::add_edge(0, 1, 1, graph);
    boost::add_edge(1, 2, 1, graph);
    boost::add_edge(0, 3, 1, graph);
    boost::add_edge(3, 2, 1, graph);
    boost::add_edge(1, 4, 2, graph);
    boost::add_edge(2, 4, 1, graph);

    Vertex start = 0;
    Vertex goal = 4;

    std::vector<Vertex> predecessors(boost::num_vertices(graph));
    std::vector<int> distances(boost::num_vertices(graph), (std::numeric_limits<int>::max)());

    auto weight_map = boost::get(boost::edge_weight, graph);
    auto predecessor_map = boost::make_iterator_property_map(predecessors.begin(), boost::get(boost::vertex_index, graph));
    auto distance_map = boost::make_iterator_property_map(distances.begin(), boost::get(boost::vertex_index, graph));

    try
    {
        boost::astar_search(graph, start,
                            manhattan_heuristic<Graph, int>(vertex_coords, goal),
                            boost::predecessor_map(predecessor_map)
                                .distance_map(distance_map)
                                .visitor(astar_goal_visitor<Vertex>(goal)));

    }
    catch (const goal_found& ex)
    {
        std::cout << "Path found from " << start << " to " << goal << ":\n";
        for (Vertex v = goal; ; v = predecessors[v])
        {
            std::cout << v;
            if (predecessors[v] == v)
                break;
            std::cout << " <- ";
        }
        std::cout << std::endl;
    }

    return 0;
}
