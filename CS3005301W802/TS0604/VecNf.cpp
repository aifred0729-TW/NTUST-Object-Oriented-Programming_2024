#include <iostream>
#include <vector>
#include "VecNf.h"

int VecNf::Size() {
	return coordinate.size();
}

bool VecNf::runDimensionsCheck(const VecNf a, const VecNf b) {
	if (a.coordinate.size() != b.coordinate.size()) {
		std::cout << "dimensions inconsistent" << std::endl;
		return true;
	}
	return false;
}

float& VecNf::operator[](const unsigned int index) {
	if (coordinate.size() < index + 1) coordinate.resize(index + 1);
	return coordinate[index];
}

VecNf VecNf::operator=(const VecNf other) {
	std::cout << "ASSIGNMENT!!!" << std::endl;
	coordinate = other.coordinate;
	return *this;
}

//VecNf VecNf::operator=(const float result) {
//	std::cout << "ASSIGNMENT!!!" << std::endl;
//	coordinate.resize(1);
//	coordinate[0] = result;
//	return *this;
//}

VecNf VecNf::operator+(const VecNf other) {
	if (runDimensionsCheck(*this, other)) return VecNf();

	VecNf tmp;
	VecNf lhs = *this;
	VecNf rhs = other;
	
	for (unsigned int i = 0; i < lhs.coordinate.size(); i++) {
		tmp[i] = lhs[i] + rhs[i];
	}

	return tmp;
}

VecNf VecNf::operator-(const VecNf other) {
	if (runDimensionsCheck(*this, other)) return VecNf();

	VecNf tmp;
	VecNf lhs = *this;
	VecNf rhs = other;

	for (unsigned int i = 0; i < lhs.coordinate.size(); i++) {
		tmp[i] = lhs[i] - rhs[i];
	}

	return tmp;
}

float VecNf::operator*(const VecNf other) {
	if (runDimensionsCheck(*this, other)) return 0.0f;

	VecNf tmp;
	VecNf lhs = *this;
	VecNf rhs = other;

	float result = 0.0f;

	for (unsigned int i = 0; i < lhs.Size(); i++) {
		result += lhs[i] * rhs[i];
	}
	
	return result;
}

VecNf VecNf::operator*(float scalar) {
	VecNf lhs = *this;
	VecNf tmp;

	float result = 0.0f;

	for (unsigned int i = 0; i < coordinate.size(); i++) {
		tmp[i] = lhs[i] * scalar;
	}

	return tmp;
}

VecNf operator*(float scalar, VecNf other) {
	return other * scalar;
}