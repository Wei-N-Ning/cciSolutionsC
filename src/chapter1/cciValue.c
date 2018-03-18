//
// Created by wein on 3/18/18.
//

#include "cciValue.h"

#include <math.h>

cciValue_t newInt(int x) {
    cciValue_t v;
    SETINT(v, x);
    return v;
}

cciValue_t newFloat(float x) {
    cciValue_t v;
    SETFLOAT(v, x);
    return v;
}

cciValue_t newChar(char x) {
    cciValue_t v;
    SETCHAR(v, x);
    return v;
}

int CompareI(cciValue_t lhs, cciValue_t rhs) {
    int delta = lhs.store.i - rhs.store.i;
    if (delta == 0) {
        return 0;
    }
    return delta > 0 ? 1 : -1;
}

int CompareF(cciValue_t lhs, cciValue_t rhs) {
    float delta = lhs.store.f - rhs.store.f;
    if (fabs(delta) < 1e-7) {
        return 0;
    }
    return delta > 0 ? 1 : -1;
}

int Compare(cciValue_t lhs, cciValue_t rhs, cciValueType_t vt) {
    if (lhs.type == CCI_FLOAT && rhs.type == CCI_FLOAT) {
        return CompareF(lhs, rhs);
    }
    return CompareI(lhs, rhs);
}