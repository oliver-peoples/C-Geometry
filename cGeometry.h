namespace geo
{
    typedef int GEO_MAKE;

    constexpr GEO_MAKE P2P = 0;
    cosntexpr GEO_MAKE BASE_AND_DIRECTOR = 1;

    class Point3d : public hmath::Vector3
    {
    public:
        Point3d() {}
        ~Point3d() {}

        Point3d(hmath::Vector3 v)
        {
            this->i = v.i;
            this->j = v.j;
            this->k = v.k;
        }
    };

    class Line
    {
    private:
        Point3d p1, p2;
    public:
        Line() {}
        ~Line() {}
    };        

    namespace polyhedron
    {
        class vertice
        {
        private:
            Point3d p;
        public:
            vertice() {}
            ~vertice() {}

            vertice(hmath::Vector3 point)
            {
                this->p = point;
            }
        };
       
    }
    
}