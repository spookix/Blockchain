#include "Block.h"
#include "Encryption.h"
#include <string>
#include <sstream>
#include <utility>

Block::Block(uint32_t nIndexIn, string sDataIn, const int pKey) : _nIndex(nIndexIn), _sData(std::move(sDataIn)), _pKey(pKey) {
    _nNonce = -1;
}

string Block::GetHash() {
    return _sHash;
}

void Block::MineBlock() {
    _nNonce++;
    _sHash = _CalculateHash();

    cout << "Block mined: " << _sHash << endl;
}

inline string Block::_CalculateHash() const {
    Encryption keyEnc = Encryption();
    stringstream ss;
    ss << _nIndex << _sData << _nNonce << sPrevHash << _pKey;
    return keyEnc.encryption(ss.str(),_pKey);
}