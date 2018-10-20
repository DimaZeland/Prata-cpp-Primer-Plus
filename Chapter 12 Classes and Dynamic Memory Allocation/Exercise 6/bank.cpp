// bank.cpp -- using the Queue interface
// compile with queue.cpp
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
#include "queue.h"
const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new customer?

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	// setting things up
	std::srand(std::time(0));    //  random initializing of rand()

	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;

	cout << "Enter the number of simulation hours: ";
	int hours;              //  hours of simulation
	cin >> hours;
	// simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR * hours; // # of cycles


	cout << "Enter the average number of customers per hour: ";
	double perhour = 1;         //  average # of arrival per hour
	double average_wait_time = 0; // average waiting time for perhour customers
	for (; true; ++perhour) {
		Queue line(qs), line2(qs);         // line queue holds up to qs people
		//cin >> perhour;
		double min_per_cust;    //  average time between arrivals
		min_per_cust = MIN_PER_HR / perhour;

		Item temp;              //  new customer data to line
		Item temp2;              //  new customer data to line2
		long turnaways = 0;     //  turned away by full queue
		long customers = 0;     //  joined the queue
		long served = 0;        //  served during the simulation
		long sum_line = 0;      //  cumulative line length
		int wait_time = 0;      //  time until autoteller is free
		int wait_time2 = 0;      //  time until autoteller 2 is free
		long line_wait = 0;     //  cumulative time in line


								// running the simulation

		Queue* pLineNow = nullptr; // pointer to the smallest queue
		Item* pTempNow = nullptr; // pointer to the new customer data to smallest line

		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (line.queuecount() < line2.queuecount()) { // determination of the smallest queue
				pLineNow = &line; // selection of the smallest queue for the current minute
				pTempNow = &temp; // selection the new customer data of smallest line
			}
			else {
				pLineNow = &line2;
				pTempNow = &temp2;
			}

			if (newcustomer(min_per_cust))  // have newcomer
			{
				if (line.isfull() and line2.isfull())
					turnaways++;
				else
				{
					customers++;
					pTempNow->set(cycle);    // cycle = time of arrival
					pLineNow->enqueue(*pTempNow);
				}
			}
			
			if (wait_time <= 0 && !line.isempty()) // change in the first line in a minute
			{
				line.dequeue(temp);      // attend next customer
				wait_time = temp.ptime(); // for wait_time minutes
				line_wait += cycle - temp.when();
				served++;
			}
			if (wait_time > 0)
				wait_time--;

			if (wait_time2 <= 0 && !line2.isempty()) // change in the second line in a minute
			{
				line2.dequeue(temp2);      // attend next customer
				wait_time2 = temp2.ptime(); // for wait_time2 minutes
				line_wait += cycle - temp2.when();
				served++;
			}
			if (wait_time2 > 0)
				wait_time2--;

			sum_line += line.queuecount()+ line2.queuecount();
		}

		// reporting results
		//if (customers > 0)
		//{
		//	cout << "customers accepted: " << customers << endl;
		//	cout << "  customers served: " << served << endl;
		//	cout << "         turnaways: " << turnaways << endl;
		//	cout << "average queue size: ";
		//	cout.precision(2);
		//	cout.setf(ios_base::fixed, ios_base::floatfield);
		//	cout << (double)sum_line / cyclelimit << endl;
		//	cout << " average wait time: "
		//		<< (double)line_wait / served << " minutes\n";
		//}
		//else
		//	cout << "No customers!\n";

		average_wait_time = (double)line_wait / served;
		if (0.99 < average_wait_time and 1.99 > average_wait_time) { // bingo
			cout << "Done!\n" <<
				"average number of customers per hour, which leads to an average waiting time of one minute: " << perhour
				<< " persons\n";
			break;
		}
		else // next ateration
		//	cout << "\nline_wait: " << line_wait << ", served: " << served << '\n';
			cout << "\n" << perhour << " customers per hour, waiting time: " << average_wait_time << " minutes\n";
	} // for(;true;) end

	cin.get();
	cin.get();
	return 0;
}

//  x = average time, in minutes, between customers
//  return value is true if customer shows up this minute
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}
