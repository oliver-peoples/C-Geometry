#include <cgeo_core.hpp>

namespace cgeo
{
    class PointCloud
    {
    private:
        std::vector<Point3d> points;
    public:
        PointCloud() {}
        ~PointCloud() {}
    };
}
