#pragma once

#include <vector>
#include <cgeo_core.hpp>
#include <cgeo/cloud.hpp>
#include <cgeo/mesh.hpp>

namespace cgeo
{
    class Polyhedra
    {
    private:
        std::vector<PointE3> vertices;
    public:
        Polyhedra() {}
        ~Polyhedra() {}

        PointE3& operator[](int idx)
        {
            return this->vertices[idx];
        }

        PointE3& getVertice(int idx)
        {
            return this->vertices[idx];
        }

        PointE3 returnVertice(int idx)
        {
            return this->vertices[idx];
        }

        std::vector<PointE3>& getVertices()
        {
            return this->vertices;
        }

        std::vector<PointE3> returnVertices()
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
