#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> grid;

int main()
{
  // 1. Input
  string n, m;
  cin >> n >> m;

  // 2. Fill array
  for(char c: m)
  {
    grid.push_back(vector<char>());
    for(char d : n)
    {
      grid[grid.size() - 1].push_back('.');
    }
  }

  // 4. Get coordinates
  int x = 0, y = 0;
  bool found = false;
  for(char c: n)
  {
    y = 0;
    for(char d: m)
    {
      if(c == d) found = true;
      if(found) break;
      y++;
    }
    if(found) break;
    x++;
  }

  // 5. Fill 1. word
  for(int i = 0; i < grid.size(); i++)
  {
    grid[i][x] = m[i];
  }

  // 6. Fill 2. word
  for(int i = 0; i < grid[0].size(); i++)
  {
    grid[y][i] = n[i];
  }

  // 3. Print array
  for(vector<char> v : grid)
  {
    for(char c : v)
    {
      cout << c;
    }
    cout << endl;
  }

  return 0;
}
