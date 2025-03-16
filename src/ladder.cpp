#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include "ladder.h"
#include <algorithm>

using namespace std;

void error(string word1, string word2, string msg){
    std::cout << "Error Message:" << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    return false;
}

bool is_adjacent(const string& word1, const string& word2){
    if (word1 == word2) return true;

    if (word1.size() == word2.size()){
        int tally = 0;
        for (int i = 0; i < word1.size(); ++i) if (word1[i] != word2[i]) ++tally;
        if (tally > 1) return false;
        else return true;
    }

    if (word1.size() - word2.size() == 1){
        int tally = 0;
        for (int i = 0; i < word2.size(); ++i){
            if (word1[i + tally] != word2[i]){
                ++tally;
                if (word1[i + tally] != word2[i]) return false;
            }
            if (tally > 1) return false;
        }
        return true;
    }

    if (word1.size() - word2.size() == -1){
        int tally = 0;
        for (int i = 0; i < word2.size(); ++i){
            if (word1[i] != word2[i + tally]){
                ++tally;
                if (word1[i] != word2[i + tally]) return false;
            }
            if (tally > 1) return false;
        }
        return true;
    }

    return false;
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    queue<vector<string>> ladder_queue;
    ladder_queue.push({begin_word});
    set<string> visited;
    visited.insert(begin_word);

    while (!ladder_queue.empty()){
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        
        string last_word = ladder.back();

        for (string word : word_list){
            if (is_adjacent(last_word, word)){
                if (visited.count(word) == 0){

                    visited.insert(word);
                    vector<string> new_ladder(ladder);
                    new_ladder.push_back(word);

                    if (word == end_word) return new_ladder;
                    
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    return {};
}


void load_words(set<string> & word_list, const string& file_name) {
    ifstream in(file_name);
    if (!in) {
        throw runtime_error("Can't open input file");
    }

    string word;
    while (in >> word) word_list.insert(word);
    in.close();
}

void print_word_ladder(const vector<string>& ladder){
    if (ladder.size() == 0){
        cout << "No word ladder found." << endl;
        return;
    }
    cout << "Word ladder found: " ;
    for (int i = 0; i < ladder.size(); ++i) cout << ladder[i] << " "; 
    cout << endl;
}


#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
void verify_word_ladder() {

    set<string> word_list;

    load_words(word_list, "words.txt");

    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);

    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);

    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);

    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);

    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);

    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);

}

