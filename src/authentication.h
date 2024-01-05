#ifndef TELCONODE_AUTHENTICATION_H
#define TELCONODE_AUTHENTICATION_H

#include "runtime.h"

#include <telco-core.h>
#include <node.h>

G_BEGIN_DECLS

#define TELCO_TYPE_NODE_AUTHENTICATION_SERVICE (telco_node_authentication_service_get_type())
G_DECLARE_FINAL_TYPE(
    TelcoNodeAuthenticationService,
    telco_node_authentication_service,
    TELCO,
    NODE_AUTHENTICATION_SERVICE,
    GObject)

TelcoAuthenticationService* telco_node_authentication_service_new(
    v8::Local<v8::Function> callback, telco::Runtime* runtime);

G_END_DECLS

#endif
