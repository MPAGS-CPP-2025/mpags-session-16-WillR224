#ifndef CIPHERFACTORY_HPP
#define CIPHERFACTORY_HPP
#include "Cipher.hpp"
#include "CipherType.hpp"
#include <memory>
#include <string>

namespace CipherFactory {
    std::unique_ptr<Cipher> makeCipher(const CipherType cipherType, const std::string& key = "");
    std::unique_ptr<Cipher> makeCipher(const CipherType cipherType, const std::size_t key = 0);
}

#endif // CIPHERFACTORY_HPP