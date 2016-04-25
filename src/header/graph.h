/**
 * @file   Graph.h
 * @brief  Undirected Graph
 *
 * @author Ethan Slattery && Osvaldo Moreno Ornelas
 * @date   7-APR-2016
 */

#ifndef DATA_STRUCTURES_GRAPH_H
#define DATA_STRUCTURES_GRAPH_H
#define DEBUG 0

#include <vector>
#include <list>
#include <fstream>
#include <iostream>
#include "edge.h"
#include "vertex.h"
using std::ostream;
using std::cout;
using std::endl;

/**
 *
 */
template <typename E>
class Graph {
public:
    /*** FORWARD DECLARE NESTED CLASSES ***/
    class Vertex;
    class Edge;
    /*** TYPEDEF FOR CLASS USE ***/
    typedef std::list<Vertex> VertexList;
    typedef std::list<Edge> EdgeList;
    typedef typename VertexList::iterator VertexItr;
    typedef typename EdgeList::iterator EdgeItr;
    typedef std::list<EdgeItr> EdgeItrList;
    typedef typename EdgeItrList::iterator EdgeItrItr;

    /*** GRAPH INTERFACE ***/
    // Basic Constructor
    Graph() : vertices_() {}
    // Returns a list of all vertices in the graph
    VertexList vertices() { return vertices_; }
    // Returns a list of all edges in the graph
    EdgeList edges() { return edges_; }
    // Inserts a new vertex storing element e
    void insertVertex(const E& e);
    // Inserts a new undirected edge connecting 'v' and 'w' and storing 'x'
    void insertEdge(const E &v, const E &w, const int &x);
    // Removes vertex 'v' and all its incident edges
//    eraseVertex(v);
    // Removes the edge e
//    eraseEdge(e);
    // Print the graph as a dot text file
    void print(std::ofstream &output, std::string title = "Graph Output");
    // Depth First Search Traversal of the graph. Returns an ordered VertexList
    VertexList dft(const E &e);

protected:
    // Finds the vertex containing 'e' and returns an iterator to that vertex
    VertexItr findVertex(const E &e);
    // Depth First Search Traversal of the graph. Returns an ordered VertexList
    void dftHelper(Vertex &location, VertexList &outList);

private:
    VertexList vertices_;   // List of vertex
    EdgeList   edges_;      // List of Edges
};

/******************************************************************************
 *                          IMPLEMENTATION OF GRAPH METHODS                   *
 ******************************************************************************/

template <typename E>
typename Graph<E>::VertexItr  Graph<E>::Edge::opposite(Vertex v)
{
  if(v == *start_){
      return end_;
  }
  else if(v == *end_){
      return start_;
  }
  else{
	  std::cout << "***** ERROR - NODE NOT INCIDENT *****\n";std::cout.flush();
  }
}

/**
 * @brief prints the graph to a dot output file with the given title
 * @param output [IN] reference to an output file stream
 * @param title  [IN] Title for the graph
 */
template <typename E>
void Graph<E>::print(std::ofstream &output, std::string title) {
    output << "graph \"" << title << "\" {\n"
              "  graph [label=\"" << title << "\", labeloc=t, fontsize=24, "
              "page=\"8.5,11\", center=true, orientation=landscape, "
              "size=\"10,7.5, \"ratio=compress];\n  overlap=false;\n";

    // OUTPUT THE VERTICES
    for(VertexItr itr = vertices_.begin(); itr != vertices_.end(); itr++){
        output << "  \"" << **itr << "\"";
        output << ( (*itr).visited() ? " [style=filled, color=blue, fontcolor=white];\n" : ";\n");
    }

    for(EdgeItr itr = edges_.begin(); itr != edges_.end(); itr++){
        output << "  \"" << *((*itr).start()) << "\" -- \"" << *((*itr).end()) << "\" [";
        output << "label=\"" << (*itr).weight() << "\", len=" << (*itr).weight() ;
        output << ( (*itr).visited() ? ", style=bold, color=blue];\n" : "];\n");
    }

    output << "}\n";
}

/**
 * @brief Adds a vertex to the graph with the data 'x'
 */
template <typename E>
void Graph<E>::insertVertex(const E &e) {
    bool found = false;     //
    Vertex tempVertex(e);   //

    // Check if vertex is already in the graph
    VertexItr searchItr = vertices_.begin();
    while(searchItr != vertices_.end() && !found){
        if( (*searchItr) == tempVertex){
            found = true;
        }
        else {
            searchItr++;
        }
    }

    if(!found){
        vertices_.push_back(tempVertex);
        searchItr = vertices_.end();
        searchItr--;
    }
    (*searchItr).setData(e);
    (*searchItr).setItr(searchItr);
}

/**
 * @breif performs a depth first traversal starting at vertex E
 * @param e [IN] the starting element
 */
template <typename E>
typename Graph<E>::VertexList Graph<E>::dft(const E &e) {
    VertexItr eItr = findVertex(e);
    VertexList outList;

    dftHelper(*eItr, outList);
    return outList;
}

/**
 *
 */
template <typename E>
void Graph<E>::dftHelper(Vertex &location, VertexList &outList) {
    // Mark this vertex as visited
std::cout << location << endl << endl;

	location.visit();

//std::cout << location << location.visited() << endl;
//for(VertexItr i = vertices_.begin(); i != vertices_.end(); i++){
//	cout << *i << (*i).visited() << " - ";
//}
//cout << endl;
//std::cin.get();

    EdgeItrList edges = location.incidentEdges();

    for(EdgeItrItr itr = edges.begin(); itr != edges.end(); itr++){
    	if(!(**itr).visited()){
    		VertexItr w = (**itr).opposite(location);
    		if(!(*w).visited()){
    			(**itr).visit();
    			std::cout << **itr << endl << endl;
    			dftHelper(*w, outList);
    		}
    	}
    }
}


/**
 *
 */
template <typename E>
typename Graph<E>::VertexItr Graph<E>::findVertex(const E &e) {
    bool found = false;
    VertexItr outVal = vertices_.begin();

    while(outVal != vertices_.end() && !found){
        if(**outVal == e){
            found = true;
        }
        else{
            outVal++;
        }
    }

    return outVal;
}

#endif //DATA_STRUCTURES_GRAPH_H
