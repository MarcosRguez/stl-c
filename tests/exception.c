#include "../src/h/exception.h"
void g() {
	exception ex = {
		.what = "asdf",
	};
	throw(ex);
}
void f() {
	try {
		g();
	} catch (const auto v) {
		fprintf(stdout, "Excepción capturada en g, relanzando: %s\n", v->what);
		throw(*v);
	}
}
int main() {
	fprintf(stdout, "¡Hola mundo!\n");
	try {
		f();
	} catch (const auto _) {
		fprintf(stdout, "Excepción capturada en main\n");
	} finally {
		fprintf(stdout, "finally\n");
	}
	fprintf(stdout, "¡Adiós mundo!\n");
}