#ifndef TELCONODE_APPLICATION_H
#define TELCONODE_APPLICATION_H

#include "glib_object.h"

#include <telco-core.h>

namespace telco {

class Application : public GLibObject {
 public:
  static void Init(v8::Local<v8::Object> exports, Runtime* runtime);
  static v8::Local<v8::Object> New(gpointer handle, Runtime* runtime);

 private:
  explicit Application(TelcoApplication* handle, Runtime* runtime);
  ~Application();

  static NAN_METHOD(New);

  static NAN_PROPERTY_GETTER(GetIdentifier);
  static NAN_PROPERTY_GETTER(GetName);
  static NAN_PROPERTY_GETTER(GetPid);
  static NAN_PROPERTY_GETTER(GetParameters);

  static v8::Local<v8::Value> ParseParameters(GHashTable* dict);
};

}

#endif
