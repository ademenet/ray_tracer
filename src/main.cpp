#include <iostream>
#include "sphere.hpp"
#include "hitablelist.hpp"
#include "float.h"

vector_3d color(const ray& r, hitable *world) {
	// Liner blend, linear interpolation, lerp
	hit_record rec;
	if (world->hit(r, 0.0, MAXFLOAT, rec)) {
		return 0.5 * vector_3d(rec.normal.x()+1, rec.normal.y()+1, rec.normal.z()+1);
	}
	else {
		vector_3d unit_direction = unit_vector(r.direction());
		float t = 0.5 * (unit_direction.y() + 1.0);
		return (1.0 - t) * vector_3d(1.0, 1.0, 1.0) + t * vector_3d(0.5, 0.7, 1.0);
	}
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
	hitable *list[2];

	list[0] = new sphere(vector_3d(0, 0, -1), 0.5);
	list[1] = new sphere(vector_3d(0, -100.5, -1), 100);
	hitable *world = new hitable_list(list, 2);
	std::cout << "P3\n" << nx << " " << ny << "\n255\n";
	for (int j = ny-1; j >= 0; j--) {
		for (int i = 0; i < nx; i++) {
			u = float(i) / float(nx);
			v = float(j) / float(ny);
			ray r(origin, lower_left_corner + u*horizontal + v*vertical);
			vector_3d col = color(r, world);
			ir = int(255.99 * col[0]);
			ig = int(255.99 * col[1]);
			ib = int(255.99 * col[2]);
			std::cout << ir << " " << ig << " " << ib << "\n";
		}
	}
	return(0);
}
