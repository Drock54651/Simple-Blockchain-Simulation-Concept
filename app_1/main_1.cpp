#include <iostream>
#include <fstream>
#include "../code_1/Blockchain.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    Blockchain buffCUoin;
    // cout << "ashutosh mining first block ... " << endl;
    // buffCUoin.minePendingTransactions("ashutosh");
    // //buffCUoin.prettyPrint(); 
    
    // cout << "ashutosh paid maciej 1 BFC ... " << endl;
    // buffCUoin.addTransaction("ashutosh","maciej", 1);

    // cout << "ashutosh paid asa 1 BFC ... " << endl;
    // buffCUoin.addTransaction("ashutosh","asa", 1);
    // cout << "asa mining second block ... " << endl;
    // buffCUoin.minePendingTransactions("asa");
    // //buffCUoin.prettyPrint(); 
    
    // cout << "asa paid ashutosh 1 BFC ... " << endl;
    // buffCUoin.addTransaction("asa","ashutosh", 1);    
    // cout << "ashutosh paid maciej 2 BFC ... " << endl;
    // buffCUoin.addTransaction("ashutosh","maciej", 2);
    
    // cout << "maciej mining third block ... " << endl;
    // buffCUoin.minePendingTransactions("maciej");
    // //buffCUoin.prettyPrint(); 
    
    // cout << "ashutosh mining fourth block ... " << endl;
    // buffCUoin.minePendingTransactions("ashutosh");
    // buffCUoin.prettyPrint();
    // cout << endl;
    
    //////////////////////////
    //buffCUoin.prettyPrint(); 

    cout << "ashutosh mining first block ... " << endl;
    buffCUoin.minePendingTransactions("ashutosh");
    //buffCUoin.prettyPrint(); 
    
    cout << "ashutosh paid maciej 1 BFC ... " << endl;
    buffCUoin.addTransaction("ashutosh","maciej", 1);

    cout << "ashutosh paid asa 1 BFC ... " << endl;
    buffCUoin.addTransaction("ashutosh","asa", 1);
    cout << "asa mining second block ... " << endl;
    buffCUoin.minePendingTransactions("asa");
   // buffCUoin.prettyPrint(); 
    
    cout << "asa paid ashutosh 1 BFC ... " << endl;
    buffCUoin.addTransaction("asa","ashutosh", 1);    
    cout << "ashutosh paid maciej 10 BFC ... " << endl;
    buffCUoin.addTransaction("ashutosh","maciej", 8);
    cout << "ashutosh paid maciej 1 BFC ... " << endl;
    buffCUoin.addTransaction("ashutosh","maciej", 1);
    cout << "ashutosh paid maciej 1 BFC ... " << endl;
    buffCUoin.addTransaction("ashutosh","maciej", 1);
    cout << "ashutosh paid maciej 1 BFC ... " << endl;
    buffCUoin.addTransaction("ashutosh","maciej", 1);
    
    


    cout << "maciej mining third block ... " << endl;
    buffCUoin.minePendingTransactions("maciej");
   // buffCUoin.prettyPrint(); 
    cout << "ashutosh paid maciej 8 BFC ... " << endl;
    buffCUoin.addTransaction("ashutosh","maciej", 8);
    cout << "ashutosh mining fourth block ... " << endl;
    buffCUoin.minePendingTransactions("ashutosh");

    cout << "asa paid ashutosh 10 BFC ... " << endl;
    buffCUoin.addTransaction("asa","ashutosh", 10);    

    cout << "JOE mining 5th block ... " << endl;
    buffCUoin.minePendingTransactions("JOE");

    cout << "ashutosh paid maciej 20 BFC ... " << endl;
    buffCUoin.addTransaction("ashutosh","maciej", 20);

    
    cout << "JOE mining 6th block ... " << endl;
    buffCUoin.minePendingTransactions("JOE");

    cout << "maciej paid JOE 40 BFC ... " << endl;
    buffCUoin.addTransaction("maciej","JOE", 40);

    if(buffCUoin.isChainValid())
    {
        cout << "Chain is valid." << endl;
    }
    else
    {
        cout << "ERROR: Chain is not valid" << endl;
        return 0;
    }
    buffCUoin.prettyPrint();
    
    return 0;
}