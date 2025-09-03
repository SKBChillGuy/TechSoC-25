#include <iostream>
#include <string>

int n;

int encode();
int decode();

int main() {
    std::cout << "1. Encode Message" << std::endl;
    std::cout << "2. Decode Message" << std::endl;

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            encode();
            break;
        case 2:
            decode();
            break;
        default:
            std::cout << "Invalid Choice" << std::endl;
    }
    return 0;
}

int encode() {
    std::cin.ignore(); // clear newline left by previous input
    std::string name;
    std::cout << "Enter Message: " << std::endl;
    std::getline(std::cin, name);

    std::cout << "Shift Value: " << std::endl;
    std::cin >> n;

    for (int i = 0; i < name.size(); ++i) {
        if (name[i] >= 'a' && name[i] <= 'z')
            name[i] = ((name[i] - 'a' + n) % 26) + 'a';
        else if (name[i] >= 'A' && name[i] <= 'Z')
            name[i] = ((name[i] - 'A' + n) % 26) + 'A';
    }

    std::cout << "Encoded Message: " << name << std::endl;
    return 0;
}

int decode() {
    std::cin.ignore(); // clear newline
    std::string name;
    std::cout << "Enter Encoded Message: " << std::endl;
    std::getline(std::cin, name);

    std::cout << "Shift Value: " << std::endl;
    std::cin >> n;

    for (int i = 0; i < name.size(); ++i) {
        if (name[i] >= 'a' && name[i] <= 'z')
            name[i] = ((name[i] - 'a' - n + 26) % 26) + 'a';
        else if (name[i] >= 'A' && name[i] <= 'Z')
            name[i] = ((name[i] - 'A' - n + 26) % 26) + 'A';
    }

    std::cout << "Decoded Message: " << name << std::endl;
    return 0;
}
