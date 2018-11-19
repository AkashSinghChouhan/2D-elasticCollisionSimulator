#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <string>



using namespace std;

int w{ Fl::w() / 2 }, h{ Fl::h() };

struct point {
	int x, y;
	point(int x, int y) { this->x = x; this->y = y; }

};

struct Windows : Fl_Double_Window {
	Windows(point topleft, int w, int h, string title) :Fl_Double_Window(topleft.x, topleft.y, w, h, title.c_str()) {
		color(FL_BLACK);
		show();

	}
}; 
