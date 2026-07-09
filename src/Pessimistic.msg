enum MessageKind {
	LOCKREQUEST    = 1;
	LOCKGRANTED    = 2;
	LOCKRELEASE    = 3;
	LOCKRELSUCCESS = 4;
}

message LockRequest {}

message LockGranted {
	int data;
}

message LockRelease {
	int data;
}

message LockReleaseSuccessful {}
