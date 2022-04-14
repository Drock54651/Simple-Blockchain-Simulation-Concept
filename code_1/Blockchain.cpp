#include<iostream>
#include <sstream>

#include "Transaction.hpp"
#include "Block.hpp"
#include "Blockchain.hpp"
#include<vector>

using namespace std;

Blockchain::Blockchain() {
    Transaction genesis("BFC","BFC",0);
    pending.push_back(genesis);

    Block gBlock(pending, time(nullptr), "In the beginning..");
    chain.push_back(gBlock);

    Transaction freeMoney("BFC","make money by mining",0);
    pending.push_back(freeMoney);

    difficulty = 4;
    miningReward = 10;
}

Block Blockchain::getLatestBlock() { 
    return chain.back();
}

void Blockchain::addTransaction(string src, string dst, int coins) {
    // TODO
}

bool Blockchain::isChainValid() { 
    // TODO
    return true;
}

bool Blockchain::minePendingTransactions(string minerAddress) {
    // TODO
    return true;
}

int Blockchain::getBalanceOfAddress(string address) {
    // TODO
    return 100;
}

void Blockchain::prettyPrint() {
    // TODO
}