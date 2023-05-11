#include <string>
class Member
{
private:
    std::string _name;
    int _id = 0;

public:
    Member(std::string &name) : _name(name) {}
    Member(std::string name) : _name(name) {}
    ~Member() = default;
    std::string getName();
    int getId();
    void setId(int id);
};
