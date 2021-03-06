
//
// Pretty printing helpers
//

#ifndef _pretty_printing_h
#define _pretty_printing_h

#include <ostream>

#include "emscripten-optimizer/colors.h"

inline std::ostream &doIndent(std::ostream &o, unsigned indent) {
  for (unsigned i = 0; i < indent; i++) {
    o << "  ";
  }
  return o;
}

inline std::ostream &incIndent(std::ostream &o, unsigned& indent) {
  o << '\n';
  indent++;
  return o; 
}

inline std::ostream &decIndent(std::ostream &o, unsigned& indent) {
  indent--;
  doIndent(o, indent);
  return o << ')';
}

inline std::ostream &prepareMajorColor(std::ostream &o) {
  Colors::red(o);
  Colors::bold(o);
  return o;
}

inline std::ostream &prepareColor(std::ostream &o) {
  Colors::magenta(o);
  Colors::bold(o);
  return o;
}

inline std::ostream &prepareMinorColor(std::ostream &o) {
  Colors::orange(o);
  return o;
}

inline std::ostream &restoreNormalColor(std::ostream &o) {
  Colors::normal(o);
  return o;
}

inline std::ostream& printText(std::ostream &o, const char *str) {
  o << '"';
  Colors::green(o);
  o << str;
  Colors::normal(o);
  return o << '"';
}

inline std::ostream& printOpening(std::ostream &o, const char *str, bool major=false) {
  o << '(';
  major ? prepareMajorColor(o) : prepareColor(o);
  o << str;
  restoreNormalColor(o);
  return o;
}

inline std::ostream& printMinorOpening(std::ostream &o, const char *str) {
  o << '(';
  prepareMinorColor(o);
  o << str;
  restoreNormalColor(o);
  return o;
}

#endif //  _pretty_printing_h

