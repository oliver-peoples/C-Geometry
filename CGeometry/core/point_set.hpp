namespace cgeo
{
    template<typename T> class PointE3_Set
    {
    public:
        std::vector<PointE3<T>> points;

        PointE3_Set() {}
        ~PointE3_Set() {}

        PointE3_Set(std::string path_to_list, size_t a_idx=0, size_t b_idx=1, size_t c_idx=2, COORDINATE_SPACE coordinate_space=CARTESIAN, bool header=true)
        {
            std::ifstream point_list;
            point_list.open(path_to_list);

            std::string line;

            if (header)
            {
                std::getline(point_list, line);
                std::cout << "Header: " << line << std::endl;
            }
            
            while (std::getline(point_list, line))
            {
                std::vector<std::string> entries;

                std::stringstream ss(line);
                std::string entry;

                while(std::getline(ss, entry, ','))
                {
                    entries.push_back(entry);
                }

                PointE3<T> temp_point(hmath::Vector3<T>(T(std::stold(entries[a_idx])), T(std::stold(entries[b_idx])), T(std::stold(entries[c_idx]))), coordinate_space);
                this->points.push_back(temp_point);
            }
        }

        void addFromFile(std::string path_to_list, size_t a_idx=0, size_t b_idx=1, size_t c_idx=2, COORDINATE_SPACE coordinate_space=CARTESIAN, bool header=true)
        {
            std::ifstream point_list;
            point_list.open(path_to_list);

            std::string line;

            if (header)
            {
                std::getline(point_list, line);
                std::cout << "Header: " << line << std::endl;
            }
            
            while (std::getline(point_list, line))
            {
                std::vector<std::string> entries;

                std::stringstream ss(line);
                std::string entry;

                while(std::getline(ss, entry, ','))
                {
                    entries.push_back(entry);
                }

                PointE3<T> temp_point(hmath::Vector3<T>(T(std::stold(entries[a_idx])), T(std::stold(entries[b_idx])), T(std::stold(entries[c_idx]))), coordinate_space);
                this->points.push_back(temp_point);
            }
        }
    };
}
