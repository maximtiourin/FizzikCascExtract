#include <SimpleOpt.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

enum
{
	OPT_HELP,
	OPT_LISTFILE,
	OPT_SEARCH,
	OPT_EXTRACT,
	OPT_DEST,
	OPT_FULLPATH,
	OPT_LOWERCASE,
	OPT_FLAG,
	OPT_ARG
};

CSimpleOpt::SOption CMDLINE_OPTIONS[] = {
	{ OPT_FLAG, "-a", SO_NONE },     // "-a"
	{ OPT_FLAG, "-b", SO_NONE },     // "-b"
	{ OPT_ARG,  "-f", SO_REQ_SEP },  // "-f ARG"
	{ OPT_HELP, "-?", SO_NONE },     // "-?"
	{ OPT_HELP, "--help", SO_NONE }, // "--help"
	SO_END_OF_OPTIONS                // END
};

int main(int argc, char **argv) {

	return 0;
}