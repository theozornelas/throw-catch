/**
 * @file   Graph.h
 * @brief  Undirected Graph
 *
 * @author Ethan Slattery && Osvaldo Moreno Ornelas
 * @date   7-APR-2016
 */

#ifndef DATA_STRUCTURES_GRAPH_H
#define DATA_STRUCTURES_GRAPH_H
#define VERBOSE_DEBUG 0
#define EXTRA_VERBOSE_DEBUG 0

#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <QDebug>

/**
 *  @brief Undirected Graph
 *  A graph with built in algorithms and features
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

    /**
     * @brief The Vertex class
     */
    class Vertex {
    public:
        // Basic Constructor
        Vertex(const E& data) : data_(data), visited_(false) {}
        // Sets the data stored in this vertex to a new value
        void setData(const E& data) { data_ = data; }
        // Sets the state of this vertex to visited
        void visit() { visited_ = true; }
        // Sets the state of this vertex to unvisited
        void resetVisited() { visited_ = false; }

        // Return an edge list of the edges incident on 'u'
        EdgeItrList incidentEdges() { return incident_; }
        // Adds an edge connecting this vertex to vertex 'v'
        //void addEdge(EdgeItr newEdge) { incident_.push_back(newEdge); }
        void addEdge(EdgeItr newEdge) {
            EdgeItrItr insertPoint = incident_.begin();
            while( insertPoint != incident_.end()
                   && **insertPoint < *newEdge){ insertPoint++; }
            incident_.insert(insertPoint, newEdge);
        }

        // Checks if this vertex has been visited
        bool visited() { return visited_; }
        // Test whether this vertex and vertex 'v' are adjacent
        bool isAdjacentTo(const E& v);

        /*** OPERATOR OVERLOADS ***/
        // Overload the output stream operator
        friend QDebug operator<<(QDebug output, const Vertex &obj) {
            output << "[" << obj.data_ << "]";
            return output;
        }
        // Overload for the * Operator
        E& operator*() { return data_; }
        // Overload all the comparison operators
        bool operator==(const Vertex &other) const { return this->data_ == other.data_; }
        bool operator!=(const Vertex &other) const { return this->data_ != other.data_; }
        bool operator>(const Vertex &other)  const { return this->data_ > other.data_ ; }
        bool operator<(const Vertex &other)  const { return this->data_ < other.data_ ; }
        bool operator>=(const Vertex &other) const { return this->data_ >= other.data_ ; }
        bool operator<=(const Vertex &other) const { return this->data_ <= other.data_ ; }

    private:
        E    data_;            // Data stored at this node
        bool visited_;         // Has this vertex been visited?
        EdgeItrList incident_; // Adjacency list of edges
    };  // END OF VERTEX CLASS

    /**
     * @brief The Edge class
     */
    class Edge {
    public:
        // Basic Constructor for the edge class
        Edge(const int &weight = 0) : weight_(weight), visited_(false) {}
        // Sets the end vertex of this edge
        void setEnd(VertexItr newEnd){end_ = newEnd;}
        // Sets the start vertex of this edge
        void setStart(VertexItr newStart ){start_ = newStart;}
        // Sets the state of this vertex to visited
        void visit() { visited_ = true; }
        // Sets the state of this vertex to unvisited
        void resetVisited() { visited_ = false; }

        // Returns vertex at the beginning of this edge
        Vertex start() { return *start_; }
        // Returns vertex at the beginning of this edge
        Vertex end() { return *end_; }
        // Returns the weight of the edge
        int weight() { return weight_; }
        // Return the end vertex of this edge distinct from vertex v
        // an error occurs if this edge is not incident on v
        VertexItr opposite(Vertex v);

        // Test whether this edge is adjacent to edge f
        bool isAdjacentTo(Edge f);
        // Test whether this edge is incident on v
        bool isIncidentOn(Vertex v);
        // Checks if this vertex has been visited
        bool visited() { return visited_; }

        /*** OPERATOR OVERLOADS ***/
        // Overload for the * Operator
        int& operator*() { return weight_; }
        // Overload the output stream operator
        friend QDebug operator<<(QDebug output, const Edge &obj){
            output << *(obj.start_) << "<--->" << *(obj.end_);
            return output;
        }
        // Overload all the comparison operators
        bool operator==(const Edge &other) const { return this->weight_ == other.weight_; }
        bool operator!=(const Edge &other) const { return this->weight_ != other.weight_; }
        bool operator>(const Edge &other)  const { return this->weight_ >  other.weight_; }
        bool operator<(const Edge &other)  const { return this->weight_ <  other.weight_; }
        bool operator>=(const Edge &other) const { return this->weight_ >= other.weight_; }
        bool operator<=(const Edge &other) const { return this->weight_ <= other.weight_; }

    private:
        int weight_;       // weight of the edge
        bool visited_;     // Has this Edge been visited?
        VertexItr start_;  // Iterator to vertex at end of this edge
        VertexItr end_;    // Iterator to vertex at end of this edge
    }; // END EDGE CLASS

/********************************************/
/**         ACTUAL GRAPH INTERFACE         **/
/********************************************/
public:
    // Basic Constructor
    Graph() : vertices_() {}

    /***  U T I L I T Y  M E T H O D S  ***/
    // Inserts a new vertex storing element e
    void insertVertex(const E& e);
    // Inserts a new undirected edge connecting 'v' and 'w' and storing 'x'
    void insertEdge(const E &v, const E &w, const int &x);
    // Removes vertex 'v' and all its incident edges
//    eraseVertex(v);
    // Removes the edge e
//    eraseEdge(e);

    /***    G E T - T H I N G S   M E T H O D S    ***/
    // Returns a list of all vertices in the graph
    VertexList vertices() { return vertices_; }
    // Returns a list of all edges in the graph
    EdgeList edges() { return edges_; }
    // Get the number of vertices in the graph
    int numVertices() { return vertices_.size(); }
    // Get the number of edges in the graph
    int numEdges() { return edges_.size(); }
    // Print the graph as a dot text file
    void print(std::ofstream &output, std::string title = "Graph Output");

    /*** ALGORITHMS ***/
    // Depth First Search Traversal of the graph. Returns an ordered VertexList
    VertexList dft(const E &e);

protected:
    // Resets all the verticies and edges to un-visited
    void unvisitAll();
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
//    (*searchItr).setItr(searchItr);
}

/**
 * @breif performs a depth first traversal starting at vertex E
 * @param e [IN] the starting element
 */
template <typename E>
typename Graph<E>::VertexList Graph<E>::dft(const E &e) {
    VertexItr eItr = findVertex(e);
    VertexList outList;
    unvisitAll();

    dftHelper(*eItr, outList);
    return outList;
}

/**
 *
 */
template <typename E>
void Graph<E>::dftHelper(Vertex &location, VertexList &outList) {
#if VERBOSE_DEBUG
    qDebug() << location;
#endif
    // mark location as visited and add to output list
	location.visit();
    outList.push_back(location);

#if EXTRA_VERBOSE_DEBUG
qDebug() << location << location.visited() << endl;
for(VertexItr i = vertices_.begin(); i != vertices_.end(); i++){
    qDebug() << *i << (*i).visited() << " - ";
}
qDebug() << endl;
std::cin.get();
#endif

    EdgeItrList edges = location.incidentEdges();

    for(EdgeItrItr itr = edges.begin(); itr != edges.end(); itr++){
        if(!(**itr).visited()){
    		VertexItr w = (**itr).opposite(location);
    		if(!(*w).visited()){
    			(**itr).visit();
                #if VERBOSE_DEBUG
                    qDebug() << **itr;
                #endif
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

/**
 *
 */
template <typename E>
void Graph<E>::unvisitAll() {
    // Reset the edges
    for(EdgeItr i = edges_.begin(); i != edges_.end(); i++){
        i->resetVisited();
    }

    // Reset the vertices
    for(VertexItr j = vertices_.begin(); j != vertices_.end(); j++){
        j->resetVisited();
    }
}

/*****************************************************************************
 *                         IMPLEMENTATION OF VERTEX METHODS                  *
 *****************************************************************************/

/**
 * @returns TRUE if vertex 'v' is adjacent to this vertex
 */
template <typename E>
bool Graph<E>::Vertex::isAdjacentTo(const E &v) {
    bool found = false;
    EdgeItrItr itr = incident_.begin();
    while(itr != incident_.end() && !found){
        found = found || (**itr).isIncidentOn(Vertex(v));
        itr++;
    }
    return found;
}

// Inserts a new undirected edge connecting 'v' and 'w' and storing 'x'
template <typename E>
void Graph<E>::insertEdge(const E& v, const E& w, const int& x)
{
    // Create a new edge with the weight of x
    Edge newEdge(x);

    // Find out if vertex are already in list, and get position if they are
    VertexItr vItr = findVertex(v);
    VertexItr wItr = findVertex(w);

    // Create new temporary Vertex Obj for v and w
    Vertex tempV(v);
    Vertex tempW(w);

    // If V was not in the list add it
    if(vItr == vertices_.end()){
        vertices_.push_back(tempV);
        vItr = vertices_.end();
        vItr--;
    }

    // If W was not in the list add it
    if(wItr == vertices_.end()){
        vertices_.push_back(tempW);
        wItr = vertices_.end();
        wItr--;
    }

#if VERBOSE_DEBUG
    qDebug() << *vItr << newEdge << *wItr << endl;
#endif

    // Set the start and end of the edge and add it to the edge list
    newEdge.setStart(vItr);
    newEdge.setEnd(wItr);
    edges_.push_back(newEdge);

    // Add the new edge to both vertex
    EdgeItr tempEdgeItr = edges_.end();
    tempEdgeItr--;
    (*vItr).addEdge(tempEdgeItr);
    (*wItr).addEdge(tempEdgeItr);
}

/**************************************************************************
 *                          IMPLEMENTATION OF EDGE METHODS                *
 **************************************************************************/

/**
 *
 */
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
      qDebug() << "***** ERROR - NODE NOT INCIDENT *****\n";
  }
}

// bool isAdjacentTo(Edge f) (they share a common edge);
template <typename E>
bool  Graph<E>::Edge::isAdjacentTo(Edge f)
{
    return this->end_==f.end_ || this->start_==f.end_;
}

// Test whether this edge is incident on v (they share a common vertex)
template <typename E>
bool  Graph<E>::Edge::isIncidentOn(Vertex v)
{
    return *start_== v || *end_==v;
}


#endif //DATA_STRUCTURES_GRAPH_H
