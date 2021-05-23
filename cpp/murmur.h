#include <napi.h>
#include "../../cpp/HashifyName.h"

Napi::Number MurmurWrapped(const Napi::CallbackInfo& info);
Napi::Object Init(Napi::Env env, Napi::Object exports);
