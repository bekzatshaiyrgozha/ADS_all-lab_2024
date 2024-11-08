#include <iostream>
#include <string>
#include <vector>

class RabinKarp
{
private:
    int d;
    int q;

    long long hash(const std::string &str, int end)
    {
        long long h = 0;
        for (int i = 0; i < end; i++)
        {
            h = (d * h + str[i]) % q;
        }
        return h;
    }

public:
    RabinKarp() : d(256), q(101) {}

    void search(const std::string &text, const std::string &pattern)
    {
        int m = pattern.length();
        int n = text.length();
        long long patternHash = hash(pattern, m);
        long long textHash = hash(text, m);
        long long h = 1;

        for (int i = 0; i < m - 1; i++)
        {
            h = (d * h) % q;
        }

        for (int i = 0; i <= n - m; i++)
        {
            if (patternHash == textHash)
            {
                if (text.substr(i, m) == pattern)
                {
                    std::cout << "Паттерн индексінде табылды " << i << std::endl;
                }
            }

            if (i < n - m)
            {
                textHash = (d * (textHash - text[i] * h) + text[i + m]) % q;

                if (textHash < 0)
                {
                    textHash += q;
                }
            }
        }
    }
};

int main()
{
    RabinKarp rk;
    std::string text = "GEEKS FOR GEEKS";
    std::string pattern = "GEEK";

    rk.search(text, pattern);
}