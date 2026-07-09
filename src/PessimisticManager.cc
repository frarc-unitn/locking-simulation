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
      delete msg;
      break;
    case MessageKind::LOCKRELEASE:
      handleLockRelease((LockRelease*) msg);
      delete msg;
      break;
    default:
      throw cRuntimeError("PessimisticManager: Unrecognized Message Kind");
      break;
  }
}

void PessimisticManager::handleLockRequest(LockRequest* msg) {
  if(!this->locked) {
    this->locked = true;
    LockGranted* lock = new LockGranted("Manager: Lock Granted", MessageKind::LOCKGRANTED);
    lock->setData(this->data);
    send(lock, "nodes$o", msg->getArrivalGate()->getIndex());
  } else {
    // assert this->waitQueue[msg->getArrivalGate()->getIndex()] == false
    this->otherIsWaiting = true;
  }
}

void PessimisticManager::handleLockRelease(LockRelease* msg) {
  this->data = msg->getData();

  LockReleaseSuccessful* acknowledgement = new LockReleaseSuccessful("Manager: Lock Release Ack", MessageKind::LOCKRELSUCCESS);
  send(acknowledgement, "nodes$o", msg->getArrivalGate()->getIndex());

  if(this->otherIsWaiting){
    const int waiting_index = 1 - (msg->getArrivalGate()->getIndex());
    LockGranted* lock = new LockGranted("Manager: Lock Granted", MessageKind::LOCKGRANTED);
    lock->setData(this->data);
    send(lock, "nodes$o", waiting_index);
    this->otherIsWaiting = false;
  } else {
    this->locked = false;
  }
}
