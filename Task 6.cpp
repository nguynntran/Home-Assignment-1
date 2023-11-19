/*Task 6
Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.
*/

#include <iostream>
#include <string>
using namespace std;

// Create function for mapping pattern and word
bool Mapping(string word, string pat){
    char PattoWord [26];
    char WordtoPat [26];
    for (int i = 0; i < 26; i++){
        PattoWord[i] = '0';
        WordtoPat[i] = '0';
    }
    for (int i = 0; i < word.length(); i++){
        char wordC = word[i];
        char patC = pat[i];
        int x = patC - 'a';
        int y = wordC - 'a';
        if (PattoWord[x] == '0'){
            PattoWord[x] = wordC;
        }
        if (WordtoPat[y] == '0'){
            WordtoPat[y] = patC;
        }
        if ((PattoWord[x] != wordC) || (WordtoPat[y] != patC)){
            return false;
        }
    }
    return true;
}

// Create function to print the result
void Pattern(string arr[], string pat, int n){
    string res[n];
    for (int i = 0; i < n; i++){
        if (Mapping(arr[i], pat)){
            res[i] = arr[i];
        } 
    }
    for (int i = 0; i < n; i++){
            cout << res[i] <<" ";
        }
    }   


int main(){
    int n;
    cout << "The number of elements in array of string: ";
    cin >> n;
    string pat;
    cout << "Pattern input: ";
    cin >> pat;
    string arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "The words matches the pattern:" << endl;
    Pattern(arr, pat, n);
}

