#include <iostream>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    cout << "Please choose a problem to solve (enter 1 or 2):" << endl;
    cout << "1: Stone's Love" << endl;
    cout << "2: Repeated K Times" << endl;

    int answer;
    cin >> answer;


    /* The idea behind solving the Stone's Love problem started with knowing I needed
    to (for) loop through the queries in order to find the desired output. From there, you
    (while) loop through the stones vector in order to add up the number of days Senorita
    needed to collect the amount of stones her friend was asking for. Every time you went
    through the loop, you were moving onto a new day, thus you must increment your days
    counter. You would then add that days stones to the stones counter. If we happen to equal,
    or go over, the query, we have found the correct amount of days, and we can send it as
    output. We move onto the next query and begin adding again from there.
    We must start the stones counter over every query, in case our query asks for a lesser
    amount than the previous query.  */

    // Stone's Love solution
    if (answer == 1)
    {
        // create variables to hold the sizes for the stones and queries vectors
	    int n, q;
	    cin >> n >> q;

	    // create vectors to hold the stones caught each day and each query
	    vector<int> stones;
	    vector<int> queries;

	    // add elements to stones
	    for (int i = 0; i < n; ++i)
	    {
		    int add_stones;
		    cin >> add_stones;
		    stones.push_back(add_stones);
	    }

	    // add elements to queries
	    for (int j = 0; j < q; ++j)
	    {
		    int add_queries;
		    cin >> add_queries;
		    queries.push_back(add_queries);
	    }

        // loop through the queries to answer them
	    for (int k = 0; k < queries.size(); ++k)
	    {
		    int curr_query = queries[k]; // keep track of our current query
		    int m = 0; // index for queries
		    int total_stones = 0; // current total number of stones
		    int days = 0; // counter for the amount of days it has taken

            // loop through the days, if we haven't collect enough stones yet, increment
		    while(total_stones < curr_query)
		    {
			    ++days;
			    total_stones += stones[m]; // add this days stones to the total
			    ++m; // move on the the next day if needed
		    }

            // check again to make sure we are at least equal to the query, if so output days
		    if (total_stones >= curr_query)
		    {
			    cout << days << endl;
		    }
	    }
    }

    /* From the beginning of solving this problem, I knew I would need to compare each element in the list
    with every other element to see how many times it was repeated. Each time it is repeated, you need to
    increment a counter. Once it has been compared with every element, check to see if the counter equals
    the given "K" integer. If it does, our last step is to compare this integer with the current smallest
    integer. If this new one is smaller, we will set it as the smallest integer. After we've gone through
    the whole list, we will output the smallest integer. */
    // Repeated K Times solution
    else if (answer == 2)
    {
        // variables to hold N size of the list and K value of repeats
	    int n, k;
	    cin >> n;

	    // a vector to hold the list of numbers given
	    vector<int> numbers;
	    for (int i = 0; i < n; ++i)
	    {
		    int add;
		    cin >> add;
		    numbers.push_back(add);
	    }

	    cin >> k;

	    // variables to hold the current smallest and counter for the amount of times repeated
	    int curr_smallest, counter; 
	    counter = 0;
	    curr_smallest = 100002; // we set it to some max value so our first value that works will obviously be less

	    // loop through the list, comparing each value with each other
	    for (int i = 0; i < numbers.size(); ++i)
	    {
		    // count how many times this element is repeated in the list
		    for (int j = 0; j < numbers.size(); ++j)
		    {
			    // don't compare the element with itself
			    if (i != j)
			    {
				    // count the repeats
				    if (numbers[i] == numbers[j]) ++counter;

				    // if our counter ever reaches k, compare with current smallest integer
				    if (counter == k)
				    {
					    // replace if our current number is smaller
					    if (numbers[i] < curr_smallest) curr_smallest = numbers[i];
				    }
			    }
		    }
	    }

	    if (curr_smallest != -1) cout << curr_smallest;

    }

    else
    {
        cout << "Please enter 1 or 2.";
    }

    return 0;
}
