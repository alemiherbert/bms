#pragma once
#include <iostream>
#include <iomanip>
#include <string>

namespace page
{
    enum PageList
    {
        AuthenticationPage,
        CustomeServiceMenu,
        AccountManagementMenu,
        CardManagementMenu,
        ChequeManagementMenu,
        TransactionManagementMenu,
        ReportManagementMenu,

        // Account management
        AccountOpeningPage,
        AccountDetailsPage,
        AccountTransactionsPage,
        ModifyAccountDetailsPage,
        CloseAccountPage,

        // Card Management
        ApplyNewCardPage,
        CardDetailsPage,
        ActivateCardPage,
        DeactivateCardPage,
        ReportLostStolenCardPage,

        // Cheque Management
        IssueChequePage,
        ChequeDetailsPage,
        DepositChequePage,
        CancelChequePage,

        // Transaction Management
        DepositPage,
        WithdrawPage,
        TransferFundsPage,
        TransactionHistoryPage,

        // Reports Management
        AccountStatementPage,
        TransactionReportPage,
        BalanceSummaryPage,
        Logout = 99
    };

    void printTitle(const std::string &title);

    extern unsigned int currentPage;
};