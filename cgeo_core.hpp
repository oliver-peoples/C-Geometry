#include <hmath.hpp>

namespace cgeo
{
    typedef size_t EUCLIDEAN_SPACE;

    constexpr EUCLIDEAN_SPACE PHYSICS_SPHERICAL = 1;
    constexpr EUCLIDEAN_SPACE MATH_SPHERICAL = 2;
    constexpr EUCLIDEAN_SPACE CARTO_SPHERICAL = 3;
    constexpr EUCLIDEAN_SPACE CYLINDRICAL = 4;
    constexpr EUCLIDEAN_SPACE CARTESIAN = 5;

    namespace Euclidean
    {
        class PhysicsSpherical
        {
        public:
            double r, theta, phi;

            PhysicsSpherical() {}
            ~PhysicsSpherical() {}

            PhysicsSpherical(double r, double theta, double phi)
            {
                this->r = r;
                this->theta = theta;
                this->phi = phi;
            }
        };

        class MathSpherical
        {
        public:
            double r, theta, phi;

            MathSpherical() {}
            ~MathSpherical() {}

            MathSpherical(double r, double theta, double phi)
            {
                this->r = r;
                this->theta = theta;
                this->phi = phi;
            }
        };

        class CartoSpherical
        {
        public:
            double theta, phi, r;

            CartoSpherical() {}
            ~CartoSpherical() {}

            CartoSpherical(double theta, double phi, double r)
            {
                this->theta = theta;
                this->phi = phi;
                this->r = r;
            }
        };    
        
        class Cylindrical
        {
        public:
            double rho, phi, z;

            Cylindrical() {}
            ~Cylindrical() {}

            Cylindrical(double rho, double phi, double z)
            {
                this->rho = rho;
                this->phi = phi;
                this->z = z;
            }
        };

        class Cartesian
        {
        public:
            double x, y, z;

            Cartesian() {}
            ~Cartesian() {}

            Cartesian(double x, double y, double z)
            {
                this->x = x;
                this->y = y;
                this->z = z;
            }
        };
    }

    namespace
    {
        union AbstractR3
        {
            AbstractR3() {}
            ~AbstractR3() {}

            Euclidean::Cartesian cartesian;
            Euclidean::CartoSpherical carto_spherical;
            Euclidean::Cylindrical cylindrical;
            Euclidean::MathSpherical math_spherical;
            Euclidean::PhysicsSpherical physics_spherical;
        };
    }

    class Point3d
    {
    private:
        cgeo::AbstractR3 abstract_r3;
        EUCLIDEAN_SPACE coordinate_space;
    public:
        Point3d() {}
        ~Point3d() {}

        Point3d(double values[3], EUCLIDEAN_SPACE coordinate_space=CARTESIAN)
        {
            this->coordinate_space = coordinate_space;

            switch (coordinate_space)
            {
            case PHYSICS_SPHERICAL:
                this->abstract_r3.physics_spherical.r = values[0];
                this->abstract_r3.physics_spherical.theta = values[1];
                this->abstract_r3.physics_spherical.phi = values[2];
                break;

            case MATH_SPHERICAL:
                this->abstract_r3.math_spherical.r = values[0];
                this->abstract_r3.math_spherical.theta = values[1];
                this->abstract_r3.math_spherical.phi = values[2];
                break;

            case CARTO_SPHERICAL:
                this->abstract_r3.carto_spherical.r = values[0];
                this->abstract_r3.carto_spherical.theta = values[1];
                this->abstract_r3.carto_spherical.phi = values[2];
                break;

            case CYLINDRICAL:
                this->abstract_r3.cylindrical.rho = values[0];
                this->abstract_r3.cylindrical.phi = values[1];
                this->abstract_r3.cylindrical.z = values[2];
                break;

            case CARTESIAN:
                this->abstract_r3.cartesian.x = values[0];
                this->abstract_r3.cartesian.y = values[1];
                this->abstract_r3.cartesian.z = values[2];
                break;
            
            default:
                break;
            }
        }

        Point3d(Euclidean::PhysicsSpherical& spherical)
        {
            this->coordinate_space = PHYSICS_SPHERICAL;

            this->abstract_r3.physics_spherical.r = spherical.r;
            this->abstract_r3.physics_spherical.theta = spherical.theta;
            this->abstract_r3.physics_spherical.phi = spherical.phi;
        }

        Point3d(Euclidean::MathSpherical& spherical)
        {
            this->coordinate_space = MATH_SPHERICAL;

            this->abstract_r3.math_spherical.r = spherical.r;
            this->abstract_r3.math_spherical.theta = spherical.theta;
            this->abstract_r3.math_spherical.phi = spherical.phi;
        }

        Point3d(Euclidean::CartoSpherical& spherical)
        {
            this->coordinate_space = CARTO_SPHERICAL;

            this->abstract_r3.carto_spherical.r = spherical.r;
            this->abstract_r3.carto_spherical.theta = spherical.theta;
            this->abstract_r3.carto_spherical.phi = spherical.phi;
        }

        Point3d(Euclidean::Cylindrical& cylindrical)
        {
            this->coordinate_space = CYLINDRICAL;

            this->abstract_r3.cylindrical.rho = cylindrical.rho;
            this->abstract_r3.cylindrical.phi = cylindrical.phi;
            this->abstract_r3.cylindrical.z = cylindrical.z;
        }

        Point3d(Euclidean::Cartesian& cartesian)
        {
            this->coordinate_space = CARTESIAN;

            this->abstract_r3.cartesian.x = cartesian.x;
            this->abstract_r3.cartesian.y = cartesian.y;
            this->abstract_r3.cartesian.z = cartesian.z;
        }

        Euclidean::Cartesian asCartesian()
        {
            Euclidean::Cartesian cartesian;

            switch (this->coordinate_space)
            {
            case PHYSICS_SPHERICAL:
                
                break;

            case MATH_SPHERICAL:
                
                break;

            case CARTO_SPHERICAL:
                
                break;

            case CYLINDRICAL:
                
                break;

            case CARTESIAN:
                cartesian = this->abstract_r3.cartesian;
                break;
            
            default:
                break;
            }

            return cartesian;
        }

        void makeCartesian()
        {
            if (this->coordinate_space != CARTESIAN)
            {
                this->abstract_r3.cartesian = this->asCartesian();
                this->coordinate_space = CARTESIAN;
            }
        }
    };    
}
