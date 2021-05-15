namespace cgeo
{
    template <typename T> class PointCloud
    {        
    public:
        std::vector<PointE3<T>*> point_ptrs;

        PointCloud() {}
        ~PointCloud() {}

        void addPoint(PointE3<T>* point)
        {
            this->point_ptrs.push_back(point);
        }
    };
}
