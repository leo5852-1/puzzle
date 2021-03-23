#include<bangtal.h>

SceneID scene1, scene2;
ObjectID startButton;
ObjectID p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16;


ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown) {
	ObjectID object = createObject(image);

	locateObject(object, scene, x, y);

	if (shown) {
		showObject(object);
	}
	return object;
}

void location(int x, int y) {
	if (110 < x && x < 375 && 120 < x && x < 240) {
		x = 110, y = 120;
	}
	else if (375 < x && x < 640 && 120 < x && x < 240) {
		x = 375, y = 120;
	}
	else if (640 < x && x < 905 && 120 < x && x < 240) {
		x = 640, y = 120;
	}
	else if (905 < x && x < 1170 && 120 < x && x < 240) {
		x = 905, y = 120;
	}

	else if (110 < x && x < 375 && 240 < x && x < 360) {
		x = 110, y = 240;
	}
	else if (375 < x && x < 640 && 240 < x && x < 360) {
		x = 375, y = 240;
	}
	else if (640 < x && x < 905 && 240 < x && x < 360) {
		x = 640, y = 240;
	}
	else if (905 < x && x < 1170 && 240 < x && x < 360) {
		x = 905, y = 240;
	}

	else if (110 < x && x < 375 && 360 < x && x < 480) {
		x = 110, y = 360;
	}
	else if (375 < x && x < 640 && 360 < x && x < 480) {
		x = 375, y = 360;
	}
	else if (640 < x && x < 905 && 360 < x && x < 480) {
		x = 640, y = 360;
	}
	else if (905 < x && x < 1170 && 360 < x && x < 480) {
		x = 905, y = 360;
	}

	else if (110 < x && x < 375 && 480 < x && x < 600) {
		x = 110, y = 480;
	}
	else if (375 < x && x < 640 && 480 < x && x < 600) {
		x = 375, y = 480;
	}
	else if (640 < x && x < 905 && 480 < x && x < 600) {
		x = 640, y = 480;
	}
	else if (905 < x && x < 1170 && 480 < x && x < 600) {
		x = 905, y = 480;
	}
}

void mousecallback(ObjectID object, int x, int y, MouseAction action) {

	if (object == startButton) {
		enterScene(scene2);
		hideObject(startButton);
	}
	else {
		location(x, y);
		if (action == MouseAction::MOUSE_DRAG_LEFT) {
			locateObject(object, scene2, x - 265, y);
		}
		else if (action == MouseAction::MOUSE_DRAG_RIGHT) {
			locateObject(object, scene2, x + 265, y);
		}
		else if (action == MouseAction::MOUSE_DRAG_UP) {
			locateObject(object, scene2, x, y + 120);
		}
		else if (action == MouseAction::MOUSE_DRAG_DOWN) {
			locateObject(object, scene2, x, y - 120);
		}
	}
}

int main() {

	setMouseCallback(mousecallback);

	scene1 = createScene("원본", "Images/원본.jpg");
	scene2 = createScene("배경", "Images/배경.jpg");

	startButton = createObject("Images/start.png", scene1, 595, 80, true);
	p1 = createObject("Images/p1.jpg", scene2, 110, 480, true);
	p2 = createObject("Images/p2.jpg", scene2, 375, 480, true);
	p3 = createObject("Images/p3.jpg", scene2, 640, 480, true);
	p4 = createObject("Images/p4.jpg", scene2, 905, 480, true);
	p5 = createObject("Images/p5.jpg", scene2, 110, 360, true);
	p6 = createObject("Images/p6.jpg", scene2, 375, 360, true);
	p7 = createObject("Images/p7.jpg", scene2, 640, 360, true);
	p8 = createObject("Images/p8.jpg", scene2, 905, 360, true);
	p9 = createObject("Images/p9.jpg", scene2, 110, 240, true);
	p10 = createObject("Images/p10.jpg", scene2, 375, 240, true);
	p11 = createObject("Images/p11.jpg", scene2, 640, 240, true);
	p12 = createObject("Images/p12.jpg", scene2, 905, 240, true);
	p13 = createObject("Images/p13.jpg", scene2, 110, 120, true);
	p14 = createObject("Images/p14.jpg", scene2, 375, 120, true);
	p15 = createObject("Images/p15.jpg", scene2, 640, 120, true);
	p16 = createObject("Images/p16.jpg", scene2, 905, 120, true);

	startGame(scene1);


}