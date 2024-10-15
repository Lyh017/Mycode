#define _CRT_SECURE_NO_WARNINGS
#include"PersonalFinanaceManager.h"
using namespace std;

void FinanceManager::addTransaction(T& t)
{
	transaction.push_back(t);
	system("pause");
	system("cls");
}

void FinanceManager::editTransaction(int i, T& t)
{
	if (i < transaction.size())
	{
		transaction[i] = t;
	}
	else
	{
		cout << "Invalid Operation !" << endl;
	}
	system("pause");
	system("cls");
}

void FinanceManager::deleteTransaction(int i)
{
	if (i < transaction.size())
	{
		transaction.erase(transaction.begin() + i);
	}
	else
	{
		cout << "Invalid Operation !" << endl;
	}
	system("pause");
	system("cls");
}

void FinanceManager::viewTransaction()
{
	if (transaction.empty()) {
		cout << "There are no records !" << endl;
	}
	else
	{
		for (int i = 0; i < transaction.size(); i++)
		{
			cout << i << " Amount: " << transaction[i].getAmount()
				<< ", Category: " << transaction[i].getCategory()
				<< ", Date: " << transaction[i].getDate()
				<< ", Description: " << transaction[i].getDescription() << endl;
		}
	}
	system("pause");
	system("cls");
}

void FinanceManager::setBudget(B& b)
{
	for (auto& existingBudget : budget) {
		if (existingBudget.getCategory() ==  b.getCategory() && existingBudget.getMonth() == b.getMonth()) {
			cout << "Budget for this category and month already exists." << endl;
			return;
		}
	}
	budget.push_back(b);
	system("pause");
	system("cls");
}

void FinanceManager::viewBudget()
{

	if (budget.empty()) {
		cout << "There are no records !" << endl;
		return;
	}
	else
	{
		for (auto& i : budget)
		{
			cout << "Month: " << i.getMonth() << ", Limit: " << i.getLimit() << ", Category: " << i.getCategory() << endl;
		}
	}
	system("pause");
	system("cls");
}

void FinanceManager::budgetWarn()
{
	bool anyWarning = false;
	//create a map to present the expense per month,the key is a pair which includes category and month
	map<pair<string, string>, double> monthlyExpense;
	//calculate the expense per month and add together
	for (auto& expense : transaction)
	{
		if (expense.getCategory() != "income")
		{
			string month = expense.getDate().substr(0, 7);  //select year and month YYYY-MM-DD
			string category = expense.getCategory();
			monthlyExpense[{month, category}] += expense.getAmount();
		}
	}
	for (auto& b : budget)
	{
		string month = b.getMonth();
		string category = b.getCategory();
		double limit = b.getLimit();
		auto it = monthlyExpense.find({ month,category });
		if (it != monthlyExpense.end() && it->second > limit)
		{
			anyWarning = true;
			cout << "Warning: Budget exceeded for " << category << " in " << month << ". "
				<< "Limit: " << limit << ", Spent: " << it->second << endl;
		}
	}
	if (!anyWarning)
	{
		cout << "No budget warning" << endl;
	}
	system("pause");
	system("cls");
}

void FinanceManager::monthlySummary(string& month)
{
	double total_income = 0;
	double total_expense = 0;
	map<string, double>categoryExpense;

	for (auto& i : transaction)
	{
		if (i.getDate().substr(0, 7) == month)
		{
			if (i.getCategory() == "income")
			{
				total_income += i.getAmount();
			}
			else
			{
				categoryExpense[i.getCategory()] += i.getAmount();
				total_expense += i.getAmount();
			}
		}
	}
	cout << "Monthly Summary for " << month << ":\n";
	cout << "Total Income: " << total_income << endl;
	cout << "Total Expense: " << total_expense << endl;
	cout << "Net Savings: " << total_income - total_expense << endl;

	cout << "Expenses by category: " << endl;
	for (auto& m : categoryExpense)
	{
		cout << "Category: " << m.first << " , Amount: " << m.second << endl;
	}
	system("pause");
	system("cls");
}

void FinanceManager::categoryReport(string& category)
{
	double total = 0.0;
	map<string, double> monthlyExpenses;

	for (auto& t : transaction) {
		if (t.getCategory() == category) {
			string month = t.getDate().substr(0, 7);
			monthlyExpenses[month] += t.getAmount();   //for the same category,record the expenses monthly
			total += t.getAmount();
		}
	}

	cout << "Category Report for " << category << ":\n";
	for (auto& i : monthlyExpenses) {
		cout << "Month: " << i.first << ", Amount: " << i.second << endl; //each month expense for one category
	}
	cout << "Total: " << total << endl;
	system("pause");
	system("cls");
}

void FinanceManager::Comparsion(string& m1, string& m2)
{
	set<string> existingMonths;           //check the input 
	for (auto& t : transaction) {
		existingMonths.insert(t.getDate().substr(0, 7));
	}
	if (existingMonths.find(m1) == existingMonths.end()) {
		cout << "Error: " << m1 << " does not exist in the transaction records." << endl;
		return;
	}
	if (existingMonths.find(m2) == existingMonths.end()) {
		cout << "Error: " << m2 << " does not exist in the transaction records." << endl;
		return;
	}
	double total1 = 0;
	double total2 = 0;
	map<string, double>monthlyExpense1;
	map<string, double>monthlyExpense2;
	//the first month
	for (auto& i : transaction)
	{
		if (i.getDate().substr(0, 7) == m1 && i.getCategory() != "income")
		{
			monthlyExpense1[i.getCategory()] += i.getAmount();
			total1 += i.getAmount();
		}
	}

	for (auto& i : transaction)
	{
		if (i.getDate().substr(0, 7) == m2 && i.getCategory() != "income")
		{
			monthlyExpense2[i.getCategory()] += i.getAmount();
			total2 += i.getAmount();
		}
	}

	cout << "Comparison between " << m1 << " and " << m2 << ":\n";
	cout << "Total expenses in " << m1 << ": " << total1 << endl;
	cout << "Total expenses in " << m2 << ": " << total2 << endl;

	// print each category expenses between two month
	cout << "Expenses by category in " << m1 << ":\n";
	for (auto& entry : monthlyExpense1) {
		cout << "Category: " << entry.first << ", Amount: " << entry.second << endl;
	}

	cout << "Expenses by category in " << m2 << ":\n";
	for (auto& entry : monthlyExpense2) {
		cout << "Category: " << entry.first << ", Amount: " << entry.second << endl;
	}
	system("pause");
	system("cls");
}

void FinanceManager::saveTransactionsToFile(string filename)
{
	ofstream outfile(filename);
	if (!outfile.is_open())
	{
		std::cerr << "Could not open the file: " << filename << std::endl;
		return;
	}

	for (auto& t : transaction)
	{
		outfile << t.getAmount() << ","
			<< t.getCategory() << ","
			<< t.getDate() << ","
			<< t.getDescription() << std::endl;
	}

	outfile.close();
}

void FinanceManager::loadTransactionsFromFile(string filename)
{
	ifstream infile(filename);
	if (!infile.is_open())
	{
		std::cerr << "Could not open the file: " << filename << std::endl;
		return;
	}

	string line;
	while (getline(infile, line))
	{
		istringstream ifs(line);
		string amountStr, category, date, description;

		if (getline(ifs, amountStr, ',') &&
			getline(ifs, category, ',') &&
			getline(ifs, date, ',') &&
			getline(ifs, description))
		{
			double amount = stod(amountStr);
			T transaction(amount,date,category,description);
			addTransaction(transaction);
		}
	}

	infile.close();
}
