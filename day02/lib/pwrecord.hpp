#include <string>
#include <ostream>

namespace aoc2020
{

    class PwRecord
    {
    public:
        PwRecord (std::string);
        bool IsValid();
        bool IsValidInSecondJob();
        friend std::ostream& operator<<(std::ostream&, const PwRecord&);
    private:
        uint8_t minCount;
        uint8_t maxCount;
        char chr;
        std::string password;
    };

}
