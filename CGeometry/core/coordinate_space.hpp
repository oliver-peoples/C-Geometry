#pragma once

#include <hmath.hpp>
#include <promote.hpp>
#include <iostream>

namespace cgeo
{
    /* ############################# COORDINATE SPACES ############################# */

    typedef size_t COORDINATE_SPACE;

    constexpr COORDINATE_SPACE CARTESIAN = 0;
    constexpr COORDINATE_SPACE MATHS_SPHERICAL = 1;
    constexpr COORDINATE_SPACE PHYSICS_SPHERICAL = 2;
    constexpr COORDINATE_SPACE CARTOGRAPHIC_SPHERICAL = 3;
    constexpr COORDINATE_SPACE ASTRO_SPHERICAL = 4;
    constexpr COORDINATE_SPACE CYLINDRICAL = 5;

    /* ################################ POINT CLASS ################################ */

    template <typename T> class PointE3 : public hmath::Vector3<T>
    {
    private:
        COORDINATE_SPACE coordinate_space = CARTESIAN;

    public:
        PointE3() {}
        ~PointE3() {}

        PointE3(hmath::Vector3<T> rlc, COORDINATE_SPACE coordinate_space=CARTESIAN)
        {
            this->i = rlc.i;
            this->j = rlc.j;
            this->k = rlc.k;

            this->coordinate_space = coordinate_space;
        }   
    };

    // /* ############################## CARTESIAN SPACE ############################## */

    // template <typename T> class Cartesian
    // {
    // private:
    //     hmath::Vector3<T>* rlc;
    // public:
    //     Cartesian() {}
    //     ~Cartesian() {}

    //     Cartesian(hmath::Vector3<T>* rlc)
    //     {
    //         this->rlc = rlc;
    //     }

    //     void operator=(hmath::Vector3<T> v)
    //     {
    //         *this->rlc = v;
    //     }

    //     T& x()
    //     {
    //         return this->rlc->i;
    //     }

    //     T& y()
    //     {
    //         return this->rlc->j;
    //     }

    //     T& z()
    //     {
    //         return this->rlc->k;
    //     }
    // };

    // template <typename c1_T, typename c2_T> hmath::Vector3<typename promote<c1_T, c2_T>::type> operator-(Cartesian<c1_T> c1, Cartesian<c2_T> c2)
    // {
    //     hmath::Vector3<typename promote<c1_T, c2_T>::type> v;

    //     v.i = c1.x() - c2.x();
    //     v.j = c1.y() - c2.y();
    //     v.k = c1.z() - c2.z();

    //     return v;
    // }

    // template <typename c_T, typename v_T> void operator+=(Cartesian<c_T> pt, hmath::Vector3<v_T> v)
    // {
    //     pt.x() += v.i;
    //     pt.y() += v.j;
    //     pt.z() += v.k;
    // }

    // /* ######################## MATHEMATICAL SPHERICAL SPACE ####################### */

    // template <typename T> class MathsSpherical
    // {
    // private:
    //     hmath::Vector3<T>* rlc;
    // public:
    //     MathsSpherical() {}
    //     ~MathsSpherical() {}

    //     MathsSpherical(hmath::Vector3<T>* rlc)
    //     {
    //         this->rlc = rlc;
    //     }

    //     T& rho()
    //     {
    //         return this->rlc->i;
    //     }

    //     T& theta()
    //     {
    //         return this->rlc->j;
    //     }

    //     T& phi()
    //     {
    //         return this->rlc->k;
    //     }
    // };

    // /* ########################### PHYSICS SPHERICAL SPACE ######################### */

    // template <typename T> class PhysicsSpherical
    // {
    // private:
    //     hmath::Vector3<T>* rlc;
    // public:
    //     PhysicsSpherical() {}
    //     ~PhysicsSpherical() {}

    //     PhysicsSpherical(hmath::Vector3<T>* rlc)
    //     {
    //         this->rlc = rlc;
    //     }

    //     T& rho()
    //     {
    //         return this->rlc->i;
    //     }

    //     T& theta()
    //     {
    //         return this->rlc->j;
    //     }

    //     T& phi()
    //     {
    //         return this->rlc->k;
    //     }
    // };

    // /* ######################## CARTOGRAPHIC SPHERICAL SPACE ####################### */

    // template <typename T> class CartoSpherical
    // {
    // private:
    //     hmath::Vector3<T>* rlc;
    // public:
    //     CartoSpherical() {}
    //     ~CartoSpherical() {}

    //     CartoSpherical(hmath::Vector3<T>* rlc)
    //     {
    //         this->rlc = rlc;
    //     }

    //     T& rho()
    //     {
    //         return this->rlc->i;
    //     }

    //     T& latitude()
    //     {
    //         return this->rlc->j;
    //     }

    //     T& longitude()
    //     {
    //         return this->rlc->k;
    //     }
    // };

    // /* ############################## CYLINDRICAL SPACE ############################ */

    // template <typename T> class Cylindrical
    // {
    // private:
    //     hmath::Vector3<T>* rlc;
    // public:
    //     Cylindrical() {}
    //     ~Cylindrical() {}

    //     Cylindrical(hmath::Vector3<T>* rlc)
    //     {
    //         this->rlc = rlc;
    //     }

    //     T& rho()
    //     {
    //         return this->rlc->i;
    //     }

    //     T& theta()
    //     {
    //         return this->rlc->j;
    //     }

    //     T& phi()
    //     {
    //         return this->rlc->k;
    //     }
    // };

    // /* ############################# 3D EUCLIDEAN POINT ############################ */

    // template <typename T> class PointE3
    // {
    // private:
    //     hmath::Vector3<T> rlc;

    // public:
    //     PointE3() {}
    //     ~PointE3() {}

    //     template <typename pt_T> void operator=(PointE3<pt_T> pt)
	// 	{
    //         this->rlc.i = T(pt.a());
    //         this->rlc.j = T(pt.b());
    //         this->rlc.k = T(pt.c());
	// 	}

    //     template <typename pt_T> PointE3(PointE3<pt_T> pt)
    //     {
    //         this->rlc.i = T(pt.a());
    //         this->rlc.j = T(pt.b());
    //         this->rlc.k = T(pt.c());
    //     }

    //     template <typename v_T> PointE3(hmath::Vector3<v_T> v)
    //     {
    //         this->rlc = v;
    //     }

    //     template <typename a_T, typename b_T, typename c_T> PointE3(a_T a, b_T b, c_T c)
    //     {
    //         this->rlc.i = a;
    //         this->rlc.j = b;
    //         this->rlc.k = c;
    //     }

    //     T& a()
    //     {
    //         return this->rlc.i;
    //     }

    //     T& b()
    //     {
    //         return this->rlc.j;
    //     }

    //     T& c()
    //     {
    //         return this->rlc.k;
    //     }

    //     hmath::Vector3<T>& asVector3()
    //     {
    //         return this->rlc;
    //     }

    //     Cartesian<T> asCartesian()
    //     {
    //         return Cartesian<T>(&this->rlc);
    //     }

    //     template <typename c_T> void asCartesian(c_T x, c_T y, c_T z)
    //     {
    //         this->rlc.i = x;
    //         this->rlc.j = y;
    //         this->rlc.k = z;
    //     }
    // };

    // template <typename pt_T> std::ostream& operator<<(std::ostream& os, PointE3<pt_T> pt)
	// {
	// 	os << "{ " << pt.a() << ", " << pt.b() << ", " << pt.c() << " }";
	// 	return os;
	// }

    // template <typename pt_T, typename v_T> PointE3<typename promote<pt_T, v_T>::type> operator+(PointE3<pt_T> pt, hmath::Vector3<v_T> v)
    // {
    //     PointE3<typename promote<pt_T, v_T>::type> ret_pt = pt;

    //     ret_pt.asCartesian().x() += v.i;
    //     ret_pt.asCartesian().y() += v.j;
    //     ret_pt.asCartesian().z() += v.k;

    //     return ret_pt;
    // }

    // template <typename pt_T, typename v_T> void operator+=(PointE3<pt_T>& pt, hmath::Vector3<v_T> v)
    // {
    //     pt.asCartesian().x() += v.i;
    //     pt.asCartesian().y() += v.j;
    //     pt.asCartesian().z() += v.k;
    // }

    // template <typename pt1_T, typename pt2_T> hmath::Vector3<typename promote<pt1_T, pt2_T>::type> operator-(PointE3<pt1_T> pt1, PointE3<pt2_T> pt2)
    // {
    //     hmath::Vector3<typename promote<pt1_T, pt2_T>::type> v;

    //     v.i = pt1.asCartesian().x() - pt2.asCartesian().x();
    //     v.j = pt1.asCartesian().y() - pt2.asCartesian().y();
    //     v.k = pt1.asCartesian().z() - pt2.asCartesian().z();

    //     return v;
    // }

    // template <typename pt_T, typename v_T> void operator-=(PointE3<pt_T>& pt, hmath::Vector3<v_T> v)
    // {
    //     pt.asCartesian().x() -= v.i;
    //     pt.asCartesian().y() -= v.j;
    //     pt.asCartesian().z() -= v.k;
    // }
}