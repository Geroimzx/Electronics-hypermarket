#include "Product.h"

long Product::getID()
{
	return ID;
}

void Product::setID(long ID)
{
	this->ID = ID;
}

bool Product::isAvailable()
{
	if (available > 0)
		return true;
	return false;
}

int Product::getAvailable()
{
	return available;
}

void Product::setAvailable(int available)
{
	this->available = available;
}

float Product::getPrice()
{
	return price;
}

void Product::setPrice(float price)
{
	this->price = price;
}

std::string Product::getBrand()
{
	return brand;
}

void Product::setBrand(std::string brand)
{
	this->brand = brand;
}

std::string Product::getType()
{
	return type;
}

void Product::setType(std::string type)
{
	this->type = type;
}

void Product::viewProducts(std::string filePath)
{
}

void Product::initProduct(std::ifstream& file)
{
	file >> ID;
	file >> available;
	file >> price;
	file >> brand;
	file >> type;
}

bool Product::updateProductList(int id, int amount)
{
	return true;
}

