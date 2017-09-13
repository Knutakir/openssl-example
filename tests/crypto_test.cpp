#include "crypto.hpp"
#include <cassert>

using namespace std;

int main() {
  // Results copied from https://caligatio.github.io/jsSHA/
  assert(Crypto::hex(Crypto::sha1("Test")) == "640ab2bae07bedc4c163f679a746f7ab7fb5d1fa");
  assert(Crypto::hex(Crypto::sha1(Crypto::sha1("Test"))) == "af31c6cbdecd88726d0a9b3798c71ef41f1624d5");

  // Results copied from http://www.freecodeformat.com/pbkdf2.php
  assert(Crypto::hex(Crypto::pbkdf2("Password", "Salt", 4096, 128 / 8)) == "f66df50f8aaa11e4d9721e1312ff2e66");
  assert(Crypto::hex(Crypto::pbkdf2("Password", "Salt", 8192, 512 / 8)) == "a941ccbc34d1ee8ebbd1d34824a419c3dc4eac9cbc7c36ae6c7ca8725e2b618a6ad22241e787af937b0960cf85aa8ea3a258f243e05d3cc9b08af5dd93be046c");

  //MD5 tests
  assert(Crypto::hex(Crypto::md5("Knutakir")) == "109859344338f6a5ac7a7e5ebf75a849");
  //assert(

  //SHA-256
  assert(Crypto::hex(Crypto::sha256("Knutakir")) == "7fbdeac8963f7d9821f515b1522e3dad1c5440937b9f44a115076bc7c2745b01");

  //SHA-512
  assert(Crypto::hex(Crypto::sha512("Knutakir")) == "c1a87dd6627a597630c2f8486216e1db6b556a8361dc5a96b8f24de001f2a5ff65bcb14a3b5d57ec60bd012497df92bcd071cd2a7de5df799204230061040ae0");
}
