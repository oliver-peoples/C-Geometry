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

        PointCloud(std::vector<Point3d>& points)
        {
            this->points = points;
        }

        void addPoint(Point3d point)
        {
            this->points.push_back(point);
        }

        Point3d& operator[](int idx)
        {
            return this->points[idx];
        }

        Point3d returnPoint(int idx)
        {
            return this->points[idx];
        }

        // Point3d returnBF_NN(Point3d point)
        // {
            
        // }

        // Point3d& getBF_NN(Point3d point)
        // {

        // }

        // int idxBF_NN(Point3d point)
        // {

        // }
    };
}
