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
#include "Laptop.h"
#include "Printer.h"
#include "Router.h"
#include "PCAccessories.h"
#include "Videocard.h"
#include "Processor.h"
#include "Motherboard.h"
#include "DDR.h"
#include "Storage.h"
#include "PowerSupplies.h"
#include "Accessories.h"
#include "Television.h"
#include "Multimedia.h"
#include "Projectors.h"
#include "TVAccessories.h"
#include "SmartWatches.h"
#include "Quadrocopter.h"
#include "Printer3D.h"
#include "Tablet.h"
#include "EBook.h"
#include "Photocamera.h"
#include "VideoCamera.h"


void help();

using namespace std;
int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);//відображення мови в консолі
	ShoppingCart shoppingCart;

	/*Перша категорія*/
	Smartphone smartphone;
	Telephone telephone;
	Cover cover;
	Headphone headphone;

	PortableSpeakers portableSpeakers;
	BluetoothHeadset bluetoothHeadset;
	MemoryCard memoryCard;
	ProtectiveGlass protectiveGlass;

	SIMCard simCard;
	/*Друга категорія*/
	Laptop laptop;
	Printer printer;
	Router router;
	
	Videocard videocard;
	Processor processor;
	Motherboard motherboard;
	DDR ddr;
	Storage storage;
	PowerSupplies powerSupplies;

	Accessories accessories;
	/*Третя категорія*/
	Television television;
	Multimedia multimedia;
	Projectors projector;
	TVAccessories tvAccessories;
	/*Четверта категорія*/
	SmartWatches smartWatch;
	Quadrocopter quadrocopter;
	Printer3D printer3D;
	/*П'ята категорія*/
	Tablet tablet;
	EBook ebook;
	/*Шоста категорія*/
	PhotoCamera photoCamera;
	VideoCamera videoCamera;
	/*------------------*/
	int choice = 0;
	int categoryChoice = 0;
	int pidmenu;
	int id, amount;
	cout << "-------------------------------------" << endl;
	cout << "Гіпермаркет електроніки \"No Name\"" << endl;
	cout << "-------------------------------------" << endl;

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
				cout << "Аксесуари:" << endl;
				cout << "Підкатегорії:" << endl;
				cout << "1 - Чохли" << endl;
				cout << "2 - Навушники" << endl;
				cout << "3 - Портативні колонки" << endl;
				cout << "4 - Bluetooth-гарнітури" << endl;
				cout << "5 - Карти пам'яті" << endl;
				cout << "6 - Захисні плівки та скло" << endl;
				cout << "7 - Вихід з категорії" << endl;
				int tmp;
				cin >> tmp;
				switch (tmp) {
				case 1:
					cout << "-------------------------------------" << endl;
					cout << "Чохли" << endl;
					cover.viewProducts("CoverList.txt");
					cout << "-------------------------------------" << endl;
					cout << "Підменю вибору:" << endl;
					cout << "1 - Купити товар" << endl;
					cout << "2 - Вийти в підкатегорії" << endl;
					cout << "3 - Вийти в головне меню" << endl;
					cin >> pidmenu;
					switch (pidmenu)
					{
					case 1:
					check3:
						shoppingCart.initShoppingCartAdd(id, amount);
						if (!cover.getCoverByID(id).isAvailable() && (cover.getCoverByID(id).getAvailable() < amount)) {
							int tmp;
							cout << "1 - Купити інший товар\n2 - Вийти\n";
							cin >> tmp;
							if (tmp == 1) {
								goto check3;
							}
							else if (tmp == 2) {
								system("cls");
								cout << "Вихід у головне меню" << endl;
								cout << "-------------------------------------" << endl;
							}
						}
						else if (cover.updateProductList(id, amount)) {
							shoppingCart.addProduct(cover.getCoverByID(id), amount);
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
					cout << "-------------------------------------" << endl;
					cout << "Навушники" << endl;
					headphone.viewProducts("HeadphoneList.txt");
					cout << "-------------------------------------" << endl;
					cout << "Підменю вибору:" << endl;
					cout << "1 - Купити товар" << endl;
					cout << "2 - Вийти в підкатегорії" << endl;
					cout << "3 - Вийти в головне меню" << endl;
					cin >> pidmenu;
					switch (pidmenu)
					{
					case 1:
					check4:
						shoppingCart.initShoppingCartAdd(id, amount);
						if (!headphone.getHeadphoneByID(id).isAvailable() && (headphone.getHeadphoneByID(id).getAvailable() < amount)) {
							int tmp;
							cout << "1 - Купити інший товар\n2 - Вийти\n";
							cin >> tmp;
							if (tmp == 1) {
								goto check4;
							}
							else if (tmp == 2) {
								system("cls");
								cout << "Вихід у головне меню" << endl;
								cout << "-------------------------------------" << endl;
							}
						}
						else if (headphone.updateProductList(id, amount)) {
							shoppingCart.addProduct(headphone.getHeadphoneByID(id), amount);
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
					cout << "-------------------------------------" << endl;
					cout << "Портативні колонки" << endl;
					portableSpeakers.viewProducts("PortableSpeakersList.txt");
					cout << "-------------------------------------" << endl;
					cout << "Підменю вибору:" << endl;
					cout << "1 - Купити товар" << endl;
					cout << "2 - Вийти в підкатегорії" << endl;
					cout << "3 - Вийти в головне меню" << endl;
					cin >> pidmenu;
					switch (pidmenu)
					{
					case 1:
					check5:
						shoppingCart.initShoppingCartAdd(id, amount);
						if (!portableSpeakers.getPortableSpeakersByID(id).isAvailable() && (portableSpeakers.getPortableSpeakersByID(id).getAvailable() < amount)) {
							int tmp;
							cout << "1 - Купити інший товар\n2 - Вийти\n";
							cin >> tmp;
							if (tmp == 1) {
								goto check5;
							}
							else if (tmp == 2) {
								system("cls");
								cout << "Вихід у головне меню" << endl;
								cout << "-------------------------------------" << endl;
							}
						}
						else if (portableSpeakers.updateProductList(id, amount)) {
							shoppingCart.addProduct(portableSpeakers.getPortableSpeakersByID(id), amount);
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
				case 4:
					cout << "-------------------------------------" << endl;
					cout << "Bluetooth-гарнітури" << endl;
					bluetoothHeadset.viewProducts("BluetoothHeadsetList.txt");
					cout << "-------------------------------------" << endl;
					cout << "Підменю вибору:" << endl;
					cout << "1 - Купити товар" << endl;
					cout << "2 - Вийти в підкатегорії" << endl;
					cout << "3 - Вийти в головне меню" << endl;
					cin >> pidmenu;
					switch (pidmenu)
					{
					case 1:
					check6:
						shoppingCart.initShoppingCartAdd(id, amount);
						if (!bluetoothHeadset.getBluetoothHeadsetByID(id).isAvailable() && (bluetoothHeadset.getBluetoothHeadsetByID(id).getAvailable() < amount)) {
							int tmp;
							cout << "1 - Купити інший товар\n2 - Вийти\n";
							cin >> tmp;
							if (tmp == 1) {
								goto check6;
							}
							else if (tmp == 2) {
								system("cls");
								cout << "Вихід у головне меню" << endl;
								cout << "-------------------------------------" << endl;
							}
						}
						else if (bluetoothHeadset.updateProductList(id, amount)) {
							shoppingCart.addProduct(bluetoothHeadset.getBluetoothHeadsetByID(id), amount);
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
				case 5:
					cout << "-------------------------------------" << endl;
					cout << "Карти пам'яті" << endl;
					memoryCard.viewProducts("MemoryCardList.txt");
					cout << "-------------------------------------" << endl;
					cout << "Підменю вибору:" << endl;
					cout << "1 - Купити товар" << endl;
					cout << "2 - Вийти в підкатегорії" << endl;
					cout << "3 - Вийти в головне меню" << endl;
					cin >> pidmenu;
					switch (pidmenu)
					{
					case 1:
					check7:
						shoppingCart.initShoppingCartAdd(id, amount);
						if (!memoryCard.getMemoryCardByID(id).isAvailable() && (memoryCard.getMemoryCardByID(id).getAvailable() < amount)) {
							int tmp;
							cout << "1 - Купити інший товар\n2 - Вийти\n";
							cin >> tmp;
							if (tmp == 1) {
								goto check7;
							}
							else if (tmp == 2) {
								system("cls");
								cout << "Вихід у головне меню" << endl;
								cout << "-------------------------------------" << endl;
							}
						}
						else if (memoryCard.updateProductList(id, amount)) {
							shoppingCart.addProduct(memoryCard.getMemoryCardByID(id), amount);
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
				case 6:
					cout << "-------------------------------------" << endl;
					cout << "Захисні плівки та скло" << endl;
					protectiveGlass.viewProducts("ProtectiveGlassList.txt");
					cout << "-------------------------------------" << endl;
					cout << "Підменю вибору:" << endl;
					cout << "1 - Купити товар" << endl;
					cout << "2 - Вийти в підкатегорії" << endl;
					cout << "3 - Вийти в головне меню" << endl;
					cin >> pidmenu;
					switch (pidmenu)
					{
					case 1:
					check8:
						shoppingCart.initShoppingCartAdd(id, amount);
						if (!protectiveGlass.getProtectiveGlassByID(id).isAvailable() && (protectiveGlass.getProtectiveGlassByID(id).getAvailable() < amount)) {
							int tmp;
							cout << "1 - Купити інший товар\n2 - Вийти\n";
							cin >> tmp;
							if (tmp == 1) {
								goto check8;
							}
							else if (tmp == 2) {
								system("cls");
								cout << "Вихід у головне меню" << endl;
								cout << "-------------------------------------" << endl;
							}
						}
						else if (protectiveGlass.updateProductList(id, amount)) {
							shoppingCart.addProduct(protectiveGlass.getProtectiveGlassByID(id), amount);
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
				case 7:
					system("cls");
					cout << "-------------------------------------" << endl;
					cout << "Вихід у головне меню" << endl;
					break;
				}
				break;
			case 4:
				system("cls");
				cout << "-------------------------------------" << endl;
				cout << "Стартові пакети" << endl;
				simCard.viewProducts("SIMCardList.txt");
				cout << "-------------------------------------" << endl;
				cout << "Підменю вибору:" << endl;
				cout << "1 - Купити товар" << endl;
				cout << "2 - Вийти в підкатегорії" << endl;
				cout << "3 - Вийти в головне меню" << endl;
				cin >> pidmenu;
				switch (pidmenu)
				{
				case 1:
				check9:
					shoppingCart.initShoppingCartAdd(id, amount);
					if (!simCard.getSIMCardByID(id).isAvailable() && (simCard.getSIMCardByID(id).getAvailable() < amount)) {
						int tmp;
						cout << "1 - Купити інший товар\n2 - Вийти\n";
						cin >> tmp;
						if (tmp == 1) {
							goto check9;
						}
						else if (tmp == 2) {
							system("cls");
							cout << "Вихід у головне меню" << endl;
							cout << "-------------------------------------" << endl;
						}
					}
					else if (simCard.updateProductList(id, amount)) {
						shoppingCart.addProduct(simCard.getSIMCardByID(id), amount);
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
			cout << "Підкатегорії:" << endl;
			cout << "1 - Ноутбуки" << endl;
			cout << "2 - Принтери" << endl;
			cout << "3 - Роутери" << endl;
			cout << "4 - Комплектуючі до ПК" << endl;
			cout << "5 - Аксесуари" << endl;
			cout << "6 - Вихід з категорії" << endl;
			std::cin >> categoryChoice;
			switch (categoryChoice)
			{
			case 1:
				system("cls");
				cout << "Ноутбуки" << endl;
				laptop.viewProducts("LaptopsList.txt");
				cout << "-------------------------------------" << endl;
				cout << "Підменю вибору:" << endl;
				cout << "1 - Купити товар" << endl;
				cout << "2 - Вийти в підкатегорії" << endl;
				cout << "3 - Вийти в головне меню" << endl;
				cin >> pidmenu;
				switch (pidmenu)
				{
				case 1:
				check10:
					shoppingCart.initShoppingCartAdd(id, amount);
					if (!laptop.getLaptopByID(id).isAvailable() && (laptop.getLaptopByID(id).getAvailable() < amount)) {
						int tmp;
						cout << "1 - Купити інший товар\n2 - Вийти\n";
						cin >> tmp;
						if (tmp == 1) {
							goto check10;
						}
						else if (tmp == 2) {
							system("cls");
							cout << "Вихід у головне меню" << endl;
							cout << "-------------------------------------" << endl;
						}
					}
					else if (laptop.updateProductList(id, amount)) {
						shoppingCart.addProduct(laptop.getLaptopByID(id), amount);
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
				cout << "Принтери" << endl;
				printer.viewProducts("PrintersList.txt");
				cout << "-------------------------------------" << endl;
				cout << "Підменю вибору:" << endl;
				cout << "1 - Купити товар" << endl;
				cout << "2 - Вийти в підкатегорії" << endl;
				cout << "3 - Вийти в головне меню" << endl;
				cin >> pidmenu;
				switch (pidmenu)
				{
				case 1:
				check11:
					shoppingCart.initShoppingCartAdd(id, amount);
					if (!printer.getPrinterByID(id).isAvailable() && (printer.getPrinterByID(id).getAvailable() < amount)) {
						int tmp;
						cout << "1 - Купити інший товар\n2 - Вийти\n";
						cin >> tmp;
						if (tmp == 1) {
							goto check11;
						}
						else if (tmp == 2) {
							system("cls");
							cout << "Вихід у головне меню" << endl;
							cout << "-------------------------------------" << endl;
						}
					}
					else if (laptop.updateProductList(id, amount)) {
						shoppingCart.addProduct(printer.getPrinterByID(id), amount);
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
				cout << "Роутери" << endl;
				router.viewProducts("RoutersList.txt");
				cout << "-------------------------------------" << endl;
				cout << "Підменю вибору:" << endl;
				cout << "1 - Купити товар" << endl;
				cout << "2 - Вийти в підкатегорії" << endl;
				cout << "3 - Вийти в головне меню" << endl;
				cin >> pidmenu;
				switch (pidmenu)
				{
				case 1:
				check12:
					shoppingCart.initShoppingCartAdd(id, amount);
					if (!router.getRouterByID(id).isAvailable() && (router.getRouterByID(id).getAvailable() < amount)) {
						int tmp;
						cout << "1 - Купити інший товар\n2 - Вийти\n";
						cin >> tmp;
						if (tmp == 1) {
							goto check12;
						}
						else if (tmp == 2) {
							system("cls");
							cout << "Вихід у головне меню" << endl;
							cout << "-------------------------------------" << endl;
						}
					}
					else if (laptop.updateProductList(id, amount)) {
						shoppingCart.addProduct(router.getRouterByID(id), amount);
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
			case 4: 
				system("cls");
				cout << "-------------------------------------" << endl;
				cout << "Комплектуючі до ПК:" << endl;
				cout << "Підкатегорії:" << endl;
				cout << "1 - Відеокарти" << endl;
				cout << "2 - Процесори" << endl;
				cout << "3 - Материнські плати" << endl;
				cout << "4 - Пам'ять DDR" << endl;
				cout << "5 - SSD і HDD накопичувачі" << endl;
				cout << "6 - Блоки живлення" << endl;
				cout << "7 - Вихід з категорії" << endl;
				int tmp;
				cin >> tmp;
				switch (tmp) {
				case 1:
					cout << "-------------------------------------" << endl;
					cout << "Відеокарти" << endl;
					videocard.viewProducts("VideocardsList.txt");
					cout << "-------------------------------------" << endl;
					cout << "Підменю вибору:" << endl;
					cout << "1 - Купити товар" << endl;
					cout << "2 - Вийти в підкатегорії" << endl;
					cout << "3 - Вийти в головне меню" << endl;
					cin >> pidmenu;
					switch (pidmenu)
					{
					case 1:
					check13:
						shoppingCart.initShoppingCartAdd(id, amount);
						if (!videocard.getVideocardByID(id).isAvailable() && (videocard.getVideocardByID(id).getAvailable() < amount)) {
							int tmp;
							cout << "1 - Купити інший товар\n2 - Вийти\n";
							cin >> tmp;
							if (tmp == 1) {
								goto check13;
							}
							else if (tmp == 2) {
								system("cls");
								cout << "Вихід у головне меню" << endl;
								cout << "-------------------------------------" << endl;
							}
						}
						else if (videocard.updateProductList(id, amount)) {
							shoppingCart.addProduct(videocard.getVideocardByID(id), amount);
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
					cout << "-------------------------------------" << endl;
					cout << "Процесори" << endl;
					processor.viewProducts("ProcessorsList.txt");
					cout << "-------------------------------------" << endl;
					cout << "Підменю вибору:" << endl;
					cout << "1 - Купити товар" << endl;
					cout << "2 - Вийти в підкатегорії" << endl;
					cout << "3 - Вийти в головне меню" << endl;
					cin >> pidmenu;
					switch (pidmenu)
					{
					case 1:
					check14:
						shoppingCart.initShoppingCartAdd(id, amount);
						if (!processor.getProcessorByID(id).isAvailable() && (processor.getProcessorByID(id).getAvailable() < amount)) {
							int tmp;
							cout << "1 - Купити інший товар\n2 - Вийти\n";
							cin >> tmp;
							if (tmp == 1) {
								goto check14;
							}
							else if (tmp == 2) {
								system("cls");
								cout << "Вихід у головне меню" << endl;
								cout << "-------------------------------------" << endl;
							}
						}
						else if (processor.updateProductList(id, amount)) {
							shoppingCart.addProduct(processor.getProcessorByID(id), amount);
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
					cout << "-------------------------------------" << endl;
					cout << "Материнські плати" << endl;
					motherboard.viewProducts("MotherboardsList.txt");
					cout << "-------------------------------------" << endl;
					cout << "Підменю вибору:" << endl;
					cout << "1 - Купити товар" << endl;
					cout << "2 - Вийти в підкатегорії" << endl;
					cout << "3 - Вийти в головне меню" << endl;
					cin >> pidmenu;
					switch (pidmenu)
					{
					case 1:
					check15:
						shoppingCart.initShoppingCartAdd(id, amount);
						if (!motherboard.getMotherboardByID(id).isAvailable() && (motherboard.getMotherboardByID(id).getAvailable() < amount)) {
							int tmp;
							cout << "1 - Купити інший товар\n2 - Вийти\n";
							cin >> tmp;
							if (tmp == 1) {
								goto check15;
							}
							else if (tmp == 2) {
								system("cls");
								cout << "Вихід у головне меню" << endl;
								cout << "-------------------------------------" << endl;
							}
						}
						else if (motherboard.updateProductList(id, amount)) {
							shoppingCart.addProduct(motherboard.getMotherboardByID(id), amount);
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
				case 4:
					cout << "-------------------------------------" << endl;
					cout << "Пам'ять DDR" << endl;
					ddr.viewProducts("DDRsList.txt");
					cout << "-------------------------------------" << endl;
					cout << "Підменю вибору:" << endl;
					cout << "1 - Купити товар" << endl;
					cout << "2 - Вийти в підкатегорії" << endl;
					cout << "3 - Вийти в головне меню" << endl;
					cin >> pidmenu;
					switch (pidmenu)
					{
					case 1:
					check16:
						shoppingCart.initShoppingCartAdd(id, amount);
						if (!ddr.getDDRByID(id).isAvailable() && (ddr.getDDRByID(id).getAvailable() < amount)) {
							int tmp;
							cout << "1 - Купити інший товар\n2 - Вийти\n";
							cin >> tmp;
							if (tmp == 1) {
								goto check16;
							}
							else if (tmp == 2) {
								system("cls");
								cout << "Вихід у головне меню" << endl;
								cout << "-------------------------------------" << endl;
							}
						}
						else if (ddr.updateProductList(id, amount)) {
							shoppingCart.addProduct(ddr.getDDRByID(id), amount);
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
				case 5:
					cout << "-------------------------------------" << endl;
					cout << "SSD і HDD накопичувачі" << endl;
					storage.viewProducts("StoragesList.txt");
					cout << "-------------------------------------" << endl;
					cout << "Підменю вибору:" << endl;
					cout << "1 - Купити товар" << endl;
					cout << "2 - Вийти в підкатегорії" << endl;
					cout << "3 - Вийти в головне меню" << endl;
					cin >> pidmenu;
					switch (pidmenu)
					{
					case 1:
					check17:
						shoppingCart.initShoppingCartAdd(id, amount);
						if (!storage.getStorageByID(id).isAvailable() && (storage.getStorageByID(id).getAvailable() < amount)) {
							int tmp;
							cout << "1 - Купити інший товар\n2 - Вийти\n";
							cin >> tmp;
							if (tmp == 1) {
								goto check17;
							}
							else if (tmp == 2) {
								system("cls");
								cout << "Вихід у головне меню" << endl;
								cout << "-------------------------------------" << endl;
							}
						}
						else if (storage.updateProductList(id, amount)) {
							shoppingCart.addProduct(storage.getStorageByID(id), amount);
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
				case 6:
					cout << "-------------------------------------" << endl;
					cout << "Блоки живлення" << endl;
					powerSupplies.viewProducts("PowerSuppliesList.txt");
					cout << "-------------------------------------" << endl;
					cout << "Підменю вибору:" << endl;
					cout << "1 - Купити товар" << endl;
					cout << "2 - Вийти в підкатегорії" << endl;
					cout << "3 - Вийти в головне меню" << endl;
					cin >> pidmenu;
					switch (pidmenu)
					{
					case 1:
					check18:
						shoppingCart.initShoppingCartAdd(id, amount);
						if (!powerSupplies.getPowerSuppliesByID(id).isAvailable() && (powerSupplies.getPowerSuppliesByID(id).getAvailable() < amount)) {
							int tmp;
							cout << "1 - Купити інший товар\n2 - Вийти\n";
							cin >> tmp;
							if (tmp == 1) {
								goto check18;
							}
							else if (tmp == 2) {
								system("cls");
								cout << "Вихід у головне меню" << endl;
								cout << "-------------------------------------" << endl;
							}
						}
						else if (powerSupplies.updateProductList(id, amount)) {
							shoppingCart.addProduct(powerSupplies.getPowerSuppliesByID(id), amount);
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
				case 7:
					system("cls");
					cout << "-------------------------------------" << endl;
					cout << "Вихід у головне меню" << endl;
					break;
				}
				break;
			case 5:
				system("cls");
				cout << "Аксесуари" << endl;
				accessories.viewProducts("AccessoriesList.txt");
				cout << "-------------------------------------" << endl;
				cout << "Підменю вибору:" << endl;
				cout << "1 - Купити товар" << endl;
				cout << "2 - Вийти в підкатегорії" << endl;
				cout << "3 - Вийти в головне меню" << endl;
				cin >> pidmenu;
				switch (pidmenu)
				{
				case 1:
				check19:
					shoppingCart.initShoppingCartAdd(id, amount);
					if (!accessories.getAccessoriesByID(id).isAvailable() && (accessories.getAccessoriesByID(id).getAvailable() < amount)) {
						int tmp;
						cout << "1 - Купити інший товар\n2 - Вийти\n";
						cin >> tmp;
						if (tmp == 1) {
							goto check19;
						}
						else if (tmp == 2) {
							system("cls");
							cout << "Вихід у головне меню" << endl;
							cout << "-------------------------------------" << endl;
						}
					}
					else if (accessories.updateProductList(id, amount)) {
						shoppingCart.addProduct(accessories.getAccessoriesByID(id), amount);
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
			case 6:
				system("cls");
				cout << "-------------------------------------" << endl;
				cout << "Вихід у головне меню" << endl;
				break;
			}
			break;
		/*-------------------------------------------------------------*/
		/*case2end----------------------------------------------------------*/
		/*case3start----------------------------------------------------------*/
		/*-------------------------------------------------------------*/
		case 3:
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "Телевізори та мультимедіа:" << endl;
			cout << "Підкатегорії:" << endl;
			cout << "1 - Телевізори" << endl;
			cout << "2 - Мультимедіа та звук" << endl;
			cout << "3 - Проектори та екрани" << endl;
			cout << "4 - Аксесуари для ТВ" << endl;
			cout << "5 - Вихід з категорії" << endl;
			std::cin >> categoryChoice;
			switch (categoryChoice)
			{
			case 1:
				system("cls");
				cout << "Телевізори" << endl;
				television.viewProducts("TVsList.txt");
				cout << "-------------------------------------" << endl;
				cout << "Підменю вибору:" << endl;
				cout << "1 - Купити товар" << endl;
				cout << "2 - Вийти в підкатегорії" << endl;
				cout << "3 - Вийти в головне меню" << endl;
				cin >> pidmenu;
				switch (pidmenu)
				{
				case 1:
				check20:
					shoppingCart.initShoppingCartAdd(id, amount);
					if (!television.getTVByID(id).isAvailable() && (television.getTVByID(id).getAvailable() < amount)) {
						int tmp;
						cout << "1 - Купити інший товар\n2 - Вийти\n";
						cin >> tmp;
						if (tmp == 1) {
							goto check20;
						}
						else if (tmp == 2) {
							system("cls");
							cout << "Вихід у головне меню" << endl;
							cout << "-------------------------------------" << endl;
						}
					}
					else if (television.updateProductList(id, amount)) {
						shoppingCart.addProduct(television.getTVByID(id), amount);
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
				cout << "Мультимедіа та звук" << endl;
				multimedia.viewProducts("MultimediasList.txt");
				cout << "-------------------------------------" << endl;
				cout << "Підменю вибору:" << endl;
				cout << "1 - Купити товар" << endl;
				cout << "2 - Вийти в підкатегорії" << endl;
				cout << "3 - Вийти в головне меню" << endl;
				cin >> pidmenu;
				switch (pidmenu)
				{
				case 1:
				check21:
					shoppingCart.initShoppingCartAdd(id, amount);
					if (!multimedia.getMultimediaByID(id).isAvailable() && (multimedia.getMultimediaByID(id).getAvailable() < amount)) {
						int tmp;
						cout << "1 - Купити інший товар\n2 - Вийти\n";
						cin >> tmp;
						if (tmp == 1) {
							goto check21;
						}
						else if (tmp == 2) {
							system("cls");
							cout << "Вихід у головне меню" << endl;
							cout << "-------------------------------------" << endl;
						}
					}
					else if (multimedia.updateProductList(id, amount)) {
						shoppingCart.addProduct(multimedia.getMultimediaByID(id), amount);
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
				cout << "Проектори та екрани" << endl;
				projector.viewProducts("ProjectorsList.txt");
				cout << "-------------------------------------" << endl;
				cout << "Підменю вибору:" << endl;
				cout << "1 - Купити товар" << endl;
				cout << "2 - Вийти в підкатегорії" << endl;
				cout << "3 - Вийти в головне меню" << endl;
				cin >> pidmenu;
				switch (pidmenu)
				{
				case 1:
				check22:
					shoppingCart.initShoppingCartAdd(id, amount);
					if (!projector.getProjectorByID(id).isAvailable() && (projector.getProjectorByID(id).getAvailable() < amount)) {
						int tmp;
						cout << "1 - Купити інший товар\n2 - Вийти\n";
						cin >> tmp;
						if (tmp == 1) {
							goto check22;
						}
						else if (tmp == 2) {
							system("cls");
							cout << "Вихід у головне меню" << endl;
							cout << "-------------------------------------" << endl;
						}
					}
					else if (projector.updateProductList(id, amount)) {
						shoppingCart.addProduct(projector.getProjectorByID(id), amount);
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
			case 4:
				system("cls");
				cout << "Аксесуари для ТВ" << endl;
				tvAccessories.viewProducts("TVAccessoriesList.txt");
				cout << "-------------------------------------" << endl;
				cout << "Підменю вибору:" << endl;
				cout << "1 - Купити товар" << endl;
				cout << "2 - Вийти в підкатегорії" << endl;
				cout << "3 - Вийти в головне меню" << endl;
				cin >> pidmenu;
				switch (pidmenu)
				{
				case 1:
				check23:
					shoppingCart.initShoppingCartAdd(id, amount);
					if (!tvAccessories.getTVAccessoriesByID(id).isAvailable() && (tvAccessories.getTVAccessoriesByID(id).getAvailable() < amount)) {
						int tmp;
						cout << "1 - Купити інший товар\n2 - Вийти\n";
						cin >> tmp;
						if (tmp == 1) {
							goto check23;
						}
						else if (tmp == 2) {
							system("cls");
							cout << "Вихід у головне меню" << endl;
							cout << "-------------------------------------" << endl;
						}
					}
					else if (tvAccessories.updateProductList(id, amount)) {
						shoppingCart.addProduct(tvAccessories.getTVAccessoriesByID(id), amount);
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
			case 5:
				system("cls");
				cout << "-------------------------------------" << endl;
				cout << "Вихід у головне меню" << endl;
				break;
			}
			break;
		/*-------------------------------------------------------------*/
		/*case3end----------------------------------------------------------*/
		/*case4start----------------------------------------------------------*/
		case 4:
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "Смарт-годинники та гаджети:" << endl;
			cout << "Підкатегорії:" << endl;
			cout << "1 - Смарт-годинники" << endl;
			cout << "2 - Квадрокоптери" << endl;
			cout << "3 - 3D принтери" << endl;
			cout << "4 - Вихід з категорії" << endl;
			std::cin >> categoryChoice;
			switch (categoryChoice) {
			case 1:
				system("cls");
				cout << "Смарт-годинники" << endl;
				smartWatch.viewProducts("SmartWatchesList.txt");
				cout << "-------------------------------------" << endl;
				cout << "Підменю вибору:" << endl;
				cout << "1 - Купити товар" << endl;
				cout << "2 - Вийти в підкатегорії" << endl;
				cout << "3 - Вийти в головне меню" << endl;
				cin >> pidmenu;
				switch (pidmenu)
				{
				case 1:
				check24:
					shoppingCart.initShoppingCartAdd(id, amount);
					if (!smartWatch.getSmartWatchesByID(id).isAvailable() && (smartWatch.getSmartWatchesByID(id).getAvailable() < amount)) {
						int tmp;
						cout << "1 - Купити інший товар\n2 - Вийти\n";
						cin >> tmp;
						if (tmp == 1) {
							goto check24;
						}
						else if (tmp == 2) {
							system("cls");
							cout << "Вихід у головне меню" << endl;
							cout << "-------------------------------------" << endl;
						}
					}
					else if (smartWatch.updateProductList(id, amount)) {
						shoppingCart.addProduct(smartWatch.getSmartWatchesByID(id), amount);
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
				cout << "Квадрокоптери" << endl;
				quadrocopter.viewProducts("QuadrocoptersList.txt");
				cout << "-------------------------------------" << endl;
				cout << "Підменю вибору:" << endl;
				cout << "1 - Купити товар" << endl;
				cout << "2 - Вийти в підкатегорії" << endl;
				cout << "3 - Вийти в головне меню" << endl;
				cin >> pidmenu;
				switch (pidmenu)
				{
				case 1:
				check25:
					shoppingCart.initShoppingCartAdd(id, amount);
					if (!quadrocopter.getQuadrocopterByID(id).isAvailable() && (quadrocopter.getQuadrocopterByID(id).getAvailable() < amount)) {
						int tmp;
						cout << "1 - Купити інший товар\n2 - Вийти\n";
						cin >> tmp;
						if (tmp == 1) {
							goto check25;
						}
						else if (tmp == 2) {
							system("cls");
							cout << "Вихід у головне меню" << endl;
							cout << "-------------------------------------" << endl;
						}
					}
					else if (quadrocopter.updateProductList(id, amount)) {
						shoppingCart.addProduct(quadrocopter.getQuadrocopterByID(id), amount);
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
				cout << "3D принтери" << endl;
				printer3D.viewProducts("Printer3DList.txt");
				cout << "-------------------------------------" << endl;
				cout << "Підменю вибору:" << endl;
				cout << "1 - Купити товар" << endl;
				cout << "2 - Вийти в підкатегорії" << endl;
				cout << "3 - Вийти в головне меню" << endl;
				cin >> pidmenu;
				switch (pidmenu)
				{
				case 1:
				check26:
					shoppingCart.initShoppingCartAdd(id, amount);
					if (!printer3D.getPrinter3DByID(id).isAvailable() && (printer3D.getPrinter3DByID(id).getAvailable() < amount)) {
						int tmp;
						cout << "1 - Купити інший товар\n2 - Вийти\n";
						cin >> tmp;
						if (tmp == 1) {
							goto check26;
						}
						else if (tmp == 2) {
							system("cls");
							cout << "Вихід у головне меню" << endl;
							cout << "-------------------------------------" << endl;
						}
					}
					else if (printer3D.updateProductList(id, amount)) {
						shoppingCart.addProduct(printer3D.getPrinter3DByID(id), amount);
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
			case 4:
				system("cls");
				cout << "-------------------------------------" << endl;
				cout << "Вихід у головне меню" << endl;
				break;
			}
			break;
		/*case4end----------------------------------------------------------*/
		/*case5start----------------------------------------------------------*/
		case 5:
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "Планшети та електронні книги:" << endl;
			cout << "Підкатегорії:" << endl;
			cout << "1 - Планшети" << endl;
			cout << "2 - Електронні книги" << endl;
			cout << "3 - Вихід з категорії" << endl;
			std::cin >> categoryChoice;
			switch (categoryChoice) {
			case 1:
				system("cls");
				cout << "Планшети" << endl;
				tablet.viewProducts("TabletsList.txt");
				cout << "-------------------------------------" << endl;
				cout << "Підменю вибору:" << endl;
				cout << "1 - Купити товар" << endl;
				cout << "2 - Вийти в підкатегорії" << endl;
				cout << "3 - Вийти в головне меню" << endl;
				cin >> pidmenu;
				switch (pidmenu)
				{
				case 1:
				check27:
					shoppingCart.initShoppingCartAdd(id, amount);
					if (!tablet.getTabletByID(id).isAvailable() && (tablet.getTabletByID(id).getAvailable() < amount)) {
						int tmp;
						cout << "1 - Купити інший товар\n2 - Вийти\n";
						cin >> tmp;
						if (tmp == 1) {
							goto check27;
						}
						else if (tmp == 2) {
							system("cls");
							cout << "Вихід у головне меню" << endl;
							cout << "-------------------------------------" << endl;
						}
					}
					else if (tablet.updateProductList(id, amount)) {
						shoppingCart.addProduct(tablet.getTabletByID(id), amount);
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
				cout << "Електронні книги" << endl;
				ebook.viewProducts("EBooksList.txt");
				cout << "-------------------------------------" << endl;
				cout << "Підменю вибору:" << endl;
				cout << "1 - Купити товар" << endl;
				cout << "2 - Вийти в підкатегорії" << endl;
				cout << "3 - Вийти в головне меню" << endl;
				cin >> pidmenu;
				switch (pidmenu)
				{
				case 1:
				check28:
					shoppingCart.initShoppingCartAdd(id, amount);
					if (!ebook.getEBookByID(id).isAvailable() && (ebook.getEBookByID(id).getAvailable() < amount)) {
						int tmp;
						cout << "1 - Купити інший товар\n2 - Вийти\n";
						cin >> tmp;
						if (tmp == 1) {
							goto check28;
						}
						else if (tmp == 2) {
							system("cls");
							cout << "Вихід у головне меню" << endl;
							cout << "-------------------------------------" << endl;
						}
					}
					else if (ebook.updateProductList(id, amount)) {
						shoppingCart.addProduct(ebook.getEBookByID(id), amount);
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
				cout << "Вихід у головне меню" << endl;
				break;
			}
			break;
		/*case5end----------------------------------------------------------*/
		/*case6start----------------------------------------------------------*/
		case 6:
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "Фото та відео:" << endl;
			cout << "Підкатегорії:" << endl;
			cout << "1 - Фотокамери" << endl;
			cout << "2 - Відеокамери" << endl;
			cout << "3 - Вихід з категорії" << endl;
			std::cin >> categoryChoice;
			switch (categoryChoice) {
			case 1:
				system("cls");
				cout << "Фотокамери" << endl;
				photoCamera.viewProducts("PhotoCamerasList.txt");
				cout << "-------------------------------------" << endl;
				cout << "Підменю вибору:" << endl;
				cout << "1 - Купити товар" << endl;
				cout << "2 - Вийти в підкатегорії" << endl;
				cout << "3 - Вийти в головне меню" << endl;
				cin >> pidmenu;
				switch (pidmenu)
				{
				case 1:
				check29:
					shoppingCart.initShoppingCartAdd(id, amount);
					if (!photoCamera.getPhotoCameraByID(id).isAvailable() && (photoCamera.getPhotoCameraByID(id).getAvailable() < amount)) {
						int tmp;
						cout << "1 - Купити інший товар\n2 - Вийти\n";
						cin >> tmp;
						if (tmp == 1) {
							goto check29;
						}
						else if (tmp == 2) {
							system("cls");
							cout << "Вихід у головне меню" << endl;
							cout << "-------------------------------------" << endl;
						}
					}
					else if (photoCamera.updateProductList(id, amount)) {
						shoppingCart.addProduct(photoCamera.getPhotoCameraByID(id), amount);
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
				cout << "Відеокамери" << endl;
				videoCamera.viewProducts("VideoCamerasList.txt");
				cout << "-------------------------------------" << endl;
				cout << "Підменю вибору:" << endl;
				cout << "1 - Купити товар" << endl;
				cout << "2 - Вийти в підкатегорії" << endl;
				cout << "3 - Вийти в головне меню" << endl;
				cin >> pidmenu;
				switch (pidmenu)
				{
				case 1:
				check30:
					shoppingCart.initShoppingCartAdd(id, amount);
					if (!videoCamera.getVideoCameraByID(id).isAvailable() && (videoCamera.getVideoCameraByID(id).getAvailable() < amount)) {
						int tmp;
						cout << "1 - Купити інший товар\n2 - Вийти\n";
						cin >> tmp;
						if (tmp == 1) {
							goto check30;
						}
						else if (tmp == 2) {
							system("cls");
							cout << "Вихід у головне меню" << endl;
							cout << "-------------------------------------" << endl;
						}
					}
					else if (videoCamera.updateProductList(id, amount)) {
						shoppingCart.addProduct(videoCamera.getVideoCameraByID(id), amount);
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
				cout << "Вихід у головне меню" << endl;
				break;
			}
			break;
		/*case6end----------------------------------------------------------*/
		case 7:
			system("cls");
			cout << "-------------------------------------" << endl;
			cout << "Корзина:" << endl;
			shoppingCart.viewShoppingCart();
			break;
		case 8:
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
	cout << "8 - Вихід з програми" << endl;
	cout << "-------------------------------------" << endl;
}
