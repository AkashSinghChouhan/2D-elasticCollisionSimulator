#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Display.H>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

using Callback = void(*)(Fl_Widget*, void*);

int w{ Fl::w() / 2 }, h{ Fl::h() };

struct point {
	int x, y;
	point(int x, int y) { this->x = x; this->y = y; }

};
struct Windows;



#include "shape.h"
#include "Widget.h"
#include "Windows.h"



