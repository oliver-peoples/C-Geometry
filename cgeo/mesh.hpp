#include <cgeo_core.hpp>

namespace cgeo
{
    class Facet
    {
    private:
        Point3d* vtx1, vtx2, vtx3;
    public:
        Facet() {}
        ~Facet() {}

        Facet(Point3d* vtx1, Point3d* vtx2, Point3d* vtx3)
        {
            this->vtx1 = vtx1;
            this->vtx2 = vtx2;
            this->vtx3 = vtx3;
        }

        
    };
}
