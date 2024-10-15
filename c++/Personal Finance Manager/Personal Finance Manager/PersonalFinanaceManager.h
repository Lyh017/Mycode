#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<map>
#include<set>
#include<fstream>
#include<sstream>

class Transaction
{
public:
	Transaction(double amount, string& date, string& category, string& description) : m_Amount(amount), m_Date(date), m_Category(category), m_Description(description){}
	double getAmount()
	{
		return this->m_Amount;
	}
	string getDate()
	{
		return this->m_Date;
	}
	string getCategory()
	{
		return this->m_Category;
	}
	string getDescription()
	{
		return this->m_Description;
	}
	void setAmount(double amount)
	{
		this->m_Amount = amount;
	}
	void setDate(string& date)
	{
		this->m_Date = date;
	}
	void setCategory(string& category)
	{
		this->m_Category = category;
	}
	void setDescription(string& description)
	{
		this->m_Description = description;
	}

private:
	double m_Amount;
	string m_Date;
	string m_Category;
	string m_Description;
};
typedef Transaction T;

class Budget
{
public:
	Budget(double limit,string& category,string& month)
		: m_Limit(limit), m_Category(category),m_Month(month) {}

	double getLimit(){ return m_Limit; }
	string getCategory(){ return m_Category; }
	string getMonth() const { return m_Month; }
	void setLimit(double limit) { m_Limit = limit; }
	void setCategory(const string& category) { m_Category = category; }
	void setMonth(const string& month) { m_Month = month; }
private:
	double m_Limit;
	string m_Category;
	string m_Month;
};
typedef Budget B;

class FinanceManager
{
public:
	void addTransaction(T& t);
	void editTransaction(int i,T& t); 
	void deleteTransaction(int i);
	void viewTransaction();
	void setBudget(B& b);
	void viewBudget();
	void budgetWarn();
	void monthlySummary(string& month);
	void categoryReport(string& category);
	void Comparsion(string& m1, string& m2);
	void loadTransactionsFromFile(string filename);
	void saveTransactionsToFile(string filename);
private:
	vector<T> transaction;
	vector<B> budget;
};
