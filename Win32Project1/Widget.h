

struct Widget {
	int width, height;
	string label;
	point xy;
	Callback do_it;
	Windows *own;
	Widget(point p, int w, int h, string s, Callback cb)
		: xy(p), width(w), height(h), label(s), do_it(cb) {}
	virtual void attach(Windows&) {}
}; 

struct Slider : Widget {
	Fl_Slider* pw;
	Slider(point p, int w, int h, string s)
		: Widget(p, w, h, s, 0) {}
	void set_value(int v) { pw->value(v); }
	int get_value() { return pw->value(); }
	void set_bounds(int b1, int b2) { pw->bounds(b1, b2); }
	void attach(Windows &window) {
		pw = new Fl_Slider(xy.x, xy.y, width, height, label.c_str());
		pw->type(FL_HOR_NICE_SLIDER);
		pw->align(FL_ALIGN_RIGHT);
		pw->labelfont(FL_COURIER_ITALIC);
		pw->labelcolor(FL_WHITE);
		pw->labelsize(14);
		own = &window;
	}
};

struct In_box : Widget {
	Fl_Input* pw;
	In_box(point p, int w, int h, string s)
		: Widget(p, w, h, s, 0) {}
	void set_value(string s) { pw->value(s.c_str()); }
	string get_value() { return string(pw->value()); }
	void attach(Windows &window) {
		pw = new Fl_Input(xy.x, xy.y, width, height, label.c_str());
		pw->align(FL_ALIGN_RIGHT);
		pw->color(FL_WHITE);
		pw->textfont(FL_COURIER);
		pw->textcolor(FL_BLACK);
		pw->textsize(12);
		pw->labelfont(FL_COURIER_ITALIC);
		pw->labelcolor(FL_WHITE);
		pw->labelsize(14);
		own = &window;
	}
};

struct Button : Widget {
	Fl_Button* pw;
	Button(point p, int w, int h, string s, Callback cb)
		: Widget(p, w, h, s, cb) {}
	void attach(Windows &window) {
		pw = new Fl_Button(xy.x, xy.y, width, height, label.c_str());
		pw->callback(do_it);
		pw->color(FL_DARK_BLUE);
		pw->labelfont(FL_COURIER_BOLD_ITALIC);
		pw->labelcolor(FL_WHITE);
		pw->labelsize(14);
		own = &window;
	}
};



struct Out_box : Widget {
	Fl_Text_Display* pw;
	Fl_Text_Buffer* buff;
	Out_box(point p, int w, int h, string s)
		: Widget(p, w, h, s, 0) {}
	void set_value(string s) { buff->text(s.c_str()); }
	void attach(Windows &window) {
		pw = new Fl_Text_Display(xy.x, xy.y, width, height, label.c_str());
		buff = new Fl_Text_Buffer();
		pw->buffer(buff);
		pw->align(FL_ALIGN_RIGHT);
		pw->color(FL_BLACK);
		pw->textfont(FL_COURIER);
		pw->textcolor(FL_WHITE);
		pw->textsize(12);
		pw->labelfont(FL_COURIER_ITALIC);
		pw->labelcolor(FL_WHITE);
		pw->labelsize(14);
		own = &window;
	}
};

