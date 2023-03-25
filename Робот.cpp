#include <iostream>
#include <fstream>
using namespace std;

enum EState { EWork, Egraffity, Erotate, Emove, Efinish, Edance };

class Sender {

public:
	void send_Rotate() {
		cout << "Rotating" << endl;
	}
	void send_Moving() {
		cout << "Moving" << endl;
	}
	void send_Dancing() {
		cout << "Dancing" << endl;
	}
};

class Detector {
public:
	bool graffity_exist(bool a) {
		cin >> a;
		return a;
	}
	float angle(float betta) {
		cin >> betta;
		return betta;
	}
	float distance(float dist) {
		cin >> dist;
		return dist;
	}
};

class Robot {
	EState state;
	Detector det;
	Sender send;
	const float a = 5, b = 10;
	bool quit = false;

public:
	Robot() {
		state = EWork;
	}
	void Events() {
		switch (state) {
		case EWork:
			if (det.graffity_exist()) state = Egraffity;
			else state = Edance;
			break;
		case Egraffity:
			if (det.angle(a)) state = Erotate;
			else if (det.distance(b)) state = Emove;
			break;
		case Erotate:
			send.send_Rotate();
			state = EWork;
			break;
		case Emove:
			send.send_Moving();
			state = EWork;
			break;
		case Edance:
			send.send_Dancing();
			state = Efinish;
		case Efinish:
			quit = true;

		}
	}
	void Run() {
		while (!quit) Events();
		cout << "End" << endl;
		quit = false;
	}
};

int main() {
	bool t = true;
	Robot bot;
	while (t) {
		bot.Run();
	}
}
