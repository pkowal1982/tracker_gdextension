#ifndef SEGMENT_H
#define SEGMENT_H

namespace godot {

class Segment {
private:
	friend class MarkerTracker;

	int from;
	int to;
	int index;
	int row;

	bool is_connected_with(Segment other);
	bool has_index();
	bool set_index(int index);

public:
	Segment(int p_from, int p_to, int p_row);
};

}

#endif

