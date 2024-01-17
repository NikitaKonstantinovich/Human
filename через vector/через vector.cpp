#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;

string MaleNames[5] = { "Александр", "Михаил", "Максим", "Артём", "Лев" };
string FemaleNames[5] = { "Софья", "Мария", "Ева", "Виктория", "Анна" };
string MaleSurnames[10] = { "Иванов", "Смирнов", "Кузнецов", "Попов", "Соколов",
						"Лебедев", "Козлов", "Новиков", "Морозов", "Петров" };
enum GenderType {
	male,   // 0 - false
	female, // 1 - true
	totalGender
};
string GenderStrings[2] = { "Male", "Female" };

struct Human {
	double mHeight{ 0 };		// member height
	double mWeight{ 0 };		// member weight
	string mName{ "" };		// member name
	string mSurname{ "" };		// member name
	GenderType mGender{ male };

	// getter and setter
	double Height() { return mHeight; }             // <--- getter

	void Height(double value) { mHeight = value; }  // <--- setter
	double Weight() { return mWeight; }             // <--- getter
	void Weight(double value) { mWeight = value; }  // <--- setter
	string Name() { return mName; }                 // <--- getter
	void Name(string value) { mName = value; }      // <--- setter
	string Surname() { return mSurname; }                 // <--- getter
	void Surname(string value) { mSurname = value; }      // <--- setter
	GenderType Gender() { return mGender; }
	void Gender(GenderType value) { mGender = value; }

	//--- string functions
	string WeightString() {
		std::ostringstream ss;
		ss << mWeight;
		return ss.str();
	}
	string HeightString() {
		std::ostringstream ss;
		ss << mHeight;
		return ss.str();
	}

	//--- conditional functions
	bool IsMale() { return mGender == male; }
	bool IsFemale() { return mGender = female; }

	//--- get string function
	string GetString() {
		// Фамилия Имя | вес: 90 кг | рост: 175 см
		string result = Surname() + " " + Name() +
			" | вес: " + WeightString() +
			" кг | рост: " + HeightString() +
			" см | пол: " + GenderStrings[Gender()];
		return result;
	}
	//--- print function
	void Print() {
		std::cout << GetString();
	}
};

Human GenerateHuman() {
	GenderType gender = rand() % 2 ? female : male; // rand() %2 вернёт либо 0 либо 1, в случае 0 будет male, 1 - female
	string name = gender == male ? MaleNames[rand() % 5] : FemaleNames[rand() % 5];
	string surname = gender == male ? MaleSurnames[rand() % 10] : MaleSurnames[rand() % 10] + "a";
	double height = rand() % 40 + 140;
	double weight = rand() % 40 + 80;

	Human human{ height, weight, name, surname, gender };
	return human;
}

void fillHumanArray(vector<Human>& humanArray, int size)
{
	for (int i = 0; i < size; i++)
		humanArray.push_back(GenerateHuman());
}

void printHumanArray(vector<Human>& humanArray)
{
	for (Human human : humanArray)
		cout << human.GetString() << endl;
}

double AverageWeight(vector<Human>& humanArray) {
	double result = 0;

	for (Human human : humanArray)
		result += human.Weight();

	result /= humanArray.size();
	return result;
}

double AverageHeight(vector<Human>& humanArray) {
	double result = 0;

	for (Human human : humanArray)
		result += human.Height();

	result /= humanArray.size();
	return result;
}

void sortArrayByHeight(vector<Human>& array)
{
	for (size_t i = 0; i < array.size() - 1; i++)
	{
		int counter = 0;
		for (size_t j = 0; j < array.size() - 1 - i; j++)
		{
			if (array[j].Height() > array[j + 1].Height())
			{
				swap(array[j], array[j + 1]);
			}
		}
		if (counter == 0) break;
	}
}

void sortArrayByWeight(vector<Human>& array)
{
	for (size_t i = 0; i < array.size() - 1; i++)
	{
		int counter = 0;
		for (size_t j = 0; j < array.size() - 1 - i; j++)
		{
			if (array[j].Weight() > array[j + 1].Weight())
			{
				swap(array[j], array[j + 1]);
			}
		}
		if (counter == 0) break; // вместо брейк можно ретёрн, тк тип войд который ничего не выводит
	}
}

int main()
{
	srand(time(0)); // <--- настройка генератора случайных чисел
	setlocale(LC_ALL, "");

	cout << "Enter amount of people: ";
	int size = 0;
	cin >> size;

	vector<Human> humanArray;

	fillHumanArray(humanArray, size);
	printHumanArray(humanArray);
	cout << "\nСредний вес: " << AverageWeight(humanArray);
	cout << "\nСредний рост: " << AverageHeight(humanArray) << endl;

	cout << "Sorted array by weight:" << endl;
	sortArrayByWeight(humanArray);
	printHumanArray(humanArray);

	cout << "Sorted array by height:" << endl;
	sortArrayByHeight(humanArray);
	printHumanArray(humanArray);
}