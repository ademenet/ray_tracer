#include <iostream>
#include "vector.hpp"
#include "ray.hpp"

float hit_sphere(const vector_3d &center, float radius, const ray &r) {
	// Here we calculate the discriminant to see of the ray intercept the sphere
	// of center `center` and radius `radius`. It's not more than what you
	// learned in high school discriminant = b^2 - 4 * a * c.
	// In our case the quadratic equation is:
	// 		t*t*dot(B,B) + 2*t*dot(B,A-C) + dot(A-C,A-C)-R*R = 0
	// With:
	// 		- t: the ray parameter,
	// 		- B: the direction,
	// 		- A: the origin,
	// 		- C: the center of the sphere,
	// 		- R: the radius.
	vector_3d oc = r.origin() - center; // A - C
	float a = dot(r.direction(), r.direction()); // dot(B,B)
	float b = 2.0 * dot(oc, r.direction()); // 2.0 * dot(B,A-C)
	float c = dot(oc, oc) - radius*radius; // dot(A-C,A-C)-R*R
	float discriminant = b*b - 4 * a * c;
	if (discriminant < 0)
		return -1.0;
	else
		return (-b - sqrt(discriminant)) / (2.0*a);
}

vector_3d color(const ray& r) {
	// Liner blend, linear interpolation, lerp
	float t = hit_sphere(vector_3d(0, 0, -1), 0.5, r);

	if (t > 0.0) {
		vector_3d N = unit_vector(r.point_at_parameter(t) - vector_3d(0, 0, -1));
		return 0.5 * vector_3d(N.x()+1, N.y()+1, N.z()+1);
	}
	vector_3d unit_direction = unit_vector(r.direction());
	t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - t) * vector_3d(1.0, 1.0, 1.0) + t * vector_3d(0.5, 0.7, 1.0);
}

int main()
{
	int			nx = 200;
	int			ny = 100;
	float		u, v;
	int			ir, ig, ib;
	vector_3d	lower_left_corner(-2.0, -1.0, -1.0);
	vector_3d	horizontal(4.0, 0.0, 0.0);
	vector_3d	vertical(0.0, 2.0, 0.0);
	vector_3d	origin(0.0, 0.0, 0.0);

	std::cout << "P3\n" << nx << " " << ny << "\n255\n";
	for (int j = ny-1; j >= 0; j--) {
		for (int i = 0; i < nx; i++) {
			u = float(i) / float(nx);
			v = float(j) / float(ny);
			ray r(origin, lower_left_corner + u*horizontal + v*vertical);
			vector_3d col = color(r);
			ir = int(255.99 * col[0]);
			ig = int(255.99 * col[1]);
			ib = int(255.99 * col[2]);
			std::cout << ir << " " << ig << " " << ib << "\n";
		}
	}
	return(0);
}
