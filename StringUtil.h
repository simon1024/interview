#include <vector>
#include <string>
using namespace std;

class StringUtil
{
public:
    StringUtil() {}
    ~StringUtil() {}

public:
    static std::vector<std::string> split(const std::string& text, const std::string& sepStr, bool ignoreEmpty = true);
};

std::vector<std::string> StringUtil::split(const std::string& text, const std::string& sepStr, bool ignoreEmpty) {
    std::vector<std::string> vec;
    std::string str(text);
    std::string sep(sepStr);
    size_t n = 0, old = 0;
    while (n != std::string::npos)
        {
            n = str.find(sep,n);
            if (n != std::string::npos)
                {
                    if (!ignoreEmpty || n != old)
                        vec.push_back(str.substr(old, n-old));
                    n += sep.length();
                    old = n;
                }
        }

    if (!ignoreEmpty || old < str.length()) {
        vec.push_back(str.substr(old, str.length() - old));
    }
    return vec;
}

