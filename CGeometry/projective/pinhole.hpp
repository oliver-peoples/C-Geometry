namespace cgeo
{
    namespace projection
    {
        template <typename T> class SimplePinholeCamera
        {

        public:
            cv::Mat frame;
            hmath::Vector3<T> camera_center = { 0,0,0 };
            hmath::Vector3<T> principal_point;
            hmath::Vector3<T> sensor_half_x, sensor_half_y;
            hmath::Vector2<size_t> sensor_resolution;

            SimplePinholeCamera() {}
            ~SimplePinholeCamera() {}

            void simpleSetup(hmath::Vector3<T> camera_center, hmath::Quaternion<T> orientation, T focal_length, size_t x_res, size_t y_res, T x_dim, T y_dim)
            {
                this->frame = cv::Mat(y_res, x_res, CV_8UC3, { 0,0,0 });

                this->sensor_resolution = { x_res,y_res };
                this->camera_center = camera_center;

                hmath::Quaternion<T> principal_point_qt(0,focal_length,0,0);

                this->principal_point = (orientation * principal_point_qt * orientation.conjugated()).getVectorComponent();
                
                this->sensor_half_x = { 0.0,0.5,0.0 };
                this->sensor_half_y = { 0.0,0.0,0.5 };

                this->sensor_half_x *= x_dim;
                this->sensor_half_y *= y_dim;

                hmath::Quaternion<T> sensor_half_x_qt(this->sensor_half_x);
                hmath::Quaternion<T> sensor_half_y_qt(this->sensor_half_y);

                this->sensor_half_x = (orientation * sensor_half_x_qt * orientation.conjugated()).getVectorComponent();
                this->sensor_half_y = (orientation * sensor_half_y_qt * orientation.conjugated()).getVectorComponent();
            }

            template <typename v_T> void projectPoint(hmath::Vector3<v_T> point, bool hold=false, T radius=1, T thickness=-1, cv::Scalar color={ 255,255,255 })
            {
                if (!hold)
                {
                    this->frame = cv::Mat(this->frame.size(), CV_8UC3, { 0,0,0 });
                }
                
                hmath::Vector3<T> cc_relative = point - this->camera_center;

                T scalar = hmath::dot(cc_relative, this->principal_point) / this->principal_point.norm();

                scalar = this->principal_point.norm() / scalar;

                cc_relative *= scalar;
                
                T sensor_x_projection = hmath::dot(this->sensor_half_x, cc_relative) / this->sensor_half_x.norm();
                T sensor_y_projection = hmath::dot(this->sensor_half_y, cc_relative) / this->sensor_half_y.norm();

                sensor_x_projection /= this->sensor_half_x.norm();
                sensor_y_projection /= this->sensor_half_y.norm();

                if (abs(sensor_x_projection) < 1 && abs(sensor_y_projection) < 1)
                {
                    T x_center, y_center;

                    x_center = this->sensor_resolution.i;
                    y_center = this->sensor_resolution.j;

                    x_center *= 0.5;
                    y_center *= 0.5;

                    T x_position, y_position;

                    x_position = x_center + x_center * -sensor_x_projection;
                    y_position = y_center + y_center * -sensor_y_projection;

                    cv::circle(this->frame, { (int)x_position,(int)y_position }, radius, color, thickness);
                }
            }

            template <typename ps_T> void projectPointSet(PointE3_Set<ps_T>& point_set, bool hold=false, T radius=1, T thickness=-1, cv::Scalar color={ 255,255,255 })
            {
                if (!hold)
                {
                    this->frame = cv::Mat(this->frame.size(), CV_8UC3, { 0,0,0 });
                }

                for (PointE3<ps_T>& point : point_set.points)
                {
                    this->projectPoint(point, true, radius, thickness, color);
                }
            }

            void rotate(hmath::Quaternion<T> rotation_qt)
            {
                hmath::Quaternion<T> principal_point_qt(this->principal_point);
                hmath::Quaternion<T> half_x_qt(this->sensor_half_x);
                hmath::Quaternion<T> half_y_qt(this->sensor_half_y);

                this->principal_point = (rotation_qt * principal_point_qt * rotation_qt.conjugated()).getVectorComponent();
                this->sensor_half_x = (rotation_qt * half_x_qt * rotation_qt.conjugated()).getVectorComponent();
                this->sensor_half_y = (rotation_qt * half_y_qt * rotation_qt.conjugated()).getVectorComponent();
            }

            void drawAxes(T scale, size_t subdivisions, bool hold=false)
            {
                if (!hold)
                {
                    this->frame = cv::Mat(this->frame.size(), CV_8UC3, { 0,0,0 });
                }

                for (T subdivision = 1; subdivision <= subdivisions; subdivision++)
                {
                    hmath::Vector3<T> x, y, z;

                    x = { 1,0,0 };
                    y = { 0,1,0 };
                    z = { 0,0,1 };

                    x *= scale;
                    y *= scale;
                    z *= scale;

                    x *= subdivision / (T)subdivisions;
                    y *= subdivision / (T)subdivisions;
                    z *= subdivision / (T)subdivisions;

                    this->projectPoint(x, true, 1, -1, { 255,0,0 });
                    this->projectPoint(y, true, 1, -1, { 0,255,0 });
                    this->projectPoint(z, true, 1, -1, { 0,0,255 });
                }
            }
        };
    }
}
