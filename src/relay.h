#ifndef TELCONODE_RELAY_H
#define TELCONODE_RELAY_H

#include "glib_object.h"

#include <telco-core.h>

namespace telco {

class Relay : public GLibObject {
 public:
  static void Init(v8::Local<v8::Object> exports, Runtime* runtime);

  static TelcoRelay* TryParse(v8::Local<v8::Value> value, Runtime* runtime);
  static bool HasInstance(v8::Local<v8::Value> value, Runtime* runtime);

 private:
  explicit Relay(TelcoRelay* handle, Runtime* runtime);
  ~Relay();

  static NAN_METHOD(New);

  static NAN_PROPERTY_GETTER(GetAddress);
  static NAN_PROPERTY_GETTER(GetUsername);
  static NAN_PROPERTY_GETTER(GetPassword);
  static NAN_PROPERTY_GETTER(GetKind);
};

}

#endif
