#include "Blockchain.h"

Blockchain::Blockchain() {
    _vChain.emplace_back(Block(0, "Genesis Block",1));
}

void Blockchain::AddBlock(Block bNew) {
    bNew.sPrevHash = _GetLastBlock().GetHash();
    bNew.MineBlock();
    _vChain.push_back(bNew);
}

Block Blockchain::_GetLastBlock() const {
    return _vChain.back();
}
