#include <iostream>
#include <string>
#include "Class.h"

enum State
{
    Ne_Zahvachen,    // int=0; S0 - груз не захвачен
    Zahvachen,       // int=1; S1 - груз захвачен
    Kran_Podnyat_Na, // int=2; S2 - груз поднят на N метров, максимум поднимается до высоты согласно возможностям ПТМ
    Kran_Opuschen_Na // int=3; S3 - груз опущен на N метров, максимум опускается до нуля
                     //  S4, Если состояние Груз_Упал, Масса груза уменьшается на определенное число в
    // в зависимости оттого, на какой высоте z упал груз, масса которого превышает грузоподъемность
};
State st = Ne_Zahvachen;
void Latm::inputLatm(char *TypeLatmT, float MaxMassaM, int heightH, int CordX, int CordY, int CordZ, float MassaBoxM, int CordX1, int CordY1, int CordZ1)
{
    TypeLatm = new char[strlen(TypeLatmT) + 1];
    strcpy(TypeLatm, TypeLatmT);
    MaxMassa = MaxMassaM, x = CordX, y = CordY, z = CordZ, x1 = CordX1, y1 = CordY1, z1 = CordZ1, MassaBox = MassaBoxM, height = heightH;
}
void Latm::destructor()
{
    delete[] TypeLatm;
}
void Latm::SetX(int CordX)
{
    x = CordX;
}
void Latm::SetY(int CordY)
{
    y = CordY;
}
void Latm::SetZ(int CordZ)
{
    z = CordZ;
}
void Latm::SetZ1(int CordZ)
{
    z1 = CordZ;
}

void Latm::SetTypeLatm(char *TypeLatmT)
{
    delete[] TypeLatm;
    TypeLatm = new char[strlen(TypeLatmT) + 1];
    strcpy(TypeLatm, TypeLatmT);
}
void Latm::SetX1(int CordX)
{
    x1 = CordX;
}
void Latm::SetY1(int CordY)
{

    y1 = CordY;
}
void Latm::LatmTravel(int x2, int y2)
{
    if (LatmTake)
    {
        x = x2, y = y2;
        x1 = x2, y1 = y2;
    }

    else if (!LatmTake)
    {
        x = x2, y = y2;
    }
}
void Latm::LatmToBox()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    if (x == x1 && y == y1)
    {
        std::cout << "ПТМ уже впритык к грузу" << std::endl;
    }
    else
    {
        x = x1;
        y = y1;
    }
}

int Latm::GetX() const
{
    return x;
}
int Latm::GetY() const
{
    return y;
}
int Latm::GetZ() const
{
    return z;
}
int Latm::GetMassaBox() const // можно задумать, что можно узнать массу груза, если захватить его
{
    return MassaBox;
}
int Latm::GetMaxMassa() const
{
    return MaxMassa;
}
char *Latm::GetTypeLatm() const
{
    return TypeLatm;
}
int Latm::GetX1() const
{
    return x1;
}
int Latm::GetY1() const
{
    return y1;
}
int Latm::GetZ1() const
{
    return z1;
}
int Latm::GetHeight() const
{
    return height;
}
bool Latm::Proverka() const
{
    return LatmTake;
}
void Status(State st)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    switch (st)
    {
    case 0:
        std::cout << "Ne_Zahvachen" << std::endl;
        break;
    case 1:
        std::cout << "Zahvachen" << std::endl;
        break;
    case 2:
        std::cout << "Kran_Podnyat_Na" << std::endl;
        break;
    case 3:
        std::cout << "Kran_Opuschen_Na" << std::endl;
        break;
    }
}
void Latm::InfoLatm() const
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    std::cout << "Подъемно-транспортная машина : " << GetTypeLatm() << std::endl;
    std::cout << "Грузоподъемность - " << GetMaxMassa() << std::endl;
    std::cout << "Координата X - " << GetX() << std::endl;
    std::cout << "Координата Y - " << GetY() << std::endl;
    std::cout << "Максимальная высота подъема груза - " << GetHeight() << std::endl;
    std::cout << "текущее состояние  - ";
    Status(st);
    std::cout << std::endl;
    // if(состояние = Груз_Захвачен) {
    // std::cout << "Вес груза - " << GetMassa() << std::endl;
    // }
    // else {
    // std::cout << "Вес груза неизвестен"<<std::endl;
    // }
}
void Latm::InfoBox() const
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    std::cout << "Масса груза - " << GetMassaBox() << std::endl;
    std::cout << "Координата x груза - " << GetX1() << std::endl;
    std::cout << "Координата y груза - " << GetY1() << std::endl;
    // придумать, что типа из 1000 допустимой грузоподъемности осталось 843
}

void Latm::Take()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    if (GetZ() == 0 && GetZ1() == 0)
    {
        if (GetX1() != GetX() && GetY1() != GetY())
        {
            std::cout << "Захватили пустоту" << std::endl;
        }
        else if (GetX1() == GetX() && GetY1() == GetY())
        {
            std::cout << "Захватили груз" << std::endl;
            LatmTake = true;
        }
    }
    else if (GetZ() > 0 && GetZ1() == 0)
    {
        std::cout << "Чтобы что-либо захватить, нужно, чтобы высота захватчика была равна 0 "<<std::endl;
    }
}

void Latm::Put()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    if (GetZ() == 0 && GetZ1() == 0)
    {
        if (GetX1() != GetX() && GetY1() != GetY())
        {
            std::cout << "Выложили пустоту" << std::endl;
        }
        else if (GetX1() == GetX() && GetY1() == GetY())
        {
            std::cout << "Выложили груз" << std::endl;
            LatmTake = false;
        }
    }
    else if (GetZ() > 0 && GetZ1() > 0)
    {
        if (GetX1() != GetX() && GetY1() != GetY())
        {
            std::cout << "Вышвырнули пустоту" << std::endl;
        }
        else if (GetX1() == GetX() && GetY1() == GetY())
        {
            std::cout << "Вышвырнули груз" << std::endl;
            LatmTake = false;
        }
    }
}

void Latm::Up(int heightH)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    if (heightH > GetZ())
    { // если соблюдается, то значит мы поднимаем с меньшей на большую высоту
        if (!LatmTake)//st == Ne_Zahvachen
        {
            if (heightH > height)
            {
                SetZ(height);
                std::cout << "Смог поднять кран до " << height << " метров, больше не могу!" << std::endl;
            }
            else
            {
                SetZ(heightH);
                std::cout << "Поднял кран до " << heightH << " метров" << std::endl;
            }
        }
        if (LatmTake)//st == Zahvachen
        {
            if (heightH > height)
            {
                SetZ(height);
                SetZ1(height);
                std::cout << "Смог поднять груз до " << height << " метров, больше не могу!" << std::endl;
            }
            else
            {
                SetZ(heightH);
                SetZ1(heightH);
                std::cout << "Поднял груз до " << heightH << " метров" << std::endl;
            }
        }
    }
    else if (heightH == GetZ())
    {
        std::cout << "Не поднял кран, но и не опустил его" << std::endl;
    }
    else if (heightH < GetZ())
    {
        std::cout << "Ошибка! Вероятно, вы хотели опустить кран" << std::endl;
    }
}

void Latm::Down(int heightH)
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    if (heightH < GetZ())
    { // если соблюдается, значит мы опускаем с большей на меньшую высоту
        if (!LatmTake)//st == Ne_Zahvachen
        {
            if (heightH > height)
            {
                SetZ(0);
                std::cout << "Смог опустить кран  до " << height << " метров, больше не могу! Придется рыть яму!" << std::endl;
            }
            else
            {
                SetZ(height - heightH);
                std::cout << "Опустил кран до " << heightH << " метров" << std::endl;
            }
        }
        if (LatmTake)//st == Zahvachen
        {
            if (heightH > height)
            {
                SetZ(height);
                SetZ1(height);
                std::cout << "Смог опустить груз до " << height << " метров, больше не могу!" << std::endl;
            }
            else
            {
                SetZ(heightH);
                SetZ1(heightH);
                std::cout << "Опустил груз до " << heightH << " метров" << std::endl;
            }
        }
    }
    else if (heightH == GetZ())
    {
        std::cout << "Не опустил кран, но и не поднял его" << std::endl;
    }
    else if (heightH > GetZ())
    {
        std::cout << "Ошибка! Вероятно, вы хотели поднять кран" << std::endl;
    }
}

/*
x1 - получить информацию об характеристиках и текущем состоянии ПТМ
x2 - подъехать к грузу
x3 - захватить груз
x4 - поднять кран до высоты h
x5 - опустить кран до высоты h
x6 - переместиться в другие координаты x,y
x7 - положить груз

y1 - вывод информации об объекте ПТМ
y2 - ПТМ впритык к грузу
y3 - ПТМ захватил груз
y4 - ПТМ поднял кран до высоты h
y5 - ПТМ опустил кран до высоты h
y6 - ПТМ переместился из координат (x1,y1) в координаты (x2,y2) совершив путь S метров
y7 - Вывод информации о характеристике груза и его текущем положении
 */

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    Latm PTM;
    PTM.inputLatm("Loader", 200.5, 4, 0, 0, 0, 150.49, 5, 3, 0); // инициализация конструктором с 8-ю параметрами
    
    PTM.InfoLatm();
    int x1 = 1, // int=0
        x2 = 2, // int= 1
        x3 = 3, // int= 2
        x4 = 4, // int=3
        x5 = 5, // int=4
        x6 = 6, // int=5
        x7 = 7; // int=6

    int y1, // int=0
        y2, // int=1
        y3, // int=2
        y4, // int=3
        y5, // int=4
        y6, // int=5
        y7; // int=6
    bool exit = true;
    int cnt = 0;
    do
    {
        int x;

        switch (st)
        {
        case 0:
            std::cout << "Текущее состояние: ";
            Status(st);
            std::cout << std::endl;
            std::cout << "Находясь в данном состоянии вы можете ввести: " << std::endl;
            std::cout << "x3 - захватить груз" << std::endl;
            std::cout << "x2 - подъехать к грузу" << std::endl;
            std::cout << "x4 - поднять кран до высоты h" << std::endl;
            std::cout << "x5 - опустить кран до высоты h" << std::endl;
            std::cout << "x6 - переместиться в другие координаты x,y" << std::endl;
            std::cout << "Input x:";
            std::cin >> x;
            if (x == x3)
            {
                std::cout << "Текущее состояние: ";
            Status(st);

                st = Zahvachen;
                std::cout << "ПТМ использует захватчик" << std::endl;
                std::cout << "Проверка (было) груз захвачен или нет, 1 если да, 0 если нет, результат: " << PTM.Proverka() << std::endl;
                PTM.Take();
                std::cout << "Проверка (стало) груз захвачен или нет, 1 если да, 0 если нет, результат: " << PTM.Proverka() << std::endl;
            }
            else if (x == x5)
            {
                std::cout << "Текущее состояние: ";
            Status(st);

                int height;
                std::cout << "Введите высоту, до которой надо опустить захвачик, h:";
                std::cin >> height;

                
                std::cout << "ПТМ опускает кран до " << height << " метров" << std::endl;
                std::cout << "Проверка (было): высота захватчика " << PTM.GetZ() << ", высота груза " << PTM.GetZ1() << std::endl;
                PTM.Down(height);
                std::cout << "Проверка (стало): высота захватчика " << PTM.GetZ() << ", высота груза " << PTM.GetZ1() << std::endl;
                st = Kran_Opuschen_Na;
            }
            else if (x == x2)
            {
                std::cout << "Текущее состояние: ";
            Status(st);
                std::cout << "ПТМ впритык к грузу" << std::endl;
                std::cout << "Проверка (было): координаты ПТМ (" << PTM.GetX() << "," << PTM.GetY() << ")" << std::endl;
                std::cout << "Проверка (было): координаты груза (" << PTM.GetX1() << "," << PTM.GetY1() << ")" << std::endl;
                PTM.LatmToBox();
                std::cout << "Проверка (стало): координаты ПТМ (" << PTM.GetX() << "," << PTM.GetY() << ")" << std::endl;
                std::cout << "Проверка (стало): координаты груза (" << PTM.GetX1() << "," << PTM.GetY1() << ")" << std::endl;
            }
            else if (x == x4)
            {
                std::cout << "Текущее состояние: ";
            Status(st);

                int N;
                std::cout << "Введите высоту, до которой надо поднять захватчик, h:";
                std::cin >> N;
                
                std::cout << "ПТМ поднял кран до " << N << " метров" << std::endl;
                std::cout << "Проверка (было): высота захватчика" << PTM.GetZ() << ", высота груза " << PTM.GetZ1() << std::endl;
                PTM.Up(N);
                std::cout << "Проверка (стало): высота захватчика" << PTM.GetZ() << ", высота груза " << PTM.GetZ1() << std::endl;
                st = Kran_Podnyat_Na;
            }
            else if (x == x6)
            {
                std::cout << "Текущее состояние: ";
            Status(st);
                int x1, y1;
                std::cout << "Чтобы сделать перемещение, нужно ввести координаты нового положения x1,y1" << std::endl;
                std::cout << "x1:";
                std::cin >> x1;
                std::cout << "y1:";
                std::cin >> y1;
                std::cout << "ПТМ переместился из координат (" << PTM.GetX() << "," << PTM.GetY() << ") в";
                std::cout << " координаты (" << x1 << "," << y1 << std::endl;
                std::cout << "Проверка (было): координаты ПТМ (" << PTM.GetX() << "," << PTM.GetY() << ")" << std::endl;
                std::cout << "Проверка (было): координаты груза (" << PTM.GetX1() << "," << PTM.GetY1() << ")" << std::endl;
                PTM.LatmTravel(x1, y1);
                std::cout << "Проверка (стало): координаты ПТМ (" << PTM.GetX() << "," << PTM.GetY() << ")" << std::endl;
                std::cout << "Проверка (стало): координаты груза (" << PTM.GetX1() << "," << PTM.GetY1() << ")" << std::endl;
            }
            break;

        case 1:
            std::cout << "Текущее состояние: ";
            Status(st);
            std::cout << std::endl;
            std::cout << "Находясь в данном состоянии вы можете ввести: " << std::endl;
            std::cout << "x4 - поднять кран до высоты h" << std::endl;
            std::cout << "x5 - опустить кран до высоты h" << std::endl;
            std::cout << "x6 - переместиться в другие координаты x,y" << std::endl;
            std::cout << "x7 - положить груз" << std::endl;
            std::cout << "Input x:";

            std::cin >> x;
            if (x == x4)
            {
                int height;
                std::cout << "Введите высоту, до которой надо поднять захватчик, h:";
                std::cin >> height;
                
                std::cout << "ПТМ поднимает кран до " << height << " метров" << std::endl;
                std::cout << "Проверка (было): высота захватчика " << PTM.GetZ() << ", высота груза " << PTM.GetZ1() << std::endl;
                PTM.Up(height);
                std::cout << "Проверка (стало): высота захватчика " << PTM.GetZ() << ", высота груза " << PTM.GetZ1() << std::endl;
                st = Kran_Podnyat_Na;
            }
            else if (x == x5)
            {
                std::cout << "Текущее состояние: ";
            Status(st);

                int height;
                std::cout << "Введите высоту, до которой надо опустить захвачик, h:";
                std::cin >> height;

                
                std::cout << "ПТМ опускает кран до " << height << " метров" << std::endl;
                std::cout << "Проверка (было): высота захватчика" << PTM.GetZ() << ", высота груза " << PTM.GetZ1() << std::endl;
                PTM.Down(height);
                std::cout << "Проверка (стало): высота захватчика" << PTM.GetZ() << ", высота груза " << PTM.GetZ1() << std::endl;
                st = Kran_Opuschen_Na;
            }
            else if (x == x6)
            {
                std::cout << "Текущее состояние: ";
            Status(st);

                int x1, y1;
                std::cout << "Чтобы сделать перемещение, нужно ввести координаты нового положения x1,y1" << std::endl;
                std::cout << "x1:";
                std::cin >> x1;
                std::cout << "y1:";
                std::cin >> y1;
                std::cout << "Проверка (было): координаты ПТМ (" << PTM.GetX() << "," << PTM.GetY() << ")" << std::endl;
                std::cout << "Проверка (было): координаты груза (" << PTM.GetX1() << "," << PTM.GetY1() << ")" << std::endl;
                PTM.LatmTravel(x1, y1);
                std::cout << "Проверка (стало): координаты ПТМ (" << PTM.GetX() << "," << PTM.GetY() << ")" << std::endl;
                std::cout << "Проверка (стало): координаты груза (" << PTM.GetX1() << "," << PTM.GetY1() << ")" << std::endl;
            }
            else if (x == x7)
            {
                std::cout << "Текущее состояние: ";
            Status(st);

                st = Ne_Zahvachen;
                std::cout << "Проверка (было) груз положен или нет, 0 если да, 1 если нет, результат: " << PTM.Proverka() << std::endl;
                PTM.Put();
                std::cout << "Проверка (стало) груз положен или нет, 0 если да, 1 если нет, результат: " << PTM.Proverka() << std::endl;
                exit = false;
                cnt++;
            }
            break;

        case 2:
            std::cout << "Находясь в данном состоянии вы можете ввести: " << std::endl;
            std::cout << "x4 - поднять кран до высоты h" << std::endl;
            std::cout << "x7 - положить груз" << std::endl;
            std::cout << "x5 - опустить кран до высоты h" << std::endl;
            std::cout << "x6 - переместиться в другие координаты x,y" << std::endl;
            std::cout << "Input x:";

            std::cin >> x;
            if (x == x4)
            {
                std::cout << "Текущее состояние: ";
            Status(st);
                int height;
                std::cout << "Введите высоту, до которой надо поднять захватчик, h:";
                std::cin >> height;
                std::cout << "Проверка (было): высота захватчика " << PTM.GetZ() << ", высота груза " << PTM.GetZ1() << std::endl;
                PTM.Up(height);
                std::cout << "Проверка (стало): высота захватчика " << PTM.GetZ() << ", высота груза " << PTM.GetZ1() << std::endl;
            }
            else if (x == x7)
            {
                std::cout << "Текущее состояние: ";
            Status(st);

                st = Ne_Zahvachen;
                std::cout << "Проверка (было) груз положен или нет, 0 если да, 1 если нет, результат: " << PTM.Proverka() << std::endl;
                PTM.Put();
                std::cout << "Проверка (стало) груз положен или нет, 0 если да, 1 если нет, результат:  " << PTM.Proverka() << std::endl;
                exit = false;
                cnt++;
            }
            else if (x == x5)
            {
                std::cout << "Текущее состояние: ";
            Status(st);
                int height;
                std::cout << "Введите высоту, до которой надо опустить захватчик, h:";
                std::cin >> height;
                std::cout << "Проверка (было): высота захватчика " << PTM.GetZ() << ", высота груза " << PTM.GetZ1() << std::endl;
                PTM.Down(height);
                std::cout << "Проверка (стало): высота захватчика " << PTM.GetZ() << ", высота груза " << PTM.GetZ1() << std::endl;
                st = Kran_Opuschen_Na;
            }
            else if (x == x6)
            {
                std::cout << "Текущее состояние: ";
            Status(st);
                int x1, y1;
                std::cout << "Чтобы сделать перемещение, нужно ввести координаты нового положения x1,y1" << std::endl;
                std::cout << "x1:";
                std::cin >> x1;
                std::cout << "y1:";
                std::cin >> y1;
                std::cout << "ПТМ переместился из координат (" << PTM.GetX() << "," << PTM.GetY() << ") в";
                std::cout << " координаты (" << x1 << "," << y1 << ")" << std::endl;
                std::cout << "Проверка (было): координаты ПТМ (" << PTM.GetX() << "," << PTM.GetY() << ")" << std::endl;
                std::cout << "Проверка (было): координаты груза (" << PTM.GetX1() << "," << PTM.GetY1() << ")" << std::endl;
                PTM.LatmTravel(x1, y1);
                std::cout << "Проверка (стало): координаты ПТМ (" << PTM.GetX() << "," << PTM.GetY() << ")" << std::endl;
                std::cout << "Проверка (стало): координаты груза (" << PTM.GetX1() << "," << PTM.GetY1() << ")" << std::endl;
            }
            break;
        case 3:
        std::cout << "Текущее состояние: ";
            Status(st);
            std::cout << "Находясь в данном состоянии вы можете ввести: " << std::endl;
            std::cout << "x6 - переместиться в другие координаты x,y" << std::endl;
            std::cout << "x5 - опустить кран до высоты h" << std::endl;
            std::cout << "x4 - поднять кран до высоты h" << std::endl;
            std::cout << "x7 - положить груз" << std::endl;
            std::cout << "Input x:";

            std::cin >> x;
            if (x == x6)
            {
                std::cout << "Текущее состояние: ";
            Status(st);
                int x1, y1;
                std::cout << "Чтобы сделать перемещение, нужно ввести координаты нового положения x1,y1" << std::endl;
                std::cout << "x1:";
                std::cin >> x1;
                std::cout << "y1:";
                std::cin >> y1;
                std::cout << "ПТМ переместился из координат (" << PTM.GetX() << "," << PTM.GetY() << ") в";
                std::cout << " координаты (" << x1 << "," << y1 << std::endl;
                std::cout << "Проверка (было): координаты ПТМ (" << PTM.GetX() << "," << PTM.GetY() << ")" << std::endl;
                std::cout << "Проверка (было): координаты груза (" << PTM.GetX1() << "," << PTM.GetY1() << ")" << std::endl;
                PTM.LatmTravel(x1, y1);
                std::cout << "Проверка (стало): координаты ПТМ (" << PTM.GetX() << "," << PTM.GetY() << ")" << std::endl;
                std::cout << "Проверка (стало): координаты груза (" << PTM.GetX1() << "," << PTM.GetY1() << ")" << std::endl;
            }
            else if (x == x5)
            {
                std::cout << "Текущее состояние: ";
            Status(st);
                int height_;
                std::cout << "Введите высоту, до которой надо опустить захватчик, h:";
                std::cin >> height_;
                std::cout << "Проверка (было): высота захватчика " << PTM.GetZ() << ", высота груза " << PTM.GetZ1() << std::endl;
                PTM.Down(height_);
                std::cout << "Проверка (стало): высота захватчика " << PTM.GetZ() << ", высота груза " << PTM.GetZ1() << std::endl;
            }
            else if (x == x4)
            {
                std::cout << "Текущее состояние: ";
            Status(st);
                int height;
                std::cout << "Введите высоту, до которой надо поднять захватчик, h:";
                std::cin >> height;
                
                std::cout << "Проверка (было): высота захватчика " << PTM.GetZ() << ", высота груза " << PTM.GetZ1() << std::endl;
                PTM.Up(height);
                std::cout << "Проверка (стало): высота захватчика " << PTM.GetZ() << ", высота груза " << PTM.GetZ1() << std::endl;
                st = Kran_Podnyat_Na;
            }
            else if (x == x7)
            {
                std::cout << "Текущее состояние: ";
            Status(st);
                st = Ne_Zahvachen;
                std::cout << "Проверка (было) груз положен или нет, 0 если да, 1 если нет, результат: " << PTM.Proverka() << std::endl;
                PTM.Put();
                std::cout << "Проверка (стало) груз положен или нет, 0 если да, 1 если нет, результат: " << PTM.Proverka() << std::endl;
                exit = false;
                cnt++;
            }
            break;
        }

    } while (cnt != 100);

    PTM.destructor();
}
