#include <cmath>
#include <iostream>

namespace cgeo
{
    typedef size_t EUCLIDEAN_SPACE;

    constexpr EUCLIDEAN_SPACE PHYSICS_SPHERICAL = 1;
    constexpr EUCLIDEAN_SPACE MATH_SPHERICAL = 2;
    constexpr EUCLIDEAN_SPACE CARTO_SPHERICAL = 3;
    constexpr EUCLIDEAN_SPACE CYLINDRICAL = 4;
    constexpr EUCLIDEAN_SPACE CARTESIAN = 5;

    class R3
    {
    public:
        double array[3];

        R3() {}
        ~R3() {}

        R3(double a, double b, double c)
        {
            array[0] = a;
            array[1] = b;
            array[2] = c;
        }

        R3(double array[3])
        {
            this->array[0] = array[0];
            this->array[1] = array[1];
            this->array[2] = array[2];
        }

        R3* ptr()
        {
            return this;
        }
    };

    namespace Euclidean
    {
        struct E3
        {
            EUCLIDEAN_SPACE coordinate_space;
            R3* r3_element;

            E3() {}
            ~E3() {}

            E3(EUCLIDEAN_SPACE coordinate_space, R3* r3_element)
            {
                this->coordinate_space = coordinate_space;
                this->r3_element = r3_element;
            }
        };
        
        class PhysicsSpherical : private R3
        {
        public:
            PhysicsSpherical() {}
            ~PhysicsSpherical() {}

            PhysicsSpherical(double rho, double theta, double phi)
            {
                this->array[0] = rho;
                this->array[1] = theta;
                this->array[2] = phi;
            }

            double& rho()
            {
                return this->array[0];
            }

            double& theta()
            {
                return this->array[1];
            }

            double& phi()
            {
                return this->array[2];
            }

            E3 getE3()
            {
                return { PHYSICS_SPHERICAL,this->ptr() };
            }
        };

        class MathSpherical : private R3
        {
        public:
            MathSpherical() {}
            ~MathSpherical() {}

            MathSpherical(double rho, double theta, double phi)
            {
                this->array[0] = rho;
                this->array[1] = theta;
                this->array[2] = phi;
            }

            double& rho()
            {
                return this->array[0];
            }

            double& theta()
            {
                return this->array[1];
            }

            double& phi()
            {
                return this->array[2];
            }

            E3 getE3()
            {
                return { MATH_SPHERICAL,this->ptr() };
            }
        };

        class CartoSpherical : private R3
        {
        public:
            CartoSpherical() {}
            ~CartoSpherical() {}

            CartoSpherical(double rho, double theta, double phi)
            {
                this->array[0] = rho;
                this->array[1] = theta;
                this->array[2] = phi;
            }

            double& rho()
            {
                return this->array[0];
            }

            double& theta()
            {
                return this->array[1];
            }

            double& phi()
            {
                return this->array[2];
            }

            E3 getE3()
            {
                return { CARTO_SPHERICAL,this->ptr() };
            }
        };    
        
        class Cylindrical : private R3
        {
        public:
            Cylindrical() {}
            ~Cylindrical() {}

            Cylindrical(double rho, double phi, double z)
            {
                this->array[0] = rho;
                this->array[1] = phi;
                this->array[2] = z;
            }

            double& rho()
            {
                return this->array[0];
            }

            double& phi()
            {
                return this->array[1];
            }

            double& z()
            {
                return this->array[2];
            }

            E3 getE3()
            {
                return { CYLINDRICAL,this->ptr() };
            }
        };

        class Cartesian : private R3
        {
        public:
            Cartesian() {}
            ~Cartesian() {}

            Cartesian(double x, double y, double z)
            {
                this->array[0] = x;
                this->array[1] = y;
                this->array[2] = z;
            }

            double& x()
            {
                return this->array[0];
            }

            double& y()
            {
                return this->array[1];
            }

            double& z()
            {
                return this->array[2];
            }

            E3 getE3()
            {
                return { CARTESIAN,this->ptr() };
            }
        };
    }

    class PointE3
    {
    private:
        union
        {
            Euclidean::PhysicsSpherical physics_spherical;
            Euclidean::MathSpherical math_spherical;
            Euclidean::CartoSpherical carto_spherical;
            Euclidean::Cylindrical cylindrical;
            Euclidean::Cartesian cartesian;
        };
        EUCLIDEAN_SPACE coordinate_space = 0;
    public:
        PointE3() {}
        ~PointE3() {}

        PointE3(double a, double b, double c, EUCLIDEAN_SPACE coordinate_space=CARTESIAN)
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

        PointE3(R3 r3_element, EUCLIDEAN_SPACE coordinate_space=CARTESIAN)
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

        PointE3(Euclidean::E3 e3_element)
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

        PointE3(Euclidean::PhysicsSpherical& spherical)
        {
            this->coordinate_space = PHYSICS_SPHERICAL;

            this->physics_spherical.rho() = spherical.rho();
            this->physics_spherical.theta() = spherical.theta();
            this->physics_spherical.phi() = spherical.phi();
        }

        PointE3(Euclidean::MathSpherical& spherical)
        {
            this->coordinate_space = MATH_SPHERICAL;

            this->math_spherical.rho() = spherical.rho();
            this->math_spherical.theta() = spherical.theta();
            this->math_spherical.phi() = spherical.phi();
        }

        PointE3(Euclidean::CartoSpherical& spherical)
        {
            this->coordinate_space = CARTO_SPHERICAL;

            this->carto_spherical.rho() = spherical.rho();
            this->carto_spherical.theta() = spherical.theta();
            this->carto_spherical.phi() = spherical.phi();
        }

        PointE3(Euclidean::Cylindrical& cylindrical)
        {
            this->coordinate_space = CYLINDRICAL;

            this->cylindrical.rho() = cylindrical.rho();
            this->cylindrical.phi() = cylindrical.phi();
            this->cylindrical.z() = cylindrical.z();
        }

        PointE3(Euclidean::Cartesian& cartesian)
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

        Euclidean::E3 returnCurrent()
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
                return Euclidean::E3();
            }
        }

        Euclidean::Cartesian& asCartesian()
        {
            double x, y, z;

            switch (this->coordinate_space)
            {
            case PHYSICS_SPHERICAL:

                x = this->physics_spherical.rho() * sin(this->physics_spherical.phi()) * cos(this->physics_spherical.theta());
                y = this->physics_spherical.rho() * sin(this->physics_spherical.phi()) * sin(this->physics_spherical.theta());
                z = this->physics_spherical.rho() * cos(this->physics_spherical.phi());

                break;

            case MATH_SPHERICAL:

                x = this->math_spherical.rho() * sin(this->math_spherical.theta()) * cos(this->math_spherical.phi());
                y = this->math_spherical.rho() * sin(this->math_spherical.theta()) * sin(this->math_spherical.phi());
                z = this->math_spherical.rho() * cos(this->math_spherical.theta());

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

            case CARTESIAN:

                x = this->cartesian.x();
                y = this->cartesian.y();
                z = this->cartesian.z();

                break;
            
            default:
                break;
            }

            this->cartesian = { x,y,z };

            this->coordinate_space = CARTESIAN;
            
            return this->cartesian;
        }

        Euclidean::PhysicsSpherical& asPhysicsSpherical()
        {
            this->asCartesian();

            double x, y, z;

            x = this->cartesian.x();
            y = this->cartesian.y();
            z = this->cartesian.z();
        }

        Euclidean::MathSpherical& asMathSpherical()
        {
            this->asCartesian();

            double x, y, z;

            x = this->cartesian.x();
            y = this->cartesian.y();
            z = this->cartesian.z();
        }

        Euclidean::CartoSpherical& asCartoSpherical()
        {
            this->asCartesian();

            double x, y, z;

            x = this->cartesian.x();
            y = this->cartesian.y();
            z = this->cartesian.z();
        }

        Euclidean::Cylindrical& asCylindrical()
        {
            this->asCartesian();

            double x, y, z;

            x = this->cartesian.x();
            y = this->cartesian.y();
            z = this->cartesian.z();
        }
    };

    std::ostream& operator<<(std::ostream& os, PointE3& point_e3)
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
}
