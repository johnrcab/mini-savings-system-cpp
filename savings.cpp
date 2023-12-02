#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int one, five, ten, twenty, fifty, hundred, two_hundred, five_hundred, thousand, result, totalW, balInput, resInput, zero = 0;
string totalR;
string unable = "Error!";

void clearScreen()
{
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

void moneyInProcess()
{
	int fiveW = five * 5;
	int tenW = ten * 10;
	int twenW = twenty * 20;
	int fifW = fifty * 50;
	int hunW = hundred * 100;
	int twohunW = two_hundred * 200;
	int fivehunW = five_hundred * 500;
	int thouW = thousand * 1000;
	totalW = one + fiveW + tenW + twenW + fifW + hunW + twohunW + fivehunW + thouW;
}

void moneyInWrite()
{
	ofstream svW;
	svW.open("savings.txt");

	if (svW.is_open())
	{
		svW << totalW << "\n";
	}
	else
	{
		cout << unable << endl;
	}
	svW.close();
}

void balInquiry()
{
	ifstream svR;
	svR.open("savings.txt");
	if (svR.is_open())
	{
		while (getline(svR, totalR))
		{
			cout << "[*] Balance: " << totalR << endl;
		}
	}
	else
	{
		cout << unable << endl;
	}
	svR.close();
	do
	{
		cout << "\n[0] Back\n\nSelect [0] > ";
		cin >> balInput;
		
		switch (balInput)
		{
			case 0:
				break;

			default:
				cout << "Invalid choice" << endl;
				break;
		}
	} while (balInput != 0);
}

void resetSavings()
{
	ofstream money0;
	money0.open("savings.txt");
	money0 << zero << "\n";
	money0.close();
	cout << "[*] Reset Savings Success" << endl;
	do
	{
		cout << "\n[0] Back\n\nSelect [0] > ";
		cin >> resInput;

		switch (resInput)
		{
			case 0:
				break;

			default:
				cout << "Invalid choice" << endl;
				break;
		}
	} while (resInput != 0);
}

int main()
{
	int choice;
	do
	{
		clearScreen();
		cout << "Savings System\nMenu\n[1] Deposit to Savings\n[2] Balance Inquiry\n[3] Reset Savings\n[4] Quit\n\nChoose [1/2/3/4] > ";
		cin >> choice;
		
		switch (choice)
		{
			case 1:
				cout << "Quantity for (P)\n";
				cout << "1: ";
				cin >> one;
				cout << "5: ";
				cin >> five;
				cout << "10: ";
				cin >> ten;
				cout << "20: ";
				cin >> twenty;
				cout << "50: ";
				cin >> fifty;
				cout << "100: ";
				cin >> hundred;
				cout << "200: ";
				cin >> two_hundred;
				cout << "500: ";
				cin >> five_hundred;
				cout << "1000: ";
				cin >> thousand;
				moneyInProcess();
				moneyInWrite();
				break;

			case 2:
				balInquiry();
				break;

			case 3:
				resetSavings();
				break;

			case 4:
				return 0;

			default:
				cout << "Invalid choice!" << endl;
				break;
		}
	} while (choice != 4);
	return 0;
}
