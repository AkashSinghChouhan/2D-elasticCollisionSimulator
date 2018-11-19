#include"GUI.h"


int main() {
	
	Windows window(point(w, 0), w, h, "Part3");
	Line line1(point(0, h / 4), point(w, h / 4), 3, FL_WHITE);
	Line line2(point(w / 2, 0), point(w / 2, h / 4), 3, FL_WHITE);
	Circle circle1(point(w / 2, h / 2), 25, 1, FL_GREEN, FL_BLUE);
	Text text1(point(200, 50), FL_HELVETICA, 25, FL_RED, "INPUT");
	Text text2(point(w / 2 + 200, 50), FL_HELVETICA, 25, FL_RED, "OUTPUT");
	window.attach(line1);
	window.attach(line2);
	window.attach(text1);
	window.attach(text2);
	window.attach(circle1);
	

	return Fl::run();
}