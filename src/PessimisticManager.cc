#include "PessimisticManager.h"
#include "Pessimistic_m.h"

Define_Module(PessimisticManager);

void PessimisticManager::initialize() {
  // Initialize queue
}

void PessimisticManager::handleMessage(cMessage* msg) {
  switch(msg->getKind()) {
    case MessageKind::LOCKREQUEST:
      handleLockRequest((LockRequest*) msg);
      break;
    case MessageKind::LOCKRELEASE:
      handleLockRelease((LockRelease*) msg);
      break;
    default:
      throw cRuntimeError("PessimisticManager: Unrecognized Message Kind");
      break;
  }
}
