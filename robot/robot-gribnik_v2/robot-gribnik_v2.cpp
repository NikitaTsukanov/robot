// robot-gribnik_v2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// прототипы функций
int walk();                  // функция дойти до места сбора
int sit();                   // функция присесть
int bring();                 // функция поднести руку
int cut();                   // функция срезать
int close();                 // функция закрыть
int fault();                 // функция неисправности
int back();                  // функция вернуться домой

const int E = 15;
const int H = 10;

int main()
{
    cout << "Press 1 to turn on \n"
        "Press 0 to turn off \n";
    int a;                                       // включение
    cin >> a;
    if (a == 1)
    {
        walk();                                  // дошел до леса
        int forest[50];                          // формирование леса
        vector <int> bag_edible;                 // отсеки для съедобных и галлюциногенных в корзине
        vector <int> bag_halluc;
        int count_edible = 0, count_halluc = 0, count_poisonous = 0, count_0 = 0;          // счетчик грибов
        srand(time(NULL));
        for (int i = 0, charge = 40; i < 50; i++, charge--)
        {
            forest[i] = rand() % 4;              // заполняем лес грибами, т.е. случайными числами от 0 до 3
            switch (forest[i])                   // поиск и определение типа гриба
            {
            case 0:                              // нет гриба
                count_0++;
                cout << "Search futher\n";
                cout << "Remaining battery charge - " << charge << "\n";
                break;
            case 1:                              // нашел съедобный
                bag_edible.push_back(forest[i]);
                sit();
                bring();
                cut();
                count_edible++;
                cout << bag_edible.size() << " - number of edible mushrooms in bag" << "\n";
                close();
                cout << "Remaining battery charge - " << charge << "\n";
                break;
            case 2:                              // нашел галлюционегенный
                bag_halluc.push_back(forest[i]);
                sit();
                bring();
                cut();
                count_halluc++;
                cout << bag_halluc.size() << " - number of hallucinogenic mushrooms in bag" << "\n";
                close();
                cout << "Remaining battery charge - " << charge << "\n";
                break;
            case 3:                              // нашел ядовитый
                count_poisonous++;
                cout << "Don't touch\n";
                cout << "Remaining battery charge - " << charge << "\n";
                break;
            default:
                cout << fault();
                break;
            }
            if (charge == 0 or bag_edible.size() == E or bag_halluc.size() == H)
            {
                back();
                cout << "\n";
                cout << "The robot found and took edible mushrooms - " << count_edible << endl;
                cout << "The robot found and took hallucinogenic mushrooms -  " << count_halluc << endl;
                cout << "The robot found poisonous mushrooms -  " << count_poisonous << endl;
                cout << "The robot walked empty steps - " << count_0 << endl;
                cout << "Charge - " << charge << endl;
                return 0;
            }
        }

        back();
    }
    else if (a != 1 && a != 0)
    {
        cout << fault();
    }
    else
    {
        exit(0);
    }
}

// определение функций

int walk()
{
    cout << "walk" << endl;
    return 0;
}

int find_()
{
    cout << "find" << endl;
    return 0;
}

int sit()
{
    cout << "sit" << endl;
    return 0;
}

int bring()
{
    cout << "bring" << endl;
    return 0;
}

int cut()
{
    cout << "cut" << endl;
    return 0;
}

int close()
{
    cout << "close" << endl;
    return 0;
}

int fault()
{
    cout << "Error\n" << "Restart, please" << endl;
    exit(0);
    return 0;
}

int back()
{
    cout << "The robot has returned home" << endl;
    return 0;
}