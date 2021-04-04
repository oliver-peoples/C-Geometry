#pragma once

#include <hmath.hpp>
#include <cgeo_core.hpp>

namespace hmath
{
    cgeo::PointE3 toPoint3E(Vector3 vector)
    {
        return { vector.i, vector.j, vector.k, cgeo::CARTESIAN };
    }
}

namespace cgeo
{
    class Quaternion : public hmath::Quaternion
    {
    public:
        using hmath::Quaternion::Quaternion;

        Quaternion(PointE3 point)
        {
            Euclidean::Cartesian cartesian = point.asCartesian();
            this->w = 0;
            this->i = cartesian.x();
            this->j = cartesian.y();
            this->k = cartesian.z();
        }

        Quaternion(hmath::Quaternion q)
        {
            this->w = q.w;
            this->i = q.i;
            this->j = q.j;
            this->k = q.k;
        }
    };
    
    PointE3 rotate(PointE3 point, Quaternion q)
    {
        Quaternion p(point);

        Quaternion p_dash = q * p * q.conjugated();

        return hmath::toPoint3E(p_dash.getVectorComponent());
    }

    PointE3 operator+(cgeo::PointE3 point, hmath::Vector3 vector)
    {
        R3* r3_ptr = point.asCartesian().getE3().r3_element;
        return { r3_ptr->array[0] + vector.i,r3_ptr->array[1] + vector.j,r3_ptr->array[2] + vector.k };
    }

    PointE3 operator-(cgeo::PointE3 point, hmath::Vector3 vector)
    {
        R3* r3_ptr = point.asCartesian().getE3().r3_element;
        return { r3_ptr->array[0] - vector.i,r3_ptr->array[1] - vector.j,r3_ptr->array[2] - vector.k };
    }

    PointE3 operator+(cgeo::PointE3* point, hmath::Vector3& vector)
    {
        R3* r3_ptr = point->asCartesian().getE3().r3_element;
        return { r3_ptr->array[0] + vector.i,r3_ptr->array[1] + vector.j,r3_ptr->array[2] + vector.k };
    }

    PointE3 operator-(cgeo::PointE3* point, hmath::Vector3& vector)
    {
        R3* r3_ptr = point->asCartesian().getE3().r3_element;
        return { r3_ptr->array[0] - vector.i,r3_ptr->array[1] - vector.j,r3_ptr->array[2] - vector.k };
    }
}