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
	int getID();
	void setID(int ID);
	bool isAvailable();
	int getAvailable();
	void setAvailable(int available);
	float getPrice();
	void setPrice(int price);
	std::string getBrand();
	void setBrand(std::string brand);
	std::string getType();
	void setType(std::string type);

	//�������� ������� ������
	virtual void viewProducts(std::string filePath);
	//�������� ��������� ����� ������ �� ������ � ����
	virtual void initProduct(std::ifstream& file);
	//������� ���� ������ � ������� true ���� �� ������� � false ���� �
	virtual bool updateProductList(int id, int amount);
};

