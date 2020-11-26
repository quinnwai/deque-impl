Answer any exam questions here
Name: Quinn Wai Wong
WUSTL ID: 475074

Deep vs. Shallow Copy:

...Code...
int main(int argc, char* argv[])
{
	deque<int>* dqp1 = new deque<int>;
	deque<int>* dqp2 = &(deque<int>(*dqp1));

	cout << "dq1 ptr: " << dqp1 << endl;
	cout << "dq2 ptr: " << dqp2 << endl;

	return 0;
}

...Output...
dq1 ptr: 0000024017C039C0
dq2 ptr: 0000005BC5AFFD28

I know that a deep copy means the dequeue is stored in another location in memory. Since there are two different addresses for the
two pointers, I know that the standard library implements the copy constructor to create a deep copy

