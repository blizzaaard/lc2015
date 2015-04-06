#include <iostream>
#include <string>

/*
void remove_spaces(char s[], const int len)
{
    int start = 0;
    int end   = len - 1;
    while (' ' == s[start]) {
        ++start;
    }
    while (' ' == s[end]) {
        --end;
    }

    bool flag = false; // is the previous char is space
    int j = 0;
    for (int i = start; i <= end; ++i) {
        if (' ' == s[i]) {
            if (!flag) {
                s[j++] = ' ';
                flag = true;
            }
        } else {
            s[j++] = s[i];
            flag = false;
        }
    }
    s[j] = '\0';
}

void reverse(char s[], const int len)
{
    int i = 0;
    int j = len - 1;

    while (i < j) {
        char temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
    }
}

void reverse_words_in_a_string(char s[], const int len)
{
    reverse(s, len);

    int i = 0;
    int j = 0;

    while (i < len && j < len) {
        while (' ' == s[i]) {
            ++i;
            if (i >= len) {
                remove_spaces(s, len);
                return;
            }
        }

        j = i + 1;
        while (j < len && ' ' != s[j]) {
            ++j;
        }

        reverse(&s[i], j - i);
        i = j + 1;
    }

    remove_spaces(s, len);
}

int main()
{
    char string1[] = "  abc";
    char string2[] = "abc  ";
    char string3[] = "  abc  ";
    char string4[] = "  ab cd  ef  ";
    char string5[] = "";
    char string6[] = " ";
    char string7[] = "  ";

    reverse_words_in_a_string(string1, strlen(string1));
    reverse_words_in_a_string(string2, strlen(string2));
    reverse_words_in_a_string(string3, strlen(string3));
    reverse_words_in_a_string(string4, strlen(string4));
    reverse_words_in_a_string(string5, strlen(string5));
    reverse_words_in_a_string(string6, strlen(string6));
    reverse_words_in_a_string(string7, strlen(string7));

    std::cout << '|' << string1 << '|' << std::endl;
    std::cout << '|' << string2 << '|' << std::endl;
    std::cout << '|' << string3 << '|' << std::endl;
    std::cout << '|' << string4 << '|' << std::endl;
    std::cout << '|' << string5 << '|' << std::endl;
    std::cout << '|' << string6 << '|' << std::endl;
    std::cout << '|' << string7 << '|' << std::endl;

    return 0;
}
*/

class Solution {
public:
    void reverseWords(std::string &s) {
        std::string result;
        int i = s.size() - 1;
        while (0 <= i) {
            while (' ' == s[i] && i >= 0) {
                --i;
            }
            if (0 > i) {
                break;
            }
            if (!result.empty()) {
                result += " ";
            }
            std::string word;
            while (' ' != s[i] && i >= 0) {
                word.push_back(s[i]);
                --i;
            }
            std::reverse(word.begin(), word.end());
            result += word;
        }
        s = result;
    }
};


using namespace std;
class Solution1 {
public:
    void reverseWords(string &s) {
        string result;
        for (int start = s.size() - 1; start >= 0; --start) {
            if (s[start] == ' ') continue;
            int end = start;
            while (s[start] != ' ' && start >= 0) --start;
            if (!result.empty()) result += ' ';
            result += s.substr(start + 1,  end - start);
        }
        s = result;
    }
};

int main()
{
    std::string string1("  abc");
    std::string string2("abc  ");
    std::string string3("  abc  ");
    std::string string4("  ab cd  ef  ");
    std::string string5("");
    std::string string6(" ");
    std::string string7("  ");

    Solution1 s;
    s.reverseWords(string1);
    s.reverseWords(string2);
    s.reverseWords(string3);
    s.reverseWords(string4);
    s.reverseWords(string5);
    s.reverseWords(string6);
    s.reverseWords(string7);

    std::cout << '|' << string1 << '|' << std::endl;
    std::cout << '|' << string2 << '|' << std::endl;
    std::cout << '|' << string3 << '|' << std::endl;
    std::cout << '|' << string4 << '|' << std::endl;
    std::cout << '|' << string5 << '|' << std::endl;
    std::cout << '|' << string6 << '|' << std::endl;
    std::cout << '|' << string7 << '|' << std::endl;

    return 0;
}
