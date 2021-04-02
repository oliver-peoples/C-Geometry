#include <hmath.hpp>

namespace geo
{
    typedef int GEO_MAKE;

    constexpr GEO_MAKE P2P = 0;
    constexpr GEO_MAKE BASE_AND_DIRECTOR = 1;

    class Point3d : public hmath::Vector3
    {
    public:
        Point3d() {}
        ~Point3d() {}

        Point3d(hmath::Vector3 v)
        {
            this->i = v.i;
            this->j = v.j;
            this->k = v.k;
        }
    };

    class Line3d
    {
    private:
        Point3d p1, p2;
    public:
        Line3d() {}
        ~Line3d() {}
    };

    class Ray3d
    {
    private:
        Point3d origin;
        hmath::Vector3 direction;
    public:
        Ray() {}
        ~Ray() {}
    };  

    class     
}