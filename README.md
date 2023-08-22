Author: Derick Sayavong

Functionality of code:

To simulate the concept of a blockchain in a simple manner. A User can mine a block as a result of a computational complex task(A specific Nounce is to be found) and if successful is rewarded BuffCUoins. Transactions made by any User will be added to a pending list, in which it will be wrapped into a block once a User decides to mine a block. Each block has a specific hash key in which it must have a specific number of 0's in front according to the difficulty number. And to check if the blockchain is valid, each block must have a previous hash that is equal to the hash of the block prior to the current one. To find the hash key, a blocks contents is converted into a string and that string is used as the input for sha256. If the blockchain is valid, then a User can make a transaction if they have the sufficient funds to do so, and these transactions will be added to the pending list.
