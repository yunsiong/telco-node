#ifndef TELCONODE_BUS_H
#define TELCONODE_BUS_H

#include "glib_object.h"

#include <telco-core.h>

namespace telco {

class Bus : public GLibObject {
 public:
  static void Init(v8::Local<v8::Object> exports, Runtime* runtime);
  static v8::Local<v8::Object> New(gpointer handle, Runtime* runtime);

 private:
  explicit Bus(TelcoBus* handle, Runtime* runtime);
  ~Bus();

  static NAN_METHOD(New);

  static NAN_METHOD(Attach);
  static NAN_METHOD(Post);

  static v8::Local<v8::Value> TransformSignal(const gchar* name, guint index,
      const GValue* value, gpointer user_data);
  static void OnConnect(const gchar* signal, gpointer user_data);
  static void OnDisconnect(const gchar* signal, gpointer user_data);
  static bool ShouldStayAliveToEmit(const gchar* signal);
};

}

#endif
