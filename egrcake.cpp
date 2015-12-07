/*
 * Chef has bought N robots to transport cakes for a large community wedding. 
 * He has assigned unique indices, from 1 to N, to each of them. How it will happen?

Chef arranges the N robots in a row, in the (increasing) order of their indices. 
* Then, he chooses the first M robots and moves them to the end of the queue. Now,
*  Chef goes to the robot at the first position in the row and hands it one cake. 
* He then notes this robot's index (say k) in his notebook, and goes to the kth position
*  in the row. If the robot at this position does not have a cake, he give him one cake, 
* notes his index in his notebook, and continues the same process. If a robot visited by 
* Chef already has a cake with it, then he stops moving and the cake assignment process is stopped.

Chef will be satisfied if all robots have a cake in the end. In order to prepare the 
* kitchen staff for Chef's wrath (or happiness :) ), you must find out if he will be 
* satisfied or not? If not, you have to find out how much robots have a cake, so that 
* the kitchen staff can prepare themselves accordingly.
Input

    The first line of input contains a single integer T denoting the number of test cases.
    The single line of each test cases contains two space separated integers N and M.

Output

For each of the T test cases, output a single line:

    If all N robots have a cake, output "Yes" (without quotes).
    Otherwise, output "No" (without quotes) followed by a space and the number of robots which have a cake.

Constraints and Subtasks

    1 ≤ T ≤ 10
    0 ≤ M < N

Subtask 1: 25 points

    1 ≤ N ≤ 10^5

Subtask 3: 75 points

    1 ≤ N ≤ 10^9

Example

Input:
3
2 0
2 1
4 2

Output:
No 1
Yes
No 2
 * */
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class A
{
	public:
	A(unsigned long long n, unsigned long long m):N(n), M(m)
	{
		robo.resize(N+1);
		unsigned long long i=1;
		for(; i<=N-M; i++)
		{
			robo[i]=i+M;
		}
		unsigned long long c=1;
		for(; i<=N; i++)
		{
			robo[i]=c++;
		}
		count = 0;
	}
	void process()
	{
		int index=1;
		while(1)
		{
			if(hasCake.find(robo[index])!=hasCake.end())break;
			else
			{
				hasCake.insert(robo[index]);
				index=robo[index];
				count++;
			}
		}
		if(count==N)
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No "<<hasCake.size()<<"\n";
		}
	}
	private:
	vector<int> robo;
	unordered_set<int> hasCake;
	unsigned long long N, M;
	unsigned long long count;
};

int main()
{
	unsigned long long n, m;
	int cases;
	cin>>cases;
	for(int c=0; c<cases; c++)
	{
		cin>>n>>m;
		A a(n, m);
		a.process();
	}
	return 0;
}
