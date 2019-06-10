#include <iostream>
#include <time.h>
#include <string>
#include <memory> 

using namespace std;


class Transport {

	public:

		virtual float go(float *) = 0;
		virtual bool stop() = 0;
		virtual void load() = 0;

};

class LandTransport : public Transport {

	protected:

		int seet_quantity, door_quantity, window_quantity;
		bool radio, air_conditioning;
		
	public:

		virtual int stay_in_traffic_jam() = 0;

		LandTransport() {}
		LandTransport(int sq, int dq, int windq) : seet_quantity(sq), door_quantity(dq), window_quantity(windq) {}

		float go(float * velocity) {return 0;}
		bool stop() { return 0; }
		void load() {}

};

class RailVechicle : public LandTransport {
	   	
	protected:

		int carriage_quantity;

	public:
		RailVechicle() {}
		RailVechicle(int carrq) : carriage_quantity(carrq) {}
};

class MotorVechicles : public LandTransport{

	protected:

		int wheels_quantity;	
		string brand;

	public:

		MotorVechicles() {}
		MotorVechicles(int wq, int sq, int dq, int windq, string br) : wheels_quantity(wq), LandTransport (sq, dq, windq), brand(br) {}

		float go(float *) { return 0; }
		bool stop() { return false; }
		void load() {}
		int stay_in_traffic_jam() { return 0; }
};

class Train : public RailVechicle{

	protected:

		string name, marka;

	public:

		Train(string _name, string _marka, int _carriage_quantity) : name(_name), marka(_marka), RailVechicle (_carriage_quantity) {}

};

class Carriage : public LandTransport {
	   	
	
};


class Car : public MotorVechicles {
	
	string name, silnik, felgi, brand;
	int  dist;
	//int wheelq, seetq, doorq, windowsq,

		
	public:

		Car() {}
		Car(string _name, string _silnik, string _felgi, int wq, int sq, int dq, int windq, string _brand) : name (_name), 
																							  silnik(_silnik), felgi(_felgi),
																							  MotorVechicles (wq, sq, dq, windq, _brand) {}

		//Car(const Car &_car) {
		//
		//	this->name = _car.name;
		//	this->silnik = _car.silnik;
		//	this->felgi = _car.felgi;
		//	wheels_quantity = _car.wheelq;
		//    seet_quantity = _car.seetq;
		//	door_quantity = _car.doorq;
		//	window_quantity = _car.windowsq;
		//	brand = _car.brand;
		//	
		//}

		void setName(string n)   { name = n; }
		void setSilnik(string s) { silnik = s; }
		void setFelgi(string f)  { felgi = f; }		
		void setWheels(int wh)   { wheels_quantity = wh; }
		void setSeets(int sits)  {seet_quantity = sits; }
		void setDoors(int doors) {door_quantity = doors;}
		void setWindows(int window) { window_quantity = window; }
		void setBrand(string _brand)   { brand = _brand; }
		void if_exist_Radio(bool rad) { radio = rad; }
		void if_air_conditioning(bool air_cond) { air_conditioning = air_cond; }


		float go(float *v) { 
			

			bool x;
			time_t start, end;
			time(&start);

			//while (getchar() != 32 || getchar() != ' ');		
			while (!stop())

				time(&end);

			time_t czas = (difftime(end, start) / CLOCKS_PER_SEC);

			float distance = *v * czas;

			return dist; 
		}
		bool stop() { return false;}

		void load() {}

		int stay_in_traffic_jam() { return 0;}



		void show() {

			cout << "Name: " << name << endl;
			cout << "Motor: " << silnik << endl;
			cout << "Rims name: " << felgi << endl;
			cout << "Number of wheels: " << wheels_quantity << endl; //byla zmiana z wheelq na wheels_quantity
			cout << "Numer of seets: " << seet_quantity << endl; //byla zmiana z sheelq na 
			cout << "Numer of doors: " << door_quantity << endl; //byla zmiana doorq na wheels_quantity
			cout << "Numer of windows: " << window_quantity << endl;  //byla zmiana windowsq na wheels_quantity
			cout << "Brand: " << brand << endl;
			cout << "Is threre Radio : " << radio << endl;
			cout << "Is there Air Condition: " << air_conditioning << endl;


		}
};


class Builder {

	protected:

		 shared_ptr<Car> car;

	public:

		void setCar() {

			shared_ptr<Car> car(new Car()); //dynamiczne alokowanie pamieci pod nowy samochod
		}

		Car getCar() {
			
			return *car ;
		}
		 
		virtual void buildName(string ) = 0;
		virtual void buildSilnik(string ) = 0;
		virtual void buildFelgi(string ) = 0;
		virtual void buildWheels() = 0;
		virtual void buildSeets(int ) = 0;
		virtual void buildDoors(int ) = 0;
		virtual void buildWindows(int ) = 0;
		virtual void buildBrand(string ) = 0;
		virtual void buildRadio(bool ) = 0;
		virtual void buildAirCond(bool ) = 0;
};

class OffRoadCar: public Builder {

	public:

		OffRoadCar() : Builder() {}

		void buildName(string  _name_) {

			car->setName(_name_ = "Bla");

		}
		
		void buildSilnik(string _silnik_) {

			car->setSilnik(_silnik_ = "s");

		}

		void buildFelgi(string _felgi_) {
			
			car->setFelgi(_felgi_ ="f");

		}

		void buildWheels() {

			car->setWheels(4);

		}

		void buildSeets(int  _seets_) {

			car->setSeets(_seets_ = 0);
				
		}

		void buildDoors(int _door_){
		
			car->setDoors(_door_= 0);
		
		}

		void buildWindows(int _window_) {

			car->setWindows(_window_= 0);
		}

		void buildBrand(string  _brand_) {

			car->setBrand(_brand_ = "m&m");

		}

		void buildRadio(bool  rad) {

			car->if_exist_Radio(rad = 0);
		}

		void buildAirCond(bool  air) {

			car->if_air_conditioning(air = 0);
		}
		
};

class Director {

	private:

		shared_ptr<Builder> builder;
		string name;
		string sil;
		string felg;
		int door;
		int se;
		int window;
		string brand;
		bool radio;
		bool aircondition;


	public:

		void setBuilder(shared_ptr<Builder> b) {

			builder = b;
		}

		Car getCar() {

			return builder->getCar();
		}

		void fill(string n) { name = n; }
		void fill(string n, string s, string f, int d , int seet, 
					int wind, string br, bool r, bool air ) {

			name = n;
			sil = s;
			felg = f;
			door = d;
			se = seet;
			window = wind;
			brand = br;
			radio = r;
			aircondition = air;
		}

		void create() {

			builder->setCar();
			builder->buildName(name);
			builder->buildSilnik(sil);
			builder->buildFelgi(felg);
			builder->buildWheels();
			builder->buildSeets(se);
			builder->buildDoors(door);
			builder->buildWindows(window);
			builder->buildBrand(brand);
			builder->buildRadio(radio);
			builder->buildAirCond(aircondition);
			
		}
};



int main() {

	int number = 0, q_seets = 0 , q_wind = 0, q_doors = 0;
	float vel = 0;
	string name, motor, rims, brand;
	bool rad = false, aircond = false;

	Car car3("Cadet", "Wolkswagen ", "aluminiowe", 4, 4, 4, 6, "Opel");

	cout << " Wprowadza dane do utworzenia nowego samochodu" << endl;
	cout << "Name: ";  cin >> name;
	/*cout << "Motor: ";  cin >> motor;
	cout << "Felgi: ";  cin >> rims;
	cout << "Ilosc miejsc: ";  cin >> q_seets;
	cout << "Ilosc drzwi: ";  cin >> q_doors;
	cout << "Ile okien: ";  cin >> q_wind;
	cout << "Marka: ";  cin >> brand;
	cout << "Czy ma byc klimatyzacja (true/false): ";  cin >> aircond;
	cout << " Czy wbudowane radio (true/false): "; cin >> rad;*/


	shared_ptr<Director> boss(new Director());
	shared_ptr<Car> car(new Car());
	shared_ptr<Builder> builder(new OffRoadCar());
	shared_ptr<Builder> builder2(new OffRoadCar());

	boss->setBuilder(builder);
	boss->fill(name);
	//boss->fill(name, motor, rims, q_doors, q_seets, q_wind, brand, rad, aircond);	
	boss->create();

	Car car1 = boss->getCar();

	boss->setBuilder(builder2);
	Car car2 (shared_ptr<Car> car1);
	//boss->create();

	//car2 = boss->getCar();

	car1.show();
	//car2.show();

	car3.show();

	cout << " WYbierz nume" << endl;
	cout << "1: jedz" << endl;
	cout << "2: stop" << endl;

	switch (number) {

	case 1:
		cin >> vel;
		car3.go(&vel);

	case 2: car3.stop();

	}

	return 0;
}