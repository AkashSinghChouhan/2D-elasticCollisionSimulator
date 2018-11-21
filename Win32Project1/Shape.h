




struct Shape {
	int line_width, line_color, fill_color;
	vector<point> pts;
	Shape(int lw, int lc, int fc)
		: line_width(lw), line_color(lc), fill_color(fc) {}
	void add(point p) { pts.push_back(p); }
	void move(int dx, int dy) {
		for (int i = 0; i<pts.size(); i++) {
			pts[i].x += dx;
			pts[i].y += dy;
		}
	}
	virtual void draw() {}
};


struct Circle : Shape {
	int radius;
	Circle(point p, int r, int lw, int lc, int fc)
		: radius(r), Shape(lw, lc, fc) {
		add(p);
		move(-radius, -radius);
	}
	void draw() {
		fl_line_style(FL_SOLID, line_width);
		fl_color(fill_color);
		fl_pie(pts[0].x, pts[0].y, 2 * radius - 1, 2 * radius - 1, 0, 360);
		fl_color(line_color);
		fl_arc(pts[0].x, pts[0].y, 2 * radius, 2 * radius, 0, 360);
	}
};

struct Line : Shape {
	Line(point p1, point p2, int lw, int lc)
		: Shape(lw, lc, 0) {
		add(p1);
		add(p2);
	}
	void draw() {
		fl_line_style(FL_SOLID, line_width);
		fl_color(line_color);
		fl_line(pts[0].x, pts[0].y, pts[1].x, pts[1].y);
	}
};

struct Text : Shape {
	int font;
	string content;
	Text(point p, int f, int lw, int lc, string s)
		: font(f), content(s), Shape(lw, lc, 0) {
		add(p);
	}
	void draw() {
		fl_font(font, line_width);
		fl_color(line_color);
		fl_draw(content.c_str(), pts[0].x, pts[0].y);
	}
}; 
