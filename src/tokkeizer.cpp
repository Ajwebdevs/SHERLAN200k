#include "tokkeizer.h"

//def called from header
Tokkenizer::Tokkenizer(const string &corpus_file_load)
{
}

//def called from header
void Tokkenizer::train(size_t Vocab_size)
{
}


//encoder
vector<string> Tokkenizer::encode(const string &text)
{
    return vector<string>();
}

//decoder couple model
vector<string> Tokkenizer::decode(const vector<string> &tokkens)
{
    return vector<string>();
}
// decoder incase the state varible is low
vector<string> Tokkenizer::decode_low_strata(const vector<int> &tokkens)
{
    return vector<string>();
}

//loading and saving the vocabulary
void Tokkenizer::save_vocab(const string &filename_load)
{
}
void Tokkenizer::load_vocab(const string &filename_load)
{
}

//tokkenise
vector<string> Tokkenizer::tokenzie(const string &text)
{
    return vector<string>();
}

//return the O_max_pair
pair<string, string> Tokkenizer::O_max_pair()
{
    return pair<string, string>();
}

//

// merge the base pairs
void Tokkenizer::merge_pair(const string &pair)
{
}
