#ifndef CAESARCIPHER_H
#define CAESARCIPHER_H

#include <QString>

#include "caesar_cipher_interface.h"

namespace lib {

enum class CipherAlphabet: std::int8_t {
    LATIN,
    CYRILLIC
};

class LIB_EXPORT CaesarCipher
{
public:
  explicit CaesarCipher(const CipherAlphabet alphabet) noexcept;
  bool IsValidKey(std::int32_t key) const noexcept;
  void SetAlphabet(const CipherAlphabet alphabet) noexcept;
  QString Encrypt(const QString data, std::int32_t key) const noexcept;
  QString Decrypt(const QString data, std::int32_t key) const noexcept;

private:
  int GetPosition(QChar ch) const noexcept;

private:
  QString alphabet_;
};

} // namespace lib

#endif // CAESARCIPHER_H
