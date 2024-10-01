#ifndef HSV_H
#define HSV_H

#include <godot_cpp/core/math.hpp>
#include <stdint.h>

namespace godot {

/*template <typename T, typename T2>
constexpr auto MIN(const T m_a, const T2 m_b) {
	return m_a < m_b ? m_a : m_b;
}

template <typename T, typename T2>
constexpr auto MAX(const T m_a, const T2 m_b) {
	return m_a > m_b ? m_a : m_b;
}*/

class HSV {
private:
	uint8_t h;
	uint8_t s;
	uint8_t v;

	static inline uint8_t min(uint8_t p_r, uint8_t p_g, uint8_t p_b) {
		return MIN(MIN(p_r, p_g), p_b);
	}
	static inline uint8_t max(uint8_t p_r, uint8_t p_g, uint8_t p_b) {
		return MAX(MAX(p_r, p_g), p_b);
	}
	inline bool is_similar(uint8_t p_a, uint8_t p_b, uint8_t p_threshold) {
		return p_a > p_b ? (p_a - p_b <= p_threshold) : (p_b - p_a <= p_threshold);
	}

public:
	static HSV from_argb32(uint32_t p_argb32);
	static HSV from_rgb(uint8_t p_h, uint8_t p_s, uint8_t p_v);

	HSV(uint8_t p_h, uint8_t p_s, uint8_t p_v);

	bool is_similar(HSV p_hsv, HSV p_threshold);
};

}

#endif
