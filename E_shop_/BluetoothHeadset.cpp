#include "BluetoothHeadset.h"

string BluetoothHeadset::getBluetoothVersion()
{
    return bluetoothVersion;
}

BluetoothHeadset BluetoothHeadset::getBluetoothHeadsetByID(int id)
{
    return bluetoothHeadsetList[id - 1];
}

int BluetoothHeadset::listSizeCheck()
{
	int i = 0;
	ifstream base("BluetoothHeadsetList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів в корзині
	base.close();
	return i;
}

void BluetoothHeadset::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(13) << " Наявність" << "|";
	cout << setw(14) << "Ціна" << "|";
	cout << setw(21) << "Бренд" << "|";
	cout << setw(14) << "Тип" << "|";
	cout << setw(scale) << "Версія Bluetooth" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		bluetoothHeadsetList = new BluetoothHeadset[listSize];
		for (int i = 0; i < listSize; i++)
		{
			bluetoothHeadsetList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << bluetoothHeadsetList[i].getID() << "|";
			cout.width(scale);
			cout << bluetoothHeadsetList[i].getAvailable() << "|";
			cout.width(scale);
			cout << bluetoothHeadsetList[i].getPrice() << "|";
			cout.width(16);
			cout << bluetoothHeadsetList[i].getBrand() << "|";
			cout.width(scale);
			cout << bluetoothHeadsetList[i].getType() << "|";
			cout.width(16);
			cout << bluetoothHeadsetList[i].getBluetoothVersion() << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void BluetoothHeadset::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;
		file >> bluetoothVersion;
	}
}

bool BluetoothHeadset::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (bluetoothHeadsetList[id - 1].isAvailable() && bluetoothHeadsetList[id - 1].getAvailable() >= amount)
	{
		bluetoothHeadsetList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("BluetoothHeadsetList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << bluetoothHeadsetList[i].ID << ' ';
			outFile << bluetoothHeadsetList[i].available << ' ';
			outFile << bluetoothHeadsetList[i].price << ' ';
			outFile << bluetoothHeadsetList[i].brand << ' ';
			outFile << bluetoothHeadsetList[i].type << ' ';
			outFile << bluetoothHeadsetList[i].bluetoothVersion << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
