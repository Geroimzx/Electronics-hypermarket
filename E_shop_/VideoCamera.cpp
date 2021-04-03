#include "VideoCamera.h"

VideoCamera VideoCamera::getVideoCameraByID(int id)
{
    return videoCameraList[id - 1];
}

int VideoCamera::listSizeCheck()
{
	int i = 0;
	ifstream base("VideoCamerasList.txt");
	while (!base.eof())
	{
		base.getline(new char[1024], 1024, '\n');
		i++;
	}
	this->listSize = i - 1;//підрахунок товарів
	base.close();
	return i;
}

void VideoCamera::viewProducts(string filePath)
{
	int scale = 10;
	cout << "|";
	cout << setw(scale) << "ID" << "|";
	cout << setw(12) << " Наявність" << "|";
	cout << setw(14) << "Ціна" << "|";
	cout << setw(15) << "Бренд" << "|";
	cout << setw(14) << "Тип" << "|";
	cout << setw(scale) << "Тип матриці" << "|";
	cout << setw(scale) << "Стабілізація" << "|";
	cout << setw(scale) << "Роздільна здатність" << "|";
	cout << setw(scale) << "Зум" << "|";
	cout << setw(scale) << "Сенсорний кран" << "|";
	cout << setw(scale) << "Аудіосистема" << "|";
	cout << setw(scale) << "Ємність акумулятора" << "|";
	cout << setw(scale) << "Колір" << "|";
	if (listSizeCheck() > 0)
	{
		ifstream inFile;
		inFile.open(filePath);
		if (!inFile)
			cout << "Cannot open file" << endl;
		listSizeCheck();

		videoCameraList = new VideoCamera[listSize];
		for (int i = 0; i < listSize; i++)
		{
			videoCameraList[i].initProduct(inFile);
			cout << "\n|";
			cout.width(scale);
			cout << videoCameraList[i].getID() << "|";
			cout.width(scale);
			cout << videoCameraList[i].getAvailable() << "|";
			cout.width(scale);
			cout << videoCameraList[i].getPrice() << "|";
			cout.width(scale);
			cout << videoCameraList[i].getBrand() << "|";
			cout.width(scale);
			cout << videoCameraList[i].getType() << "|";

			cout.width(11);
			cout << videoCameraList[i].matrixType << "|";
			cout.width(19);
			cout << videoCameraList[i].stabilization << "|";
			cout.width(19);
			cout << videoCameraList[i].resolution << "|";
			cout.width(7);
			cout << videoCameraList[i].opticZoom << "|";
			cout.width(15);
			cout << videoCameraList[i].sensorScreen << "|";
			cout.width(12);
			cout << videoCameraList[i].audiosystem << "|";
			cout.width(19);
			cout << videoCameraList[i].batteryCapacity << "|";
			cout.width(scale);
			cout << videoCameraList[i].color << "|";
		}
		cout << "\n";
		inFile.close();
	}
}

void VideoCamera::initProduct(std::ifstream& file)
{
	if (!file.eof())
	{
		file >> ID;
		file >> available;
		file >> price;
		file >> brand;
		file >> type;

		file >> matrixType;
		file >> stabilization;
		file >> resolution;
		file >> opticZoom;
		file >> sensorScreen;
		file >> audiosystem;
		file >> batteryCapacity;
		file >> color;
	}
}

bool VideoCamera::updateProductList(int id, int amount)
{
	listSizeCheck();
	if (videoCameraList[id - 1].isAvailable() && videoCameraList[id - 1].getAvailable() >= amount)
	{
		videoCameraList[id - 1].available -= amount;
		listSizeCheck();
		fstream outFile("VideoCamerasList.txt", ios::out);
		if (!outFile)
			cout << "Cannot open file\n" << endl;
		outFile.setf(ios::left);
		for (int i = 0; i < listSize; i++)
		{
			outFile << videoCameraList[i].ID << ' ';
			outFile << videoCameraList[i].available << ' ';
			outFile << videoCameraList[i].price << ' ';
			outFile << videoCameraList[i].brand << ' ';
			outFile << videoCameraList[i].type << ' ';

			outFile << videoCameraList[i].matrixType << ' ';
			outFile << videoCameraList[i].stabilization << ' ';
			outFile << videoCameraList[i].resolution << ' ';
			outFile << videoCameraList[i].opticZoom << ' ';
			outFile << videoCameraList[i].sensorScreen << ' ';
			outFile << videoCameraList[i].audiosystem << ' ';
			outFile << videoCameraList[i].batteryCapacity << ' ';
			outFile << videoCameraList[i].color << '\n';
		}
		outFile.close();
		return true;
	}
	else {
		cout << "Товару немає в наяності виберіть будь ласка інший товар\n";
		return false;
	}
}
