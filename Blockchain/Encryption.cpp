#include "Encryption.h"

int Encryption::keyGenerator() {
    return rand();
}

//formulle qui permet de calculer la clé publique
// cléPublique= base^cléPrivée (modulo nbrPremier) [base et nbrPremier identique pour tous

int Encryption::createPublicKey(int privateKey) {
    return (int) (pow(BASE, privateKey)) % FIRST;
}

string Encryption::encryption(string transaction, int key) {

    for (string::iterator it = transaction.begin(); it < transaction.end(); ++it) {
        if (isupper(*it)) {
            *it = 'A' + modulo(*it - 'A' + key, 26);
        } else if (islower(*it)) {
            *it = 'a' + modulo(*it - 'a' + key, 26);
        } else if (isdigit(*it)) {
            *it = '0' + modulo(*it - '0' + key, 10);
        }
    }

    return transaction;
}


string Encryption::decrypt(string transaction, int key) {

    for (string::iterator it = transaction.begin(); it < transaction.end(); ++it) {
        if (isupper(*it)) {
            *it = 'A' + modulo(*it - 'A' - key, 26);
        } else if (islower(*it)) {
            *it = 'a' + modulo(*it - 'a' - key, 26);
        } else if (isdigit(*it)) {
            *it = '0' + modulo(*it - '0' - key, 10);
        }
    }
    return transaction;
}

int Encryption::modulo(int m, int n) {
    return m >= 0 ? m % n : (n - abs(m % n)) % n;
}

bool Encryption::verifPrivateKey(string transmitter, int key) {
    if (transmitter == PRODUCER) {
        return key == PRIVATEKEYPRODUCER;
    } else if (transmitter == DELIVER) {
        return key == PRIVATEKEYDELIVER;
    } else if (transmitter == DISTRIBUTOR) {
        return key == PRIVATEKEYDISTRIBUTOR;
    } else if (transmitter == CONSUMER) {
        return key == PRIVATEKEYCONSUMER;
    } else
        return false;
}

int Encryption::cryptKey(int publicKeyOther, int PersonalPrivateKey) {
    int result = (int) (pow(publicKeyOther, PersonalPrivateKey)) % FIRST;
    if (result < 0)
        result *= -1;
    return result;
}

int Encryption::keyOfReceiver(string receiver){
    if (receiver == PRODUCER) {
        return PRIVATEKEYPRODUCER;
    } else if (receiver == DELIVER) {
        return PRIVATEKEYDELIVER;
    } else if (receiver == DISTRIBUTOR) {
        return PRIVATEKEYDISTRIBUTOR;
    } else if (receiver == CONSUMER) {
        return PRIVATEKEYCONSUMER;
    } else
        return 0;
}