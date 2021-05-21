// We need to identify coordinate frame friendly stars, but to do that, a struct
// containing pointers to the star pairs used to construct the coordinate frame
// would be quite handy.

struct StarPair
{
    cgeo::PointE3<long double>* s1, s2;
};

struct CoordinateFrame
{
    StarPair sp1, sp2, sp3;
};

