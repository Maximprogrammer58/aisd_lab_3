#include "../include/Sorting.h"
#include "../include/Analytics.h"
#include "../include/User.h"


int main() {
    Stats stats;

    std::vector<std::string> strings = { "c", "c++", "python", "js", "java", "sql", "pascal", "go", "kotlin" };
    std::cout << strings;
    stats = insertionSorting(strings);
    std::cout << strings;
    std::cout << stats;

    std::vector<int> vec = generateRandomVector(-100, 100, 20);
    std::cout << vec;
    stats = quickSorting(vec);
    std::cout << vec;
    std::cout << stats;

    std::vector<User> users = { User("Max", 19), User("Oleg", 28), User("Max", 21), User("Marina", 18), User("Angelina", 19) };
    std::cout << users;
    stats = naturialTwoWayMergeSorting(users);
    std::cout << users;
    std::cout << stats;
    
    return 0;
}