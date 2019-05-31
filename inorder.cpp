#include "inorder.h"
#include "mini.h"
using namespace std;
#include "mini.cpp"
mini m;


inorder::inorder()
{
}


inorder::~inorder()
{
}
void  inorder::input_graph()
{
	ways.clear();
	cout << 'Please Enter number of citys: ' << endl;
	cin >> m.ncity;
	cout << endl;
	for (int i = 0; i < m.ncity; i++)
	{
		cout << 'Please Enter the start city:' << endl;
		cin >> m.start;
		m.it = ways.find(m.start);
		if (m.it != ways.end()) {
			cout << 'this city already exists in the graph"'<< endl;
			m.ncity++;
		}
		else
		{
			cout << 'Enter The connected citys and the weghit/if you finish press 0 0 : ' << endl;
			while (true)
			{
				cin >> m.endw.first >> m.endw.second;
				if (m.endw.first == "0"&&m.endw.second == 0) { break; }
				m.inf.push_back(m.endw);
			}
			ways[m.start] = m.inf;
			m.inf.erase(m.inf.begin(), m.inf.end());
		}
	}
}
void  inorder::add_graph()
{
	ways.clear();
	for (int i = 1; i <= 7; i++)
	{
		if (i == 1)
		{
			m.endw.first = "b";
			m.endw.second = 2;
			m.inf.push_back(m.endw);
			m.endw.first = "c";
			m.endw.second = 5;
			m.inf.push_back(m.endw);
			ways["a"] = m.inf;
			m.inf.clear();
		}
		else if (i == 2)
		{
			m.endw.first = "a";
			m.endw.second = 2;
			m.inf.push_back(m.endw);
			m.endw.first = "d";
			m.endw.second = 2;
			m.inf.push_back(m.endw);
			ways["b"] = m.inf;
			m.inf.clear();
		}
		else if (i == 3)
		{
			m.endw.first = "b";
			m.endw.second = 3;
			m.inf.push_back(m.endw);
			m.endw.first = "d";
			m.endw.second = 7;
			m.inf.push_back(m.endw);
			m.endw.first = "f";
			m.endw.second = 2;
			m.inf.push_back(m.endw);
			ways["c"] = m.inf;
			m.inf.clear();
		}
		else if (i == 4)
		{
			m.endw.first = "b";
			m.endw.second = 2;
			m.inf.push_back(m.endw);
			m.endw.first = "f";
			m.endw.second = 5;
			m.inf.push_back(m.endw);
			ways["d"] = m.inf;
			m.inf.clear();
		}
		else if (i == 5)
		{
			m.endw.first = "a";
			m.endw.second = 6;
			m.inf.push_back(m.endw);
			m.endw.first = "f";
			m.endw.second = 7;
			m.inf.push_back(m.endw);
			ways["e"] = m.inf;
			m.inf.clear();
		}
		else if (i == 6)
		{
			m.endw.first = "j";
			m.endw.second = 1;
			m.inf.push_back(m.endw);
			ways["f"] = m.inf;
			m.inf.clear();
		}
		else if (i == 7)
		{
			ways["j"] = m.inf;
			m.inf.clear();
		}

	}
}
void  inorder::order()
{
	while (true)
	{
		cout << 'press 1 to add_graph ||press 2 to input_graph ||press 3 to make update&&delete&&display ||press 0 to break' << endl;
		int numofop;
		cin >> numofop;
		if (numofop == 0)break;
		else if (numofop == 1)add_graph();
		else if (numofop == 2)input_graph();
		else if (numofop == 3)
		{
			cout << 'press 1 to update ||press 2 to delete ||press 3 to display graph date ||press 0 to break ' << endl;
			int n;
			cin >> n;
			while (n != 0)
			{

				if (n == 1)update();
				else if (n == 2)deletee();
				else if (n == 3)display_date();
				cout << 'press 1 to update ||press 2 to delete ||press 3 to display graph date ||press 0 to break ' << endl;
				cin >> n;
			}
		}
	}
    string destination;
    m.graph(ways);
    cout << 'please enter your destination : ' << endl;
    cin >> destination;
     m.output(destination);
    m.display();
}

void inorder::update()
{
	cout << 'Press 1 if you want add new city|| Press 2 if you want add edge || Press 3 if you want edit weight of edge' << endl;
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << 'Enter the number of city that you want add' << endl;
		int num;
		cin >> num;
		m.ncity = ways.size();
		m.ncity += num;
		for (int i = 0; i < num; i++)
		{
			cout << 'Please Enter the start city:' << endl;
			cin >> m.start;

			m.it = ways.find(m.start);
			if (m.it != ways.end()) {
				cout << 'this city already exists in the graph' << endl;
				num++;
			}
			else
			{
				cout << 'Enter The connected citys and the weghit/if you finish press 0 0 : ' << endl;
				while (true)
				{
					cin >> m.endw.first >> m.endw.second;
					unordered_map<string, vector<pair<string, double> > >::iterator its;
					if (m.endw.first == "0"&&m.endw.second == 0) { break; }
					its = ways.find(m.endw.first);
					if (its != ways.end())
					{
						m.inf.push_back(m.endw);
					}
					else {
						cout << 'this city doesnot belong to the graph (add the city if you want to use it)' << endl;
					}
				}
				ways[m.start] = m.inf;
				m.inf.erase(m.inf.begin(), m.inf.end());
			}
		}
	}
	else if (n == 2)
	{
		cout << 'Enter the city that you want add edges for it' << endl;
		string city;
		cin >> city;
		m.it = ways.find(city);
		if (m.it == ways.end()) {
			cout << 'this city doesnot belong to the graph' << endl;
		}
		else
		{
			m.inf = (*m.it).second;
			cout << 'enter the edge and the weight and 0 0 to finish' << endl;
			while (true)
			{
				cin >> m.endw.first >> m.endw.second;
				unordered_map<string, vector<pair<string, double> > >::iterator its;
				if (m.endw.first == "0"&&m.endw.second == 0) { break; }
				its = ways.find(m.endw.first);
				if (its != ways.end()) {

						m.inf.push_back(m.endw);
				}
				else {
					cout << ' this city doesnot belong to the graph (add the city if you want to use it)' << endl;
				}
			}
			ways[city] = m.inf;
			m.inf.erase(m.inf.begin(), m.inf.end());
		}
	}
	else if (n == 3)
	{
		cout << 'Enter the city that you want update edge for it' << endl;
		string city;
		cin >> city;
		m.it = ways.find(city);
		if (m.it == ways.end()) {
			cout << 'this city doesnot belong to the graph' << endl;
		}
		else
		{
			vector<pair<string, double> >vupdate;
			vupdate = (*m.it).second;
			cout << 'Enter the edge that you want update for it' << endl;
			string edge;
			cin >> edge;
			cout << 'Enter the weight for edge that you want update it' << endl;
			int weight;
			cin >> weight;
			for (int i = 0; i < vupdate.size(); i++)
			{
				if (vupdate[i].first == edge) { vupdate[i].second = weight; ways[city] = vupdate; break; }
			}
		}
	}
}


void inorder::deletee()
{
	cout << 'press 1 if you want delete edge || press 2 if you want delete city' << endl;
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << 'Enter the name of city that you want to delete edge inside it' << endl;
		string city, edge;
		cin >> city;
		cout << 'Enter the name of edge' << endl;
		cin >> edge;
		delete_edge(city, edge);
	}
	if (n == 2)
	{
		cout << 'Enter the name of city that you want to delete' << endl;
		string city;
		cin >> city;
		delete_city(city);
	}
}

void inorder::delete_edge(string city, string edge)
{
	vector<pair<string, double> >vdelete;
	m.it = ways.find(city);
	vdelete = (*m.it).second;
	for (int i = 0; i < vdelete.size(); i++)
	{
		if (vdelete[i].first == edge)
		{
			vdelete.erase(vdelete.begin()+i);
			break;
		}
	}
	ways[city] = vdelete;
}

void inorder::delete_city(string city)
{
	ways.erase(city);
	unordered_map<string, vector<pair<string, double> > >::iterator its;
	for (its = ways.begin(); its != ways.end(); its++) {
		delete_edge((*its).first, city);
	}
}
void inorder::display_date()
{
	cout << 'The number of city' << endl;
	cout << ways.size() << endl;
	cout << 'The graph is' << endl;
	for (m.it = ways.begin(); m.it != ways.end(); m.it++)
	{
		cout << (*m.it).first << endl;
		for (int i = 0; i < (*m.it).second.size(); i++)
		{
			cout << (*m.it).second[i].first << "    " << (*m.it).second[i].second << endl;
		}
	}
}
