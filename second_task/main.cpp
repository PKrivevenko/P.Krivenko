#include <iostream>
#include <cmath>
using namespace std;
class figures{
public:
    figures(){}
    virtual double getS() = 0;
    virtual double getP() = 0;
    ~figures(){}
};



class Ellipse : public figures{
private:
    double a;
    double b;
public:
    Ellipse(double a, double b){
        this->a = a;
        this->b = b;
    }
    double getP(){
        return (4 * (acos(-1) * a * b + (a - b))) / (a + b);
    }
    double getS(){
        return acos(-1) * a * b;
    }
};

class circle : public Ellipse{
private:
    double r;
public:
    circle(double r) : Ellipse(r, r){
        this->r = r;
    }

};



class Quadrilateral : public figures{
private:
    double d1, d2, sina, a, b, c, d;
public:
    Quadrilateral(double d1, double d2, double sina, double a, double b, double c, double d){
        this->d1 = d1;
        this->d2 = d2;
        this->sina = sina;
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
    double getP(){
        return a + b + c + d;
    }
    double getS(){
        return 0.5 * d1 * d2 * sina;
    }
};

class rectangle : public Quadrilateral{
public:
    rectangle(double a, double b) : Quadrilateral(sqrt(a * a + b * b), sqrt(a * a + b * b), (2 * a * b) / (a*a+b*b), a, b, a, b){

    }

};

class square : public rectangle{
public:

    square(double a) : rectangle(a, a){
    }
};

class triangle : public figures{
private:
    double a;
    double b;
    double c;
public:
    triangle(double a, double b, double c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    double getP() override{
        return a + b + c;
    }
    double getS() override{
        double p = (a + b + c) / 2;
        return pow(p*(p - a)*(p - b)*(p - c), 0.5);
    }
};



int main() {
    figures* a[6];
    Ellipse ellipse(10, 5);
    a[0] = &ellipse;
    circle circle(7);
    a[1] = &circle;
    triangle triangle(3, 4, 5);
    a[2] = &triangle;
    Quadrilateral quadrilateral(2, 7, 1, 12, 1, 4, 9);
    a[3] = &quadrilateral;
    rectangle rectangle(4, 10);
    a[4] = &rectangle;
    square square(15);
    a[5] = &square;

    for(int i = 0; i < 6; i++){
        cout << "The perimeter of this figure is " << a[i]->getP() << ". The square of this figure is " << a[i]->getS() << endl;
    }
    for(int i = 0; i < 6; i++){
        delete []a[i];
    }

    return 0;
}
