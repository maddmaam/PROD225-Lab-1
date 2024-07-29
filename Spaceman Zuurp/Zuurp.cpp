#include "Zuurp.h"

#include <iostream>

Zuurp::Zuurp()
{
}

Zuurp::~Zuurp() = default;

void Zuurp::Start()
{
    std::cout << "+---------------------------------------------------------+" << '\n';
    std::cout << '\n' << "                           " << R"(\_/)" << '\n';
    std::cout << "                           " << "(\")" << '\n';
    std::cout << "                         " << "---+---" << '\n';
    std::cout << "                          " << R"(_/ \_)" << '\n';
    std::cout << '\n' << "+---------------------------------------------------------+" << '\n';
}

void Zuurp::GenerateSecretWord()
{
}
