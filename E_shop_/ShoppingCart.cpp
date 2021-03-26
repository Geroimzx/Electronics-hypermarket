#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
	amount = 0;
	oplata = 0;
}

void ShoppingCart::viewShoppingCart()
{
	if (amountCheck() > 0)
	{
		inFile.open("ShoppingCart.txt");
		if (!inFile)
			cout << "Cannot open file" << endl;
		amountCheck();
		int scale = 10;
		cout << "|";
		cout << setw(scale) << "ID" << "|";
		cout << setw(scale) << "Кількість" << "|";
		cout << setw(scale) << "Ціна" << "|";
		cout << setw(scale) << "Бренд" << "|";
		cout << setw(scale) << "Тип" << "|";
		Product* products = new Product[amount];
		for (int i = 0; i < amount; i++)
		{
			products[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << products[i].getID() << "|";
			cout.width(scale);
			cout << products[i].getAvailable() << "|";
			cout.width(scale);
			cout << products[i].getPrice() << "|";
			cout.width(scale);
			cout << products[i].getBrand() << "|";
			cout.width(scale);
			cout << products[i].getType() << "|";
		}
		cout << "\n";
		inFile.close();
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

void ShoppingCart::deleteProduct(int ID)
{
}

void ShoppingCart::clearShoppingCart()
{
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
