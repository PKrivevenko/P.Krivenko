#include <iostream>
#include <vector>
using namespace std;

//КР 2021, 2-я
//Копилка
class MoneyBox {
private:
    vector <unsigned int> a;
public:
    MoneyBox(){}

    // Добавить монетку достоинством value
    void addCoin(unsigned int value){
        a.push_back(value);
    }

    // Получить текущее количество монеток в копилке
    unsigned int getCoinsNumber() const{
        int k = 0;
        for(auto i : a){
            k++;
        }
        return k;
    }

    // Получить текущее общее достоинство всех монеток
    unsigned int getCoinsValue() const{
        int sum = 0;
        for(int i = 0; i < a.size(); i++){
            sum += a[i];
        }
        return sum;
    }
};


int main() {
    MoneyBox m;
// Добавили монетку достоинством 10
    m.addCoin(10);
// Добавили монетку достоинством 5
    m.addCoin(5);

// Ожидаем, что монеток внутри 2 штуки
    cout << m.getCoinsNumber() << endl;
// Ожидаем, что общее достоинство всех монеток 15
    cout << m.getCoinsValue() << endl;
    //Данный пример должен вывести:
   // 2
   // 15
    return 0;
}
