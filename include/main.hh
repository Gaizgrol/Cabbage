#include <string>

class Teste
{
    public:
        Teste(std::string s)
        {
            data = s;
        }

        std::string fetch()
        {
            std::string s = "";
            for ( const auto& c : data )
                s += std::toupper(c);

            return s;
        }

    private:
        std::string data;
};
