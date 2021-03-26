#pragma once
#include "Product.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class ShoppingCart
{
private:
	int oplata;
	int amount;
	ifstream inFile;
	fstream outFile;
public:
	ShoppingCart();

	void viewShoppingCart();
	//������� ������ ������ ������ �� ID � �������
	void initShoppingCartAdd(int& id, int& amount);
	void addProduct(Product product, int amount);
	void deleteProduct(int ID);//TODO ��������� � ������� � �������
	void clearShoppingCart();

	//������� ������� ������ � ������
	int amountCheck();
};

