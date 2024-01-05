#ifndef TELCONODE_ENDPOINT_PARAMETERS_H
#define TELCONODE_ENDPOINT_PARAMETERS_H

#include "glib_object.h"

#include <telco-core.h>

namespace telco {

class EndpointParameters : public GLibObject {
 public:
  static void Init(v8::Local<v8::Object> exports, Runtime* runtime);

  static TelcoEndpointParameters* TryParse(v8::Local<v8::Value> value,
      Runtime* runtime);
  static bool HasInstance(v8::Local<v8::Value> value, Runtime* runtime);

 private:
  explicit EndpointParameters(TelcoEndpointParameters* handle,
      Runtime* runtime);
  ~EndpointParameters();

  static NAN_METHOD(New);
};

}

#endif
