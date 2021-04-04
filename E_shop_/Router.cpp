#include "Router.h"

Router Router::getRouterByID(int id)
{
    return routerList[id - 1];
}

int Router::listSizeCheck()
{
	int i = 0;
	ifstream base("RoutersList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void Router::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(19) << "Наявність" << "|";
	cout << setw(14) << "Ціна" << "|";
	cout << setw(15) << "Бренд" << "|";
	cout << setw(9) << "Тип" << "|";
	cout << setw(scale) << "Призначення" << "|";
	cout << setw(scale) << "Частота Wi-Fi" << "|";
	cout << setw(scale) << "Макс. швидкість" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		routerList = new Router[listSize];
		for (int i = 0; i < listSize; i++)
		{
			routerList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << routerList[i].getID() << "|";
			cout.width(scale);
			cout << routerList[i].getAvailable() << "|";
			cout.width(scale);
			cout << routerList[i].getPrice() << "|";
			cout.width(scale);
			cout << routerList[i].getBrand() << "|";
			cout.width(scale);
			cout << routerList[i].getType() << "|";
			cout.width(19);
			cout << routerList[i].appointment << "|";
			cout.width(13);
			cout << routerList[i].frequency << "|";
			cout.width(15);
			cout << routerList[i].maxSpeed << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void Router::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> appointment;
		file >> frequency;
		file >> maxSpeed;
	}
}

bool Router::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (routerList[id - 1].isAvailable() && routerList[id - 1].getAvailable() >= amount)
	{
		routerList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("RoutersList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << routerList[i].ID << ' ';
			outFile << routerList[i].available << ' ';
			outFile << routerList[i].price << ' ';
			outFile << routerList[i].brand << ' ';
			outFile << routerList[i].type << ' ';

			outFile << routerList[i].appointment << ' ';
			outFile << routerList[i].frequency << ' ';
			outFile << routerList[i].maxSpeed << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
