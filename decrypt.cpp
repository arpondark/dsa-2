#include<bits/stdc++.h>
using namespace std;
string encryptedText, decryptedText;
void encrypt(string s, int index, int k, string res){
    if(index == s.size()){
        encryptedText = res;
        return;
    }
    if (s[index] >= 'A' && s[index] <= 'Z'){
        res += (s[index] + k - 'A') % 26 + 'A';
        encrypt(s, index + 1, k + 1, res);
    }
    else{
        res += (s[index] + k - 'a') % 26 + 'a';
        encrypt(s, index + 1, k + 1, res);
    }
}
void decrypt(string s, int index, int k, string res){
    if(index == s.size()){
        decryptedText = res;
        return;
    }
    if (s[index] >= 'A' && s[index] <= 'Z'){
        res += (s[index] - k - 'A' + 26) % 26 + 'A';
        decrypt(s, index + 1, k + 1, res);
    }
    else{
        res += (s[index] - k - 'a' + 26) % 26 + 'a';
        decrypt(s, index + 1, k + 1, res);
    }
}
int main()
{
    string s;
    int k;
    cout << "Enter string: ";
    cin >> s >> k;
    encrypt(s, 0, k, "");
    cout << "Encrypted Text: " << encryptedText << endl;
    decrypt(encryptedText, 0, k, "");
    cout << "Decrypted Text: " << decryptedText << endl;
    return 0;
}