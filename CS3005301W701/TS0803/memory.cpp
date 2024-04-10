#include <iostream>
#include <string>
#include <vector>
#include "memory.h"

bool Memory::runSecurityCheck(int point, int saveType, int strSize) {
	if (point > size) return false;
	switch (saveType) {
	case 1:
		if (point + 1 > size) return false;
		break;
	case 2:
		if (point + 2 > size) return false;
		break;
	case 3:
		if (point + 4 > size) return false;
		break;
	case 4:
		if (point + strSize > size) return false;
		break;
	}
	return true;
}

void Memory::Write(int point, int saveType, )