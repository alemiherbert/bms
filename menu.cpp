#include "menu.hpp"
#include "page.hpp"


void menu::MenuItem::print(Menu *parent)
{
    unsigned int line = 5;
    MenuItem *head = parent->head;

    do
    {
        term::moveCursor(term::margin, line);
        if (this == head)
        {
            term::setTextHighlight();
            std::cout << " ■ " << std::left << std::setw(term::menuWidth - 3) << head->getLabel() << "\n";
        }
        else
        {
            term::setTextNormal();
            std::cout << " ■ " << std::left << std::setw(term::menuWidth - 3) << head->getLabel() << "\n";
        }
        term::setTextNormal();
        head = head->next;
        line++;
    } while (head != parent->head);
}

void menu::MenuItem::setLabel(const std::string &label)
{
    this->label = label;
}

const std::string &menu::MenuItem::getLabel(void)
{
    return this->label;
}

menu::Menu::~Menu(void)
{
    MenuItem *nextItem, *currentItem = this->head;
    do
    {
        nextItem = currentItem->next;
        delete currentItem;
        currentItem = nextItem;
    } while(currentItem != this->head);
}

void menu::Menu::display(void)
{
    MenuItem *head = this->head;
    if (!head)
        return;

    int key;
    system("cls");
    term::moveCursor(term::margin, 3);
    page::printTitle(this->name);
    term::moveCursor(term::margin, 5);
    do
    {
        head->print(this);
        key = getch();
        switch (key)
        {
        case term::keyUp:
            head = head->prev;
            if (head->next == this->head)
                head = this->head->prev;
            break;
        case term::keyDown:
            head = head->next;
            if (head == this->head)
                head = this->head;
            break;
        }
    } while (key != term::keyEnter);
    page::currentPage = head->action;
}

void menu::Menu::addItem(const std::string label, const int action)
{
    MenuItem *item = new MenuItem;

    if (this->head)
    {
        MenuItem *tail = this->head->prev;
        tail->next = item;
        item->prev = tail;
        item->next = this->head;
        this->head->prev = item;
    }
    else
    {
        this->head = item;
        item->next = item;
        item->prev = item;
    }

    item->setLabel(label);
    item->action = action;
}

menu::CustomerServiceMenu::CustomerServiceMenu(void)
{
    this->name = "CUSTOMER SERVICE";
    this->addItem("Account Management", page::PageList::AccountManagementMenu);
    this->addItem("Cards Management", page::PageList::CardManagementMenu);
    this->addItem("Cheque Management", page::PageList::ChequeManagementMenu);
    this->addItem("Transaction Management", page::PageList::TransactionManagementMenu);
    this->addItem("Reports Management", page::PageList::ReportManagementMenu);
    this->addItem("Logout", page::PageList::Logout);
}


menu::AccountManagementMenu::AccountManagementMenu(void)
{
    this->name = "ACCOUNTS MANAGEMENT";
    this->addItem("Open new account", page::PageList::AccountOpeningPage);
    this->addItem("View account details", page::PageList::AccountDetailsPage);
    this->addItem("View account transactions", page::PageList::AccountTransactionsPage);
    this->addItem("Modify account details", page::PageList::ModifyAccountDetailsPage);
    this->addItem("Close account", page::PageList::CloseAccountPage);
    this->addItem("Back", page::PageList::CustomeServiceMenu);
}

menu::CardManagementMenu::CardManagementMenu(void)
{
    this->name = "CARD MANAGEMENT";
    this->addItem("Apply for new card", page::PageList::ApplyNewCardPage);
    this->addItem("View card details", page::PageList::CardDetailsPage);
    this->addItem("Activate card", page::PageList::ActivateCardPage);
    this->addItem("Deactivate card", page::PageList::DeactivateCardPage);
    this->addItem("Report lost or stolen card", page::PageList::ReportLostStolenCardPage);
    this->addItem("Back", page::PageList::CustomeServiceMenu);
}

menu::ChequeManagementMenu::ChequeManagementMenu(void)
{
    this->name = "CHEQUE MANAGEMENT";
    this->addItem("Issue New Cheque", page::PageList::IssueChequePage);
    this->addItem("View Cheque Details", page::PageList::ChequeDetailsPage);
    this->addItem("Deposit Cheque", page::PageList::DepositChequePage);
    this->addItem("Cancel Cheque", page::PageList::CancelChequePage);
    this->addItem("Back", page::PageList::CustomeServiceMenu);
}


menu::TransactionManagementMenu::TransactionManagementMenu(void)
{
    this->name = "TRANSACTION MANAGEMENT";
    this->addItem("Deposit", page::PageList::DepositPage);
    this->addItem("Withdraw", page::PageList::WithdrawPage);
    this->addItem("Transfer Funds", page::PageList::TransferFundsPage);
    this->addItem("View Transaction History", page::PageList::TransactionHistoryPage);
    this->addItem("Back", page::PageList::CustomeServiceMenu);
}

menu::ReportManagementMenu::ReportManagementMenu(void)
{
    this->name = "REPORT MANAGEMENT";
    this->addItem("Generate Account Statement", page::PageList::AccountStatementPage);
    this->addItem("Generate Transaction Report", page::PageList::TransactionReportPage);
    this->addItem("Generate Balance Summary", page::PageList::BalanceSummaryPage);
    this->addItem("Back", page::PageList::CustomeServiceMenu);
}





