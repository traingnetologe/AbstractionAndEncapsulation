#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
// ���������� ����� ���� ������� ����������, ��� �� �� ������ ��������������
#include <algorithm>

// ����������� ���� ��� ���� ��� �� ���� ������� ��� ��� ����������.
// ������� ������� �������.
class Address{

private:
std::string citi{}, street{};
int house{}, apartment{};

public:
// ������������ �����
    Address() {}
    Address(std::string set_citi, std::string set_street, int set_house, int set_appartment): citi(set_citi), street(set_street), house(set_house), apartment(set_appartment){ }

std::string get_stirng_Address(){
    return citi + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment)+ "\n";
}

std::string get_siti(){
    return citi;
}
};
// ���� � ����������� ��� � ���� ���� ���������� ������� ����� ���������� ������
int Comparison_Class_Address(Address* oneAddress, Address* twoAddress){
    return oneAddress->get_stirng_Address().compare(twoAddress->get_stirng_Address());
}
int main() {

setlocale(LC_ALL, "Russian");

// to do ���������� ����������� ����������
const std::string PATH_FILE_SOUCE= "./source_text.txt";
const std::string PATH_FILE_OUT = "./out.txt";
const int SIZI_STRING_CONTAINER = 3;

// ���� ������ �� �����
std::ifstream fin(PATH_FILE_SOUCE);
int cout_container;
fin >> cout_container;
// std::cout << cout_container;

std::vector <Address*> ContainerAddress;

// ���� ���������� ��������� ����������
std::string set_citi{}, set_street{};
int set_house{}, set_appartment{};

// ��������� ������ �� ����� �� ��������� ��������� � ����� ������������ �������
for (int i = 0; i < cout_container; i++)
{
    fin >> set_citi; fin >> set_street; fin >> set_house; fin >> set_appartment;
    ContainerAddress.push_back(new Address(set_citi, set_street, set_house, set_appartment));
}

// ��������� ����� �������� ����
fin.close();
// sorted vector for citi

std::sort(ContainerAddress.begin(), ContainerAddress.end(), [](Address* oneObject, Address* towObject){
    return oneObject->get_siti() > towObject->get_siti();
});

// ��������� ������ � ����
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

// ����������� ����� ������� ������
for (int i = 0; i < ContainerAddress.size(); i++)
{
    delete ContainerAddress[i];
}

return 0;
}