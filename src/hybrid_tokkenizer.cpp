/*
*******************************************************************************
*
*   Copyright (C) 2024, sherlan200k
    Created by : Arjun S Nair
*   All Rights Reserved.
*
*******************************************************************************
*   file name:  hybrid_tokkenizer.cpp
*   encoding:   utf-8
*   created on: 2024Sep22
*/
#include "hybrid_tokkenizer.h"
#include <unicode/ustream.h>
#include <regex>
#include <iostream>
using namespace std;
using namespace icu;

// constructor for nu
HyrbridTokkenizer::HyrbridTokkenizer() : status(U_ZERO_ERROR), pattern(nullptr), matcher(nullptr)
{
    // initiate the regex
    initalize_regex_pattern();
};

// WARINING MEMORY LEAKS FOUND IN INITAL CASES WHERE DESTRUCTOR WAS NOT USED -- DO NOT REMOVE(PATTERN AND MATCHER ARE LEFT IN MEMORY WITHOUT DELETION)//
HyrbridTokkenizer::~HyrbridTokkenizer()
{
    // if our matcher or the pattern is not != nullpointer delteting the occurance
    if (matcher != nullptr)
    {
        delete matcher;
    }
    if (pattern != nullptr)
    {
        delete pattern;
    }
}

// building the regex pattern:
//  source taken from open ai's / gpt 2; rgex handeler
void HyrbridTokkenizer::initalize_regex_pattern()
{

    // regex pattern taken similar to gpt 2 but faces issues with IGNORECASE || lowercase and unicode character have issue while parsing
    // regex pattern modifed to incoperate contraction , word with unicode letters and number with unicode digit and special charachters and punctuations and whitespace handeling as well
    // model reincoperated using gpt4O
    string string_pattern_str = R"((?:\p{L}+['’]?(?=\s|$))|(?:\p{N}+)|(?:[^\p{L}\p{N}\s]+)|(?:\s+(?!\S))|(?:\s+))";

    // encoding the string regex pattern and passing to the icu::unicode string structure
    // converting string_pattern_str to a unicodde_pattern based on UTF_* encoding
    UnicodeString Unicode_pattern = UnicodeString::fromUTF8(string_pattern_str);
    // compile the pattern into a pattern object
    pattern = RegexPattern::compile(Unicode_pattern, 0, status);
    /*
    error catching and handeling using the U_FAILURE operator
    When an ICU function returns a UErrorCode, you can use U_FAILURE(status) to determine if the operation was successful.If the status value is a failure code, U_FAILURE(status) will return true else false.
    */
    if (U_FAILURE(status))
    {
        cerr << "Compilation to unicode failed with error :" << u_errorName << endl;
        return;
    };

    // if the matcher pattern fails
    matcher = pattern->matcher(icu::UnicodeString::fromUTF8(""), status);
    if (U_FAILURE(status))
    {
        cerr << "Matcher compilation to regex failed , error : " << u_errorName << endl;
        return;
    };
}

// tokkenize function
vector<string> HyrbridTokkenizer::tokkenize(const string &text)
{
    vector<string> tokkens;
    //lets get the total string length as well to calcaucte a much more efficent approch
    tokkens.reserve(text.length() / 2);
}
