// Copyright 2016 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SHAKA_EMBEDDED_JS_IDB_IDB_FACTORY_H_
#define SHAKA_EMBEDDED_JS_IDB_IDB_FACTORY_H_

#include <string>

#include "shaka/optional.h"
#include "src/core/ref_ptr.h"
#include "src/js/events/event_target.h"
#include "src/mapping/any.h"
#include "src/mapping/backing_object_factory.h"
#include "src/mapping/exception_or.h"

namespace shaka {
namespace js {
namespace idb {

class IDBOpenDBRequest;
class IDBRequest;

class IDBFactory : public events::EventTarget {
  DECLARE_TYPE_INFO(IDBFactory);

 public:
  IDBFactory();

  RefPtr<IDBOpenDBRequest> Open(const std::string& name,
                                optional<uint64_t> version);
  RefPtr<IDBOpenDBRequest> OpenTestDb();
  RefPtr<IDBRequest> DeleteDatabase(const std::string& name);

  ExceptionOr<Any> CloneForTesting(Any value);
};

class IDBFactoryFactory
    : public BackingObjectFactory<IDBFactory, events::EventTarget> {
 public:
  IDBFactoryFactory();
};

}  // namespace idb
}  // namespace js
}  // namespace shaka

#endif  // SHAKA_EMBEDDED_JS_IDB_IDB_FACTORY_H_
