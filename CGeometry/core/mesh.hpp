#pragma once

#include <hmath.hpp>
#include <cgeo_core.hpp>
#include <cgeo/cloud.hpp>

namespace cgeo
{
    class Facet
    {
    private:
        PointE3* vtx1;
        PointE3* vtx2;
        PointE3* vtx3;
        hmath::Vector3 normal;
        PointE3 centroid;

        union
        {
            uint8_t bgr[3];
            uint8_t bgra[4];
        };

        void recomputeCentroid()
        {

        }

        void recomputeNormal()
        {

        }
        
    public:
        Facet() {}
        ~Facet() {}

        Facet(PointE3* vtx1, PointE3* vtx2, PointE3* vtx3)
        {
            this->vtx1 = vtx1;
            this->vtx2 = vtx2;
            this->vtx3 = vtx3;
        }

        Facet(PointE3* vtx1, PointE3* vtx2, PointE3* vtx3, uint8_t bgr[3])
        {
            this->vtx1 = vtx1;
            this->vtx2 = vtx2;
            this->vtx3 = vtx3;
            this->bgr[0] = bgr[0];
            this->bgr[1] = bgr[1];
            this->bgr[2] = bgr[2];
        }

        Facet(PointE3* vtx1, PointE3* vtx2, PointE3* vtx3, uint8_t bgra[4])
        {
            this->vtx1 = vtx1;
            this->vtx2 = vtx2;
            this->vtx3 = vtx3;
            this->bgra[0] = bgra[0];
            this->bgra[1] = bgra[1];
            this->bgra[2] = bgra[2];
            this->bgra[3] = bgra[3];
        }

        PointE3 vtx1()
        {
            return *this->vtx1;
        }

        void vtx1(PointE3* point)
        {
            this->vtx1 = point;
        }

        PointE3 vtx2()
        {
            return *this->vtx2;
        }

        void vtx2(PointE3* point)
        {
            this->vtx2 = point;
        }

        PointE3 vtx3()
        {
            return *this->vtx3;
        }

        void vtx3(PointE3* point)
        {
            this->vtx3 = point;
        }
    };

    class Mesh : private PointCloud
    {
    private:
        std::vector<Facet> facets;
    public:
        Mesh() {}
        ~Mesh() {}
    };
}
