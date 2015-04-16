#ifndef TETRA_H
#define TETRA_H

#include "Point.h"
#include <array>
#include <set>
#include "Triangle.h"

template<unsigned N>
class tetra
{
    std::set<Point<N>> points;
    public:
        tetra(std::array<Point<N>,4> p);
        std::set<Triangle<N>> getTriangle();
        bool operator <(tetra<N> const & a) const;
};


template<unsigned N>
tetra<N>::tetra(std::array<Point<N>,4> p){
    for(unsigned i=0;i<4;++i)
        points.insert(p[i]);
}

/*infatti questo metodo fa schifo come è scrito, volevo prendere tutti i punti del tetraedro tre a tre. Però, il set non permete il acesso usando la sintassi []. Cosi ho fatto applicando incremento(++) e  decremento(--). */
template<unsigned N>
std::set<Triangle<N>> tetra<N>::getTriangle(){
    typename std::set<Point<N>>::const_iterator it = points.begin();
    Triangle<N> t1({*(it),*(++it),*(++it)});  //012
    Triangle<N> t2({*(--it),*(++it),*(++it)});  //123
    Triangle<N> t3({*(it),*(--it),*(----it)}); //320
    Triangle<N> t4({*(it),*(++it),*(++++it)}); //013
    std::set<Triangle<N>> tri({t1,t2,t3,t4});
    return tri;
}


template<unsigned N>
bool tetra<N>::operator <(tetra<N> const & a) const{
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
    if(*ip<*ia) return true;
    if(*ia<*ip) return false;
    ip++;
    ia++;
    return *ip<*ia;
}

#endif // TETRA_H
