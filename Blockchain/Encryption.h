#ifndef BLOCKCHAIN_ENCRYPTION_H
#define BLOCKCHAIN_ENCRYPTION_H

#include <cstdint>
#include <iostream>
#include <math.h>

#define PRODUCER "producer"
#define DELIVER "deliver"
#define DISTRIBUTOR "distributor"
#define CONSUMER "consumer"

#define PRIVATEKEYPRODUCER 5
#define PRIVATEKEYDELIVER 2
#define PRIVATEKEYDISTRIBUTOR 8
#define PRIVATEKEYCONSUMER 3

// on définie une base de 5 et un nombre premier a 23 pour cette blockchain
#define BASE  5
#define FIRST  23

using namespace std;

class Encryption {
public:

    const string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    int keyGenerator();

    string encryption(string transaction, int key);
    string decrypt(string transaction, int key);

    int createPublicKey(int privateKey);
    int cryptKey(int publicKeyReceiver, int privateKeyTransmit);
    static bool verifPrivateKey(string transmitter, int key);
    int keyOfReceiver(string receiver);

    int modulo (int m, int n);


};


#endif //BLOCKCHAIN_ENCRYPTION_H
