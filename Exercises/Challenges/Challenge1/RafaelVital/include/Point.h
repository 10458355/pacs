#ifndef POINT_H
#define POINT_H
#include <array>

template<unsigned N>
class Point
{
    std::array<float,N> points;
    public:
        Point(std::array<float,N> p);
        bool operator <(Point<N> const & a) const;
        template <unsigned m> friend std::ostream& operator<<(std::ostream& os, const Point<m>& p);
    protected:
};


template<unsigned N>
Point<N>::Point(std::array<float,N> p){
    points = p;
}

template<unsigned N>
bool Point<N>::operator <(Point<N> const & a) const{
    for(unsigned i=0;i<N;i++)
        if(points[i]!=a.points[i])
            return points[i] < a.points[i];
    return false;
}

template<unsigned m>
std::ostream& operator<<(std::ostream& os, const Point<m>& p)
{
    os << '{';
    for (auto s : p.points) os << s << ',';
    os << '}';
    return os;
}

#endif // POINT_H

