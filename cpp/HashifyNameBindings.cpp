#include <emscripten.h>
#include <emscripten/bind.h>
#include "../cpp/HashifyName.h"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(Module) {
    emscripten::function("hashifyName", optional_override([](std::string a) -> std::u16string  {
        return HashifyName::hashifyName(a);
    }));
}
