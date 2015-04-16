#ifndef EDGE_H
#define EDGE_H

#include "Point.h"
#include <array>
#include <set>
#include <ostream>


template<unsigned N>
class Edge
{
    std::set<Point<N>> points;
    public:
        Edge(std::array<Point<N>,2> p);
        bool operator <(Edge<N> const & a) const;
        template <unsigned m> friend std::ostream& operator<<(std::ostream& os, const Edge<m>& e);
};

template<unsigned N>
Edge<N>::Edge(std::array<Point<N>,2> p){
    for(unsigned i=0;i<2;++i)
        points.insert(p[i]);
}

template<unsigned m>
std::ostream& operator<<(std::ostream& os, const Edge<m>& e)
{
    for (auto s : e.points) os << s << '-' ;
    os <<std::endl;
    return os;
}

template<unsigned N>
bool Edge<N>::operator <(Edge<N> const & a) const{
    typename std::set<Point<N>>::const_reverse_iterator ip = points.crbegin();
    typename std::set<Point<N>>::const_reverse_iterator ia = a.points.crbegin();
    if(*ip<*ia) return true;
    if(*ia<*ip) return false;
    ip++;
    ia++;
    return *ip<*ia;
}

#endif // EDGE_H
