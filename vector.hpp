#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <math.h>
# include <stdlib.h>
# include <iostream>

class vector_3d {
	public:
		vector_3d() {}
		vector_3d(float e0, float e1, float e2) {
			e[0] = e0;
			e[1] = e1;
			e[2] = e2;
		}
		inline float x() const { return e[0]; }
		inline float y() const { return e[1]; }
		inline float z() const { return e[2]; }
		inline float r() const { return e[0]; }
		inline float g() const { return e[1]; }
		inline float b() const { return e[2]; }

		inline const vector_3d& operator+() const { return *this; }
		inline vector_3d operator-() const { return vector_3d(-e[0], -e[1], -e[2]); }
		inline float operator[](int i) const { return e[i]; }
		inline float & operator[](int i) { return e[i]; }

		inline vector_3d& operator+=(const vector_3d &v2);
		inline vector_3d& operator-=(const vector_3d &v2);
		inline vector_3d& operator*=(const vector_3d &v2);
		inline vector_3d& operator/=(const vector_3d &v2);
		inline vector_3d& operator*=(const float t);
		inline vector_3d& operator/=(const float t);

		inline float length() const {
			return sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
		}
		inline float squared_length() const {
			return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
		}
		inline void make_unit_vector();

		float e[3];
};

inline std::istream& operator>>(std::istream &is, vector_3d &t) {
	is >> t.e[0] >> t.e[1] >> t.e[2];
	return is;
}

inline std::ostream& operator<<(std::ostream &os, vector_3d &t) {
	os << t.e[0] << " " << t.e[1] << " " << t.e[2];
	return os;
}

inline void vector_3d::make_unit_vector() {
	float k = 1.0 / sqrt(e[0]*e[0] + e[1]*e[1] + e[2]*e[2]);
	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
}

inline vector_3d operator+(const vector_3d &v1, const vector_3d &v2) {
	return vector_3d(v1.e[0]+v2.e[0], v1.e[1]+v2.e[1], v1.e[2]+v2.e[2]);
}

inline vector_3d operator-(const vector_3d &v1, const vector_3d &v2) {
	return vector_3d(v1.e[0]-v2.e[0], v1.e[1]-v2.e[1], v1.e[2]-v2.e[2]);
}

inline vector_3d operator*(const vector_3d &v1, const vector_3d &v2) {
	return vector_3d(v1.e[0]*v2.e[0], v1.e[1]*v2.e[1], v1.e[2]*v2.e[2]);
}

inline vector_3d operator/(const vector_3d &v1, const vector_3d &v2) {
	return vector_3d(v1.e[0]/v2.e[0], v1.e[1]/v2.e[1], v1.e[2]/v2.e[2]);
}

inline vector_3d operator*(float t, const vector_3d &v) {
	return vector_3d(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vector_3d operator/(vector_3d &v, float t) {
	return vector_3d(v.e[0]/t, v.e[1]/t, v.e[2]/t);
}

inline vector_3d operator*(const vector_3d &v, float t) {
	return vector_3d(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline float dot(const vector_3d &v1, const vector_3d &v2) {
	return v1.e[0]*v2.e[0] + v1.e[1]*v2.e[1] + v1.e[2]*v2.e[2];
}

inline vector_3d cross(const vector_3d &v1, const vector_3d &v2) {
	return vector_3d((v1.e[1]*v2.e[2] - v1.e[2]*v2.e[1]),
					 (v1.e[2]*v2.e[0] - v1.e[0]*v2.e[2]),
					 (v1.e[0]*v2.e[1] - v1.e[1]*v2.e[0]));
}

inline vector_3d& vector_3d::operator+=(const vector_3d &v) {
	e[0] += v.e[0];
	e[1] += v.e[1];
	e[2] += v.e[2];
	return *this;
}

inline vector_3d& vector_3d::operator*=(const vector_3d &v) {
	e[0] *= v.e[0];
	e[1] *= v.e[1];
	e[2] *= v.e[2];
	return *this;
}

inline vector_3d& vector_3d::operator/=(const vector_3d &v) {
	e[0] /= v.e[0];
	e[1] /= v.e[1];
	e[2] /= v.e[2];
	return *this;
}

inline vector_3d& vector_3d::operator-=(const vector_3d &v) {
	e[0] -= v.e[0];
	e[1] -= v.e[1];
	e[2] -= v.e[2];
	return *this;
}

inline vector_3d& vector_3d::operator*=(const float t) {
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;
	return *this;
}

inline vector_3d& vector_3d::operator/=(const float t) {
	float k = 1.0 / t;

	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
	return *this;
}

inline vector_3d unit_vector(vector_3d v) {
	return v / v.length();
}

#endif