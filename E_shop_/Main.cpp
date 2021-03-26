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
	/*����� ��������*/
	Smartphone smartphone;
	Telephone telephone;
	Cover cover;
	Headphone headphone;

	PortableSpeakers portableSpeakers;
	BluetoothHeadset bluetoothHeadset;
	MemoryCard memoryCard;
	ProtectiveGlass protectiveGlass;

	SIMCard simCard;
	/*����� ��������*/
	


	int choice = 0;
	int categoryChoice = 0;
	int pidmenu;
	int id, amount;
	cout << "-------------------------------------" << endl;
	cout << "ó��������� ���������� \"No Name\"" << endl;
	cout << "-------------------------------------" << endl;


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
				cout << "���������:" << endl;
				cout << "ϳ��������:" << endl;
				cout << "1 - �����" << endl;
				cout << "2 - ���������" << endl;
				cout << "3 - ��������� �������" << endl;
				cout << "4 - Bluetooth-��������" << endl;
				cout << "5 - ����� ���'��" << endl;
				cout << "6 - ������ ����� �� ����" << endl;
				cout << "7 - ����� � �������" << endl;
				int tmp;
				cin >> tmp;
				switch (tmp) {
				case 1:
					cout << "-------------------------------------" << endl;
					cout << "�����" << endl;
					cover.viewProducts("CoverList.txt");
					cout << "-------------------------------------" << endl;
					cout << "ϳ����� ������:" << endl;
					cout << "1 - ������ �����" << endl;
					cout << "2 - ����� � ���������" << endl;
					cout << "3 - ����� � ������� ����" << endl;
					cin >> pidmenu;
					switch (pidmenu)
					{
					case 1:
					check3:
						shoppingCart.initShoppingCartAdd(id, amount);
						if (!cover.getCoverByID(id).isAvailable() && (cover.getCoverByID(id).getAvailable() < amount)) {
							int tmp;
							cout << "1 - ������ ����� �����\n2 - �����\n";
							cin >> tmp;
							if (tmp == 1) {
								goto check3;
							}
							else if (tmp == 2) {
								system("cls");
								cout << "����� � ������� ����" << endl;
								cout << "-------------------------------------" << endl;
							}
						}
						else if (cover.updateProductList(id, amount)) {
							shoppingCart.addProduct(cover.getCoverByID(id), amount);
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
					cout << "-------------------------------------" << endl;
					cout << "���������" << endl;
					headphone.viewProducts("HeadphoneList.txt");
					cout << "-------------------------------------" << endl;
					cout << "ϳ����� ������:" << endl;
					cout << "1 - ������ �����" << endl;
					cout << "2 - ����� � ���������" << endl;
					cout << "3 - ����� � ������� ����" << endl;
					cin >> pidmenu;
					switch (pidmenu)
					{
					case 1:
					check4:
						shoppingCart.initShoppingCartAdd(id, amount);
						if (!headphone.getHeadphoneByID(id).isAvailable() && (headphone.getHeadphoneByID(id).getAvailable() < amount)) {
							int tmp;
							cout << "1 - ������ ����� �����\n2 - �����\n";
							cin >> tmp;
							if (tmp == 1) {
								goto check4;
							}
							else if (tmp == 2) {
								system("cls");
								cout << "����� � ������� ����" << endl;
								cout << "-------------------------------------" << endl;
							}
						}
						else if (headphone.updateProductList(id, amount)) {
							shoppingCart.addProduct(headphone.getHeadphoneByID(id), amount);
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
					cout << "-------------------------------------" << endl;
					cout << "��������� �������" << endl;
					portableSpeakers.viewProducts("PortableSpeakersList.txt");
					cout << "-------------------------------------" << endl;
					cout << "ϳ����� ������:" << endl;
					cout << "1 - ������ �����" << endl;
					cout << "2 - ����� � ���������" << endl;
					cout << "3 - ����� � ������� ����" << endl;
					cin >> pidmenu;
					switch (pidmenu)
					{
					case 1:
					check5:
						shoppingCart.initShoppingCartAdd(id, amount);
						if (!portableSpeakers.getPortableSpeakersByID(id).isAvailable() && (portableSpeakers.getPortableSpeakersByID(id).getAvailable() < amount)) {
							int tmp;
							cout << "1 - ������ ����� �����\n2 - �����\n";
							cin >> tmp;
							if (tmp == 1) {
								goto check5;
							}
							else if (tmp == 2) {
								system("cls");
								cout << "����� � ������� ����" << endl;
								cout << "-------------------------------------" << endl;
							}
						}
						else if (portableSpeakers.updateProductList(id, amount)) {
							shoppingCart.addProduct(portableSpeakers.getPortableSpeakersByID(id), amount);
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
				case 4:
					cout << "-------------------------------------" << endl;
					cout << "Bluetooth-��������" << endl;
					bluetoothHeadset.viewProducts("BluetoothHeadsetList.txt");
					cout << "-------------------------------------" << endl;
					cout << "ϳ����� ������:" << endl;
					cout << "1 - ������ �����" << endl;
					cout << "2 - ����� � ���������" << endl;
					cout << "3 - ����� � ������� ����" << endl;
					cin >> pidmenu;
					switch (pidmenu)
					{
					case 1:
					check6:
						shoppingCart.initShoppingCartAdd(id, amount);
						if (!bluetoothHeadset.getBluetoothHeadsetByID(id).isAvailable() && (bluetoothHeadset.getBluetoothHeadsetByID(id).getAvailable() < amount)) {
							int tmp;
							cout << "1 - ������ ����� �����\n2 - �����\n";
							cin >> tmp;
							if (tmp == 1) {
								goto check6;
							}
							else if (tmp == 2) {
								system("cls");
								cout << "����� � ������� ����" << endl;
								cout << "-------------------------------------" << endl;
							}
						}
						else if (bluetoothHeadset.updateProductList(id, amount)) {
							shoppingCart.addProduct(bluetoothHeadset.getBluetoothHeadsetByID(id), amount);
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
				case 5:
					cout << "-------------------------------------" << endl;
					cout << "����� ���'��" << endl;
					memoryCard.viewProducts("MemoryCardList.txt");
					cout << "-------------------------------------" << endl;
					cout << "ϳ����� ������:" << endl;
					cout << "1 - ������ �����" << endl;
					cout << "2 - ����� � ���������" << endl;
					cout << "3 - ����� � ������� ����" << endl;
					cin >> pidmenu;
					switch (pidmenu)
					{
					case 1:
					check7:
						shoppingCart.initShoppingCartAdd(id, amount);
						if (!memoryCard.getMemoryCardByID(id).isAvailable() && (memoryCard.getMemoryCardByID(id).getAvailable() < amount)) {
							int tmp;
							cout << "1 - ������ ����� �����\n2 - �����\n";
							cin >> tmp;
							if (tmp == 1) {
								goto check7;
							}
							else if (tmp == 2) {
								system("cls");
								cout << "����� � ������� ����" << endl;
								cout << "-------------------------------------" << endl;
							}
						}
						else if (memoryCard.updateProductList(id, amount)) {
							shoppingCart.addProduct(memoryCard.getMemoryCardByID(id), amount);
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
				case 6:
					cout << "-------------------------------------" << endl;
					cout << "������ ����� �� ����" << endl;
					protectiveGlass.viewProducts("ProtectiveGlassList.txt");
					cout << "-------------------------------------" << endl;
					cout << "ϳ����� ������:" << endl;
					cout << "1 - ������ �����" << endl;
					cout << "2 - ����� � ���������" << endl;
					cout << "3 - ����� � ������� ����" << endl;
					cin >> pidmenu;
					switch (pidmenu)
					{
					case 1:
					check8:
						shoppingCart.initShoppingCartAdd(id, amount);
						if (!protectiveGlass.getProtectiveGlassByID(id).isAvailable() && (protectiveGlass.getProtectiveGlassByID(id).getAvailable() < amount)) {
							int tmp;
							cout << "1 - ������ ����� �����\n2 - �����\n";
							cin >> tmp;
							if (tmp == 1) {
								goto check8;
							}
							else if (tmp == 2) {
								system("cls");
								cout << "����� � ������� ����" << endl;
								cout << "-------------------------------------" << endl;
							}
						}
						else if (protectiveGlass.updateProductList(id, amount)) {
							shoppingCart.addProduct(protectiveGlass.getProtectiveGlassByID(id), amount);
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
				case 7:
					system("cls");
					cout << "-------------------------------------" << endl;
					cout << "����� � ������� ����" << endl;
					break;
				}
				break;
			case 4:
				system("cls");
				cout << "-------------------------------------" << endl;
				cout << "������� ������" << endl;
				simCard.viewProducts("SIMCardList.txt");
				cout << "-------------------------------------" << endl;
				cout << "ϳ����� ������:" << endl;
				cout << "1 - ������ �����" << endl;
				cout << "2 - ����� � ���������" << endl;
				cout << "3 - ����� � ������� ����" << endl;
				cin >> pidmenu;
				switch (pidmenu)
				{
				case 1:
				check9:
					shoppingCart.initShoppingCartAdd(id, amount);
					if (!simCard.getSIMCardByID(id).isAvailable() && (simCard.getSIMCardByID(id).getAvailable() < amount)) {
						int tmp;
						cout << "1 - ������ ����� �����\n2 - �����\n";
						cin >> tmp;
						if (tmp == 1) {
							goto check9;
						}
						else if (tmp == 2) {
							system("cls");
							cout << "����� � ������� ����" << endl;
							cout << "-------------------------------------" << endl;
						}
					}
					else if (simCard.updateProductList(id, amount)) {
						shoppingCart.addProduct(simCard.getSIMCardByID(id), amount);
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
