#include "hsv.h"

namespace godot {

HSV HSV::from_argb32(uint32_t p_argb32) {
	return from_rgb(p_argb32 >> 16 & 0xFF, p_argb32 >> 8 & 0xFF, p_argb32 & 0xFF);
}

HSV HSV::from_rgb(uint8_t p_r, uint8_t p_g, uint8_t p_b) {
	uint8_t v = max(p_r, p_g, p_b);

	int tmp = min(p_r, p_g, p_b);
	int h = 0;
	int s = 0;
	if (tmp != v) {
		if (p_r == v) {
			h = (p_g - p_b) * 43 / (v - tmp);
		} else {
			if (p_g == v) {
				h = 85 + (p_b - p_r) * 43 / (v - tmp);
			} else {
				h = 171 + (p_r - p_g) * 43 / (v - tmp);
			}
		}

		if (h < 0) {
			h += 255;
		}
		if (v != 0) {
			s = 255 * (v - tmp) / v;
		}
	}
	return HSV(h, s, v);
}

HSV::HSV(uint8_t p_h, uint8_t p_s, uint8_t p_v) {
	h = p_h;
	s = p_s;
	v = p_v;
}

bool HSV::is_similar(HSV p_hsv, HSV p_threshold) {
	return is_similar(h, p_hsv.h, p_threshold.h) && is_similar(v, p_hsv.v, p_threshold.v) && is_similar(s, p_hsv.s, p_threshold.s);
}

}

