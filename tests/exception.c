#include "../src/h/exception.h"
#include <assert.h>
// t-0
void caso0() {
	auto t = 0;
	try {
		t++;
	}
	assert(t == 1);
}
// tc-0
void caso1() {
	auto t = 0;
	auto c = 0;
	try {
		t++;
	} catch (const auto _) {
		c++;
	}
	assert(t == 1);
	assert(c == 0);
}
// tcf-0
void caso2() {
	auto t = 0;
	auto c = 0;
	auto f = 0;
	try {
		t++;
	} catch (const auto _) {
		c++;
	} finally {
		f++;
	}
	assert(t == 1);
	assert(c == 0);
	assert(f == 1);
}
// tcf-1
void caso3() {
	auto t = 0;
	auto c = 0;
	auto f = 0;
	try {
		t++;
		exception ex = {
			.what = "asdf",
		};
		throw(ex);
	} catch (const auto _) {
		c++;
	} finally {
		f++;
	}
	assert(t == 1);
	assert(c == 1);
	assert(f == 1);
}
// tcf-2
void caso4() {
	auto t = 0;
	auto c = 0;
	auto f = 0;
	try {
		t++;
		exception ex = {
			.what = "asdf",
		};
		throw(ex);
	} catch (const auto _) {
		c++;
		exception ex = {
			.what = "asdf",
		};
		throw(ex);
	} finally {
		f++;
	}
	assert(t == 1);
	assert(c == 1);
	assert(f == 1);
}
// tcf-3
void caso5() {
	auto t = 0;
	auto c = 0;
	auto f = 0;
	try {
		t++;
		exception ex = {
			.what = "asdf",
		};
		throw(ex);
	} catch (const auto _) {
		c++;
		exception ex = {
			.what = "asdf",
		};
		throw(ex);
	} finally {
		f++;
		exception ex = {
			.what = "asdf",
		};
		throw(ex);
	}
	assert(t == 1);
	assert(c == 1);
	assert(f == 1);
}
int main() {
	caso0();
	caso1();
	caso2();
	caso3();
	// caso4();
	// caso5();
}