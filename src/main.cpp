#include <iostream>
#include "vector.hpp"
#include "ray.hpp"

vector_3d color(const ray& r) {
	// Liner blend, linear interpolation, lerp
	vector_3d unit_direction = unit_vector(r.direction());
	float t = 0.5 * (unit_direction.y() + 1.0);
	return (1.0 - t) * vector_3d(1.0, 1.0, 1.0) + t * vector_3d(0.5, 0.7, 1.0);
}

int main()
{
	int		nx = 200;
	int		ny = 100;

	std::cout << "P3\n" << nx << " " << ny << "\n255\n";
	vector_3d lower_left_corner(-2.0, -1.0, -1.0);
	vector_3d horizontal(4.0, 0.0, 0.0);
	vector_3d vertical(0.0, 2.0, 0.0);
	vector_3d origin(0.0, 0.0, 0.0);
	for (int j = ny-1; j >= 0; j--) {
		for (int i = 0; i < nx; i++) {
			float u = float(i) / float(nx);
			float v = float(j) / float(ny);
			ray r(origin, lower_left_corner + u*horizontal + v*vertical);
			vector_3d col = color(r);
			int ir = int(255.99 * col[0]);
			int ig = int(255.99 * col[1]);
			int ib = int(255.99 * col[2]);
			std::cout << ir << " " << ig << " " << ib << "\n";
		}
	}
	return(0);
}
