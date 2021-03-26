#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <cstdlib>
#include "ShoppingCart.h"
#include "Smartphone.h"
#include "Telephone.h"
#include "PhoneAccessories.h"
#include "BluetoothHeadset.h"
#include "Cover.h"
#include "Headphone.h"
#include "MemoryCard.h"
#include "PortableSpeakers.h"
#include "ProtectiveGlass.h"
#include "SIMCard.h"

void help();

using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);//����������� ���� � ������
	/*TODO ������� ��� ����������� � ���� �� �������*/
	ShoppingCart shoppingCart;
	Smartphone smartphone;
	Telephone telephone;

	int choice = 0;
	int categoryChoice = 0;
	int pidmenu;
	int id, amount;

	while (true)
	{
		switch (choice) 
		{
		case 1:
		/*case1start----------------------------------------------------------*/
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "��������� �� ��������:" << endl;
			cout << "ϳ��������:" << endl;
			cout << "1 - ���������" << endl;
			cout << "2 - ��������" << endl;
			cout << "3 - ���������" << endl;
			cout << "4 - ������� ������" << endl;
			cout << "5 - ����� � �������" << endl;
			std::cin >> categoryChoice;
			switch (categoryChoice)
			{
			case 1:
				system("cls");
				cout << "���������" << endl;
				smartphone.viewProducts("SmartphonesList.txt");
				cout << "-------------------------------------" << endl;
				cout << "ϳ����� ������:" << endl;
				cout << "1 - ������ �����" << endl;
				cout << "2 - ����� � ���������" << endl;
				cout << "3 - ����� � ������� ����" << endl;
				cin >> pidmenu;
				switch (pidmenu)
				{
				case 1:
					check1:
					shoppingCart.initShoppingCartAdd(id, amount);
					if (!smartphone.getSmartphoneByID(id).isAvailable() && (smartphone.getSmartphoneByID(id).getAvailable() < amount)) {
						int tmp;	
						cout << "1 - ������ ����� �����\n2 - �����\n";
						cin >> tmp;
						if (tmp == 1) {
							goto check1;
						}
						else if (tmp == 2) {
							system("cls");
							cout << "����� � ������� ����" << endl;
							cout << "-------------------------------------" << endl;
						}
					}
					else if(smartphone.updateProductList(id, amount)){
						shoppingCart.addProduct(smartphone.getSmartphoneByID(id), amount);
						system("cls");
						cout << "����� ������ � �������" << endl;
						cout << "-------------------------------------" << endl;
					}
					break;
				case 2:
					system("cls");
					cout << "����� � ���� ����������" << endl;
					cout << "-------------------------------------" << endl;
					continue;
				case 3:
					system("cls");
					cout << "-------------------------------------" << endl;
					cout << "����� � ������� ����" << endl;
					break;
				}
				break;
			case 2:
				system("cls");
				cout << "-------------------------------------" << endl;
				cout << "��������" << endl;
				telephone.viewProducts("TelephoneList.txt");
				cout << "-------------------------------------" << endl;
				cout << "ϳ����� ������:" << endl;
				cout << "1 - ������ �����" << endl;
				cout << "2 - ����� � ���������" << endl;
				cout << "3 - ����� � ������� ����" << endl;
				cin >> pidmenu;
				switch (pidmenu)
				{
				case 1:
					check2:
					shoppingCart.initShoppingCartAdd(id, amount);
					if (!telephone.getTelephoneByID(id).isAvailable() && (telephone.getTelephoneByID(id).getAvailable() < amount)) {
						int tmp;
						cout << "1 - ������ ����� �����\n2 - �����\n";
						cin >> tmp;
						if (tmp == 1) {
							goto check2;
						}
						else if (tmp == 2) {
							system("cls");
							cout << "����� � ������� ����" << endl;
							cout << "-------------------------------------" << endl;
						}
					}
					else if (telephone.updateProductList(id, amount)) {
						shoppingCart.addProduct(telephone.getTelephoneByID(id), amount);
						system("cls");
						cout << "����� ������ � �������" << endl;
						cout << "-------------------------------------" << endl;
					}
					break;
				case 2:
					system("cls");
					cout << "����� � ���� ����������" << endl;
					cout << "-------------------------------------" << endl;
					continue;
				case 3:
					system("cls");
					cout << "-------------------------------------" << endl;
					cout << "����� � ������� ����" << endl;
					break;
				}
				break;
			case 3:
				system("cls");
				cout << "-------------------------------------" << endl;
				cout << "���������" << endl;
				continue;
			case 4:
				system("cls");
				cout << "-------------------------------------" << endl;
				cout << "������� ������" << endl;
				continue;
			case 5:
				system("cls");
				cout << "-------------------------------------" << endl;
				cout << "����� � ������� ����" << endl;
				break;
			}
			break;
		/*case1end----------------------------------------------------------*/
		case 2:
		/*case2start----------------------------------------------------------*/
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "�������� �� ����'�����:" << endl;
			break;
		/*-------------------------------------------------------------*/
		/*case2end----------------------------------------------------------*/
		case 3:
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "��������� �� ����������:" << endl;
			break;
		case 4:
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "�����-��������� �� �������:" << endl;
			break;
		case 5:
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "�������� �� ��������� �����:" << endl;
			break;
		case 6:
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "���� �� ����:" << endl;
			break;
		case 7:
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "�������:" << endl;
			shoppingCart.viewShoppingCart();
			break;
		case 8:
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "�������:" << endl;
			break;
		case 9:
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "�����:" << endl;
			cout << "-------------------------------------" << endl;
			exit(0);
		}
		help();
		std::cin >> choice;
		system("cls");
	}
	return 0;
}

void help()
{
	cout << "-------------------------------------" << endl;
	cout << "������� ������:" << endl;
	cout << "1 - ��������� �� ��������" << endl;
	cout << "2 - �������� �� ����'�����" << endl;
	cout << "3 - ��������� �� ����������" << endl;
	cout << "4 - �����-��������� �� �������" << endl;
	cout << "5 - �������� �� ��������� �����" << endl;
	cout << "6 - ���� �� ����" << endl;
	cout << "-------------------------------------" << endl;
	cout << "7 - �������" << endl;
	cout << "8 - �������" << endl;
	cout << "9 - ����� � ��������" << endl;
	cout << "-------------------------------------" << endl;
}
