#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<cstring>
#include<utility>

#include"Network.h"

using namespace std;



void Network::addTransaction(Transaction s) {
	transactions.push_back(s);
	string dnr = s.donor;
	string brwr = s.borrower;
	int amt = s.amount;
	// if the given person don't exist , create one with zero net before updating
	if (net_amount.count(dnr) == 0) {
		net_amount[dnr] = 0;
	}
	if (net_amount.count(brwr) == 0) {
		net_amount[brwr] = 0;
	}
	net_amount[dnr] -= amt;
	net_amount[brwr] += amt;

}

void Network::optimiseTransaction() {
	vector<Transaction> optimised;
	multiset<pair<int, string> > ordering;
	for (pair<string, int> p : net_amount) {
		string person = p.first;
		int amount = p.second;
		if (amount != 0) {
			ordering.insert(make_pair(amount, person));
		}
	}
	pair<int, string> low, high;
	while (!ordering.empty()) {
		// store two values from both left and right
		low = *(ordering.begin());
		high = *(prev(ordering.end()));
		// remove the two values
		ordering.erase(ordering.begin());
		ordering.erase(prev(ordering.end()));
		// calculate the settlement amount possible between two of them
		int settlement = min(-low.first, high.first);
		// low.second will give settlement amount to high.second
		// store this transaction in optimised transactions list
		Transaction nw = {low.second, high.second, settlement};
		optimised.push_back(nw);
		// update the values after transaction
		low.first += settlement;
		high.first -= settlement;
		// store back the unsorted values into ordering
		if (low.first != 0) {
			ordering.insert(low);
		}
		if (high.first != 0) {
			ordering.insert(high);
		}
	}
	// update the list of transactions
	transactions.clear();
	for (int i = 0; i < optimised.size(); i++) {
		transactions.push_back(optimised[i]);
	}
	return;
}

void Network::print() {
	for (int i = 0; i < transactions.size(); i++) {
		auto ts = transactions[i];
		string dnr = ts.donor;
		string brwr = ts.borrower;
		int amount = ts.amount;
		cout << "\t\t"<<dnr << " to pay " << amount << " to " << brwr << endl;
	}
	cout << endl;
}
