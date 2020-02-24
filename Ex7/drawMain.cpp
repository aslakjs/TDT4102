#include "drawMain.h"
#include "Simple_window.h"
#include "Emoji.h"
#include "face.h"

// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

void drawMain(void) {
	using namespace Graph_lib;
	Vector_ref<Emoji> emojoies;
	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};

	// Smiley #1: Empty face emoji:
	Point pEf{100,100};
	EmptyFace ef(pEf, emojiRadius);
	emojoies.push_back(ef);

	// Smiley #2: Smiley:
	Point pSm{xmax/2,ymax/2};
	Smiley sm(pSm, emojiRadius);
	emojoies.push_back(sm);

	// Smiley #3: SadFace:
	Point pSf{xmax-100,100};
	SadFace sf(pSf, emojiRadius);
	emojoies.push_back(sf);

	// Smiley #4: Surprised:
	Point pS{xmax-100,ymax-100};
	Surprised sS(pS, emojiRadius);
	emojoies.push_back(sS);

	// Smiley #5: Wink
	Point pW{100, ymax-100};
	WinkyFace sW(pW, emojiRadius);
	emojoies.push_back(sW);

	for (int i = 0; i < emojoies.size(); i++) {
		emojoies[i].attach_to(win);
	}
	win.wait_for_button();
}
