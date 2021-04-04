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
		cout << setw(19) << "Кількість" << "|";
		cout << setw(14) << "Ціна" << "|";
		cout << setw(20) << "Бренд" << "|";
		cout << setw(22) << "Тип";
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
			cout.width(15);
			cout << products[i].getBrand() << "|";
			cout.width(26);
			cout << products[i].getType();
		}
		cout << "\n";
		inFile.close();
		amountCheck();
		cout << "Загальна сума до оплати: " << checkOplata() << endl;
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
		outFile << '\n' << product.getID() << ' ';
		outFile << amount << ' ';
		outFile << product.getPrice() << ' ';
		outFile << product.getBrand() << ' ';
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
				outFile.setf(ios::left);
				for (int i = 0; i < amount; i++)
				{
					if ((i + 1) != number)
					{
						outFile << products[i].getID() << ' ';
						outFile << products[i].getAvailable() << ' ';
						outFile << products[i].getPrice() << ' ';
						outFile << products[i].getBrand() << ' ';
						outFile << products[i].getType() << '\n';
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

int ShoppingCart::checkOplata()
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
				oplata += products[i].getPrice() * products[i].getAvailable();
			}
			cout << "\n";
			inFile.close();
		}
		int tmp = oplata;
		oplata = 0;
		return tmp;
	}
	cout << "Кошик пустий\n";
	return 0;
}

int ShoppingCart::pay()
{
	if (amountCheck() > 1)
	{
		inFile.open("ShoppingCart.txt");
		fstream admFile;
		admFile.open("ShoppingCartAdminList.txt", ios::app);
		if (!inFile || !admFile) {
			cout << "Cannot open file" << endl;
		}
		else {
			// current date/time based on current system
			time_t now = time(0);
			// convert now to string form
			char* _Buffer = new char[50];
			ctime_s(_Buffer, 50, &now);
			string dt = _Buffer;
			admFile << dt << '\n';
			amountCheck();
			products = new Product[amount];
			for (int i = 0; i < amount; i++)
			{
				products[i].initProduct(inFile);
				admFile << products[i].getID() << ' ';
				admFile << products[i].getAvailable() << ' ';
				admFile << products[i].getPrice() << ' ';
				admFile << products[i].getBrand() << ' ';
				admFile << products[i].getType() << '\n';
				oplata += products[i].getPrice() * products[i].getAvailable();
			}
			admFile << "Загальна сума: " << oplata << '\n';
			cout << "\n";

		}
		inFile.close();
		admFile.close();
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
