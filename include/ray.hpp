#ifndef RAY_HPP
# define RAY_HPP

# include "vector.hpp"

class ray {

    // This is the ray class function: p(t) = A + t * B
    // p is a 3D position along a line in 3D
    // A is the origin
    // B is the ray direction
    // t is the ray parameter (a real represented as float)

    public:
        ray() {}
        ray(const vector_3d& a, const vector_3d& b) { A = a; B = b; }
        vector_3d origin() const { return A; }
        vector_3d direction() const { return B; }

        vector_3d point_at_parameter(float t) const { return A + t * B; }

        vector_3d A;
        vector_3d B;
};

#endif