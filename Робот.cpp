#include <iostream>
#include <fstream>
using namespace std;

enum EState {EWork, Egraffity, Erotate, Emove};

class Sender {

public:
    void send_Rotate() {
        cout << "Rotating" << endl;
    }
    void send_Moving() {
        cout << "Moving" << endl;
    }
};

class Detector {
public:
	bool graffity_exist(bool a) {
		cin >> a;
		return a;
	};
	bool angle(float betta) {
		cin >> betta;
		return betta;
	};
	bool distance(float dist) {
		cin >> dist;
		return dist;
	};
};

class Robot {
	EState state;
	Detector det;
    Sender send;
    const float a = 5, b = 10;
    bool f = false;

public:
	Robot() {
		state = EWork;

	}
	void Events() {
		switch (state) {
		case EWork:
			if (det.graffity_exist()) state = Egraffity;
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
		}
	}
	void Run() {
        while (!f) Events();
        cout << "End" << endl;
        f = false;
	}
};

int main() {
    bool t = true;
	Robot bot;
    while (t) {
        bot.Run();
    }
}