#include <example.h> // Will be generated by the go compiler
#include <string>

/**
 * @brief Transforms std::string into GoString
 * 
 * @param s string from
 * @return GoString string transformed
 */
GoString getString(std::string s)
{
  GoString str;
  str.p = s.c_str();
  str.n = s.size() + 1;
  return str;
}

int main() {
  GoString str = getString("Holi");
  Print(str);
  printf("BRET\n");

  return 0;
}
