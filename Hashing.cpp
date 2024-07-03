#include<iostream>
#include<list>
using namespace std;
# define size 5

list<int> hashtable[size];

int hashfunc(int x)
{
	return x % size;
}

void insert(int key)
{
	int index = hashfunc(key);
	hashtable[index].push_back(key);
}

void delete_key(int key)
{
	list<int>::iterator i;
	int index = hashfunc(key);
	for (i=hashtable[index].begin(); i!=hashtable[index].end();i++)
	{
		if (*i == key)
		{
			break;
		}
	}
	if (i != hashtable[index].end())
	{
		hashtable[index].erase(i);
		cout << "Key " << key << " deleted" << endl;
	}
	else
	{
		cout << "Key " << key << " not found" << endl;
	}
}

void display()
{
	for (int i = 0; i < size; i++)
	{
		cout << i;
		for (auto x : hashtable[i])
		{
			cout << " -> " << x;
		}
		cout << endl;
	}
}

void main()
{
	int hash_array[size] = { 11, 12, 21, 14, 15 };
	int key;

	for (int i = 0; i < size; i++)
	{
		insert(hash_array[i]);
	}

	cout << "hashtable created: " << endl;

	display();

	cout << endl;

	cout << "enter no to delete: ";
	cin >> key;

	delete_key(key);

	cout << "hashtable after deletion: ";

	cout << endl;

	display();
}