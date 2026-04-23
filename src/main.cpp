#include <iostream>
#include <string>

struct User
{
    std::string name;
    int age;
    std::string street;
};

void printUser(const User& user)
{
    std::cout << "Name: " << user.name << std::endl;
    std::cout << "Age: " << user.age << std::endl;
    std::cout << "Street: " << user.street << std::endl << std::endl;
}

int main()
{
    User user1{ "Tomas Marny", 33, "Sikma 5" };
    User user2{ "Josef Novy", 28, "Ve Svahu 8" };

    printUser(user1);
    printUser(user2);

    return 0;
}
