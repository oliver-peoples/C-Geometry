#pragma once

#include <hmath.hpp>
#include <cgeo_core.hpp>

namespace cgeo
{
    hmath::Vector3 Vector3(PointE3 point)
    {
        Euclidean::Cartesian cartesian = point.asCartesian();
        return { cartesian.x(),cartesian.y(),cartesian.z() };
    }
}
