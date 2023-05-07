#include <iostream>
#include <Windows.h>
#include "CarShowRoom.h"

using namespace std;

Car* CarChoice(ShowRoom<Car>& sr);
void Menu();
void CarShowRoomUpdate(ShowRoom<Car>& showRoom);
void AutoPartShowRoomUpdate(ShowRoom<AutoPart>& showRoom);

ostream& operator << (ostream& out, Car* obj)
{
	CombustionEngineCar* carr1 = dynamic_cast<CombustionEngineCar*>(obj);
	ElectricCar* carr2 = dynamic_cast<ElectricCar*>(obj);
	HybridEngineCar* carr3 = dynamic_cast<HybridEngineCar*>(obj);
	if (carr3 != 0)
	{
		out << obj->GetSerialNumber() << " " << obj->GetPrice() << " " << obj->GetBrand() << " ";
		out << obj->GetModel() << " " << obj->GetBodyType() << " " << obj->GetColor() << " ";
		out << obj->GetYear() << " " << obj->GetTransmissionType() << " " << obj->GetHorsePower() << " ";
		out << obj->GetMileAge() << " " << obj->GetPowerReserve() << " " << carr3->GetTankVolume() << " ";
		out << carr3->GetFuelType() << " " << carr3->GetBatteryVolume() << " " << carr3->GetEngineType();
	}
	else if (carr2 != 0)
	{
		out << obj->GetSerialNumber() << " " << obj->GetPrice() << " " << obj->GetBrand() << " ";
		out << obj->GetModel() << " " << obj->GetBodyType() << " " << obj->GetColor() << " ";
		out << obj->GetYear() << " " << obj->GetTransmissionType() << " " << obj->GetHorsePower() << " ";
		out << obj->GetMileAge() << " " << obj->GetPowerReserve() << " " << carr2->GetBatteryVolume();
	}	
	else if (carr1 != 0)
	{
		out << obj->GetSerialNumber() << " " << obj->GetPrice() << " " << obj->GetBrand() << " ";
		out << obj->GetModel() << " " << obj->GetBodyType() << " " << obj->GetColor() << " ";
		out << obj->GetYear() << " " << obj->GetTransmissionType() << " " << obj->GetHorsePower() << " ";
		out << obj->GetMileAge() << " " << obj->GetPowerReserve() << " " << carr1->GetTankVolume() << " " << carr1->GetFuelType();
	}
	return out;
}
ostream& operator << (ostream& out, AutoPart* obj)
{
	out << "_________________________________________________________________________\n";
	out << "|" << obj->GetSerialNumber() << "\t\t" << obj->GetName() << "\t\t" << obj->GetPrice() << "\t\t" << obj->GetBrand() << "\t\t";
	out << obj->GetColor() << "\t|";
	return out;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	system("mode con cols=230 lines=35");

	Car* car1 = new CombustionEngineCar(11, 100, "brand1", "model", KUPE, "color", 2002, AUTOMATIC, 400, 100001, 1000, 100, "97");
	Car* car2 = new CombustionEngineCar(11, 100, "brand1", "model", KUPE, "color", 2002, AUTOMATIC, 400, 100001, 1000, 100, "101");
	Car* car3 = new ElectricCar(2, 100, "brand2", "model", KUPE, "color", 2002, AUTOMATIC, 400, 100001, 1000, 100);
	Car* car4 = new HybridEngineCar(3, 100, "brand3", "model", KUPE, "color", 2002, AUTOMATIC, 400, 100001, 1000, 100, "99", 4, FULL);

	AutoPart* part1 = new AutoPart(1, "name1", 100, "brand1", "red");
	AutoPart* part2 = new AutoPart(2, "name2", 200, "brand2", "black");
	AutoPart* part3 = new AutoPart(3, "name3", 300, "brand3", "green");
	AutoPart* part4 = new AutoPart(4, "name4", 400, "brand4", "yellow");

	ShowRoom<Car> showRoom1 = ShowRoom<Car>();
	showRoom1.AddTop(car1);
	showRoom1.AddTop(car4);
	showRoom1.AddTop(car3);
	showRoom1.AddEnd(car2);

	ShowRoom<AutoPart> showRoom2 = ShowRoom<AutoPart>();
	showRoom2.AddTop(part1);
	showRoom2.AddTop(part2);
	showRoom2.AddTop(part3);
	showRoom2.AddEnd(part4);
	
	int n;
	while (true)
	{
		cout << "1) Car SR\n";
		cout << "2) AutoPart SR\n";
		cout << "3) Exit\n";
		cout << "Enter: ";
		cin >> n;
		system("cls");
		switch (n)
		{
		case 1:
			CarShowRoomUpdate(showRoom1);
			break;
		case 2:
			AutoPartShowRoomUpdate(showRoom2);
			break;
		case 3:
			showRoom1.RemoveAll();
			showRoom2.RemoveAll();
			return 0;
		default:
			break;
		}
	}
	return 0;
}

Car* CarChoice(ShowRoom<Car>& sr)
{
	int choice;
	Car* car = 0;
	cout << "1) ДВС \n";
	cout << "2) Электромобиль \n";
	cout << "3) Гибрид\n";
	cin >> choice;
	switch (choice)
	{
	case 1:
		car = new CombustionEngineCar();
		break;
	case 2:
		car = new ElectricCar();
		break;
	case 3:
		car = new HybridEngineCar();
		break;
	default:
		break;
	}
	return car;
}

void Menu()
{
	cout << "1) Показать всё.\n";
	cout << "2) Добавить в начало.\n";
	cout << "3) Добавить в конец.\n";
	cout << "4) Добавить в позицию.\n";
	cout << "5) Изменить.\n";
	cout << "6) Найти по серийному номеру.\n";
	cout << "7) Удалить.\n";
	cout << "8) Удалить всё.\n";
	cout << "9) Выход.\n";
	cout << "Ввод: ";
}

void CarShowRoomUpdate(ShowRoom<Car>& showRoom)
{
	int n;
	while (true)
	{
		int position = 0;
		Menu();
		cin.clear();
		cin.ignore();
		cin >> n;
		system("cls");
		switch (n)
		{
		case 1:
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 2);
			cout << "#\tЦена\tБренд\t\tМодель\t\tКузов\t\tЦвет\t\tГод\t\tКПП\t\tЛ.С.\t\tПробег\t\tЗапас хода\tОбъем бака\tТип топлива\tОбъем батареи\tТип гибрида\n";
			SetConsoleTextAttribute(hConsole, 7);
			showRoom.ShowAll();
			break;
		}
		case 2:
		{
			try
			{
				Car* car = CarChoice(showRoom);
				if (car == 0) throw exception("nullptr");
				car->SetAllParameters();
				showRoom.AddTop(car);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
				system("Pause");
			}
			break;
		}
		case 3:
		{
			try
			{
				Car* car = CarChoice(showRoom);
				car->SetAllParameters();
				showRoom.AddEnd(car);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
				system("Pause");
			}
			break;
		}
		case 4:
		{
			try
			{
				Car* car = CarChoice(showRoom);
				cout << "Введите позицию: ";
				if (!(cin >> position)) throw exception("Нельзя вводить строку!");
				system("cls");
				car->SetAllParameters();
				showRoom.AddToPosition(car, position);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
				system("Pause");
			}
			break;
		}
		case 5:
		{
			try
			{
				cout << "Введите позицию: ";
				cin >> position;
				showRoom.Change(position);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
				system("Pause");
			}
			break;
		}
		case 6:
		{
			try
			{
				int serialNumber;
				cout << "Введите серийный номер: ";
				if (!(cin >> serialNumber)) throw exception("Нельзя вводить строку!");
				showRoom.FindBySerialNumber(serialNumber);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
				system("Pause");
			}
			
			break;
		}
		case 7:
		{
			try
			{
				cout << "Введите позицию: ";
				if (!(cin >> position)) throw exception("Нельзя вводить строку!");
				showRoom.Remove(position);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
				system("Pause");
			}
			break;
		}
		case 8:
			showRoom.RemoveAll();
			break;
		case 9:
			return;
		default:
			break;
		}
	}
}

void AutoPartShowRoomUpdate(ShowRoom<AutoPart>& showRoom)
{
	int n = 0;
	while (true)
	{
		int position = 0;
		Menu();
		cin.clear();
		cin.ignore();
		cin >> n;
		system("cls");
		switch (n)
		{
		case 1:
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 2);
			cout << "#\t\tName\t\tPrice\t\tBrand\t\tColor\n";
			SetConsoleTextAttribute(hConsole, 7);
			for (int i = 0; i < showRoom.SizeOfList(); i++)
			{
				cout << showRoom[i] << endl;
			}
			cout << "\n";
			system("Pause");
			system("cls");
			break;
		}
		case 2:
		{
			try
			{
				AutoPart* part = new AutoPart();
				part->SetAllParameters();
				showRoom.AddTop(part);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
				system("Pause");
			}
			break;
		}
		case 3:
		{
			try
			{
				AutoPart* part = new AutoPart();
				part->SetAllParameters();
				showRoom.AddEnd(part);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
				system("Pause");
			}
			break;
		}
		case 4:
		{
			try
			{
				AutoPart* part = new AutoPart();
				cout << "Введите позицию: ";
				if (!(cin >> position)) throw exception("Нельзя вводить строку!");
				system("cls");
				part->SetAllParameters();
				showRoom.AddToPosition(part, position);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
				system("Pause");
			}
			break;
		}
		case 5:
		{
			try
			{
				cout << "Введите позицию: ";
				cin >> position;
				showRoom.Change(position);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
				system("Pause");
			}
			break;
		}
		case 6:
		{
			try
			{
				int serialNumber;
				cout << "Введите серийный номер: ";
				if (!(cin >> serialNumber)) throw exception("Нельзя вводить строку!");
				showRoom.FindBySerialNumber(serialNumber);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
				system("Pause");
			}
			break;
		}
		case 7:
		{
			try
			{
				cout << "Введите позицию: ";
				if (!(cin >> position)) throw exception("Нельзя вводить строку!");
				showRoom.Remove(position);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what() << endl;
				system("Pause");
			}
			break;
		}
		case 8:
			showRoom.RemoveAll();
			break;
		case 9:
			return;
		default:
			break;
		}
	}
}


