#include <iostream>
#include <cmath>
using namespace std;
//КР 2021, 1-я
//        Задан следующий класс точки в трёхмерном пространстве:

class Point
{
protected:
    double _x;
    double _y;
    double _z;

public:
    Point(double x, double y, double z): _x(x), _y(y), _z(z) {
    }

    double x() const {
        return _x;
    }

    double y() const {
        return _y;
    }

    double z() const {
        return _z;
    }
};
//Реализуйте класс, задающий сферу. Прототип класса:

class Sphere
{
private:
    double center_x;
    double center_y;
    double center_z;
    double R;
public:
    // Конструктор сферы с центром в точке center и радиусом r
    Sphere(const Point& center, double r){
        center_x = center.x();
        center_y = center.y();
        center_z = center.z();
        R = r;
    }

    // Проверка, попадает ли заданная точка p в данную сферу.
    // (Расстояния сравнивать с точностью 1e-6.)
    bool covers(const Point& p) const{
        if(abs((pow((p.x() - center_x), 2) + pow((p.y() - center_y), 2),  pow((p.z() - center_z), 2)) - pow(R, 2)) < 0.000001){
            return true;
        }
        else{
            return false;
        }
    }
};
//Для тестирования можете использовать следующий базовый пример:

int main() {
    // Создаём сферу
    Point center(10.0, 10.0, 10.0);
    Sphere s(center, 0.5);

// Создаём пару тестовых точек
    Point p1(10.1, 10.1, 10.1);
    Point p2(2, 2, 2);

// Ожидаем, что первая точка внутри сферы
    cout << boolalpha << s.covers(p1) << endl;
// Ожидаем, что вторая точка не попала внутрь сферы
    cout << boolalpha << s.covers(p2) << endl;
    //Данный пример должен вывести:

    //true
    //false
    //return 0;
}
