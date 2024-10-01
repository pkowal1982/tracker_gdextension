#ifndef HSV_TRACKER_H
#define HSV_TRACKER_H

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/image.hpp>

namespace godot {

class HsvTracker : public RefCounted {
	GDCLASS(HsvTracker, RefCounted);

protected:
	static void _bind_methods();

public:
	Vector3 track(Ref<Image> p_image, Color p_example, Vector3 p_threshold, Ref<Image> p_destination_image);

private:
	bool wrong_format(Ref<Image> p_image);
	void update_destination_image(Ref<Image> p_destination_image, Vector2i p_size, PackedByteArray p_data, Vector2i p_center);
	void draw_cross(Ref<Image> p_image, Vector2i p_center);
};

}

#endif

