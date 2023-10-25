#include "build.h"

#ifdef STANDALONE
#define BUILD_EXE "daemon.elf"
#pragma message("Including daemon.elf")
#else
#define BUILD_EXE "daemon_shim.elf"
#pragma message("Including daemon_shim.elf")
#endif

__asm__(
	".intel_syntax noprefix\n"
	".section .data\n"
	".global daemon_start\n"
	".type   daemon_start, @object\n"
	".align  4\n"
	"daemon_start:\n"
    	".incbin \"../bin/" BUILD_EXE "\"\n"
	"daemon_end:\n"
	    ".global daemon_size\n"
	    ".type   daemon_size, @object\n"
	    ".align  4\n"
	"daemon_size:\n"
    	".int    daemon_end - daemon_start\n"
);
