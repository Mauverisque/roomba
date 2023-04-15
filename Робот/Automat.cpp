#include <iostream>
#include <fstream>
using namespace std;

enum EState { EDetect, EWork, ERotate, EMove, EClean, EFinish, EDance };

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
		state = EDetect;
	}
	void events() {
		switch (state) {
		case EDetect:
			if (det.graffity_exist(a)) state = EWork;
			else state = EDance;
			break;
		case EWork:
			if (det.angle(a)) state = ERotate;
			else if (det.distance(b)) state = EMove;
			else state = EClean;
			break;
		case ERotate:
			send.send_rotate();
			if (det.distance(b)) state = EMove;
			else state = EClean;
			break;
		case EMove:
			send.send_moving();
			state = EClean;
			break;
		case EClean:
			send.send_cleaning();
			state = EDetect;
			break;
		case EDance:
			send.send_dancing();
			state = EFinish;
			break;
		case EFinish:
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
