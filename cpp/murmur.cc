#include "./murmur.h"

Napi::Number MurmurWrapped(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Number returnValue = Napi::Number::New(env, HashifyName::murmurGen(
    info[0].As<Napi::String>()
  ));

  return returnValue;
}

Napi::String HashifyWrapped(const Napi::CallbackInfo& info)
{
  Napi::Env env = info.Env();
  Napi::String returnValue = Napi::String::New(env, HashifyName::hashifyName(
    info[0].As<Napi::String>()
  ));

  return returnValue;
}

Napi::Object Init(Napi::Env env, Napi::Object exports)
{
  exports.Set(
    Napi::String::New(env, "hashifyName"), Napi::Function::New(env, HashifyWrapped));
  exports.Set(
    Napi::String::New(env, "murmur"), Napi::Function::New(env, MurmurWrapped));
  return exports;
}

NODE_API_MODULE(murmur, Init);
