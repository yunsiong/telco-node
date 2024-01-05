#ifndef TELCONODE_PORTAL_MEMBERSHIP_H
#define TELCONODE_PORTAL_MEMBERSHIP_H

#include "glib_object.h"

#include <telco-core.h>

namespace telco {

class PortalMembership : public GLibObject {
 public:
  static void Init(v8::Local<v8::Object> exports, Runtime* runtime);
  static v8::Local<v8::Object> New(gpointer handle, Runtime* runtime);

 private:
  explicit PortalMembership(TelcoPortalMembership* handle, Runtime* runtime);
  ~PortalMembership();

  static NAN_METHOD(New);

  static NAN_METHOD(Terminate);
};

}

#endif
