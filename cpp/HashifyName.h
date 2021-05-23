#include <string>

class HashifyName {
public:
  static unsigned int murmurGen(std::string);
  static std::u16string generateHashedName(unsigned int);
  static char16_t getAlphabeticChar(unsigned int);
  static std::u16string hashifyName(std::string);
};
