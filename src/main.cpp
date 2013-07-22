#include "libs\luacpp.hpp"
#include "libs\luafile.hpp"
#include "libs\io helper.hpp"

int main(int argc, char* argv []) {
	Lua lua;

	lua.l_openlibs();

	return 0;
}