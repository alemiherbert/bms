#pragma once

#include <memory>
#include <iomanip>
#include <iostream>

#include <conio.h>
#include <windows.h>

#include "term.hpp"

namespace menu
{
    class Menu;

    class MenuItem
    {
    private:
        std::string label;

    public:
        MenuItem *prev = nullptr;
        MenuItem *next = nullptr;

        unsigned int action;
        void print(Menu *parent);
        void setLabel(const std::string &label);
        const std::string &getLabel(void);
    };

    class Menu
    {
    public:
        ~Menu(void);
        std::string name;
        MenuItem *head = nullptr;
        void addItem(const std::string label, const int action);
        void display(void);
    };

    class CustomerServiceMenu : public Menu
    {
    public:
        CustomerServiceMenu(void);
    };

    class AccountManagementMenu : public Menu
    {
    public:
        AccountManagementMenu(void);
    };

    class CardManagementMenu : public Menu
    {
    public:
        CardManagementMenu(void);
    };

    class ChequeManagementMenu : public Menu
    {
    public:
        ChequeManagementMenu(void);
    };

    class TransactionManagementMenu : public Menu
    {
    public:
        TransactionManagementMenu(void);
    };

    class ReportManagementMenu : public Menu
    {
    public:
        ReportManagementMenu(void);
    };
};

