#ifndef HITABLE_HPP
# define HITABLE_HPP

# include "ray.hpp"

struct hit_record {
	float		t;
	vector_3d	p;
	vector_3d	normal;
};

class hitable {
	public:
		virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const = 0;
};

#endif
