#include <iostream>
#include <CGeometry/core.hpp>
#include <CGeometry/projective.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include "stargate.hpp"

int main()
{
    // Load up the star HYG star catalogue

    cgeo::PointE3_Set<long double> star_set;
    star_set.addFromFile("../hygdata_v3.csv", 17, 18, 19, cgeo::CARTESIAN);

    // Space is big, so compensate for the parsec unit used by the HYG star database

    for (cgeo::PointE3<long double>& point_e3 : star_set.points)
    {
        point_e3 *= cgeo::unit::parsec;
    }

    // For star coordinate frame, it is probably useful to stay within the same
    // galaxy. Distance from the origin can be quite significant, perhaps the radius
    // of the relevant galaxy, however distance between coordinate frame stars should
    // be less, perhaps a quarter radius of the relevant galaxy. Given that most of
    // the HYG catalogue stars are in the milky way, we'll use its dimensions as a
    // basis for the study.

    long double max_origin_dist = 5000 * cgeo::unit::lightyear;
    long double max_frame_dist = 100 * cgeo::unit::lightyear;

    // Now we go through the dataset treating all stars as origins. From those
    // origins, we identify candiate stars less than max_origin_dist away. Out of
    // those, we then cycle through them, and find candidate stars for coordinate
    // frames based on max_frame_dist.

    size_t set_size = star_set.points.size();

    for (size_t origin_star_idx = 0; origin_star_idx < set_size; origin_star_idx++)
    {
        cgeo::PointE3<long double>* origin_star;
        origin_star = &star_set.points[origin_star_idx];

        std::vector<cgeo::PointE3<long double>*> candidate_stars;

        for (size_t frame_star_idx = 0; frame_star_idx < set_size; frame_star_idx++)
        {
            if (frame_star_idx != origin_star_idx)
            {
                cgeo::PointE3<long double>* frame_star;
                frame_star = &star_set.points[frame_star_idx];

                long double dist = (*frame_star - *origin_star).norm();

                if (dist < max_origin_dist)
                {
                    candidate_stars.push_back(frame_star);
                }
            }
        }

        size_t c_set_size = candidate_stars.size();

        for (size_t c_idx = 0; c_idx < c_set_size; c_idx++)
        {
            cgeo::PointE3<long double>* candidate_star = candidate_stars[c_idx];

            std::vector<cgeo::PointE3<long double>*> acceptable_frame_stars;

            for (size_t f_idx = 0; f_idx < c_set_size; f_idx++)
            {
                if (f_idx != c_idx)
                {
                    cgeo::PointE3<long double>* frame_star = candidate_stars[f_idx];

                    long double dist = (*frame_star - *candidate_star).norm();

                    if (dist < max_frame_dist)
                    {
                        acceptable_frame_stars.push_back(frame_star);
                    }
                }                
            }

            if (acceptable_frame_stars.size() >= 6)
            {
                cgeo::PointCloud<long double> subset;
                subset.point_ptrs = acceptable_frame_stars;
            }
        }
    }
    
    return 0;


}