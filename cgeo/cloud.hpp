#include <cgeo_core.hpp>

namespace cgeo
{
    template <typename T> class PointCloud
    {
    private:
        union points
        {
            std::vector<PointE3<T>> points;
            std::vector<PointE3<T>*> pointer_list;
            std::vector<PointE3<T>>* list_pointer;
        };

        size_t active = -1;
        
    public:
        PointCloud() {}
        ~PointCloud() {}

        PointCloud(std::vector<PointE3<T>>& points)
        {
            this->points = points;
            this->active = 1;
        }

        PointCloud(std::vector<PointE3<T>*>& pointer_list)
        {
            this->pointer_list = pointer_list;
            this->active = 2;
        }

        PointCloud(std::vector<PointE3<T>>* list_pointer)
        {
            this->list_pointer = list_pointer;
            this->active = 3;
        }

        void addPoint(PointE3<T> point)
        {
            if (this->active == 1 || this->active == -1)
            {
                this->active = 1;
                this->points.push_back(point);
            }
            
            else
            {
                throw;
            }
            
        }

        void addPoint(PointE3<T>* point)
        {
            if (this->active == 2 || this->active == -1)
            {
                this->active = 2;
                this->pointer_list.push_back(point);
            }
            
            else
            {
                throw;
            }
        }
    };
}
