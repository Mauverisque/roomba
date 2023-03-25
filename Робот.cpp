#include <iostream>
#include <fstream>
using namespace std;

enum EState {EWork, Egraffity, Erotate, Emove};

class Sender {

};

class detector {
public:
	bool graffity_exist(int a) {
		cin >> a;
		return a;
	};
	bool angle(float alpfa) {
		cin >> alpfa;
		return alpfa;
	};
	bool distance(float dist) {
		cin >> dist;
		return dist;
	};
};


class Robot {
	EState state;
	detector det;
public:
	Robot() {
		state = EWork;

	}
	void Events() {
		switch (state) {
		case EWork:
			if (det.graffity_exist('Yes')) state = Egraffity;
			break;
		case Egraffity:
			if (det.angle(10)) state = Erotate;
			if (det.distance(10)) state = Emove;
			break;
		case Erotate:
			//command->Rotate(3)
			state = EWork;
			break;
		case Emove:
			//
			state = EWork;
			break;
		}
	}
	void Run() {
		while (True) Events();
	}
};

int main() {
	Robot bot;
	bot.run();

}