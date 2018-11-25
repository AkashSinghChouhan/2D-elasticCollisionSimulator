#include"GUI.h"
#include<time.h>

Windows window(point(w, 0), w, h, "testing_phase");
Line line1(point(0, h / 4), point(w, h / 4), 3, FL_WHITE);
Line line2(point(w / 2, 0), point(w / 2, h / 4), 3, FL_WHITE);
//Circle circle1(point(w / 2, h / 2), 25, 1, FL_GREEN, FL_BLUE);
Text text1(point(200, 50), FL_HELVETICA, 25, FL_RED, "INPUT");
Text text2(point(w / 2 + 200, 50), FL_HELVETICA, 25, FL_RED, "OUTPUT");

Slider slider1(point(50, 80), 100, 30, "Particle speed.");
In_box inbox1(point(50, 120), 100, 30, "Number of particles.");

Out_box outbox1(point(w / 2 + 50, 80), 100, 30, "Number of collisions.");
Out_box outbox2(point(w / 2 + 50, 120), 100, 30, "Time elapsed (seconds).");

#include"CallBack1.h"
Button button1(point(200, 170), 100, 30, "RUN", callback1);
Button button2(point(w / 2 + 200, 170), 100, 30, "PLOT", callback1);



int main() {
	srand(time(NULL));
    window.attach(line1);
	window.attach(line2);
	window.attach(text1);
	window.attach(text2);
	//window.attach(circle1);

	window.attach(slider1);
	window.attach(inbox1);
	window.attach(button1);
	window.attach(outbox1);
	window.attach(outbox2);
	window.attach(button2);

	slider1.set_value(500);
	slider1.set_bounds(100, 1000);
	inbox1.set_value("10");
	outbox1.set_value("0");
	outbox2.set_value("0");
	

	return Fl::run();
}