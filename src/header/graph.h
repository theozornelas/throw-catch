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
#include <queue>
#include <climits>
#include <functional>
#include "HeapPriorityQueue.h"
#define INF INT_MAX

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
    typedef HeapPriorityQueue<Edge, std::less<Edge> > EdgePQueue;
    typedef std::vector<VertexItr> VertexItrVector;

    /**
     * @brief The Vertex class
     */
    class Vertex {
    public:
        // Basic Constructor
        Vertex(const E& data) : data_(data), visited_(false), distance_(INF) {}
        // Sets the data stored in this vertex to a new value
        void setData(const E& data) { data_ = data; }
        // Sets the state of this vertex to visited
        void visit() { visited_ = true; }
        // Sets the state of this vertex to unvisited
        void resetVisited() { visited_ = false; }

        // returns a vector of vertices adjacent top this vertex
        VertexItrVector adjacentVertex();

        /*** Dijkstra Methods ***/
        // Sets the distance from this vertex to the starting point
        void setDistance(const int &newValue){ distance_ = newValue;}
        // Gets the distance from the starting vertex for last dijkstra executed
        int getDistance() { return distance_; }
        // Sets the parent vertex to this vertex
        void setParent(const VertexItr &parent) { parent_ = parent; }
        // Gets the parent of this vertex in the dijkstra routing
        VertexItr getParent() { return parent_; }
        // Resets the dijkstra variables to default values
        void resetDijkstra() { distance_ = INF; }

        // Return an edge list of the edges incident on 'u'
        EdgeItrList  incidentEdges() { return incident_; }
        // Adds an edge connecting this vertex to vertex 'v'
        //void addEdge(EdgeItr newEdge) { incident_.push_back(newEdge); }
        void addEdge(EdgeItr newEdge) {
            EdgeItrItr insertPoint = incident_.begin();
            while( insertPoint != incident_.end() && **insertPoint < *newEdge){
                insertPoint++;
            }
            incident_.insert(insertPoint, newEdge);
        }

        // removes the edge pointed to by the given iterator from this adjaceny list
        void removeEdge(EdgeItr edge);

        // Checks if this vertex has been visited
        bool visited() { return visited_; }
        // Test whether this vertex and vertex 'v' are adjacent
        bool isAdjacentTo(const E& v);
        // Gets the distance from this vertex to vertex 'v'
        int distanceTo(const VertexItr &v);

        /*** DISPLAY METHODS OVERLOADS ***/
        // return the vertex as a string
        QString print();
        // Overload the output stream operator
        friend QDebug operator<<(QDebug output, const Vertex &obj) {
            output << obj.data_;
            return output;
        }
        // overload for text stream
        friend QTextStream &operator <<(QTextStream &output, const Vertex &obj){
            output << obj.data_;
            return output;
        }

        /*** OPERATOR OVERLOADS ***/
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
        int  distance_;        // total distance for dijkstra
        VertexItr   parent_;   // parent vertex for dijkstra
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
        Vertex& start() { return *start_; }
        // Returns vertex at the beginning of this edge
        Vertex& end() { return *end_; }
        // Returns the weight of the edge
        int weight() const { return weight_; }
        // Return the end vertex of this edge distinct from vertex v
        // an error occurs if this edge is not incident on v
        VertexItr opposite(Vertex v);

        // Test whether this edge is adjacent to edge f
        bool isAdjacentTo(Edge f);
        // Test whether this edge is incident on v
        bool isIncidentOn(Vertex v);
        // Checks if this vertex has been visited
        bool visited() { return visited_; }

        /*** COMPARATOR***/
        bool sortComp(Edge i,Edge j) { return (i<j); }

        /*** OPERATOR OVERLOADS ***/
        // Print Method
        QString print();


        // Overload for the * Operator
        int& operator*() { return weight_; }
        // Overload the output stream operator
        friend QDebug operator<<(QDebug output, const Edge &obj){
            output << *(obj.start_) << "<-->" << *(obj.end_);
            return output;
        }
        // overload for text stream
        friend QTextStream &operator <<(QTextStream &output, const Edge &obj){
           output << *(obj.start_) << "<-->" << *(obj.end_);
           return output;
        }

        // Overload all the comparison operators
        bool operator==(const Edge &other) const { return this->weight_ == other.weight_; }
        bool operator!=(const Edge &other) const { return this->weight_ != other.weight_; }
        bool operator>(const Edge &other) const { return this->weight_ >  other.weight_; }
        bool operator<(const Edge &other) const { return this->weight_ <  other.weight_; }
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
    // Removes vertex containing the data 'e' and all inciden edges
    void eraseVertex(const E& e);
    // Removes the edge that connects 'v' to 'w' with weight 'x'
    void eraseEdge(const E &v, const E &w, const int &x);

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

    /***   A L G O R I T H M S   ***/
    // Depth First Search Traversal of the graph. Returns an ordered VertexList
    VertexList dft(const E &e);

    // Runs the dijkstra algorithm starting from vertex with data e
    void Dijkstra(const E &e);
    // Gets the distance to 'e' from the starting point of the last Dijkstra run
    int GetDistanceTo(const E &e) { return findVertex(e)->getDistance(); }
    // Get Distance from vertex 'u' to vertex 'v' using dijkstra
    int GetDistance(const E &start, const E &end) { Dijkstra(start); return GetDistanceTo(end); }
    // Returns an ordered vertex list of the path from the last dijkstra origin to the given vertex 'e'
    VertexList shortestPathTo(const E &end);

    // Outputs the MST graph edges using the basic prim algortihm
    EdgeList MSTPrim();
    // Outputs the MST using a PQueue and PrimJarnek
    EdgeList PrimJarnek();

protected:
    // Resets all the verticies and edges to un-visited
    void unvisitAll();
    // Resets the parent and distance of all vertecies for dijkstra
    void resetDijkstra();
    // Finds the vertex containing 'e' and returns an iterator to that vertex
    VertexItr findVertex(const E &e);
    // Finds the edge connecting 'v' to 'w' with weight 'x'
    EdgeItr findEdge(const E &v, const E &w, const int &x);
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
 * @brief Get all the neightbors of this vertex
 * @return A vector of iterators pointing to vertex adjacent to this one
 */
template <typename E>
typename Graph<E>::VertexItrVector Graph<E>::Vertex::adjacentVertex()
{

    VertexItrVector neighbors;

    for(EdgeItrItr it = incident_.begin(); it != incident_.end(); it++)
    {
        neighbors.push_back( (**it).opposite(*this) );
    }

    return neighbors;
}

/**
 * @brief Inserts a new undirected edge connecting 'v' and 'w' and storing 'x'
 * @param v [IN] vertex data at 'start' of edge
 * @param w [IN] vertex data at 'end' of edge
 * @param x [IN] weight of the edge as an integer
 */
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

    // Set the start and end of the edge and add it to the edge list
    newEdge.setStart(vItr);
    newEdge.setEnd(wItr);
    edges_.push_back(newEdge);

    // Add the new edge to both vertex
    EdgeItr tempEdgeItr = edges_.end();
    tempEdgeItr--;
    (*vItr).addEdge(tempEdgeItr);
    (*wItr).addEdge(tempEdgeItr);

#if VERBOSE_DEBUG
    qDebug() << "ADDED EDGE:" << *tempEdgeItr;
#endif
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
 * @brief creates shortest path tree starting at specified vertex
 * @param e [IN] the starting vertex
 */
template<typename E>
void Graph<E>::Dijkstra(const E &e)
{
    // Comparitor class for vertexItr, pushes smallest weights to the bottom
    struct distanceCompare {
        bool operator()(const VertexItr &lhs, const VertexItr &rhs) {
            return (lhs->getDistance() > rhs->getDistance());
        }
    } compareDist;

    // Reset the weight and parent of all vertex
    resetDijkstra();
    // find the vertex to use as a starting point
    VertexItr eItr = findVertex(e);

    // set source distance to 0
    eItr->setDistance(0);

    // Load iterators to vertices into a psudo PQueue
    VertexItrVector unusedVertex;
    for(VertexItr i = vertices_.begin(); i != vertices_.end(); i++){
        unusedVertex.push_back(i);
    }

    // actual algorithm
    while(!unusedVertex.empty()){
        // re-sort every time since weights have changed
        std::sort(unusedVertex.begin(), unusedVertex.end(), compareDist);

        // grab the next vertex with the smallest distance, and then pop it
        VertexItr currentVertex = unusedVertex.back();
        unusedVertex.pop_back();

        // IF the smallest vertex has weight infintiy then it is unconnected, skip
        if( currentVertex->getDistance() != INF ){
            // get iterators to all the neightbors of current vertex
            VertexItrVector neighbors = currentVertex->adjacentVertex();
            for(typename VertexItrVector::iterator j = neighbors.begin(); j != neighbors.end(); j++){
                // relaxation algorithm
                int sumDistance = currentVertex->getDistance() + currentVertex->distanceTo(*j);
                if( sumDistance < (**j).getDistance() ){
                    (**j).setDistance(sumDistance);
                    (**j).setParent(currentVertex);
                }
            }//END FOR LOOP
        }//END INF IF STATEMENT
    }//END WHILE
}//END DIJKSTRA

/**
 * @brief Gets the distance from last dijkstra origin to end
 * @param end [IN] The ending vertex
 * @return ordered vector if vertices represeting path from last dijkstra origin to end
 */
template <typename E>
typename Graph<E>::VertexList Graph<E>::shortestPathTo(const E &end) {
    VertexItr itr      = findVertex(end);
    VertexList outList;
    bool done = false;

    while(!done){
        outList.push_front(*itr);
        if(itr->getDistance() == 0){
            done = true;
        }
        else{
            itr = itr->getParent();
        }
    }

    return outList;
}

/**
 * @brief Depth frist traversal of the graph
 * @param location [IN] the location to begin at
 * @param outList [OUT] the list of vertex in depth first order
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
 * @brief creates the Minimum Spannin Tree using Prim-Jarnek and PQueue
 * @returns A list of edge objects that make up the MST
 */
template <typename E>
typename Graph<E>::EdgeList Graph<E>::PrimJarnek() {
    unvisitAll();          // ensure all edges and vertices are unvisited
    EdgeList usedEdges;    // List of edges to use in MST, for return
    EdgePQueue edgePQ;     // Priority Queue of unused edges
    unsigned int VertexCount = 0;  // Count of vertecies visited

    // add first vertex to the list and set it to visited
    vertices_.begin()->visit();
    VertexCount++;
    // add incident edges to PQueue
    EdgeItrList incident = vertices_.begin()->incidentEdges();
    for(EdgeItrItr i = incident.begin(); i != incident.end(); i++){
        edgePQ.push(**i);
    }

    // loop while vertecies in the done cloud is less than total
    while( VertexCount < vertices_.size() ) {
        // Get Rid of any edges that are incident to two visited vertex
        while(edgePQ.top().start().visited() && edgePQ.top().end().visited()){
            edgePQ.pop();
        }

        // add shortest edge to the list and visit, then pop.
        usedEdges.push_back(edgePQ.top());
        edgePQ.top().start().visit();
        edgePQ.top().end().visit();

        // Get incident lists from the end vertices
        EdgeItrList endIncident = edgePQ.top().end().incidentEdges();
        EdgeItrList startIncident = edgePQ.top().start().incidentEdges();

        // pop the smallest and increment vertexcount
        edgePQ.pop();
        VertexCount++;

        // add unvisted edges from start to PQueue
        for(EdgeItrItr i = endIncident.begin(); i != endIncident.end(); i++){
            if( !(**i).start().visited() || !(**i).end().visited() ){
                edgePQ.push(**i);
            }
        }

        // add unvisted edges from end to PQueue
        for(EdgeItrItr i = startIncident.begin(); i != startIncident.end(); i++){
            if( !(**i).start().visited() || !(**i).end().visited() ){
                edgePQ.push(**i);
            }
        }
    } // END OF MST WHILE LOOP

    return usedEdges;
}

/**
 * @brief Graph<E>::MSTPrim
 * @returns A list of edge objects
 */
template <typename E>
typename Graph<E>::EdgeList Graph<E>::MSTPrim() {
    unvisitAll();          // ensure all edges and vertices are unvisited
    EdgeList usedEdges;    // List of edges to use in MST
    EdgeList unusedEdges(edges_.begin(), edges_.end());  // list of unused edges
    unsigned int VertexCount = 0;  // Count of vertecies visited

    // sort the list of unused edges
    unusedEdges.sort();

    // add first vertex to the list and set it to visited
    vertices_.begin()->visit();
    VertexCount++;

    // create iterator to the front of the unused edge list
    EdgeItr itr = unusedEdges.begin();
    // loop while vertecies in the done cloud is less than total
    while( VertexCount < vertices_.size() ) {
        // find the shortest edge connected a vistied vertex to an unvisted vertex
        // using homemade XOR with modulus 2 of the sum of booleans
        if((itr->start().visited() + itr->end().visited())%2  ){
            // visit both verticies
            itr->start().visit();
            itr->end().visit();

            // remove edge from unused list and add to edge list
            usedEdges.push_back(*itr);
            VertexCount++;
            itr = unusedEdges.erase(itr);
            // reset itr to the front of the unused list
            itr = unusedEdges.begin();
        }
        // If the edge is double visited remove that edge from possible edges and move on
        else if( itr->start().visited() && itr->end().visited() ){
            EdgeItr tempItr = itr;
            tempItr = unusedEdges.erase(tempItr);
            itr++;
        }
        else if ( !itr->start().visited() && !itr->end().visited() ) {
            itr++;
        }
    } // END OF MST WHILE LOOP

    return usedEdges;
}

/**
 * @brief Finds the vertex with data 'e'
 * @param e [IN] the data to find in a given vertex
 * @return iterator to the vertex containing 'e' or VertexList::end() if not found
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
 * @brief finds the edge matching the given criteria
 * @param v [IN] vertex data at 'start' of edge
 * @param w [IN] vertex data at 'end' of edge
 * @param x [IN] weight of the edge as an integer
 * @return iterator to the edge or EdgeItrList::end() if not found
 */
template <typename E>
typename Graph<E>::EdgeItr Graph<E>::findEdge(const E &v, const E &w, const int &x){
    bool found = false;
    Edge testEdge(x);
    Vertex testVertex1(v);
    Vertex testVertex2(w);
    EdgeItr outVal = edges_.begin();

    while(outVal != edges_.end() && !found){
        if( *outVal == testEdge
            && outVal->isIncidentOn(testVertex1)
            && outVal->isIncidentOn(testVertex2) )
        {
            found = true;
        }
        else{
            outVal++;
        }
    }
    return outVal;
}

/**
 * @brief Graph<E>::unvisitAll
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

/**
 * @brief Graph::resetDijkstra
 */
template <typename E>
void Graph<E>::resetDijkstra()
{
    // Reset the vertices
    for(VertexItr j = vertices_.begin(); j != vertices_.end(); j++){
        j->resetDijkstra();
    }
}

/**
 * @brief Erases the given vertex and all edges incident
 * @param e [IN] The vertex to remove
 */
template <typename E>
void Graph<E>::eraseVertex(const E &e) {
    // find the vertex if it exists
    VertexItr itr = findVertex(e);

    // remove the vertex if it exists
    if(itr != vertices_.end()){
        EdgeItrList edges = itr->incidentEdges();

        // remove all incident edges from master edge list
        for(EdgeItrItr j = edges.begin(); j != edges.end(); j++){
            #if VERBOSE_DEBUG
            qDebug() << "ERASING EDGE:" << **j;
            #endif
            *j = edges_.erase(*j);
        }

        // remove vertex from master vertex list
        #if VERBOSE_DEBUG
        qDebug() << "ERASING:" << *itr;
        #endif
        itr = vertices_.erase(itr);
    }
}

/**
 * @brief Erases the edge with the given start, end, and weight
 * @param v [IN] vertex data at 'start' of edge to delete
 * @param w [IN] vertex data at 'end' of edge to delete
 * @param x [IN] weight of the edge as an integer
 */
template <typename E>
void Graph<E>::eraseEdge(const E &v, const E &w, const int &x) {
    // find the edge if it exists
    EdgeItr edge2remove = findEdge(v, w, x);

    // remove the edge if it exists
    if(edge2remove != edges_.end()){

        // remove edge from any incident vertices
        for(VertexItr i = vertices_.begin(); i != vertices_.end(); i++) {
            if( edge2remove->isIncidentOn(*i) ){
                #if VERBOSE_DEBUG
                qDebug() << "ERASING EDGE FROM:" << *i;
                #endif
                i->removeEdge(edge2remove);
            }
        }

        // remove edge from master edge list
        #if VERBOSE_DEBUG
        qDebug() << "ERASING:" << *edge2remove;
        #endif
        edge2remove = edges_.erase(edge2remove);
    }
}

/*****************************************************************************
 *                         IMPLEMENTATION OF VERTEX METHODS                  *
 *****************************************************************************/


/**
 * @brief tests if this vertex is adjacent to vertex 'v'
 * @param v [IN] the value of the vertex to check for
 * @return TRUE if vertex is adjacent
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

/**
 * @brief get the distance from this vertec to 'v'
 * @param v [IN] the vertex to get the distance to
 * @return distance between this vertex and 'v' (INF if not adjacent)
 */
template <typename E>
int Graph<E>::Vertex::distanceTo(const VertexItr &v) {
    bool found = false;
    EdgeItrItr itr = incident_.begin();
    while(itr != incident_.end() && !found){
        found = (**itr).isIncidentOn(*v);
        if(!found) { itr++; }
    }
    return (**itr).weight();
}

/**
 * @brief Removed the edge pointed to by the given iterator from this vertex's adjaceny list
 * @param edge [IN] iterator to the edge to remove from this vertex
 */
template <typename E>
void Graph<E>::Vertex::removeEdge(EdgeItr edge) {
    bool found = false;
    EdgeItrItr itr = incident_.begin();

    // find edge to remove if it exists, and remove it
    while(itr != incident_.end() && !found){
        if(*itr == edge){
            itr = incident_.erase(itr);
            found = true;
        }
        else{
            itr++;
        }
    }
}

/**
 * @brief prints the Vertex
 * @return A string representation of the vertex
 */
template <typename E>
QString Graph<E>::Vertex::print() {
    QString output;                      // QString for output
    QTextStream outputStream(&output);   // Qstring stream for output

    outputStream << data_;
    return outputStream.readAll();
}

/**************************************************************************
 *                          IMPLEMENTATION OF EDGE METHODS                *
 **************************************************************************/

/**
 * @brief Graph<E>::Edge::opposite
 * @param v
 * @return
 */
template <typename E>
typename Graph<E>::VertexItr  Graph<E>::Edge::opposite(Vertex v) {
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

/**
 * @brief Graph<E>::Edge::isAdjacentTo
 * @param f
 * @return
 */
template <typename E>
bool  Graph<E>::Edge::isAdjacentTo(Edge f) {
    return this->end_==f.end_ || this->start_==f.end_;
}

/**
 * @brief Test whether this edge is incident on v
 * @param v [IN] vertex to test with
 * @return TRUE if this edge is incident on vertex 'v'
 */
template <typename E>
bool  Graph<E>::Edge::isIncidentOn(Vertex v) {
    return *start_== v || *end_==v;
}

/**
 * @brief prints the Edge
 * @return A string representation of the edge
 */
template <typename E>
QString Graph<E>::Edge::print() {
    QString output;                      // QString for output
    QTextStream outputStream(&output);   // Qstring stream for output

    outputStream << *start_ << "<-->" << *end_;
    return outputStream.readAll();
}


#endif //DATA_STRUCTURES_GRAPH_H
