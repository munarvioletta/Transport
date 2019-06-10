
#include <iostream>
#include <time.h>
#include <string>
#include <memory> 
#include <cstdio>

using namespace std;

class Transport {

public:

	virtual float go(float *) = 0;
	virtual bool stop() = 0;
	virtual void load() = 0;

};


class LandTransport : public Transport {

protected:

	int seet_quantity = 0, door_quantity = 0, window_quantity = 0;
	bool radio, air_conditioning;

public:

	virtual int stay_in_traffic_jam() = 0;

	LandTransport() {}
	LandTransport(int sq, int dq, int windq, bool r, bool air) : seet_quantity(sq), door_quantity(dq), window_quantity(windq),
		radio(r), air_conditioning(air) {}
	virtual ~LandTransport() {}

	float go(float * velocity) { return 0; }
	bool stop() { return 0; }
	void load() {}

};


class RailVechicle : public LandTransport {

protected:

	int carriage_quantity;

public:
	RailVechicle() {}
	RailVechicle(int carrq) : carriage_quantity(carrq) {}
	virtual ~RailVechicle() {}
};

class MotorVechicles : public LandTransport {

protected:

	int wheels_quantity;
	string brand;

public:

	MotorVechicles() {}
	MotorVechicles(int wq, int sq, int dq, int windq, bool r, bool air, string br) : wheels_quantity(wq), LandTransport(sq, dq, windq, r, air), brand(br) {}

	float go(float *) { return 0; }
	bool stop() { return false; }
	void load() {}
	int stay_in_traffic_jam() { return 0; }

	int & getWheels() { return  wheels_quantity; }
	int getSeets() { return seet_quantity; }
	int getDoors() { return door_quantity; }
	int getWindow() { return window_quantity; }
	string getBrand() { return brand; }
	bool getRadio() { return radio; }
	bool getAirCond() { return air_conditioning; }
};

class Train : public RailVechicle {

protected:

	string name, marka;

public:

	Train(string _name, string _marka, int _carriage_quantity) : name(_name), marka(_marka), RailVechicle(_carriage_quantity) {}

};

class Carriage : public LandTransport {


};


class Car : public MotorVechicles {

	string silnik, brand = getBrand();
	float distance = 0;
	int wheelq = getWheels(), seetq = getSeets(), doorq = getDoors(), windowsq = getWindow();
	bool rad = getRadio(), air = getAirCond();

public:

	Car() {}
	Car(string _silnik, int wq, int sq, int dq, int windq, string _brand, bool _r, bool _air) :
		silnik(_silnik),
		MotorVechicles(wq, sq, dq, windq, _r, _air, _brand) {}

	//Car(const Car &_car) {
	//
	//
	//	this->silnik = _car.silnik;		
	//	wheels_quantity = _car.wheelq;
	//    seet_quantity = _car.seetq;
	//	door_quantity = _car.doorq;
	//	window_quantity = _car.windowsq;
	//	brand = _car.brand;
	//	radio = _car.rad;
	//	air_conditioning = _car.air;
	//			   			
	//}



	void setSilnik(string s) { silnik = s; }
	void setWheels(int wh) { wheels_quantity = wh; }
	void setSeets(int sits) { seet_quantity = sits; }
	void setDoors(int doors) { door_quantity = doors; }
	void setWindows(int window) { window_quantity = window; }
	void setBrand(string _brand) { brand = _brand; }
	void if_exist_Radio(bool r) { radio = r; }
	void if_air_conditioning(bool a) { air_conditioning = a; }


	float go(float *v) {


		int count = 0;
		char liczba = '0';

		clock_t start = clock();

		cout << "wybierz numer: ";  cin >> liczba;

		while (liczba != '2') {

			count += 1;
			cin.get(liczba);


		}

		clock_t end = clock();

		float czas = (float)(end - start) / CLOCKS_PER_SEC;

		distance = *v * czas;


		return distance;
	}

	bool stop() { return false; }

	void load() {}

	int stay_in_traffic_jam() { return 0; }



	void show() {


		cout << "Motor: " << silnik << endl;
		cout << "Number of wheels: " << wheels_quantity << endl; //byla zmiana z wheelq na wheels_quantity
		cout << "Numer of seets: " << seet_quantity << endl; //byla zmiana z sheelq na 
		cout << "Numer of doors: " << door_quantity << endl; //byla zmiana doorq na wheels_quantity
		cout << "Numer of windows: " << window_quantity << endl;  //byla zmiana windowsq na wheels_quantity
		cout << "Brand: " << brand << endl;
		cout << "Is threre Radio : ";
		if (radio == 0) { cout << "false" << endl; }
		else { cout << "true" << endl; }
		cout << "Is there Air Condition: ";
		if (air_conditioning == 0) { cout << "false" << endl; }
		else { cout << "true" << endl << endl; }

	}
};

