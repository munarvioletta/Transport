//Transport.h

#ifndef  TRANSPORT_H
#define  TRANSPORT_H

#include <iostream>
#include <string>


class Transport {

public:

	virtual float go(float *) = 0;
	virtual bool stop() = 0;
	virtual void load() = 0;

};


class LandTransport : public Transport {

protected:

	int seet_quantity{ 0 }, door_quantity{ 0 }, window_quantity{ 0 };
	bool radio, air_conditioning;

public:

	virtual int stay_in_traffic_jam() = 0;

	LandTransport() {}
	LandTransport(int sq, int dq, int windq, bool r, bool air) : seet_quantity(sq), door_quantity(dq), window_quantity(windq),
		radio(r), air_conditioning(air) {}
	virtual ~LandTransport() {}

	float go(float * velocity);
	bool stop();
	void load();

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
	virtual ~MotorVechicles() {}

	float go(float *);
	bool stop();
	void load();
	int stay_in_traffic_jam();

	int getWheels();
	int getSeets();
	int getDoors();
	int getWindow();
	string getBrand();
	bool getRadio();
	bool getAirCond();
};

class Train : public RailVechicle {

protected:

	string name, marka;

public:

	Train(string _name, string _marka, int _carriage_quantity) : name(_name), marka(_marka), RailVechicle(_carriage_quantity) {}
	virtual ~Train() {}

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

	virtual ~Car() {}
	//Car(const Car &_car) 


	void setSilnik(string s);
	void setWheels(int wh);
	void setSeets(int sits);
	void setDoors(int doors);
	void setWindows(int window);
	void setBrand(string _brand);
	void if_exist_Radio(bool r);
	void if_air_conditioning(bool a);

	float go(float *v);
	bool stop();
	void load();
	int stay_in_traffic_jam();
	   
	void show();
};


#endif // ! TRANSPORT_H
