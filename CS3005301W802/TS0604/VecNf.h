#include <iostream>
#include <vector>
#include <string>

class VecNf {
private:
	std::vector<float> coordinate;
public:
	VecNf() {
		coordinate.push_back(0);
	}

	VecNf(float* dest, int cnt) {
		coordinate.resize(cnt);
		for (unsigned int i = 0; i < cnt; i++) {
			coordinate[i] = dest[i];
		}
	}

	VecNf(const VecNf& rhs) {
		coordinate = rhs.coordinate;
	}

	int Size();
	bool runDimensionsCheck(const VecNf a, const VecNf b);
	VecNf operator=(const VecNf other);
	//VecNf operator=(const float result);
	float& operator[](const unsigned int index);
	VecNf operator+(const VecNf other);
	VecNf operator-(const VecNf other);
	float operator*(const VecNf other);
	VecNf operator*(float scalar);
	friend VecNf operator*(float scalar, VecNf other);

};