#include "CarShowRoom.h"

AutoPart::AutoPart(int serialNumber, string name, int price, string brand, string color)
{
	this->serialNumber = serialNumber;
	this->name = name;
	this->price = price;
	this->brand = brand;
	this->color = color;
}

void AutoPart::SetAllParameters()
{
	string s;
	int n;
	cout << "Введите серийный номер(число): ";
	if(!(cin >> n)) throw exception("Нельзя вводить строку!");
	SetSerialNumber(n);

	cout << "Введите название запчасти: ";
	cin >> s;
	SetName(s);

	cout << "Введите стоимость(число): ";
	if (!(cin >> n)) throw exception("Нельзя вводить строку!");
	SetPrice(n);

	cout << "Введите брэнд: ";
	cin >> s;
	SetBrand(s);

	cout << "Введите цвет: ";
	cin >> s;
	SetColor(s);
}

void AutoPart::GetAllParameters()
{
	cout << GetSerialNumber() << " " << GetName() << " " << GetPrice() << " " << GetBrand() << " " << GetColor() << "\n";
}

void AutoPart::SetSerialNumber(int serialNumber)
{
	this->serialNumber = serialNumber;
}

void AutoPart::SetName(string name)
{
	this->name = name;
}

void AutoPart::SetPrice(int price)
{
	this->price = price;
}

void AutoPart::SetBrand(string brand)
{
	this->brand = brand;
}

void AutoPart::SetColor(string color)
{
	this->color = color;
}

int AutoPart::GetSerialNumber()
{
	return serialNumber;
}

string AutoPart::GetName()
{
	return name;
}

int AutoPart::GetPrice()
{
	return price;
}

string AutoPart::GetBrand()
{
	return brand;
}

string AutoPart::GetColor()
{
	return color;
}

CombustionEngineCar::CombustionEngineCar(int serialNumber, int price, string brand, string model, BodyType bodyType, string color,
	int year, Transmission transmissionType, int horsePower, int mileAge,
	int powerReserve, int tankVolume, string fuelType): Car(serialNumber, price, brand, model, bodyType, color, year, transmissionType, horsePower, mileAge, powerReserve), tankVolume(tankVolume), fuelType(fuelType) {};


void CombustionEngineCar::SetAllParameters()
{
	int serialNumber = 0, price = 0, nType = 0, year = 0, horsePower = 0, mileAge = 0, powerReserve = 0, tankVolume = 0;
	string brand = "", model = "", fuelType = "", color = "";
	cout << "Введите серийный номер(число): ";
	if (!(cin >> serialNumber)) throw exception("Нельзя вводить строку!");
	SetSerialNumber(serialNumber);

	cout << "Введите цену(число): ";
	if (!(cin >> price)) throw exception("Нельзя вводить строку!");
	SetPrice(price);

	cout << "Введите брэнд: ";
	cin >> brand;
	SetBrand(brand);

	cout << "Введите модель: ";
	cin >> model;
	SetModel(model);

	cout << "Тип кузова:\n1) Седан\n2) Хэчбэк\n3) Кроссовер\n4) Внедорожник\n5) Минивэн\n6) Купе\n";
	cout << "Ввод: ";
	if (!(cin >> nType)) throw exception("Нельзя вводить строку!");
	SetBodyType(nType);

	cout << "Введите цвет: ";
	cin >> color;
	SetColor(color);

	cout << "Введите год: ";
	if (!(cin >> year)) throw exception("Нельзя вводить строку!");
	SetYear(year);

	cout << "Тип трансмиссии:\n1) Механика\n2) Автомат\n3) Робот\n4) Вариатор\n";
	cout << "Ввод: ";
	if (!(cin >> nType)) throw exception("Нельзя вводить строку!");
	SetTransmissionType(nType);

	cout << "Введите кол-во л.с.: ";
	if (!(cin >> horsePower)) throw exception("Нельзя вводить строку!");
	SetHorsePower(horsePower);

	cout << "Введите пробег(км): ";
	if (!(cin >> mileAge)) throw exception("Нельзя вводить строку!");
	SetMileAge(mileAge);

	cout << "Введите запас хода(км): ";
	if (!(cin >> powerReserve)) throw exception("Нельзя вводить строку!");
	SetPowerReserve(powerReserve);

	cout << "Введите объем бака(л): ";
	if (!(cin >> tankVolume)) throw exception("Нельзя вводить строку!");
	SetTankVolume(tankVolume);

	cout << "Введите тип топлива(строка): ";
	cin >> fuelType;
	SetFuelType(fuelType);
	
	system("cls");
}

void CombustionEngineCar::GetAllParameters()
{
	cout << "_______________________________________________________________________________________________________________";
	cout << "______________________________________________________________________________________________________________\n";
	cout << "|" << GetSerialNumber() << "\t";
	cout << GetPrice() << "\t";
	cout << GetBrand() << "\t\t";
	cout << GetModel() << "\t\t";
	cout << GetBodyType() << "\t\t";
	cout << GetColor() << "\t\t";
	cout << GetYear() << "\t\t";
	cout << GetTransmissionType() << "\t";
	cout << GetHorsePower() << "\t\t";
	cout << GetMileAge() << "\t\t";
	cout << GetPowerReserve() << "\t\t";
	cout << GetTankVolume() << "\t\t";
	cout << GetFuelType() << "\t\t\t\t\t\n";
}

ElectricCar::ElectricCar(int serialNumber, int price, string brand, string model, BodyType bodyType, string color,
	int year, Transmission transmissionType, int horsePower, int mileAge,
	int powerReserve, int batteryVolume): Car(serialNumber, price, brand, model, bodyType, color, year, transmissionType, horsePower, mileAge, powerReserve), batteryVolume(batteryVolume) {};


void ElectricCar::SetAllParameters()
{
	int serialNumber = 0, price = 0, nType = 0, year = 0, horsePower = 0, mileAge = 0, powerReserve = 0, batteryVolume = 0;
	string brand = "", model = "", color = "";
	cout << "Введите серийный номер(число): ";
	if (!(cin >> serialNumber)) throw exception("Нельзя вводить строку!");
	SetSerialNumber(serialNumber);

	cout << "Введите цену(число): ";
	if (!(cin >> price)) throw exception("Нельзя вводить строку!");
	SetPrice(price);

	cout << "Введите брэнд: ";
	cin >> brand;
	SetBrand(brand);

	cout << "Введите модель: ";
	cin >> model;
	SetModel(model);

	cout << "Тип кузова:\n1) Седан\n2) Хэчбэк\n3) Кроссовер\n4) Внедорожник\n5) Минивэн\n6) Купе\n";
	cout << "Ввод: ";
	if (!(cin >> nType)) throw exception("Нельзя вводить строку!");
	SetBodyType(nType);

	cout << "Введите цвет: ";
	cin >> color;
	SetColor(color);

	cout << "Введите год: ";
	if (!(cin >> year)) throw exception("Нельзя вводить строку!");
	SetYear(year);

	cout << "Тип трансмиссии:\n1) Механика\n2) Автомат\n3) Робот\n4) Вариатор\n";
	cout << "Ввод: ";
	if (!(cin >> nType)) throw exception("Нельзя вводить строку!");
	SetTransmissionType(nType);

	cout << "Введите кол-во л.с.: ";
	if (!(cin >> horsePower)) throw exception("Нельзя вводить строку!");
	SetHorsePower(horsePower);

	cout << "Введите пробег(км): ";
	if (!(cin >> mileAge)) throw exception("Нельзя вводить строку!");
	SetMileAge(mileAge);

	cout << "Введите запас хода(км): ";
	if (!(cin >> powerReserve)) throw exception("Нельзя вводить строку!");
	SetPowerReserve(powerReserve);

	cout << "Введите объем батареи(А*ч): ";
	if (!(cin >> batteryVolume)) throw exception("Нельзя вводить строку!");
	SetBatteryVolume(batteryVolume);
}

void ElectricCar::GetAllParameters()
{
	cout << "_______________________________________________________________________________________________________________";
	cout << "______________________________________________________________________________________________________________\n";
	cout << "|" << GetSerialNumber() << "\t";
	cout << GetPrice() << "\t";
	cout << GetBrand() << "\t\t";
	cout << GetModel() << "\t\t";
	cout << GetBodyType() << "\t\t";
	cout << GetColor() << "\t\t";
	cout << GetYear() << "\t\t";
	cout << GetTransmissionType() << "\t";
	cout << GetHorsePower() << "\t\t";
	cout << GetMileAge() << "\t\t";
	cout << GetPowerReserve() << "\t\t\t\t\t\t";
	cout << GetBatteryVolume() << "\t\t\t\n";
}

HybridEngineCar::HybridEngineCar(int serialNumber, int price, string brand, string model, BodyType bodyType, string color,
	int year, Transmission transmissionType, int horsePower, int mileAge, int powerReserve,
	int tankVolume, string fuelType, int batteryVolume, HybridEngine engineType) : Car(serialNumber, price, brand, model, bodyType, color, year, transmissionType,
		horsePower, mileAge, powerReserve)
{
	this->batteryVolume = batteryVolume;
	this->tankVolume = tankVolume;
	this->fuelType = fuelType;
	this->engineType = engineType;
}

void HybridEngineCar::SetAllParameters()
{
	
	int serialNumber = 0, price = 0, nType = 0, year = 0, horsePower = 0, mileAge = 0, powerReserve = 0, batteryVolume = 0, tankVolume = 0;
	string brand = "", model = "", fuelType = "", color = "";
	cout << "Введите серийный номер(число): ";
	if (!(cin >> serialNumber)) throw exception("Нельзя вводить строку!");
	SetSerialNumber(serialNumber);

	cout << "Введите цену(число): ";
	if (!(cin >> price)) throw exception("Нельзя вводить строку!");
	SetPrice(price);

	cout << "Введите брэнд: ";
	cin >> brand;
	SetBrand(brand);

	cout << "Введите модель: ";
	cin >> model;
	SetModel(model);

	cout << "Тип кузова:\n1) Седан\n2) Хэчбэк\n3) Кроссовер\n4) Внедорожник\n5) Минивэн\n6) Купе\n";
	cout << "Ввод: ";
	if (!(cin >> nType)) throw exception("Нельзя вводить строку!");
	SetBodyType(nType);

	cout << "Введите цвет: ";
	cin >> color;
	SetColor(color);

	cout << "Введите год: ";
	if (!(cin >> year)) throw exception("Нельзя вводить строку!");
	SetYear(year);

	cout << "Тип трансмиссии:\n1) Механика\n2) Автомат\n3) Робот\n4) Вариатор\n";
	cout << "Ввод: ";
	if (!(cin >> nType)) throw exception("Нельзя вводить строку!");
	SetTransmissionType(nType);

	cout << "Введите кол-во л.с.: ";
	if (!(cin >> horsePower)) throw exception("Нельзя вводить строку!");
	SetHorsePower(horsePower);

	cout << "Введите пробег(км): ";
	if (!(cin >> mileAge)) throw exception("Нельзя вводить строку!");
	SetMileAge(mileAge);

	cout << "Введите запас хода(км): ";
	if (!(cin >> powerReserve)) throw exception("Нельзя вводить строку!");
	SetPowerReserve(powerReserve);

	cout << "Введите объем бака(л): ";
	if (!(cin >> tankVolume)) throw exception("Нельзя вводить строку!");
	SetTankVolume(tankVolume);

	cout << "Введите тип топлива(строка): ";
	cin >> fuelType;
	SetFuelType(fuelType);

	cout << "Введите объем батареи(А*ч): ";
	if (!(cin >> batteryVolume)) throw exception("Нельзя вводить строку!");
	SetBatteryVolume(batteryVolume);

	cout << "Тип гибридного двигателя:\n1) Последовательный\n2) Мягкий\n3) Параллельный\n4) Полный\n";
	cout << "Ввод: ";
	if (!(cin >> nType)) throw exception("Нельзя вводить строку!");
	SetEngineType(nType);
}

void HybridEngineCar::GetAllParameters()
{
	cout << "_______________________________________________________________________________________________________________";
	cout << "______________________________________________________________________________________________________________\n";
	cout << "|" << Car::GetSerialNumber() << "\t";
	cout << Car::GetPrice() << "\t";
	cout << Car::GetBrand() << "\t\t";
	cout << Car::GetModel() << "\t\t";
	cout << Car::GetBodyType() << "\t\t";
	cout << Car::GetColor() << "\t\t";
	cout << Car::GetYear() << "\t\t";
	cout << Car::GetTransmissionType() << "\t";
	cout << Car::GetHorsePower() << "\t\t";
	cout << Car::GetMileAge() << "\t\t";
	cout << Car::GetPowerReserve() << "\t\t";
	cout << GetTankVolume() << "\t\t";
	cout << GetFuelType() << "\t\t";
	cout << GetBatteryVolume() << "\t\t";
	cout << GetEngineType() << "\t\n";
}


Car::Car(int serialNumber, int price, string brand, string model, BodyType bodyType, string color, int year, Transmission transmissionType, int horsePower, int mileAge, int powerReserve)
{
	this->serialNumber = serialNumber;
	this->price = price;
	this->brand = brand;
	this->model = model;
	this->bodyType = bodyType;
	this->color = color;
	this->year = year;
	this->transmissionType = transmissionType;
	this->horsePower = horsePower;
	this->mileAge = mileAge;
	this->powerReserve = powerReserve;
}

Car::~Car() {};

void Car::SetPrice(int price)
{
	this->price = price;
}

int Car::GetPrice()
{
	return price;
}

void Car::SetBrand(string brand)
{
	this->brand = brand;
}

string Car::GetBrand()
{
	return brand;
}

void Car::SetSerialNumber(int serialNumber)
{
	this->serialNumber = serialNumber;
}

int Car::GetSerialNumber()
{
	return serialNumber;
}

void Car::SetModel(string model)
{
	this->model = model;
}

string Car::GetModel()
{
	return model;
}

void Car::SetBodyType(int nType)
{
	switch (nType)
	{
	case SEDAN:
		bodyType = SEDAN;
		break;
	case HATCHBACK:
		bodyType = HATCHBACK;
		break;
	case CROSSOVER:
		bodyType = CROSSOVER;
		break;
	case SUV:
		bodyType = SUV;
		break;
	case MINIVAN:
		bodyType = MINIVAN;
		break;
	case KUPE:
		bodyType = KUPE;
		break;
	default:
		break;
	}
}

string Car::GetBodyType()
{
	switch (bodyType)
	{
	case SEDAN:
		return "седан";
	case HATCHBACK:
		return "хечбэк";
	case CROSSOVER:
		return "кросс.";
	case SUV:
		return "внед.";
	case MINIVAN:
		return "минивен";
	case KUPE:
		return "купе";
	default:
		break;
	}
	return "";
}

void Car::SetColor(string color)
{
	this->color = color;
}

string Car::GetColor()
{
	return color;
}

void Car::SetYear(int year)
{
	this->year = year;
}

int Car::GetYear()
{
	return year;
}

void Car::SetTransmissionType(int nType)
{
	switch (nType)
	{
	case MANUAL:
		transmissionType = MANUAL;
		break;
	case AUTOMATIC:
		transmissionType = AUTOMATIC;
		break;
	case ROBOTIC:
		transmissionType = ROBOTIC;
		break;
	case VARIABLE:
		transmissionType = VARIABLE;
		break;
	default:
		break;
	}
}

string Car::GetTransmissionType()
{
	switch (transmissionType)
	{
	case MANUAL:
		return "механическая";
	case AUTOMATIC:
		return "автоматическая";
	case ROBOTIC:
		return "робот";
	case VARIABLE:
		return "вариатор";
	default:
		break;
	}
	return "";
}

void Car::SetHorsePower(int horsePower)
{
	this->horsePower = horsePower;
}

int Car::GetHorsePower()
{
	return horsePower;
}

void Car::SetMileAge(int mileAge)
{
	this->mileAge = mileAge;
}

int Car::GetMileAge()
{
	return mileAge;
}

void Car::SetPowerReserve(int powerReserve)
{
	this->powerReserve = powerReserve;
}

int Car::GetPowerReserve()
{
	return powerReserve;
}

void CombustionEngineCar::SetTankVolume(int tankVolume)
{
	this->tankVolume = tankVolume;
}

int CombustionEngineCar::GetTankVolume()
{
	return tankVolume;
}

void CombustionEngineCar::SetFuelType(string fuelType)
{
	this->fuelType = fuelType;
}

string CombustionEngineCar::GetFuelType()
{
	return fuelType;
}

void ElectricCar::SetBatteryVolume(int batteryVolume)
{
	this->batteryVolume = batteryVolume;
}

int ElectricCar::GetBatteryVolume()
{
	return batteryVolume;
}

void HybridEngineCar::SetEngineType(int nType)
{
	switch (nType)
	{
	case CONSISTENT:
		engineType = CONSISTENT;
		break;
	case SOFT:
		engineType = SOFT;
		break;
	case PARALLEL:
		engineType = PARALLEL;
		break;
	case FULL:
		engineType = FULL;
		break;
	default:
		break;
	}
}

string HybridEngineCar::GetEngineType()
{
	switch (engineType)
	{
	case CONSISTENT:
		return "последовательный";
	case SOFT:
		return "мягкий";
	case PARALLEL:
		return "параллельный";
	case FULL:
		return "полный";
	default:
		break;
	}
	return "";
}


