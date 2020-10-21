#ifndef EDGE_FILE_H
#define EDGE_FILE_H

namespace DynamicPlatformD {
class Edge
{
public:
    Edge(){}
    Edge(int end_id, double cost): dest_id(end_id), cost(cost) {}
    const int GetDestID() const { return this->dest_id; } 
    const double GetCost() const { return this->cost; }
    const bool operator==(const DynamicPlatformD::Edge & e) { return this->dest_id ==  e.dest_id; }
private:
    int dest_id;
    double cost;
};
}

#endif