#include "HotDogStand.h"

#include <iostream>

int HotDogStand::totalSellAmount = 0;

HotDogStand::HotDogStand() {
    ;
}

HotDogStand::HotDogStand(const char* id) {
    standId = (char*)malloc(strlen(id) + 1);
    strcpy_s(standId, strlen(id) + 1, id);

    hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const char* id, int amount) {
    standId = (char*)malloc(strlen(id) + 1);
    strcpy_s(standId, strlen(id) + 1, id);

    hotDogSellAmount = amount;
    totalSellAmount += amount;
}

HotDogStand::~HotDogStand() {
    free(standId);
}

void HotDogStand::justSold() {
    hotDogSellAmount += 1;
    totalSellAmount += 1;
    return;
}

void HotDogStand::print() {
    using namespace std;
    cout << standId << ' ' << thisStandSoldAmount() << endl;
    return;
}

int HotDogStand::thisStandSoldAmount() {
    return this->hotDogSellAmount;
}

int HotDogStand::allStandSoldAmount() {
    return totalSellAmount;
}
