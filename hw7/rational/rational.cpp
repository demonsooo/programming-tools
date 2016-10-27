/*
 * HW7
 * CSE 374 HW7, 15au
 * YIJIA LIU
 * 1238339
 */

#include "rational.h"
#include <cmath>

// Construct Rational 0/1
Rational::Rational() {
    num = 0;
    denom = 1;
}

// Construct Rational n/1
Rational::Rational(int n) {
    num = n;
    denom = 1;
}

// Construct Rational n/d
Rational::Rational(int n, int d) {
    if (d < 0) {
        d = -d;
        n = -n;
    }
    num = n;
    denom = d;
}

// return the numerator and denominator of this Rational
int Rational::n() {
    return num;
}

int Rational::d() {
    return denom;
}

// reduce the fraction into simplest form
void reduce(int* a, int* b) {
    int Commondenom = 1;
    for (int i = 2; i <= abs(*a) && i <= abs(*b); i++) {
        if (*a % i == 0 && *b % i == 0) {
            Commondenom = i;
        }
    }
    *a /= Commondenom;
    *b /= Commondenom;
}

// = this + other
Rational Rational::plus(Rational other) {
    int d = denom * other.d();
    int n = num * other.d()+ other.n() * denom;
    reduce(&d, &n);
    return Rational(n, d);
}

// = this - other
Rational Rational::minus(Rational other) {
    int d = denom * other.d();
    int n = num * other.d() - other.n() * denom;
    reduce(&d, &n);
    return Rational(n, d);
}

// = this * other
Rational Rational::times(Rational other) {
    int n = num * other.n();
    int d = denom * other.d();
    reduce(&d, &n);
    return Rational(n, d);
}

// = this / other
Rational Rational::div(Rational other) {
    int n = num * other.d();
    int d = denom * other.n();
    reduce(&d, &n);
    return Rational(n, d);
}
