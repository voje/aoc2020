#include <string>

namespace aoc2020
{

    class PwRecord
    {
    public:
        PwRecord (std::string);
        bool IsValid();
    private:
        std::string minCount;
        std::string maxCount;
        std::string chr;
        std::string password;
    };
}