#pragma once

#include <hmath.hpp>
#include <cgeo_core.hpp>

namespace cgeo
{
    template <typename T> hmath::Vector3<T> Vector3(PointE3<T> point)
    {
        Euclidean::Cartesian<T> cartesian = point.asCartesian();
        return hmath::Vector3<T>(cartesian.x(), cartesian.y(), cartesian.z());
    }

    template <typename pt_T, typename vec_T> void operator+=(PointE3<pt_T>& p, hmath::Vector3<vec_T> v)
    {
        p.asCartesian().x() += v.i;
        p.asCartesian().y() += v.j;
        p.asCartesian().z() += v.k;
    }

    template <typename pt_T, typename vec_T> PointE3<typename promote<pt_T, vec_T>::type> operator+(PointE3<pt_T> p, hmath::Vector3<vec_T> v)
    {
        PointE3<typename promote<pt_T, vec_T>::type> p_n;
        p_n.asCartesian().x() = p.asCartesian().x() + v.i;
        p_n.asCartesian().y() = p.asCartesian().y() + v.j;
        p_n.asCartesian().z() = p.asCartesian().z() + v.k;
    }

    template <typename pt_T, typename vec_T> void operator-=(PointE3<pt_T>& p, hmath::Vector3<vec_T> v)
    {
        p.asCartesian().x() -= v.i;
        p.asCartesian().y() -= v.j;
        p.asCartesian().z() -= v.k;
    }

    template <typename pt_T, typename vec_T> PointE3<typename promote<pt_T, vec_T>::type> operator-(PointE3<pt_T> p, hmath::Vector3<vec_T> v)
    {
        PointE3<typename promote<pt_T, vec_T>::type> p_n;
        p_n.asCartesian().x() = p.asCartesian().x() - v.i;
        p_n.asCartesian().y() = p.asCartesian().y() - v.j;
        p_n.asCartesian().z() = p.asCartesian().z() - v.k;
    }

    template <typename pt1_T, typename pt2_T> hmath::Vector3<typename promote<pt1_T, pt2_T>::type> operator-(PointE3<pt1_T> pt1, PointE3<pt2_T> pt2)
    {
        hmath::Vector3<typename promote<pt1_T, pt2_T>::type> diff;

        R3<pt1_T>* pt1_r3 = pt1.asCartesian().ptr();
        R3<pt2_T>* pt2_r3 = pt2.asCartesian().ptr();

        diff.i = pt1_r3

        return diff;
    }
}
