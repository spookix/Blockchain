#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Block.h"

using namespace std;

class Blockchain {
public:
    Blockchain();

    void AddBlock(Block bNew);

private:
    vector<Block> _vChain;

    Block _GetLastBlock() const;
};

#endif //BLOCKCHAIN_BLOCKCHAIN_H
