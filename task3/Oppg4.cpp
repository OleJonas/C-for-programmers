#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string word1;
    string word2;
    string word3;
    string sentence;
    string sentence2;
    string sentence_start;

    cout << "Skriv inn 3 ord: " << endl;
    cin >> word1 >> word2 >> word3;
    
    sentence = word1 + " " + word2 + " " + word3 + ".";
    cout << sentence << endl;

    sentence2 = sentence;
    int remainder = (sentence2.length() - 10 > 2)? 2 : sentence2.length()-10; // Check if enough chars to do whole loop
    if(remainder > -1){
        for(int i = 9; i <= 9+remainder; i++){
            sentence2[i] = 'x';
        }
    }

    cout << "Setning 1: " << sentence << "\nSetning 2: " << sentence2 << endl;

    if(sentence.length() > 4){
        for(int i = 0; i < 5; i++){
            sentence_start += sentence[i];
        }
    }

    cout << "Setning 1: " << sentence << "\nSetning start: " << sentence2 << endl;
    
    if (sentence.find("hallo") != string::npos) {
        cout << "fant hallo" << endl;
    }

    string keyword = "er";
    vector<size_t> positions;
    size_t position = sentence.find(keyword);
    while(position != string::npos){
        positions.push_back(position);
        position = sentence.find(keyword, position+keyword.size());
    }

    cout << "Ordet 'er' ble funnet i setning1 paa disse indeksene: " << endl;
    for(int i = 0; i < positions.size(); i++) cout << positions[i] << endl;
}