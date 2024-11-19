#include <iostream>
#include <fstream>
#include <vector>
#include <locale>

// Комментарии пишу для себя что бы было понятно что где происходит.
// Спасибо большое заранее.
class Address{

private:
std::string citi{}, street{};
int house{}, apartment{};

public:
// Конструкторы класс
    Address() {}
    Address(std::string set_citi, std::string set_street, int set_house, int set_appartment): citi(set_citi), street(set_street), house(set_house), apartment(set_appartment){ }

std::string get_stirng_Address(){
    return citi + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment)+ "\n";
}
};
int main() {

setlocale(LC_ALL, "Russian");

// to do Объявление константных переменных
const std::string PATH_FILE_SOUCE= "./source_text.txt";
const std::string PATH_FILE_OUT = "./out.txt";
const int SIZI_STRING_CONTAINER = 3;

// блок чтения из файла
std::ifstream fin(PATH_FILE_SOUCE);
int cout_container;
fin >> cout_container;
// std::cout << cout_container;

std::vector <Address*> ContainerAddress;

// Блок объявление временных переменных
std::string set_citi{}, set_street{};
int set_house{}, set_appartment{};

// Считываем данные из файла во временные переменые и сразу конструируем объекты
for (int i = 0; i < cout_container; i++)
{
    fin >> set_citi; fin >> set_street; fin >> set_house; fin >> set_appartment;
    ContainerAddress.push_back(new Address(set_citi, set_street, set_house, set_appartment));
}

// Закрываем ранее открытый файл
fin.close();

// Записывае данные в файл
std::ofstream fop(PATH_FILE_OUT);
fop << cout_container << "\n";

for (int i = ContainerAddress.size()-1; i >= 0; i--)
{
    fop << ContainerAddress[i]->get_stirng_Address();
    // std::cout << ContainerAddress[i]->get_stirng_Address()<< std::endl;
}

// for (int i = 0; i < ContainerAddress.size(); i++)
// {
//     fop << ContainerAddress[i]->get_stirng_Address();
//     std::cout << ContainerAddress[i]->get_stirng_Address();
// }
fop.close();

// Освобождаем ранее занятую память
for (int i = 0; i < ContainerAddress.size(); i++)
{
    delete ContainerAddress[i];
}

return 0;
}