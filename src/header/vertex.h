#ifndef VERTEX_H
#define VERTEX_H
#include "edge.h"

template <typename E>
class Vertex {
public:
    // Basic Constructor
    Vertex(const E& data) : data_(data), visited_(false) {}
    // Return an edge list of the edges incident on 'u'
    EdgeItrList incidentEdges() { return incident_; }
    // Test whether this vertex and vertex 'v' are adjacent
    bool isAdjacentTo(const E& v);
    // Sets the position aware iterator in this vertex
    void setItr(VertexItr itr) { itr_ = itr; }
    // Sets the data stored in this vertex to a new value
    void setData(const E& data) { data_ = data; }
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
    // Sets the state of this vertex to visited
    void visit() { visited_ = true; }
    // Sets the state of this vertex to unvisited
    void resetVisited() { visited_ = false; }
    // Gets the closest unvisited edge based on weight of edges
    //EdgeItr

    /*** OPERATOR OVERLOADS    void test_insert(); // tests to make sure all numbers are added and are sorted.
 ***/
    // Overload the output stream operator
    friend std::ostream &operator<<(std::ostream &output, const Vertex &obj) {
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
    E           data_;     // Data stored at this node
    bool        visited_;  // Has this vertex been visited?
    EdgeItrList incident_; // Adjacency list of edges
    VertexItr   itr_;      // Iterator to this vertex's position Graph list
};


/*****************************************************************************
 *                         IMPLEMENTATION OF VERTEX METHODS                  *
 *****************************************************************************/

/**
 * @returns TRUE if vertex 'v' is adjacent to this vertex
 */
bool Vertex<E>::isAdjacentTo(const E &v) {
    bool found = false;
    EdgeItrItr itr = incident_.begin();
    while(itr != incident_.end() && !found){
        found = found || (**itr).isIncidentOn(Vertex(v));
        itr++;
    }
    return found;
}

// Inserts a new undirected edge connecting 'v' and 'w' and storing 'x'
void Vertex<E>::insertEdge(const E& v, const E& w, const int& x)
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

#if DEBUG
    cout << *vItr << newEdge << *wItr << endl; cout.flush();
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

#endif // VERTEX_H
