#include "Headphone.h"

string Headphone::getConnectorType()
{
	return connectorType;
}

string Headphone::getNoiseReduction()
{
	return noiseReduction;
}

string Headphone::getColor()
{
	return color;
}

Headphone Headphone::getHeadphoneByID(int id)
{
    return  headphoneList[id - 1];
}

int Headphone::listSizeCheck()
{
	int i = 0;
	ifstream base("HeadphoneList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів в корзині
	base.close();
	return i;
}

void Headphone::viewProducts(string filePath)
{
	int scale = 15;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(24) << "Наявність" << "|";
	cout << setw(19) << "Ціна" << "|";
	cout << setw(20) << "Бренд" << "|";
	cout << setw(16) << "Тип" << "|";
	cout << setw(16) << "Роз'єм" << "|";
	cout << setw(27) << "  Шумозаглушення" << "|";
	cout << setw(scale) << "Колір" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		headphoneList = new Headphone[listSize];
		for (int i = 0; i < listSize; i++)
		{
			headphoneList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << headphoneList[i].getID() << "|";
			cout.width(scale);
			cout << headphoneList[i].getAvailable() << "|";
			cout.width(scale);
			cout << headphoneList[i].getPrice() << "|";
			cout.width(scale);
			cout << headphoneList[i].getBrand() << "|";
			cout.width(24);
			cout << headphoneList[i].getType() << "|";
			cout.width(18);
			cout << headphoneList[i].getConnectorType() << "|";
			cout.width(21);
			cout << headphoneList[i].getNoiseReduction() << "|";
			cout.width(scale);
			cout << headphoneList[i].getColor() << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void Headphone::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;
		file >> connectorType;
		file >> noiseReduction;
		file >> color;
	}
}

bool Headphone::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (headphoneList[id - 1].isAvailable() && headphoneList[id - 1].getAvailable() >= amount)
	{
		headphoneList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("HeadphoneList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << headphoneList[i].ID << ' ';
			outFile << headphoneList[i].available << ' ';
			outFile << headphoneList[i].price << ' ';
			outFile << headphoneList[i].brand << ' ';
			outFile << headphoneList[i].type << ' ';
			outFile << headphoneList[i].connectorType << ' ';
			outFile << headphoneList[i].noiseReduction << ' ';
			outFile << headphoneList[i].color << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
