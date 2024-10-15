#pragma once
#include"PersonalFinanaceManager.h"
#include<sstream>
class userInterface
{
public:
	void menu()
	{
		cout << "------Welcome to Personal Finance Manager------" << endl;
		cout << "      1.Add Transaction" << endl;
		cout << "      2.Edit Transaction" << endl;
		cout << "      3.Delete Transaction" << endl;
		cout << "      4.View Transaction" << endl;
		cout << "      5.Set Budget " << endl;
		cout << "      6.View Budget" << endl;
		cout << "      7.Budget Warning" << endl;
		cout << "      8.Monthly Summary" << endl;
		cout << "      9.Category Report" << endl;
		cout << "     10.Compare Two Month" << endl;
		cout << "     11. Load Transactions from File" << endl;
		cout << "     12. Save Transactions to File" << endl;
		cout << "      0.Exit" << endl;
	}

	void handleUserInterface(FinanceManager& fm)
	{
		int choice = 0;
		do
		{
			menu();
			cout << "Enter your choice:";
			cin >> choice;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			switch (choice)
			{
			case 1:
			{
				double amount = getInputDouble("Enter amount: ");
				string category = getInputString("Enter category (income/expense): ");
				string date = getInputString("Enter date (YYYY-MM-DD): ");
				string description = getInputString("Enter description: ");
				T t(amount, date, category, description);
				fm.addTransaction(t);
				break;
			}
			case 2:
			{
				size_t index = getInputSizeT("Enter transaction number(from 0) to edit: ");
				double amount = getInputDouble("Enter amount: ");
				string category = getInputString("Enter category (income/expense): ");
				string date = getInputString("Enter date (YYYY-MM-DD): ");
				string description = getInputString("Enter description: ");
				T t(amount, date, category, description);
				fm.editTransaction(index,t);
				break;
			}
			case 3:
			{
				
				size_t index = getInputSizeT("Enter transaction number(from 0) to delete: ");
				fm.deleteTransaction(index);
				break;
			}
			case 4:
			{
				fm.viewTransaction();
				break;
			}
			case 5:
			{
				double limit = getInputDouble("Enter budget limit: ");
				string category = getInputString("Enter budget category: ");
				string month = getInputString("Enter budget month (YYYY-MM): ");
				B b(limit, category, month);
				fm.setBudget(b);
				break;
			}
			case 6:
			{
				fm.viewBudget();
				break;
			}
			case 7:
			{
				fm.budgetWarn();
				break;
			}
			case 8:
			{
				string month = getInputString("Enter the month for summary (YYYY-MM): ");
				fm.monthlySummary(month);
				break;
			}
			case 9:
			{
				string category = getInputString("Enter the category for report: ");
				fm.categoryReport(category);
				break;
			}
			case 10:
			{
				string m1 = getInputString("Enter the first month for comparing (YYYY-MM): ");
				string m2 = getInputString("Enter the second month for comparing (YYYY-MM): ");
				fm.Comparsion(m1, m2);
				break;
			}
			case 11:
			{
				cout << "Transactions loaded from file." << endl;
				fm.loadTransactionsFromFile("transactions.txt");
				break;
			}
			case 12:
			{
				fm.saveTransactionsToFile("transactions.txt");
				cout << "Transactions saved to file." << endl;
				break;
			}
			case 0:
			{
				cout << "Exit......" << endl;
				break;
			}
			default:
			{
				cout << "Invalid choice. Please try again.\n";
				break;
			}
			}

		} while (choice != 0);
	}

private:
	double getInputDouble(const string& prompt) {
		double value;
		cout << prompt;
		while (!(cin >> value)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. " << prompt;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return value;
	}

	string getInputString(const string& prompt) {
		string value;
		cout << prompt;
		getline(cin, value);
		return value;
	}
	size_t getInputSizeT(const string& prompt) {
		size_t value;
		cout << prompt;
		cin >> value; 
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			cout << "Invalid input. Please enter a non-negative integer." << endl;
			return getInputSizeT(prompt); 
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return value;
	}


};