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
	float oplata;
	int amount;
	ifstream inFile;
	fstream outFile;

	Product* products;
public:
	void viewShoppingCart();
	//викликає підменю вибору товару за ID і кількістю
	void initShoppingCartAdd(int& id, int& amount);
	void addProduct(Product product, int amount);
	//видалення з корзини
	void deleteProduct(int ID);
	//очистити корзину
	void clearShoppingCart();
	//оплата товарів
	int pay();

	//повертає кількість товарів в корзині
	int amountCheck();
};

