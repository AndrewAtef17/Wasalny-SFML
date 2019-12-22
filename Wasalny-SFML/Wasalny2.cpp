//CPP for driver and customer
#include "Wasalny.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

int choosen = 0, bb = 0, ssss = -5, ssss2, ssss3, number_of_nodes = 15;
string currpost, dist;
bool Once = false;
bool isFound = false;

BFS b(number_of_nodes);


car::car() {

}

car::~car() {

}

Driver::Driver() {
	rate = 5.0;
	distinationNumber["Al-Asher"] = 0;
	distinationNumber["Al-Ahly"] = 1;
	distinationNumber["Al-Tamen"] = 2;
	distinationNumber["Akher-Fakhry"] = 3;
	distinationNumber["Mid-Fakhry"] = 4;
	distinationNumber["Awel-Fakhry"] = 5;
	distinationNumber["Akher-Makram"] = 6;
	distinationNumber["Mid-Makram"] = 7;
	distinationNumber["Awel-Makram"] = 8;
	distinationNumber["Akher-Abbas"] = 9;
	distinationNumber["Mid-Abbas"] = 10;
	distinationNumber["Awel-Abbas"] = 11;
	distinationNumber["Al-Sabe3"] = 12;
	distinationNumber["Al-Taiaran"] = 13;
	distinationNumber["Al-Sades"] = 14;
}
void Driver::SaveToVector() {



	Driver s;
	string ignore, getContent;
	ifstream driverFile("drivers.txt");
	bool ignorePass = false;
	int i = 1;
	if (driverFile.is_open()) {
		while (getline(driverFile, getContent)) {
			if (i % 9 == 0) {
				ignorePass = false;
				i = 1;
				V.push_back(s);
			}

			if (ignorePass == false) {
				getline(driverFile, ignore);
				ignorePass = true;
			}
			if (i == 1)
				s.driver_name = getContent;
			else if (i == 2)
				s.phone = getContent;
			else if (i == 3)
				s.curr_Destination = getContent;
			else if (i == 4)
				s.pref_Destination = getContent;
			else if (i == 5)
				s.c.name = getContent;
			else if (i == 6)
				s.c.model = getContent;
			else if (i == 7)
				s.c.number = getContent;
			else if (i == 8)
				s.c.color = getContent;
			i++;

		}
		V.push_back(s);

	}
}

void Driver::registerFn() {
	ofstream driverFile("drivers.txt", ofstream::app);

	cout << "--------- Drivers' Registration Section ---------\n";
	cout << "Name: "; cin >> driver_name;
	driverFile << driver_name << endl;
	cout << "Enter a strong password: "; cin >> pass;
	driverFile << pass << endl;
	cout << "Phone Number: "; cin >> phone;
	driverFile << phone << endl;
	cout << "Enter your current destination: "; cin >> curr_Destination;
	currnum = d.distinationNumber[curr_Destination];
	driverFile << curr_Destination << endl;
	cout << "Please provide your preferred destination: "; cin >> pref_Destination;
	prefnum = d.distinationNumber[pref_Destination];
	driverFile << pref_Destination << endl;
	cout << "____________ Car's data _____________\n";
	cout << "Car's name: "; cin >> c.name;
	driverFile << c.name << endl;
	cout << "Model: "; cin >> c.model;
	driverFile << c.model << endl;
	cout << "Plate numbers: "; cin >> c.number;
	driverFile << c.number << endl;
	cout << "Color: "; cin >> c.color;
	driverFile << c.color << endl;

}

void Driver::login(customer& C) {
	string username, password, ignore;
	bool driverFound = false;
	int choice;
	vector<int> v;
	do {
		cout << "--------- Drivers' Login Section ---------\n";
		cout << "Name: "; cin >> username;
		cout << "Password: "; cin >> password;
		ifstream driverFile("drivers.txt");

		while (getline(driverFile, driver_name)) {
			getline(driverFile, pass);
			if (driver_name == username && pass == password) {
				driverFound = true;
				cout << "Successfully logged in!\n";
				break;
			}

			getline(driverFile, ignore);
			getline(driverFile, ignore);
			getline(driverFile, ignore);
			getline(driverFile, ignore);
			getline(driverFile, ignore);
			getline(driverFile, ignore);
			getline(driverFile, ignore);

		}
		if (driverFound == false) {
			cout << "Email or password is incorrect.\n";
			cout << "\n[1] for re-login\n"; cin >> choice;
		}
	} while (driverFound == false);
	Dijkstra ds;
	if (bb == 1 && V[choosen].driver_name == driver_name) {
		char y;
		cout << "You Have 1 customer press (y) to show the way and info: ";
		cin >> y;
		if (y == 'y') {
			cout << "Customer's information: \n";
			cout << "Customer's Name is: " << C.username << endl << "Phone number: " << C.getphone << endl;
			/*cout << "Do you want to use BFS or Dijkstra ?" << endl;
			cout << "[1] BFS" << endl;
			cout << "[2] Dijkstra" << endl;
			int ans;
			cin >> ans;
			/*if (ans == 1) {

				cout << "Path to go to the customer is: \n";
				b.bfs(b, ssss, ssss2, number_of_nodes);
				cout << "You have arrived, going to the destination..." << endl;
				b.bfs(b, ssss2, ssss3, number_of_nodes);
			}
			else if (ans == 2) {
				cout << "Path to go to the customer is: ";
				ssss = distinationNumber[D.V[choosen].curr_Destination];
				ds.shortestpathFrom(ssss);
				ssss2 = distinationNumber[currpost];
				ds.printpath(ssss, ssss2,v);
				cout << ds.Distance[ssss2] << endl;
				cout << "You have arrived, going to the destination..." << endl;
				ds.shortestpathFrom(ssss2);
				ssss3 = distinationNumber[dist];
				ds.printpath(ssss2, ssss3,v);
				cout << ds.Distance[ssss3] << endl;
			}*/
		}
	}
	else
		cout << "No Current Customers.\n";
	system("pause");
	//} while (choice == 2 && driverFound == false);          //badeel el recursion bta3 [ login(); ].
}

void Driver::display() {
	string ignore, getContent;
	ifstream driverFile("drivers.txt");
	bool ignorePass = false;
	int i = 1, j = 1;
	if (driverFile.is_open()) {
		cout << "Driver " << i << " : " << endl;
		while (getline(driverFile, getContent)) {
			if (i % 9 == 0) {
				ignorePass = false;
				i = 1;
				j++;
				cout << "Driver " << j << " : " << endl;
			}
			cout << getContent << endl;
			if (ignorePass == false) {
				getline(driverFile, ignore);
				ignorePass = true;
			}
			i++;
		}

	}
	system("pause");
}

void customer::orderTrip(Driver& D)
{
	if (Once == false) {
		D.SaveToVector();
		Once = true;
	}
	cout << "Enter Current position and distination\n";
	cin >> currpost >> dist;
	Dijkstra ds;
	for (int i = 0; i < D.V.size(); i++) {
		if (D.V[i].pref_Destination == dist) {
			cout << endl;
			cout << "Driver's Information : " << endl;
			cout << "Driver's Name : " << D.V[i].driver_name << endl;
			cout << "Driver's Phone : " << D.V[i].phone << endl;
			cout << "Driver's Car information:\nCar name: " << D.V[i].c.name << "\nModel: " << D.V[i].c.model << "\nColor: " << D.V[i].c.color << "\nPlate Number: " << D.V[i].c.number << endl;
			choosen = i;
			isFound = true;
		}
	}
	system("pause");
}

float Driver::updateRate(float input) {
	//average between the input and the existing
	float avg = (rate + input) / 2;
	return avg;
}

Driver::~Driver() {

}

customer::customer()
{
	username;
	phonenum;

}

void customer::registerf() {
	cout << "--------- Customers' Registration Section ---------\n";
	ofstream customersFile("customers.txt", ofstream::app);
	cout << "Name: ";
	cin >> username;
	customersFile << username << endl;
	cout << endl;
	cout << "Select a strong password: ";
	cin >> password;
	customersFile << password << endl;
	cout << endl;
	cout << "E-mail: ";
	cin >> email;
	customersFile << email << endl;
	cout << endl;
	cout << "Phone Number: ";
	cin >> phonenum;
	customersFile << phonenum << endl;
	cout << endl;

	customersFile.close();



}

void customer::login() {
	string username1, password1;
	int choice;
	string x;
	bool userfound = 0; //false
						//do {
	bb = 1;
	do {
		cout << "--------- Customers' Login Section ---------\n";
		cout << "Username: ";
		cin >> username1;
		cout << "Password: ";
		cin >> password1;
		ifstream customersFile("customers.txt");
		while (getline(customersFile, username))
		{
			getline(customersFile, password);
			if (username == username1 && password == password1) {
				userfound = 1;
				cout << "Succesfully logged in!" << endl;
				getline(customersFile, x);
				getline(customersFile, phonenum);
				getphone = phonenum;
				break;
			}
		}
		if (userfound == 0) {
			cout << "The email or password you have entered is not correct " << endl;
			cout << "\n[1] For re-login\n"; cin >> choice;
		}
	} while (userfound == 0);
	system("pause");
	//customersFile.close();
	//} while (choice == 2 && userfound == 0);
}


void customer::display() {
	string x;
	string getcontent;
	bool ignorepassword = false;
	int i = 1, j = 1;
	ifstream customersFile("customers.txt");
	if (customersFile.is_open())
	{
		cout << "Customer " << i << " : " << endl;
		while (getline(customersFile, getcontent))
		{
			if (i % 4 == 0) {
				ignorepassword = false;
				i = 1;
				j++;
				cout << "Customer " << j << " : " << endl;
			}
			cout << getcontent << endl;
			if (ignorepassword == false) {
				getline(customersFile, x);
				ignorepassword = true;

			}
			i++;
		}
	}
	system("pause");
}

