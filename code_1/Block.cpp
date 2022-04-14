#include<iostream>
#include <sstream>


#include "Transaction.hpp"
#include "Block.hpp"
#include "sha256.hpp"

using namespace std;

Block::Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash) {
    nonce = -1;
    transactions = _transactions;
    previousHash = _previousHash;
    timestamp = _timestamp;
    hash = calculateHash();
}

void Block::setPreviousHash(string _previousHash) {
    // TODO
}

string Block::calculateHash() {
    // TODO
    return "";   
}

void Block::mineBlock(unsigned int difficulty) {
    // TODO
}

string Block::toString() {
    // TODO
    return "";
}