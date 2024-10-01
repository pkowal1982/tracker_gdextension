#ifndef MARKER_TRACKER_H
#define MARKER_TRACKER_H

#include <godot_cpp/core/error_macros.hpp>
#include <godot_cpp/classes/image.hpp>
//#include "core/math/math_funcs.h"
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/templates/hash_map.hpp>
#include <godot_cpp/templates/hash_set.hpp>
#include "segment.h"
#include <stdint.h>

namespace godot {

class MarkerTracker : public RefCounted {
	GDCLASS(MarkerTracker, RefCounted);

protected:
	static void _bind_methods();

public:
	Vector3 track(Ref<Image> p_image, Vector3 p_previous_position);
	MarkerTracker();

private:
	static const float THRESHOLD;
	static const int THRESHOLD_GRAYSCALE = 0xC0;
	static const float MAX_DISTANCE;

	int index = -1;

	HashMap<int, List<Segment *>> find_areas(Ref<Image> p_image, HashSet<int> &p_excluded);
	void filter_areas(HashMap<int, List<Segment *>> p_areas, HashSet<int> &p_excluded);
	List<Segment *> find_segments(Ref<Image> p_image, int p_row);
	List<Segment *> find_segments_grayscale(Ref<Image> p_image, int p_row);
	void connect_segments(List<Segment *> p_top, List<Segment *> p_bottom, HashSet<int> &p_excluded);
	Vector3 find_marker(HashMap<int, List<Segment *>> p_areas, HashSet<int> p_excluded);
	Vector3 find_center(Ref<Image> p_image, Vector3 p_previous_position);
	Rect2 find_center_and_bounding_box(List<Segment *> p_segments);
};

}

#endif

