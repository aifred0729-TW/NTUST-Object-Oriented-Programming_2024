#include <iostream>
#include <string>
#include <vector>
#include "memory.h"

bool Memory::runSecurityCheck(int point, int dataType, int strSize) {
	if (point > size) return true;
	switch (dataType) {
	case 1:
		if (point + 1 > size) return true;
		break;
	case 2:
		if (point + 2 > size) return true;
		break;
	case 3:
		if (point + 4 > size) return true;
		break;
	case 4:
		if (point + strSize > size) return true;
		break;
	}
	return false;
}

//void Memory::Write(int point, int saveType, )