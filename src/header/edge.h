#ifndef EDGE_H
#define EDGE_H
#include "vertex.h"


template <typename E>
class Edge {
public:
    /*** CLASS TYPEDEFS***/
    typedef unsigned int weight;
    typedef Vertex<E> Vertex;

    // Basic Constructor for the edge class
    Edge(const weight &weight = 0) : weight_(weight), visited_(false) {}
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
    // Sets the state of this vertex to visited
    void visit() { visited_ = true; }
    // Sets the state of this vertex to unvisited
    void resetVisited() { visited_ = false; }

    void setEnd(VertexItr newEnd){end_ = newEnd;}
    void setStart(VertexItr newStart ){start_ = newStart;}

    /*** OPERATOR OVERLOADS ***/
    // Overload for the * Operator
    weight& operator*() { return weight_; }
    // Overload the output stream operator
    friend std::ostream &operator<<(std::ostream &output, const Edge &obj){
            output << *(obj.start_) << "<--->" << *(obj.end_);
            return output;
    }
    // Overload all the comparison operators
    bool operator==(const Edge &other) const { return (this->weight_ == other.weight_); }
    bool operator!=(const Edge &other) const { return (this->weight_ != other.weight_); }
    bool operator>(const Edge &other)  const { return this->weight_ > other.weight_ ; }
    bool operator<(const Edge &other)  const { return this->weight_ < other.weight_ ; }
    bool operator>=(const Edge &other) const { return this->weight_ >= other.weight_ ; }
    bool operator<=(const Edge &other) const { return this->weight_ <= other.weight_ ; }

private:
    weight weight_;       // weight of the edge
    bool   visited_;      // Has this Edge been visited?
    VertexItr start_;     // Iterator to vertex at end of this edge
    VertexItr end_;       // Iterator to vertex at end of this edge
    EdgeItr   itr_;       // Iterator to this edge's position in Edge List
};

/**************************************************************************
 *                          IMPLEMENTATION OF EDGE METHODS                *
 **************************************************************************/

VertexItr  Edge::opposite(Vertex v)
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

// bool isAdjacentTo(Edge f) (they share a common edge);
bool Edge::isAdjacentTo(Edge f)
{
    return this->end_==f.end_ || this->start_==f.end_;
}

// Test whether this edge is incident on v (they share a common vertex)
bool Edge::isIncidentOn(Vertex v)
{
    return *start_== v || *end_==v;
}

#endif // EDGE_H
