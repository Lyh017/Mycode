#pragma once
#include"user.h"
#include<fstream>
#include<sstream>
using namespace std;
#define FILENAME "UserList.txt"

class socialNetwork
{
private:
	vector<User> users;

public:
	void registerUser(const string& username, const string& password)
	{
		User newUser(username, password);
		users.push_back(newUser);
	}

	User* loginUser(const string& username, const string& password)
	{
		for (vector<User>::iterator it = this->users.begin(); it != this->users.end(); it++)
		{
			if ((*it).getUsername() == username && (*it).getPassword() == password)
			{
				cout << "��¼�ɹ���" << endl;
				return &(*it);
			}
		}

		cout << "��¼ʧ�ܣ��������û����������" << endl;
		return 0;
	}

	User* findUser(const string& username)
	{
		for (vector<User>::iterator it = this->users.begin(); it != this->users.end(); it++)
		{
			if ((*it).getUsername() == username)
			{
				cout << "�ҵ��û�:" << (*it).getUsername() << endl;
				return &(*it);
			}
		}
		cout << "�����ڸ��û�" << endl;
	}

	void saveTofile()
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::out);

		for (vector<User>::iterator it = this->users.begin(); it != this->users.end(); it++)
		{
			ofs << (*it).getUsername() << (*it).getPassword() << endl;
			for (int i = 0; i < (*it).m_friend.size(); i++)
			{
				ofs << (*it).m_friend[i] << " ";
			}
			ofs << endl;
			for (int i = 0; i < (*it).m_State.size(); i++)
			{
				ofs << (*it).m_State[i] << " ";
			}
			ofs << endl;
		}
		ofs.close();

	}

	void loadFromfile()
	{
		ifstream ifs;
		ifs.open(FILENAME, ios::in);
		if (!ifs.is_open())
		{
			cout << "�ļ���ʧ��" << endl;
			return;
		}
		users.clear();
		string username, password;

		while (ifs >> username >> password)
		{
			User user(username, password);

			
			string line;
			if (getline(ifs, line)) // Read the entire line
			{
				istringstream friendsStream(line);
				string friendName;
				while (friendsStream >> friendName)
				{
					user.addFriend(friendName);
				}
			}

			// Read states
			if (getline(ifs, line)) // Read the entire line
			{
				istringstream stateStream(line);
				string state;
				while (stateStream >> state)
				{
					user.postState(state);
				}
			}

			users.push_back(user);
		}
		ifs.close();
		}
	}
};