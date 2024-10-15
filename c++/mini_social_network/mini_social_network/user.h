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
			cout << "��û�к��ѣ���ȥ���" << endl;
		}
		else
		{
			cout << "����:" << endl;
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
			cout << "û������״̬�����ȸ���" << endl;
		}
		else
		{
			vector<string>::iterator it = this->m_State.end() - 1;
			cout << "���µ�״̬:" << *it << endl;
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

