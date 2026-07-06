enum MessageKind {
	READREQUEST = 1;
	READREPLY   = 2;
	CAS         = 3;
	CASSUCCESS  = 4;
	CASFAILED   = 5;
}

message ReadRequest {}

message ReadReply {
	int data;
}

message CompareAndSwap {
	int old_data;
	int data;
}

message CompareAndSwapSuccess {}

message CompareAndSwapFailed {
	int data;
}

