#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Customer.h"
#include "CustomerManager.h"


bool cinfail;
int confirmation;
string Customer_ID;
void MainMenu();
Customer* customer = new Customer();
CustomerManager customermanager;
int status;
int a;
int tempid;
int tempcarid;

void login();
void registerme();
void exit();
void loginuser(int tempid);
void carmenu();
void bookingCar(int tempid);
void updateinfo(int tempid);
void receiptmenu(int tempid);




void MainMenu() {
	int choice = 0;

	cout << "***************************************************************************************************" << endl;
	cout << "*                                                                                                 *" << endl;
	cout << "*          Welcome To Car Dealership System                                                       *" << endl;
	cout << "*          Hello, Would you like to log in or register?                                           *" << endl;
	cout << "*           [1] Login									          *" << endl;
	cout << "*           [2] Register                                                                          *" << endl;
	cout << "*           [3] Exit                                                                              *" << endl;
	cout << "*                                                                                                 *" << endl;
	cout << "***************************************************************************************************" << endl;

	cin >> choice;
	
	do {
		cinfail = cin.fail();
		cin.clear();
		cin.ignore(10000, '\n');
	} 
	while (cinfail == true); {
		switch (choice) {
		case 1:
			login();
			break;

		case 2:
			registerme();
			break;

		case 3:
			exit();
		}
	}
}

void login(){

	system("pause");
	system("cls");

	cout << "\n\n";
	cout << "******************************************************" << endl;
	cout << "******************** LOG IN MENU *********************" << endl;
	cout << "******************************************************" << endl;

	cout << "Enter your Customer ID" << endl;
	//cin.ignore(1, '\n');
	cin >> tempid;
	customer->Customer_ID = tempid;

	if (customermanager.login(customer)) {
		cout << "You are being logged in!" << endl;

		loginuser(tempid);
	}
	else {
		login();
	}
	


}

void registerme() {

	system("pause");
	system("cls");

	int choice = 0;
	cout << "Please enter the your details" << endl
		<< "Customer ID:\t";
	cin >> customer->Customer_ID;

	cout << "First Name:\t";
	cin.ignore(1, '\n');
	getline(cin, customer->First_Name);

	cout << "Last Name:\t";
	getline(cin, customer->Last_Name);

	cout << "Phone Number:\t";
	cin >> customer->Phone_Number;

	CustomerManager* customermanager{};
	status = customermanager->insertCustomer(customer);

	if (status != 0)
		cout << "Successfully added a new program." << endl;
	else
		cout << "Unable to add a new program." << endl;

	cout << "\n\nYou want to continue using the program?";
	cout << "\n Yes [1] No[0]"<< endl;
	cin >> choice;

	system("pause");
	system("cls");

	do {
		cinfail = cin.fail();
		cin.clear();
		cin.ignore(10000, '\n');
	} while (cinfail == true); {
		switch (choice) {
		case 1:
			MainMenu();
			break;

		case 2:
			exit();
			break;
		}
	}


}

void exit() {

	system("pause");
	system("cls");

	cout << "******************************************************" << endl;
	cout << "           Thank you for using the system.\n";
	cout << "******************************************************" << endl;

	system("pause");
	system("cls");
}


int main()
{
	MainMenu();

	/*
	cout << "Please enter the customer you want to search:" << endl
		<< "Customer ID:\t";
	getline(cin, Customer_ID);

	Customer* customer = CustomerManager.selectCustomer(Customer_ID);

	cout << "The name of the searched program is " << customer-> First_Name << " " << Last_Name << "." << endl;
	*/
	return 0;
}

void loginuser(int tempid) {
	system("pause");
	system("cls");

	Customer* info = new Customer();
	info = customermanager.showInformation(tempid);
	cout << "******************************************************" << endl;
	cout << "Name: ";
	cout << info->First_Name;
	cout << " ";
	cout << info->Last_Name << endl;
	cout << "Phone Number: ";
	cout << info->Phone_Number << endl;
	cout << "******************************************************" << endl;
	carmenu();
}

void carmenu(){


	int choice;

	cout << endl;
	cout << "******************************************************" << endl;
	cout << "|                                                    |" << endl;
	cout << "|           1. Update information                    |" << endl;
	cout << "|           2. Booking Car                           |" << endl;
	cout << "|           3. Receipt                               |" << endl;
	cout << "|           4. Log Out                               |" << endl;
	cout << "|                                                    |" << endl;
	cout << "******************************************************" << endl;

	cin >> choice;

	if (choice == 1) {
		updateinfo(tempid);
	}

	else if (choice == 2) {
		 bookingCar(tempid);
	}

	else if (choice == 3) {
		receiptmenu(tempid);
	}

	else {
		system("pause");
		system("cls");
		MainMenu();
	}
}

void updateinfo(int tempid) {
	system("pause");
	system("cls");

	int choice;
	
	Customer* latestinfo = new Customer();
	latestinfo->Customer_ID = tempid;

	cout << "Choose Option\n1. First Name \n2. Last Name \n3.Phone Number\n";
	cin >> choice;
	if (choice == 1) {
		cout << "\nEnter new First Name: ";
		cin >> latestinfo->First_Name;
		customermanager.updateCustomerFirstName(latestinfo);
		loginuser(tempid);
	}
	else if (choice == 2) {
		cout << "\nEnter new Last Name: ";
		cin >> latestinfo->Last_Name;
		customermanager.updateCustomerLastName(latestinfo);
		loginuser(tempid);
	}

	else if (choice == 3) {
		cout << "\nEnter new Phone Number: ";
		cin >> latestinfo->Phone_Number;
		customermanager.updateCustomerPhoneNumber(latestinfo);
		loginuser(tempid);
	}

	else {
		cout << "Error";
		updateinfo(tempid);
	}
}

void bookingCar(int tempid) {

	system("pause");
	system("cls");

	int choice, choice2, choice3;
	int companylocation = 0;
	string bookingstatus;

	customermanager.showCarInformation();


	Booking* booking = new Booking();
	booking->Customer_ID = tempid;

	Salesreceipt* salesreceipt = new Salesreceipt();
	salesreceipt->Customer_ID = tempid;

	cout << "\n\n Choose Your Car: ";
	cin >> choice;

	time_t rawtime;
	srand(time(&rawtime));

	if (choice == 1) {

		tempcarid = 426410;
		booking->Vehicle_ID = tempcarid;

		cout << "\nYou want to pay right now ? (1 for Pay, 2 for Pending): ";
		cin >> choice2;

		if (choice2 == 1) {
			bookingstatus = "PASS";

		}

		else if (choice2 == 2) {
			bookingstatus = "PENDING";
		}

		booking->Booking_Status = bookingstatus;
		booking->Booking_ID = rand();
		customermanager.bookingCar(booking);

	}

	else if (choice == 2) {

		tempcarid = 599902;
		booking->Vehicle_ID = tempcarid;

		cout << "\nYou want to pay right now ? (1 for Pay, 2 for Pending): ";
		cin >> choice2;

		if (choice2 == 1) {
			bookingstatus = "PASS";
		}

		else if (choice2 == 2) {
			bookingstatus = "PENDING";
		}

		

		booking->Booking_Status = bookingstatus;
		booking->Booking_ID = rand();

		customermanager.bookingCar(booking);

	}

	else if (choice == 3) {

		tempcarid = 778854;
		booking->Vehicle_ID = tempcarid;

		cout << "\nYou want to pay right now ? (1 for Pay, 2 for Pending): ";
		cin >> choice2;

		if (choice2 == 1) {
			bookingstatus = "PASS";
		}

		else if (choice2 == 2) {
			bookingstatus = "PENDING";
		}

		booking->Booking_Status = bookingstatus;
		booking->Booking_ID = rand();
		customermanager.bookingCar(booking);

	}

	else if (choice == 4) {

		tempcarid = 783054;
		booking->Vehicle_ID = tempcarid;

		cout << "\nYou want to pay right now ? (1 for Pay, 2 for Pending): ";
		cin >> choice2;

		if (choice2 == 1) {
			bookingstatus = "PASS";
		}

		else if (choice2 == 2) {
			bookingstatus = "PENDING";
		}

		booking->Booking_Status = bookingstatus;
		booking->Booking_ID = rand();
		customermanager.bookingCar(booking);

	}

	else if (choice == 5) {

		tempcarid = 811473;
		booking->Vehicle_ID = tempcarid;

		cout << "\nYou want to pay right now ? (1 for Pay, 2 for Pending): ";
		cin >> choice2;

		if (choice2 == 1) {
			bookingstatus = "PASS";
		}

		else if (choice2 == 2) {
			bookingstatus = "PENDING";
		}

		booking->Booking_Status = bookingstatus;
		booking->Booking_ID = rand();
		customermanager.bookingCar(booking);

	}

	else if (choice == 6) {

		tempcarid = 929729;
		booking->Vehicle_ID = tempcarid;

		cout << "\nYou want to pay right now ? (1 for Pay, 2 for Pending): ";
		cin >> choice2;

		if (choice2 == 1) {
			bookingstatus = "PASS";
		}

		else if (choice2 == 2) {
			bookingstatus = "PENDING";
		}

		booking->Booking_Status = bookingstatus;
		booking->Booking_ID = rand();
		customermanager.bookingCar(booking);
				
	}

	cout << "\nWhich company do you want to select ? (1 for Kulim, Kedah, 2 for Kuala Lumpur, 3 for Melaka): ";
	cin >> choice3;

	if (choice3 == 1) {
		companylocation = 141330;
	}

	else if (choice3 == 2) {
		companylocation = 398876;
	}

	else if (choice3 == 3) {
		companylocation = 643918;
	}

	salesreceipt->Receipt_ID = rand();
	salesreceipt->Vehicle_ID = tempcarid;
	salesreceipt->Booking_ID = booking->Booking_ID;
	salesreceipt->Company_ID = companylocation;

	customermanager.insertReceipt(salesreceipt);

	system("pause");
	system("cls");
	carmenu();
}

void receiptmenu(int tempid) {

	system("pause");
	system("cls");

	Salesreceipt* salesreceipt = new Salesreceipt();
	customermanager.showReceipt(tempid);

	system("pause");
	system("cls");

	carmenu();
}