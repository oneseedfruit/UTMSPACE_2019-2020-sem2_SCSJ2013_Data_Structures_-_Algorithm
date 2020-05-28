#include <iostream>
#include <iomanip>
#include "Node.hpp"

void Node::DisplayNode() const
{
    std::cout << "\n---------------------------------------------\n";
    std::cout << "| Student name: " << data.name << "\n";
    std::cout << "| Matric number: " << data.matric << "\n";
    std::cout << "| Program: " << data.program << "\n";
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << "| CGPA: " << data.cgpa;
    std::cout << "\n---------------------------------------------\n";
}

void Node::DisplayNode(int tabs) const
{
    for (int i = 0; i < tabs; ++i) std::cout << "\t";
    std::cout << ">>> ---------------------------------------------\n";
    for (int i = 0; i < tabs; ++i) std::cout << "\t";
    std::cout << ">>> | Student name: " << data.name << "\n";
    for (int i = 0; i < tabs; ++i) std::cout << "\t";
    std::cout << ">>> | Matric number: " << data.matric << "\n";
    for (int i = 0; i < tabs; ++i) std::cout << "\t";
    std::cout << ">>> | Program: " << data.program << "\n";
    for (int i = 0; i < tabs; ++i) std::cout << "\t";
    std::cout << ">>> | CGPA: " << data.cgpa << "\n";
    for (int i = 0; i < tabs; ++i) std::cout << "\t";
    std::cout << ">>> ---------------------------------------------\n";
}