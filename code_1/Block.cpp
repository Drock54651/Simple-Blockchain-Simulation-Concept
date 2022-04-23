#include<iostream>
#include <sstream>


#include "Transaction.hpp"
#include "Block.hpp"
#include "sha256.hpp"

using namespace std;

Block::Block(vector<Transaction> _transactions, time_t _timestamp, string _previousHash) 
{
    nonce = -1;
    transactions = _transactions;
    previousHash = _previousHash;
    timestamp = _timestamp;
    hash = calculateHash();
}

void Block::setPreviousHash(string _previousHash)
 {
    // TODO
    previousHash = _previousHash;
    

}

string Block::calculateHash()
 {
    // TODO
    string input = toString();
    return sha256(input);
    return "";   
}
string Block::getPreviousHash()
{
    return previousHash;
}
string Block::getHash()
{
    return hash;
}
int Block::mineBlock(unsigned int difficulty) 
{
    // TODO
    string temp = ""; // to get number of 0s according to difficulty
    for(unsigned int i = 0; i < difficulty; i++)
    {
        temp+= "0";
    }
    string temp_hash = calculateHash();
    while(temp_hash.substr(0, difficulty) != temp)
    {
        nonce++;
        temp_hash = calculateHash();
    }
    // cout << nonce << endl;
    // cout << temp_hash << endl;
    hash = temp_hash;

    return nonce;
}
int Block::getNonce()
{
    return nonce;
}

string Block::toString() 
{
    // TODO
    string time = to_string(timestamp);
    string n = to_string(nonce);
    string trans = "";
    for(unsigned int i = 0; i < transactions.size(); i++)
    {
        if(i != transactions.size() - 1)
        {

            string temp = to_string(transactions[i].getAmount()) + "#" + transactions[i].getReceiver() + "#" + transactions[i].getSender() + "#";
            trans+= temp;
        }
        else
        {
            string temp = to_string(transactions[i].getAmount()) + "#" + transactions[i].getReceiver() + "#" + transactions[i].getSender();
            trans+= temp;
        }
    }
     // just append maybe in a for loop
   
    string input = n + " ||| " + time + " ||| " + trans + " ||| " + previousHash; // the input for sha
    //cout << input << endl << endl;
    // cout << n << endl << endl;
    // cout << time << endl << endl;
    // cout << previousHash << endl << endl;
    // cout << trans << endl << endl;

    return input;

    return "";
}

int Block::traverserTransaction(string name)
{
    int sum = 0;
    for(unsigned int i = 0; i < transactions.size(); i++)
    {
        if(transactions[i].getSender() == name) // person is sending money and therefore losing money
        {
            sum-= transactions[i].getAmount();
        }
        else if(transactions[i].getReceiver() == name) // person is recieivng money
        {
            sum+= transactions[i].getAmount();
        }

    }
    return sum;
    // if(sum >= 0)
    // {
    //     //cout << name << " has " << sum << " buffCUoin" << endl;
    //     return sum;
    // }
    // else
    // {
    //     cout << "ERROR: NEGATIVE SUM: "  << sum << endl;
    //     return 0;
    // }
    
}
void Block::printTransaction()
{
    for(unsigned int i = 0;  i < transactions.size(); i++)
    {
        cout << "(" << transactions[i].getSender() <<", " << transactions[i].getReceiver() << ", " << transactions[i].getAmount() << ")";
    }
}

time_t Block::getTime()
{
    return timestamp;
}
