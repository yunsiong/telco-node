#ifndef TELCONODE_PROCESS_H
#define TELCONODE_PROCESS_H

#include "glib_object.h"

#include <telco-core.h>

namespace telco {

class Process : public GLibObject {
 public:
  static void Init(v8::Local<v8::Object> exports, Runtime* runtime);
  static v8::Local<v8::Object> New(gpointer handle, Runtime* runtime);

 private:
  explicit Process(TelcoProcess* handle, Runtime* runtime);
  ~Process();

  static NAN_METHOD(New);

  static NAN_PROPERTY_GETTER(GetPid);
  static NAN_PROPERTY_GETTER(GetName);
  static NAN_PROPERTY_GETTER(GetParameters);

  static v8::Local<v8::Value> ParseParameters(GHashTable* dict);
};

}

#endif
