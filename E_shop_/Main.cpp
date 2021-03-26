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
	SetConsoleOutputCP(1251);//відображення мови в консолі
	/*TODO зробити тут авторизацію і вхід до акаунту*/
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
			cout << "Смартфони та телефони:" << endl;
			cout << "Підкатегорії:" << endl;
			cout << "1 - Смартфони" << endl;
			cout << "2 - Телефони" << endl;
			cout << "3 - Аксесуари" << endl;
			cout << "4 - Стартові пакети" << endl;
			cout << "5 - Вихід з категорії" << endl;
			std::cin >> categoryChoice;
			switch (categoryChoice)
			{
			case 1:
				system("cls");
				cout << "Смартфони" << endl;
				smartphone.viewProducts("SmartphonesList.txt");
				cout << "-------------------------------------" << endl;
				cout << "Підменю вибору:" << endl;
				cout << "1 - Купити товар" << endl;
				cout << "2 - Вийти в підкатегорії" << endl;
				cout << "3 - Вийти в головне меню" << endl;
				cin >> pidmenu;
				switch (pidmenu)
				{
				case 1:
					check1:
					shoppingCart.initShoppingCartAdd(id, amount);
					if (!smartphone.getSmartphoneByID(id).isAvailable() && (smartphone.getSmartphoneByID(id).getAvailable() < amount)) {
						int tmp;	
						cout << "1 - Купити інший товар\n2 - Вийти\n";
						cin >> tmp;
						if (tmp == 1) {
							goto check1;
						}
						else if (tmp == 2) {
							system("cls");
							cout << "Вихід у головне меню" << endl;
							cout << "-------------------------------------" << endl;
						}
					}
					else if(smartphone.updateProductList(id, amount)){
						shoppingCart.addProduct(smartphone.getSmartphoneByID(id), amount);
						system("cls");
						cout << "Товар додано в корзину" << endl;
						cout << "-------------------------------------" << endl;
					}
					break;
				case 2:
					system("cls");
					cout << "Вихід у меню підкатегорій" << endl;
					cout << "-------------------------------------" << endl;
					continue;
				case 3:
					system("cls");
					cout << "-------------------------------------" << endl;
					cout << "Вихід у головне меню" << endl;
					break;
				}
				break;
			case 2:
				system("cls");
				cout << "-------------------------------------" << endl;
				cout << "Телефони" << endl;
				telephone.viewProducts("TelephoneList.txt");
				cout << "-------------------------------------" << endl;
				cout << "Підменю вибору:" << endl;
				cout << "1 - Купити товар" << endl;
				cout << "2 - Вийти в підкатегорії" << endl;
				cout << "3 - Вийти в головне меню" << endl;
				cin >> pidmenu;
				switch (pidmenu)
				{
				case 1:
					check2:
					shoppingCart.initShoppingCartAdd(id, amount);
					if (!telephone.getTelephoneByID(id).isAvailable() && (telephone.getTelephoneByID(id).getAvailable() < amount)) {
						int tmp;
						cout << "1 - Купити інший товар\n2 - Вийти\n";
						cin >> tmp;
						if (tmp == 1) {
							goto check2;
						}
						else if (tmp == 2) {
							system("cls");
							cout << "Вихід у головне меню" << endl;
							cout << "-------------------------------------" << endl;
						}
					}
					else if (telephone.updateProductList(id, amount)) {
						shoppingCart.addProduct(telephone.getTelephoneByID(id), amount);
						system("cls");
						cout << "Товар додано в корзину" << endl;
						cout << "-------------------------------------" << endl;
					}
					break;
				case 2:
					system("cls");
					cout << "Вихід у меню підкатегорій" << endl;
					cout << "-------------------------------------" << endl;
					continue;
				case 3:
					system("cls");
					cout << "-------------------------------------" << endl;
					cout << "Вихід у головне меню" << endl;
					break;
				}
				break;
			case 3:
				system("cls");
				cout << "-------------------------------------" << endl;
				cout << "Аксесуари" << endl;
				continue;
			case 4:
				system("cls");
				cout << "-------------------------------------" << endl;
				cout << "Стартові пакети" << endl;
				continue;
			case 5:
				system("cls");
				cout << "-------------------------------------" << endl;
				cout << "Вихід у головне меню" << endl;
				break;
			}
			break;
		/*case1end----------------------------------------------------------*/
		case 2:
		/*case2start----------------------------------------------------------*/
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "Ноутбуки та комп'ютери:" << endl;
			break;
		/*-------------------------------------------------------------*/
		/*case2end----------------------------------------------------------*/
		case 3:
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "Телевізори та мультимедіа:" << endl;
			break;
		case 4:
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "Смарт-годинники та гаджети:" << endl;
			break;
		case 5:
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "Планшети та електронні книги:" << endl;
			break;
		case 6:
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "Фото та відео:" << endl;
			break;
		case 7:
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "Корзина:" << endl;
			shoppingCart.viewShoppingCart();
			break;
		case 8:
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "Профіль:" << endl;
			break;
		case 9:
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "Вихід:" << endl;
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
	cout << "Категорії товарів:" << endl;
	cout << "1 - Смартфони та телефони" << endl;
	cout << "2 - Ноутбуки та комп'ютери" << endl;
	cout << "3 - Телевізори та мультимедіа" << endl;
	cout << "4 - Смарт-годинники та гаджети" << endl;
	cout << "5 - Планшети та електронні книги" << endl;
	cout << "6 - Фото та відео" << endl;
	cout << "-------------------------------------" << endl;
	cout << "7 - Корзина" << endl;
	cout << "8 - Профіль" << endl;
	cout << "9 - Вихід з програми" << endl;
	cout << "-------------------------------------" << endl;
}
