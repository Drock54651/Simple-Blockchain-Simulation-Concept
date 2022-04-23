#include<iostream>
#include <sstream>

#include "Transaction.hpp"
#include "Block.hpp"
#include "Blockchain.hpp"
#include<vector>

using namespace std;

Blockchain::Blockchain() 
{
    Transaction genesis("BFC","BFC",0);
    pending.push_back(genesis);

    Block gBlock(pending, time(nullptr), "In the beginning..");
    chain.push_back(gBlock);

    Transaction freeMoney("BFC","make money by mining",0);
    pending.push_back(freeMoney);

    difficulty = 4;
    miningReward = 10;
}

Block Blockchain::getLatestBlock() 
{ 
    return chain.back();
}

void Blockchain::addTransaction(string src, string dst, int coins) 
{
    // TODO
    
    int balance = getBalanceOfAddress(src);
    int balanceWithPending = getBalanceOfAddressWithPending(src); // since originally only traversed the transactions inside the blocks, a person could keep sending money as transactions 
                                                                // wont change until pending is put into a block, making it so the balance always stayed the same
                                                                 
    if(isChainValid())
    {
        
        if(balance >= coins && balanceWithPending >= coins ) // taking pending into account, a persons TRUE balance is taken into account and is not static.
        {
            
            Transaction temp(src, dst, coins);
            pending.push_back(temp);
            cout << "Transaction successful" << endl << endl;
            //cout << src << " HAS " << balanceWithPending << " COINS" << endl;
        }
        else
        {
            cout << "ERROR: "<< src <<  " does not have enough coins for transfer" << endl << endl;
        }
    }
    else
    {
        cout << "ERROR: Chain is not valid" << endl;
    }
    
}

bool Blockchain::isChainValid() 
{ 
    // TODO
    string temp = ""; // to get number of 0s according to difficulty
    for(unsigned int i = 0; i < difficulty; i++)
    {
        temp+= "0";
    }
    for(unsigned int i = 1; i < chain.size(); i++)
    {
        if(chain[i].getPreviousHash() != chain[i - 1].getHash() || chain[i].getHash().substr(0, difficulty) != temp)
        {
            //cout << "Chain is not valid" << endl;
            return false;
        }
    }
    //cout << "Chain is valid" << endl;
    return true;
}

bool Blockchain::minePendingTransactions(string minerAddress) 
{
    // TODO
    Block newBlock(pending, time(nullptr), getLatestBlock().calculateHash());
  
    newBlock.mineBlock(difficulty);
    pending.clear();
    chain.push_back(newBlock);
    Transaction newTransaction("BFC", minerAddress, miningReward);
    pending.push_back(newTransaction);
    return true;
}

int Blockchain::getBalanceOfAddress(string address) 
{
    // TODO
    int sum = 0;
    for(unsigned int i = 0; i < chain.size(); i++)
    {
        sum+= chain[i].traverserTransaction(address);
    }
    if(sum < 0)
    {
        cout << "ERROR: Balance is negative" << endl;
        return sum;
    }
    return sum;
    //return 100;
}
int Blockchain::getBalanceOfAddressWithPending(string address) 
{
    
    int sum = 0;
    for(unsigned int i = 0; i < chain.size(); i++)
    {
        sum+= chain[i].traverserTransaction(address);
    }
    for(unsigned int i = 0; i < pending.size(); i++)
    {
       if(pending[i].getReceiver() == address)
       {
           sum+= pending[i].getAmount();
       }
       else if(pending[i].getSender() == address)
       {
           sum-= pending[i].getAmount();
       }
    }
    return sum;
   
}

void Blockchain::prettyPrint() 
{
    // TODO
    for(unsigned int i = 0; i < chain.size(); i++)
    {
        cout << "HASH for " << "block " << i << ": " << chain[i].getHash() << endl;
        if(i > 0)
        {

            cout << "PREVIOUS HASH for " << "block " << i << ": " << chain[i].getPreviousHash() << endl;
        }
        cout << "TIME for " << "block " << i << ": " << chain[i].getTime() << endl;
        cout << "NONCE for " << "block " << i << ": " << chain[i].getNonce() << endl;
        cout << "TRANSACTIONS for " << "block " << i << ": "; 
        chain[i].printTransaction();
        cout << endl;
        cout << "------------------------------------------------------" << endl;
    }
   
}