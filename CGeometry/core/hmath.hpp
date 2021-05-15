#pragma once

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

        return p_n;
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

        return p_n;
    }

    template <typename pt1_T, typename pt2_T> hmath::Vector3<typename promote<pt1_T, pt2_T>::type> operator-(PointE3<pt1_T> pt1, PointE3<pt2_T> pt2)
    {
        hmath::Vector3<typename promote<pt1_T, pt2_T>::type> vector;

        vector.i = pt2.asCartesian().x() - pt1.asCartesian().x();
        vector.j = pt2.asCartesian().y() - pt1.asCartesian().y();
        vector.k = pt2.asCartesian().z() - pt1.asCartesian().z();

        return vector;
    }
}
