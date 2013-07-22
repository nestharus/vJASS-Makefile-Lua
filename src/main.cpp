#include "libs\luacpp.hpp"
#include "libs\luafile.hpp"
#include "libs\io helper.hpp"

void report_errors(Lua& lua, int status)
{
	
	if (status != 0) {
		std::cerr << "-- " << lua.tostring(-1) << std::endl;
		lua.pop(1); // remove error message
	}
}

int main(int argc, char* argv []) {
	Lua lua;

	lua.l_openlibs();

	int status = lua.l_loadfile(argv[1]);
	if (status == 0) {
		status = lua.pcall(0, LUA_MULTRET, 0);
	}
	
	report_errors(lua, status);

	std::cerr << std::endl;

	return 0;
}