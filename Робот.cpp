#include <iostream>
#include <fstream>
using namespace std;

enum EState { Edetect, Ework, Erotate, Emove, Eclean, Efinish, Edance };

class Sender {

public:
	void send_rotate() {
		cout << "Rotating" << endl;
	}
	void send_moving() {
		cout << "Moving" << endl;
	}
	void send_cleaning() {
		cout << "Cleaning" << endl;
	}
	void send_dancing() {
		cout << "Dancing" << endl;
	}
};

class Detector {
public:
	bool graffity_exist(bool a) {
		cout << "Is there any graffiti?\n";
		cin >> a;
		return a;
	}
	float angle(float beta) {
		cout << "What angle should the robot rotate at?\n";
		cin >> beta;
		return beta;
	}
	float distance(float dist) {
		cout << "What distance should the robot move?\n";
		cin >> dist;
		return dist;
	}
};

class Robot {
	EState state;
	Detector det;
	Sender send;
	const float a = 5, b = 10;
	bool end = false;

public:
	Robot() {
		state = Edetect;
	}
	void events() {
		switch (state) {
		case Edetect:
			if (det.graffity_exist(a)) state = Ework;
			else state = Edance;
			break;
		case Ework:
			if (det.angle(a)) state = Erotate;
			else if (det.distance(b)) state = Emove;
			else state = Eclean;
			break;
		case Erotate:
			send.send_rotate();
			if (det.distance(b)) state = Emove;
			else state = Eclean;
			break;
		case Emove:
			send.send_moving();
			state = Eclean;
			break;
		case Eclean:
			send.send_cleaning();
			state = Edetect;
			break;
		case Edance:
			send.send_dancing();
			state = Efinish;
			break;
		case Efinish:
			end = true;
			break;
		}
	}
	void run() {
		while (!end) events();
		cout << "End" << endl;
	}
};

int main() {
	bool quit = false;
	Robot bot;
	while (!quit){
		bot.run();
		quit = true;
	}
}
