#ifndef COLOR_H
#define COLOR_H

#include "rtweekend.hpp"
#include "interval.hpp"

#include "vec.hpp"


using color = vec3;

inline double linear_to_gamma(double linear_component){
    return linear_component > 0 ? std::sqrt(linear_component) : 0;
}


uint32_t pack_color(const color& pixel_color) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);

    static const interval intensity(0.000, 0.999);

    uint8_t ir = static_cast<uint8_t>(256 * intensity.clamp(r));
    uint8_t ig = static_cast<uint8_t>(256 * intensity.clamp(g));
    uint8_t ib = static_cast<uint8_t>(256 * intensity.clamp(b));

    return (ir << 24) | (ig << 16) | (ib << 8) | 255;
}



#endif 