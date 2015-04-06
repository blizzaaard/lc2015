// #65 Valid Number
//
// Validate if a given string is numeric.
//
// Some examples:
//
// "0" => true
// " 0.1 " => true
// "abc" => false
// "1 a" => false
// "2e10" => true
//
// Note: It is intended for the problem statement to be ambiguous. You should
// gather all requirements up front before implementing one.
//
// Update (2015-02-10):
//
// The signature of the C++ function had been updated. If you still see your
// function signature accepts a const char * argument, please click the reload
// button  to reset your code definition.


#include <iostream>
#include <string>

class Solution {

  public:
    bool isNumber(std::string s)
    {
        int state = 1;
        for (std::string::const_iterator it = s.begin(); it != s.end(); ++it) {
            char c = *it;
            switch (state) {
              case 1: {
                if (' ' == c)                  state = 1;
                else if ('+' == c || '-' == c) state = 2;
                else if ('.' == c)             state = 3;
                else if ('0' <= c && c <= '9') state = 4;
                else                           return false;
              }  break;
              case 2: {
                if ('.' == c)                  state = 3;
                else if ('0' <= c && c <= '9') state = 4;
                else                           return false;
              }  break;
              case 3: {
                if ('0' <= c && c <= '9')      state = 5;
                else                           return false;
              }  break;
              case 4: {
                if ('0' <= c && c <= '9')      state = 4;
                else if ('.' == c)             state = 6;
                else if ('e' == c)             state = 7;
                else if (' ' == c)             state = 10;
                else                           return false;
              }  break;
              case 5: {
                if ('0' <= c && c <= '9')      state = 5;
                else if ('e' == c)             state = 7;
                else if (' ' == c)             state = 10;
                else                           return false;
              }  break;
              case 6: {
                if ('0' <= c && c <= '9')      state = 5;
                else if ('e' == c)             state = 7;
                else if (' ' == c)             state = 10;
                else                           return false;
              }  break;
              case 7: {
                if ('+' == c || '-' == c)      state = 8;
                else if ('0' <= c && c <= '9') state = 9;
                else                           return false;
              }  break;
              case 8: {
                if ('0' <= c && c <= '9')      state = 9;
                else                           return false;
              }  break;
              case 9: {
                if ('0' <= c && c <= '9')      state = 9;
                else if (' ' == c)             state = 10;
                else                           return false;
              }  break;
              case 10: {
                if (' ' == c)                  state = 10;
                else                           return false;
              }  break;
            }
        }
        return 4  == state
            || 5  == state
            || 6  == state
            || 9  == state
            || 10 == state;
    }
};

int main()
{
    Solution s;
    std::cout << s.isNumber("-1.e49046 ") << std::endl;
    return 0;
}
