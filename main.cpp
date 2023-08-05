#include "menu.hpp"
#include "term.hpp"
#include "page.hpp"
#include <memory>

HANDLE term::console;
COORD term::cursor;
SMALL_RECT term::windowRect;
unsigned int page::currentPage;

int main(void)
{
    SetConsoleOutputCP(CP_UTF8);
    term::console = GetStdHandle(STD_OUTPUT_HANDLE);
    term::windowRect = {0, 0, term::windowWidth, term::windowHeight};
    SetConsoleWindowInfo(term::console, TRUE, &term::windowRect);
    term::hideCursor();

    page::currentPage = 1; // Main menu
    auto customerServiceMenu = std::make_unique<menu::CustomerServiceMenu>();
    auto accountManagementMenu = std::make_unique<menu::AccountManagementMenu>();
    auto cardManagementMenu = std::make_unique<menu::CardManagementMenu>();
    auto chequeManagementMenu = std::make_unique<menu::ChequeManagementMenu>();
    auto transactionManagementMenu = std::make_unique<menu::TransactionManagementMenu>();
    auto reportManagementMenu = std::make_unique<menu::ReportManagementMenu>();

    while (true)
    {
        switch (page::currentPage)
        {
        case page::PageList::CustomeServiceMenu:
            customerServiceMenu->display();
            break;

        case page::PageList::AccountManagementMenu:
            accountManagementMenu->display();
            break;

        case page::PageList::CardManagementMenu:
            cardManagementMenu->display();
            break;

        case page::PageList::ChequeManagementMenu:
            chequeManagementMenu->display();
            break;

        case page::PageList::TransactionManagementMenu:
            transactionManagementMenu->display();
            break;

        case page::PageList::ReportManagementMenu:
            reportManagementMenu->display();
            break;

        case page::PageList::Logout:
            exit(1);
            break;
        default:
            break;
        }
    }

    auto csm = std::make_unique<menu::CustomerServiceMenu>();

    return (0);
}