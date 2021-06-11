#include <napi.h>
#include "HashifyName.h"

Napi::Number MurmurWrapped(const Napi::CallbackInfo& info);
Napi::Object Init(Napi::Env env, Napi::Object exports);
