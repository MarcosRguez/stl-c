#define tuple(...) \
	struct {         \
		char a[];  \
	}

#define tuple_get(this, i)\
	((this)->a[i])

int main() {
	tuple() a;
	tuple(int, float, double) b;
	tuple_get(&b, 0);
}