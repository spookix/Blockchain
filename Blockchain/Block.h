#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include <cstdint>
#include <iostream>

using namespace std;

class Block
{
public:
    string sPrevHash;

    Block(uint32_t nIndexIn, string sDataIn, int pKey);

    string GetHash();

    void MineBlock();

private:
    uint32_t _nIndex;
    int64_t _nNonce;
    string _sData;
    string _sHash;
    int _pKey;

    string _CalculateHash() const;
};


#endif //BLOCKCHAIN_BLOCK_H
