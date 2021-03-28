#define _CRT_SECURE_NO_WARNINGS
#include<bangtal.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

SceneID scene1;
ObjectID startButton;
ObjectID game_board[16], original_board[16];
int blank = 15;

bool game = false;

TimerID timer;
float timerValue = 0.05f;
int mixCount;

int indexToX(int i) {
	return 110 + 265 * (i % 4);
}

int indexToY(int i) {
	return 480 - 120 * (i / 4);
}

int game_index(ObjectID object) {
	for (int i = 0; i < 16; i++) {
		if (game_board[i] == object) return i;
	}
	return -1;
}

void game_move(int i) {
	ObjectID object = game_board[i];
	game_board[i] = game_board[blank];
	locateObject(game_board[i], scene1, indexToX(i), indexToY(i));
	game_board[blank] = object;
	locateObject(game_board[blank], scene1, indexToX(blank), indexToY(blank));

	blank = i;
}

bool possible_move(int i) {
	if (i % 4 > 0 && blank == i -1) return true;
	if (i % 4 < 3 && blank == i + 1) return true;
	if (i / 4 > 0 && blank == i - 4) return true;
	if (i / 4 < 3 && blank == i + 4) return true;

	return false;
}

int random_move() {
	int i = -1;
	while (i == -1) {
		switch (rand() % 4) {
			case 0: if (blank % 4 > 0) i = blank - 1;
				break;
			case 1: if (blank % 4 < 3) i = blank + 1;
				break;
			case 2: if (blank / 4 > 0) i = blank - 4;
				break;
			case 3: if (blank / 4 < 3) i = blank + 4;
				break;
		}
	}
	return i;
}

bool game_end() {
	for (int i = 0; i < 16; i++) {
		if (game_board[i] != original_board[i]) return false;
	}
	return true;
}

void game_start() {
	blank = 15;
	hideObject(game_board[blank]);

	mixCount = 50;

	setTimer(timer, timerValue);
	startTimer(timer);
}

ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown=true) {
	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);

	if (shown) showObject(object);
	
	return object;
}

void mousecallback(ObjectID object, int x, int y, MouseAction action) {

	if (game) {
		int i = game_index(object);
		if (possible_move(i))
			game_move(i);
		if (game_end()) {
			game = false;
			showObject(startButton);
			showObject(game_board[blank]);
			showMessage("퍼즐 완성!");
			}
	}
	else {
		if (object == startButton) {
			game_start();
		}
	}
}

void timerCallback(TimerID timer) {
	game_move(random_move());
	
	mixCount--;
	if (mixCount > 0) {
		setTimer(timer, timerValue);
		startTimer(timer);
	}
	else {
		game = true;
		hideObject(startButton);
	}
}

SceneID game_init() {
	
	scene1 = createScene("배경", "Images/배경.jpg");
	
	char buf[50];
	for (int i = 0; i < 16; i++) {
		sprintf(buf, "Images/%d.jpg", i + 1);
		game_board[i] = createObject(buf, scene1, indexToX(i), indexToY(i));
		original_board[i] = game_board[i];
	}
	
	startButton = createObject("Images/start.png", scene1, 595, 80);
	
	timer = createTimer(timerValue);

	return scene1;
}

int main() {
	
	srand(time(NULL));

	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);

	setMouseCallback(mousecallback);	
	setTimerCallback(timerCallback);
	startGame(game_init());
}