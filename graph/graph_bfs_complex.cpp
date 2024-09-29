#include <iostream>
#include <string>
#include <utility>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/graph/visitors.hpp>

class bfs_visitor : public boost::default_bfs_visitor
{
public:
    template <typename Vertex, typename Graph>
    void discover_vertex(Vertex u, const Graph& g) const
    {
        std::cout << "Discovered city: " << g[u].name << std::endl;
    }

    template <typename Edge, typename Graph>
    void examine_edge(Edge e, const Graph& g) const
    {
        std::cout << "Traversing road from " 
                  << g[source(e, g)].name << " to " 
                  << g[target(e, g)].name 
                  << " with distance: " << g[e].distance << " km\n";
    }
};

struct City
{
    std::string name;
};

struct Road
{
    double distance;
};

typedef boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS, City, Road> Graph;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;
typedef boost::graph_traits<Graph>::edge_descriptor Edge;

void add_city(Graph& g, const std::string& name)
{
    Vertex v = boost::add_vertex(g);
    g[v].name = name;
}

void add_road(Graph& g, const std::string& city1, const std::string& city2, double distance)
{
    Vertex v1, v2;
    bool found1 = false, found2 = false;
    
    for (auto v : boost::make_iterator_range(vertices(g)))
    {
        if (g[v].name == city1) v1 = v, found1 = true;
        if (g[v].name == city2) v2 = v, found2 = true;
    }

    if (found1 && found2)
    {
        Edge e;
        bool inserted;
        boost::tie(e, inserted) = boost::add_edge(v1, v2, g);
        if (inserted)
        {
            g[e].distance = distance;
        }
    }
}

int main()
{
    Graph g;

    add_city(g, "New York");
    add_city(g, "Los Angeles");
    add_city(g, "Chicago");
    add_city(g, "Houston");
    add_city(g, "Phoenix");

    add_road(g, "New York", "Los Angeles", 3940);
    add_road(g, "New York", "Chicago", 1270);
    add_road(g, "Chicago", "Houston", 1750);
    add_road(g, "Houston", "Phoenix", 1600);
    add_road(g, "Los Angeles", "Phoenix", 600);

    bfs_visitor vis;

    Vertex start;
    for (auto v : boost::make_iterator_range(vertices(g)))
    {
        if (g[v].name == "New York")
        {
            start = v;
            break;
        }
    }

    boost::breadth_first_search(g, start, boost::visitor(vis));

    return 0;
}
