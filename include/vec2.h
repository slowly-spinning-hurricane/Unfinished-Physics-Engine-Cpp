/* INCOMPLETE as of 10 August 2025 */

#ifndef __vec2_h
#   define __vec2_h 1
#include <math.h> // sin, cos, tan, sqrt, pow, atan2

typedef struct {
    float x, y;
} vec2;

typedef struct {
    vec2 init, vec2 fini;
} line;

vec2 sum(vec2 v1, vec2 v2) {
    return (vec2) {
        .x = v1.x + v2.x, 
        .y = v1.y + v2.y
    };
}

vec2 inverse(vec2 v) {
    return (vec2) {
        .x = -v.x,
        .y = -v.y
    };
} // additive inverse of v.

vec2 relative(vec2 v1, vec2 v2) {
    return v2.sum(inverse(v1)); // v2 - v1; v2 relative to v1
}

vec2 multiply(vec2 v, float f) {
    return (vec2) {
        .x = v.x * f,
        .y = v.y * f
    };
}

float dot(vec2 v1, vec2 v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

vec2 conjugate(vec2 v) {
    return (vec2) {
        .x = v.x,
        .y = -v.y
    };
}

vec2 rotate(vec2 v, float theta) {
    return (vec2) {
        .x = v.x * cos(theta) - v.y * sin(theta),
        .y = v.x * sin(theta) + v.y * cos(theta)
    };
}

float modulus(vec2 v) {
    return sqrt(dot(v, v));
}

vec2 unit_vector(vec2 v) {
    float v_mod = modulus(v);
    return (v_mod > 0) ? multiply(v, 1.0f / v_mod): (vec2) {.x = 0, .y = 0};
}

float arg(vec2 v) {
    return atan2(v.y, v.x);
}

float slope(vec2 v) {
    return tan(arg(v));
}

void print_line(line L) {
    printf("Initial: (%f, %f)\nFinal: (%f, %f)",
            L.init.x, L.init.y, L.fini.x, L.fini.y);
    return;
}

float gradient(line L) {
    return (L.fini.x == L.init.x) ? 0.0 : slope(relative(L.fini, L.init));
    // return a default slope of 0 to avert a zero-divisor disaster
}

#endif /* vec2.h */


