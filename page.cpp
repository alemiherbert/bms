#include "page.hpp"
#include "term.hpp"

void page::printTitle(const std::string &title)
{
    int padding = term::menuWidth - title.length() - 4;
    std::cout << "██ " << title << " ";
    for (int i = 0; i < padding; i++)
        std::cout << "█";
}