#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

long long case1()
{
    ifstream input("input1.txt");

    long long result = 0;
    vector<long long> v1, v2;
    string line;
    while (getline(input, line))
    {
        stringstream ss(line);
        long long a, b;
        ss >> a >> b;
        v1.push_back(a);
        v2.push_back(b);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    for (int i = 0; i < v1.size(); ++i)
        result += abs(v1[i] - v2[i]);
    
    return result;
}

long long case2()
{
    ifstream input("input1.txt");

    long long result = 0;
    map<long long, int> m1, m2;
    string line;
    while (getline(input, line))
    {
        stringstream ss(line);
        long long a, b;
        ss >> a >> b;
        m1[a]++;
        m2[b]++;
    }

    for (const auto &pair : m1)
    {
        if (m2.find(pair.first) != m2.end())
        {
            result += pair.first * pair.second * m2[pair.first]; 
        }
    }
    
    
    return result;
}

int main()
{
    cout << "case1 = " << case1() << endl;
    cout << "case2 = " << case2() << endl;
    return 0;
}