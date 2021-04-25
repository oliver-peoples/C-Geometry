#pragma once

#include <hmath.hpp>
#include <promote.hpp>
#include <iostream>

namespace cgeo
{
    /* ############################## CARTESIAN SPACE ############################## */

    template <typename T> class Cartesian
    {
    private:
        hmath::Vector3<T>* rlc;
    public:
        Cartesian() {}
        ~Cartesian() {}

        Cartesian(hmath::Vector3<T>* rlc)
        {
            this->rlc = rlc;
        }

        T& x()
        {
            return this->rlc->i;
        }

        T& y()
        {
            return this->rlc->j;
        }

        T& z()
        {
            return this->rlc->k;
        }
    };

    /* ######################## MATHEMATICAL SPHERICAL SPACE ####################### */

    template <typename T> class MathsSpherical
    {
    private:
        hmath::Vector3<T>* rlc;
    public:
        MathsSpherical() {}
        ~MathsSpherical() {}

        MathsSpherical(hmath::Vector3<T>* rlc)
        {
            this->rlc = rlc;
        }

        T& rho()
        {
            return this->rlc->i;
        }

        T& theta()
        {
            return this->rlc->j;
        }

        T& phi()
        {
            return this->rlc->k;
        }
    };

    /* ########################### PHYSICS SPHERICAL SPACE ######################### */

    template <typename T> class PhysicsSpherical
    {
    private:
        hmath::Vector3<T>* rlc;
    public:
        PhysicsSpherical() {}
        ~PhysicsSpherical() {}

        PhysicsSpherical(hmath::Vector3<T>* rlc)
        {
            this->rlc = rlc;
        }

        T& rho()
        {
            return this->rlc->i;
        }

        T& theta()
        {
            return this->rlc->j;
        }

        T& phi()
        {
            return this->rlc->k;
        }
    };

    /* ######################## CARTOGRAPHIC SPHERICAL SPACE ####################### */

    template <typename T> class CartoSpherical
    {
    private:
        hmath::Vector3<T>* rlc;
    public:
        CartoSpherical() {}
        ~CartoSpherical() {}

        CartoSpherical(hmath::Vector3<T>* rlc)
        {
            this->rlc = rlc;
        }

        T& rho()
        {
            return this->rlc->i;
        }

        T& latitude()
        {
            return this->rlc->j;
        }

        T& longitude()
        {
            return this->rlc->k;
        }
    };

    /* ############################## CYLINDRICAL SPACE ############################ */

    template <typename T> class Cylindrical
    {
    private:
        hmath::Vector3<T>* rlc;
    public:
        Cylindrical() {}
        ~Cylindrical() {}

        Cylindrical(hmath::Vector3<T>* rlc)
        {
            this->rlc = rlc;
        }

        T& rho()
        {
            return this->rlc->i;
        }

        T& theta()
        {
            return this->rlc->j;
        }

        T& phi()
        {
            return this->rlc->k;
        }
    };

    /* ############################# 3D EUCLIDEAN POINT ############################ */

    template <typename T> class PointE3
    {
    private:
        hmath::Vector3<T> rlc;

    public:
        PointE3() {}
        ~PointE3() {}

        template <typename pt_T> void operator=(PointE3<pt_T> pt)
		{
            this->rlc.i = T(pt.a());
            this->rlc.j = T(pt.b());
            this->rlc.k = T(pt.c());
		}

        template <typename pt_T> PointE3(PointE3<pt_T> pt)
        {
            this->rlc.i = T(pt.a());
            this->rlc.j = T(pt.b());
            this->rlc.k = T(pt.c());
        }

        template <typename a_T, typename b_T, typename c_T> PointE3(a_T a, b_T b, c_T c)
        {
            this->rlc.i = a;
            this->rlc.j = b;
            this->rlc.k = c;
        }

        T& a()
        {
            return this->rlc.i;
        }

        T& b()
        {
            return this->rlc.j;
        }

        T& c()
        {
            return this->rlc.k;
        }

        Cartesian<T> asCartesian()
        {
            return Cartesian<T>(&this->rlc);
        }
    };

    template <typename pt_T> std::ostream& operator<<(std::ostream& os, PointE3<pt_T> pt)
	{
		os << "{ " << pt.a() << ", " << pt.b() << ", " << pt.c() << " }";
		return os;
	}

    template <typename pt_T, typename v_T> PointE3<typename promote<pt_T, v_T>::type> operator+(PointE3<pt_T> pt, hmath::Vector3<v_T> v)
    {
        PointE3<typename promote<pt_T, v_T>::type> ret_pt = pt;

        ret_pt.asCartesian().x() += v.i;
        ret_pt.asCartesian().y() += v.j;
        ret_pt.asCartesian().z() += v.k;

        return ret_pt;
    }
}