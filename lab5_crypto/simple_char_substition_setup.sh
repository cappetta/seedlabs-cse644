#!/bin/bash -x
tr [:upper:] [:lower:] < gettysburg_address.txt > lowercase.txt
tr -cd ’[a-z][\n][:space:]’ < lowercase.txt > plaintext.txt
substitution=$(python -c "import random; s = 'abcdefghijklmnopqrstuvwxyz'; cipher=''.join(random.sample(s,len(s))); print cipher")
echo $substitution> cipher_key.txt
tr "abcdefghijklmnopqrstuvwxyz" $substitution < plaintext.txt > ciphertext.txt

