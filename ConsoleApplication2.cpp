/*
Задача 104.

Запросить целое число n от 10 до 100.

Создать массив случайно сгенерированных людей размером n.

Найти средний вес людей этого массива.
Найти средний рост этого массива. (изменено)
[20:17]
Задача 105.

Вывести список всех людей по росту по возрастанию.
Вывести список всех людей по весу по возрастанию.
*/
#include<iostream>
#include<string>
#include<sstream>
#include<ctime>
using namespace std;

string MaleNames[5] = { "Александр", "Михаил", "Максим", "Артём", "Лев" };
string FemaleNames[5] = { "Софья", "Мария", "Ева", "Виктория", "Анна" };
string MaleSurnames[10] = { "Иванов", "Смирнов", "Кузнецов", "Попов", "Соколов", "Лебедев", "Козлов", "Новиков", "Морозов", "Петров" };

enum GenderType
{
    male,
    female,
    totalGender
};

string GenderString[2] = { "male", "famale" };

struct Human
{
    double mHeight{ 0 };   // member height
    double mWeight{ 0 };   // member weight
    string mName{ "" };    // member name
    string mSurname{ "" }; // member surname
    GenderType mGender{ male };// member gender


    // getter and setter
    double Height() { return mHeight; }
    string HeightString() { ostringstream ss; ss << mHeight; return ss.str(); }
    void Height(double value) { mHeight = value; }

    double Weight() { return mWeight; }
    void Weight(double value) { mWeight = value; }
    string WeightString() { ostringstream ss; ss << mWeight; return ss.str(); };

    string Name() { return mName; }
    void Name(string value) { mName = value; }

    string Surname() { return mSurname; }
    void Surname(string value) { mSurname = value; }

    GenderType Gender() { return mGender; }
    void Genger(GenderType value) { mGender = value; }

    // conditional function
    bool IsMale() { return mGender == male; }
    bool IsFemale() { return mGender = female; }

    // get string function
    string GetString()
    {
        // Name Surname | gender: *** | weight: *** kg | height: *** m
        string result = mName + " " + mSurname + " | gender: " + GenderString[Gender()] + " | weight: " + WeightString() + " kg | height: " + HeightString() + " cm";
        return result;
    }

    // print function
    void PrintString()
    {
        cout << GetString();
    }
};

Human GenerateHuman()
{
    GenderType gender = rand() % 2 ? male : female;
    string name = gender == male ? MaleNames[rand() % 5] : FemaleNames[rand() % 5];
    string surname = gender == male ? MaleSurnames[rand() % 10] : MaleSurnames[rand() % 10] + "a";
    double height = rand() % 40 + 150;
    double weight = rand() % 40 + 80;

    Human human{ height, weight, name, surname, gender };
    return human;
}

void fillHumanArray(Human* humanArray,int n)
{
    for (size_t i = 0; i < n; i++)
    {
        humanArray[i] = GenerateHuman();
    }
}

void printHumanArray(Human* humanArray, int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << humanArray[i].GetString() << endl;
    }
}

double findAverageWeight(Human* humanArray, int n)
{
    double sumWeight = 0;
    for (size_t i = 0; i < n; i++)
    {
        sumWeight += humanArray[i].mWeight;
    }
    return sumWeight / (n + 1);
}

double findAverageHeight(Human* humanArray, int n)
{
    double sumHeight = 0;
    for (size_t i = 0; i < n; i++)
    {
        sumHeight += humanArray[i].mHeight;
    }
    return sumHeight / (n + 1);
}

void printSortedHumanArrayByHeight(Human* humanArray, int n)
{
    Human temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (humanArray[j].mHeight > humanArray[j + 1].mHeight)
            {
                temp = humanArray[j];
                humanArray[j] = humanArray[j + 1];
                humanArray[j + 1] = temp;
            }
        }
    }
    cout << "Sorting by Height: " << endl;
    
    for (size_t i = 0; i < n; i++)
    {
        cout << humanArray[i].GetString() << endl;
    }
}

void printSortedHumanArrayByWeight(Human* humanArray, int n)
{
    Human temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (humanArray[j].mWeight > humanArray[j + 1].mWeight)
            {
                temp = humanArray[j];
                humanArray[j] = humanArray[j + 1];
                humanArray[j + 1] = temp;
            }
        }
    }
    cout << "Sorting by Weight: " << endl;

    for (size_t i = 0; i < n; i++)
    {
        cout << humanArray[i].GetString() << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    srand(time(0));
    int n = 10;
    cout << "enter a number from 10 to 100: ";
    cin >> n;
    Human* humanArrray;
    humanArrray = new Human[n];
    fillHumanArray(humanArrray, n);
    printHumanArray(humanArrray, n);
    cout << "Awerage weight: " << findAverageWeight(humanArrray, n) << endl;
    cout << "Awerage height: " << findAverageHeight(humanArrray, n) << endl;
    printSortedHumanArrayByHeight(humanArrray, n);
    printSortedHumanArrayByWeight(humanArrray, n);
}