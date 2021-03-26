#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Product
{
protected:
	long int ID;
	int available;
	float price;
	std::string brand;
	std::string type;
public:
	long getID();
	void setID(long ID);
	bool isAvailable();
	int getAvailable();
	void setAvailable(int available);
	float getPrice();
	void setPrice(float price);
	std::string getBrand();
	void setBrand(std::string brand);
	std::string getType();
	void setType(std::string type);

	//виводить таблицю товарів
	virtual void viewProducts(std::string filePath);
	//ініціалізує динамічний масив товарів за даними в файлі
	virtual void initProduct(std::ifstream& file);
	//оновлює лист товарів і повертає true якщо це вдалося і false якщо ні
	virtual bool updateProductList(int id, int amount);
};

