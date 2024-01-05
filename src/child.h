#ifndef TELCONODE_CHILD_H
#define TELCONODE_CHILD_H

#include "glib_object.h"

#include <telco-core.h>

namespace telco {

class Child : public GLibObject {
 public:
  static void Init(v8::Local<v8::Object> exports, Runtime* runtime);
  static v8::Local<v8::Object> New(gpointer handle, Runtime* runtime);

 private:
  explicit Child(TelcoChild* handle, Runtime* runtime);
  ~Child();

  static NAN_METHOD(New);

  static NAN_PROPERTY_GETTER(GetPid);
  static NAN_PROPERTY_GETTER(GetParentPid);
  static NAN_PROPERTY_GETTER(GetOrigin);
  static NAN_PROPERTY_GETTER(GetIdentifier);
  static NAN_PROPERTY_GETTER(GetPath);
  static NAN_PROPERTY_GETTER(GetArgv);
  static NAN_PROPERTY_GETTER(GetEnvp);
};

}

#endif
