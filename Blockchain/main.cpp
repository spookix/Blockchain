#include <iostream>
#include <string>
#include "Blockchain.h"
#include "Encryption.h"

int main() {
    Blockchain bChain = Blockchain();
    Encryption keyEnc = Encryption();

    int privateKeyTransmitter, privateKeyReceiver;
    int publicKeyTransmitter, publicKeyReceiver;
    int keyTransmitter, keyReceiver;
    string transmitter, receiver;

    // partie qui remplace l'interface pour l'instant
    //dans l'interface on choisira qui réalise la transaction, on entre sa clé privée et le destinataire
    do {
        cout << "Qui fait la transaction? " << endl;
        cin >> transmitter;
        cout << "quelle est la cle privee?" << endl;
        cin >> privateKeyTransmitter;

        if (keyEnc.verifPrivateKey(transmitter, privateKeyTransmitter))
            cout << "Cle correct" << endl;
        else
            cout << "mauvaise cle privee" << endl;
    } while (!keyEnc.verifPrivateKey(transmitter, privateKeyTransmitter));

    cout << "Avec qui fait on la transaction? " << endl;
    cin >> receiver;

    //calcul des clés publiques
    publicKeyTransmitter = keyEnc.createPublicKey(privateKeyTransmitter);
    privateKeyReceiver = keyEnc.keyOfReceiver(receiver);
    publicKeyReceiver =  keyEnc.createPublicKey(privateKeyReceiver);

    // calcul des cles de chiffrages, elles sont censées etre identiques, mais calculablent qu'avec les clés privées de chacun
    // donc si quelqu'un intercepte le message et essai de le décoder il ne pourra pas
    keyReceiver = keyEnc.cryptKey(publicKeyTransmitter,privateKeyReceiver);
    keyTransmitter = keyEnc.cryptKey(publicKeyReceiver,privateKeyTransmitter);

    // ici on choisira l'action avec le menu déroulant et on affectera a la place du message, le choix du menu
    string message = "creation d'un produit";
    string message2 = "livraison d'un produit";
    string message3 = "vente d'un produit";
    cout << " le message: " << message << endl;


    //------ partie de test chiffrement et dechiffrement, ça se fait au niveau de l'insertion dans le block.cpp ligne 26 -------------
/*
    // on chiffre le message avec la clé calculée au dessus
    message = keyEnc.encryption(message,keyTransmitter);
    cout << " le message crypte: " << message << endl;

    cout << "on le decrypt avec la cle du receveur:" << endl;
     message = keyEnc.decrypt(message,keyReceiver);

    cout << "Le message decrypte :"  << message << endl;
*/


    cout << "    Mining :    "<< endl;

    cout << "Mining block 1..." << endl;
    bChain.AddBlock(Block(1, message,keyTransmitter));

    cout << "Mining block 2..." << endl;
    bChain.AddBlock(Block(2, message2,keyTransmitter));

    cout << "Mining block 3..." << endl;
    bChain.AddBlock(Block(3, message3,keyTransmitter));


    return 0;
}