#pragma once

#include <cmath>
#include <iostream>

namespace cgeo
{
    /* ############################### TYPE PROMOTION ############################## */

	// This code is by Johannes Schaub, and can be found here: https://stackoverflow.com/a/2450157

	template<int, typename A, typename B>
	struct cond;

	#define CCASE(N, typed) \
	template<typename A, typename B> \
	struct cond<N, A, B> { \
		typedef typed type; \
	}

	CCASE(1, A); CCASE(2, B);
	CCASE(3, int); CCASE(4, unsigned int);
	CCASE(5, long); CCASE(6, unsigned long);
	CCASE(7, float); CCASE(8, double);
	CCASE(9, long double);

	#undef CCASE

	// for a better syntax...
	template<typename T> struct identity { typedef T type; };

	// different type => figure out common type
	template<typename A, typename B>
	struct promote {
	private:
		static A a;
		static B b;

		// in case A or B is a promoted arithmetic type, the template
		// will make it less preferred than the nontemplates below
		template<typename T>
		static identity<char[1]>::type &check(A, T);
		template<typename T>
		static identity<char[2]>::type &check(B, T);

		// "promoted arithmetic types"
		static identity<char[3]>::type &check(int, int);
		static identity<char[4]>::type &check(unsigned int, int);
		static identity<char[5]>::type &check(long, int);
		static identity<char[6]>::type &check(unsigned long, int);
		static identity<char[7]>::type &check(float, int);
		static identity<char[8]>::type &check(double, int);
		static identity<char[9]>::type &check(long double, int);

	public:
		typedef typename cond<sizeof check(0 ? a : b, 0), A, B>::type
			type;
	};

	// same type => finished
	template<typename A>
	struct promote<A, A> {
	typedef A type;
	};

    /* ############################### SPACE DEFINITIONS ############################## */

    typedef size_t EUCLIDEAN_SPACE;

    constexpr EUCLIDEAN_SPACE PHYSICS_SPHERICAL = 1;
    constexpr EUCLIDEAN_SPACE MATH_SPHERICAL = 2;
    constexpr EUCLIDEAN_SPACE CARTO_SPHERICAL = 3;
    constexpr EUCLIDEAN_SPACE CYLINDRICAL = 4;
    constexpr EUCLIDEAN_SPACE CARTESIAN = 5;

    /* ############################### R3 BASE ############################## */

    template<typename T> class R3
    {
    public:
        T array[3];

        R3() {}
        ~R3() {}

        R3(T a, T b, T c)
        {
            array[0] = a;
            array[1] = b;
            array[2] = c;
        }

        R3(T array[3])
        {
            this->array[0] = array[0];
            this->array[1] = array[1];
            this->array[2] = array[2];
        }

        R3<T>* ptr()
        {
            return this;
        }
    };

    /* ##################### EUCLIDEAN SPACE DEFINITION #################### */

    namespace Euclidean
    {
        template <typename T> struct E3
        {
            EUCLIDEAN_SPACE coordinate_space;
            R3<T>* r3_element;

            E3() {}
            ~E3() {}

            E3(EUCLIDEAN_SPACE coordinate_space, R3<T>* r3_element)
            {
                this->coordinate_space = coordinate_space;
                this->r3_element = r3_element;
            }
        };
        
        template <typename T> class PhysicsSpherical : private R3<T>
        {
        public:
            PhysicsSpherical() {}
            ~PhysicsSpherical() {}

            PhysicsSpherical(T rho, T theta, T phi)
            {
                this->array[0] = rho;
                this->array[1] = theta;
                this->array[2] = phi;
            }

            T& rho()
            {
                return this->array[0];
            }

            T& theta()
            {
                return this->array[1];
            }

            T& phi()
            {
                return this->array[2];
            }

            E3<T> getE3()
            {
                return { PHYSICS_SPHERICAL,this->ptr() };
            }
        };

        template <typename T> class MathSpherical : private R3<T>
        {
        public:
            MathSpherical() {}
            ~MathSpherical() {}

            MathSpherical(T rho, T theta, T phi)
            {
                this->array[0] = rho;
                this->array[1] = theta;
                this->array[2] = phi;
            }

            T& rho()
            {
                return this->array[0];
            }

            T& theta()
            {
                return this->array[1];
            }

            T& phi()
            {
                return this->array[2];
            }

            E3<T> getE3()
            {
                return { MATH_SPHERICAL,this->ptr() };
            }
        };

        template <typename T> class CartoSpherical : private R3<T>
        {
        public:
            CartoSpherical() {}
            ~CartoSpherical() {}

            CartoSpherical(T rho, T theta, T phi)
            {
                this->array[0] = rho;
                this->array[1] = theta;
                this->array[2] = phi;
            }

            T& rho()
            {
                return this->array[0];
            }

            T& theta()
            {
                return this->array[1];
            }

            T& phi()
            {
                return this->array[2];
            }

            E3<T> getE3()
            {
                return { CARTO_SPHERICAL,this->ptr() };
            }
        };    
        
        template<typename T> class Cylindrical : private R3<T>
        {
        public:
            Cylindrical() {}
            ~Cylindrical() {}

            Cylindrical(T rho, T phi, T z)
            {
                this->array[0] = rho;
                this->array[1] = phi;
                this->array[2] = z;
            }

            T& rho()
            {
                return this->array[0];
            }

            T& phi()
            {
                return this->array[1];
            }

            T& z()
            {
                return this->array[2];
            }

            E3<T> getE3()
            {
                return { CYLINDRICAL,this->ptr() };
            }
        };

        template <typename T> class Cartesian : private R3<T>
        {
        public:
            Cartesian() {}
            ~Cartesian() {}

            Cartesian(T x, T y, T z)
            {
                this->array[0] = x;
                this->array[1] = y;
                this->array[2] = z;
            }

            T& x()
            {
                return this->array[0];
            }

            T& y()
            {
                return this->array[1];
            }

            T& z()
            {
                return this->array[2];
            }

            E3<T> getE3()
            {
                return { CARTESIAN,this->ptr() };
            }
        };
    }

    template <typename T> class PointE3
    {
    private:
        union
        {
            Euclidean::PhysicsSpherical<T> physics_spherical;
            Euclidean::MathSpherical<T> math_spherical;
            Euclidean::CartoSpherical<T> carto_spherical;
            Euclidean::Cylindrical<T> cylindrical;
            Euclidean::Cartesian<T> cartesian;
        };

        EUCLIDEAN_SPACE coordinate_space = 0;

    public:
        PointE3() {}
        ~PointE3() {}

        PointE3(T a, T b, T c, EUCLIDEAN_SPACE coordinate_space=CARTESIAN)
        {
            this->coordinate_space = coordinate_space;

            switch (coordinate_space)
            {
            case PHYSICS_SPHERICAL:
                this->physics_spherical.rho() = a;
                this->physics_spherical.theta() = b;
                this->physics_spherical.phi() = c;
                break;

            case MATH_SPHERICAL:
                this->math_spherical.rho() = a;
                this->math_spherical.theta() = b;
                this->math_spherical.phi() = c;
                break;

            case CARTO_SPHERICAL:
                this->carto_spherical.rho() = a;
                this->carto_spherical.theta() = b;
                this->carto_spherical.phi() = c;
                break;

            case CYLINDRICAL:
                this->cylindrical.rho() = a;
                this->cylindrical.phi() = b;
                this->cylindrical.z() = c;
                break;

            case CARTESIAN:
                this->cartesian.x() = a;
                this->cartesian.y() = b;
                this->cartesian.z() = c;
                break;
            
            default:
                break;
            }
        }

        // Construction under R3 input

        PointE3(R3<T> r3_element, EUCLIDEAN_SPACE coordinate_space=CARTESIAN)
        {
            this->coordinate_space = coordinate_space;

            switch (coordinate_space)
            {
            case PHYSICS_SPHERICAL:
                this->physics_spherical.rho() = r3_element.array[0];
                this->physics_spherical.theta() = r3_element.array[1];
                this->physics_spherical.phi() = r3_element.array[2];
                break;

            case MATH_SPHERICAL:
                this->math_spherical.rho() = r3_element.array[0];
                this->math_spherical.theta() = r3_element.array[1];
                this->math_spherical.phi() = r3_element.array[2];
                break;

            case CARTO_SPHERICAL:
                this->carto_spherical.rho() = r3_element.array[0];
                this->carto_spherical.theta() = r3_element.array[1];
                this->carto_spherical.phi() = r3_element.array[2];
                break;

            case CYLINDRICAL:
                this->cylindrical.rho() = r3_element.array[0];
                this->cylindrical.phi() = r3_element.array[1];
                this->cylindrical.z() = r3_element.array[2];
                break;

            case CARTESIAN:
                this->cartesian.x() = r3_element.array[0];
                this->cartesian.y() = r3_element.array[1];
                this->cartesian.z() = r3_element.array[2];
                break;
            
            default:
                break;
            }
        }

        PointE3(Euclidean::E3<T> e3_element)
        {
            this->coordinate_space = e3_element.coordinate_space;
            
            switch (coordinate_space)
            {
            case PHYSICS_SPHERICAL:
                this->physics_spherical.rho() = e3_element.r3_element->array[0];
                this->physics_spherical.theta() = e3_element.r3_element->array[1];
                this->physics_spherical.phi() = e3_element.r3_element->array[2];
                break;

            case MATH_SPHERICAL:
                this->math_spherical.rho() = e3_element.r3_element->array[0];
                this->math_spherical.theta() = e3_element.r3_element->array[1];
                this->math_spherical.phi() = e3_element.r3_element->array[2];
                break;

            case CARTO_SPHERICAL:
                this->carto_spherical.rho() = e3_element.r3_element->array[0];
                this->carto_spherical.theta() = e3_element.r3_element->array[1];
                this->carto_spherical.phi() = e3_element.r3_element->array[2];
                break;

            case CYLINDRICAL:
                this->cylindrical.rho() = e3_element.r3_element->array[0];
                this->cylindrical.phi() = e3_element.r3_element->array[1];
                this->cylindrical.z() = e3_element.r3_element->array[2];
                break;

            case CARTESIAN:
                this->cartesian.x() = e3_element.r3_element->array[0];
                this->cartesian.y() = e3_element.r3_element->array[1];
                this->cartesian.z() = e3_element.r3_element->array[2];
                break;
            
            default:
                break;
            }
        }

        PointE3(Euclidean::PhysicsSpherical<T>& spherical)
        {
            this->coordinate_space = PHYSICS_SPHERICAL;

            this->physics_spherical.rho() = spherical.rho();
            this->physics_spherical.theta() = spherical.theta();
            this->physics_spherical.phi() = spherical.phi();
        }

        PointE3(Euclidean::MathSpherical<T>& spherical)
        {
            this->coordinate_space = MATH_SPHERICAL;

            this->math_spherical.rho() = spherical.rho();
            this->math_spherical.theta() = spherical.theta();
            this->math_spherical.phi() = spherical.phi();
        }

        PointE3(Euclidean::CartoSpherical<T>& spherical)
        {
            this->coordinate_space = CARTO_SPHERICAL;

            this->carto_spherical.rho() = spherical.rho();
            this->carto_spherical.theta() = spherical.theta();
            this->carto_spherical.phi() = spherical.phi();
        }

        PointE3(Euclidean::Cylindrical<T>& cylindrical)
        {
            this->coordinate_space = CYLINDRICAL;

            this->cylindrical.rho() = cylindrical.rho();
            this->cylindrical.phi() = cylindrical.phi();
            this->cylindrical.z() = cylindrical.z();
        }

        PointE3(Euclidean::Cartesian<T>& cartesian)
        {
            this->coordinate_space = CARTESIAN;

            this->cartesian.x() = cartesian.x();
            this->cartesian.y() = cartesian.y();
            this->cartesian.z() = cartesian.z();
        }

        EUCLIDEAN_SPACE getCoordinateSpace()
        {
            return this->coordinate_space;
        }

        Euclidean::E3<T> returnCurrent()
        {
            if (this->coordinate_space == PHYSICS_SPHERICAL)
            {
                return this->physics_spherical.getE3();
            }
            
            else if (this->coordinate_space == MATH_SPHERICAL)
            {
                return this->math_spherical.getE3();
            }

            else if (this->coordinate_space == CARTO_SPHERICAL)
            {
                return this->carto_spherical.getE3();
            }
            
            else if (this->coordinate_space == CYLINDRICAL)
            {
                return this->cylindrical.getE3();
            }
            
            else if (this->coordinate_space == CARTESIAN)
            {
                return this->cartesian.getE3();
            }
            
            else
            {
                return Euclidean::E3<T>();
            }
        }

        Euclidean::Cartesian<T>& asCartesian()
        {
            T x, y, z;

            switch (this->coordinate_space)
            {
            case CARTESIAN:

            x = this->cartesian.x();
            y = this->cartesian.y();
            z = this->cartesian.z();

            break;

            case PHYSICS_SPHERICAL:

                x = this->physics_spherical.rho() * sin(this->physics_spherical.theta()) * cos(this->physics_spherical.phi());
                y = this->physics_spherical.rho() * sin(this->physics_spherical.theta()) * sin(this->physics_spherical.phi());
                z = this->physics_spherical.rho() * cos(this->physics_spherical.theta());

                break;

            case MATH_SPHERICAL:

                x = this->math_spherical.rho() * sin(this->math_spherical.phi()) * cos(this->math_spherical.theta());
                y = this->math_spherical.rho() * sin(this->math_spherical.phi()) * sin(this->math_spherical.theta());
                z = this->math_spherical.rho() * cos(this->math_spherical.phi());

                break;

            case CARTO_SPHERICAL:

                x = this->carto_spherical.rho() * cos(this->carto_spherical.phi()) * cos(this->carto_spherical.theta());
                y = this->carto_spherical.rho() * cos(this->carto_spherical.phi()) * sin(this->carto_spherical.theta());
                z = this->carto_spherical.rho() * sin(this->carto_spherical.phi());
                
                break;

            case CYLINDRICAL:

                x = this->cylindrical.rho() * cos(this->cylindrical.phi());
                y = this->cylindrical.rho() * sin(this->cylindrical.phi());
                z = this->cylindrical.z();

                break;
            
            default:
                break;
            }

            this->cartesian = { x,y,z };

            this->coordinate_space = CARTESIAN;
            
            return this->cartesian;
        }

        Euclidean::PhysicsSpherical<T>& asPhysicsSpherical()
        {
            this->asCartesian();

            T x, y, z;

            x = this->cartesian.x();
            y = this->cartesian.y();
            z = this->cartesian.z();

            this->physics_spherical.rho() = sqrt((x * x + y * y + z * z));
            this->physics_spherical.theta() = atan((sqrt(x * x + y * y)) / z);
            this->physics_spherical.phi() = atan(y / x);

            this->coordinate_space = PHYSICS_SPHERICAL;

            return this->physics_spherical;
        }

        Euclidean::MathSpherical<T>& asMathSpherical()
        {
            this->asCartesian();

            T x, y, z;

            x = this->cartesian.x();
            y = this->cartesian.y();
            z = this->cartesian.z();

            this->math_spherical.rho() = sqrt(x * x + y * y + z * z);
            this->math_spherical.theta() = atan(y / x);
            this->math_spherical.phi() = atan((sqrt(x * x + y * y)) / z);

            this->coordinate_space = MATH_SPHERICAL;

            return this->math_spherical;
        }

        Euclidean::CartoSpherical<T>& asCartoSpherical()
        {
            this->asCartesian();

            T x, y, z;

            x = this->cartesian.x();
            y = this->cartesian.y();
            z = this->cartesian.z();

            this->carto_spherical.rho() = sqrt((x * x + y * y + z * z));

            x /= this->carto_spherical.rho();
            y /= this->carto_spherical.rho();
            z /= this->carto_spherical.rho();

            this->carto_spherical.theta() = atan2(y, x);
            this->carto_spherical.phi() = asin(z);

            this->coordinate_space = CARTO_SPHERICAL;

            return this->carto_spherical;
        }

        Euclidean::Cylindrical<T>& asCylindrical()
        {
            this->asCartesian();

            T x, y, z;

            x = this->cartesian.x();
            y = this->cartesian.y();
            z = this->cartesian.z();

            this->cylindrical.rho() = sqrt(x * x + y * y);
            this->cylindrical.phi() = atan(y / x);
            this->cylindrical.z() = z;

            this->coordinate_space = CYLINDRICAL;

            return this->cylindrical;
        }
    };

    template <typename T> std::ostream& operator<<(std::ostream& os, PointE3<T>& point_e3)
    {
        if (point_e3.getCoordinateSpace() == 0)
        {
            os << "E3 element has no coordinate system!";
        }
        
        else if (point_e3.getCoordinateSpace() == PHYSICS_SPHERICAL)
        {
            os << "Spherical Space, Physics ISO := { " << point_e3.returnCurrent().r3_element->array[0] << "," << point_e3.returnCurrent().r3_element->array[1] << "," << point_e3.returnCurrent().r3_element->array[2] << " }";
        }

        else if (point_e3.getCoordinateSpace() == MATH_SPHERICAL)
        {
            os << "Spherical Space, Maths := { " << point_e3.returnCurrent().r3_element->array[0] << "," << point_e3.returnCurrent().r3_element->array[1] << "," << point_e3.returnCurrent().r3_element->array[2] << " }";
        }
        
        else if (point_e3.getCoordinateSpace() == CARTO_SPHERICAL)
        {
            os << "Spherical Space, Cartography := { " << point_e3.returnCurrent().r3_element->array[0] << "," << point_e3.returnCurrent().r3_element->array[1] << "," << point_e3.returnCurrent().r3_element->array[2] << " }";
        }

        else if (point_e3.getCoordinateSpace() == CYLINDRICAL)
        {
            os << "Cylindrical := { " << point_e3.returnCurrent().r3_element->array[0] << "," << point_e3.returnCurrent().r3_element->array[1] << "," << point_e3.returnCurrent().r3_element->array[2] << " }";
        }
        
        else if (point_e3.getCoordinateSpace() == CARTESIAN)
        {
            os << "Cartesian Space := { " << point_e3.returnCurrent().r3_element->array[0] << "," << point_e3.returnCurrent().r3_element->array[1] << "," << point_e3.returnCurrent().r3_element->array[2] << " }";
        }

        else
        {
            os << "Unknown space.";
        }
        
        return os;
    }

    template <typename T> std::ostream& operator<<(std::ostream& os, Euclidean::PhysicsSpherical<T> physics_spherical)
    {
        os << "{ " << physics_spherical.rho() << "," << physics_spherical.theta() << "," << physics_spherical.phi() << " }";

        return os;
    }

    template <typename T> std::ostream& operator<<(std::ostream& os, Euclidean::MathSpherical<T> math_spherical)
    {
        os << "{ " << math_spherical.rho() << "," << math_spherical.theta() << "," << math_spherical.phi() << " }";
        
        return os;
    }

    template <typename T> std::ostream& operator<<(std::ostream& os, Euclidean::CartoSpherical<T> carto_spherical)
    {
        os << "{ " << carto_spherical.rho() << "," << carto_spherical.theta() << "," << carto_spherical.phi() << " }";
        
        return os;
    }

    template <typename T> std::ostream& operator<<(std::ostream& os, Euclidean::Cylindrical<T> cylindrical)
    {
        os << "{ " << cylindrical.rho() << "," << cylindrical.phi() << "," << cylindrical.z() << " }";
        
        return os;
    }

    template <typename T> std::ostream& operator<<(std::ostream& os, Euclidean::Cartesian<T> cartesian)
    {
        os << "{ " << cartesian.x() << "," << cartesian.y() << "," << cartesian.z() << " }";
        
        return os;
    }
}
