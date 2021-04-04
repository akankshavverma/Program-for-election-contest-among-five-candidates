/*An election is contested by 5 candidates.The candidates are numbered 1 to 5 and the voting is done by marking the 
candidate number on the ballot paper.Write a C++ program to read the ballots and count the votes cast for each candidate 
using an array.In case, a number read is outside the range 1 to 5, the ballot should be considered as a ‘spoilt ballot’
and the program should also count the number of spoilt ballots.*/

#include <iostream>
#include <algorithm>
using namespace std;

class Election
{
public:
	int count_of_votes[5] = { 0,0,0,0,0 }; //intializing the array
	int spoilt_ballot = 0; //intializing invalid votes

	void print_in_main()
	{
		int i;
		for (i = 1; i <= 5; i++)
		{
			cout << "Press " << i << " to vote for candicate " << i << endl;
		}
			
	}

	void number_of_voters()
	{
		cout << "Enter the number of people who would like to vote: ";
		int count_of_voters;
		cin >> count_of_voters;
		
		cout << endl;

		int i, candicate_vote_for;
	

		for (i = 1; i <= count_of_voters; i++)
		{
			cout << "Who do you choose to vote for: " << endl;
			cin >> candicate_vote_for;
			
			switch (candicate_vote_for)
			{
				case 1:
					count_of_votes[0]++;
					break;
				case 2:
					count_of_votes[1]++;
					break;
				case 3:
					count_of_votes[2]++;
					break;
				case 4:
					count_of_votes[3]++;
					break;
				case 5:
					count_of_votes[4]++;
					break;
				default:
					spoilt_ballot++;
					break;
			}
			
		}

	}

	void result_of_election()
	{
		int i;
		for (i = 1; i <= 5; i++)
		{
			cout << "Number of people who voted for candidate: " << i << " is " << count_of_votes[i - 1] << endl;
		}
		
		cout << "Number of invalid votes: " << spoilt_ballot << endl;
	}

	void winner()
	{
		int* max = max_element(count_of_votes, count_of_votes + 4);

		for (int i = 0; i <= 4; i++)
		{
			if (count_of_votes[i] == *max)
			{
				cout << "Winner of this Election is Candidate " << i+1 << " with " << *max << " votes." << endl;
			}
		}
	}
	
};


int main()
{
	Election ele;

	ele.print_in_main();
	cout << endl;

	ele.number_of_voters();
	cout << endl;

	ele.result_of_election();	
	cout << endl;

	ele.winner();
	
	return 0;

}
