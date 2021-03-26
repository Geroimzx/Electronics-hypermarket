#include "PortableSpeakers.h"

int PortableSpeakers::getOutputPower()
{
    return outputPower;
}

int PortableSpeakers::getBateryLife()
{
    return batteryLife;
}

PortableSpeakers PortableSpeakers::getPortableSpeakersByID(int id)
{
    return portableSpeakersList[id-1];
}

int PortableSpeakers::listSizeCheck()
{
	int i = 0;
	ifstream base("PortableSpeakersList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів в корзині
	base.close();
	return i;
}

void PortableSpeakers::viewProducts(string filePath)
{
	int scale = 15;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(scale) << "Наявність" << "|";
	cout << setw(scale) << "Ціна" << "|";
	cout << setw(scale) << "Бренд" << "|";
	cout << setw(scale) << "Тип" << "|";
	cout << setw(scale) << "Потужність" << "|";
	cout << setw(scale) << "Час роботи" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		portableSpeakersList = new PortableSpeakers[listSize];
		for (int i = 0; i < listSize; i++)
		{
			portableSpeakersList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << portableSpeakersList[i].getID() << "|";
			cout.width(scale);
			cout << portableSpeakersList[i].getAvailable() << "|";
			cout.width(scale);
			cout << portableSpeakersList[i].getPrice() << "|";
			cout.width(scale);
			cout << portableSpeakersList[i].getBrand() << "|";
			cout.width(scale);
			cout << portableSpeakersList[i].getType() << "|";
			cout.width(scale);
			cout << portableSpeakersList[i].getOutputPower() << "|";
			cout.width(scale);
			cout << portableSpeakersList[i].getBateryLife() << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void PortableSpeakers::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;
		file >> outputPower;
		file >> batteryLife;
	}
}

bool PortableSpeakers::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (portableSpeakersList[id - 1].isAvailable() && portableSpeakersList[id - 1].getAvailable() >= amount)
	{
		portableSpeakersList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("PortableSpeakersList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << portableSpeakersList[i].ID << ' ';
			outFile << portableSpeakersList[i].available << ' ';
			outFile << portableSpeakersList[i].price << ' ';
			outFile << portableSpeakersList[i].brand << ' ';
			outFile << portableSpeakersList[i].type << ' ';
			outFile << portableSpeakersList[i].outputPower << ' ';
			outFile << portableSpeakersList[i].batteryLife << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
