#include <cgeo_core.hpp>
#include <cgeo/mesh.hpp>
#include <vector>

namespace cgeo
{
    class Polyhedra
    {
    private:
        std::vector<Point3d> vertices;
    public:
        Polyhedra() {}
        ~Polyhedra() {}

        Point3d& operator[](int idx)
        {
            return this->vertices[idx];
        }

        Point3d& getVertice(int idx)
        {
            return this->vertices[idx];
        }

        Point3d returnVertice(int idx)
        {
            return this->vertices[idx];
        }

        std::vector<Point3d>& getVertices()
        {
            return this->vertices;
        }

        std::vector<Point3d> returnVertices()
        {
            return this->vertices;
        }
    };

    class Tetrahedron : private Polyhedra
    {
    public:
        Tetrahedron()
        {

        }
        
        ~Tetrahedron() {}
    };

    class Cube : private Polyhedra
    {
    public:
        Cube()
        {

        }

        ~Cube() {}
    };

    class Octahedron : private Polyhedra
    {
    public:
        Octahedron()
        {

        }

        ~Octahedron() {}
    };

    class Dodecahedron : private Polyhedra
    {
    public:
        Dodecahedron()
        {

        }
        
        ~Dodecahedron() {}
    };

    class Dodecahedron : private Polyhedra
    {
    public:
        Dodecahedron()
        {

        }
        
        ~Dodecahedron() {}
    };

    class Icoshedron : private Polyhedra
    {
    public:
        Icoshedron()
        {

        }
        
        ~Icoshedron() {}
    }; 
}
