#include <iostream>
#include <time.h>
#include <string>
#include <memory> 
#include <cstdio>


#include "Transport.cpp"



using namespace std;


class Builder {

	protected:

	
		Car * car;

	public:

		void setCar() {

			
			car = new Car();
		}

		Car getCar() {
			
			return *car ;
		}
		 
		
		virtual void buildSilnik(string ) = 0;	
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

				
		void buildSilnik(string _silnik_) {

			car->setSilnik(_silnik_ );

		}


		void buildWheels() {

			car->setWheels(4);

		}

		void buildSeets(int _seets_) {

			car->setSeets(_seets_);
				
		}

		void buildDoors(int _door_){
		
			car->setDoors(_door_);
		
		}

		void buildWindows(int _window_) {

			car->setWindows(_window_);
		}

		void buildBrand(string  _brand_) {

			car->setBrand(_brand_);

		}

		void buildRadio(bool _rad_) {

			car->if_exist_Radio(_rad_ );
		}

		void buildAirCond(bool  _air_) {

			car->if_air_conditioning(_air_ );
		}
		
};

class Director {

	private:

		Builder * builder;	
		string sil;	
		int door;
		int se;
		int window;
		string brand;
		bool radio;
		bool aircondition;


	public:

		void setBuilder(Builder * b) {

			builder = b;
		}

		Car getCar() {

			return builder->getCar();
		}

		void fill(string s, int d , int seet, 
					int wind, string br, bool r, bool air ) {

			
			sil = s;			
			door = d;
			se = seet;
			window = wind;
			brand = br;
			radio = r;
			aircondition = air;
		}

		void create() {

			builder->setCar();			
			builder->buildSilnik(sil);			
			builder->buildWheels();
			builder->buildSeets(se);
			builder->buildDoors(door);
			builder->buildWindows(window);
			builder->buildBrand(brand);
			builder->buildRadio(radio);
			builder->buildAirCond(aircondition);
			
		}
};


void cteate_car_menu(string *, int *, int *, int*, string*, string*, bool*, bool*);

int main() {

	int q_seets{ 0 }, q_wind{ 0 }, q_doors{ 0 }, number{ 0 };
	float vel{ 0 };
	string name, motor, rims, brand;
	bool rad{ false }, aircond{ false };
	string num;

	Car car1("Wolkswagen ", 4, 4, 4, 6, "Opel", true, true);

	cteate_car_menu( &motor, &q_doors, &q_seets, &q_wind, &brand, &num, &aircond, &rad); //!< Menu wyboru 

	Director * boss = new Director();
	Car * car = new Car[4];
	
	Builder * builder = new OffRoadCar();
	Builder * builder2 = new OffRoadCar();


	boss->setBuilder(builder);
	boss->fill(motor, q_doors, q_seets, q_wind, brand, rad, aircond);

	boss->create();

	car[1] = boss->getCar();
	car[0] = car1;

	Car car2 (car1);
	car[2] = car2;

	cteate_car_menu(&motor, &q_doors, &q_seets, &q_wind, &brand, &num, &aircond, &rad); //!< Menu wyboru 	

	boss->setBuilder(builder2);
	boss->fill(motor, q_doors, q_seets, q_wind, brand, rad, aircond);
	boss->create();
	car[3] = boss->getCar();	

	
	int car_lenght = sizeof(car);		
	cout << endl;
	

	for (int i = 0; i < car_lenght; i++) {

		cout << "\n Samochod :" << i+1 << endl<<endl;
		car[i].show();

	}


	cout << " WYbierz numer :" << endl;
	cout << "1: go" << endl;
	cout << "2: stop" << endl;
	cout << "3: wyniki" << endl;
	cout << "4: exit" << endl;

	float * dist = new float[0];
	int i = 0;


	for (int j = 0; j < sizeof(dist); j++) {

		 dist[j]  = 0;

	}

	while (number != 4) {

		cout << " WYbierz numer :" << endl;
		cin >> number;



		switch (number) {


		case 1:

			cout << "wpisz predkosc dla samochodu w km/h: ";
			cin >> vel;
			dist[i] = (float)car[i].go(&vel);
			i++;

			break;


		case 2: 
			
			car[0].stop();
			number = {0};
			break;
			
		case 3:

			cout << " Wyniki: " << endl;

			for (int j = 0; j < sizeof(dist); j++) {

				cout<<j<<":" << dist[j] <<"km"<< endl;

			}

			break;

		case 4: 
			
			exit;

			break;

		}

	}

	system("pause");

	return 0;
}


void cteate_car_menu(string *m, int *q_d, int *q_s, int *q_w, string *br, string *n, bool *air, bool *_radio) {


	cout << " Choose the equipment for your car" << endl;
	cout << "Motor brand: ";  cin >> *m;
	cout << "Ilosc drzwi: ";  cin >> *q_d;
	cout << "Ilosc miejsc: ";  cin >> *q_s;
	cout << "Ile okien: ";  cin >> *q_w;
	cout << "Marka: ";  cin >> *br;
	cout << "Czy ma byc klimatyzacja (true/false): ";  cin >> *n;

	if (*n == "true") { *air = 1; }
	else { *air = 0; }

	cout << " Czy wbudowane radio (true/false): "; cin >> *n;
	if (*n == "true") { *_radio = 1; }
	else { _radio = 0; }

}