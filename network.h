#include<vector>
#include<map>

#ifndef NETWORK_H
#define NETWORK_H


struct Transaction {
	std::string donor;
	std::string borrower;
	int amount;
};

class Network {
	std::vector<Transaction> transactions;
	std::map<std::string, int> net_amount;
public:
	void addTransaction(Transaction s);

	void optimiseTransaction();

	void print();
};

#endif
