#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Point.h"
#include <array>
#include <set>
#include "Edge.h"

template<unsigned N>
class Triangle
{
    std::set<Point<N>> points;
    public:
        Triangle(std::array<Point<N>,3> p);
        std::set<Edge<N>> getEdge();
        bool operator <(Triangle<N> const & a) const;
        template <unsigned m> friend std::ostream& operator<<(std::ostream& os, const Triangle<m>& e);
};

template<unsigned N>
Triangle<N>::Triangle(std::array<Point<N>,3> p){
    for(unsigned i=0;i<3;++i)
        points.insert(p[i]);
}


/*infatti questo metodo fa schifo come è scrito, volevo prendere tutti i punti del triangulo due a due. Però, il set non permete il acesso usando la sintassi []. Cosi ho fatto applicando incremento(++) e  decremento(--). */
template<unsigned N>
std::set<Edge<N>> Triangle<N>::getEdge(){
    typename std::set<Point<N>>::const_iterator it = points.cbegin();
    Edge<N> e1({*it,*(++it)});
    Edge<N> e2({*(--it),*(++++it)});
    Edge<N> e3({*(it),*(--it)});
    std::set<Edge<N>> Edge({e1,e2,e3});
    return Edge;
}


template<unsigned m>
std::ostream& operator<<(std::ostream& os, const Triangle<m>& t)
{
    for (auto s : t.points) os << s << '-' ;
    os <<std::endl;
    return os;
}

template<unsigned N>
bool Triangle<N>::operator <(Triangle<N> const & a) const{
    typename std::set<Point<N>>::const_reverse_iterator ip = points.crbegin();
    typename std::set<Point<N>>::const_reverse_iterator ia = a.points.crbegin();
    if(*ip<*ia) return true;
    if(*ia<*ip) return false;
    ip++;
    ia++;
    if(*ip<*ia) return true;
    if(*ia<*ip) return false;
    ip++;
    ia++;
    return *ip<*ia;
}


#endif // TRIANGLE_H
