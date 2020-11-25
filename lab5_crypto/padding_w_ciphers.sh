#!/bin/bash -x

openssl enc -aes-128-cbc -e -in f1.txt -out f1.cbc -K 00112233445566778899aabbccddeeff -iv 010203040506070809
openssl enc -aes-128-cbc -e -in f2.txt -out f2.cbc -K 00112233445566778899aabbccddeeff -iv 010203040506070809
openssl enc -aes-128-cbc -e -in f3.txt -out f3.cbc -K 00112233445566778899aabbccddeeff -iv 010203040506070809

openssl enc -aes-128-cfb -e -in f1.txt -out f1.cfb -K 00112233445566778899aabbccddeeff -iv 010203040506070809
openssl enc -aes-128-cfb -e -in f2.txt -out f2.cfb -K 00112233445566778899aabbccddeeff -iv 010203040506070809
openssl enc -aes-128-cfb -e -in f3.txt -out f3.cfb -K 00112233445566778899aabbccddeeff -iv 010203040506070809

openssl enc -aes-128-ofb -e -in f1.txt -out f1.ofb -K 00112233445566778899aabbccddeeff -iv 010203040506070809
openssl enc -aes-128-ofb -e -in f2.txt -out f2.ofb -K 00112233445566778899aabbccddeeff -iv 010203040506070809
openssl enc -aes-128-ofb -e -in f3.txt -out f3.ofb -K 00112233445566778899aabbccddeeff -iv 010203040506070809

openssl enc -aes-128-ecb -e -in f1.txt -out f1.ecb -K 00112233445566778899aabbccddeeff 
openssl enc -aes-128-ecb -e -in f2.txt -out f2.ecb -K 00112233445566778899aabbccddeeff 
openssl enc -aes-128-ecb -e -in f3.txt -out f3.ecb -K 00112233445566778899aabbccddeeff 

#decrypt commands
openssl enc -aes-128-ecb -d -in f1.ecb -out f1.ecb.decrypt -K 00112233445566778899aabbccddeeff 
openssl enc -aes-128-ofb -d -in f1.ofb -out f1.ofb.decrypt -K 00112233445566778899aabbccddeeff -iv 010203040506070809
openssl enc -aes-128-cfb -d -in f1.cfb -out f1.cfb.decrypt -K 00112233445566778899aabbccddeeff -iv 010203040506070809


openssl enc -aes-128-ecb -e -in gettysburg_address.txt -out gettysburg_address.ecb -K 00112233445566778899aabbccddeeff 
openssl enc -aes-128-ecb -d -in gettysburg_address.ecb -out gettysburg_address.decrypt -K 00112233445566778899aabbccddeeff 
