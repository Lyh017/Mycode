#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"socialNetwork.h"
using namespace std;

class socialNetwork;
class User
{

	friend class socialNetwork;
public:

	User(string username, string password)
	{
		this->m_userName = username;
		this->m_Password = password;
	}

	void addFriend(const string& friendName)
	{
		this->m_friend.push_back(friendName);
	}

	void postState(const string& state)
	{
		this->m_State.push_back(state);
	}
	void viewFriend()
	{
		if (this->m_friend.empty())
		{
			cout << "还没有好友，快去添加" << endl;
		}
		else
		{
			cout << "好友:" << endl;
			for (vector<string>::iterator it = this->m_friend.begin(); it != this->m_friend.end(); it++)
			{
				cout << *it << " ";
			}
			cout << endl;
		}
		
	}

	void viewState()
	{
		if (this->m_State.empty())
		{
			cout << "没有最新状态，请先更新" << endl;
		}
		else
		{
			vector<string>::iterator it = this->m_State.end() - 1;
			cout << "最新的状态:" << *it << endl;
		}
		
	}

	string getUsername()
	{
		return this->m_userName;
	}

	string getPassword()
	{
		return this->m_Password;
	}
private:
	string m_userName;
	string m_Password;
	vector<string> m_friend;
	vector<string> m_State;
};

