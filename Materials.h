#pragma once

#include "Sequences.h"

template<typename T>
bool first(const T &a, const T &b) {
    return a <= b;
}

template<typename T>
bool second(const T &a, const T &b) {
    return a < b;
}

template<typename T>
bool third(const T &a, const T &b) {
    return a > b;
}

