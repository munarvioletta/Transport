
#include <iostream>
#include <time.h>
#include <string>
#include <memory> 
#include <cstdio>
#include"Transport.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

float Transport::go(float *) {}
bool Transport::stop() {}
void Transport::load() {}


int LandTransport::stay_in_traffic_jam() {}
float LandTransport::go(float * velocity) { return 0; }
bool LandTransport::stop() { return 0; }
void LandTransport::load() { cout << "Loading continiue"; }


float MotorVechicles:: go(float *) { return 0; }
bool MotorVechicles::stop() { return false; }
void MotorVechicles::load() {}
int MotorVechicles::stay_in_traffic_jam() { return 0; }

int MotorVechicles::getWheels() { return  wheels_quantity; }
int MotorVechicles::getSeets() { return seet_quantity; }
int MotorVechicles::getDoors() { return door_quantity; }
int MotorVechicles::getWindow() { return window_quantity; }
string MotorVechicles::getBrand() { return brand; }
bool MotorVechicles::getRadio() { return radio; }
bool MotorVechicles::getAirCond() { return air_conditioning; }

	Car::Car() {}
	
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



	void Car::setSilnik(string s) { silnik = s; }
	void Car::setWheels(int wh) { wheels_quantity = wh; }
	void Car::setSeets(int sits) { seet_quantity = sits; }
	void Car::setDoors(int doors) { door_quantity = doors; }
	void Car:: setWindows(int window) { window_quantity = window; }
	void Car::setBrand(string _brand) { brand = _brand; }
	void Car::if_exist_Radio(bool r) { radio = r; }
	void Car::if_air_conditioning(bool a) { air_conditioning = a; }


	float Car::go(float *v) {


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

	bool Car::stop() { return false; }

	void Car::load() {}

	int Car::stay_in_traffic_jam() { return 0; }



	void Car::show() {


		cout << "Motor: " << silnik << endl;
		cout << "Number of wheels: " << wheels_quantity << endl; 
		cout << "Numer of seets: " << seet_quantity << endl; 
		cout << "Numer of doors: " << door_quantity << endl; 
		cout << "Numer of windows: " << window_quantity << endl;  
		cout << "Brand: " << brand << endl;
		cout << "Is threre Radio : ";
		if (radio == 0) { cout << "false" << endl; }
		else { cout << "true" << endl; }
		cout << "Is there Air Condition: ";
		if (air_conditioning == 0) { cout << "false" << endl; }
		else { cout << "true" << endl << endl; }

	}
};

