#include "HashifyName.h"

unsigned int HashifyName::murmurGen(std::string key){
  unsigned int len = key.length(), hash = 0,
    i = 0, remainder = len % 4, bytes = len - remainder, k;
      while (i < bytes) {
        k = (
            (((unsigned int)key[i++] & (unsigned int)0xFF)) |
            (((unsigned int)key[i++] & (unsigned int)0xFF) << 8) |
            (((unsigned int)key[i++] & (unsigned int)0xFF) << 16) |
            (((unsigned int)key[i++] & (unsigned int)0xFF) << 24));
        k *= (unsigned int)0xcc9e2d51;
        k = (k << 15) | (k >> 17);
        k *= (unsigned int)0x1b873593;

        hash ^= k;
        hash = (hash << 13) | (hash >> 19);
        hash *= 5;
        hash += (unsigned int)0xe6546b64;
      }

      if (remainder > 0) {
        unsigned int rem = 0, bits = 0;
        switch(remainder) {
          case 3: rem ^= ((unsigned int)key[i + 2] & 0xff) << 16;
      		case 2: rem ^= ((unsigned int)key[i + 1] & 0xff) << 8;
      		case 1: rem ^= ((unsigned int)key[i] & 0xff);
        }

        rem *= (unsigned int)0xcc9e2d51;
        rem = (rem << 15) | (rem >> 17);
        rem *= (unsigned int)0x1b873593;

        hash ^= rem;
      }

      hash ^= len;

      hash ^= (hash >> 16);
      hash *= (unsigned int)0x85ebca6b;
      hash ^= (hash >> 13);
      hash *= (unsigned int)0xc2b2ae35;
      hash ^= (hash >> 16);

      return hash;
}

char16_t HashifyName::getAlphabeticChar(unsigned int hash) {
  return (char16_t)((unsigned int)(0x4e00) + hash);
}

std::u16string HashifyName::generateHashedName(unsigned int hash) {
  unsigned int size = (unsigned int)(0x9fa5) - (unsigned int)(0x4e00),
    x;
  std::u16string name;
  for (x = hash; x > size; x = floor(x / size)) {
    name = getAlphabeticChar(x % size) + name;
  }
  name = getAlphabeticChar(x % size) + name;
  return name;
}

std::u16string HashifyName::hashifyName(std::string name) {
  return generateHashedName(murmurGen(name));
}
