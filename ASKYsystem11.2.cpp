/**********************************************************
	ASKY RESOURCE MANAGEMENT SYSTEM		Version 11.2




	Last modified : 31/12/22 16:07

//*********************************************************
Creators :

		
	        Batangala D.R.M.M.K.
		Vithanage V.A.C.
                Bandara R.M.S.S.
                Dissanayake S.D.A.Y.D.

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
#include<ctime>

using namespace std;


bool mode = 0; //0-regular, 1 -educational
const string AdminPassword = "Admin1234";		//change admin password here
char YorN;
bool clearall = false;
bool logged = false;

char name[20];
char prems[20];
char dep[20];
int chair;
bool AC;
char line[1000];

int stime;
int etime;
int d[3];
char perps[50];

int numOfLECclasses = 0;
int numOfReserveclasses = 0;



class Hall {

public:
	string hallname;
	string premisess;
	string department;
	int numOfchairs;
	bool ACavailable;

public:

	Hall() {
		if (mode) { cout << "\t\t\t\t\t\t\t\tHall-constructor" << endl; }
	}
	~Hall() {
		if (mode) { cout << "\t\t\t\t\t\t\t\tHall-destructor" << endl; }
	}

	void addthroughtext(string name, string premisess, string dep, int chair, bool AC) {
		if (mode) { cout << "\t\t\t\t\t\t\t\tHall-addthroughtext()" << endl; }

		hallname = name;
		this->premisess = premisess;
		department = dep;
		numOfchairs = chair;
		ACavailable = AC;

	};

	void addDetails() {
		if (mode) { cout << "\t\t\t\t\t\t\t\tHall-addDetails()" << endl; }

		cout << "Enter hall name :";
		cin >> hallname;
		cout << "Enter hall premisess :";
		cin >> premisess;
		cout << "Enter department :";
		cin >> department;
		cout << "Enter available number of chairs :";
		cin >> numOfchairs;
		cout << "Is air conditioning available ? (0/1):";
		cin >> ACavailable;

	};


	void printDetails() {
		if (mode) { cout << "\t\t\t\t\t\t\t\tHall-printDetails()" << endl; }

		cout << "Hall Name : " << hallname;
		cout << "\tPremisess: " << premisess;
		cout << "\tDepartment: " << department;
		cout << "\tNumber of seats: " << numOfchairs;
		cout << "\t" << (ACavailable ? "AC" : "Non AC") << endl;
	}

	bool checkhallname(string h) {
		if (mode) { cout << "\t\t\t\t\t\t\t\tHall-checkhallname()" << endl; }

		return (this->hallname == h) ? true : false;
	}


protected:
	// Protected Declarations
};



class LectureHall :public Hall {
private:
	int projectors;

public:
	LectureHall() {

		if (mode) { cout << "\t\t\t\t\t\t\t\tLectureHall-constructor" << endl; }
		//Hall:printDetails();
	}
	~LectureHall() {
		if (mode) { cout << "\t\t\t\t\t\t\t\tLectureHall-destructor" << endl; }
	}

	void addnewLechall(string name, string prems, string dep, int chair, bool AC) {
		if (mode) { cout << "\t\t\t\t\t\t\t\tLectureHall-addnewLechall()" << endl; }

		ofstream Hout;
		Hout.open("LecHall_Details.txt", ofstream::app);

		//R << "new"<<endl;
		Hout << name << " " << prems << " " << dep << " " << chair << " " << AC << "\n";

		Hout.close();
	}

	void clearAllHalldata() {
		if (mode) { cout << "\t\t\t\t\t\t\t\tHall-clearAllHalldata()" << endl; }

		ofstream Hout;

		Hout.open("LecHall_Details.txt", ofstream::out);
		Hout.clear();

		Hout.close();
	}

	void updatetotxt() {
		if (mode) { cout << "\t\t\t\t\t\t\t\tHall-updatetotxt()" << endl; }

		ofstream Hout;
		Hout.open("LecHall_Details.txt", ofstream::app);
		Hout << this->hallname << " " << this->premisess << " " << this->department << " " << this->numOfchairs << " " << this->ACavailable << "\n";
		Hout.close();
	}



protected:
	// Protected Declarations
};

class Laboratory :public Hall {
private:
	int numOflabbenchs;

public:
	Laboratory() {
		if (mode) { cout << "\t\t\t\t\t\t\t\tLaboratory-constructor" << endl; }
	}
	~Laboratory() {
		if (mode) { cout << "\t\t\t\t\t\t\t\tLaboratory-distructor" << endl; }
	}
protected:
	// Protected Declarations
};

class user {
private:
	string name;
	string department;
	string IDNo;


public:
	user() {
		if (mode) { cout << "\t\t\t\t\t\t\t\tuser-constructor" << endl; }
	}
	~user() {
		if (mode) { cout << "\t\t\t\t\t\t\t\tuser-destructor" << endl; }
	}

	void recorde() {
		if (mode) { cout << "\t\t\t\t\t\t\t\tuser-recorde()" << endl; }

		ofstream out("Logging_Details.txt", ios::app);

		cout << "...Please Loggin to te ASKY ..." << endl;
		cout << "Enter Name : ";
		cin >> name;
		cout << "Enter ID No : ";
		cin >> IDNo;
		cout << "Enter your department or designation : ";
		cin >> department;

		out << "\n| User Name : " << name << endl;
		out << "| Registration No : " << IDNo << endl;
		out << "| Department : " << department << endl;

		time_t now = time(0);

		//cout<<"Login time : "<<ctime(&now)<<endl;

		//out<<"| Login time : "<<ctime(&now)<<endl;

		out << "===============================" << endl;
		out.close();
		//cout << "\nYour details have been recorded. Thank you" << endl;
	}


};

class admin :public user {

protected:
	string pswrd;

public:
	admin() {
		if (mode) { cout << "\t\t\t\t\t\t\t\tadmin-constructor" << endl; }
	}

	~admin() {
		if (mode) { cout << "\t\t\t\t\t\t\t\tadmin-destructor" << endl; }
	}

	void takepassword() {
		if (mode) { cout << "\t\t\t\t\t\t\t\tadmin-takepassword()" << endl; }

		cout << "\nEnter Password : ";
		cin >> pswrd;
	}

	bool checkpassword() {
		if (mode) { cout << "\t\t\t\t\t\t\t\tadmin-checkpassword()" << endl; }

		if (pswrd == AdminPassword) {
			return true;
		}
		else {
			cout << "Password Incorrect !" << endl;
			return false;
		}
	}

};


class Reservation {

private:
	string hallcode;
	string perpouse;
	int starttime;
	int endtime;
	int date[3];
	//string userID;
	//Day D1;

public:

	Reservation() {
		if (mode) { cout << "\t\t\t\t\t\t\t\tReservation-constructor" << endl; }
	}
	~Reservation() {
		if (mode) { cout << "\t\t\t\t\t\t\t\tReservation-destructor" << endl; }
	}

	void addthroughtext(string hallcode,string perps, int starttime, int endtime, int day, int month, int year) {
		if (mode) { cout << "\t\t\t\t\t\t\t\tReservation-addthroughtext()" << endl; }

		this->hallcode = hallcode;
		this->perpouse = perps;
		this->starttime = starttime;
		this->endtime = endtime;
		this->date[0] = day; this->date[1] = month; this->date[2] = year;


	};

	void addReservation(string hallcode,string perpouse, int starttime, int endtime, int day, int month, int year) {
		if (mode) { cout << "\t\t\t\t\t\t\t\tReservation-addReservation()" << endl; }

		ofstream Rout;
		Rout.open("Reserve_Details.txt", ofstream::app);


		//R << "new"<<endl;
		Rout << hallcode <<" "<<perpouse << " " << starttime << " " << endtime << " " << day << " " << month << " " << year<<"\n";

		Rout.close();

	};

	void updatetotxt() {
		if (mode) { cout << "\t\t\t\t\t\t\t\tReservation-updatetotxt()" << endl; }

		ofstream Rout;
		Rout.open("Reserve_Details.txt", ofstream::app);
		Rout << hallcode << " " <<perpouse<<" " << starttime << " " << endtime << " " << date[0] << " " << date[1] << " " << date[2] << "\n";
		Rout.close();
	}

	bool checkhallbooked(string code, int st, int et, int dy, int mon, int y) {
		if (mode) { cout << "\t\t\t\t\t\t\t\tReservation-checkhallbooked()" << endl; }

		if (hallcode == code && date[0] == dy && date[1] == mon) {
			return (endtime<st or starttime>et) ? false : true;
		}
		else {
			return 0;
		}
	}

	void printDetails() {
		if (mode) { cout << "\t\t\t\t\t\t\t\tReservation-printDetails()" << endl; }

		cout << "Perpouse : " << perpouse;
		cout << "\nHall Name : " << hallcode;
		cout << "\tstart time: " << starttime;
		cout << "\tend time : " << endtime;
		cout << "\tdate (D/M/Y): " << date[0] << "/" << date[1] << "/" << date[2] << endl;

	}

	void clearAllreservations() {
		if (mode) { cout << "\t\t\t\t\t\t\t\tReservation-clearAllreservations()" << endl; }

		ofstream Rout;

		Rout.open("Reserve_Details.txt", ofstream::out);
		Rout << "";
		Rout.clear();

		Rout.close();
	}

	bool checkdate(int d, int m, int y) {
		if (mode) { cout << "\t\t\t\t\t\t\t\tReservation-checkdate()" << endl; }

		return (this->date[0] == d && this->date[1] == m) ? true : false;
	}


protected:
	// Protected Declarations
};


void setcolor(int p) {
	HANDLE console_color;
	// Color of the console
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	// P is color code according to your need.
	SetConsoleTextAttribute(console_color, p);

}

void clearallReservations() {
	Reservation Rclear;
	Rclear.clearAllreservations();
}



void printtasks() {
	cout << " Enter your task number : " << endl;
	cout << " 1 - Add new reservation " << endl;
	cout << " 2 - View all hall deatials " << endl;
	cout << " 3 - View all reservation datails " << endl;
	cout << " 4 - Edit reservation(s)" << endl;
	cout << " 5 - Add new Hall detail" << endl;
	cout << " 6 - Edit Hall details" << endl;
	cout << " 0 - Exit programme" << endl;
}

void welcome()
{
	cout << "\n";
	setcolor(30);
	cout << "\t\tÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\n";

	cout << "\t\t            ÛÛ ÛÛÛÛÛÛ ÛÛ  ÛÛ ÛÛ   ÛÛ  ÛßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßÛ     \n";
	cout << "\t\t           ÛÛÛ Û      ÛÛ ÛÛ   ÛÛ ÛÛ   Û   ASKY   Hall Allocation System            Û     \n";
	cout << "\t\t          ÛÛ Û ÛÛÛÛÛÛ ÛÛÛÛ     ÛÛ     Û          Faculty of Engineering            Û     \n";
	cout << "\t\t         ÛÛ  Û      Û ÛÛ ÛÛ   ÛÛ      Û          University of Sri Jayawardenapura Û     \n";
	cout << "\t\t        ÛÛ  ÛÛ ÛÛÛÛÛÛ ÛÛ  ÛÛ ÛÛ       ÛÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÜÛ     \n";

	cout << "\t\tÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ\n";
	setcolor(7);
	cout << "\t\t                                                                          " << (logged ? "Logged  \x3" : "\x1 GUEST");
	cout << "\n\n";

	//	cout << "\t\t\tÛ                   ASKY Hall Allocation System - EFAC JAPURA                     Û\n";
	//	cout << "\t\t\tÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛÛ\n";
}


void lognow() {

	admin Newadmin;
	Newadmin.recorde();
	Newadmin.takepassword();

	while (!Newadmin.checkpassword()) {

		cout << "Unable to logging !" << endl;
		Newadmin.takepassword();
	}

	logged = true;
}




int main() {

	cout << "Choose Mode	: \tEducation Mode - 1\tRegular Mode - 0" << endl;
	cin >> mode;

	(mode == 1) ? (cout << "You are in education mode" << endl) : (cout << "You are in Regular Mode" << endl);


	while (1) {

		//** load hall data*************************************
	loaddata:

		ifstream lechall;
		lechall.open("LecHall_Details.txt");
		if (!lechall) {
			//cout<<"counld not open file creating new file"<<endl;
			ofstream newlecfile("LecHall_Details.txt", ofstream::out);
			newlecfile.close();
			goto loaddata;
		}

		numOfLECclasses = 0;

		while (!lechall.eof()) {
			lechall.getline(line, 1000, '\n');
			numOfLECclasses++;
			//cout<<line<<endl;
		}
		//cout<<"numOfLECclasses  "<<numOfLECclasses<<endl;
		lechall.close();

		lechall.open("LecHall_Details.txt");
		LectureHall** h1;
		h1 = (LectureHall**)malloc(numOfLECclasses * sizeof(LectureHall*));
		for (int i = 0; i < numOfLECclasses; i++) {
			h1[i] = new LectureHall;
		}


		int i = 0;

		while (!lechall.eof()) {


			lechall.getline(name, 20, ' ');
			lechall.getline(prems, 20, ' ');
			lechall.getline(dep, 20, ' ');
			//lechall.getline(chair,' ');
			//lechall.getline(AC,' ');

			lechall >> chair;
			lechall.ignore();
			lechall >> AC;
			lechall.ignore();

			//cout<<name<<" "<<prems<<" "<<dep<<" "<<chair<<" "<<AC<<" "<<endl;

			h1[i]->addthroughtext(name, prems, dep, chair, AC);
			i++;

		}

		lechall.close();

		//*******load reserve data*************************

		ifstream R;
		R.open("Reserve_Details.txt");

		if (!R) {
			//cout<<"counld not open file creating new file"<<endl;
			ofstream newRfile("Reserve_Details.txt", ofstream::out);
			newRfile.close();
			goto loaddata;
		}

		numOfReserveclasses = 0;

		while (!R.eof()) {
			R.getline(line, 1000, '\n');
			numOfReserveclasses++;
			//cout<<line<<endl;
		}
		//cout<<"numOfReserveclasses  "<<numOfReserveclasses<<endl;
		R.close();

		R.open("Reserve_Details.txt");

		Reservation** R1;
		R1 = (Reservation**)malloc(numOfReserveclasses * sizeof(Reservation*));
		for (int i = 0; i < numOfReserveclasses; i++) {
			R1[i] = new Reservation;
		}

		i = 0;

		while (!R.eof()) {


			R.getline(name, 20, ' ');
			R.getline(perps, 50, ' ');
			R >> stime; R.ignore();
			R >> etime; R.ignore();
			R >> d[0]; R.ignore();
			R >> d[1]; R.ignore();
			R >> d[2]; R.ignore();

			//cout<<name<<" "<<prems<<" "<<dep<<" "<<chair<<" "<<AC<<" "<<endl;

			R1[i]->addthroughtext(name,perps, stime, etime, d[0], d[1], d[3]);
			i++;

		}

		R.close();

		//****end of detail obtaining**************************************************************

		while (1) {
		toploop:

			if (!mode) { system("CLS"); }

			welcome();

			while (!logged) {
				lognow();
				if (logged) {
					if (!mode) { system("CLS"); }
					welcome();
				}
			}






			int task = 8;

			printtasks();
			cin >> task;

			switch (task) {
			case 1:
				goto addnewR;
				break;
			case 2:
				for (int i = 0; i < numOfLECclasses; i++) {
					cout << "hall " << i << " " << endl;
					h1[i]->printDetails();
				}
				cout << "\n\n";
				system("pause");
				break;
			case 3:
				for (int i = 0; i < numOfReserveclasses; i++) {
					cout << "Reservation " << i << " " << endl;
					R1[i]->printDetails();
				}
				cout << "\n\n";
				system("pause");
				break;
			case 4: {

				cout << "Cancel specific record - 1\nDelete all records - 0" << endl;
				cin >> YorN;
				if (YorN == '1') {
					for (int i = 0; i < numOfReserveclasses; i++) {
						cout << "\nReservation No :" << i << " " << endl;
						R1[i]->printDetails();
					}
					cout << "Enter recored number : ";
					int Rnum = 1000;
					cin >> Rnum;
					try {
						if (Rnum < 0 or Rnum >= numOfReserveclasses) { throw Rnum; }

						R1[Rnum]->~Reservation();

						clearallReservations();
						for (int i = 0; i < numOfReserveclasses; i++) {
							if (i != Rnum) {
								R1[i]->updatetotxt();
							}
							
						}
					}
					catch (int exception) {
						cout << "Invalid record number " << endl;
					}



				}
				else if (YorN == '0') {
					clearallReservations();
					goto loaddata;
				}
			}

				  break;
			case 5: {
				cout << "\nEnter Hall name   : ";	cin >> name;
				cout << "\nEnter Premisess : ";	cin >> prems;
				cout << "\nDepartment      : ";	cin >> dep;
				cout << "\nNumber fo seats : "; 	cin >> chair;
				cout << "\nAC availability (0/1) : ";	cin >> AC;

				LectureHall Hnew;
				Hnew.addnewLechall(name, prems, dep, chair, AC);
				goto loaddata;
				break;
			}
			case 6: {

				cout << "Enter Hall name : ";
				string H;
				int found = 1000;
				cin >> H;

				for (int i = 0; i < numOfLECclasses; i++) {
					if (h1[i]->checkhallname(H)) {
						found = i;
						break;
					}
				}

				try {
					if (found < 0 or found >= numOfLECclasses) { throw found; }

					cout << "Current details of the Hall : " << endl;
					h1[found]->printDetails();
					cout << "Enter new details : " << endl;
					h1[found]->addDetails();

					LectureHall hclear;
					hclear.clearAllHalldata();

					for (int i = 0; i < numOfLECclasses; i++) {
						h1[i]->updatetotxt();
					}
				}
				catch (int exception) {
					cout << "Can not find hall !" << endl;
					system("pause");
				}
				break;
			}
			case 0: {
				cout << "Exiting programme...!" << endl;
				for (int i = 0; i < numOfLECclasses; i++) {
					h1[i]->~LectureHall();
				}
				free(h1);

				for (int i = 0; i < numOfReserveclasses; i++) {
					R1[i]->~Reservation();
				}
				free(R1);

				goto exit;
				break;
			}
			default:
				cout << "Enter a task ..." << endl;
				break;

			}
		}



		//**** add new reservation **************************	
	addnewR:

		cout << "Enter Perpouse (course code/event) : ";		cin >> perps;
		cout << "\nEnter Hall name : ";		cin >> name;
		cout << "\nEnter date (Day): ";	cin >> d[0];
		cout << "  (Month): ";			cin >> d[1];
		cout << "  (Year) : ";			cin >> d[2];
		cout << "\nEnter start time : ";	cin >> stime;
		cout << "\nEnter end time : ";	cin >> etime;

		bool booked = false;

		for (int i = 0; i < numOfReserveclasses; i++) {

			if (R1[i]->checkhallbooked(name, stime, etime, d[0], d[1], d[2])) {
				booked = true;
			}

		}


		if (!booked) {
			cout << "Reservation can be added.\n Do you want to proceed ? (Y/N)";

			cin >> YorN;
			if (YorN == 'Y' or YorN == 'y') {

				cout << "\nRecording reservation ... " << endl;
				Reservation Rmy;
				Rmy.addReservation(name,perps, stime, etime, d[0], d[1], d[2]);
			}

		}
		else {
			cout << "Sorry, reservation can not be done.\nTry another hall or another time/date." << endl;
			system("pause");
		}


		//************************************************************************
		for (int i = 0; i < numOfLECclasses; i++) {
			h1[i]->~LectureHall();
		}
		free(h1);

		for (int i = 0; i < numOfReserveclasses; i++) {
			R1[i]->~Reservation();
		}
		free(R1);

	}

exit:

	return 0;

}
