#include <string>

class IDatabase
{
  public:
    virtual void Open() = 0;
    virtual void WriteData() = 0;
    virtual void ReadData() = 0;
    virtual void Close() = 0;

    virtual ~IDatabase(){};
    
};