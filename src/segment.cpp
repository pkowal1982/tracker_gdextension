#include "segment.h"

namespace godot {

Segment::Segment(int p_from, int p_to, int p_row) {
	from = p_from;
	to = p_to;
	row = p_row;
	index = -1;
}

bool Segment::is_connected_with(Segment p_other) {
	return !(from > p_other.to || to < p_other.from);
}

bool Segment::has_index() {
	return index != -1;
}

bool Segment::set_index(int p_index) {
	if (index != -1 && index != p_index) {
		return false;
	}
	index = p_index;
	return true;
}

}

