#ifndef HYBRID_TOKKEN_HEADER
#define HYBRID_TOKKEN_HEADER

#include <string>
#include <vector>
/* GETTING REGX FROM ICU */
//libunistring-dev install from the brew package manager
// brew install libunistring ==> for string manipulation of regex and bytes
#include <unicode/unistr.h>
#include <unicode/regex.h>
#include <iostream>
using namespace std;


class HyrbridTokkenizer {
    public:
        HyrbridTokkenizer();
        ~HyrbridTokkenizer();

        //get the input and return the vector of tokkens as a result
        vector<string> tokkenize(const string& text);
    private:
        UErrorCode status;
        //after getting the status ecode match with the patter and weights
        icu::RegexPattern* pattern;
        icu::RegexMatcher* matcher;

        //init regex pattern
        void initalize_regex_pattern();

};
    
#endif // HYBRID_TOKKEN