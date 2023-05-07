#pragma once
#include <iostream>
#include <string>

using namespace std;

enum BodyType{ NaN1, SEDAN, HATCHBACK, CROSSOVER, SUV, MINIVAN, KUPE };
enum Transmission { NaN2, MANUAL, AUTOMATIC, ROBOTIC, VARIABLE };
enum HybridEngine { NaN3, CONSISTENT, SOFT, PARALLEL, FULL };

class AutoPart final
{
	int serialNumber;
	string name;
	int price;
	string brand;
	string color;
public:
	AutoPart* next = 0;
	AutoPart* prev = 0;
	AutoPart(int serialNumber, string name, int price, string brand, string color);
	AutoPart() { serialNumber = 0; name = "-"; price = -1; brand = "-"; color = "-"; }
	void SetAllParameters();
	void GetAllParameters();

	void SetSerialNumber(int serialNumber);
	void SetName(string name);
	void SetPrice(int price);
	void SetBrand(string brand);
	void SetColor(string color);

	int GetSerialNumber();
	string GetName();
	int GetPrice();
	string GetBrand();
	string GetColor();

	friend ostream& operator << (ostream& out, AutoPart* obj);
};


class Car
{
protected:
		int serialNumber;
		int price;
		string brand;
		string model;
		BodyType bodyType;
		string color;
		int year;
		Transmission transmissionType;
		int horsePower;
		int mileAge;
		int powerReserve;
public:
		Car* next = 0;
		Car* prev = 0;
		Car(int serialNumber, int price, string brand, string model, BodyType bodyType, string color,
			int year, Transmission transmissionType, int horsePower, int mileAge, int powerReserve);
		Car() { serialNumber = 0, price = 0, brand = "-", model = "-", bodyType = NaN1, color = "-", year = 0, transmissionType = NaN2, horsePower = 0, mileAge = 0, powerReserve = 0; }
		virtual ~Car() = 0;
		virtual void GetAllParameters() = 0;
		virtual void SetAllParameters() = 0;

		void SetSerialNumber(int serialNumber);
		void SetPrice(int price);
		void SetBrand(string brand);
		void SetModel(string model);
		void SetBodyType(int nType);
		void SetColor(string color);
		void SetYear(int year);
		void SetTransmissionType(int nType);
		void SetHorsePower(int horsePower);
		void SetMileAge(int mileAge);
		void SetPowerReserve(int powerReserve);

		int GetSerialNumber();
		int GetPrice();
		string GetBrand();
		string GetModel();
		string GetBodyType();
		string GetColor();
		int GetYear();
		string GetTransmissionType();
		int GetHorsePower();
		int GetMileAge();
		int GetPowerReserve();

		friend ostream& operator << (ostream& out, Car* obj);
};

class CombustionEngineCar : public virtual Car
{
protected:
	int tankVolume;
	string fuelType;
public:
	CombustionEngineCar(int serialNumber, int price, string brand, string model, BodyType bodyType, string color,
						int year, Transmission transmissionType, int horsePower, int mileAge, 
						int powerReserve, int tankVolume, string fuelType);
	CombustionEngineCar() : Car() { tankVolume = 0; fuelType = ""; }
	~CombustionEngineCar() override {};
	void GetAllParameters() override;
	void SetAllParameters() override;
	void SetTankVolume(int tankVolume);
	int GetTankVolume();
	void SetFuelType(string fuelType);
	string GetFuelType();
};

class ElectricCar : public virtual Car
{
protected:
	int batteryVolume;
public:
	ElectricCar(int serialNumber, int price, string brand, string model, BodyType bodyType, string color,
		int year, Transmission transmissionType, int horsePower, int mileAge,
		int powerReserve, int batteryVolume);
	ElectricCar() : Car() { batteryVolume = 0; }
	~ElectricCar() override {};
	void GetAllParameters() override;
	void SetAllParameters() override;
	void SetBatteryVolume(int batteryVolume);
	int GetBatteryVolume();
};

class HybridEngineCar final: public CombustionEngineCar, public ElectricCar
{
private:
	HybridEngine engineType;
public:
	HybridEngineCar(int serialNumber, int price, string brand, string model, BodyType bodyType, string color,
		int year, Transmission transmissionType, int horsePower, int mileAge, int powerReserve, 
		int tankVolume, string fuelType, int batteryVolume, HybridEngine engineType);
	HybridEngineCar() : Car() { tankVolume = 0; fuelType = ""; batteryVolume = 0; engineType = NaN3; };
	~HybridEngineCar() override {};
	void GetAllParameters() override;
	void SetAllParameters() override;
	void SetEngineType(int nType);
	string GetEngineType();
};


template<class T>
class ShowRoom
{
private:
	T* head = 0;
public:
	int SizeOfList();
	void ShowAll();
	void AddTop(T* newNode);
	void AddEnd(T* newNode);
	void AddToPosition(T* newNode, int position);
	void Change(int position);
	void Remove(int position);
	void FindBySerialNumber(int serialNumber);
	void RemoveAll();

	T* operator[] (int index);
};


template<class T>
int ShowRoom<T>::SizeOfList()
{
	T* current = head;
	int i = 0;
	do
	{
		i++;
		current = current->next;
	} while (current != head);
	return i;
}

template<class T>
void ShowRoom<T>::ShowAll()
{
	T* current = head;
	if (current == 0)
	{
		cout << "Список пуст" << endl;
	}
	else
	{
		do
		{
			current->GetAllParameters();
			current = current->next;
		} while (current != head);
	}
	system("Pause");
	system("cls");
}

template<class T>
void ShowRoom<T>::AddTop(T* newNode)
{
	if (newNode == 0) return;
	if (head == 0)
	{
		head = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
	}
	else
	{
		newNode->prev = head->prev;
		newNode->next = head;
		head->prev->next = newNode;
		head->prev = newNode;
		head = newNode;
	}
	system("cls");
}

template<class T>
void ShowRoom<T>::AddEnd(T* newNode)
{
	if (newNode == 0) return;
	if (head == 0)
	{
		head = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
	}
	else
	{
		newNode->prev = head->prev;
		newNode->next = head;
		head->prev->next = newNode;
		head->prev = newNode;
	}
	system("cls");
}

template<class T>
void ShowRoom<T>::AddToPosition(T* newNode, int position)
{
	if (newNode == 0) return;
	if (position <= SizeOfList() && position != 0)
	{
		T* temp = head, * previous = head;
		while (--position)
		{
			previous = temp;
			temp = temp->next;
		}
		if (temp == previous) AddTop(newNode);
		else
		{
			newNode->next = temp;
			newNode->prev = previous;
			previous->next = newNode;
			temp->prev = newNode;
		}
		system("cls");
	}
	else
	{
		if (position == SizeOfList() + 1) AddEnd(newNode);
		else cout << "Out of range!" << endl;
	}
}

template<class T>
void ShowRoom<T>::Change(int position)
{
	if (position <= SizeOfList() && position != 0)
	{
		T* temp = head;
		while (--position) temp = temp->next;

		temp->SetAllParameters();
		system("cls");
	}
	else
	{
		cout << "Out of range!\n\n";
	}
}

template<class T>
void ShowRoom<T>::Remove(int position)
{
	if (position <= SizeOfList() && position != 0)
	{
		if (position == 1)
		{
			if (SizeOfList() == 1)
			{
				cout << "Deleting: "; head->GetAllParameters();
				system("Pause");
				delete head;
				head = 0;
				return;
			}
			T* temp = head;
			temp = temp->next;
			temp->prev = head->prev;
			head->prev->next = temp;
			//cout << "Deleting: "; head->GetAllParameters();
			//system("Pause");
			delete head;
			head = temp;
			//system("cls");
			return;
		}
		T* temp = head, * previous = head;
		while (--position)
		{
			previous = temp;
			temp = temp->next;
		}
		previous->next = temp->next;
		temp->next->prev = previous;
		//cout << "Deleting: "; temp->GetAllParameters();
		//system("Pause");
		delete temp;
		//system("cls");
	}
	else
	{
		cout << "Out of range!\n\n";
	}
}

template<class T>
void ShowRoom<T>::FindBySerialNumber(int serialNumber)
{
	T* current = head;
	if (current == 0)
	{
		cout << "Список пуст" << endl;
	}
	else
	{
		do
		{
			if (current->GetSerialNumber() == serialNumber)
			{
				cout << "Найдена машина: ";
				current->GetAllParameters();
			}
			current = current->next;
		} while (current != head);
	}
	system("Pause");
	system("cls");
}

template<class T>
void ShowRoom<T>::RemoveAll()
{
	if (head == 0)
	{
		cout << "Список пуст.\n";
		return;
	}
	T* prev = head;
	T* current = head;
	do
	{
		current = head->next;
		head->prev->next = current;
		current->prev = head->prev;
		//cout << "Deleting: "; head->GetAllParameters();
		delete(head);
		head = current;
	} while (head->next != head);
	//cout << "Deleting: "; head->GetAllParameters();
	delete head;
	head = 0;
	if (head == 0)
	{
		cout << "List '" << typeid(T).name() << "' deleted" << endl;
	}
}

template<class T>
T* ShowRoom<T>::operator[] (int index)
{
	index++;
	T* current = head;
	while (--index)
	{
		current = current->next;
	}
	return current;
}


