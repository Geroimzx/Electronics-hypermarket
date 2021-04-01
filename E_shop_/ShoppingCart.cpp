#include "ShoppingCart.h"

void ShoppingCart::viewShoppingCart()
{
	if (amountCheck() > 1)
	{
		inFile.open("ShoppingCart.txt");
		if (!inFile)
			cout << "Cannot open file" << endl;
		amountCheck();
		int scale = 10;
		cout << "|";
		cout << setw(5) << "    №" << "|";
		cout << setw(5) << "ID" << "|";
		cout << setw(14) << " Кількість" << "|";
		cout << setw(scale) << "      Ціна" << "|";
		cout << setw(scale) << "     Бренд" << "|";
		cout << setw(scale) << "Тип" << "|";
		products = new Product[amount];
		for (int i = 0; i < amount; i++)
		{
			products[i].initProduct(inFile);
			cout << "\n|";
			cout.width(5);
			cout << i+1 << "|";
			cout.width(5);
			cout << products[i].getID() << "|";
			cout.width(10);
			cout << products[i].getAvailable() << "|";
			cout.width(scale);
			cout << products[i].getPrice() << "|";
			cout.width(scale);
			cout << products[i].getBrand() << "|";
			cout.width(scale);
			cout << products[i].getType();
		}
		cout << "\n";
		inFile.close();
		amountCheck();
		cout << "Загальна сума до оплати: " << pay() << endl;
	}
	else {
		cout << "Кошик пустий\n";
	}
}

void ShoppingCart::initShoppingCartAdd(int& id, int& amount)
{
	cout << "-------------------------------------" << endl;
	cout << "Введіть ID товару:\n";
	cin >> id;
	cout << "Ведіть кількість товару:\n";
	cin >> amount;
}

void ShoppingCart::addProduct(Product product, int amount)
{
	outFile.open("ShoppingCart.txt", ios::app);
	if (!inFile) {
			cout << "Cannot open file" << endl;
	}
	else {
		int scale = 10;
		outFile.setf(ios::left);
		cout << "\n|";
		outFile << '\n';
		outFile.width(scale);
		outFile << product.getID();
		outFile.width(scale);
		outFile << amount;
		outFile.width(scale);
		outFile << product.getPrice();
		outFile.width(scale);
		outFile << product.getBrand();
		outFile.width(scale);
		outFile << product.getType();
		outFile.close();
		amountCheck();
	}
}

void ShoppingCart::deleteProduct(int number)
{
	if (amountCheck() > 0)
	{
		inFile.open("ShoppingCart.txt");
		if (!inFile) {
			cout << "Cannot open file" << endl;
		}
		else {
			amountCheck();
			products = new Product[amount];
			for (int i = 0; i < amount; i++)
			{
				products[i].initProduct(inFile);
			}
			inFile.close();
			fstream outFile("ShoppingCart.txt", ios::out);
			if (!outFile) {
				cout << "Cannot open file\n" << endl;
			}else {
				int scale = 10;
				outFile.setf(ios::left);
				for (int i = 0; i < amount; i++)
				{
					if ((i + 1) != number)
					{
						outFile << '\n';
						outFile.width(scale);
						outFile << products[i].getID();
						outFile.width(scale);
						outFile << products[i].getAvailable();
						outFile.width(scale);
						outFile << products[i].getPrice();
						outFile.width(scale);
						outFile << products[i].getBrand();
						outFile.width(scale);
						outFile << products[i].getType();
					}
				}
			}
			outFile.close();
		}
	}
	else {
		clearShoppingCart();
	}
}

void ShoppingCart::clearShoppingCart()
{
	ofstream oFile;
	oFile.open("ShoppingCart.txt", ios::out | ios::trunc);
	oFile.close();
}

int ShoppingCart::pay()
{
	if (amountCheck() > 1)
	{
		inFile.open("ShoppingCart.txt");
		if (!inFile)
			cout << "Cannot open file" << endl;
		amountCheck();
		products = new Product[amount];
		for (int i = 0; i < amount; i++)
		{
			products[i].initProduct(inFile);
			oplata += products[i].getPrice() * products[i].getAvailable();
		}
		cout << "\n";
		inFile.close();
		int tmp = oplata;
		oplata = 0;
		return tmp;
	}
	cout << "Кошик пустий\n";
	return 0;
}

int ShoppingCart::amountCheck()
{
	int i = 0;
	ifstream base("ShoppingCart.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->amount = i-1;
	base.close();
	return i;
}
