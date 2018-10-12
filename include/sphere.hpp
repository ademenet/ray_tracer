#ifndef SPHERE_HPP
# define SPHERE_HPP

# include "hitable.hpp"

class sphere: public hitable {
	public:
		sphere() {}
		sphere(vector_3d cen, float r): center(cen), radius(r) {};
		virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const;
		vector_3d center;
		float radius;
};

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

bool sphere::hit(const ray& r, float t_min, float t_max, hit_record& rec) {
	vector_3d oc = r.origin() - center; // A - C
	float a = dot(r.direction(), r.direction()); // dot(B,B)
	float b = 2.0 * dot(oc, r.direction()); // 2.0 * dot(B,A-C)
	float c = dot(oc, oc) - radius*radius; // dot(A-C,A-C)-R*R
	float discriminant = b*b - a*c;
	if (discriminant > 0) {
		float temp = (-b - sqrt(discriminant)) / a;
		if (temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			return true;
		}
		temp = (-b + sqrt(discriminant)) / a;
		if (temp < t_max && temp > t_min) {
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			return true;
		}
	}
	return false;
}

#endif