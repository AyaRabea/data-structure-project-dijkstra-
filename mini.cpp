#include "mini.h"
using namespace std;


mini::mini()
{
}


mini::~mini()
{
}
best::best()
{

	weight = numeric_limits<double>::max();
	pname = "_";
	ismarked = false;
};

void mini::graph(unordered_map<string, vector<pair<string, double> > > w)
{
	wways = w;
	ncity = wways.size();
	cout << 'Enter your Location :' << endl;
	cin >> mylocation;
	string begine = mylocation;

	int small = 0;

	for (it = wways.begin(); it != wways.end(); it++)
	{
		best object;
		object.name = (*it).first;
		if (object.name == mylocation) { object.weight = 0; }
		bestway.push_back(object);
	}
	vector<pair<string, double> >v;
	for (int i = 0; i <ncity; i++)
	{
		it = wways.find(begine);
		v = (*it).second;
		for (int j = 0; j < v.size(); j++)
		{
			for (int k = 0; k < bestway.size(); k++)
			{
				if (v[j].first == bestway[k].name)
				{
					if ((v[j].second) + small < (bestway[k].weight))
					{
						bestway[k].weight = (v[j].second) + small;
						bestway[k].pname = begine;
					}
					break;
				}

			}
		}
		double min = numeric_limits<double>::infinity(); int index;

		for (int k = 0; k < bestway.size(); k++)
		{
			if (bestway[k].ismarked == false) {

				if (min > bestway[k].weight)
				{
					min = bestway[k].weight;
					begine = bestway[k].name;
					index = k;
				}
			}
		}
		small = min;
		bestway[index].ismarked = true;

	}


}


void mini::display() {
	if (!b)cout << 'This way is not in the graph'<< endl;
	else
	{
		int x;
		cout << 'the shortest way : ' << endl << endl;
		x = final.size();
		for (int i = 0; i < x; i++) {
			cout << final.top() << '' -----> ';
			final.pop();
		}
		cout << 'it takes time ( '' << short_time << )'  << endl << endl;
	}
}



void mini::output(string destination)
{
	final.push(destination);
	string find = destination;
	int numo = bestway.size();

		for (int i = 0; i < numo&&find != mylocation; i++)
		{
			if (bestway[i].name == find)
			{
				if (bestway[i].pname == "_"&& bestway[i].name!=mylocation)
				{
					b = false;
				}
				final.push(bestway[i].pname);

				if (find == destination)
				{
					short_time = bestway[i].weight;
				}
				find = bestway[i].pname;
				i = -1;
			}

		}

}
