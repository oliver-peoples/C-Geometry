#pragma once

#include <hmath.hpp>
#include <cgeo_core.hpp>

namespace cgeo
{
    class Facet
    {
    private:
        PointE3* vtx1;
        PointE3* vtx2;
        PointE3* vtx3;
        hmath::Vector3 normal;
        PointE3 normal_origin;
        
    public:
        Facet() {}
        ~Facet() {}

        Facet(PointE3* vtx1, PointE3* vtx2, PointE3* vtx3)
        {
            this->vtx1 = vtx1;
            this->vtx2 = vtx2;
            this->vtx3 = vtx3;
        }
    };
}
