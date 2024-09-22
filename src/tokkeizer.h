#ifndef TOKKEN_H
#define TOKKEN_H

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Tokkenizer{
    //public instance for BPE trainers
    public:
    Tokkenizer(const string& corpus_file_load);

    //use the train module to train the BPE sequence
    void train(size_t Vocab_size);
    
    //encoder and decoder arch
    //encoder == translates the sentances to BPE tokkens 
    vector<string>encode( const string& text);

    //decoder == translatede the BPE tokkens back to sentances
    vector<string>decode(const vector<string>& tokkens);

    //another sperate instance of decode to use incase the tokken length is considerably low
    vector<string>decode_low_strata(const vector<int>& tokkens);

    //save the model and load the vocabulary
    void save_vocab(const string& filename_load);
    void load_vocab(const string& filename_load);

    //private helper functions
    private:
        unordered_map<string, int> vocab;
        //save the merges
        unordered_map<string, string> merges_save;

        vector<string> tokenzie(const string& text);
        //get O_max_pair ** (documentation section O_max pairs, section 0.1)
        pair<string, string> O_max_pair();
        //merging pair
        void merge_pair(const string& pair);
};
#endif //TOKKEN_H closer