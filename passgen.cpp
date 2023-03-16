#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <num-passwords> <password-length>\n";
        return 1;
    }

    int num_passwords = std::stoi(argv[1]);
    int password_length = std::stoi(argv[2]);

    std::srand(std::time(nullptr)); // initialize random seed
    
    std::cout << "\n";

    for (int i = 0; i < num_passwords; i++) {
        for (int j = 0; j < password_length; j++) {
            char c;
            do {
                c = std::rand() % 128; // generate random ASCII character
            } while (!std::isalnum(c) && !std::ispunct(c)); // exclude non-alphanumeric/special characters

            std::cout << c;
        }

        std::cout << "\n\n";
    }

    return 0;
}

