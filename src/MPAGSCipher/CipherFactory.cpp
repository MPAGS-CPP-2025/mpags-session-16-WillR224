#include "CipherFactory.hpp"
#include "CaesarCipher.hpp"
#include "VigenereCipher.hpp"
#include "PlayfairCipher.hpp"
#include <memory>
#include <stdexcept>

std::unique_ptr<Cipher> CipherFactory::makeCipher(const CipherType cipherType, const std::string& key) {
    
    switch (cipherType) {
        case CipherType::Caesar:
            return std::make_unique<CaesarCipher>(key);
        case CipherType::Vigenere:
            return std::make_unique<VigenereCipher>(key);
        case CipherType::Playfair:
            return std::make_unique<PlayfairCipher>(key);
        default:
            throw std::invalid_argument("Invalid cipher type");
    }
}

std::unique_ptr<Cipher> CipherFactory::makeCipher(const CipherType cipherType, const std::size_t key) {
    
    switch (cipherType) {
        case CipherType::Caesar:
            return std::make_unique<CaesarCipher>(key);
        case CipherType::Vigenere:
            throw std::invalid_argument("Invalid cipher type - only Caesar cipher can be created with a numeric key");
        case CipherType::Playfair:
            throw std::invalid_argument("Invalid cipher type - only Caesar cipher can be created with a numeric key");
        default:
            throw std::invalid_argument("Invalid cipher type");
    }

}