#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <random>
// Простая функция преобразования,
int xform(int i) {
    return i*i; // квадрат исходного значения
}

int main() {
    //1. создать вектор
    std::vector<int> P1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //2. добавить n элементов из cin
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        std::cin >> a;
        P1.push_back(a);
    }

    //3. перемешать P1
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(P1.begin(), P1.end(), g);


    //4. удалить повторно идущие дубликаты
    auto last = std :: unique ( P1.begin ( ) , P1.end ( ) );
    P1.erase ( last, P1.end ( ) ) ;

    //5. посчитать количество нечетых
    int count_div4 = std::count_if(P1.begin(), P1.end(), [](int a){
        return a % 2 != 0;
    });
    std::cout <<"5. count of ungerade numbers is "<<  count_div4 << std::endl;

    //6. определить min(v), max(v) в P1
    std::cout<<"6. Min element in P1 is " << *std::min_element(P1.begin(), P1.end()) << std::endl;
    std::cout<<"6. Max element in P1 is " << *std::max_element(P1.begin(), P1.end()) << std::endl;

    //8. заменить числа их квадратами
    std::transform(P1.begin(), P1.end(),  P1.begin(), xform);

    //9. создать последовательность P2 из N случайных чисел, где N - длина P1
    int N = P1.size();
    std::vector<int> P2(N);

    std::uniform_int_distribution<> dis(1, 10); // создаем распределение std::vector<int> list2 (list.size()); //сделал вектор
    std::generate(P2.begin(), P2.end(), std::bind(dis, std::ref(g))); //алгоритм наполняющий вектор

    //10. Вычислить сумму чисел в P2
    auto sum = std::accumulate(P2.begin(), P2.end(), 0);
    std::cout << "10. Sum of P2 is " << sum << std::endl;

    //11. Заменить первые k чисел в P2 числом 1
    int k;
    std::cin >> k;
    std::replace_if (P2.begin(), P2.end() - P2.size() + k, [&k](int a){
        return (1);
        },1);

    //12. создать P3 как разность P1 и P2
    std::vector<int>P3(P1.size());
    for(auto i = 0; i < P3.size(); i++){
        P3[i] = P1[i] - P2[i];
    }

    //13.  Заменить каждый отрицательный элемент в P3 нулем
    std::replace_if (P3.begin(), P3.end(), [](int a){
        return (a < 0);
    },0);

    //14. Удалить полностью все нулевые элементы из P3
    auto l = std::remove(P3.begin(), P3.end(), 0);
    P3.erase(l, P3.end());

    //15.Изменить порядок следования элементов в ПЗ на обратный
    std::reverse(P3.begin(), P3.end());

    //16. Определить быстро топ-3 наибольших элемента в ПЗ

    //17. Отсортировать полностью П1 и П2 по возрастанию
    std::sort(P1.begin(), P1.end());
    std::sort(P2.begin(), P2.end());

    //18. Создать последовательность П4 как слияние П1 и П2
    std::vector<int>P4(P1.size() + P2.size());
    std::merge(P1.begin(), P1.end(), P2.begin(), P2.end(), P4.begin());
    //20. вывести последовательности в cout
    for(auto it = std::begin(P1); it != std::end(P1); it++) {
        std::cout << *it << ' ';
    }
    std::cout<<std::endl;
    for(auto it = std::begin(P2); it != std::end(P2); it++) {
        std::cout << *it << ' ';
    }
    std::cout<<std::endl;
    for(auto it = std::begin(P3); it != std::end(P3); it++) {
        std::cout << *it << ' ';
    }
    std::cout<<std::endl;
    for(auto it = std::begin(P4); it != std::end(P4); it++) {
        std::cout << *it << ' ';
    }
    // 1. iota -(not used iota)
    // 3. shuffle ? +
    // 4. unique + .erase (удаление последовательных дубликатов) +
    // 5. count_if +
    // 7. find_if -
    // 8. transform +
    // 9. generate_n + rand() +
    // 11. replace_if +
    // 12. transform -(not used transform)
    // 13. replace_if +
    // 14. remove + erase +
    // 15. reverse +
    // 16. partial_sort | nth_element
    // 17. sort +
    // 18. merge -- для отсортированных +
    // 19. equal_range -- для отсортированных - 
    return 0;
}
